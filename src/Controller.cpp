#include "Controller.h"

Controller::Controller()
{
	m_commands.push_back("(AUB)");
	m_commands.push_back("(A^B)");
	m_commands.push_back("(A-B)");
	for (int i = 0; i < m_commands.size(); i++) //number of sets that we need for input
		m_num_of_params.push_back(2);
}


void Controller::run()
{
	std::string action;
	
	while (true)
	{
		std::cout << "List of available set operations:\n";

		for (int i = 0 ;i < m_commands.size() ; i++)
		{
			std::cout << i << ". " << m_commands[i] << std::endl;
		}

		std::cout << "Enter command ('help' for the list of available commands): ";
		std::cin >> action;
		//do sth with the action
	}
}

void Controller::handleEvaluation()
{
	int command;
	int num_of_nums;
	std::cin >> command;
	std::string temp = m_commands[command];
	//take in input
	for (int sets = 0; sets < m_num_of_params[command]; sets++ )//sets=input for command
	{
		int num_of_members;
		std::vector<int> temp_members;
		std::cin >> num_of_members;
		for (int members = 0; members < num_of_members; members++)
		{
			int num;
			std::cin >> num;
			temp_members.push_back(num);
		}
		Set temp_set(temp_members);
		m_input.emplace_back(std::make_unique<Set>(temp_members));
	}
	Set result = calculateResult(temp);
	std::cout << result;
}

Set Controller::calculateResult(std::string command)
{
	int leftPar = 0;
	int rightPar = 0;
	for (int i = 0 ; i < command.size(); i++)
	{
		if (command[i] == '(')
			leftPar++;
		if (command[i] == ')')
			rightPar++;
		if (command[i] == 'U' || command[i] == '^' || command[i] == '-') // add * and ->
		{
			if (leftPar -1 == 0 && rightPar == 0) //stop condition
			{
				if (command[i] == 'U')
				{
					Set temp_res = Union(*m_input[0], *m_input[1]);
					m_input.erase(m_input.begin(),m_input.begin()+1);
					return temp_res;
				}
				else if (command[i] == '^')
				{
					Set temp_res = Intersection(*m_input[0], *m_input[1]);
					m_input.erase(m_input.begin(), m_input.begin() + 1);
					return temp_res;
				}
				else if (command[i] == '-')
				{
					Set temp_res = Difference(*m_input[0], *m_input[1]);
					m_input.erase(m_input.begin(), m_input.begin() + 1);
					return temp_res;
				}
			}
			else if (leftPar - 1 == rightPar) // this means that we reached the central action
			{
				Set left_Set = calculateResult(split_string(command,1,command[i]-1));
				Set right_Set = calculateResult(split_string(command,command[i] + 1, command.size() - 1));
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
}

std::string Controller::split_string(std::string str, int beg, int end)
{
	std::string result = "";
	for (int i = beg ; i <= end ; i++)
		result.push_back(str[i]);
	return result;
}


Set Controller::Union(const Set& s1, const Set& s2)
{
	std::vector<int> result;
	std::ranges::set_union(s1.getVector(),s2.getVector(),std::back_inserter(result));
	Set set_result(result);
	return set_result;
}

Set Controller::Intersection(const Set& s1, const Set& s2)
{
	std::vector<int> result;
	std::ranges::set_intersection(s1.getVector(), s2.getVector(), std::back_inserter(result));
	Set set_result(result);
	return set_result;
}

Set Controller::Difference(const Set& s1, const Set& s2)
{
	std::vector<int> result;
	std::ranges::set_difference(s1.getVector(), s2.getVector(), std::back_inserter(result));
	Set set_result(result);
	return set_result;
}

