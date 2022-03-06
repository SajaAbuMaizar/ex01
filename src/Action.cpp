#include "Action.h"

Action::Action()
{
	m_commands.push_back("(AUB)");
	m_commands.push_back("(A^B)");
	m_commands.push_back("(A-B)");
	for (int i = 0; i < m_commands.size(); i++) //number of sets that we need for input
		m_num_of_params.push_back(2);
}

void Action::Uni(int command1, int command2)
{
	std::string new_command = "(" + m_commands[command1] + "U" + m_commands[command2] + ")";
	m_commands.push_back(new_command);
	m_num_of_params.push_back(m_num_of_params[command1] + m_num_of_params[command2]);
}

void Action::Inter(int command1, int command2)
{
	std::string new_command = "(" + m_commands[command1] + "^" + m_commands[command2] + ")";
	m_commands.push_back(new_command);
	m_num_of_params.push_back(m_num_of_params[command1] + m_num_of_params[command2]);
}

void Action::Diff(int command1, int command2)
{
	std::string new_command = "(" + m_commands[command1] + "-" + m_commands[command2] + ")";
	m_commands.push_back(new_command);
	m_num_of_params.push_back(m_num_of_params[command1] + m_num_of_params[command2]);
}

void Action::Prod(int command1, int command2)
{
	std::string new_command = "(" + m_commands[command1] + "*" + m_commands[command2] + ")";
	m_commands.push_back(new_command);
	m_num_of_params.push_back(m_num_of_params[command1] + m_num_of_params[command2]);
}

void Action::Comp(int command1, int command2)
{
	std::string new_command = "(" + m_commands[command1] + "->" + m_commands[command2] + ")";
	m_commands.push_back(new_command);
	m_num_of_params.push_back(m_num_of_params[command1] + m_num_of_params[command2] - 1);
}

Set Action::handleEvaluation(const int command)
{
	Set result = calculateResult(m_commands[command]);
	return result;
}

Set Action::calculateResult(std::string command)
{
	int leftPar = 0;
	int rightPar = 0;
	for (int i = 0; i < command.size(); i++)
	{
		if (command[i] == '(')
			leftPar++;
		if (command[i] == ')')
			rightPar++;
		if (command[i] == 'U' || command[i] == '^' || command[i] == '-') // add * and ->
		{
			if (leftPar - 1 == 0 && rightPar == 0) //stop condition
			{
				if (command[i] == 'U')
				{
					Set temp_res = Union(*m_input[0], *m_input[1]);
					m_input.erase(m_input.begin());
					m_input.erase(m_input.begin());
					return temp_res;
				}
				else if (command[i] == '^')
				{
					Set temp_res = Intersection(*m_input[0], *m_input[1]);
					m_input.erase(m_input.begin());
					m_input.erase(m_input.begin());
					return temp_res;
				}
				else if (command[i] == '-')
				{
					Set temp_res = Difference(*m_input[0], *m_input[1]);
					m_input.erase(m_input.begin());
					m_input.erase(m_input.begin());
					return temp_res;
				}
			}

			else if (leftPar - 1 == rightPar) // this means that we reached the central action
			{
				Set left_Set = calculateResult(split_string(command, 1, i - 1));
				Set right_Set = calculateResult(split_string(command, i + 1, command.size() - 1));
				if (command[i] == 'U')
				{
					Set temp_res = Union(left_Set, right_Set);
					return temp_res;
				}
				else if (command[i] == '^')
				{
					Set temp_res = Intersection(left_Set, right_Set);
					return temp_res;
				}
				else if (command[i] == '-')
				{
					Set temp_res = Difference(left_Set, right_Set);
					return temp_res;
				}
			}
		}
	}
	std::vector<int> t(10, 20);
	Set s(t);
	return s;
}

std::string Action::split_string(std::string str, int beg, int end)
{
	std::string result = "";
	for (int i = beg; i <= end; i++)
		result.push_back(str[i]);
	return result;
}


Set Action::Union(const Set& s1, const Set& s2)
{
	std::vector<int> result;
	std::ranges::set_union(s1.getVector(), s2.getVector(), std::back_inserter(result));
	Set set_result(result);
	return set_result;
}

Set Action::Intersection(const Set& s1, const Set& s2)
{
	std::vector<int> result;
	std::ranges::set_intersection(s1.getVector(), s2.getVector(), std::back_inserter(result));
	Set set_result(result);
	return set_result;
}

Set Action::Difference(const Set& s1, const Set& s2)
{
	std::vector<int> result;
	std::ranges::set_difference(s1.getVector(), s2.getVector(), std::back_inserter(result));
	Set set_result(result);
	return set_result;
}

std::vector<std::string> Action::getCommands() const
{
	return m_commands;
}

std::vector<int> Action::getNumOfParameters() const
{
	return m_num_of_params;
}

void Action::addSet(std::vector<int> temp_members)
{
	m_input.emplace_back(std::make_unique<Set>(temp_members));
}