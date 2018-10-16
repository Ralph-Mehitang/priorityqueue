#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "heapq.h"
using namespace std;

heapq::heapq(int size) {
	heapsize = -1;
	arr_size = size;
	arr = new node[size];
}



void ::heapq :: print() {
	int count = 1; // tree print
	node n;
	for (int i = 0; i <arr_size; i++)
	{
		//cout<<(arr[i])<<" "<<endl;
	}
}
void heapq::increase_key(int i, int size) {

	arr[i].key += size;
	while ((arr[i].key > arr[(i / 2)].key) && i != 0)
	{
		swap(arr[i], arr[(i / 2)]); //swaps child with node
		i = (i / 2);
	}
}
void heapq::increase_arr() {

	node * temp = new node[arr_size + 1];
	for (int i = 0; i < arr_size; i++)
	{
		temp[i].name = arr[i].name;
		temp[i].key = arr[i].key;
	}
	arr_size++; // increases the new size of the array
	delete[] arr; //clears old array memory
	arr = temp; //resets the original array to the new temp
}
void heapq::maxheapify(int i) {

	int largenode = i; // sets largenode as root node
	int l = 2 * i + 1; //sets left node
	int r = 2 * i + 2; //sets right node
					   //if left child is greater than root
	if (l<heapsize && arr[l].key>arr[i].key) {
		largenode = l;
	}
	//if right child is greater than the root
	if (r<heapsize && arr[r].key>arr[largenode].key)
	{
		largenode = r;
	}
	//swap and continue heapifying if largenode is not the root
	if (largenode != i)
	{
		swap(arr[i], arr[largenode]);
		//recursively heapify the affected subtree.
		maxheapify(largenode);
	}
}


node heapq::peek() {
	//check to see if heap is empty if so can't return any value
	if (heapsize == -1)
	{
		node tempval;
		return tempval;
	}
	return arr[0];
}

node heapq::extractmax() {
	if (heapsize == -1) // checks if heap is empty if so returns nothinng
	{
		node val;
		return val;
	}
	else {
		node tempval = arr[0];
		swap(arr[heapsize], arr[0]);
		heapsize--;
		//maxheapify[0];
		return tempval;
	}

}

void heapq::insert(string name, int prioritynum) {

	heapsize++; // begins by increasing heapsize to get 
		if (heapsize>=arr_size)
		{
			increase_arr();
		}
		arr[heapsize].name = name;
		arr[heapsize].key = 0; // I set it to zero because I am expecting no negative priority values
		increase_key(heapsize, prioritynum);
}

