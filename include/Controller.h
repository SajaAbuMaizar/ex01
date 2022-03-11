#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include <iterator>
#include "Set.h"
#include "Action.h"


class Controller
{
public:
	Controller() = default;
	void run();

private:
	Action m_action;
	//------ helper function(s) ------
	void readData(const int command);

};