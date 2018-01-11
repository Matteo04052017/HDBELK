#include "LibHdb++ELK.h"

const string LOCAL_DC_DEFAULT = "DC1";

namespace HDBPP
{

//=============================================================================
//=============================================================================
void HdbPPELK::string_vector2map(vector<string> str, string separator, map<string, string>* results)
{
    for (vector<string>::iterator it = str.begin(); it != str.end(); it++) {
        string::size_type found_eq;
        found_eq = it->find_first_of(separator);

        if (found_eq != string::npos && found_eq > 0)
            results->insert(make_pair(it->substr(0, found_eq), it->substr(found_eq + 1)));
    }
}

HdbPPELK::HdbPPELK(vector<string> configuration)
{
    map<string, string> libhdb_conf;
    string_vector2map(configuration, "=", &libhdb_conf);
    // string elk_http_repo; string m_keyspace_name;
    string contact_points; //, user, password;
    string local_dc = LOCAL_DC_DEFAULT;

    // ---- logging_enabled optional config parameter ----
    try
    {
        string logging_enabled_state = libhdb_conf.at("logging_enabled");
        logging_enabled_state == "true" ? Log::LogLevel() = Debug : Log::LogLevel() = Error;
    }
    catch (const std::out_of_range& e)
    {
        // setting logging to Error by default
        Log::LogLevel() = Error;
    }

    // ---- Mandatory configuration parameters ----
    try
    {
        contact_points = libhdb_conf.at("contact_points");
        LOG(Debug) << "Configuration \"contact_points\" set to: " << contact_points << endl;
    }
    catch (const std::out_of_range& e)
    {
        stringstream error_desc;

        error_desc << "Configuration parsing error: \"contact_points\" mandatory configuration parameter not found"
                   << ends;

        LOG(Error) << error_desc.str() << endl;
        Tango::Except::throw_exception(EXCEPTION_TYPE_CONFIG, error_desc.str(), __func__);
    }

    try
    {
        m_keyspace_name = libhdb_conf.at("keyspace");
        LOG(Debug) << "contact_points=\"" << contact_points << "\"" << endl;
        LOG(Debug) << "keyspace=\"" << m_keyspace_name << "\"" << endl;
    }
    catch (const std::out_of_range& e)
    {
        stringstream error_desc;

        error_desc << "Configuration parsing error: \"keyspace\" mandatory configuration parameter not found" << ends;

        LOG(Error) << error_desc.str() << endl;
        Tango::Except::throw_exception(EXCEPTION_TYPE_CONFIG, error_desc.str(), __func__);
    }

    try
    {
        elk_http_repo = libhdb_conf.at("elk_http_repo");
    }
    catch (const std::out_of_range& e)
    {
        stringstream error_desc;

        error_desc << "Http url for Elastic repository must be present" << ends;

        LOG(Error) << error_desc.str() << endl;
        Tango::Except::throw_exception(EXCEPTION_TYPE_CONFIG, error_desc.str(), __func__);
    }

    /*try
    {
        local_dc = libhdb_conf.at("local_dc");
    }
    catch (const std::out_of_range &e)
    {
        LOG(Debug) << "Library configuration parameter \"local_dc\" is not defined. Default value DC1 will be used."
                   << endl;
    }*/
}

HdbPPELK::~HdbPPELK()
{
    TRACE_ENTER;

    TRACE_EXIT;
}

void HdbPPELK::insert_param_Attr(Tango::AttrConfEventData* data, HdbEventDataType ev_data_type)
{
    TRACE_ENTER;
    LOG(Warning) << "insert_param_Attr";

    /*if (data == NULL) {
        stringstream error_desc;
        error_desc << "Unexpected null Tango::AttrConfEventData" << ends;
        LOG(Error) << error_desc.str() << endl;
        Tango::Except::throw_exception(EXCEPTION_TYPE_NULL_POINTER, error_desc.str(), __func__);
    }

    if (data->attr_conf == NULL) {
        stringstream error_desc;
        error_desc << "Unexpected null in Tango::AttrConfEventData field attr_conf" << ends;
        LOG(Error) << error_desc.str() << endl;
        Tango::Except::throw_exception(EXCEPTION_TYPE_NULL_POINTER, error_desc.str(), __func__);
    }

    AttributeName attr_name(data->attr_name);
    int64_t ev_time = ((int64_t)data->get_date().tv_sec) * 1000;
    int ev_time_us = data->get_date().tv_usec;

    string uuid;

    if (!find_attr_id(attr_name, uuid)) {
        LOG(Error) << "Could not find ID for attribute " << attr_name << endl;
        stringstream error_desc;
        error_desc << "ERROR Could not find ID for attribute  \"" << attr_name << "\": " << ends;
        Tango::Except::throw_exception(EXCEPTION_TYPE_MISSING_ATTR, error_desc.str().c_str(), __func__);
    }

    LOG(Debug) << " label: \"" << data->attr_conf->label.c_str() << "\"" << endl;
    LOG(Debug) << " unit: \"" << data->attr_conf->unit.c_str() << "\"" << endl;
    LOG(Debug) << " standard unit: \"" << data->attr_conf->standard_unit.c_str() << "\"" << endl;
    LOG(Debug) << " display unit: \"" << data->attr_conf->display_unit.c_str() << "\"" << endl;
    LOG(Debug) << " format: \"" << data->attr_conf->format.c_str() << "\"" << endl;
    LOG(Debug) << " archive rel change: \"" << data->attr_conf->events.arch_event.archive_rel_change.c_str() << "\""
               << endl;
    LOG(Debug) << " archive abs change: \"" << data->attr_conf->events.arch_event.archive_abs_change.c_str() << "\""
               << endl;
    LOG(Debug) << " archive period: \"" << data->attr_conf->events.arch_event.archive_period.c_str() << "\"" << endl;
    LOG(Debug) << " description: \"" << data->attr_conf->description.c_str() << "\"" << endl;
    LOG(Debug) << " after binding description" << endl;

    // Get the current time
    struct timespec ts;
    if (clock_gettime(CLOCK_REALTIME, &ts) != 0)
        perror("clock_gettime()");

    int64_t insert_time = ((int64_t)ts.tv_sec) * 1000;
    int insert_time_us = ts.tv_nsec / 1000;

    // build the json object to store in type PARAM_TABLE_NAME
    json to_store = { { PARAM_COL_ID, uuid },
                      { PARAM_COL_EV_TIME, ev_time },
                      { PARAM_COL_EV_TIME_US, ev_time_us },
                      { PARAM_COL_INS_TIME, insert_time },
                      { PARAM_COL_INS_TIME_US, insert_time_us },
                      { PARAM_COL_LABEL, data->attr_conf->label.c_str() },
                      { PARAM_COL_UNIT, data->attr_conf->unit.c_str() },
                      { PARAM_COL_STANDARDUNIT, data->attr_conf->standard_unit.c_str() },
                      { PARAM_COL_DISPLAYUNIT, data->attr_conf->display_unit.c_str() },
                      { PARAM_COL_FORMAT, data->attr_conf->format.c_str() },
                      { PARAM_COL_ARCHIVERELCHANGE, data->attr_conf->events.arch_event.archive_rel_change.c_str() },
                      { PARAM_COL_ARCHIVEABSCHANGE, data->attr_conf->events.arch_event.archive_abs_change.c_str() },
                      { PARAM_COL_ARCHIVEPERIOD, data->attr_conf->events.arch_event.archive_period.c_str() },
                      { PARAM_COL_DESCRIPTION, data->attr_conf->description.c_str() }, };

    string out_id;
    insertElastic(attr_name.tango_host_with_domain().c_str(), PARAM_TABLE_NAME, to_store, out_id);*/
}

void HdbPPELK::insert_Attr(Tango::EventData* data, HdbEventDataType ev_data_type)
{
    TRACE_ENTER;

    /*if (data == NULL) {
        stringstream error_desc;
        error_desc << "Unexpected null Tango::EventData" << ends;
        LOG(Error) << error_desc.str() << endl;
        Tango::Except::throw_exception(EXCEPTION_TYPE_NULL_POINTER, error_desc.str(), __func__);
    }

    AttributeName attr_name(data->attr_name);

    int64_t ev_time;
    int ev_time_us;
    int64_t rcv_time = ((int64_t)data->get_date().tv_sec) * 1000;
    int rcv_time_us = data->get_date().tv_usec;
    int quality = (int)data->attr_value->get_quality();
    string error_desc("");

    Tango::AttributeDimension attr_w_dim;
    Tango::AttributeDimension attr_r_dim;
    int data_type = ev_data_type.data_type;
    Tango::AttrDataFormat data_format = ev_data_type.data_format;
    int write_type = ev_data_type.write_type;

    bool is_null = false;
    if (data->err) {
        LOG(Debug) << "Attribute in error:" << error_desc << endl;

        is_null = true;
        // Store the error description
        error_desc = data->errors[0].desc;
    }

    data->attr_value->reset_exceptions(Tango::DeviceAttribute::isempty_flag); // disable is_empty exception

    if (data->attr_value->is_empty()) {
        LOG(Debug) << "no value will be archived... (Attr Value is empty)" << endl;
        is_null = true;
    }

    if (quality == Tango::ATTR_INVALID) {
        LOG(Debug) << "no value will be archived... (Invalid Attribute)" << endl;
        is_null = true;
    }

    LOG(Debug) << "data_type=" << data_type << " data_format=" << data_format << " write_type=" << write_type << endl;

    if (!is_null) {
        attr_w_dim = data->attr_value->get_w_dimension();
        attr_r_dim = data->attr_value->get_r_dimension();
        ev_time = ((int64_t)data->attr_value->get_date().tv_sec) * 1000;
        ev_time_us = data->attr_value->get_date().tv_usec;
    } else {
        attr_r_dim.dim_x = 0; // max_dim_x;//TODO: OK?
        attr_w_dim.dim_x = 0; // max_dim_x;//TODO: OK?
        attr_r_dim.dim_y = 0; // max_dim_y;//TODO: OK?
        attr_w_dim.dim_y = 0; // max_dim_y;//TODO: OK?
        ev_time = rcv_time;
        ev_time_us = rcv_time_us;
    }

    string id;
    unsigned int ttl = 0;

    if (find_attr_id_and_ttl(attr_name, id, ttl)) {
        LOG(Error) << "Could not find ID for attribute " << attr_name << endl;
        stringstream error_desc;
        error_desc << "ERROR Could not find ID for attribute  \"" << attr_name << "\": " << ends;
        Tango::Except::throw_exception(EXCEPTION_TYPE_MISSING_ATTR, error_desc.str().c_str(), __func__);
    }

    // Compute the period based on the month of the event time
    struct tm* tms;
    time_t ev_time_s = ev_time / 1000;

    if ((tms = localtime(&ev_time_s)) == NULL)
        perror("localtime");

    char period[11];
    snprintf(period, 11, "%04d-%02d-%02d", tms->tm_year + 1900, tms->tm_mon + 1, tms->tm_mday);

    // Get the current time
    struct timespec ts;
    if (clock_gettime(CLOCK_REALTIME, &ts) != 0)
        perror("clock_gettime()");

    int64_t insert_time = ((int64_t)ts.tv_sec) * 1000;
    int insert_time_us = ts.tv_nsec / 1000;

    json to_store = { { SC_COL_ID, id },
                      { SC_COL_PERIOD, period },
                      { SC_COL_EV_TIME, ev_time },
                      { SC_COL_EV_TIME_US, ev_time_us },
                      { SC_COL_RCV_TIME, rcv_time },
                      { SC_COL_RCV_TIME_US, rcv_time_us },
                      { SC_COL_INS_TIME, insert_time },
                      { SC_COL_INS_TIME_US, insert_time_us },
                      { SC_COL_QUALITY, quality },
                      { SC_COL_ERROR_DESC, error_desc.c_str() } };

    if (write_type != Tango::WRITE) // RO or RW
    {
        to_store += { SC_COL_VALUE_R, extract_read(data, data_type) };
    }
    if (write_type != Tango::READ) // RW or WO
    {
        to_store += { SC_COL_VALUE_W, extract_set(data, data_type) };
    }
    if (ttl != 0)
        to_store += { "_ttl", { "enabled", true, "default", (ttl * 3600) + "ms" } };

    string out_id;
    insertElastic(attr_name.tango_host_with_domain().c_str(), PARAM_TABLE_NAME, to_store, out_id);

    TRACE_EXIT;*/
}

void HdbPPELK::configure_Attr(string name, int type, int format, int write_type, unsigned int ttl)
{
    TRACE_ENTER;

    AttributeName attr_name(name);
    LOG(Debug) << "name=" << name << " -> tango_host=" << attr_name.tango_host_with_domain()
               << " attr_name=" << attr_name << endl;

    AttributeConfiguration attr_conf(attr_name);
    DAL d(elk_http_repo);

    if (attr_name.validate_domain_family_member_name() != AttributeName::NoError) {
        stringstream error_desc;

        error_desc << attr_name.tango_host_with_domain() << "/" << attr_name
                   << " already configured with different configuration."
                   << "Please contact your administrator for this special case" << ends;

        LOG(Error) << error_desc.str() << endl;
        Tango::Except::throw_exception(EXCEPTION_TYPE_NULL_POINTER, error_desc.str(), __func__);
    }

    string data_type = get_data_type(type, format, write_type);
    struct timespec ts;
    if (clock_gettime(CLOCK_REALTIME, &ts) != 0) {
        perror("clock_gettime()"); // TODO handle this error?
    }
    int64_t current_time = ((int64_t)ts.tv_sec) * 1000;
    int current_time_us = ts.tv_nsec / 1000;

    bool already_configured = d.GetAttributeConfiguration(attr_conf);

    if (!already_configured) {
        attr_conf.SetDataType(data_type);
        attr_conf.SetTtl(ttl);
        LOG(Error) << "Save Attribute Configuration " << attr_conf.ToJson() << endl;
        d.SaveAttributeConfiguration(attr_conf);
        AttributeConfigurationHistory attr_conf_history(attr_conf, EVENT_ADD, current_time, current_time_us);
        LOG(Error) << "Save Attribute Configuration History" << attr_conf_history.ToJson() << endl;
        d.SaveAttributeConfigurationHistory(attr_conf_history);

        TRACE_EXIT;
        return;
    }
    
    // if (already_configured) {
    if (attr_conf.GetDataType().compare(data_type) != 0) {
        stringstream error_desc;

        error_desc << attr_name.tango_host_with_domain() << "/" << attr_name
                   << " already configured with different configuration."
                   << "Please contact your administrator for this special case" << ends;

        LOG(Error) << error_desc.str() << endl;
        Tango::Except::throw_exception(EXCEPTION_TYPE_NULL_POINTER, error_desc.str(), __func__);
    }

    LOG(Debug) << "ALREADY CONFIGURED with same configuration: " << attr_name.tango_host_with_domain() << "/"
               << attr_name << endl;

    if (attr_conf.GetTtl() != ttl) {
        LOG(Debug) << ".... BUT different ttl: updating " << attr_conf.GetTtl() << " to " << ttl << endl;
        attr_conf.SetTtl(ttl);
        LOG(Error) << "Save Attribute Configuration " << attr_conf.ToJson() << endl;
        d.SaveAttributeConfiguration(attr_conf);
    }

    AttributeConfigurationHistory attr_conf_history(attr_conf);
    if (d.GetAttributeConfigurationHistory(attr_conf_history)) {
        if (attr_conf_history.GetEventType().compare(EVENT_REMOVE) == 0) {
            LOG(Error) << "Save Attribute Configuration History" << attr_conf_history.ToJson() << endl;
            d.SaveAttributeConfigurationHistory(attr_conf_history);
        }
    }

    TRACE_EXIT;
}

void HdbPPELK::updateTTL_Attr(string fqdn_attr_name, unsigned int ttl)
{
    /*TRACE_ENTER;

    AttributeName attr_name(fqdn_attr_name);
    string id;

    if (!find_attr_id(attr_name, id)) {
        stringstream error_desc;
        error_desc << "ERROR Attribute " << attr_name << " NOT FOUND in HDB++ configuration table" << ends;
        LOG(Error) << error_desc.str() << endl;
        Tango::Except::throw_exception(EXCEPTION_TYPE_MISSING_ATTR, error_desc.str(), __func__);
    }

    json attr_conf_update = { CONF_COL_TTL, ttl };
    updateElastic(m_keyspace_name, CONF_TABLE_NAME, id, attr_conf_update);
    TRACE_EXIT;*/
}

void HdbPPELK::event_Attr(string fqdn_attr_name, unsigned char event)
{
    /*TRACE_ENTER;

    struct timespec ts;
    if (clock_gettime(CLOCK_REALTIME, &ts) != 0) {
        // TODO handle this error?
        perror("clock_gettime()");
    }
    int64_t current_time = ((int64_t)ts.tv_sec) * 1000;
    int current_time_us = ts.tv_nsec / 1000;

    AttributeName attr_name(fqdn_attr_name);
    string uuid;

    if (!find_attr_id(attr_name, uuid)) {
        stringstream error_desc;
        error_desc << "ERROR Attribute " << attr_name << " NOT FOUND in HDB++ configuration table" << ends;
        LOG(Error) << error_desc.str() << endl;
        Tango::Except::throw_exception(EXCEPTION_TYPE_MISSING_ATTR, error_desc.str().c_str(), __func__);
    }

    string event_name = "";

    switch (event) {
    case DB_START: {
        string index = m_keyspace_name;
        string type = HISTORY_TABLE_NAME;
        json jsonQuery = { { "size", 1 },
                           { "query", { "term", { { HISTORY_COL_ID, uuid }, { HISTORY_COL_EVENT, EVENT_REMOVE } } } },
                           { "sort", { HISTORY_COL_TIME, "desc" } } };

        json out_json;
        bool ret = false;
        if (searchElasticByJson(index, type, jsonQuery, out_json))
            ret = true;

        string last_event = out_json[HISTORY_COL_EVENT];
        if (ret && last_event == EVENT_START) {
            // It seems there was a crash
            json history_event = { { HISTORY_COL_ID, uuid },
                                   { HISTORY_COL_EVENT, EVENT_CRASH },
                                   { HISTORY_COL_TIME, current_time },
                                   { HISTORY_COL_TIME_US, current_time_us } };
            string out_event_id;
            insertElastic(m_keyspace_name, HISTORY_TABLE_NAME, history_event, out_event_id);
        }
        event_name = EVENT_START;
        break;
    }
    case DB_STOP: {
        event_name = EVENT_STOP;
        break;
    }
    case DB_REMOVE: {
        event_name = EVENT_REMOVE;
        break;
    }
    case DB_PAUSE: {
        event_name = EVENT_PAUSE;
        break;
    }
    default: {
        stringstream error_desc;
        error_desc << "ERROR for " << attr_name << " event=" << (int)event << " NOT SUPPORTED" << ends;
        LOG(Error) << error_desc.str() << endl;
        Tango::Except::throw_exception(EXCEPTION_TYPE_MISSING_ATTR, error_desc.str(), __func__);
    }
    }

    json history_event = { { HISTORY_COL_ID, uuid },
                           { HISTORY_COL_EVENT, event_name },
                           { HISTORY_COL_TIME, current_time },
                           { HISTORY_COL_TIME_US, current_time_us } };
    string out_event_id;
    insertElastic(m_keyspace_name, HISTORY_TABLE_NAME, history_event, out_event_id);

    TRACE_EXIT;*/
}

//=============================================================================
//=============================================================================
AbstractDB* HdbPPELKFactory::create_db(vector<string> configuration)
{
    return new HdbPPELK(configuration);
}

/*bool HdbPPELK::insertElastic(string index, string type, json in_json, string out_id)
{
    TRACE_ENTER;

    std::stringstream qurl;
    qurl << elk_http_repo << "/" << index << "/" << type << "/";

    RestClient::init();
    RestClient::Connection* conn = new RestClient::Connection(qurl.str());
    RestClient::HeaderFields headers;
    headers["Content-Type"] = "application/json";
    conn->SetHeaders(headers);
    RestClient::Response r = conn->post("", in_json.dump());

    LOG(Debug) << r.code << "\n"; // HTTP response code
    LOG(Debug) << r.body << "\n"; // HTTP response body

    bool found = false;
    if (r.code == HTTP_STATUS_CREATED) {
        found = true;
        auto res = json::parse(r.body);
        out_id = res["_id"];
    }

    RestClient::disable();
    TRACE_EXIT;
    return found;
}

bool HdbPPELK::updateElastic(string index, string type, string id, string update_json_doc)
{
    TRACE_ENTER;

    std::stringstream qurl;
    qurl << elk_http_repo << "/" << index << "/" << type << "/" << id << "/_update";

    RestClient::init();
    RestClient::Connection* conn = new RestClient::Connection(qurl.str());
    RestClient::HeaderFields headers;
    headers["Content-Type"] = "application/json";
    conn->SetHeaders(headers);

    json in_json = { { "doc", { update_json_doc } } };

    RestClient::Response r = conn->post("", in_json.dump());

    LOG(Debug) << r.code << "\n"; // HTTP response code
    LOG(Debug) << r.body << "\n"; // HTTP response body

    bool found = false;
    if (r.code == HTTP_STATUS_OK)
        found = true;

    RestClient::disable();
    TRACE_EXIT;
    return found;
}

bool HdbPPELK::searchElastic(string index, string type, string query, json out_json)
{
    TRACE_ENTER;
    LOG(Debug) << "stica";
    std::stringstream qurl;
    qurl << elk_http_repo << "/" << index << "/" << type << "/"
         << "_search?q=" << query;

    LOG(Debug) << "stica==" << qurl.str();
    RestClient::Response r = RestClient::get(qurl.str());

    LOG(Debug) << r.code << "\n" << r.body << "\n"; // HTTP response

    bool found = false;
    if (r.code == HTTP_STATUS_OK) {
        found = true;
        out_json = json::parse(r.body);
    }

    TRACE_EXIT;
    return found;
}

bool HdbPPELK::searchElasticByJson(string index, string type, json json_search, json out_json)
{
    TRACE_ENTER;
    std::stringstream qurl;
    qurl << elk_http_repo << "/" << index << "/" << type << "/"
         << "_search";

    RestClient::init();
    RestClient::Connection* conn = new RestClient::Connection(qurl.str());
    RestClient::HeaderFields headers;
    headers["Content-Type"] = "application/json";
    conn->SetHeaders(headers);
    RestClient::Response r = conn->post("", json_search.dump());

    LOG(Debug) << r.code << "\n" << r.body << "\n"; // HTTP response

    bool found = false;
    if (r.code == HTTP_STATUS_OK) {
        found = true;
        out_json = json::parse(r.body);
    }

    TRACE_EXIT;
    return found;
}*/

//=============================================================================
//=============================================================================
string HdbPPELK::get_data_type(int type /*DEV_DOUBLE, DEV_STRING, ..*/,
                               int format /*SCALAR, SPECTRUM, ..*/,
                               int write_type /*READ, READ_WRITE, ..*/) const
{
    TRACE_ENTER;

    ostringstream data_type;

    if (format == Tango::SCALAR) {
        data_type << TYPE_SCALAR << "_";
    } else {
        data_type << TYPE_ARRAY << "_";
    }

    switch (type) {
    case Tango::DEV_BOOLEAN:
        data_type << TYPE_DEV_BOOLEAN << "_";
        break;
    case Tango::DEV_UCHAR:
        data_type << TYPE_DEV_UCHAR << "_";
        break;
    case Tango::DEV_SHORT:
        data_type << TYPE_DEV_SHORT << "_";
        break;
    case Tango::DEV_USHORT:
        data_type << TYPE_DEV_USHORT << "_";
        break;
    case Tango::DEV_LONG:
        data_type << TYPE_DEV_LONG << "_";
        break;
    case Tango::DEV_ULONG:
        data_type << TYPE_DEV_ULONG << "_";
        break;
    case Tango::DEV_LONG64:
        data_type << TYPE_DEV_LONG64 << "_";
        break;
    case Tango::DEV_ULONG64:
        data_type << TYPE_DEV_ULONG64 << "_";
        break;
    case Tango::DEV_FLOAT:
        data_type << TYPE_DEV_FLOAT << "_";
        break;
    case Tango::DEV_DOUBLE:
        data_type << TYPE_DEV_DOUBLE << "_";
        break;
    case Tango::DEV_STRING:
        data_type << TYPE_DEV_STRING << "_";
        break;
    case Tango::DEV_STATE:
        data_type << TYPE_DEV_STATE << "_";
        break;
    case Tango::DEV_ENCODED:
        data_type << TYPE_DEV_ENCODED << "_";
        break;
    default:
        stringstream error_desc;
        error_desc << "(" << type << ", ...): Type not supported (" << __FILE__ << ":" << __LINE__ << ")" << ends;
        LOG(Error) << error_desc.str() << endl;
        Tango::Except::throw_exception(EXCEPTION_TYPE_UNSUPPORTED_ATTR, error_desc.str(), __func__);
    }

    if (write_type == Tango::READ) {
        data_type << TYPE_RO;
    } else {
        data_type << TYPE_RW;
    }

    TRACE_EXIT;
    return data_type.str();
}

bool HdbPPELK::find_attr_id(AttributeName& attr_name, string ID)
{
    TRACE_ENTER;

    // First look into the cache
    map<string, AttributeParams>::iterator it = attribute_cache.find(attr_name.fully_qualified_attribute_name());

    if (it == attribute_cache.end()) {
        // if not already present in cache, look for ID in the DB
        unsigned int ttl = 0;
        string attr_type;
        if (!find_attr_id_type_and_ttl(attr_name, ID, attr_type, ttl)) {
            LOG(Debug) << "ID not found for attr=" << attr_name << endl;
            TRACE_EXIT;
            return false;
        }
    } else {
        ID = it->second.id;
    }

    TRACE_EXIT;
    return true;
}

//=============================================================================
//=============================================================================
bool HdbPPELK::find_attr_id_and_ttl(AttributeName& attr_name, string ID, unsigned int& ttl)
{
    TRACE_ENTER;

    // First look into the cache
    map<string, AttributeParams>::iterator it = attribute_cache.find(attr_name.fully_qualified_attribute_name());

    if (it == attribute_cache.end()) {
        // if not already present in cache, look for ID in the DB
        unsigned int ttl = 0;
        string attr_type;
        if (!find_attr_id_type_and_ttl(attr_name, ID, attr_type, ttl)) {
            LOG(Debug) << "ID not found for attr=" << attr_name << endl;
            TRACE_EXIT;
            return false;
        }
    } else {
        ID = it->second.id;
        ttl = it->second.ttl;
    }

    TRACE_EXIT;
    return true;
}

FindAttrResult
HdbPPELK::find_attr_id_type_and_ttl(AttributeName& attr_name, string ID, string attr_type, unsigned int& conf_ttl)
{
    return AttrNotFound;
    /*TRACE_ENTER;

    string index = m_keyspace_name;
    string type = CONF_TABLE_NAME;
    json out_json;
    string db_type;
    json jsonQuery = { { "size", 1 },
                       { "query", { "term", { CONF_COL_NAME, attr_name.full_attribute_name().c_str() } } } };

    LOG(Debug) << jsonQuery << endl;
    bool found = false;
    if (searchElasticByJson(index, type, jsonQuery, out_json)) {
        try
        {
            ID = out_json[CONF_COL_ID];
            db_type = out_json[CONF_COL_TYPE];
            conf_ttl = out_json[CONF_COL_TTL].get<int>();
            attribute_cache.insert(
                make_pair(attr_name.fully_qualified_attribute_name(), AttributeParams(ID, conf_ttl)));
            found = true;
        }
        catch (json::type_error& e)
        {
            LOG(Debug) << "NO RESULT in query: " << jsonQuery << endl;
            TRACE_EXIT;
            return AttrNotFound;
        }
    }

    if (!found) {
        LOG(Debug) << "NO RESULT in query: " << jsonQuery << endl;
        TRACE_EXIT;
        return AttrNotFound;
    } else if (db_type != attr_type) {
        LOG(Debug) << "FOUND ID for " << attr_name.tango_host_with_domain() << "/" << attr_name.full_attribute_name()
                   << " but different type: attr_type=" << attr_type << "-db_type=" << db_type << endl;

        TRACE_EXIT;
        return FoundAttrWithDifferentType;
    }

    LOG(Debug) << "FOUND ID for " << attr_name.tango_host_with_domain() << "/" << attr_name.full_attribute_name()
               << " with SAME type: attr_type=" << attr_type << "-db_type=" << db_type << endl;

    TRACE_EXIT;
    return FoundAttrWithSameType;*/
}

//=============================================================================
//=============================================================================
json HdbPPELK::extract_read(Tango::EventData* data, int data_type)
{
    TRACE_ENTER;
    json result;
    vector<bool> vbool;
    vector<unsigned char> vUnsignedChar;
    vector<short> vshort;
    vector<unsigned short> vUshort;
    vector<long> vlong;
    vector<unsigned long> vUlong;
    vector<int64_t> vInt64;
    vector<Tango::DevState> vState;
    vector<float> vfloat;
    vector<double> vdouble;
    vector<string> vString;
    bool extract_success = false;
    // There is a read value
    switch (data_type) {
    case Tango::DEV_BOOLEAN:
        if (data->attr_value->extract_read(vbool)) {
            result = vbool;
        };
    case Tango::DEV_UCHAR:
        if (data->attr_value->extract_read(vUnsignedChar)) {
            result = (vUnsignedChar);
        }
    case Tango::DEV_SHORT:
        if (data->attr_value->extract_read(vshort)) {
            result = (vshort);
        }
        break;
    case Tango::DEV_USHORT:
        if (data->attr_value->extract_read(vUshort)) {
            result = (vUshort);
        }
        break;
    case Tango::DEV_LONG:
        if (data->attr_value->extract_read(vlong)) {
            result = (vlong);
        }
        break;
    case Tango::DEV_ULONG:
        if (data->attr_value->extract_read(vUlong)) {
            result = (vUlong);
        }
        break;
    case Tango::DEV_LONG64:

        if (data->attr_value->extract_read(vInt64)) {
            result = (vInt64);
        }
        break;
    case Tango::DEV_FLOAT:

        if (data->attr_value->extract_read(vfloat)) {
            result = (vfloat);
        }
        break;
    case Tango::DEV_DOUBLE:

        if (data->attr_value->extract_read(vdouble)) {
            result = (vdouble);
        }
        break;
    case Tango::DEV_STRING:

        if (data->attr_value->extract_read(vString)) {
            result = (vString);
        }
        break;
    case Tango::DEV_STATE:

        if (data->attr_value->extract_read(vState)) {
            result = (vState);
        }
        break;
    default: {
        stringstream error_desc;
        error_desc << "Attribute " << data->attr_name << " type (" << (int)(data_type) << ")) not supported" << ends;
        LOG(Error) << error_desc.str() << endl;
        Tango::Except::throw_exception(EXCEPTION_TYPE_UNSUPPORTED_ATTR, error_desc.str(), __func__);
    }
    } // switch(data_type)

    if (!extract_success) {
        stringstream error_desc;
        error_desc << "Failed to extract the attribute " << data->attr_name
                   << " from the Tango EventData. Possible type mismatch?" << ends;
        LOG(Error) << error_desc.str() << endl;
        Tango::Except::throw_exception(EXCEPTION_TYPE_EXTRACT, error_desc.str(), __func__);
    }

    return result;
}

//=============================================================================
//=============================================================================
json HdbPPELK::extract_set(Tango::EventData* data, int data_type)
{
    TRACE_ENTER;
    json result;
    vector<bool> vbool;
    vector<unsigned char> vUnsignedChar;
    vector<short> vshort;
    vector<unsigned short> vUshort;
    vector<long> vlong;
    vector<unsigned long> vUlong;
    vector<float> vfloat;
    vector<double> vdouble;

    vector<string> vString;
    vector<int64_t> vInt64;
    vector<Tango::DevState> vState;
    bool extract_success = false;
    // There is a read value
    switch (data_type) {
    case Tango::DEV_BOOLEAN:
        if (data->attr_value->extract_set(vbool)) {
            result = vbool;
        };
    case Tango::DEV_UCHAR:
        if (data->attr_value->extract_set(vUnsignedChar)) {
            result = (vUnsignedChar);
        }
    case Tango::DEV_SHORT:
        if (data->attr_value->extract_set(vshort)) {
            result = (vshort);
        }
        break;
    case Tango::DEV_USHORT:
        if (data->attr_value->extract_set(vUshort)) {
            result = (vUshort);
        }
        break;
    case Tango::DEV_LONG:
        if (data->attr_value->extract_set(vlong)) {
            result = (vlong);
        }
        break;
    case Tango::DEV_ULONG:
        if (data->attr_value->extract_set(vUlong)) {
            result = (vUlong);
        }
        break;
    case Tango::DEV_LONG64:

        if (data->attr_value->extract_set(vInt64)) {
            result = (vInt64);
        }
        break;
    case Tango::DEV_FLOAT:

        if (data->attr_value->extract_set(vfloat)) {
            result = (vfloat);
        }
        break;
    case Tango::DEV_DOUBLE:

        if (data->attr_value->extract_set(vdouble)) {
            result = (vdouble);
        }
        break;
    case Tango::DEV_STRING:

        if (data->attr_value->extract_set(vString)) {
            result = (vString);
        }
        break;
    case Tango::DEV_STATE:

        if (data->attr_value->extract_set(vState)) {
            result = (vState);
        }
        break;
    default: {
        stringstream error_desc;
        error_desc << "Attribute " << data->attr_name << " type (" << (int)(data_type) << ")) not supported" << ends;
        LOG(Error) << error_desc.str() << endl;
        Tango::Except::throw_exception(EXCEPTION_TYPE_UNSUPPORTED_ATTR, error_desc.str(), __func__);
    }
    } // switch(data_type)

    if (!extract_success) {
        stringstream error_desc;
        error_desc << "Failed to extract the attribute " << data->attr_name
                   << " from the Tango EventData. Possible type mismatch?" << ends;
        LOG(Error) << error_desc.str() << endl;
        Tango::Except::throw_exception(EXCEPTION_TYPE_EXTRACT, error_desc.str(), __func__);
    }

    return result;
}
// end Helper
}; // namespace

//=============================================================================
//=============================================================================
DBFactory* getDBFactory()
{
    HDBPP::HdbPPELKFactory* db_ELK_factory = new HDBPP::HdbPPELKFactory();
    return static_cast<DBFactory*>(db_ELK_factory);
}

/*using namespace HDBPP;

int main(int argc, char ** argv)
{
    vector<string> lib_config;
        lib_config.push_back("contact_points=teone");
        lib_config.push_back("keyspace=osboxes");
    HdbPPELK myDB = HdbPPELK(lib_config);

        try
        {
            string ID;
                unsigned int ttl_at_start = 0;
                unsigned int ttl_at_end = 0;

                string fqdn_attr_name = "tango://localhost:10000/sys/tg_test/1/float_scalar";

        AttributeName attr_name(fqdn_attr_name);
            cout << "attr name = " << fqdn_attr_name << endl;
            int err = myDB.find_attr_id_and_ttl(attr_name, ID, ttl_at_start);

                cout << "find_attr_id_and_ttl(" << fqdn_attr_name << ") returned " << err << endl;

                cout << "ttl = " << ttl_at_start << endl;
        }
        catch(Tango::DevFailed e)
        {
                Tango::Except::print_exception(e);
                return -2;
        }
    return 0;
}*/