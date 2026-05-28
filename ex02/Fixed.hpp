/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:26:09 by kkido             #+#    #+#             */
/*   Updated: 2026/05/23 17:23:15 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <cmath>
#include <iostream>

class Fixed {
 public:
  Fixed();
  Fixed(const int value);
  Fixed(const float value);
  Fixed(const Fixed&);
  Fixed& operator=(const Fixed& src);
  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

  bool operator>(const Fixed& other) const;
  bool operator<(const Fixed& other) const;
  bool operator>=(const Fixed& other) const;
  bool operator<=(const Fixed& other) const;
  bool operator==(const Fixed& other) const;
  bool operator!=(const Fixed& other) const;

  Fixed operator+(const Fixed& other) const;
  Fixed operator-(const Fixed& other) const;
  Fixed operator*(const Fixed& other) const;
  Fixed operator/(const Fixed& other) const;

  Fixed& operator++();
  Fixed operator++(int);
  Fixed& operator--();
  Fixed operator--(int);

  static Fixed& min(Fixed& fixed_1, Fixed& fixed_2);
  static const Fixed& min(const Fixed& fixed_1, const Fixed& fixed_2);
  static Fixed& max(Fixed& fixed_1, Fixed& fixed_2);
  static const Fixed& max(const Fixed& fixed_1, const Fixed& fixed_2);

 private:
  int _fixed_point_num;
  static const int fractional_bit = fractional_bit;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
