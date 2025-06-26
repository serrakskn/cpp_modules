/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:04:41 by sekeskin          #+#    #+#             */
/*   Updated: 2025/02/05 19:18:41 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    AForm* form1 = NULL;
    AForm* form2 = NULL;
    AForm* form3 = NULL;
    try
    {
        std::cout << "✅ Successfull form example:\n" << std::endl;
        form1 = someRandomIntern.makeForm("presidential pardon", "Alice");
        form2 = someRandomIntern.makeForm("robotomy request", "Bob");
        form3 = someRandomIntern.makeForm("shrubbery creation", "James");

        Bureaucrat a("John", 156);
        a.signAForm(*form1);
        a.executeForm(*form1);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    delete form1;
    delete form2;
    delete form3;
    
    std::cout << std::endl;

    AForm* form = NULL;
    try {
        std::cout << "❌ Invalid form example:\n" << std::endl;
        form = someRandomIntern.makeForm("some random form", "John");
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    delete form;

    std::cout << std::endl;

}