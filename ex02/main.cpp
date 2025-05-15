/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:46:38 by rnovotny          #+#    #+#             */
/*   Updated: 2025/05/13 16:07:10 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed const b(a);
	Fixed c(42.42f);
	Fixed d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a.getRawBits() << std::endl;
	std::cout << "b is " << b.getRawBits() << std::endl;
	std::cout << "c is " << c.getRawBits() << std::endl;
	std::cout << "d is " << d.getRawBits() << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}
