#pragma once
#include "Action.h"

class Composite : public Action
{
public:
	Composite() = default;
	void Comp(int command1, int command2, std::vector<std::string>& m_commands, std::vector<int>& m_num_of_params);
};