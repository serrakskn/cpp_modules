/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:04:41 by sekeskin          #+#    #+#             */
/*   Updated: 2025/02/05 13:25:16 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("Bureaucrat", 1); 
        Bureaucrat junior("Junior", 100); 
        
        std::cout << bureaucrat << std::endl;
        std::cout << junior << std::endl;
        std::cout << std::endl;

        std::cout << "Creating Forms...\n" << std::endl;

        PresidentialPardonForm pardonForm("Alice");
        RobotomyRequestForm robotomyForm("Bob");
        ShrubberyCreationForm shrubberyForm("James");
        
        std::cout << "✅ The forms have been created successfully!\n" << std::endl;

        std::cout << pardonForm << std::endl;
        std::cout << robotomyForm << std::endl;
        std::cout << shrubberyForm << std::endl;
        
        std::cout << std::endl;
        
        std::cout << "❌ Failed signature and execute attempt:\n" << std::endl;
        junior.signAForm(pardonForm);
        std::cout << pardonForm << std::endl;
        junior.executeForm(pardonForm);
        std::cout << std::endl;

        std::cout << "✅ Successfull signature and execute attempt:\n" << std::endl;
        bureaucrat.signAForm(pardonForm);
        std::cout << pardonForm << std::endl;
        bureaucrat.executeForm(pardonForm);
        std::cout << std::endl;

        std::cout << "✅ Successfull signature and execute attempt:\n" << std::endl;
        bureaucrat.signAForm(robotomyForm);
        std::cout << robotomyForm << std::endl;
        bureaucrat.executeForm(robotomyForm);
        std::cout << std::endl;

        std::cout << "✅ Successfull signature and execute attempt:\n" << std::endl;
        junior.signAForm(shrubberyForm);
        std::cout << shrubberyForm << std::endl;
        junior.executeForm(shrubberyForm);
        std::cout << std::endl;        

    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
