#include "Controller.h"

Controller::Controller()
{
	m_commands.push_back("(AUB)");
	m_commands.push_back("(A^B)");
	m_commands.push_back("(A-B)");
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
	//take in unput
	cin << num_of_nums;
	for ()
	{

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
		if (command[i] == 'U' || command[i] == '^' || command[i] == '-')
		{
			if (leftPar - 1 == rightPar) // this means that we reached the central action
			{
				std::string = 
			}
		}
	}
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

