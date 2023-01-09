#include <iostream>
#include "LinkedList.h"

using std::cout;
using std::endl;

int main()
{
	LinkedList<int> list;
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);

	cout << "toString() method: " 
		 << list.toString() 
	     << "\n";

	cout << "operator<< result: "
	     << list << endl;

	system("pause");
	return 0;
}
