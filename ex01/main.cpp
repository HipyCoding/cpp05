/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:51:58 by candrese          #+#    #+#             */
/*   Updated: 2025/07/07 23:00:44 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
	std::cout << "\n----- form creation should work" << std::endl;
	try {
		Form tax_form("Tax Form", 50, 25);
		std::cout << tax_form << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n\n----- form creation should not work" << std::endl;
	try {
		Form invalid_form("Invalid", 50, 0);  // Too high
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n\n----- signing should work" << std::endl;
	try {
		Bureaucrat martin("Martin", 30);
		Form contract("Contract", 50, 25);
		
		std::cout << "Before: " << contract << std::endl;
		martin.signForm(contract);
		std::cout << "After: " << contract << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n\n----- signing should not work" << std::endl;
	try {
		Bureaucrat alban("Alban", 100);
		Form secret_form("Secret", 25, 10);
		
		alban.signForm(secret_form);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
