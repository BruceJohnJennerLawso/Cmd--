// Cmd-- 1.10 Delta Vee! Example source code  ///////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <math.h>
#include <string>
#include <new>
#include <vector>
#include <exception>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <time.h>
#include "GenericMenu.h"
#include "TCmdMenu.h"
#include "ProgData.h"
#include <stdio.h>   
#define NEWLINE '\n'
#define TAB '\t'
#define VTAB '\v'
#define BEEP '\a'
#define BACK '\b'
using namespace std;


double GiveameINPUT ();

void Runprog();


int main()
{	try
	{	Runprog();		
	}
	catch (exception& e)
	{	cout << "Standard Exception: " << e.what() << endl;	
	}
	return 0;
}

void Runprog()
{	Output_program_title(Program_Title);
	InitFxObjects();
	CGenericMenu * main = new TCmdMenu ("Main", "Main-Menu");
	CGenericMenu * graph = new TCmdMenu ("Main", "Calculator", "Delta-Vee Calculation Menu");
	(graph)->Embed_function(Dv);
	(graph)->Embed_function(Mp);
	(graph)->Embed_function(Mpay);
	(graph)->Embed_function(Vexh);
	(main)->menu();												
}


//  Delta Vee! Code for demonstration  //////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

struct stagedata 
{	double Vexh;
	double Mp;
	double Mpay;
	double DeeVee;
	double Md;
	double Mrcs;
	double Mcons;
	double Crew;
}	singlestage;

double Md1;
double Mp1;

double GiveameINPUT ()
{	double data;
	while(true)
	{	cin >> data;
		if (!cin.fail())
		{	return data;	
		}
		cin.clear();
		cin.ignore();
	}
}

void DvFunction::Fx ()									// Apologies for the horrific... everything. This was my first ever useful program ;)
{	cout << NEWLINE << "Exhaust velocity (m/s): ";
    singlestage.Vexh = GiveameINPUT();
	cout << "Dry Mass (kg): ";
	singlestage.Md = GiveameINPUT();
	cout << "RCS Fuel (kilograms): ";
	singlestage.Mrcs = GiveameINPUT();
	cout << "Consumables Mass (kilograms): ";
	singlestage.Mcons = GiveameINPUT();
	cout << "Crew Number: ";
	singlestage.Crew = GiveameINPUT();
	cout << "Propellant Mass(kilograms): ";
	singlestage.Mp = GiveameINPUT();
	Mp1 = (singlestage.Mp);
	Md1 = (singlestage.Md+singlestage.Mrcs+singlestage.Mcons+(singlestage.Crew*90));
	singlestage.DeeVee = singlestage.Vexh*(log((Mp1+Md1)/(Md1)));
	cout << "Delta-Vee: " << TAB << singlestage.DeeVee << "m/s" << NEWLINE << endl;
	Cmd_dashdash::Send_WM_Box("Delta Vee!", singlestage.DeeVee);
}

void MpFunction::Fx ()
{	cout << NEWLINE << "Exhaust Velocity (m/s): ";
	singlestage.Vexh = GiveameINPUT();
	cout << "Dry Mass (kilograms): ";
	singlestage.Md = GiveameINPUT();
	cout << "RCS Fuel (kilograms): ";
	singlestage.Mrcs = GiveameINPUT();
	cout << "Consumables Mass (kilograms): ";
	singlestage.Mcons = GiveameINPUT();
	cout << "Crew Number: ";
	singlestage.Crew = GiveameINPUT();
	cout << "Delta-Vee: ";
	singlestage.DeeVee = GiveameINPUT();
	Md1 = (singlestage.Md+singlestage.Mrcs+singlestage.Mcons+(singlestage.Crew*90));
	singlestage.Mp = ((exp(singlestage.DeeVee/singlestage.Vexh))*(Md1))-(Md1);
	cout << "Propellant Required: " << TAB << singlestage.Mp << TAB << "kg" << NEWLINE << NEWLINE;
	Cmd_dashdash::Send_WM_Box("Propellant Required", singlestage.Mp);
}

void VexhFunction::Fx ()
{	cout <<NEWLINE;
	cout << "Dry Mass (kilograms): ";
	singlestage.Md = GiveameINPUT();
	cout << "RCS Fuel (kilograms): ";
	singlestage.Mrcs = GiveameINPUT();
	cout << "Consumables Mass (kilograms): ";
	singlestage.Mcons = GiveameINPUT();
	cout << "Propellant Mass (kilograms): ";
	singlestage.Mp = GiveameINPUT();
	cout << "Delta-Vee (m/s): ";
	singlestage.DeeVee = GiveameINPUT();
	cout << "Crew Number: ";
	singlestage.Crew = GiveameINPUT();
	Mp1 = (singlestage.Mp);
	Md1 = (singlestage.Md+singlestage.Mrcs+singlestage.Mcons+(singlestage.Crew*90));
	singlestage.Vexh = (singlestage.DeeVee/log((Mp1+Md1)/(Md1)));
	cout << "Exhaust Velocity Required: " << TAB << singlestage.Vexh << TAB << "m/s" << NEWLINE << NEWLINE;
	Cmd_dashdash::Send_WM_Box("Exhaust Velocity", singlestage.Vexh);
}

void MpayFunction::Fx ()
{	cout << NEWLINE;
	cout << "Dry Mass (kilograms): ";
	singlestage.Md = GiveameINPUT();
	cout << "RCS Fuel (kilograms): ";
	singlestage.Mrcs = GiveameINPUT();
	cout << "Consumables Mass (kilograms): ";
	singlestage.Mcons = GiveameINPUT();
	cout << "Propellant Mass (kilograms): ";
	singlestage.Mp = GiveameINPUT();
	cout << "Exhaust Velocity (m/s): ";
	singlestage.Vexh = GiveameINPUT();
	cout << "Delta-Vee (m/s): ";
	singlestage.DeeVee = GiveameINPUT();
	cout << "Crew Number: ";
	singlestage.Crew = GiveameINPUT();
	singlestage.Mp = ((singlestage.Mp/(exp(singlestage.DeeVee/singlestage.Vexh)-1))-singlestage.Md-singlestage.Mrcs-singlestage.Mcons-(singlestage.Crew*90));
	cout << "Maximum Payload: " << TAB << singlestage.Mp << TAB << "kg" << NEWLINE << NEWLINE;
	Cmd_dashdash::Send_WM_Box("Maximum Payload", singlestage.Mp);
}

