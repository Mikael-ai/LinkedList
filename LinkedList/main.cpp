#include <iostream>
#include "LinkedList.h"

using std::cout;
using std::endl;

int main()
{
	LinkedList<int> list;
	list.push_back(1);
	list.push_back(2);
	list.pop_back();
	//list.push_back(3);
	//list.push_back(4);

	//cout << "toString() method: " 
	//	 << list.toString() 
	//     << "\n";

	cout << "operator<< result: "
	     << list << endl;

	return 0;
}
