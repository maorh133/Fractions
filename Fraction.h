#pragma once
class Fraction
{
public:
	Fraction(); // c'tor
	Fraction(int nominator, int denominator); // c'tor
	Fraction(int number); // c'tor

	~Fraction(); // d'tor

	int GetNominator() const;
	int GetDenominator() const;
	void reduction();
	friend Fraction operator+(const Fraction& first, const Fraction& second);
	friend Fraction operator+(const Fraction& first, int second);
	friend Fraction operator+(int first, const Fraction& second);

	friend Fraction operator-(const Fraction& first, const Fraction& second);
	friend Fraction operator-(const Fraction& first, int second);
	friend Fraction operator-(int first, const Fraction& second);

	friend Fraction operator*(const Fraction& first, const Fraction& second);
	friend Fraction operator*(const Fraction& first, int second);
	friend Fraction operator*(int first, const Fraction& second);

	friend Fraction operator/(const Fraction& first, const Fraction& second);
	friend Fraction operator/(const Fraction& first, int second);
	friend Fraction operator/(int first, const Fraction& second);

	 Fraction operator-();

	bool operator>(const Fraction& other) const;
	bool operator>(int other) const;
	bool operator>(float other) const;

	bool operator>=(const Fraction& other) const;
	bool operator>=(int other) const;
	bool operator>=(float other) const;

	bool operator<(const Fraction& other) const;
	bool operator<(int other) const;
	bool operator<(float other) const;

	bool operator<=(const Fraction& other) const;
	bool operator<=(int other) const;
	bool operator<=(float other) const;

	operator float() const;

private: 
	int m_nominator;
	int m_denominator;
};

