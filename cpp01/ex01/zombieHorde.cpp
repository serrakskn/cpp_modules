/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:13:43 by sekeskin          #+#    #+#             */
/*   Updated: 2024/12/25 13:20:40 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
    if (N <= 0)
        return NULL;
    
    Zombie* horde = new Zombie[N];

    if (!horde)
        return NULL;
    for (int i = 0; i < N; i++)
        horde[i].setName(name);
    return horde;
}