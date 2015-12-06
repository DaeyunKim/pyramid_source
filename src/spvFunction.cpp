#include <iostream>
#include <math.h>
#include "spvFunction.h"
int* Spyramid_AdjustCenter(int dim, int dataNum,int **dataStore){

	int *data_center=new int [dim];

	for(int i=0;i<dim;i++){
		data_center[i]=0;
	}

	std::cout<<" 차원수 "<<dim<<" dataNum : "<<dataNum<<" dataStore 주소값"<<dataStore<<std::endl;	

	for(int i=0;i<dataNum;i++){

		for(int j=0;j<dim;j++){

			data_center[j]+=(*(dataStore[i]+j));

		}

		//			std::cout<<std::endl;

	}

	//중심값 데이터 확인 
	for(int i=0;i<dim;i++){
		//			std::cout<<data_center[i]<<' ';
		data_center[i]=data_center[i]/dataNum;
		//			std::cout<<data_center[i]<<' ';
	}
	//		std::cout<<data_center<<' ';
	return data_center;//중심점배열의 처음 주소값을 전달 
}//Spyramid_AdjustCenter 종료

float Spyramid_CreateKeyValue(int* data_center, int *dataNum,int dim){

	std::cout<<"data_center : "<<*data_center<<"dataNum : "<<*dataNum<<' '<<std::endl;

	//1. 피라미드 번호값 출력
	int max=0;//최대 차이 
	int value=0;//
	int pyramidNum;//피라미드 번호 

	for(int i=0;i<dim;i++){
		int a=data_center[i]-dataNum[i];//여기서 중심점과 데이터의 차가 같을 경우를 생각해야한다!! 이경우에는 앞의 경우를 사용한다.
		if(a<0){
			a=-a;					
		}
		//			std::cout<<a<<std::endl;
		if(max<a){
			max=a;
			value=i;
		}				
	}

	if(data_center[value]>dataNum[value]){
		std::cout<<"value 값 : "<<value<<std::endl;
		pyramidNum=value;
		//return value;
	}else if(data_center[value]<dataNum[value]){
		std::cout<<"value 값 : "<<value+dim<<std::endl;
		pyramidNum=value+dim;
		//				return value + dim;
	}else if(data_center[value]==dataNum[value]){
		std::cout<<"value 값 : "<<value+dim<<std::endl;
		pyramidNum=value+dim;
	}		
	//2. 피라미드번호를이용해 피라미드 키값을 만듬 
	float distance_v=0.0;

	for(int i=0;i<dim;i++){
		float a=(float)data_center[i]-(float)dataNum[i];
		distance_v +=(a*a);
	}

	distance_v = sqrt(distance_v);
	//		std::cout<<"d_v 의 거리 : "<<distance_v<<std::endl;

	//ceilling 함수 기호 
	//		std::cout<<(int)sqrt(dim)+1<<std::endl;//데이터 값이 모두 양수일때만 사용 

	//피라미드 번호 * 천장함수(루트(차원))+점과의 거리
	float sp_value = (float)(pyramidNum*(ceil(sqrt((float)dim)))+distance_v);
	std::cout<<"피라미드키 "<<sp_value<<std::endl;

	return sp_value;
}
int* Spyramid_InitialCenter(int dataRange, int dim){

	int *init_centerValue = new int[dim];

	for(int i=0;i<dim;i++){
		init_centerValue[i]=dataRange/2;
	}
	return init_centerValue;

}
