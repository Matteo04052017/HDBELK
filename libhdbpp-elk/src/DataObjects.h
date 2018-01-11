#ifndef _HDBPP_DATAOBJ_H
#define _HDBPP_DATAOBJ_H

#include <iostream>
#include <string>
#include <stdint.h>
#include <stdio.h>
#include "json/json.hpp"
#include "restclient-cpp/connection.h"
#include "restclient-cpp/restclient.h"
#include "AttributeName.h"

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
    string name;
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
    void SetName(string str);
    
    string GetID();
    string GetDataType();
    string GetDomain();
    string GetFamily();
    string GetMember();
    string GetName();
    string GetFacility();
    int GetPort();
    int GetTtl();
    
    void SetParameterFromJson(json& p_json);
    string ToJson();
    string ToElkScript4Update();
    string GetJsonQuery();

    AttributeConfiguration(string data_type,
                           string domain,
                           string family,
                           string member,
                           string name,
                           string facility,
                           int port,
                           int ttl);
    AttributeConfiguration(AttributeName& pattr_name);
    AttributeConfiguration(json& p_json);
    ~AttributeConfiguration();
};

class AttributeConfigurationHistory
{
private:
    string ID;
    string attribute_configuration_id;
    string eventType;
    int64_t time;
    int time_us;

public:
    void SetAttributeConfigurationID(string str);
    void SetEventType(string str);
    void SetTime(int64_t time);
    void SetTimeUs(int time_us);
    void SetID(string id);

    string GetAttributeConfigurationID();
    string GetEventType();
    int64_t GetTime();
    int GetTimeUs();
    string GetID();
    
    void SetParameterFromJson(json& p_json);
    string ToJson();
    string ToElkScript4Update();
    string GetJsonQuery();

    AttributeConfigurationHistory(string attr_conf_id, string eventType, int64_t time, int time_us);
    AttributeConfigurationHistory(json& pjson);
    AttributeConfigurationHistory(AttributeConfiguration attr_conf, string eventType, int64_t time, int time_us);
    AttributeConfigurationHistory(AttributeConfiguration pattr_conf);
    ~AttributeConfigurationHistory();
};

class AttributeEventData
{
};
};

#endif
