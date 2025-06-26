/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:04:38 by sekeskin          #+#    #+#             */
/*   Updated: 2025/02/05 12:47:04 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string  _name;
		size_t _grade;
		
	public:
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, size_t grade);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat();

		Bureaucrat &operator=(Bureaucrat const &copy);

		std::string getName() const;
		size_t getGrade() const;

		void incrementGrade();
		void decrementGrade();
        void signAForm(AForm &f);
		void executeForm(AForm const & form);
		
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
	
};

std::ostream	&operator<<(std::ostream& os, const Bureaucrat& b);

