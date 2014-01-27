#include "GenericMenu.h"
#include <iostream>
#include <string>
#include <vector>
#define NEWLINE '\n'
#define TAB '\t'
#define VTAB '\v'
#define BEEP '\a'
#define BACK '\b'
using namespace std;

CGenericMenu::CGenericMenu(void)
{					
}

void CGenericMenu::menu()
{	cout << "Bad call to polymorphic base class."<< endl;				
}	// This shouldnt ever happen, although I think I did manage to trigger it once during testing

void CGenericMenu::Transform_ID_to_uppercase()
{	transform (this->menuid.begin (), this->menuid.end (), this->menuid.begin (), toupper);
}

void CGenericMenu::Embed_function(CProgFx * ipt)
{	MFxPointers.emplace_back(ipt);
}

CGenericMenu::~CGenericMenu(void)
{					
}
