#include "DAL.h"

namespace HDBPP
{
DAL::DAL(string prepo)
{
    elk_http_repo = prepo;
}

DAL::~DAL()
{
}

bool DAL::InsertElastic(string index, string type, string in_json, string& out_id)
{
    std::stringstream qurl;
    qurl << elk_http_repo << "/" << index << "/" << type << "/";

    RestClient::init();
    RestClient::Connection* conn = new RestClient::Connection(qurl.str());
    RestClient::HeaderFields headers;
    headers["Content-Type"] = "application/json";
    conn->SetHeaders(headers);
    RestClient::Response r = conn->post("", in_json);

    bool found = false;
    if (r.code == HTTP_STATUS_CREATED) {
        found = true;
        auto res = json::parse(r.body);
        out_id = res["_id"];
    }

    RestClient::disable();

    return found;
}

bool DAL::UpdateElastic(string index, string type, string id, string update_json_doc)
{
    std::stringstream qurl;
    qurl << elk_http_repo << "/" << index << "/" << type << "/" << id << "/_update";

    RestClient::init();
    RestClient::Connection* conn = new RestClient::Connection(qurl.str());
    RestClient::HeaderFields headers;
    headers["Content-Type"] = "application/json";
    conn->SetHeaders(headers);

    std::stringstream elk_json_update_in;
    elk_json_update_in << "{\"script\" : {"
                       << "\"source\": \"" << update_json_doc << "\","
                       << "\"lang\": \"painless\" }}";
    string jsonstr = elk_json_update_in.str();
    RestClient::Response r = conn->post("", jsonstr);

    bool found = false;
    if (r.code == HTTP_STATUS_OK)
        found = true;

    RestClient::disable();
    return found;
}

bool DAL::SearchElastic(string index, string type, string json_search, json& out_json)
{
    std::stringstream qurl;
    qurl << elk_http_repo << "/" << index << "/" << type << "/"
         << "_search";

    RestClient::init();
    RestClient::Connection* conn = new RestClient::Connection(qurl.str());
    RestClient::HeaderFields headers;
    headers["Content-Type"] = "application/json";
    conn->SetHeaders(headers);
    RestClient::Response r = conn->post("", json_search);

    bool found = false;
    if (r.code == HTTP_STATUS_OK) {
        // found = true;
        out_json = json::parse(r.body);
        if (out_json["hits"]["total"] > 0)
            found = true;
    }

    return found;
}

bool DAL::GetElasticById(string index, string type, string id, json& out_json)
{
    std::stringstream qurl;
    qurl << elk_http_repo << "/" << index << "/" << type << "/" << id;

    RestClient::init();
    RestClient::Connection* conn = new RestClient::Connection(qurl.str());
    RestClient::HeaderFields headers;
    headers["Content-Type"] = "application/json";
    conn->SetHeaders(headers);
    RestClient::Response r = conn->get("");

    bool found = false;
    if (r.code == HTTP_STATUS_OK) {
        found = true;
        out_json = json::parse(r.body);
    }

    return found;
}

bool DAL::GetAttributeConfiguration(AttributeConfiguration& p_attr_conf)
{
    try
    {
        json res;
        if (!SearchElastic("configuration", "attribute", p_attr_conf.GetJsonQuery(), res))
            return false;

        LOG(Debug) << "Attribute configuration: " << res << endl;

        json the_one_we_search = res["hits"]["hits"][0]["_source"];

        p_attr_conf.SetParameterFromJson(the_one_we_search);
        p_attr_conf.SetID(res["hits"]["hits"][0]["_id"]);
        return true;
    }
    catch (int e)
    {
        LOG(Debug) << e << endl;
        return false;
    }
}

bool DAL::SaveAttributeConfiguration(AttributeConfiguration& p_attr_conf)
{
    try
    {
        json res;
        if (!p_attr_conf.GetID().empty()) {
            // update if not empty
            LOG(Debug) << "updating attribute configuration: \n" << res << endl;
            return UpdateElastic("configuration", "attribute", p_attr_conf.GetID(), p_attr_conf.ToElkScript4Update());
        }

        string out_id;
        if (!InsertElastic("configuration", "attribute", p_attr_conf.ToJson(), out_id))
            return false;
        LOG(Debug) << "Inserted attribute configuration: " << out_id << endl;
        p_attr_conf.SetID(out_id);
        return true;
    }
    catch (int e)
    {
        LOG(Debug) << e << endl;
        return false;
    }
}

bool DAL::GetAttributeConfigurationHistory(AttributeConfigurationHistory& p_attr_conf_history)
{
    try
    {
        json res;
        if (!SearchElastic("configuration", "attribute", p_attr_conf_history.GetJsonQuery(), res))
            return false;

        LOG(Debug) << "Attribute configuration history: \n" << res << endl;
        json the_one_we_search = res["hits"]["hits"][0]["_source"];

        p_attr_conf_history.SetParameterFromJson(the_one_we_search);
        p_attr_conf_history.SetID(res["hits"]["hits"][0]["_id"]);
        return true;
    }
    catch (int e)
    {
        LOG(Debug) << e << endl;
        return false;
    }
}

bool DAL::SaveAttributeConfigurationHistory(AttributeConfigurationHistory& p_attr_conf_history)
{
    try
    {
        json res;
        if (!p_attr_conf_history.GetID().empty()) {
            LOG(Debug) << "Updating attribute configuration history: \n" << res << endl;
            return UpdateElastic("configuration_history",
                                 "attribute",
                                 p_attr_conf_history.GetID(),
                                 p_attr_conf_history.ToElkScript4Update());
        }

        string out_id;
        if (!InsertElastic("configuration_history", "attribute", p_attr_conf_history.ToJson(), out_id))
            return false;
        LOG(Debug) << "Inserted attribute configuration history: " << out_id << endl;
        p_attr_conf_history.SetID(out_id);
        return true;
    }
    catch (int e)
    {
        LOG(Debug) << e << endl;
        return false;
    }
}
};