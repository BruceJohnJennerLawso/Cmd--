#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <vector>
#include <algorithm>
#include "ProgFx.h"
#define NEWLINE '\n'
#define TAB '\t'
#define VTAB '\v'
#define BEEP '\a'
#define BACK '\b'


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



