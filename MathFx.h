// Math Bits Header File
using namespace std;

// CTerm Class Declaration /////////////////
////////////////////////////////////////////

class CTerm
{	public:
	CTerm(void);
	std::string id;
	virtual double Term(double x);
	~CTerm();
	double pRet;	
};

// CTerm_Cx_eA Class Declaration ///////////
////////////////////////////////////////////

class CTerm_Cx_eA: public CTerm
{	public:
	CTerm_Cx_eA(void);
	CTerm_Cx_eA(double C, double A, std::string iid);
	double Term(double x);
	double c, a;
	~CTerm_Cx_eA();		
};

// CTerm_Cn_ex Class Declaration ///////////
////////////////////////////////////////////

class CTerm_Cn_eax: public CTerm
{	public:
	CTerm_Cn_eax(void);
	CTerm_Cn_eax(double C, double N, double A, std::string iid);
	double Term(double x);
	double c, n, a;
	~CTerm_Cn_eax();
};

// CTerm_CCosax Class Declaration ///////////
////////////////////////////////////////////

class CTerm_CCosax: public CTerm
{	public:
	CTerm_CCosax(void);
	CTerm_CCosax(double C, double A, std::string iid);
	double Term(double x);
	double c, a;
	~CTerm_CCosax();		
};

// CTerm_CArcCosax Class Declaration ///////////
////////////////////////////////////////////

class CTerm_CArcCosax: public CTerm
{	public:
	CTerm_CArcCosax(void);
	CTerm_CArcCosax(double C, double A, std::string iid);
	double Term(double x);
	double c, a;
	~CTerm_CArcCosax();		
};

// CTerm_CSinax Class Declaration ///////////
////////////////////////////////////////////

class CTerm_CSinax: public CTerm
{	public:
	CTerm_CSinax(void);
	CTerm_CSinax(double C, double A, std::string iid);
	double Term(double x);
	double c, a;
	~CTerm_CSinax();		
};

// CTerm_CArcSinax Class Declaration ///////////
////////////////////////////////////////////

class CTerm_CArcSinax: public CTerm
{	public:
	CTerm_CArcSinax(void);
	CTerm_CArcSinax(double C, double A, std::string iid);
	double Term(double x);
	double c, a;
	~CTerm_CArcSinax();		
};

// CTerm_CTanax Class Declaration ///////////
////////////////////////////////////////////

class CTerm_CTanax: public CTerm
{	public:
	CTerm_CTanax(void);
	CTerm_CTanax(double C, double A, std::string iid);
	double Term(double x);
	double c, a;
	~CTerm_CTanax();		
};

// CTerm_CArcTanax Class Declaration ///////////
////////////////////////////////////////////

class CTerm_CArcTanax: public CTerm
{	public:
	CTerm_CArcTanax(void);
	CTerm_CArcTanax(double C, double A, std::string iid);
	double Term(double x);
	double c, a;
	~CTerm_CArcTanax();		
};

// CFunction Class Declaration /////////////
////////////////////////////////////////////

class TCompositions
{	public:
	TCompositions();
	TCompositions(std::string iid);
	std::vector<CTerm*> Comps;
	std::vector<CTerm*>::iterator itsCT;
	std::string id;
	double Evaluate_composition(double x);
	~TCompositions();
};

class TProducts
{	public:
	TProducts(void);
	TProducts(std::string iid);
	std::vector<TCompositions*> Prods;
	std::vector<TCompositions*>::iterator itsTC;
	std::string id;
	double Evaluate_product(double x);
	~TProducts();
};

class TSums
{	public:
	TSums(void);
	TSums(std::string iid);
	std::vector<TProducts*> Sums;
	std::vector<TProducts*>::iterator itsTP;
	std::string id;
	double Evaluate_sum(double x);
	~TSums();
};

class CFunction
{	public:
	CFunction(void);
	CFunction(std::string iid);
	CFunction(vector<TSums*> FPass);
	vector<TSums*> FTerms;
	vector<TSums*>::iterator it;
	std::string id;
	double F_at_x (double x);
	~CFunction();
};

// Sums of products of compositions.

namespace MathFX
{	void Create_function();
	void Assign_sum_to_function();
	
	void Create_term();
	
	void Create_sum();
	void Assign_product_to_sum();
	
	void Create_product();
	void Assign_composition_to_product();
	
	void Create_composition();
	void Insert_product_into_composition();

};