/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:22:24 by sekeskin          #+#    #+#             */
/*   Updated: 2024/12/31 15:54:31 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed {
	private:
		int _value;
		static const int _fracBits;

	public:
		Fixed(void);
		Fixed(Fixed const &copy);
		
		~Fixed(void);
		
		Fixed	&operator=(const Fixed &copy);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
};
