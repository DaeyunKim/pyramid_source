#include <iostream>
#include <cstdlib>
#include <math.h>
#include "spvFunction.h"
using namespace std;
//��������
int dim=10;//������
int dataNum=5;//�����ͼ� 

int **dataStore = NULL;//���� �����͸� �����ϴ� ����

int main(){

	//����, ������ ���� ���� ������ dataStore �迭�� ���� 
	dataStore = new int*[dataNum];

	for(int j=0;j<dataNum;j++){
		dataStore[j] = new int[dim]	;	//���� �����Ϳ� �迭�� �Ҵ��ϰ� �� ������ �迭�� �ٽ� �Ҵ����� 	
		for(int k=0; k<dim; k++){
			int randNum = (rand()%100);
			*(dataStore[j]+k) = randNum; 
			std::cout<<*(dataStore[j]+k)<<' ';
		}
		std::cout<<std::endl;
	}
	std::cout<<"dataStore  �� : "<<dataStore<<std::endl;

	//	������ Ȯ�� 
	for(int i=0;i<dataNum;i++){

		for(int j=0;j<dim;j++){

			std::cout<<' '<<(dataStore[i]+j)<<' ';

		}
		std::cout<<std::endl;

	}


	//�߽ɰ����ϱ�
	//1.  Bulk �϶� 
	int *dc = (Spyramid_AdjustCenter(dim,dataNum,dataStore));//�߽ɰ��� �������ִ� �����ͺ��� 1�����迭[dim]�� �ּҰ�
	std::cout<<"��ȯ�� : "<<dc<<std::endl;

	std::cout<<std::endl;
	//�߽ɰ� ���� 
	for(int i=0;i<dim;i++){

		std::cout<<*(dc+i)<<' ';			

	}
	//2. �ϳ����������� 
	int *initCenter = Spyramid_InitialCenter(100,10);//�����ͺ��� 1�����迭[dim]�� �ּҰ�

	for(int i=0;i<dim;i++){

		std::cout<<" �ʱ� �߽��� "<<*(initCenter+i)<<' ';			

	}
	//bulk�϶� 
	for(int i=0;i<dataNum;i++){
		//			std::cout<<dataStore[i]<<std::endl;
		Spyramid_CreateKeyValue(dc,dataStore[i],dim);	//int Spyramid_CreateKeyValue(int &data_center, int &dataNum)	
	}
	//�Ϲ� ó�� �����Ͱ��� �߰��Ҷ� �ϳ��� �߰����ȴٸ� 

	return 0;
}