#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

enum e_forms
{
	SHRUBBERY = 0,
	ROBOTOMY,
	PRESIDENT,
};

Intern::Intern(void) {}

Intern::Intern(Intern const& toCopy) {(void)toCopy;}

Intern::~Intern(void) {}

Intern&	Intern::operator=(Intern const& toCopy) {(void)toCopy; return (*this);}

AForm*	Intern::makeForm(std::string name, std::string target) const
{
	int			i = 0;
	std::string	tab[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	while (i < 3 && name != tab[i]) {++i;}
	switch (i)
	{
		case SHRUBBERY:
			return (new ShrubberyCreationForm(target));
			break ;
		case ROBOTOMY:
			return (new RobotomyRequestForm(target));
			break ;
		case PRESIDENT:
			return (new PresidentialPardonForm(target));
		default:
			return (NULL);
	}
}
