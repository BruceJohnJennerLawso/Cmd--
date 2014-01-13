// Math Bits Mathematics library for C++. Hail the Probe!!!
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include "MathFx.h"
#define NEWLINE '\n'
#define TAB '\t'
#define VTAB '\v'
#define BEEP '\a'
#define BACK '\b'
using namespace std;


// CTerm Class Defs //////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

CTerm::CTerm(void)
{	id = "NULL";	
}

double CTerm::Term(double x)
{	if (id == "NULL")
	{	cout << "Bad CTerm initialization to polymorphic base class";
	}
	else
	{	return 0;	
	}
}

CTerm::~CTerm()
{
}


// CTerm_Cx_eA Class Defs ////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

CTerm_Cx_eA::CTerm_Cx_eA(void)
{	c = 1;
	a = 2;	
	id = "Polynomial_Default";
}

CTerm_Cx_eA::CTerm_Cx_eA(double C, double A, std::string iid)
{	c = C;
	a = A;	
	id = iid;
}

double CTerm_Cx_eA::Term(double x)
{	try
	{	pRet = (pow(x,a));
		pRet = ((pRet)*c);
		return pRet;	
	}
	catch(exception& e)
	{	return 0;
	}
}

CTerm_Cx_eA::~CTerm_Cx_eA()
{
}


// CTerm_Cn_eax Class Defs ////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

CTerm_Cn_eax::CTerm_Cn_eax(void)
{	c = 1; 
	n = 2.71828;	// weak e approximation
	a = 1;
	id = "Natural_Exponential_Default";
}

CTerm_Cn_eax::CTerm_Cn_eax(double C, double N, double A, std::string iid)
{	c = C;
	n = N;	
	a = A;
	id = iid;
}

double CTerm_Cn_eax::Term(double x)
{	try
	{	x = x*a;
		pRet = (pow(n,x));
		pRet = ((pRet)*c);
		return pRet;
	}
	catch (exception& e)
	{	return 0;
	}
}

CTerm_Cn_eax::~CTerm_Cn_eax()
{
}

// CTerm_CCosax Class Defs ///////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

CTerm_CCosax::CTerm_CCosax(void)
{	c = 1;
	a = 1;
	id = "Cos_Default";
}

CTerm_CCosax::CTerm_CCosax(double C, double A, std::string iid)
{	c = C;
	a = A;
	id = iid;
}

double CTerm_CCosax::Term(double x)
{	try
	{	pRet = cos(x);
		pRet *= c;
		return pRet;
	}
	catch (exception& e)
	{	return 0;
	}
}

CTerm_CCosax::~CTerm_CCosax()
{
}

// CTerm_CArcCosax Class Defs ///////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

CTerm_CArcCosax::CTerm_CArcCosax(void)
{	c = 1;
	a = 1;
	id = "ArcCos_Default";
}

CTerm_CArcCosax::CTerm_CArcCosax(double C, double A, std::string iid)
{	c = C;
	a = A;
	id = iid;
}

double CTerm_CArcCosax::Term(double x)
{	try
	{	pRet = acos(x);
		pRet *= c;
		return pRet;
	}
	catch (exception& e)
	{	return 0;
	}
}

CTerm_CArcCosax::~CTerm_CArcCosax()
{
}

// CTerm_CSinax Class Defs ///////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

CTerm_CSinax::CTerm_CSinax(void)
{	c = 1;
	a = 1;
	id = "Sin_Default";
}

CTerm_CSinax::CTerm_CSinax(double C, double A, std::string iid)
{	c = C;
	a = A;
	id = iid;
}

double CTerm_CSinax::Term(double x)
{	try
	{	pRet = sin(x);
		pRet *= c;
		return pRet;
	}
	catch (exception& e)
	{	return 0;
	}
}

CTerm_CSinax::~CTerm_CSinax()
{
}

// CTerm_CArcSinax Class Defs ///////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

CTerm_CArcSinax::CTerm_CArcSinax(void)
{	c = 1;
	a = 1;
	id = "ArcSin_Default";
}

CTerm_CArcSinax::CTerm_CArcSinax(double C, double A, std::string iid)
{	c = C;
	a = A;
	id = iid;
}

double CTerm_CArcSinax::Term(double x)
{	try
	{	pRet = asin(x);
		pRet *= c;
		return pRet;
	}
	catch (exception& e)
	{	return 0;
	}
}

CTerm_CArcSinax::~CTerm_CArcSinax()
{
}

// CTerm_CTanax Class Defs ///////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

CTerm_CTanax::CTerm_CTanax(void)
{	c = 1;
	a = 1;
	id = "Tan_Default";
}

CTerm_CTanax::CTerm_CTanax(double C, double A, std::string iid)
{	c = C;
	a = A;
	id = iid;
}

double CTerm_CTanax::Term(double x)
{	try
	{	pRet = tan(x);
		pRet *= c;
		return pRet;
	}
	catch (exception& e)
	{	return 0;
	}
}

CTerm_CTanax::~CTerm_CTanax()
{
}

// CTerm_CArcTanax Class Defs ///////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

CTerm_CArcTanax::CTerm_CArcTanax(void)
{	c = 1;
	a = 1;
	id = "ArcTan_Default";
}

CTerm_CArcTanax::CTerm_CArcTanax(double C, double A, std::string iid)
{	c = C;
	a = A;
	id = iid;
}

double CTerm_CArcTanax::Term(double x)
{	try
	{	pRet = atan(x);
		pRet *= c;
		return pRet;
	}
	catch (exception& e)
	{	return 0;
	}
}

CTerm_CArcTanax::~CTerm_CArcTanax()
{
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Sums of Products of Compositions! ////////////////////////////////////////////////////////////////////////////////////////////////
// Somewhere in my brain, this message is literally scorched into the neurons from making MathFX ////////////////////////////////////
// It was almost mentally painful, but very worthwhile in the long run //////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



// TComposition Class Def ////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

TCompositions::TCompositions()
{
}

TCompositions::TCompositions(std::string iid)
{	id = iid;
}

double TCompositions::Evaluate_composition(double x)
{	double vreturn; 
	itsCT = this->Comps.begin();
	vreturn = (*itsCT)->Term(x);
	if (Comps.size() > 1)
	{	for (itsCT = (this->Comps.begin()+1); itsCT != this->Comps.end(); ++itsCT)
		{	vreturn = (*itsCT)->Term(vreturn);
		}
	}
	return vreturn;
}

TCompositions::~TCompositions()
{
}

// TProducts Class Def ///////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

TProducts::TProducts()
{
}

TProducts::TProducts(std::string iid)
{	id = iid;
}

double TProducts::Evaluate_product(double x)
{	double vreturn;
	itsTC = this->Prods.begin();
	vreturn = (*itsTC)->Evaluate_composition(x);
	if (Prods.size() > 1)
	{	for (itsTC = (this->Prods.begin()+1); itsTC != this->Prods.end(); ++itsTC)
		{	vreturn += (*itsTC)->Evaluate_composition(x);
		}
	}
	return vreturn;
}

TProducts::~TProducts()
{
}

// TSums Class Def ///////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

TSums::TSums()
{
}


double TSums::Evaluate_sum(double x)
{	double vreturn;
	itsTP = this->Sums.begin();
	vreturn = (*itsTP)->Evaluate_product(x);
	if (Sums.size() > 1)
	{	for (itsTP = (this->Sums.begin()+1); itsTP != this->Sums.end(); ++itsTP)
		{	vreturn *= (*itsTP)->Evaluate_product(x);
		}
	}
	return vreturn;
}

TSums::~TSums()
{
}



// CFunction Class Def ///////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

CFunction::CFunction(void)
{	
}

CFunction::CFunction(std::string iid)
{	id = iid;
}

CFunction::CFunction(vector<TSums*> FPass)
{	for (it = (FPass.begin()); it != (FPass.end()); ++it)		
	{	FTerms.push_back(*it);
	}
}

double CFunction::F_at_x (double x)
{	double vreturn;
	it = FTerms.begin();
	vreturn = (*it)->Evaluate_sum(x);
	if (FTerms.size() > 1)
	{	for (it = (FTerms.begin()+1); it != (FTerms.end()); ++it)
		{	vreturn += (*it)->Evaluate_sum(x);	
		}
	}
	return vreturn;
}

CFunction::~CFunction()
{
}






// MathFX Namespace //////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Function-level Functions /////////////			Yo dawg, I heard you like functions.
/////////////////////////////////////////			So I made a function for your functions, so we can functionally functionalize your functions

void MathFX::Create_function()
{
}

void MathFX::Assign_sum_to_function()
{
}



// CTerm Creation ///////////////////////
/////////////////////////////////////////

void MathFX::Create_term()
{
}



// Sum-level Functions //////////////////
/////////////////////////////////////////

void MathFX::Create_sum()
{
}

void MathFX::Assign_product_to_sum()
{
}



// Product-level Functions //////////////
/////////////////////////////////////////

void MathFX::Create_product()
{
}

void MathFX::Assign_composition_to_product()
{
}



// Composition-level Functions //////////
/////////////////////////////////////////

void MathFX::Create_composition()
{
}

void MathFX::Insert_product_into_composition()
{
}