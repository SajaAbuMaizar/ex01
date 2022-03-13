#pragma once
#include "Set.h"

class Operator
{
public:
	Operator();
	Set handleEvaluation(const int command);
	Set Union(const Set& s1, const Set& s2);
	Set Intersection(const Set& s1, const Set& s2);
	Set Difference(const Set& s1, const Set& s2);
	std::vector<std::string> getCommands() const;
	std::vector<int> getNumOfParameters() const;
	void addSet(std::vector<int> temp_members);
	void setCommands(std::vector<std::string> commands);
	void setNumOfParameters(std::vector<int> updated_num);
	void eraseCommand(int command, std::vector<std::string>& commands, std::vector<int>& params_nums_vec);

private:

protected:
	std::vector<std::string> m_commands;
	std::vector<int> m_num_of_params;
	std::vector<std::unique_ptr<Set>> m_input;
	//----- helper functions -----
	Set calculateResult(std::string command);
	std::string split_string(std::string str, int beg, int end);
	Set Production(const Set& s1, const Set& s2);
	Set Composite(const Set& s1, const Set& s2);

};