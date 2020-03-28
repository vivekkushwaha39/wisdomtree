/*
 * hcf_lcm.cpp
 *
 *  Created on: Mar 28, 2020
 *      Author: VivekK4
 */
#include "hcf_lcm.h"
int findHcf(int num1, int num2){

	while ( num1 ){
		int temp = num1;
		num1 = num1%num2;
		num2 = temp;
	}

	return num2;
}
