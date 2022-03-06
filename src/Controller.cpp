#include "Controller.h"
#include <string>

void Controller::run()
{
	std::string action;
	
	while (true)
	{
		std::cout << "List of available set operations:\n";

		for (int i = 0 ;i < m_action.getCommands().size() ; i++)
			std::cout << i << ". " << m_action.getCommands()[i] << std::endl;

		std::cout << "Enter command ('help' for the list of available commands): ";
		std::cin >> action;
		//do sth with the action
		if (action == "eval") {
			int command;
			std::cin >> command;
			readData(command);
			std::cout << m_action.handleEvaluation(command);
			std::cout << std::endl;
		}
		else
		{
			int command1, command2;
			std::cin >> command1;
			std::cin >> command2;
			if (action == "uni")
				m_action.Uni(command1, command2);
			else if (action == "inter")
				m_action.Inter(command1, command2);
			else if (action == "diff")
				m_action.Diff(command1, command2);
			else if (action == "prod")
				m_action.Prod(command1, command2);
			else if (action == "comp")
				m_action.Comp(command1, command2);
		}
	}
}

void Controller::readData(const int command)
{
	//take in input
	for (int sets = 0; sets < m_action.getNumOfParameters()[command]; sets++)//sets=input for command
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
		m_action.addSet(temp_members);
	}
}