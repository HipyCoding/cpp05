/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:51:58 by candrese          #+#    #+#             */
/*   Updated: 2025/06/26 22:49:25 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() 
{
	std::cout << "----- valid bureaucrats -----" << std::endl;
	try 
	{
		Bureaucrat chris("Chris", 75);
		std::cout << chris << std::endl;
		
		Bureaucrat alban("Alban", 1);
		std::cout << alban << std::endl;
	} 
	catch (std::exception& exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}

	std::cout << "----- invalid bureaucrats -----" << std::endl;
	try
	{
		Bureaucrat invalid("Invalid", 0);
	}
	catch (std::exception& exception)
	{
		std::cout << "exception: " << exception.what() << std::endl;
	}
	try
	{
		Bureaucrat invalid("Invalid", 151);
	} catch (std::exception& exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}

	std::cout << "----- grade tests -----" << std::endl;
	try
	{
		Bureaucrat martin("Martin", 75);
		std::cout << "Initial: " << martin << std::endl;
		martin.incrementGrade();
		std::cout << "After increment: " << martin << std::endl;
		martin.decrementGrade();
		std::cout << "After decrement: " << martin << std::endl;
	}
	catch (std::exception& exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}
	
	std::cout << "----- test exception -----" << std::endl;
	try
	{
		Bureaucrat highest("Highest", 1);
		highest.incrementGrade();
	}
	catch (std::exception& exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}
	try
	{
		Bureaucrat lowest("Lowest", 150);
		lowest.decrementGrade();
	}
	catch (std::exception& exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}
	return 0;
}
