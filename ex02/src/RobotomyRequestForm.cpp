#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):
AForm("Robotomy Request Form", 145, 45),
target_("default_target") {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& toCopy);
RobotomyRequestForm::~RobotomyRequestForm(void);
RobotomyRequestForm&	operator=(RobotomyRequestForm const& toCopy);
