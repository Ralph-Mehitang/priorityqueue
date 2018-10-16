#ifndef HEAPQ_H
#define HEAPQ_H
#include <iostream>
#include <utility>
using namespace std;

struct node
{
	string name;
	int key;
};
class heapq
{

private:

	int heapsize;
	int arr_size;
	node *arr;
	void increase_key(int i, int num); // increase key
	void increase_arr(); //increase array size
public:
	heapq(int size); //constructor
	node extractmax();
	node peek();
	void insert(string, int);
	void maxheapify(int);
	void print();
	friend ostream& operator <<(ostream& os, const heapq& td){
		int i;
		os<<td.heapsize<<endl;
		os<<td.arr_size<<endl;
		//os<<td.arr[i]<<endl;
	}


};

#endif