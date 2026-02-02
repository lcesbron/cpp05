#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>

int	main(void)
{
	RobotomyRequestForm	rqf;
	Bureaucrat				boss("boss", 1);

	rqf.beSigned(boss);
	rqf.execute(boss);
	rqf.execute(boss);
	rqf.execute(boss);
	rqf.execute(boss);
	rqf.execute(boss);
	rqf.execute(boss);
	rqf.execute(boss);
	rqf.execute(boss);
	rqf.execute(boss);
	rqf.execute(boss);
	rqf.execute(boss);
	rqf.execute(boss);
	rqf.execute(boss);
	rqf.execute(boss);
	rqf.execute(boss);
}
