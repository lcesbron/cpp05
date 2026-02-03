#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
	Intern	someRandomIntern;
	AForm*	form;

	std::cout << "=== Test 1: shrubbery creation ===" << std::endl;
	form = someRandomIntern.makeForm("shrubbery creation", "garden");
	if (form)
	{
		std::cout << *form << std::endl;
		delete form;
	}
	else
		std::cout << "Form creation failed" << std::endl;

	std::cout << std::endl << "=== Test 2: robotomy request ===" << std::endl;
	form = someRandomIntern.makeForm("robotomy request", "Bender");
	if (form)
	{
		std::cout << *form << std::endl;
		delete form;
	}
	else
		std::cout << "Form creation failed" << std::endl;

	std::cout << std::endl << "=== Test 3: presidential pardon ===" << std::endl;
	form = someRandomIntern.makeForm("presidential pardon", "Arthur");
	if (form)
	{
		std::cout << *form << std::endl;
		delete form;
	}
	else
		std::cout << "Form creation failed" << std::endl;

	std::cout << std::endl << "=== Test 4: invalid form name ===" << std::endl;
	form = someRandomIntern.makeForm("invalid form", "nobody");
	if (form)
	{
		std::cout << *form << std::endl;
		delete form;
	}
	else
		std::cout << "Form creation failed (expected)" << std::endl;

	std::cout << std::endl << "=== Test 5: sign and execute created forms ===" << std::endl;
	Bureaucrat	boss("Boss", 1);
	form = someRandomIntern.makeForm("presidential pardon", "Ford");
	if (form)
	{
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	std::cout << std::endl;
	form = someRandomIntern.makeForm("robotomy request", "Marvin");
	if (form)
	{
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	std::cout << std::endl;
	form = someRandomIntern.makeForm("shrubbery creation", "home");
	if (form)
	{
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	std::cout << std::endl << "=== Test 6: execute without signing ===" << std::endl;
	form = someRandomIntern.makeForm("presidential pardon", "Trillian");
	if (form)
	{
		try
		{
			boss.executeForm(*form);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		delete form;
	}

	return (0);
}
