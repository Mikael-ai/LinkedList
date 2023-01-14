#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <sstream>


template<typename T>
class LinkedList
{
public:
	struct Node
	{
		T value;
		struct Node* next = nullptr;
	};

	Node *mFirst = nullptr;

public:
	LinkedList();

	void push_back(const T& value);
	T pop_back();
	bool isEmpty() const;
	unsigned long size() const;

private:
	unsigned long mSize;

public:
	friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list)
	{
		if (list.isEmpty())
			return os << std::string();

		// While there is a next node, 
		// write it's value to the output stream
		os << "[";
		Node *current = list.mFirst;
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

public:
	class LinkedListException : public std::runtime_error {
	private:
		std::string mMessage;

	public:

		LinkedListException() : std::runtime_error("List error.") {}
		LinkedListException(std::string message) : std::runtime_error(message.c_str()) 
		{
			mMessage = message;
		}

		std::string error() 
		{
			return (mMessage.empty()) ? "List error." : mMessage;
		}
	};
};

template<typename T>
inline LinkedList<T>::LinkedList()
	: mFirst(nullptr),
	mSize(0)
{
}

template<typename T>
inline void LinkedList<T>::push_back(const T& value)
{
	// Create a node
	Node *node = new Node
	{
		value,
		nullptr
	};

	// If the list is empty - new node becomes the first one
	if (isEmpty())
	{
		mFirst = node;
		++mSize;
		return;
	}

	// And if it's not - find node with node->next is pointing to nullptr,
	// that node is the last node we need. 
	// When found, we can assign our new created node to it
	Node *nextNode = mFirst;
	while (nextNode)
	{
		if (nextNode->next)
		{
			nextNode = nextNode->next;
			continue;
		}

		nextNode->next = node;
		++mSize;
		return;
	}
}

template<typename T>
inline T LinkedList<T>::pop_back()
{
	if (isEmpty())
	{
		try {
			throw LinkedListException("Error! The list is empty.");
		}
		catch (LinkedListException exception) {
			std::cerr << exception.error();
			exit(1);
		}
	}

	// The process is similar to the one I described in 'push_back' method,
	// but with the difference that now we need the value of the last node
	// (and also we need a double pointer, so we can change the actual value)
	T lastValue = T();
	Node** nextNode = &mFirst;
	while (nextNode)
	{
		if ((*nextNode)->next)
		{
			nextNode = &((*nextNode)->next);
			continue;
		}

		// Get the last value
		lastValue = (*nextNode)->value;

		// Get rid of the last node
		delete *nextNode;
		*nextNode = nullptr;

		// Decrease the size and return the value was found
		--mSize;
		break;
	}

	return lastValue;
}

template<typename T>
inline bool LinkedList<T>::isEmpty() const
{
	return (mFirst) ? false : true;
}

template<typename T>
inline unsigned long LinkedList<T>::size() const
{
	return mSize;
}

#endif
