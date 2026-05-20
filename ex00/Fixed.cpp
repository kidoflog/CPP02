/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 14:36:27 by kkido             #+#    #+#             */
/*   Updated: 2026/05/20 21:54:26 by kkido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "iostream"

Fixed::Fixed() : _fixed_point_num(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src){
	std::cout << "Copy constructor called" << std::endl;
	this->_fixed_point_num = src.getRawBits();
}

Fixed& Fixed::operator = (const Fixed &src){
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &src)
		this->_fixed_point_num = src.getRawBits();
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixed_point_num;
}

void Fixed::setRawBits(int const &raw){
	_fixed_point_num = raw;
}
