/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 14:36:27 by kkido             #+#    #+#             */
/*   Updated: 2026/05/22 1fractional_bit:11:30 by kkido            ###
 * ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <climits>

Fixed::Fixed() : _fixed_point_num(0) {
}

Fixed::Fixed(const int value) {
  if (value > INT_MAX >> fractional_bit || value < INT_MIN >> fractional_bit) {
    std::cerr << "Error: overflow or underflow occurred." << std::endl;
    _fixed_point_num = 0;
  } else
    _fixed_point_num = value * (1 << fractional_bit);
}

Fixed::Fixed(const float value) {
  float tmp = value * 256.0f;
  if (tmp > static_cast<float>(INT_MAX) || tmp < static_cast<float>(INT_MIN)) {
    std::cerr << "Error: overflow or underflow occurred." << std::endl;
    _fixed_point_num = 0;
  } else
    _fixed_point_num = roundf(tmp);
}

Fixed::Fixed(const Fixed& src) {
  this->_fixed_point_num = src.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& src) {
  if (this != &src) this->_fixed_point_num = src.getRawBits();
  return *this;
}

Fixed::~Fixed() {
}

int Fixed::getRawBits(void) const {
  return _fixed_point_num;
}

void Fixed::setRawBits(int const raw) {
  _fixed_point_num = raw;
}

float Fixed::toFloat(void) const {
  return (static_cast<float>(_fixed_point_num) / 256.0f);
}

int Fixed::toInt(void) const {
  return _fixed_point_num / (1 << fractional_bit);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
  os << fixed.toFloat();
  return os;
}

bool Fixed::operator>(const Fixed& other) const {
  return _fixed_point_num > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const {
  return _fixed_point_num < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const {
  return _fixed_point_num >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const {
  return _fixed_point_num <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const {
  return _fixed_point_num == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const {
  return _fixed_point_num != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed& other) const {
  Fixed result;
  int64_t value = static_cast<int64_t>(_fixed_point_num) + other.getRawBits();
  if (value > INT_MAX || value < INT_MIN) {
    std::cerr << "Error: overflow or underflow occurred." << std::endl;
    result.setRawBits(0);
  } else
    result.setRawBits(static_cast<int>(value));
  return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
  Fixed result;
  int64_t value = static_cast<int64_t>(_fixed_point_num) - other.getRawBits();
  if (value > INT_MAX || value < INT_MIN) {
    std::cerr << "Error: overflow or underflow occurred." << std::endl;
    result.setRawBits(0);
  } else
    result.setRawBits(static_cast<int>(value));
  return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
  Fixed result;
  int64_t value =
      (static_cast<int64_t>(_fixed_point_num) * other.getRawBits()) >>
      fractional_bit;
  if (value > INT_MAX || value < INT_MIN) {
    std::cerr << "Error: overflow or underflow occurred." << std::endl;
    result.setRawBits(0);
  } else
    result.setRawBits(static_cast<int>(value));
  return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
  Fixed result;

  if (other.getRawBits() == 0) {
    std::cerr << "Error: division by zero" << std::endl;
    result.setRawBits(0);
    return result;
  }

  int64_t value = (static_cast<int64_t>(_fixed_point_num) << fractional_bit) /
                  other.getRawBits();

  if (value > INT_MAX || value < INT_MIN) {
    std::cerr << "Error: overflow or underflow occurred." << std::endl;
    result.setRawBits(0);
  } else
    result.setRawBits(static_cast<int>(value));
  return result;
}

Fixed& Fixed::operator++() {
  _fixed_point_num++;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);
  _fixed_point_num++;
  return tmp;
}

Fixed& Fixed::operator--() {
  _fixed_point_num--;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);
  _fixed_point_num--;
  return tmp;
}

Fixed& Fixed::min(Fixed& fixed_1, Fixed& fixed_2) {
  if (fixed_1.getRawBits() <= fixed_2.getRawBits())
    return fixed_1;
  else
    return fixed_2;
}

const Fixed& Fixed::min(const Fixed& fixed_1, const Fixed& fixed_2) {
  if (fixed_1.getRawBits() <= fixed_2.getRawBits())
    return fixed_1;
  else
    return fixed_2;
}

Fixed& Fixed::max(Fixed& fixed_1, Fixed& fixed_2) {
  if (fixed_1.getRawBits() >= fixed_2.getRawBits())
    return fixed_1;
  else
    return fixed_2;
}

const Fixed& Fixed::max(const Fixed& fixed_1, const Fixed& fixed_2) {
  if (fixed_1.getRawBits() >= fixed_2.getRawBits())
    return fixed_1;
  else
    return fixed_2;
}