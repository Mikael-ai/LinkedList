#pragma once

#include<sstream>

template <typename T>
std::string getStringFromValue(const T &value)
{
	std::ostringstream os;
	os << value;

	return os.str();
}

template<typename T>
class LinkedList
{
public:
	struct Node 
	{
		T value;
		struct Node* next = nullptr;
	};

	typedef typename LinkedList<T>::Node Node;

	Node* _first = nullptr;
	Node* _last = nullptr;

	unsigned long long _size;

public:
	
	LinkedList();

	void add(const T &value);
	Node* getFirst();
	bool isEmpty() const;
	
	std::string toString() const;

private:
	friend std::ostream& operator<<(std::ostream& os, LinkedList<T> &list)
	{
		if (list.isEmpty())
			return os << std::string();

		// While there is a next node, 
		// write it's value to the output stream
		os << "[";
		Node* current = list.getFirst();
		while (current)
		{
			os << current->value;
			if (current->next)
				os << ", ";

			current = current->next;
		}
		os << "]";

		return os;
	}
};

template<typename T>
inline LinkedList<T>::LinkedList()
	: _first(nullptr),
	_last(nullptr),
	_size(0)
{
}

template<typename T>
inline void LinkedList<T>::add(const T& value)
{
	// Creating a node
	Node *node = new Node
	{
		value,
		nullptr
	};

	// The first node is the last if the list is empty
	if (isEmpty())
	{
		_last = _first = node;
		return;
	}

	// Last existed node points to the new created node
	// and then new becomes the last
	_last->next = node;
	_last = node;
	// Increasing the size
	++_size;
}

template<typename T>
inline typename LinkedList<T>::Node* LinkedList<T>::getFirst()
{
	return _first;
}

template<typename T>
inline bool LinkedList<T>::isEmpty() const
{
	if (!_first)
		return true;

	return false;
}

template<typename T>
inline std::string LinkedList<T>::toString() const
{
	if (isEmpty())
		return std::string();
	
	// While there is a next node,
	// add it's value to the result string
	std::string result = "[";
	Node *current = _first;
	while (current)
	{
		result += getStringFromValue(current->value);
		if (current->next)
			result += ", ";

		current = current->next;
	}
	result += "]";

	return result;
}