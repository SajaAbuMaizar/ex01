#include "Difference.h"

void Difference::Diff(int command1, int command2,
	std::vector<std::string>& m_commands, std::vector<int>& m_num_of_params)
{
	std::string new_command = "(" + m_commands[command1] + "-" + m_commands[command2] + ")";
	m_commands.push_back(new_command);
	m_num_of_params.push_back(m_num_of_params[command1] + m_num_of_params[command2]);
}