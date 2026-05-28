/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 14:36:27 by kkido             #+#    #+#             */
/*   Updated: 2026/05/22 18:11:30 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <climits>

Fixed::Fixed() : _fixed_point_num(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
  std::cout << "Int constructor called" << std::endl;
  if (value > INT_MAX >> fractional_bit || value < INT_MIN >> fractional_bit) {
    std::cerr << "Error: overflow or underflow occurred." << std::endl;
    _fixed_point_num = 0;
  } else
    _fixed_point_num = value * (1 << fractional_bit);
}

Fixed::Fixed(const float value) {
  std::cout << "Float constructor called" << std::endl;
  float tmp = value * 256.0f;
  if (tmp > static_cast<float>(INT_MAX) || tmp < static_cast<float>(INT_MIN)) {
    std::cerr << "Error: overflow or underflow occurred." << std::endl;
    _fixed_point_num = 0;
  } else
    _fixed_point_num = roundf(tmp);
}

Fixed::Fixed(const Fixed& src) {
  std::cout << "Copy constructor called" << std::endl;
  this->_fixed_point_num = src.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& src) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &src) this->_fixed_point_num = src.getRawBits();
  return *this;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
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
  return (_fixed_point_num >> fractional_bit);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
  os << fixed.toFloat();
  return os;
}
