/*
 * MatUtils2D.h
 *
 *  Created on: Jan 18, 2020
 *      Author: VivekK4
 */

#ifndef UI_MATUTILS2D_H_
#define UI_MATUTILS2D_H_

#include "MatUtils.h"
namespace ui
{

class MatUtils2D: public MatUtils
{
public:
	MatUtils2D();
	virtual ~MatUtils2D();
	static void displayMat(MatInt &);
};

} /* namespace ui */

#endif /* UI_MATUTILS2D_H_ */
