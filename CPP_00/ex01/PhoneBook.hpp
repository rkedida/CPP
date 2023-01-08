/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:09:06 by rkedida           #+#    #+#             */
/*   Updated: 2023/01/08 16:37:12 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"

class Contact;

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		index;
		int		total;

	public:
		PhoneBook();
		~PhoneBook();
		void create_contact(void);
		void search_contact(void);

		int string_to_int(std::string buffer);

		void set_total(int total);
		int get_total(void);
};

#endif