#include <iostream>
#include <cstdlib>
#include <math.h>
#include "spvFunction.h"
using namespace std;
//전역변수
int dim=10;//차원수
int dataNum=5;//데이터수 

int **dataStore = NULL;//실제 데이터를 저장하는 공간

int main(){

	//차원, 데이터 수에 따른 데이터 dataStore 배열에 저장 
	dataStore = new int*[dataNum];

	for(int j=0;j<dataNum;j++){
		dataStore[j] = new int[dim]	;	//단일 포인터에 배열을 할당하고 그 각각의 배열에 다시 할당해줌 	
		for(int k=0; k<dim; k++){
			int randNum = (rand()%100);
			*(dataStore[j]+k) = randNum; 
			std::cout<<*(dataStore[j]+k)<<' ';
		}
		std::cout<<std::endl;
	}
	std::cout<<"dataStore  값 : "<<dataStore<<std::endl;

	//	데이터 확인 
	for(int i=0;i<dataNum;i++){

		for(int j=0;j<dim;j++){

			std::cout<<' '<<(dataStore[i]+j)<<' ';

		}
		std::cout<<std::endl;

	}


	//중심값구하기
	//1.  Bulk 일때 
	int *dc = (Spyramid_AdjustCenter(dim,dataNum,dataStore));//중심값을 가지고있는 포인터변수 1차원배열[dim]의 주소값
	std::cout<<"반환값 : "<<dc<<std::endl;

	std::cout<<std::endl;
	//중심값 전달 
	for(int i=0;i<dim;i++){

		std::cout<<*(dc+i)<<' ';			

	}
	//2. 하나씩들어왓을떄 
	int *initCenter = Spyramid_InitialCenter(100,10);//포인터변수 1차원배열[dim]의 주소값

	for(int i=0;i<dim;i++){

		std::cout<<" 초기 중심점 "<<*(initCenter+i)<<' ';			

	}
	//bulk일때 
	for(int i=0;i<dataNum;i++){
		//			std::cout<<dataStore[i]<<std::endl;
		Spyramid_CreateKeyValue(dc,dataStore[i],dim);	//int Spyramid_CreateKeyValue(int &data_center, int &dataNum)	
	}
	//일반 처음 데이터값을 추가할때 하나만 추가가된다면 

	return 0;
}