#include "manager.h"

void listInfo(Car *slist, int count){
 printf("\nNo\tName\tCar Name\tprice\tRental Time\tRental Type\n");
 printf("====================================================\n");
 for(int i =0; i <count ; i++){
     printf("%2d ", i+1);
     }
 printf("\n");
}

int selectDataNum(Car *s, int count){
 int num;
 listInfo(s, count);
 printf("��ȣ�� (��� :0)? ");
 scanf("%d", &num);
 return num;
}
