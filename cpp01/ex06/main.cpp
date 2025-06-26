/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:28:44 by sekeskin          #+#    #+#             */
/*   Updated: 2024/12/25 14:34:53 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (int ac, char **av) {
    Harl h;
    
	if (ac == 2)
		h.complain(av[1]);
	else
		h.complain("irrelevant string");
    return 0;
}