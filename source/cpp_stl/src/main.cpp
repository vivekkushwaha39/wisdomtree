/*
 * main.cpp
 *
 *  Created on: Dec 26, 2020
 *      Author: VivekK4
 */
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
void printIterator(T &t);

int main()
{	//------------------------
	// vectors
	//------------------------

	vector<int> intVec =  { 1,543,643,52424,534,2,654 };

	// 1. Sorting
	sort(intVec.begin(), intVec.end());


	return 0;
}


