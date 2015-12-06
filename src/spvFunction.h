#pragma once
#ifndef __SPVFUNCTION_H_
#define __SPVFUNCTION_H_

	int* Spyramid_AdjustCenter(int dim, int dataNum,int **dataStore);
	float Spyramid_CreateKeyValue(int* data_center, int *dataNum,int dim);
	int* Spyramid_InitialCenter(int dataRange, int dim);


#endif
