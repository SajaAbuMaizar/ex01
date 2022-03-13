#include "Operator.h"

//the operator class constructor
Operator::Operator()
{
	m_commands.push_back("(AUB)"); //creates the initial list of commands
	m_commands.push_back("(A^B)");
	m_commands.push_back("(A-B)");
	for (int i = 0; i < m_commands.size(); i++) //number of sets that we need for input
		m_num_of_params.push_back(2);
}

//this function handles the "evaluate" command
Set Operator::handleEvaluation(const int command)
{
	Set result = calculateResult(m_commands[command]);
	return result;
}

//this function claculates the evaluation and returns the result
Set Operator::calculateResult(std::string command)
{
	int leftPar = 0; //the count of the left paranthasis
	int rightPar = 0; //the count of the right paranthasis
	for (int i = 0; i < command.size(); i++)
	{
		if (command[i] == '(') leftPar++;
		if (command[i] == ')') rightPar++;
		if (command[i] == 'U' || command[i] == '^' || command[i] == '-' || command[i] == '*') 
			{
			if (leftPar - 1 == 0 && rightPar == 0) //stop condition
			{
				if (command[i] == 'U') { //if the algorithms reads a union
					Set temp_res = Union(*m_input[0], *m_input[1]);
					m_input.erase(m_input.begin()); m_input.erase(m_input.begin()); //erase the used input
					return temp_res;
				}
				else if (command[i] == '^') { //if the algorithms reads an intersection
					Set temp_res = Intersection(*m_input[0], *m_input[1]);
					m_input.erase(m_input.begin()); m_input.erase(m_input.begin()); //erase the used input
					return temp_res;
				}
				else if (command[i] == '-') { //if the algorithms reads a difference
					Set temp_res = Difference(*m_input[0], *m_input[1]);
					m_input.erase(m_input.begin()); m_input.erase(m_input.begin()); //erase the used input
					return temp_res;
				}
				else if (command[i] == '*') { //if the algorithms reads a production
					Set temp_res = Production(*m_input[0], *m_input[1]);
					m_input.erase(m_input.begin()); m_input.erase(m_input.begin()); //erase the used input
					return temp_res;
				}
			}
			else if (leftPar - 1 == rightPar) { // this means that we reached the central action
				if (command[i] == '-' && command[i + 1] == '>') { //if the algorithm reads a composition
					m_input.insert(m_input.begin(), std::make_unique<Set>(calculateResult(split_string(command, 1, i - 1))));
					Set right_Set = calculateResult(split_string(command, i + 1, command.size() - 1));
					return right_Set;
				}
				else {
					Set left_Set = calculateResult(split_string(command, 1, i - 1));
					Set right_Set = calculateResult(split_string(command, i + 1, command.size() - 1));
					if (command[i] == 'U') {
						Set temp_res = Union(left_Set, right_Set);
						return temp_res;
					}
					else if (command[i] == '^') {
						Set temp_res = Intersection(left_Set, right_Set);
						return temp_res;
					}
					else if (command[i] == '-') {
						Set temp_res = Difference(left_Set, right_Set);
						return temp_res;
					}
					else if (command[i] == '*') {
						Set temp_res = Production(left_Set, right_Set);
						return temp_res;
					}
				} }
			}
	}
/*	std::vector<int> t(10, 20);
	Set s(t);
	return s;*/
}

//this fiunction splits the string of the commands into the wanted slots (beg) and (end)
std::string Operator::split_string(std::string str, int beg, int end)
{
	std::string result = "";
	for (int i = beg; i <= end; i++)
		result.push_back(str[i]);
	return result;
}

//this function does the production of two given sets
Set Operator::Production(const Set& s1, const Set& s2)
{
	std::vector<int> result;
	for (int i = 0; i < s1.getSize() ; i++)
		for (int j = 0; j < s2.getSize(); j++)
			result.push_back(s1[i] * s2[j]);
	Set set_result(result);
	return set_result;
}

/*
//this function does the compostion of two given sets
Set Operator::Composite(const Set& s1, const Set& s2)
{
	std::vector<int> result;
	Set set_result(result);
	return set_result;
}*/

//this function does the union of two given sets
Set Operator::Union(const Set& s1, const Set& s2)
{
	std::vector<int> result;
	std::ranges::set_union(s1.getVector(), s2.getVector(), std::back_inserter(result));
	Set set_result(result);
	return set_result;
}

//this function does the intersection of two given sets
Set Operator::Intersection(const Set& s1, const Set& s2)
{
	std::vector<int> result;
	std::ranges::set_intersection(s1.getVector(), s2.getVector(), std::back_inserter(result));
	Set set_result(result);
	return set_result;
}

//this function does the difference of two given sets
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

//this function converts a vector into a set then adds the set to the list of input we took from the user
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

//this function erases the fiven command from the list of available commands
void Operator::eraseCommand(int command, std::vector<std::string>& commands, std::vector<int>& params_nums_vec)
{
	for (int i = 0; i < commands.size(); i++)
		if (i == command) {
			commands.erase(commands.begin()+i);
			params_nums_vec.erase(params_nums_vec.begin()+i);
		}
}