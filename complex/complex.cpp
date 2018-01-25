#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;


class complex_t {
private:
	double r_;
	double i_;

public:

	complex_t(double r,double i);
	complex_t(void);

	~complex_t(void);
	
	void imprime_complejo(ostream& os) const;

	void set_real(double r);
	void set_imag(double i);
	
	double get_real(void) const;
	double get_imag(void) const;
	double get_modulo(void) const;
	double get_fase(void) const;
};
 
complex_t::complex_t(double r,double i)
{
	r_=r;
	i_=i;
}

complex_t::complex_t(void)
{
	r_=0;
	i_=0;
}

complex_t::~complex_t(void)
{
	cout << "-- Bye, bye, complex! --" << endl;
}

void complex_t::imprime_complejo(ostream& os) const
{
	os << setw(5) << fixed << setprecision(1) << r_;
	os << " + ";
	os << setw(5) << fixed << setprecision(1) << i_;
	os << "i";
}

void complex_t::set_real(double r)
{
	r_=r;
}

void complex_t::set_imag(double i)
{
	i_=i;
}

double complex_t::get_real(void) const
{
	return r_;
}

double complex_t::get_imag(void) const
{
	return i_;
}

double complex_t::get_modulo(void) const 
{
	return sqrt(r_*r_+i_*i_);	
}

double complex_t::get_fase(void) const
{
	return atan2(i_,r_);	
}

ostream& operator<<(ostream& os, complex_t& c)
{
	c.imprime_complejo(os);
	return os;
}


complex_t operator+(complex_t& c1,complex_t& c2)  
{
	complex_t aux;

	aux.set_real(c1.get_real()+c2.get_real());
	aux.set_imag(c1.get_imag()+c2.get_imag());

	return aux;
}

complex_t operator*(complex_t& c1,complex_t& c2) 
{
	complex_t aux;

	aux.set_real(c1.get_real()*c2.get_real()- c1.get_imag()*c2.get_imag());
	aux.set_imag(c1.get_real()*c2.get_imag()+ c2.get_real()*c1.get_imag());

	return aux;	
}


bool operator==(complex_t& c1,complex_t& c2)  
{
	return (c1.get_real()==c2.get_real())&&(c1.get_imag()==c2.get_imag());
}


int main(void)
{
	complex_t a(1, 2), b(2, 3), c(3, 4), d;

	cout << endl;
	a.imprime_complejo(cout);
	cout << endl;
	b.imprime_complejo(cout);
	cout << endl;
	c.imprime_complejo(cout);
	cout << endl;
	d.imprime_complejo(cout);
	cout << endl;
	cout << endl;

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	cout << endl;
		
	cout << "Parte real      : "<< a.get_real()<< std::endl;
	cout << "Parte imaginaria: "<< a.get_imag()<< std::endl;
	cout << "Módulo          : "<< a.get_modulo()<< std::endl;
	cout << "Fase            : "<< a.get_fase()<<std::endl;
	cout << endl;

	cout << "Cambiando número: " << a; 
	a.set_real(5);
        //a.r_=5;               // ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!
	cout << " a "<< a << endl;
	cout << endl;

	cout << "Suma            : " << a << " + " << b<< " = ";

	c = a + b; 

	cout << c << endl;
	cout << endl;

	cout << "Producto        : "<< a << " * " << b << " = ";

	d = a * b;  

	cout << d << endl;
	cout << endl;
}

