/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonoForm.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:23:50 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/15 18:15:12 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONOFORM_HPP
# define PRESIDENTIALPARDONOFORM_HPP

# include "AForm.hpp"

class PresidentialPardonoForm : public AForm
{
	public:
		PresidentialPardonoForm();
		PresidentialPardonoForm(std::string target);
		PresidentialPardonoForm(const PresidentialPardonoForm& src);
		~PresidentialPardonoForm();

		PresidentialPardonoForm& operator=(const PresidentialPardonoForm& src);
};

#endif