#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	~FragTrap();
	FragTrap(const FragTrap &copy);
	FragTrap &operator=(const FragTrap &copy);

	void vaulthunter_dot_exe(std::string const & target);
};
