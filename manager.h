#include"car.h"
#include<stdio.h>
void listInfo(Car *slist, int count); // 여러 제품을 리스트 하는 함수
int selectDataNum(Car *slist, int count);  //제품 번호를 고르는 함수
void saveData(Car slist[], int count);
int loadData(Car *slist);
