#ifndef _HDBPP_DATAOBJ_H
#define _HDBPP_DATAOBJ_H

#include <iostream>
#include <string>
#include <stdint.h>
#include <stdio.h>
#include "json/json.hpp"
#include "restclient-cpp/connection.h"
#include "restclient-cpp/restclient.h"

using namespace std;
using json = nlohmann::json;

namespace HDBPP
{
class AttributeConfiguration
{
private:
    string ID;
    string data_type;
    string domain;
    string family;
    string member;
    int ttl;
    string facility;
    int port;

public:
    void SetDataType(string str);
    void SetDomain(string str);
    void SetFamily(string str);
    void SetMember(string str);
    void SetFacility(string str);
    void SetPort(int str);
    void SetTtl(int pttl);
    void SetID(string str);
    void SetParameterFromJson(json& p_json);

    string GetID();
    string GetDataType();
    string GetDomain();
    string GetFamily();
    string GetMember();
    string GetFacility();
    int GetPort();
    int GetTtl();
    string ToJson();
    string ToElkScript4Update();
    string GetJsonQuery();

    AttributeConfiguration(string data_type,
                           string domain,
                           string family,
                           string member,
                           string facility,
                           int port,
                           int ttl);
    AttributeConfiguration(json& p_json);
    ~AttributeConfiguration();
};

class AttributeConfigurationHistory
{
private:
    AttributeConfiguration& configuration;
    string eventType;
    int64_t time;
    int time_us;

public:
    void SetAttributeConfiguration(AttributeConfiguration& configuration);
    void SetEventType(string str);
    void SetTime(int64_t time);
    void SetTimeUs(int time_us);

    AttributeConfiguration GetAttributeConfiguration();
    string GetEventType();
    int64_t GetTime();
    int GetTimeUs();

    AttributeConfigurationHistory(AttributeConfiguration& configuration, string eventType, int64_t time, int time_us);
    ~AttributeConfigurationHistory();
};

class AttributeEventData
{
};
};

#endif

#ifndef _HDBPP_DAL_H
#define _HDBPP_DAL_H

namespace HDBPP
{
const int HTTP_STATUS_OK = 200;
const int HTTP_STATUS_CREATED = 201;

class DAL
{
private:
    string elk_http_repo;

public:
    bool InsertElastic(string index, string type, string in_json, string& out_id);

    bool UpdateElastic(string index, string type, string id, string update_json_doc);

    bool SearchElastic(string index, string type, string json_search, json& out_json);

    bool GetElasticById(string index, string type, string id, json& out_json);

    bool GetAttributeConfiguration(AttributeConfiguration& p_attr_conf);

    bool SaveAttributeConfiguration(AttributeConfiguration& p_attr_conf);

    DAL(string pelk_http_repo);
    ~DAL();
};
};
#endif

namespace HDBPP
{
void AttributeConfiguration::SetDataType(string str)
{
    data_type = str;
}

void AttributeConfiguration::SetDomain(string str)
{
    domain = str;
}

void AttributeConfiguration::SetFamily(string str)
{
    family = str;
}

void AttributeConfiguration::SetMember(string str)
{
    member = str;
}

void AttributeConfiguration::SetFacility(string str)
{
    facility = str;
}

void AttributeConfiguration::SetPort(int str)
{
    port = str;
}

void AttributeConfiguration::SetTtl(int str)
{
    ttl = str;
}

string AttributeConfiguration::GetDataType()
{
    return data_type;
}

string AttributeConfiguration::GetDomain()
{
    return domain;
}

string AttributeConfiguration::GetFamily()
{
    return family;
}

string AttributeConfiguration::GetMember()
{
    return member;
}

string AttributeConfiguration::GetFacility()
{
    return facility;
}

int AttributeConfiguration::GetPort()
{
    return port;
}

int AttributeConfiguration::GetTtl()
{
    return ttl;
}

void AttributeConfiguration::SetID(string ID)
{
    this->ID = ID;
}

string AttributeConfiguration::GetID()
{
    return ID;
}

void AttributeConfiguration::SetParameterFromJson(json& p_json)
{
    data_type = p_json["data_type"];
    domain = p_json["domain"];
    family = p_json["family"];
    member = p_json["member"];
    facility = p_json["facility"];
    port = p_json["port"];
    ttl = p_json["ttl"];
}

AttributeConfiguration::AttributeConfiguration(string pdata_type,
                                               string pdomain,
                                               string pfamily,
                                               string pmember,
                                               string pfacility,
                                               int pport,
                                               int pttl)
{
    data_type = pdata_type;
    domain = pdomain;
    family = pfamily;
    member = pmember;
    facility = pfacility;
    port = pport;
    ttl = pttl;
}

AttributeConfiguration::AttributeConfiguration(json& p_json)
{
    SetParameterFromJson(p_json);
}

AttributeConfiguration::~AttributeConfiguration()
{
}

string AttributeConfiguration::GetJsonQuery()
{
    ostringstream json_str;
    json_str << "{"
             << "\"query\": {"
             << "\"bool\": {"
             << "\"must\": ["
             << " { \"match\": { \"domain\": \"" << domain << "\" } },"
             << " { \"match\": { \"family\": \"" << family << "\" } } , "
             << " { \"match\": { \"member\": \"" << member << "\" } },"
             << " { \"match\": { \"facility\": \"" << facility << "\" } },"
             << " { \"match\": { \"port\": " << port << " } }"
             << "]"
             << "}"
             << "}, \"size\": 1"
             << "}";
    string result = json_str.str().c_str();
    return result;
}

string AttributeConfiguration::ToJson()
{
    json j2 = { { "data_type", data_type },
                { "domain", domain },
                { "family", family },
                { "member", member },
                { "facility", facility },
                { "port", port },
                { "ttl", ttl } };

    return j2.dump();
}

string AttributeConfiguration::ToElkScript4Update()
{
    ostringstream json_str;
    json_str << "ctx._source.data_type = '" << data_type << "';"
             << "ctx._source.domain = '" << domain << "';"
             << "ctx._source.family = '" << family << "';"
             << "ctx._source.member = '" << member << "';"
             << "ctx._source.facility = '" << facility << "';"
             << "ctx._source.port = " << port << ";"
             << "ctx._source.ttl = " << ttl << ";";

    string result = json_str.str().c_str();
    return result;
}

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
        found = true;
        out_json = json::parse(r.body);
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

        // cout << res.dump(4) << "\n" << std::flush;
        /*
         * {"took":7,"timed_out":false,"_shards":{"total":5,"successful":5,"skipped":0,"failed":0},
         * "hits":{"total":25,"max_score":0.66765696,"hits":[{"_index":"configuration","_type":"attribute","_id":"REnD2mABSWhau62WSwCW","_score":0.66765696,"_source":{"data_type":"scalar_devdouble_rw","domain":"sys","facility":"osboxes","family":"tg_test","member":"123","port":10000,"ttl":0}}]}}
         *
         * */
        json the_one_we_search = res["hits"]["hits"][0]["_source"];

        p_attr_conf.SetParameterFromJson(the_one_we_search);
        p_attr_conf.SetID(res["hits"]["hits"][0]["_id"]);
        return true;
    }
    catch (int e)
    {
        return false;
    }
}

bool HDBPP::DAL::SaveAttributeConfiguration(AttributeConfiguration& p_attr_conf)
{
    try
    {
        json res;
        if (!p_attr_conf.GetID().empty()) {
            // update if not empty
            //LOG(Debug) << "updating attribute configuration: \n" << res << endl;
            return UpdateElastic("configuration", "attribute", p_attr_conf.GetID(), p_attr_conf.ToElkScript4Update());
        }

        string out_id;
        json json2store = p_attr_conf.ToJson();
        if (!InsertElastic("configuration", "attribute", json2store, out_id))
            return false;
        //LOG(Debug) << "Inserted attribute configuration: " << out_id << endl;
        p_attr_conf.SetID(out_id);
        return true;
    }
    catch (int e)
    {
        //LOG(Debug) << e << endl;
        return false;
    }
}
};

using namespace HDBPP;

int main(int argc, char** argv)
{
    AttributeConfiguration attr_conf("scalar_devdouble_rw", "sys", "tg_test", "1", "localhost", 10000, 0);
    json toStore = json::parse(attr_conf.ToJson());
    DAL d("localhost:9200");

   /* d.GetAttributeConfiguration(attr_conf);
    attr_conf.SetTtl(987654);
    cout << attr_conf.GetID() << "\n" << std::flush;*/
    d.SaveAttributeConfiguration(attr_conf);

    /*string out_id;
    d.insertElastic("configuration", "attribute", toStore.dump(), out_id);

    json res;
    d.searchElasticByJson("configuration", "attribute", attr_conf.getJsonQuery(), res);

    attr_conf.Setttl(20);
    d.updateElastic("configuration", "attribute", out_id, attr_conf.toElkScript4Update());*/

    printf("hello world\n");
    return 0;
}
