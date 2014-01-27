#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>

class CProgFx
{	public:
	void ID_Uppercase();
	void Call_Function();
	virtual void Fx(){std::cout << "\n" << std::endl;}
	std::string FxId;
};