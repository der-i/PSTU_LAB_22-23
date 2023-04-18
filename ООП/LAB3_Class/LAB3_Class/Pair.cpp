#include "Pair.h"


ostream& operator <<(ostream& os, const Pair& val)
{
	os << val.first << " : " << val.second;
	return os;
}

istream& operator>>(istream& is, Pair& val)
{
	is >> val.first >> val.second;
	return is;
}

Pair::Pair()
{
	first = 0;
	second = 0;
}

Pair::Pair(const Pair& copy)
{
	this->first = copy.first;
	this->second = copy.second;
}

Pair::Pair(int first, double second)
{
	this->first = first;
	this->second = second;
}

Pair& Pair::operator=(const Pair& other)
{
	this->first = other.first;
	this->second = other.second;	
	return *this;
}

Pair Pair::operator+(const Pair& other)
{
	Pair temp(this->first + other.first, this->second + other.second);
	return temp;
}
Pair& Pair::operator++()
{
	++this->first;
	++this->second;
	return *this;
}

Pair Pair::operator++(int)
{
	Pair temp(*this);
	++this->first;
	++this->second;
	return temp;
}

Pair Pair::operator-(const Pair& other)
{
	Pair temp(this->first - other.first, this->second - other.second);
	return temp;
}

const Pair operator+(const Pair& left, const int& right)
{
	return Pair(left.first + right, left.second);
}

const Pair operator+(const int& left, const Pair& right)
{
	return right + left;
}

const Pair operator+(const Pair& left, const double& right)
{
	return Pair(left.first, left.second + right);
}

const Pair operator+(const double& left, const Pair& right)
{
	return right + left;
}