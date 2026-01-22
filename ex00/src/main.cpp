#include "Bureaucrat.hpp"
#include <exception>

static void	testIncrementGrade(void)
{
	Bureaucrat	bob("bob", 29);

	try
	{
		bob.incrementGrade(10);
		std::cout << bob.getGrade() << std::endl;
		bob.incrementGrade(19);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

static void	testDecrementGrade(void)
{
	Bureaucrat	bob("bob", 30);

	try
	{
		bob.decrementGrade(10);
		std::cout << bob.getGrade() << std::endl;
		bob.decrementGrade(111);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

static void	testPrintOperator(void)
{
	Bureaucrat	bob("bob", 49);

	std::cout << bob << std::endl;
}

int	main(void)
{
	testIncrementGrade();
	testDecrementGrade();
	testPrintOperator();
}
