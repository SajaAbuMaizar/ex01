#include "Controller.h"
#include <string>
#include <fstream>

Controller::Controller()
{

}

//this function runs the program, an infinite loop until exiting the program
void Controller::run()
{
	std::string action;
	int command, command1, command2;
	
	while (true) //main loop
	{
		std::cout << "List of available set operations:\n";
        //print out all the available commands
		for (int i = 0 ;i < m_operator.getCommands().size() ; i++)
			std::cout << i << ". " << m_operator.getCommands()[i] << std::endl;
		std::cout << "Enter command ('help' for the list of available commands): ";
		std::cin >> action;
		
		if (action == "exit") {
			std::cout << "GoodBye!\n"; //exit the program
			exit(0);
		}
		else if (action == "help") {
			std::ifstream help("Help.txt"); //print out the help text from a file
			if (help.is_open())
				std::cout << help.rdbuf();
		}
		else if (action == "eval") {
			std::cin >> command;
		/*	if(command > m_operator.getCommands().size()) { //make sure the command is in range of commands
				std::cout << "Operation #" << command << " doesn't exist\n";
				continue;
			}*/
			readData(command);
			std::cout << m_operator.handleEvaluation(command);
			std::cout << std::endl;
		}
		else if (action == "del") { //delete the wanted command from the list
			std::cin >> command;
			std::vector<std::string> updated_commands = m_operator.getCommands();
			std::vector<int> updated_num = m_operator.getNumOfParameters();
			m_operator.eraseCommand(command, updated_commands, updated_num);
			m_operator.setCommands(updated_commands);
			m_operator.setNumOfParameters(updated_num);
		}
		else if(action == "uni" || action == "inter" || action == "diff"
		        || action == "prod" || action == "comp") { //other commands
			std::cin >> command1;
			std::cin >> command2;
			std::vector<std::string> updated_commands = m_operator.getCommands();
			std::vector<int> updated_num = m_operator.getNumOfParameters();
			if (action == "uni") //if the command is union then unite the sets
				m_uni.Uni(command1, command2, updated_commands, updated_num);
			else if (action == "inter")//if the command is intersection then intersect the sets
				m_inter.Inter(command1, command2, updated_commands, updated_num);
			else if (action == "diff")//if the command is difference
				m_diff.Diff(command1, command2, updated_commands, updated_num);
			else if (action == "prod")//if the command is production then mutliply the sets
				m_prod.Prod(command1, command2, updated_commands, updated_num);
			else if (action == "comp")//if the command is compostion
				m_comp.Comp(command1, command2, updated_commands, updated_num);
			m_operator.setCommands(updated_commands);
			m_operator.setNumOfParameters(updated_num);
		}
		else //if thr action wans't from the list
			std::cout << "Command Not Found!\n";
	}
}

//this function reads data from the user (the input)
void Controller::readData(const int command)
{
	//take in input
	for (int sets = 0; sets < m_operator.getNumOfParameters()[command]; sets++) {
		int num_of_members;
		std::vector<int> temp_members;
		std::cin >> num_of_members;
		for (int members = 0; members < num_of_members; members++) {
			int num;
			std::cin >> num;
			temp_members.push_back(num);
		}
		m_operator.addSet(temp_members); //add the created set to the input
	}
}