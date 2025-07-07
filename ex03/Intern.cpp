/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 04:20:41 by christian         #+#    #+#             */
/*   Updated: 2025/07/07 23:48:08 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// default constructor
Intern::Intern()
{
	// initialize array of form names
	formNames[0] = "shrubbery creation";
	formNames[1] = "robotomy request";
	formNames[2] = "presidential pardon";
	
	// initialize array of function pointers
	formCreators[0] = &Intern::createShrubberyForm;
	formCreators[1] = &Intern::createRobotomyForm;
	formCreators[2] = &Intern::createPresidentialForm;
}

// copy constructor
Intern::Intern(const Intern& other)
{
	// initialize arrays
	for (int i = 0; i < 3; i++)
	{
		formNames[i] = other.formNames[i];
		formCreators[i] = other.formCreators[i];
	}
}

// assignment operator
Intern& Intern::operator=(const Intern& other)
{
	if (this != &other)
	{
		// copy arrays
		for (int i = 0; i < 3; i++)
		{
			formNames[i] = other.formNames[i];
			formCreators[i] = other.formCreators[i];
		}
	}
	return *this;
}

// destructor
Intern::~Intern()
{
	std::cout << " Intern destructor called" << std::endl;
}

// form creation functions
AForm* Intern::createShrubberyForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

// main function to create forms using function pointer array
AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	// search for the form name in the array
	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			// call the corresponding function using function pointer
			return (this->*formCreators[i])(target);
		}
	}
	
	// if form not found, throw exception
	throw FormNotFoundException();
}

// exception for form not found
const char* Intern::FormNotFoundException::what() const noexcept
{
	return ("Form Not Found");
}
