/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:43:35 by sekeskin          #+#    #+#             */
/*   Updated: 2025/02/05 18:52:12 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm {
	private:
		const std::string  _name;
		bool _isSigned;
		const size_t _signGrade;
		const size_t _execGrade;
	public:
		AForm();
		AForm(std::string name);
		AForm(std::string name, size_t signGrade, size_t execGrade);
		AForm(AForm const &copy);
		virtual ~AForm();

		AForm &operator=(AForm const &copy);

		std::string getName() const;
		bool getIsSigned() const;
		size_t getSignGrade() const;
		size_t getExecGrade() const;
		
		void beSigned(Bureaucrat &b);
		void execute(Bureaucrat const & executor) const;
		virtual void executeAction(void) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		class FormNotSignedException: public std::exception {
            const char* what() const throw();
        };
};

std::ostream	&operator<<(std::ostream& os, const AForm& f);
