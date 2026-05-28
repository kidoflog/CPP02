/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:26:09 by kkido             #+#    #+#             */
/*   Updated: 2026/05/21 11:28:26 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
class Fixed {
 public:
  Fixed();
  Fixed(const Fixed&);
  Fixed& operator=(const Fixed& src);
  ~Fixed();
  int getRawBits(void) const;
  void setRawBits(int const raw);

 private:
  int _fixed_point_num;
  static const int fractional_bit = 8;
};

#endif
