#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const& toCopy);
		~RobotomyRequestForm(void);
		RobotomyRequestForm&	operator=(RobotomyRequestForm const& toCopy);
};

#endif //ROBOTOMYREQUESTFORM_HPP
