#include "Fraction.h"

Fraction::Fraction(int number)
{
	this->m_nominator = number;
	this->m_denominator = 1;
}

Fraction::Fraction(int nominator, int denominator)
{
	if (denominator == 0)
	{
		this->m_nominator = 0;
		this->m_denominator = 1;
	}
	else
	{
		this->m_nominator = nominator;
		this->m_denominator = denominator;
	}
	if (denominator < 0) // denominator allows positive
	{
		this->m_nominator *= -1;
		this->m_denominator *= -1;
	}
}

Fraction::Fraction()
{
	this->m_nominator = 0;
	this->m_denominator = 1;
}

Fraction::~Fraction()
{

}

int Fraction::GetNominator()const
{
	return m_nominator;
}

int Fraction::GetDenominator()const
{
	return m_denominator;
}

void Fraction::reduction()
{
	int index=2;
	while (index<=m_denominator)
	{
		if (m_nominator%index == 0 && m_denominator%index == 0)
		{
			m_nominator /= index;
			m_denominator /= index;
			//index = 2;
		}
		else
		{
			index++;
		}
	}
}

Fraction operator+(const Fraction & first, const Fraction & second)
{
	return Fraction((first.GetNominator() *second.GetDenominator()) + (second.GetNominator()*first.GetDenominator()), first.GetDenominator() * second.GetDenominator());
}

Fraction operator+(int first, const Fraction & second)
{
	return Fraction(first * second.GetDenominator() + second.GetNominator(), second.GetDenominator());
}

Fraction operator+(const Fraction & first, int  second)
{
	return second + first;
}

Fraction operator-(const Fraction & first, const Fraction &  second)
{
	return Fraction((first.GetNominator()*second.GetDenominator()) - (second.GetNominator()*first.GetDenominator()), first.GetDenominator() * second.GetDenominator());
}
Fraction operator-(const Fraction & first, int  second)
{
	return Fraction(first.GetNominator() - second*first.GetDenominator(), first.GetDenominator());
}
Fraction operator-(int first, const Fraction &  second)
{
	return (second - first)*-1;
}


Fraction operator*(const Fraction& first, const Fraction& second)
{
	return Fraction(first.GetNominator()* second.GetNominator(), first.GetDenominator() * second.GetDenominator());
}
Fraction operator*(const Fraction& first, int second)
{
	return Fraction(first.GetNominator()* second, first.GetDenominator());
}

Fraction operator*(int first, const Fraction& second)
{
	return second * first;
}

Fraction operator/(const Fraction& first, const Fraction& second)
{
	return Fraction(first.GetNominator() * second.GetDenominator(), first.GetDenominator() * second.GetNominator());
}

Fraction operator/(const Fraction& first,  int second)
{
	return Fraction(first.GetNominator() , first.GetDenominator() * second);
}

Fraction operator/(int first, const Fraction& second)
{
	return Fraction(first * second.GetDenominator(), second.GetNominator());
}

Fraction Fraction::operator-()
{
	return Fraction(-GetDenominator(), GetNominator());
}

bool Fraction::operator>(const Fraction & other) const
{
	return (float)*this - (float)other > 0.0;
}
bool Fraction::operator>(int other) const
{
	return (float)*this - (float)other > 0.0;
}
bool Fraction::operator>(float other) const
{
	return (float)*this - other > 0.0;
}

bool Fraction::operator>=(const Fraction & other) const
{
	return (float)*this - (float)other >= 0.0;
}
bool Fraction::operator>=(int other) const
{
	return (float)*this - (float)other >= 0.0;
}
bool Fraction::operator>=(float other) const
{
	return (float)*this - other >= 0.0;
}

bool Fraction::operator<(const Fraction & other) const
{					   
	return (float)*this -(float)other < 0.0;
}					   
bool Fraction::operator<(int other) const
{					   
	return (float)*this -(float)other < 0.0;
}					   
bool Fraction::operator<(float other) const
{					   
	return (float)*this- other < 0.0;
}			   
					   
bool Fraction::operator<=(const Fraction & other) const
{					   
	return (float)*this -(float)other <= 0.0;
}					   
bool Fraction::operator<=(int other) const
{					   
	return (float)*this -(float)other <= 0.0;
}					   
bool Fraction::operator<=(float other) const
{
	return (float)*this - other <= 0.0;
}

Fraction::operator float() const
{
	return (float)m_nominator / m_denominator;
}

