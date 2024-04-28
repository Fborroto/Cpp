/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:50:55 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/28 04:18:25 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
  private:
	int value;
	static const int bits = 8;

  public:
	Fixed();
	Fixed(const Fixed &fixed);
	const Fixed &operator=(const Fixed &fixed);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
