/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christian <christian@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:51:58 by candrese          #+#    #+#             */
/*   Updated: 2025/07/06 22:36:53 by christian        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main(void)
{
	Intern someRandomIntern;
	AForm* form[4] = {nullptr};
	
	try
	{
		form[0] = someRandomIntern.makeForm("shrubbery creation", "Tree");
		form[1] = someRandomIntern.makeForm("robotomy request", "Bot");
		form[2] = someRandomIntern.makeForm("Donald Trump pardon", "Musk");
		
		for (int i = 0; i < 3; i++)
		{
			std::cout << "  - " << form[i]->getName() << " created!" << std::endl;
		}
		
		form[3] = someRandomIntern.makeForm("unknown form", "Nope");
		std::cout << "  - " << form[3]->getName() << " never created!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	for (int i = 0; i < 4; i++)
	{
		if (form[i])
			delete form[i];
	}
	
	return (0);
}