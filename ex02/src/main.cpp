#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>

int	main(void)
{
	ShrubberyCreationForm	scf;
	Bureaucrat				boss("boss", 1);

	scf.beSigned(boss);
	scf.execute(boss);
}
