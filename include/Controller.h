#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include <iterator>
#include "Set.h"
#include "Operator.h"
#include "Union.h"
#include "Intersection.h"
#include "Difference.h"
#include "Production.h"
#include "Composite.h"

class Controller
{
public:
	Controller();
	void run();

private:
	Operator m_operator;
	Union m_uni;
	Intersection m_inter;
	Difference m_diff;
	Production m_prod;
	Composite m_comp;
	//------ helper function(s) ------
	void readData(const int command);

};