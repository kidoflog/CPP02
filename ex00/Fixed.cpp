/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 14:36:27 by kkido             #+#    #+#             */
/*   Updated: 2026/05/17 16:06:33 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed_point_num(0){
}

Fixed::Fixed(const Fixed&){
}

Fixed& Fixed::operator = (const Fixed& src){
	return *this;
}

Fixed::~Fixed(){
}

int Fixed::getRawBits(void) const{

}

void setRawBits(int const raw){

}
