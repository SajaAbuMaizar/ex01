#pragma once
#include "Set.h"

class Action
{
public:
	Action();
	Set handleEvaluation(const int command);
	void Uni(int command1, int command2);
	void Inter(int command1, int command2);
	void Diff(int command1, int command2);
	void Prod(int command1, int command2);
	void Comp(int command1, int command2);
	Set Union(const Set& s1, const Set& s2);
	Set Intersection(const Set& s1, const Set& s2);
	Set Difference(const Set& s1, const Set& s2);
	std::vector<std::string> getCommands() const;
	std::vector<int> getNumOfParameters() const;
	void addSet(std::vector<int> temp_members);

private:
	std::vector<std::string> m_commands;
	std::vector<int> m_num_of_params;
	std::vector<std::unique_ptr<Set>> m_input;
	//----- helper functions -----
	Set calculateResult(std::string command);
	std::string split_string(std::string str, int beg, int end);
	
};