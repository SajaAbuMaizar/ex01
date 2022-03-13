#pragma once
#include "Action.h"

class Difference : public Action
{
public:
	Difference() = default;
	void Diff(int command1, int command2, std::vector<std::string>& m_commands, std::vector<int>& m_num_of_params);
};