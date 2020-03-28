/*
 * MatUtils.h
 *
 *  Created on: Jan 18, 2020
 *      Author: vivekkushwaha39
 */

#ifndef UI_MATUTILS_H_
#define UI_MATUTILS_H_

#include "Matrix2D.h"

namespace ui
{

class MatUtils
{
public:
	MatUtils();
	virtual ~MatUtils();
	virtual static void displayMat(MatInt &);
};

} /* namespace ui */

#endif /* UI_MATUTILS_H_ */
