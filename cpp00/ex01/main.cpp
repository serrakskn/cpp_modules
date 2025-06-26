/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:18:06 by sekeskin          #+#    #+#             */
/*   Updated: 2024/12/09 16:05:46 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBookContact.hpp"

int	main(void)
{
	PhoneBook 	phoneBook;
	std::string	input;

	std::cout << "Welcome to the Phone Book!" << std::endl;
	while (true)
	{
		std::cout << "Please enter a command: ADD - SEARCH - EXIT > ";
		std::getline(std::cin, input);
		if (input == "ADD")
			phoneBook.cmdAdd(phoneBook);
		else if (input == "SEARCH")
			phoneBook.cmdSearch();
        else if (input == "EXIT")
            phoneBook.cmdExit();
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
	}
	return (0);
}