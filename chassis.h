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

