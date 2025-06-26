/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookContact.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:12:03 by sekeskin          #+#    #+#             */
/*   Updated: 2024/12/09 16:05:42 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOKCONTACT_H
# define PHONEBOOKCONTACT_H

# include <iostream>

class PhoneBook;

class Contact{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string secret;
		std::string truncate(std::string str) const;

	public:
		Contact(void);
		~Contact(void);
		bool		checkPrintable(const std::string& str);
		void		setFirstName(void);
		void		setLastName(void);
		void		setNickname(void);
		void		setPhoneNumber(PhoneBook& phoneBook);
		void		setSecret(void);
        void    	displayContacts(int i);
		void		getContact(void);
		std::string	getFirstName(void);
		std::string	getLastName(void);
		std::string	getNickname(void);
		std::string	getPhoneNumber(void);
		std::string	getSecret(void);
};

class PhoneBook{
    private:
        Contact contacts[8];
        unsigned int contactNumber;

    public:
        PhoneBook(void);
        ~PhoneBook(void);

        void    cmdAdd(PhoneBook& phoneBook);
        void    cmdSearch(void);
        void    cmdExit(void);
        bool    isNumber(const std::string& str);

};

#endif