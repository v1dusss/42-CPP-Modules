#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	bool _guardGateMode;

public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap& other);
	~ScavTrap();

	void guardGate();
	void attack(const std::string& target);
};
