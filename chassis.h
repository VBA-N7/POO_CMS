class Chassis
{
public:
	Chassis(int option_finition);

	int		get_nb_portes(void);
	float	get_coef_pen(void);
	virtual void calcul_coef_pen(void) = 0;

private:
	int option;
protected:
	int nb_portes;
	float coef_pen;
	float R = 0.03;
	
	/*DIMENSIONS*/
	float L1 = 4.6;
	float L2;
	float h;
	float l = 2.2;

};

class Coupe : public Chassis 
{
public:
	Coupe(int option_finition);

protected:
	void calcul_coef_pen(void);
};

class Berline : public Chassis
{
public:
	Berline(int option_finition);

protected:
	void calcul_coef_pen(void);
};

class Break : public Berline
{
public:
	Break(int option_finition);

protected:
	void calcul_coef_pen(void);
};
