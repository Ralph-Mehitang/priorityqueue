#include <iostream>
#include "heapq.h"
using namespace std;

//Ralph Mehitang
//Joseph Anderson

void initializeheap() {
	int heapsize;
	cout << " Enter a number for the initial size of the heap" << endl;
	cin >> heapsize;

	heapq heaptest(heapsize);
	int input = 0;
	cout << "Menu:" << endl;
	cout << "1. Insert a node " << endl;
	cout << "2. Peek the top node" << endl;
	cout << "3. Remove the top node" << endl;
	cout << "4. Print heap contents" << endl;
	cout << "5. End the program" << endl;
	cout << "input choice: ";
	cin >> input;

	switch (input)
	{
	case 1:
	{

		string name;
		int key;
		cout << "Enter the name: ";
		cin >> name;
		cout << "Enter the priority: ";
		cin >> key;
		heaptest.insert(name, key);

	}
	
	break;
	case 2:
	{
		node r = heaptest.peek();
		cout << "Max node: " << r.name << endl;
	}
	break;
	case 3:
	{
		node m = heaptest.extractmax();
		cout << "Max node: " << m.name << endl;
	}
	break;
	case 4:

		//heapq a = a.print(); //couldn't get to work

		break;

	case 5:
		exit(-1);

		break;
	}while(true);
	
}

int main()
{
	initializeheap();
	return 0;
}

//worked with billy on a couple functions