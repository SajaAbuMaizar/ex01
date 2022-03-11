#include "Set.h"

Set::Set(std::vector<int> v)
{
	std::ranges::sort(v.begin(),v.end());
	auto last = std::ranges::unique(v);
	v.erase(last.begin(),v.end());
	m_vector.assign(v.begin(),v.end());
}

int Set::operator[](int index) const
{
	return m_vector[index];
}

size_t Set::getSize() const
{
	return m_vector.size();
}

std::vector<int> Set::getVector() const
{
	return m_vector;
}


std::ostream& operator<<(std::ostream& os, const Set& set)
{
	os << "{ ";
	for (size_t i = 0; i < set.getSize(); i++)
	{
		os << set[i] ;
		(i + 1 < set.getSize()) ? os << ", " : os << "";
	}
	os << " }";

	return os;
}