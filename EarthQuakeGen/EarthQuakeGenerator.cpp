/*----- PROTECTED REGION ID(EarthQuakeGenerator.cpp) ENABLED START -----*/
static const char* RcsId = "$Id:  $";
//=============================================================================
//
// file :        EarthQuakeGenerator.cpp
//
// description : C++ source for the EarthQuakeGenerator class and its commands.
//               The class is derived from Device. It represents the
//               CORBA servant object which will be accessed from the
//               network. All commands which can be executed on the
//               EarthQuakeGenerator are implemented in this file.
//
// project :     EarthQuakeGenerator
//
// This file is part of Tango device class.
//
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
//
// $Author:  $
// Matteo Di Carlo INAF
//
// $Revision:  $
// $Date:  $
//
// $HeadURL:  $
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================
using namespace std;

#include <EarthQuakeGenerator.h>
#include <EarthQuakeGeneratorClass.h>

/*----- PROTECTED REGION END -----*/ //	EarthQuakeGenerator.cpp

/**
 *  EarthQuakeGenerator class description:
 *    EarthQuakeGenerator
 */

//================================================================
//  The following table gives the correspondence
//  between command and method names.
//
//  Command name  |  Method name
//================================================================
//  State         |  Inherited (no method)
//  Status        |  Inherited (no method)
//  NextEvent     |  next_event
//  Stop          |  stop
//================================================================

//================================================================
//  Attributes managed are:
//================================================================
//  DateReferenceEvent   |  Tango::DevString	Scalar
//  Latitude             |  Tango::DevDouble	Scalar
//  Longitude            |  Tango::DevDouble	Scalar
//  Depth                |  Tango::DevDouble	Scalar
//  ReportedMagnitudes   |  Tango::DevString	Scalar
//  GeographicaLocation  |  Tango::DevString	Scalar
//  JsonTrans            |  Tango::DevString	Scalar
//  NdkFileName          |  Tango::DevString	Scalar
//  archiveValue         |  Tango::DevString	Scalar
//================================================================

namespace EarthQuakeGenerator_ns
{
/*----- PROTECTED REGION ID(EarthQuakeGenerator::namespace_starting) ENABLED START -----*/

//	static initializations

/*----- PROTECTED REGION END -----*/ //	EarthQuakeGenerator::namespace_starting

//--------------------------------------------------------
/**
 *	Method      : EarthQuakeGenerator::EarthQuakeGenerator()
 *	Description : Constructors for a Tango device
 *                implementing the classEarthQuakeGenerator
 */
//--------------------------------------------------------
EarthQuakeGenerator::EarthQuakeGenerator(Tango::DeviceClass* cl, string& s) : TANGO_BASE_CLASS(cl, s.c_str())
{
    /*----- PROTECTED REGION ID(EarthQuakeGenerator::constructor_1) ENABLED START -----*/
    init_device();

    /*----- PROTECTED REGION END -----*/ //	EarthQuakeGenerator::constructor_1
}
//--------------------------------------------------------
EarthQuakeGenerator::EarthQuakeGenerator(Tango::DeviceClass* cl, const char* s) : TANGO_BASE_CLASS(cl, s)
{
    /*----- PROTECTED REGION ID(EarthQuakeGenerator::constructor_2) ENABLED START -----*/
    init_device();

    /*----- PROTECTED REGION END -----*/ //	EarthQuakeGenerator::constructor_2
}
//--------------------------------------------------------
EarthQuakeGenerator::EarthQuakeGenerator(Tango::DeviceClass* cl, const char* s, const char* d)
    : TANGO_BASE_CLASS(cl, s, d)
{
    /*----- PROTECTED REGION ID(EarthQuakeGenerator::constructor_3) ENABLED START -----*/
    init_device();

    /*----- PROTECTED REGION END -----*/ //	EarthQuakeGenerator::constructor_3
}

//--------------------------------------------------------
/**
 *	Method      : EarthQuakeGenerator::delete_device()
 *	Description : will be called at device destruction or at init command
 */
//--------------------------------------------------------
void EarthQuakeGenerator::delete_device()
{
    DEBUG_STREAM << "EarthQuakeGenerator::delete_device() " << device_name << endl;
    /*----- PROTECTED REGION ID(EarthQuakeGenerator::delete_device) ENABLED START -----*/

    //	Delete device allocated objects
    delete allEventInformation;

    /*----- PROTECTED REGION END -----*/ //	EarthQuakeGenerator::delete_device
    delete[] attr_DateReferenceEvent_read;
    delete[] attr_Latitude_read;
    delete[] attr_Longitude_read;
    delete[] attr_Depth_read;
    delete[] attr_ReportedMagnitudes_read;
    delete[] attr_GeographicaLocation_read;
    delete[] attr_JsonTrans_read;
    delete[] attr_NdkFileName_read;
    delete[] attr_archiveValue_read;
}

//--------------------------------------------------------
/**
 *	Method      : EarthQuakeGenerator::init_device()
 *	Description : will be called at device initialization.
 */
//--------------------------------------------------------
void EarthQuakeGenerator::init_device()
{
    DEBUG_STREAM << "EarthQuakeGenerator::init_device() create device " << device_name << endl;
    /*----- PROTECTED REGION ID(EarthQuakeGenerator::init_device_before) ENABLED START -----*/

    //	Initialization before get_device_property() call

    /*----- PROTECTED REGION END -----*/ //	EarthQuakeGenerator::init_device_before

    //	No device property to be read from database

    attr_DateReferenceEvent_read = new Tango::DevString[1];
    attr_Latitude_read = new Tango::DevDouble[1];
    attr_Longitude_read = new Tango::DevDouble[1];
    attr_Depth_read = new Tango::DevDouble[1];
    attr_ReportedMagnitudes_read = new Tango::DevString[1];
    attr_GeographicaLocation_read = new Tango::DevString[1];
    attr_JsonTrans_read = new Tango::DevString[1];
    attr_NdkFileName_read = new Tango::DevString[1];
    attr_archiveValue_read = new Tango::DevString[1];
    /*----- PROTECTED REGION ID(EarthQuakeGenerator::init_device) ENABLED START -----*/
    //	Initialize device
    allEventInformation = new vector<string>();
    string tmpString;
    ifstream infile;
    infile.open("/home/osboxes/tango-dev/Earthquake/jan76_dec13.ndk");
    int counter = 0;
    while (std::getline(infile, tmpString)) {
        if (counter % 5 == 0) {
            allEventInformation->push_back(tmpString);
        }
        counter++;
    }
    infile.close();

    cout << "Events size = " << to_string(allEventInformation->size()) << "\n";
    /*----- PROTECTED REGION END -----*/ //	EarthQuakeGenerator::init_device
}

//--------------------------------------------------------
/**
 *	Method      : EarthQuakeGenerator::always_executed_hook()
 *	Description : method always executed before any command is executed
 */
//--------------------------------------------------------
void EarthQuakeGenerator::always_executed_hook()
{
    DEBUG_STREAM << "EarthQuakeGenerator::always_executed_hook()  " << device_name << endl;
    /*----- PROTECTED REGION ID(EarthQuakeGenerator::always_executed_hook) ENABLED START -----*/

    //	code always executed before all requests

    /*----- PROTECTED REGION END -----*/ //	EarthQuakeGenerator::always_executed_hook
}

//--------------------------------------------------------
/**
 *	Method      : EarthQuakeGenerator::read_attr_hardware()
 *	Description : Hardware acquisition for attributes
 */
//--------------------------------------------------------
void EarthQuakeGenerator::read_attr_hardware(TANGO_UNUSED(vector<long>& attr_list))
{
    DEBUG_STREAM << "EarthQuakeGenerator::read_attr_hardware(vector<long> &attr_list) entering... " << endl;
    /*----- PROTECTED REGION ID(EarthQuakeGenerator::read_attr_hardware) ENABLED START -----*/

    //	Add your own code

    /*----- PROTECTED REGION END -----*/ //	EarthQuakeGenerator::read_attr_hardware
}
//--------------------------------------------------------
/**
 *	Method      : EarthQuakeGenerator::write_attr_hardware()
 *	Description : Hardware writing for attributes
 */
//--------------------------------------------------------
void EarthQuakeGenerator::write_attr_hardware(TANGO_UNUSED(vector<long>& attr_list))
{
    DEBUG_STREAM << "EarthQuakeGenerator::write_attr_hardware(vector<long> &attr_list) entering... " << endl;
    /*----- PROTECTED REGION ID(EarthQuakeGenerator::write_attr_hardware) ENABLED START -----*/

    //	Add your own code

    /*----- PROTECTED REGION END -----*/ //	EarthQuakeGenerator::write_attr_hardware
}

//--------------------------------------------------------
/**
 *	Read attribute DateReferenceEvent related method
 *	Description:
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void EarthQuakeGenerator::read_DateReferenceEvent(Tango::Attribute& attr)
{
    DEBUG_STREAM << "EarthQuakeGenerator::read_DateReferenceEvent(Tango::Attribute &attr) entering... " << endl;
    /*----- PROTECTED REGION ID(EarthQuakeGenerator::read_DateReferenceEvent) ENABLED START -----*/
    //	Set the attribute value
    attr.set_value(attr_DateReferenceEvent_read);

    /*----- PROTECTED REGION END -----*/ //	EarthQuakeGenerator::read_DateReferenceEvent
}
//--------------------------------------------------------
/**
 *	Read attribute Latitude related method
 *	Description:
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void EarthQuakeGenerator::read_Latitude(Tango::Attribute& attr)
{
    DEBUG_STREAM << "EarthQuakeGenerator::read_Latitude(Tango::Attribute &attr) entering... " << endl;
    /*----- PROTECTED REGION ID(EarthQuakeGenerator::read_Latitude) ENABLED START -----*/
    //	Set the attribute value
    attr.set_value(attr_Latitude_read);

    /*----- PROTECTED REGION END -----*/ //	EarthQuakeGenerator::read_Latitude
}
//--------------------------------------------------------
/**
 *	Read attribute Longitude related method
 *	Description:
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void EarthQuakeGenerator::read_Longitude(Tango::Attribute& attr)
{
    DEBUG_STREAM << "EarthQuakeGenerator::read_Longitude(Tango::Attribute &attr) entering... " << endl;
    /*----- PROTECTED REGION ID(EarthQuakeGenerator::read_Longitude) ENABLED START -----*/
    //	Set the attribute value
    attr.set_value(attr_Longitude_read);

    /*----- PROTECTED REGION END -----*/ //	EarthQuakeGenerator::read_Longitude
}
//--------------------------------------------------------
/**
 *	Read attribute Depth related method
 *	Description:
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void EarthQuakeGenerator::read_Depth(Tango::Attribute& attr)
{
    DEBUG_STREAM << "EarthQuakeGenerator::read_Depth(Tango::Attribute &attr) entering... " << endl;
    /*----- PROTECTED REGION ID(EarthQuakeGenerator::read_Depth) ENABLED START -----*/
    //	Set the attribute value
    attr.set_value(attr_Depth_read);

    /*----- PROTECTED REGION END -----*/ //	EarthQuakeGenerator::read_Depth
}
//--------------------------------------------------------
/**
 *	Read attribute ReportedMagnitudes related method
 *	Description:
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void EarthQuakeGenerator::read_ReportedMagnitudes(Tango::Attribute& attr)
{
    DEBUG_STREAM << "EarthQuakeGenerator::read_ReportedMagnitudes(Tango::Attribute &attr) entering... " << endl;
    /*----- PROTECTED REGION ID(EarthQuakeGenerator::read_ReportedMagnitudes) ENABLED START -----*/
    //	Set the attribute value
    attr.set_value(attr_ReportedMagnitudes_read);

    /*----- PROTECTED REGION END -----*/ //	EarthQuakeGenerator::read_ReportedMagnitudes
}
//--------------------------------------------------------
/**
 *	Read attribute GeographicaLocation related method
 *	Description:
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void EarthQuakeGenerator::read_GeographicaLocation(Tango::Attribute& attr)
{
    DEBUG_STREAM << "EarthQuakeGenerator::read_GeographicaLocation(Tango::Attribute &attr) entering... " << endl;
    /*----- PROTECTED REGION ID(EarthQuakeGenerator::read_GeographicaLocation) ENABLED START -----*/
    //	Set the attribute value
    attr.set_value(attr_GeographicaLocation_read);

    /*----- PROTECTED REGION END -----*/ //	EarthQuakeGenerator::read_GeographicaLocation
}
//--------------------------------------------------------
/**
 *	Read attribute JsonTrans related method
 *	Description:
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void EarthQuakeGenerator::read_JsonTrans(Tango::Attribute& attr)
{
    DEBUG_STREAM << "EarthQuakeGenerator::read_JsonTrans(Tango::Attribute &attr) entering... " << endl;
    /*----- PROTECTED REGION ID(EarthQuakeGenerator::read_JsonTrans) ENABLED START -----*/
    //	Set the attribute value
    attr.set_value(attr_JsonTrans_read);

    /*----- PROTECTED REGION END -----*/ //	EarthQuakeGenerator::read_JsonTrans
}
//--------------------------------------------------------
/**
 *	Read attribute NdkFileName related method
 *	Description:
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void EarthQuakeGenerator::read_NdkFileName(Tango::Attribute& attr)
{
    DEBUG_STREAM << "EarthQuakeGenerator::read_NdkFileName(Tango::Attribute &attr) entering... " << endl;
    /*----- PROTECTED REGION ID(EarthQuakeGenerator::read_NdkFileName) ENABLED START -----*/
    //	Set the attribute value
    attr.set_value(attr_NdkFileName_read);

    /*----- PROTECTED REGION END -----*/ //	EarthQuakeGenerator::read_NdkFileName
}
//--------------------------------------------------------
/**
 *	Write attribute NdkFileName related method
 *	Description:
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void EarthQuakeGenerator::write_NdkFileName(Tango::WAttribute& attr)
{
    DEBUG_STREAM << "EarthQuakeGenerator::write_NdkFileName(Tango::WAttribute &attr) entering... " << endl;
    //	Retrieve write value
    Tango::DevString w_val;
    attr.get_write_value(w_val);
    /*----- PROTECTED REGION ID(EarthQuakeGenerator::write_NdkFileName) ENABLED START -----*/

    /*----- PROTECTED REGION END -----*/ //	EarthQuakeGenerator::write_NdkFileName
}
//--------------------------------------------------------
/**
 *	Read attribute archiveValue related method
 *	Description:
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void EarthQuakeGenerator::read_archiveValue(Tango::Attribute& attr)
{
    DEBUG_STREAM << "EarthQuakeGenerator::read_archiveValue(Tango::Attribute &attr) entering... " << endl;
    /*----- PROTECTED REGION ID(EarthQuakeGenerator::read_archiveValue) ENABLED START -----*/
    //	Set the attribute value
    attr.set_value(attr_archiveValue_read);

    /*----- PROTECTED REGION END -----*/ //	EarthQuakeGenerator::read_archiveValue
}

//--------------------------------------------------------
/**
 *	Method      : EarthQuakeGenerator::add_dynamic_attributes()
 *	Description : Create the dynamic attributes if any
 *                for specified device.
 */
//--------------------------------------------------------
void EarthQuakeGenerator::add_dynamic_attributes()
{
    /*----- PROTECTED REGION ID(EarthQuakeGenerator::add_dynamic_attributes) ENABLED START -----*/

    //	Add your own code to create and add dynamic attributes if any

    /*----- PROTECTED REGION END -----*/ //	EarthQuakeGenerator::add_dynamic_attributes
}

//--------------------------------------------------------
/**
 *	Command NextEvent related method
 *	Description:
 *
 */
//--------------------------------------------------------
void EarthQuakeGenerator::next_event()
{
    DEBUG_STREAM << "EarthQuakeGenerator::NextEvent()  - " << device_name << endl;
    /*----- PROTECTED REGION ID(EarthQuakeGenerator::next_event) ENABLED START -----*/
    try
    {
        //	Add your own code
        if (!allEventInformation->empty()) {
            string tmpString = allEventInformation->front();
            cout << tmpString << "\n";
            string dateRef = tmpString.substr(5, 21);
            string strLat = tmpString.substr(27, 7);
            string strLon = tmpString.substr(34, 7);
            float latitude = stof(tmpString.substr(27, 7).c_str());
            float longitude = stof(tmpString.substr(34, 7).c_str());
            float depth = stof(tmpString.substr(42, 4).c_str());
            string magnitude = tmpString.substr(48, 3);
            string location = tmpString.substr(56, tmpString.size());

            cout << "setting attributes"
                 << "\n";
            attr_DateReferenceEvent_read[0] = new char[dateRef.length() + 1];
            strcpy(attr_DateReferenceEvent_read[0], dateRef.c_str());

            *attr_Latitude_read = latitude;

            *attr_Longitude_read = longitude;

            *attr_Depth_read = depth;

            //*attr_ReportedMagnitudes_read = Tango::string_dup(magnitude.c_str());
            attr_ReportedMagnitudes_read[0] = new char[magnitude.length() + 1];
            strcpy(attr_ReportedMagnitudes_read[0], magnitude.c_str());

            //*attr_GeographicaLocation_read = Tango::string_dup(loscation.c_str());
            attr_GeographicaLocation_read[0] = new char[location.length() + 1];
            strcpy(attr_GeographicaLocation_read[0], location.c_str());

            /*float lat = roundf(stof(strLat) * 100) / 100.0;

            float lon = roundf(stof(strLon) * 100) / 100.0;*/

            std::stringstream strGeoPoint;
            strGeoPoint << strLat << "," << strLon;

            json j = { { "DateReferenceEvent", dateRef },
                       { "GeoPoint", strGeoPoint.str() /*{ lat, lon }*/ },
                       { "Depth", depth },
                       { "ReportedMagnitudes", magnitude },
                       { "Location", location } };

            string jsonStr = j.dump();
            attr_JsonTrans_read[0] = new char[jsonStr.length() + 1];
            strcpy(attr_JsonTrans_read[0], jsonStr.c_str());

            attr_archiveValue_read[0] = new char[jsonStr.length() + 1];
            strcpy(attr_archiveValue_read[0], jsonStr.c_str());

            allEventInformation->erase(allEventInformation->begin());
            cout << "json = " << jsonStr << "\n";
            cout << "Events size = " << to_string(allEventInformation->size()) << "\n";

            DeviceImpl::push_archive_event("GeographicaLocation", attr_GeographicaLocation_read, 1, 0, false);
            DeviceImpl::push_archive_event("ReportedMagnitudes", attr_ReportedMagnitudes_read, 1, 0, false);
            DeviceImpl::push_archive_event("DateReferenceEvent", attr_DateReferenceEvent_read, 1, 0, false);
            DeviceImpl::push_archive_event("Latitude", attr_Latitude_read, 1, 0, false);
            DeviceImpl::push_archive_event("Longitude", attr_Longitude_read, 1, 0, false);
            DeviceImpl::push_archive_event("Depth", attr_Depth_read, 1, 0, false);
            DeviceImpl::push_archive_event("JsonTrans", attr_JsonTrans_read, 1, 0, false);
            DeviceImpl::push_archive_event("archiveValue", attr_JsonTrans_read, 1, 0, false);
        }
    }
    catch (int e)
    {
        cout << "An exception occurred. Exception Nr. " << e << '\n';
    }
    /*----- PROTECTED REGION END -----*/ //	EarthQuakeGenerator::next_event
}
//--------------------------------------------------------
/**
 *	Command Stop related method
 *	Description:
 *
 */
//--------------------------------------------------------
void EarthQuakeGenerator::stop()
{
    DEBUG_STREAM << "EarthQuakeGenerator::Stop()  - " << device_name << endl;
    /*----- PROTECTED REGION ID(EarthQuakeGenerator::stop) ENABLED START -----*/

    //	Add your own code

    /*----- PROTECTED REGION END -----*/ //	EarthQuakeGenerator::stop
}
//--------------------------------------------------------
/**
 *	Method      : EarthQuakeGenerator::add_dynamic_commands()
 *	Description : Create the dynamic commands if any
 *                for specified device.
 */
//--------------------------------------------------------
void EarthQuakeGenerator::add_dynamic_commands()
{
    /*----- PROTECTED REGION ID(EarthQuakeGenerator::add_dynamic_commands) ENABLED START -----*/

    //	Add your own code to create and add dynamic commands if any

    /*----- PROTECTED REGION END -----*/ //	EarthQuakeGenerator::add_dynamic_commands
}

/*----- PROTECTED REGION ID(EarthQuakeGenerator::namespace_ending) ENABLED START -----*/

//	Additional Methods

/*----- PROTECTED REGION END -----*/ //	EarthQuakeGenerator::namespace_ending
} //	namespace
