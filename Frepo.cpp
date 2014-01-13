#include "FRepo.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <windows.h>
#include <mmsystem.h>
#define NEWLINE '\n'
#define TAB '\t'
#define VTAB '\v'
#define BEEP '\a'
#define BACK '\b'
using namespace std;

int Cmd_plusplus::Input_int(string prompt)
{	while(true)
	{	cout << prompt;
		int data;
		cin >> data;
		if (!cin.fail())
			{	return data;
				cout << NEWLINE << NEWLINE;	
			}
		cin.clear();
		cin.ignore();
		cout << NEWLINE << NEWLINE;	
	}	
}

double Cmd_plusplus::Input_double(string prompt)
{	while(true)
	{	cout << prompt;
		double data;
		cin >> data;
		if (!cin.fail())
		{	return data;
			cout << NEWLINE << NEWLINE;		
		}
		cin.clear();
		cin.ignore();
		cout << NEWLINE << NEWLINE;		
	}	
}

bool Cmd_plusplus::Input_bool(string prompt)
{	while(true)
	{	cout << prompt;
		string data;
		getline (std::cin,data);
		transform (data.begin (), data.end (), data.begin (), toupper);
		if (!cin.fail())
		{	if (((data == "TRUE")||(data == "T"))||(data == "YES"))
			{	cout << NEWLINE << NEWLINE;	
				return true;				
			}
			else if (((data == "FALSE")||(data == "F"))||(data == "NO"))
			{	cout << NEWLINE << NEWLINE;	
				return false;				
			}
			else
			{	cin.clear();
				cin.ignore();
				cout << NEWLINE << NEWLINE;		
			}		
		}
		cin.clear();
		cin.ignore();
		cout << NEWLINE << NEWLINE;		
	}	
}

float Cmd_plusplus::Input_float(string prompt)
{	while(true)
	{	cout << prompt;
		float data;
		cin >> data;
		if (!cin.fail())
		{	return data;
			cout << NEWLINE << NEWLINE;		
		}
		cin.clear();
		cin.ignore();
		cout << NEWLINE << NEWLINE;		
	}	
}

string Cmd_plusplus::Input_string(string prompt)
{	while(true)
	{	cout << prompt;
		string data;
		cin >> data;
		if (!cin.fail())
		{	return data;
			cout << NEWLINE << NEWLINE;		
		}
		cin.clear();
		cin.ignore();
		cout << NEWLINE << NEWLINE;		
	}	
}


int Cmd_plusplus::Round_double_to_int (double in)
{	int d;
	d = in;
	in = in - d;
	if (in == 0.5)
	{	return d;	
	}	// I couldnt decide dammit!
	else if (in > 0.5)
	{	d++;
		return d;	
	}
	else if (in < 0.5)
	{	return d;	
	}
}

void Cmd_plusplus::Cplusplus_print_text(string text)
{	cout << text;
}

void Cmd_plusplus::Cplusplus_print_text(string text, int n)
{	for (int cy = 0; cy <= n; ++cy)
	{	cout << text;
	}
}

void Cmd_plusplus::Cplusplus_print_line(string line)
{	cout << line << endl;
}

void Cmd_plusplus::Cplusplus_print_line(string line, int n)
{	for (int cy = 0; cy <= n; ++cy)
	{	cout << line << endl;
	}
}




std::string Cmd_plusplus::Return_Char3_as_String(char i [3])
{	string output;
	output = "";
	output.insert (output.end(), 1, i [2]);
	output.insert (output.end(), 1, i [1]); 
	output.insert (output.end(), 1, i [0]);
	return output;							
}


bool Cmd_plusplus::Compare_string(string i, string comp)
{	transform (i.begin (), i.end (), i.begin (), toupper);	
	if (i == comp)
	{	return true;	
	}
	else if (i != comp)
	{	return false;	
	}		
}

int Cmd_plusplus::Compare_input_string_to_list(string i, string arg1l, string arg1s, bool transform_up)
{	if (transform_up == true)
	{	transform (i.begin (), i.end (), i.begin (), toupper);	
	}
	struct comp_bools
	{	bool comparisonl;
		bool comparisons;	
	};
	union comp_bools_lists
	{	comp_bools args1;	
	} bools_list;
	bools_list.args1.comparisonl = Compare_string(i, arg1l);
	bools_list.args1.comparisons = Compare_string(i, arg1s);
	if ((bools_list.args1.comparisonl == true)||(bools_list.args1.comparisons == true))
	{	return 1;				
	}
	else if ((Compare_string(i, "HELP") == true)||(Compare_string(i, "H") == true))
	{	cout << NEWLINE << "Valid Commands are: " << NEWLINE << endl;
		cout << arg1l << " " << arg1s << NEWLINE << endl;
		return 0;		
	}
	else
	{	return 0;		
	}	
}

int Cmd_plusplus::Compare_input_string_to_list(string i, string arg1l, string arg1s, string arg2l, string arg2s, bool transform_up)
{	if (transform_up == true)
	{	transform (i.begin (), i.end (), i.begin (), toupper);	
	}
	struct comp_bools
	{	bool comparisonl;
		bool comparisons;	
	};
	union comp_bools_lists
	{	comp_bools args1;
		comp_bools args2;	
	} bools_list;
	bools_list.args1.comparisonl = Compare_string(i, arg1l);
	bools_list.args1.comparisons = Compare_string(i, arg1s);
	if ((bools_list.args1.comparisonl == true)||(bools_list.args1.comparisons == true))
	{	return 1;
	}
	else
	{	bools_list.args2.comparisonl = Compare_string(i, arg2l);
		bools_list.args2.comparisons = Compare_string(i, arg2s);						
	}
	if ((bools_list.args2.comparisonl == true)||(bools_list.args2.comparisons == true))
	{	return 2;
	}
	else if ((Compare_string(i, "HELP") == true)||(Compare_string(i, "H") == true))
	{	cout << "Valid Commands are: " << NEWLINE << endl;
		cout << arg1l << " " << arg1s << endl;
		cout << arg2l << " " << arg2s << NEWLINE << endl;
		return 0;		
	}
	else
	{	return 0;		
	}	
}

int Cmd_plusplus::Compare_input_string_to_list(string i, string arg1l, string arg1s, string arg2l, string arg2s, string arg3l, string arg3s, bool transform_up)
{	if (transform_up == true)
	{	transform (i.begin (), i.end (), i.begin (), toupper);	
	}
	struct comp_bools
	{	bool comparisonl;
		bool comparisons;	
	};
	union comp_bools_lists
	{	comp_bools args1;
		comp_bools args2;
		comp_bools args3;	
	} bools_list;
	bools_list.args1.comparisonl = Compare_string(i, arg1l);
	bools_list.args1.comparisons = Compare_string(i, arg1s);
	if ((bools_list.args1.comparisonl == true)||(bools_list.args1.comparisons == true))
	{	return 1;				
	}
	else
	{	bools_list.args2.comparisonl = Compare_string(i, arg2l);
		bools_list.args2.comparisons = Compare_string(i, arg2s);			
	}
	if ((bools_list.args2.comparisonl == true)||(bools_list.args2.comparisons == true))
	{	return 2;
	}
	else
	{	bools_list.args3.comparisonl = Compare_string(i, arg3l);
		bools_list.args3.comparisons = Compare_string(i, arg3s);
	}
	if ((bools_list.args3.comparisonl == true)||(bools_list.args3.comparisons == true))
	{	return 3;
	}
	else if ((Compare_string(i, "HELP") == true)||(Compare_string(i, "H") == true))
	{	cout << "Valid Commands are: " << NEWLINE << endl;
		cout << arg1l << " " << arg1s << endl;
		cout << arg2l << " " << arg2s << endl;
		cout << arg3l << " " << arg3s << NEWLINE << endl;
		return 0;
	}
	else
	{	return 0;
	}	
}

int Cmd_plusplus::Compare_input_string_to_list(string i, string arg1l, string arg1s, string arg2l, string arg2s, string arg3l, string arg3s, string arg4l, string arg4s, bool transform_up)
{	if (transform_up == true)
	{	transform (i.begin (), i.end (), i.begin (), toupper);	
	}
	struct comp_bools
	{	bool comparisonl;
		bool comparisons;	
	};
	union comp_bools_lists
	{	comp_bools args1;
		comp_bools args2;
		comp_bools args3;
		comp_bools args4;	
	} bools_list;
	bools_list.args1.comparisonl = Compare_string(i, arg1l);
	bools_list.args1.comparisons = Compare_string(i, arg1s);
	if ((bools_list.args1.comparisonl == true)||(bools_list.args1.comparisons == true))
	{	return 1;				
	}
	else
	{	bools_list.args2.comparisonl = Compare_string(i, arg2l);
		bools_list.args2.comparisons = Compare_string(i, arg2s);	
	}
	if ((bools_list.args2.comparisonl == true)||(bools_list.args2.comparisons == true))
	{	return 2;				
	}
	else
	{	bools_list.args3.comparisonl = Compare_string(i, arg3l);
		bools_list.args3.comparisons = Compare_string(i, arg3s);
	}
	if ((bools_list.args3.comparisonl == true)||(bools_list.args3.comparisons == true))
	{	return 3;			
	}
	else
	{	bools_list.args4.comparisonl = Compare_string(i, arg4l);
		bools_list.args4.comparisons = Compare_string(i, arg4s);
	}
	if ((bools_list.args4.comparisonl == true)||(bools_list.args4.comparisons == true))
	{	return 4;
	}
	else if ((Compare_string(i, "HELP") == true)||(Compare_string(i, "H") == true))
	{	cout << "Valid Commands are: " << NEWLINE << endl;
		cout << arg1l << " " << arg1s << endl;
		cout << arg2l << " " << arg2s << endl;
		cout << arg3l << " " << arg3s << endl;
		cout << arg4l << " " << arg4s << NEWLINE << endl;
		return 0;
	}
	else
	{	return 0;	
	}
}




void Cmd_plusplus::Print_text(string text)
{	cout << text;
}


void Cmd_plusplus::Print_text(int n_o)
{	cout << n_o;
}

void Cmd_plusplus::Print_text(string text, int n)
{	for (int cy = 0; cy <= n; ++cy)
	{	cout << text;
	}
}

void Cmd_plusplus::Print_line(string line)
{	cout << line << endl;
}

void Cmd_plusplus::Print_line(int n_o)
{	cout << n_o << endl;
}


void Cmd_plusplus::Print_line(string line, int n)
{	for (int cy = 0; cy <= n; ++cy)
	{	cout << line << endl;
	}
}

void Cmd_plusplus::Newline()
{	cout << "\n";
}

void Cmd_plusplus::Newline(int n)
{	for(int cy = 0; cy <= n; ++cy)
	{	cout << "\n";
	}
}

int Cmd_plusplus::Convert_input_to_integer(std::string i, std::vector<std::string> icomps)
{	std::vector<std::string>::iterator itString;
	unsigned int n = 0;
	for(itString = icomps.begin(); itString != icomps.end(); ++itString)
	{	n++;
		if (*itString == i)
		{	icomps.clear();		// String Vector is cleared for you if a hit is registered, but not
			return n;
		}
	}
	return 0;
}	// Seems like a rather unsafe function, although pretty powerful. Error handling can happen later. :P



double Cmd_plusplus::Absolute_value_double(double i)
{	if (i >= 0)
	{	return i;
	}
	else if (i < 0)
	{	i = (-i);
		return i;
	}
}













#ifdef _WIN32
#include <windows.h>
void Cmd_plusplus::Send_WM_Box (std::string h, std::string m)
{	MessageBox(NULL, m.c_str(), h.c_str(), MB_OK);
}	//OS Windows Specific function for sending a message box from inside the command line. Unusual, but somewhat interesting I guess
void Cmd_plusplus::Send_WM_Box(std::string h, long double m)
{	string i;
	i = std::to_string(m);
	MessageBox(NULL, i.c_str() , h.c_str(), MB_OK);
}
#elif !defined _WIN32
void Cmd_plusplus::Send_WM_Box (std::string h, std::string m)
{	cout << NEWLINE << "Please note: Send_WM_Box is only available with a Win32 compatible compiler" << NEWLINE;
}
void Cmd_plusplus::Send_WM_Box(std::string h, long double m)
{	cout << NEWLINE << "Please note: Send_WM_Box is only available with a Win32 compatible compiler" << NEWLINE;
}
#endif

void Cmd_plusplus::ExitCall()
{	cout << "Hail The Probe!!!";
	exit(0);
} 