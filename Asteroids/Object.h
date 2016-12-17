#ifndef OBJECT_H
#define OBJECT_H

#include <string>

// Summary:
//
//
class Object
{
private:
	std::string m_id;

public:
	Object(const std::string& id) :
		m_id(id)
	{

	}

	std::string Id() { return m_id; }
};

#endif // OBJECT_H
