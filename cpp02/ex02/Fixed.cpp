/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:41:02 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/03 12:08:50 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fracBits = 8;

Fixed::Fixed(void) : _value(0) {
}

Fixed::Fixed(const int intValue) {
	_value = intValue << _fracBits;
}

Fixed::Fixed(const float floatValue) {
	_value = roundf(floatValue * (1 << _fracBits));
}

Fixed::Fixed(Fixed const &copy) {
	*this = copy;
}

Fixed	&Fixed::operator=(const Fixed &copy) {
	this->_value = copy.getRawBits();
	return *this;
}

Fixed::~Fixed(void) {
}

float Fixed::toFloat( void ) const {
	return (float)_value / (1 << _fracBits);
}

int Fixed::toInt( void ) const {
	return _value >> _fracBits;
}

int Fixed::getRawBits( void ) const {
	return this->_value;
}

void Fixed::setRawBits( int const raw ) {
	this->_value = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed &other) const {
    return this->_value > other._value;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->_value != other._value;
}

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result._value = this->_value + other._value;
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result._value = this->_value - other._value;
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;
    result._value = (this->_value * other._value) >> _fracBits;
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed result;
    result._value = (this->_value << _fracBits) / other._value;
    return result;
}

Fixed &Fixed::operator++() {
    ++_value;
    return *this;
}

Fixed &Fixed::operator--() {
    --_value;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++_value;
    return temp;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --_value;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}