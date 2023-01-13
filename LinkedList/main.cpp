#include <iostream>
#include "LinkedList.h"

using std::cout;
using std::endl;

int main()
{
	LinkedList<int> list;
	list.push_back(1);
	list.push_back(2);
	//list.push_back(3);
	//list.push_back(4);

	//cout << "toString() method: " 
	//	 << list.toString() 
	//     << "\n";

	cout << "operator<< result: "
	     << list << endl;

	system("pause");
	return 0;
}
