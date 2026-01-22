#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

// ============== BUREAUCRAT TESTS ==============

static void	testBureaucratConstructors(void)
{
	std::cout << "=== Test Bureaucrat Constructors ===" << std::endl;

	// Default constructor
	Bureaucrat	defaultBureaucrat;
	std::cout << "Default: " << defaultBureaucrat << std::endl;

	// Parametric constructor
	Bureaucrat	bob("Bob", 50);
	std::cout << "Parametric: " << bob << std::endl;

	// Copy constructor
	Bureaucrat	bobCopy(bob);
	std::cout << "Copy: " << bobCopy << std::endl;

	// Assignment operator
	Bureaucrat	assigned;
	assigned = bob;
	std::cout << "Assigned: " << assigned << std::endl;

	std::cout << std::endl;
}

static void	testBureaucratIncrementGrade(void)
{
	std::cout << "=== Test Bureaucrat Increment Grade ===" << std::endl;

	Bureaucrat	bob("Bob", 29);
	std::cout << "Initial: " << bob << std::endl;

	try
	{
		bob.incrementGrade(10);
		std::cout << "After increment(10): " << bob << std::endl;
		bob.incrementGrade(18);
		std::cout << "After increment(18): " << bob << std::endl;
		std::cout << "Trying to increment beyond max grade..." << std::endl;
		bob.incrementGrade(1);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void	testBureaucratDecrementGrade(void)
{
	std::cout << "=== Test Bureaucrat Decrement Grade ===" << std::endl;

	Bureaucrat	bob("Bob", 140);
	std::cout << "Initial: " << bob << std::endl;

	try
	{
		bob.decrementGrade(5);
		std::cout << "After decrement(5): " << bob << std::endl;
		bob.decrementGrade(5);
		std::cout << "After decrement(5): " << bob << std::endl;
		std::cout << "Trying to decrement beyond lowest grade..." << std::endl;
		bob.decrementGrade(1);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

// ============== FORM TESTS ==============

static void	testFormConstructors(void)
{
	std::cout << "=== Test Form Constructors ===" << std::endl;

	// Default constructor
	Form	defaultForm;
	std::cout << "Default Form:" << std::endl;
	std::cout << defaultForm << std::endl;

	// Copy constructor
	Form	formCopy(defaultForm);
	std::cout << "Copy Form:" << std::endl;
	std::cout << formCopy << std::endl;

	// Assignment operator
	Form	assigned;
	assigned = defaultForm;
	std::cout << "Assigned Form:" << std::endl;
	std::cout << assigned << std::endl;
}

static void	testFormSigningSuccess(void)
{
	std::cout << "=== Test Form Signing Success ===" << std::endl;

	// Default form requires grade 1 to sign
	Form		taxForm;
	Bureaucrat	director("Director", 1); // Grade 1 can sign

	std::cout << "Before signing:" << std::endl;
	std::cout << taxForm << std::endl;
	std::cout << director << std::endl;

	taxForm.signForm(director);

	std::cout << "After signing:" << std::endl;
	std::cout << taxForm << std::endl;
}

static void	testFormSigningFailure(void)
{
	std::cout << "=== Test Form Signing Failure ===" << std::endl;

	// Default form requires grade 1 to sign
	Form		taxForm;
	Bureaucrat	intern("Intern", 150); // Grade too low

	std::cout << "Before attempt:" << std::endl;
	std::cout << taxForm << std::endl;
	std::cout << intern << std::endl;

	// Using signForm (handles exception internally and prints message)
	taxForm.signForm(intern);

	std::cout << "After failed attempt:" << std::endl;
	std::cout << taxForm << std::endl;
}

static void	testFormBeSignedException(void)
{
	std::cout << "=== Test Form beSigned Exception ===" << std::endl;

	Form		taxForm;
	Bureaucrat	intern("Intern", 150);

	try
	{
		std::cout << "Trying beSigned with low grade bureaucrat..." << std::endl;
		taxForm.beSigned(intern);
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << "Form::GradeTooLowException caught: " << e.what() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Generic exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void	testFormPrintOperator(void)
{
	std::cout << "=== Test Form Print Operator ===" << std::endl;

	Form	form;
	std::cout << form << std::endl;
}

// ============== COMBINED TESTS ==============

static void	testBureaucratPromotionAndSigning(void)
{
	std::cout << "=== Test Bureaucrat Promotion Then Signing ===" << std::endl;

	Form		importantForm;
	Bureaucrat	employee("Employee", 5);

	std::cout << "Initial state:" << std::endl;
	std::cout << employee << std::endl;
	std::cout << importantForm << std::endl;

	// Try to sign with insufficient grade
	std::cout << "Attempt 1 (grade 5):" << std::endl;
	importantForm.signForm(employee);

	// Promote the employee
	std::cout << "Promoting employee..." << std::endl;
	employee.incrementGrade(4); // Now grade 1
	std::cout << employee << std::endl;

	// Try again
	std::cout << "Attempt 2 (grade 1):" << std::endl;
	importantForm.signForm(employee);

	std::cout << "Final state:" << std::endl;
	std::cout << importantForm << std::endl;
}

int	main(void)
{
	std::cout << "========================================" << std::endl;
	std::cout << "       CPP05 EX01 - TEST SUITE         " << std::endl;
	std::cout << "========================================" << std::endl << std::endl;

	// Bureaucrat tests
	testBureaucratConstructors();
	testBureaucratIncrementGrade();
	testBureaucratDecrementGrade();

	// Form tests
	testFormConstructors();
	testFormSigningSuccess();
	testFormSigningFailure();
	testFormBeSignedException();
	testFormPrintOperator();

	// Combined tests
	testBureaucratPromotionAndSigning();

	std::cout << "========================================" << std::endl;
	std::cout << "          ALL TESTS COMPLETED          " << std::endl;
	std::cout << "========================================" << std::endl;

	return (0);
}
