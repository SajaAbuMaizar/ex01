#pragma once
#include "Action.h"

class Production : public Action
{
public:
	Production() = default;
	void Prod(int command1, int command2, std::vector<std::string>& m_commands, std::vector<int>& m_num_of_params);
};