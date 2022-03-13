#include "Controller.h"
#include <string>
#include <fstream>

Controller::Controller()
{

}

void Controller::run()
{
	std::string action;
	int command, command1, command2;
	
	while (true)
	{
		std::cout << "List of available set operations:\n";

		for (int i = 0 ;i < m_operator.getCommands().size() ; i++)
			std::cout << i << ". " << m_operator.getCommands()[i] << std::endl;

		std::cout << "Enter command ('help' for the list of available commands): ";
		std::cin >> action;
		//do sth with the action
		if (action == "exit")
		{
			std::cout << "GoodBye!\n";
			exit(0);
		}
		else if (action == "help")
		{
			std::ifstream help("Help.txt");
			if (help.is_open())
				std::cout << help.rdbuf();

		}
		else if (action == "eval") 
		{
			std::cin >> command;
			readData(command);
			std::cout << m_operator.handleEvaluation(command);
			std::cout << std::endl;
		}
		else if (action == "del")
		{
			std::cin >> command;
			std::vector<std::string> updated_commands = m_operator.getCommands();
			std::vector<int> updated_num = m_operator.getNumOfParameters();
			m_operator.eraseCommand(command, updated_commands, updated_num);
			m_operator.setCommands(updated_commands);
			m_operator.setNumOfParameters(updated_num);
		}
		else
		{
			std::cin >> command1;
			std::cin >> command2;
			std::vector<std::string> updated_commands = m_operator.getCommands();
			std::vector<int> updated_num = m_operator.getNumOfParameters();
			if (action == "uni")
				m_uni.Uni(command1, command2, updated_commands, updated_num);
			else if (action == "inter")
				m_inter.Inter(command1, command2, updated_commands, updated_num);
			else if (action == "diff")
				m_diff.Diff(command1, command2, updated_commands, updated_num);
			else if (action == "prod")
				m_prod.Prod(command1, command2, updated_commands, updated_num);
			else if (action == "comp")
				m_comp.Comp(command1, command2, updated_commands, updated_num);
			m_operator.setCommands(updated_commands);
			m_operator.setNumOfParameters(updated_num);
		}
	}
}

void Controller::readData(const int command)
{
	//take in input
	for (int sets = 0; sets < m_operator.getNumOfParameters()[command]; sets++)//sets=input for command
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
		m_operator.addSet(temp_members);
	}
}