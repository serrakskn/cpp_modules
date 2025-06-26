/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:55:43 by sekeskin          #+#    #+#             */
/*   Updated: 2025/01/14 16:45:04 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    Cat* cat1 = new Cat();
    Dog* dog1 = new Dog();

    cat1->setIdea(0, "Catch a mouse");
    cat1->setIdea(1, "Climb a tree");

    dog1->setIdea(0, "Chase a ball");
    dog1->setIdea(1, "Guard the house");
	
	std::cout << std::endl;

    std::cout << "Cat1 sound: ";
    cat1->makeSound();
    
    std::cout << "Dog1 sound: ";
    dog1->makeSound();
	
	std::cout << std::endl;

    std::cout << "\nCat1's ideas:" << std::endl;
    cat1->getIdeas();

    std::cout << "\nDog1's ideas:" << std::endl;
    dog1->getIdeas();

	std::cout << std::endl;

    Cat* cat2 = new Cat(*cat1);
    Dog* dog2 = new Dog();
    *dog2 = *dog1;

    std::cout << "\nCat2's ideas after copying from Cat1:" << std::endl;
    cat2->getIdeas();

    std::cout << "\nDog2's ideas after copying from Dog1:" << std::endl;
    dog2->getIdeas();

	std::cout << std::endl;

    delete cat1;
    delete cat2;
    delete dog1;
    delete dog2;

	std::cout << std::endl;
    
	WrongAnimal *wrongAnimal = new WrongAnimal();
    WrongAnimal *wrongCat = new WrongCat();

	std::cout << std::endl;
    std::cout << "WrongAnimal makes sound: ";
    wrongAnimal->makeSound();

    std::cout << "WrongCat makes sound: ";
    wrongCat->makeSound();
	std::cout << std::endl;

    delete wrongAnimal;
    delete wrongCat;

	
    return 0;
}