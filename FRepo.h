#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#define NEWLINE '\n'
#define TAB '\t'
#define VTAB '\v'
#define BEEP '\a'
#define BACK '\b'

namespace Cmd_plusplus
{
int Input_int(std::string prompt);
double Input_double(std::string prompt);
bool Input_bool(std::string prompt);
float Input_float(std::string prompt);
std::string Input_string(std::string prompt);

void Cplusplus_print_text(std::string text);
void Cplusplus_print_text(std::string text, int n);


void Cplusplus_print_line(std::string line);
void Cplusplus_print_line(std::string line, int n);

int Round_double_to_int (double in);

std::string Return_Char3_as_String(char i [3] );

bool Compare_string(std::string i, std::string comp);

int Compare_input_string_to_list(std::string i, std::string arg1l, std::string arg1s, bool transform_up);
int Compare_input_string_to_list(std::string i, std::string arg1l, std::string arg1s, std::string arg2l, std::string arg2s, bool transform_up);
int Compare_input_string_to_list(std::string i, std::string arg1l, std::string arg1s, std::string arg2l, std::string arg2s, std::string arg3l, std::string arg3s, bool transform_up);
int Compare_input_string_to_list(std::string i, std::string arg1l, std::string arg1s, std::string arg2l, std::string arg2s, std::string arg3l, std::string arg3s, std::string arg4l, std::string arg4s, bool transform_up);



double Absolute_value_double(double i);

void Print_text(std::string text);

template <class T> T Print_value(T o_n);

void Print_text(int o_n);


void Print_text(std::string text, int n);

void Print_line(std::string line);
void Print_line(int o_n);
void Print_line(std::string line, int n);

void Newline();
void Newline(int n);

int Convert_input_to_integer(std::string i, std::vector<std::string> icomps);


#ifdef _WIN32
void Send_WM_Box(std::string h, std::string m);
void Send_WM_Box(std::string h, long double m);
#elif !defined _WIN32
void Send_WM_Box(std::string h, std::string m);
void Send_WM_Box(std::string h, long double m);
#endif


void ExitCall();
};
