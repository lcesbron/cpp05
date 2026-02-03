#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "=== Test ShrubberyCreationForm ===" << std::endl;
	{
		ShrubberyCreationForm	shrub("home");
		Bureaucrat				bob("Bob", 130);
		Bureaucrat				intern("Intern", 150);

		std::cout << shrub << std::endl;

		// exec sans signature -> fail
		std::cout << "-- execute sans signature --" << std::endl;
		bob.executeForm(shrub);

		// sign avec grade trop bas -> fail
		std::cout << "-- sign avec grade trop bas --" << std::endl;
		intern.signForm(shrub);

		// sign OK
		std::cout << "-- sign OK --" << std::endl;
		bob.signForm(shrub);

		// exec avec grade trop bas -> fail
		std::cout << "-- execute avec grade trop bas --" << std::endl;
		intern.executeForm(shrub);

		// exec OK
		std::cout << "-- execute OK --" << std::endl;
		bob.executeForm(shrub);
	}

	std::cout << std::endl << "=== Test RobotomyRequestForm ===" << std::endl;
	{
		RobotomyRequestForm	robo("Bender");
		Bureaucrat			boss("Boss", 1);
		Bureaucrat			low("Lowbie", 150);

		std::cout << robo << std::endl;

		// exec sans signature -> fail
		std::cout << "-- execute sans signature --" << std::endl;
		boss.executeForm(robo);

		// sign avec grade trop bas -> fail
		std::cout << "-- sign avec grade trop bas --" << std::endl;
		low.signForm(robo);

		// sign OK
		std::cout << "-- sign OK --" << std::endl;
		boss.signForm(robo);

		// exec avec grade trop bas -> fail
		std::cout << "-- execute avec grade trop bas (grade 150, requis 45) --" << std::endl;
		low.executeForm(robo);

		// exec OK (plusieurs fois pour tester le 50% robotomy)
		std::cout << "-- execute OK (x5) --" << std::endl;
		for (int i = 0; i < 5; i++)
			boss.executeForm(robo);
	}

	std::cout << std::endl << "=== Test PresidentialPardonForm ===" << std::endl;
	{
		PresidentialPardonForm	pardon("Arthur Dent");
		Bureaucrat				president("President", 1);
		Bureaucrat				mid("Mid", 30);
		Bureaucrat				low("Lowbie", 150);

		std::cout << pardon << std::endl;

		// exec sans signature -> fail
		std::cout << "-- execute sans signature --" << std::endl;
		president.executeForm(pardon);

		// sign avec grade trop bas -> fail
		std::cout << "-- sign avec grade trop bas (grade 30, requis 25) --" << std::endl;
		mid.signForm(pardon);

		// sign OK
		std::cout << "-- sign OK --" << std::endl;
		president.signForm(pardon);

		// exec avec grade trop bas -> fail
		std::cout << "-- execute avec grade trop bas (grade 30, requis 5) --" << std::endl;
		mid.executeForm(pardon);

		// exec OK
		std::cout << "-- execute OK --" << std::endl;
		president.executeForm(pardon);
	}

	return (0);
}
