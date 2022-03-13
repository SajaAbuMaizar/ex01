#pragma once
#include "Action.h"

class Union : public Action
{
public:
	Union() = default;
	void Uni(int command1, int command2, std::vector<std::string>& m_commands, std::vector<int>& m_num_of_params);
};