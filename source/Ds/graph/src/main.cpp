#include <iostream>
#include <stdlib.h>
#include "loop_detection.h"

using namespace std;
#define NUM_VERT 6
/**
 * to demonstrate matrix representation
 */
int matRepresent(int ac, char **av)
{

/**
 * Matrix representation of graph
 * mat[5][6] = 1 means there is an edge between verex 5 and 6
 * for undirected graph ->  mat[5][6] = mat[6]56] = 1
 *
 * lets represent below graph
 * 				   1
 * 				 /   \
 *				2     3
 *				|     |
 *				4     5
 *				 \   /
 *				   6
 */

// NOTE: Below statement initializes them by 0s
	int mat[NUM_VERT][NUM_VERT] = {0};
	mat[1][2] = mat[2][1] = 1;

	// represent the graph
	mat[0][1] = mat[1][0] = 1;
	mat[0][2] = mat[2][0] = 1;
	mat[1][3] = mat[3][1] = 1;
	mat[2][4] = mat[4][2] = 1;
	mat[3][5] = mat[5][3] = 1;
	mat[4][5] = mat[5][4] = 1;

	for (int i=0; i < NUM_VERT; i++)
	{
		for ( int j=0; j < NUM_VERT; j++ )
		{
			if ( mat[i][j] == 1 && i <= j )
				cout << i << "-" << j <<endl;
		}
	}

	return 0;
}

int main(int ac, char **av)
{
	return detectLoop(ac, av);
}
