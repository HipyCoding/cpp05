/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christian <christian@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 04:20:43 by christian         #+#    #+#             */
/*   Updated: 2025/07/06 21:01:09 by christian        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>

class Intern
{
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm* makeForm(const std::string& formName, const std::string& target);

	class FormNotFoundException : public std::exception
	{
		public:
			const char* what() const noexcept override;
	};

private:
	// array of form creation functions
	AForm* (Intern::*formCreators[3])(const std::string& target);
	std::string formNames[3];
	
	// form creation functions
	AForm* createShrubberyForm(const std::string& target);
	AForm* createRobotomyForm(const std::string& target);
	AForm* createPresidentialForm(const std::string& target);
};

#endif