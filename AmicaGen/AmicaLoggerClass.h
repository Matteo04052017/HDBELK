/*----- PROTECTED REGION ID(AmicaLoggerClass.h) ENABLED START -----*/
//=============================================================================
//
// file :        AmicaLoggerClass.h
//
// description : Include for the AmicaLogger root class.
//               This class is the singleton class for
//                the AmicaLogger device class.
//               It contains all properties and methods which the 
//               AmicaLogger requires only once e.g. the commands.
//
// project :     AmicaLogger
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
// Matteo Di Carlo
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


#ifndef AmicaLoggerClass_H
#define AmicaLoggerClass_H

#include <tango.h>
#include <AmicaLogger.h>


/*----- PROTECTED REGION END -----*/	//	AmicaLoggerClass.h


namespace AmicaLogger_ns
{
/*----- PROTECTED REGION ID(AmicaLoggerClass::classes for dynamic creation) ENABLED START -----*/


/*----- PROTECTED REGION END -----*/	//	AmicaLoggerClass::classes for dynamic creation

//=========================================
//	Define classes for attributes
//=========================================
//	Attribute ActivePower1 class definition
class ActivePower1Attrib: public Tango::Attr
{
public:
	ActivePower1Attrib():Attr("ActivePower1",
			Tango::DEV_DOUBLE, Tango::READ) {};
	~ActivePower1Attrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<AmicaLogger *>(dev))->read_ActivePower1(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<AmicaLogger *>(dev))->is_ActivePower1_allowed(ty);}
};

//	Attribute ActivePower2 class definition
class ActivePower2Attrib: public Tango::Attr
{
public:
	ActivePower2Attrib():Attr("ActivePower2",
			Tango::DEV_DOUBLE, Tango::READ) {};
	~ActivePower2Attrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<AmicaLogger *>(dev))->read_ActivePower2(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<AmicaLogger *>(dev))->is_ActivePower2_allowed(ty);}
};

//	Attribute ActivePower3 class definition
class ActivePower3Attrib: public Tango::Attr
{
public:
	ActivePower3Attrib():Attr("ActivePower3",
			Tango::DEV_DOUBLE, Tango::READ) {};
	~ActivePower3Attrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<AmicaLogger *>(dev))->read_ActivePower3(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<AmicaLogger *>(dev))->is_ActivePower3_allowed(ty);}
};

//	Attribute CurrentVoltage1 class definition
class CurrentVoltage1Attrib: public Tango::Attr
{
public:
	CurrentVoltage1Attrib():Attr("CurrentVoltage1",
			Tango::DEV_DOUBLE, Tango::READ) {};
	~CurrentVoltage1Attrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<AmicaLogger *>(dev))->read_CurrentVoltage1(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<AmicaLogger *>(dev))->is_CurrentVoltage1_allowed(ty);}
};

//	Attribute CurrentVoltage2 class definition
class CurrentVoltage2Attrib: public Tango::Attr
{
public:
	CurrentVoltage2Attrib():Attr("CurrentVoltage2",
			Tango::DEV_DOUBLE, Tango::READ) {};
	~CurrentVoltage2Attrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<AmicaLogger *>(dev))->read_CurrentVoltage2(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<AmicaLogger *>(dev))->is_CurrentVoltage2_allowed(ty);}
};

//	Attribute CurrentVoltage3 class definition
class CurrentVoltage3Attrib: public Tango::Attr
{
public:
	CurrentVoltage3Attrib():Attr("CurrentVoltage3",
			Tango::DEV_DOUBLE, Tango::READ) {};
	~CurrentVoltage3Attrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<AmicaLogger *>(dev))->read_CurrentVoltage3(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<AmicaLogger *>(dev))->is_CurrentVoltage3_allowed(ty);}
};

//	Attribute Day class definition
class DayAttrib: public Tango::Attr
{
public:
	DayAttrib():Attr("Day",
			Tango::DEV_SHORT, Tango::READ) {};
	~DayAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<AmicaLogger *>(dev))->read_Day(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<AmicaLogger *>(dev))->is_Day_allowed(ty);}
};

//	Attribute Hour class definition
class HourAttrib: public Tango::Attr
{
public:
	HourAttrib():Attr("Hour",
			Tango::DEV_DOUBLE, Tango::READ) {};
	~HourAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<AmicaLogger *>(dev))->read_Hour(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<AmicaLogger *>(dev))->is_Hour_allowed(ty);}
};

//	Attribute LineVoltage1 class definition
class LineVoltage1Attrib: public Tango::Attr
{
public:
	LineVoltage1Attrib():Attr("LineVoltage1",
			Tango::DEV_DOUBLE, Tango::READ) {};
	~LineVoltage1Attrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<AmicaLogger *>(dev))->read_LineVoltage1(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<AmicaLogger *>(dev))->is_LineVoltage1_allowed(ty);}
};

//	Attribute LineVoltage2 class definition
class LineVoltage2Attrib: public Tango::Attr
{
public:
	LineVoltage2Attrib():Attr("LineVoltage2",
			Tango::DEV_DOUBLE, Tango::READ) {};
	~LineVoltage2Attrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<AmicaLogger *>(dev))->read_LineVoltage2(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<AmicaLogger *>(dev))->is_LineVoltage2_allowed(ty);}
};

//	Attribute LineVoltage3 class definition
class LineVoltage3Attrib: public Tango::Attr
{
public:
	LineVoltage3Attrib():Attr("LineVoltage3",
			Tango::DEV_DOUBLE, Tango::READ) {};
	~LineVoltage3Attrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<AmicaLogger *>(dev))->read_LineVoltage3(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<AmicaLogger *>(dev))->is_LineVoltage3_allowed(ty);}
};

//	Attribute CurrentNeutro class definition
class CurrentNeutroAttrib: public Tango::Attr
{
public:
	CurrentNeutroAttrib():Attr("CurrentNeutro",
			Tango::DEV_DOUBLE, Tango::READ) {};
	~CurrentNeutroAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<AmicaLogger *>(dev))->read_CurrentNeutro(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<AmicaLogger *>(dev))->is_CurrentNeutro_allowed(ty);}
};

//	Attribute JsonTrans class definition
class JsonTransAttrib: public Tango::Attr
{
public:
	JsonTransAttrib():Attr("JsonTrans",
			Tango::DEV_STRING, Tango::READ) {};
	~JsonTransAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<AmicaLogger *>(dev))->read_JsonTrans(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<AmicaLogger *>(dev))->is_JsonTrans_allowed(ty);}
};


//=========================================
//	Define classes for commands
//=========================================
//	Command Next class definition
class NextClass : public Tango::Command
{
public:
	NextClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	NextClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~NextClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<AmicaLogger *>(dev))->is_Next_allowed(any);}
};


/**
 *	The AmicaLoggerClass singleton definition
 */

#ifdef _TG_WINDOWS_
class __declspec(dllexport)  AmicaLoggerClass : public Tango::DeviceClass
#else
class AmicaLoggerClass : public Tango::DeviceClass
#endif
{
	/*----- PROTECTED REGION ID(AmicaLoggerClass::Additionnal DServer data members) ENABLED START -----*/
	
	
	/*----- PROTECTED REGION END -----*/	//	AmicaLoggerClass::Additionnal DServer data members

	public:
		//	write class properties data members
		Tango::DbData	cl_prop;
		Tango::DbData	cl_def_prop;
		Tango::DbData	dev_def_prop;
	
		//	Method prototypes
		static AmicaLoggerClass *init(const char *);
		static AmicaLoggerClass *instance();
		~AmicaLoggerClass();
		Tango::DbDatum	get_class_property(string &);
		Tango::DbDatum	get_default_device_property(string &);
		Tango::DbDatum	get_default_class_property(string &);
	
	protected:
		AmicaLoggerClass(string &);
		static AmicaLoggerClass *_instance;
		void command_factory();
		void attribute_factory(vector<Tango::Attr *> &);
		void pipe_factory();
		void write_class_property();
		void set_default_property();
		void get_class_property();
		string get_cvstag();
		string get_cvsroot();
	
	private:
		void device_factory(const Tango::DevVarStringArray *);
		void create_static_attribute_list(vector<Tango::Attr *> &);
		void erase_dynamic_attributes(const Tango::DevVarStringArray *,vector<Tango::Attr *> &);
		vector<string>	defaultAttList;
		Tango::Attr *get_attr_object_by_name(vector<Tango::Attr *> &att_list, string attname);
};

}	//	End of namespace

#endif   //	AmicaLogger_H
