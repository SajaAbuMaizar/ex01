#include "Operator.h"

Operator::Operator()
{
	m_commands.push_back("(AUB)");
	m_commands.push_back("(A^B)");
	m_commands.push_back("(A-B)");
	for (int i = 0; i < m_commands.size(); i++) //number of sets that we need for input
		m_num_of_params.push_back(2);
}

Set Operator::handleEvaluation(const int command)
{
	Set result = calculateResult(m_commands[command]);
	return result;
}

Set Operator::calculateResult(std::string command)
{
	int leftPar = 0;
	int rightPar = 0;
	for (int i = 0; i < command.size(); i++)
	{
		if (command[i] == '(')
			leftPar++;
		if (command[i] == ')')
			rightPar++;
		if (command[i] == 'U' || command[i] == '^' || command[i] == '-'
			|| command[i] == '*')
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
				else if (command[i] == '*')
				{
					Set temp_res = Production(*m_input[0], *m_input[1]);
					m_input.erase(m_input.begin());
					m_input.erase(m_input.begin());
					return temp_res;
				}
			}

			else if (leftPar - 1 == rightPar) // this means that we reached the central action
			{
				if (command[i] == '-' && command[i + 1] == '>')
				{
					m_input.insert(m_input.begin(), std::make_unique<Set>(calculateResult(split_string(command, 1, i - 1))));
					Set right_Set = calculateResult(split_string(command, i + 1, command.size() - 1));
					return right_Set;
				}
				else
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
					else if (command[i] == '*')
					{
						Set temp_res = Production(left_Set, right_Set);
						return temp_res;
					}
				}
			}
		}
	}
	std::vector<int> t(10, 20);
	Set s(t);
	return s;
}



std::string Operator::split_string(std::string str, int beg, int end)
{
	std::string result = "";
	for (int i = beg; i <= end; i++)
		result.push_back(str[i]);
	return result;
}

Set Operator::Production(const Set& s1, const Set& s2)
{
	std::vector<int> result;
	for (int i = 0; i < s1.getSize() ; i++)
		for (int j = 0; j < s2.getSize(); j++)
			result.push_back(s1[i] * s2[j]);
	Set set_result(result);
	return set_result;
}

Set Operator::Composite(const Set& s1, const Set& s2)
{
	std::vector<int> result;
	Set set_result(result);
	return set_result;
}


Set Operator::Union(const Set& s1, const Set& s2)
{
	std::vector<int> result;
	std::ranges::set_union(s1.getVector(), s2.getVector(), std::back_inserter(result));
	Set set_result(result);
	return set_result;
}

Set Operator::Intersection(const Set& s1, const Set& s2)
{
	std::vector<int> result;
	std::ranges::set_intersection(s1.getVector(), s2.getVector(), std::back_inserter(result));
	Set set_result(result);
	return set_result;
}

Set Operator::Difference(const Set& s1, const Set& s2)
{
	std::vector<int> result;
	std::ranges::set_difference(s1.getVector(), s2.getVector(), std::back_inserter(result));
	Set set_result(result);
	return set_result;
}

std::vector<std::string> Operator::getCommands() const
{
	return m_commands;
}

std::vector<int> Operator::getNumOfParameters() const
{
	return m_num_of_params;
}

void Operator::addSet(std::vector<int> temp_members)
{
	m_input.emplace_back(std::make_unique<Set>(temp_members));
}

void Operator::setCommands(std::vector<std::string> updated_commands)
{
	m_commands = updated_commands;
}

void Operator::setNumOfParameters(std::vector<int> updated_num)
{
	m_num_of_params = updated_num;
}

void Operator::eraseCommand(int command, std::vector<std::string>& commands, std::vector<int>& params_nums_vec)
{
	for (int i = 0; i < commands.size(); i++)
		if (i == command)
		{
			commands.erase(commands.begin()+i);
			params_nums_vec.erase(params_nums_vec.begin()+i);
		}
}