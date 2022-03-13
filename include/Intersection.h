#pragma once
#include "Action.h"

class Intersection : public Action
{
public:
	Intersection() = default;
	void Inter(int command1, int command2, std::vector<std::string>& m_commands, std::vector<int>& m_num_of_params);
};