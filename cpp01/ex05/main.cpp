/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:58:38 by sekeskin          #+#    #+#             */
/*   Updated: 2024/12/24 14:35:31 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
    Harl h;

	h.complain("DEBUG");
	h.complain("INFO");
	h.complain("WARNING");
    h.complain("ERROR");
	return (0);
}