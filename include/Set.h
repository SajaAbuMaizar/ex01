#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

class Set {
public:
	Set(std::vector<int> v);
	int operator[](int index) const;
	size_t getSize() const;
	std::vector<int> getVector() const;


private:
	std::vector<int> m_vector;

};

std::ostream& operator<<(std::ostream& os, const Set& set);