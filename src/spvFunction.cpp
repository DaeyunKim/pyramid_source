#include <iostream>
#include <math.h>
#include "spvFunction.h"
int* Spyramid_AdjustCenter(int dim, int dataNum,int **dataStore){

	int *data_center=new int [dim];

	for(int i=0;i<dim;i++){
		data_center[i]=0;
	}

	std::cout<<" ������ "<<dim<<" dataNum : "<<dataNum<<" dataStore �ּҰ�"<<dataStore<<std::endl;	

	for(int i=0;i<dataNum;i++){

		for(int j=0;j<dim;j++){

			data_center[j]+=(*(dataStore[i]+j));

		}

		//			std::cout<<std::endl;

	}

	//�߽ɰ� ������ Ȯ�� 
	for(int i=0;i<dim;i++){
		//			std::cout<<data_center[i]<<' ';
		data_center[i]=data_center[i]/dataNum;
		//			std::cout<<data_center[i]<<' ';
	}
	//		std::cout<<data_center<<' ';
	return data_center;//�߽����迭�� ó�� �ּҰ��� ���� 
}//Spyramid_AdjustCenter ����

float Spyramid_CreateKeyValue(int* data_center, int *dataNum,int dim){

	std::cout<<"data_center : "<<*data_center<<"dataNum : "<<*dataNum<<' '<<std::endl;

	//1. �Ƕ�̵� ��ȣ�� ���
	int max=0;//�ִ� ���� 
	int value=0;//
	int pyramidNum;//�Ƕ�̵� ��ȣ 

	for(int i=0;i<dim;i++){
		int a=data_center[i]-dataNum[i];//���⼭ �߽����� �������� ���� ���� ��츦 �����ؾ��Ѵ�!! �̰�쿡�� ���� ��츦 ����Ѵ�.
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
		std::cout<<"value �� : "<<value<<std::endl;
		pyramidNum=value;
		//return value;
	}else if(data_center[value]<dataNum[value]){
		std::cout<<"value �� : "<<value+dim<<std::endl;
		pyramidNum=value+dim;
		//				return value + dim;
	}else if(data_center[value]==dataNum[value]){
		std::cout<<"value �� : "<<value+dim<<std::endl;
		pyramidNum=value+dim;
	}		
	//2. �Ƕ�̵��ȣ���̿��� �Ƕ�̵� Ű���� ���� 
	float distance_v=0.0;

	for(int i=0;i<dim;i++){
		float a=(float)data_center[i]-(float)dataNum[i];
		distance_v +=(a*a);
	}

	distance_v = sqrt(distance_v);
	//		std::cout<<"d_v �� �Ÿ� : "<<distance_v<<std::endl;

	//ceilling �Լ� ��ȣ 
	//		std::cout<<(int)sqrt(dim)+1<<std::endl;//������ ���� ��� ����϶��� ��� 

	//�Ƕ�̵� ��ȣ * õ���Լ�(��Ʈ(����))+������ �Ÿ�
	float sp_value = (float)(pyramidNum*(ceil(sqrt((float)dim)))+distance_v);
	std::cout<<"�Ƕ�̵�Ű "<<sp_value<<std::endl;

	return sp_value;
}
int* Spyramid_InitialCenter(int dataRange, int dim){

	int *init_centerValue = new int[dim];

	for(int i=0;i<dim;i++){
		init_centerValue[i]=dataRange/2;
	}
	return init_centerValue;

}
