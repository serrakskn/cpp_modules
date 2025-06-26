/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:33:43 by sekeskin          #+#    #+#             */
/*   Updated: 2024/12/25 13:24:14 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main() {
    size_t n = 10;
    Zombie *horde;
    horde = zombieHorde( n, "Zoo" );
    if (horde) {    
        for (size_t i = 0; i < n; i++)
            horde[i].announce();
        delete[] horde;
    }
    return 0;
}