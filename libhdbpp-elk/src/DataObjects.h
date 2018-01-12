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
#include "LibHdb++Defines.h"

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

class AttributeParameter
{
private:
    string ID;
    string attribute_configuration_id;
    int64_t ev_time;
    int ev_time_us;
    int64_t insert_time;
    int insert_time_us;
    string label;
    string unit;
    string standardUnit;
    string diplayUnit;
    string format;
    string archiveRelChange;
    string archiveAbsChange;
    string archivePeriod;
    string description;

public:
    void SetID(const string& ID);
    void SetArchiveAbsChange(const string& archiveAbsChange);
    void SetArchivePeriod(const string& archivePeriod);
    void SetArchiveRelChange(const string& archiveRelChange);
    void SetDescription(const string& description);
    void SetDiplayUnit(const string& diplayUnit);
    void SetEvTime(const int64_t& ev_time);
    void SetEvTimeUs(int ev_time_us);
    void SetFormat(const string& format);
    void SetInsertTime(const int64_t& insert_time);
    void SetInsertTimeUs(int insert_time_us);
    void SetLabel(const string& label);
    void SetStandardUnit(const string& standardUnit);
    void SetUnit(const string& unit);
    void SetAttributeConfigurationID(const string& str);
    const string& GetAttributeConfigurationID() const;

    const string& GetID() const;
    const string& GetArchiveAbsChange() const;
    const string& GetArchivePeriod() const;
    const string& GetArchiveRelChange() const;
    const string& GetDescription() const;
    const string& GetDiplayUnit() const;
    const int64_t& GetEvTime() const;
    int GetEvTimeUs() const;
    const string& GetFormat() const;
    const int64_t& GetInsertTime() const;
    int GetInsertTimeUs() const;
    const string& GetLabel() const;
    const string& GetStandardUnit() const;
    const string& GetUnit() const;

    void SetParameterFromJson(json& p_json);
    string ToJson();
    string ToElkScript4Update();
    string GetJsonQuery();

    AttributeParameter(string attribute_configuration_id,
                       int64_t ev_time,
                       int ev_time_us,
                       int64_t insert_time,
                       int insert_time_us,
                       string label,
                       string unit,
                       string standardUnit,
                       string diplayUnit,
                       string format,
                       string archiveRelChange,
                       string archiveAbsChange,
                       string archivePeriod,
                       string description);
    ~AttributeParameter();
};

class AttributeEventData
{
private:
    string ID;
    string attribute_configuration_id;
    string period;
    int64_t ev_time;
    int ev_time_us;
    int64_t rcv_time;
    int rcv_time_us;
    int64_t insert_time;
    int insert_time_us;
    int quality;
    string errorDesc;
    json value_r;
    json value_w;
    int ttl;

public:
    AttributeEventData(string pattribute_configuration_id,
                       string pperiod,
                       int64_t pev_time,
                       int pev_time_us,
                       int64_t prcv_time,
                       int prcv_time_us,
                       int64_t pinsert_time,
                       int pinsert_time_us,
                       int pquality,
                       string perrorDesc,
                       json& pvalue_r,
                       json& pvalue_w,
                       int pttl);
    ~AttributeEventData();

    void SetParameterFromJson(json& p_json);
    string ToJson();
    string ToElkScript4Update();
    string GetJsonQuery();

    void SetAttributeConfigurationId(const string& attribute_configuration_id);
    void SetErrorDesc(const string& errorDesc);
    void SetEvTime(const int64_t& ev_time);
    void SetEvTimeUs(int ev_time_us);
    void SetInsertTime(const int64_t& insert_time);
    void SetInsertTimeUs(int insert_time_us);
    void SetPeriod(const string& period);
    void SetQuality(int quality);
    void SetRcvTime(const int64_t& rcv_time);
    void SetRcvTimeUs(int rcv_time_us);
    void SetTtl(int ttl);
    void SetValueR(const json& value_r);
    void SetValueW(const json& value_w);
    void SetID(const string& ID);

    const string& GetID() const;
    const string& GetAttributeConfigurationId() const;
    const string& GetErrorDesc() const;
    const int64_t& GetEvTime() const;
    int GetEvTimeUs() const;
    const int64_t& GetInsertTime() const;
    int GetInsertTimeUs() const;
    const string& GetPeriod() const;
    int GetQuality() const;
    const int64_t& GetRcvTime() const;
    int GetRcvTimeUs() const;
    int GetTtl() const;
    const json& GetValueR() const;
    const json& GetValueW() const;
};
};

#endif
