/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christian <christian@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:51:58 by candrese          #+#    #+#             */
/*   Updated: 2025/07/06 19:16:38 by christian        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
	std::cout << "\n------ testing shrubbery creation form" << std::endl;
	try {
		Bureaucrat martin("Martin", 100);
		ShrubberyCreationForm tree_form("trees");
		
		std::cout << tree_form << std::endl;
		martin.signForm(tree_form);
		martin.executeForm(tree_form);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n\n------ testing robotomy request form" << std::endl;
	try
	{
		Bureaucrat alban("Alban", 40);
		RobotomyRequestForm robot_form("bot");
		
		std::cout << robot_form << std::endl;
		alban.signForm(robot_form);
		alban.executeForm(robot_form);
		
		// try multiple times to see randomness
		std::cout << "\n--- trying robotomy again" << std::endl;
		alban.executeForm(robot_form);
	} 
	catch (std::exception& e) 
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n\n------ testing presidential form" << std::endl;
	try 
	{
		Bureaucrat president("Donald Trump", 1);
		PresidentialPardonForm pardon_form("Elon Musk");
		
		std::cout << pardon_form << std::endl;
		president.signForm(pardon_form);
		president.executeForm(pardon_form);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n\n------ testing form not signed exceptio" << std::endl;
	try
	{
		Bureaucrat boss("CEO", 1);
		ShrubberyCreationForm unsigned_form("test");
		// try to execute without signing
		boss.executeForm(unsigned_form);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n\n------ testing grade too low for execution" << std::endl;
	try
	{
		Bureaucrat noob("Newbie", 150);
		Bureaucrat signer("Signer", 20);
		PresidentialPardonForm pardon_form("pardon_test");
		
		// sign with someone who can
		signer.signForm(pardon_form);
		
		// try to execute with someone who cant
		noob.executeForm(pardon_form);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}