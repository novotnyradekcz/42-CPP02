/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:43:34 by rnovotny          #+#    #+#             */
/*   Updated: 2025/05/13 16:35:17 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

// Constructors
Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _fixedPointValue(value << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _fixedPointValue(static_cast<int>(roundf(value * (1 << _fractionalBits))))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Assignment operator
Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return *this;
}

// Comparison operators
bool Fixed::operator>(const Fixed &rhs) const
{
	return this->_fixedPointValue > rhs._fixedPointValue;
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return this->_fixedPointValue < rhs._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return this->_fixedPointValue >= rhs._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return this->_fixedPointValue <= rhs._fixedPointValue;
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return this->_fixedPointValue == rhs._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return this->_fixedPointValue != rhs._fixedPointValue;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}
Fixed Fixed::operator-(const Fixed &rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}
Fixed Fixed::operator*(const Fixed &rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}
Fixed Fixed::operator/(const Fixed &rhs) const
{
	if (rhs._fixedPointValue == 0)
	{
		std::cerr << "Division by zero" << std::endl;
		return Fixed(0);
	}
	return Fixed(this->toFloat() / rhs.toFloat());
}

// Increment/Decrement operators
Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_fixedPointValue++;
	return temp;
}

Fixed &Fixed::operator++()
{
	this->_fixedPointValue++;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_fixedPointValue--;
	return temp;
}

Fixed &Fixed::operator--()
{
	this->_fixedPointValue--;
	return *this;
}

// Member functions
int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

int Fixed::toInt() const
{
	return this->_fixedPointValue >> _fractionalBits;
}

// Insertion operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}