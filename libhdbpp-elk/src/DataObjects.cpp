#include "DataObjects.h"

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

string AttributeConfiguration::GetName()
{
    return name;
}

void AttributeConfiguration::SetName(string str)
{
    name = str;
}

AttributeConfiguration::AttributeConfiguration(string pdata_type,
                                               string pdomain,
                                               string pfamily,
                                               string pmember,
                                               string pname,
                                               string pfacility,
                                               int pport,
                                               int pttl)
{
    data_type = pdata_type;
    domain = pdomain;
    family = pfamily;
    member = pmember;
    name = pname;
    facility = pfacility;
    port = pport;
    ttl = pttl;
}

AttributeConfiguration::AttributeConfiguration(AttributeName& pattr_name)
{
    domain = pattr_name.domain();
    family = pattr_name.family();
    member = pattr_name.member();
    name = pattr_name.name();

    std::string s = pattr_name.tango_host();
    std::string delimiter = ":";
    int pos = s.find(delimiter);
    facility = s.substr(0, pos); // localhost
    s = s.substr(pos + delimiter.length());
    port = atoi(s.c_str());
}

AttributeConfiguration::AttributeConfiguration(json& p_json)
{
    SetParameterFromJson(p_json);
}

AttributeConfiguration::~AttributeConfiguration()
{
}

void AttributeConfiguration::SetParameterFromJson(json& p_json)
{
    data_type = p_json["data_type"];
    domain = p_json["domain"];
    family = p_json["family"];
    member = p_json["member"];
    name = p_json["name"];
    facility = p_json["facility"];
    port = p_json["port"];
    ttl = p_json["ttl"];
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
             << " { \"match\": { \"name\": \"" << name << "\" } }"
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
                { "name", name },
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
             << "ctx._source.name = '" << name << "';"
             << "ctx._source.facility = '" << facility << "';"
             << "ctx._source.port = " << port << ";"
             << "ctx._source.ttl = " << ttl << ";";

    string result = json_str.str().c_str();
    return result;
}
};
void HDBPP::AttributeConfigurationHistory::SetAttributeConfigurationID(string str)
{
    attribute_configuration_id = str;
}

void HDBPP::AttributeConfigurationHistory::SetEventType(string str)
{
    eventType = str;
}

void HDBPP::AttributeConfigurationHistory::SetTime(int64_t ptime)
{
    time = ptime;
}

void HDBPP::AttributeConfigurationHistory::SetTimeUs(int ptime_us)
{
    this->time_us = ptime_us;
}

void HDBPP::AttributeConfigurationHistory::SetID(string id)
{
    this->ID = id;
}

string HDBPP::AttributeConfigurationHistory::GetAttributeConfigurationID()
{
    return attribute_configuration_id;
}

string HDBPP::AttributeConfigurationHistory::GetEventType()
{
    return eventType;
}

int64_t HDBPP::AttributeConfigurationHistory::GetTime()
{
    return time;
}

int HDBPP::AttributeConfigurationHistory::GetTimeUs()
{
    return time_us;
}

string HDBPP::AttributeConfigurationHistory::GetID()
{
    return ID;
}

HDBPP::AttributeConfigurationHistory::AttributeConfigurationHistory(AttributeConfiguration pattr_conf)
{
    attribute_configuration_id = pattr_conf.GetID();
}

HDBPP::AttributeConfigurationHistory::AttributeConfigurationHistory(AttributeConfiguration pattr_conf,
                                                                    string peventType,
                                                                    int64_t ptime,
                                                                    int ptime_us)
{
    attribute_configuration_id = pattr_conf.GetID();
    eventType = peventType;
    time = ptime;
    time_us = ptime_us;
}

HDBPP::AttributeConfigurationHistory::AttributeConfigurationHistory(string pattr_conf_id,
                                                                    string peventType,
                                                                    int64_t ptime,
                                                                    int ptime_us)
{
    attribute_configuration_id = pattr_conf_id;
    eventType = peventType;
    time = ptime;
    time_us = ptime_us;
}

HDBPP::AttributeConfigurationHistory::~AttributeConfigurationHistory()
{
}

string HDBPP::AttributeConfigurationHistory::ToJson()
{
    json j2 = { { "attribute_configuration_id", attribute_configuration_id },
                { "eventType", eventType },
                { "time", time },
                { "time_us", time_us } };

    return j2.dump();
}

string HDBPP::AttributeConfigurationHistory::ToElkScript4Update()
{
    ostringstream json_str;
    json_str << "ctx._source.attribute_configuration_id = '" << attribute_configuration_id << "';"
             << "ctx._source.eventType = '" << eventType << "';"
             << "ctx._source.time = '" << time << "';"
             << "ctx._source.time_us = '" << time_us << "';";

    string result = json_str.str().c_str();
    return result;
}

string HDBPP::AttributeConfigurationHistory::GetJsonQuery()
{
    ostringstream json_str;
    json_str << "{"
             << "\"query\": {"
             << "\"bool\": {"
             << "\"must\": ["
             << " { \"match\": { \"attribute_configuration_id\": \"" << attribute_configuration_id << "\" } }"
             << "]"
             << "}"
             << "}, \"size\": 1"
             << "}";
    string result = json_str.str().c_str();
    return result;
}

void HDBPP::AttributeConfigurationHistory::SetParameterFromJson(json& p_json)
{
    attribute_configuration_id = p_json["attribute_configuration_id"];
    eventType = p_json["eventType"];
    time = p_json["time"];
    time_us = p_json["time_us"];
}

HDBPP::AttributeConfigurationHistory::AttributeConfigurationHistory(json& pjson)
{
    SetParameterFromJson(pjson);
}
