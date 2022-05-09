#include "manager.h"

void listInfo(Car *slist, int count){
 printf("\nNo\tName\tCar Name\tprice\tRental Time\tRental Type\n");
 printf("====================================================\n");
 for(int i =0; i <count ; i++){
     if(slist[i].price==-1)
     continue;
     printf("%2d ", i+1);
     readInfo(&slist[i]);
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
