/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:04:38 by sekeskin          #+#    #+#             */
/*   Updated: 2025/02/01 17:37:20 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp"

class Form;

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
        void signForm(Form &f);
		
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

#endif
