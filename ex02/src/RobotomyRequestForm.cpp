#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <bits/stdc++.h>
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void):
AForm("Robotomy Request Form", 145, 45),
target_("default_target") {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& toCopy):
AForm(toCopy.getName(), toCopy.getRequiredSigning(), toCopy.getRequiredExecute()),
target_(toCopy.target_) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& toCopy)
{
	this->target_ = toCopy.target_;
	return (*this);
}


void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	this->AForm::execute(executor);
	std::cout << "BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR *drilling noises*" << std::endl;
	int r = std::rand();
	std::cout << r << std::endl;
	if (r % 2)
	{
		std::cout << this->target_ << " has been successfully robotomized." << std::endl;
	}
	else
	{
		std::cout << "Robotomy on " << this->target_ << " failed." << std::endl;
	}
}
