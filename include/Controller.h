#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include <iterator>
#include "Set.h"


class Controller
{
public:
	Controller();
	void run();
	Set Union(const Set& s1, const Set& s2);
	Set Intersection(const Set& s1, const Set& s2);
	Set Difference(const Set& s1, const Set& s2);
	void handleEvaluation();

private:
	std::vector<std::string> m_commands;
	std::vector<std::unique_ptr<Set>> m_input;
	Set calculateResult(std::string command);

};