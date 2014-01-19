// Program Settings header file /////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#include <string>
#include <iostream>
#include "Functionalize!.h"
#include "TCmdMenu.h"

#define Program_Title "Delta-Vee!_Integrated"
#define Stylechar '-'

#define sNULL "NULL"

void Output_program_title(std::string Name);
void InitFxObjects();

// Function Pointer ids /////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class DvFunction: public CProgFx
{	public:
	DvFunction(std::string ina){FxId = ina;}
	void Fx();
};

class MpFunction: public CProgFx
{	public:
	MpFunction(std::string ina){FxId = ina;}
	void Fx();
};

class VexhFunction: public CProgFx
{	public:
	VexhFunction(std::string ina){FxId = ina;}
	void Fx();
};

class MpayFunction: public CProgFx
{	public:
	MpayFunction(std::string ina){FxId = ina;}
	void Fx();
};

CProgFx * Dv, * Vexh, * Mp, * Mpay;


void InitFxObjects()
{	Dv = new DvFunction("DV");
	Mp = new MpFunction("MP");
	Mpay = new MpayFunction("MPAY");
	Vexh = new VexhFunction("VEXH");
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////


void Output_program_title(std::string Name)
{	unsigned int l = Name.length();
	l = 80 - l;
	double bracketing = l/2;
	l = bracketing;
	std::string Greetings;
	for (unsigned int cy = 0; cy <= l; ++cy)
	{	Greetings.insert(Greetings.begin(), Stylechar);
	}
	Greetings.insert(l, Name);
	l = Greetings.length();
	l = 80 - l;
	for (unsigned int cy = 0; cy <= l; ++cy)
	{	Greetings.insert(Greetings.end(), Stylechar);
		if (Greetings.length() >= 80)
		{	break;
		}
	}
	std::cout << Greetings << NEWLINE << std::endl;
}


