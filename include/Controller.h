#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include <iterator>
#include "Set.h"

enum Actions {
	eval,
	uni,
	inter,
	diff,
	prod,
	comp
};

class Controller
{
public:
	Controller();
	void run();
	Set Union(const Set& s1, const Set& s2);
	Set Intersection(const Set& s1, const Set& s2);
	Set Difference(const Set& s1, const Set& s2);
	Set handleEvaluation();
	void Uni(int command1, int command2);
	void Inter(int command1, int command2);
	void Diff(int command1, int command2);
	void Prod(int command1, int command2);
	void Comp(int command1, int command2);

private:
	std::vector<std::string> m_commands;
	std::vector<int> m_num_of_params;
	std::vector<std::unique_ptr<Set>> m_input;
	Set calculateResult(std::string command);
	std::string split_string(std::string str, int beg, int end);

};