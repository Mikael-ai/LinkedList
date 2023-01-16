#include <iostream>
#include "LinkedList.h"

using std::cout;
using std::endl;

int main()
{
	LinkedList<int> list;
	
	list.push_back(1);
	list.push_back(2);
	cout << "Operation 1: push back values '1' and '2'\n";
	cout << "Expected: [1, 2]\n";
	cout << "operator<< result: " << list << "\n\n";
	
	list.pop_back();
	list.push_back(3);
	cout << "Operation 2: pop back and then push '3'\n";
	cout << "Expected: [1, 3]\n";
	cout << "toString() result: " << list.toString() << "\n\n";

	list.pop_back();
	list.pop_back();
	cout << "Operation 3: pop back 2 times\n";
	cout << "Expected: ''\n";
	cout << "Result: '" << list << "'\n\n";

	cout << "Operation 4: pop back again\n";
	cout << "Expected: an exception\n";
	cout << "Result: ";
	list.pop_back();

	system("pause");
	return 0;
}
