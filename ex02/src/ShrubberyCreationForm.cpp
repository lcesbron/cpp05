#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("Shrubbery creation form", 145, 137)
{
	this->target_ = "./default_file";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& toCopy): AForm(toCopy::AForm);
{
	this->target_ = toCopy.target_;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery creation form", 145, 137)
{
	this->target_ = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& toCopy)
{
	this->target_ = toCopy.target_;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	std::ofstream	file;

	this->checkExecutable(executor.getGrade());
	file.open(this->target_.c_str());
	if (!file.is_open())
	{
		std::cout << "Can't create file" << std::endl;
		return ;
	}
	file << TREE;
}
