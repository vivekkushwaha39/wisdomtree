/*
 * MatUtils2D.cpp
 *
 *  Created on: Jan 18, 2020
 *      Author: VivekK4
 */

#include "MatUtils2D.h"
#include <iostream>
using namespace std;
namespace ui
{

MatUtils2D::MatUtils2D()
{
	// TODO Auto-generated constructor stub

}

MatUtils2D::~MatUtils2D()
{
	// TODO Auto-generated destructor stub
}

void MatUtils2D::displayMat(MatInt &mat)
{
	for ( MatInt::iterator i = mat.begin(); i != mat.end(); i++)
	{
		for ( vector<int>::iterator j = i->begin(); j != i->end(); j++ )
		{
			cout << *(j) << "\t";
		}
		cout << endl;
	}
}

} /* namespace ui */
