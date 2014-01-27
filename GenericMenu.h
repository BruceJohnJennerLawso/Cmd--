#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <vector>
#include <algorithm>
#define NEWLINE '\n'
#define TAB '\t'
#define VTAB '\v'
#define BEEP '\a'
#define BACK '\b'

class CProgFx
{	public:
	void ID_Uppercase();
	void Call_Function();
	virtual void Fx(){std::cout << NEWLINE << std::endl;}
	std::string FxId;
};

void CProgFx::ID_Uppercase()
{	transform (FxId.begin (), FxId.end (), FxId.begin (), toupper);	
}

class CGenericMenu
{	public:
	enum rel {up, down, sideways, root};
	CGenericMenu(void);
	virtual void menu();	
	std::string menuid;
	std::string menuname;
	std::vector<CProgFx*> MFxPointers;
	void Embed_function(CProgFx * ipt);
	virtual ~CGenericMenu();
};



