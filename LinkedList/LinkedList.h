#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <sstream>

template <typename T>
std::string getStringFromValue(const T& value)
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

	Node* mFirst = nullptr;
	Node* mLast = nullptr;

	unsigned long mSize;

public:

	LinkedList();

	void push_back(const T& value);
	T getFirst() const;
	bool isEmpty() const;

	std::string toString() const;

private:
	friend std::ostream& operator<<(std::ostream& os, LinkedList<T>& list)
	{
		if (list.isEmpty())
			return os << std::string();

		// While there is a next node, 
		// write it's value to the output stream
		os << "[";
		Node* current = list.mFirst;
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
	: mFirst(nullptr),
	mLast(nullptr),
	mSize(0)
{
}

template<typename T>
inline void LinkedList<T>::push_back(const T& value)
{
	// Creating a node
	Node* node = new Node
	{
		value,
		nullptr
	};

	// The first node is the last if the list is empty
	if (isEmpty())
	{
		mLast = mFirst = node;
		return;
	}

	// Last existed node points to the new created node
	// and then new becomes the last
	mLast->next = node;
	mLast = node;
	// Increasing the size
	++mSize;
}

template<typename T>
inline T LinkedList<T>::getFirst() const
{
	return (mFirst) ? mFirst->value : NULL;
}

template<typename T>
inline bool LinkedList<T>::isEmpty() const
{
	return (mFirst) ? false : true;
}

template<typename T>
inline std::string LinkedList<T>::toString() const
{
	if (isEmpty())
		return std::string();

	// While there is a next node,
	// add it's value to the result string
	std::string result = "[";
	Node* current = mFirst;
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

#endif