#include "manager.h"

void listInfo(Car *slist, int count){
 printf("\nNo\tName\tCar Name\tlocation\tprice\tRental Time\tRental Type\n");
 printf("==================================================================\n"); 
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
 printf("번호는(취소 :0)? ");
 scanf("%d", &num);
 return num;
}

void saveData(Car slist[], int count) {
 FILE* fp;
 fp = fopen("car.txt", "wt");
 for(int i=0; i<count; i++) {
	if(slist[i].price==-1) continue;
	fprintf(fp, "%s %s %s %d %d %d\n", slist[i].name, slist[i].carName, slist[i].location, slist[i].price, slist[i].rentalTime, slist[i].rentalType);
 }
 
 fclose(fp);
 printf("저장됨!\n");  

}

int loadData(Car *slist)  {
 int count=0;
 FILE* fp;
 fp = fopen("car.txt", "r");
 if(fp==NULL) printf("\n=> 파일 없음\n");
 else {
	for(int i=0; i<100; i++) {
               fscanf( fp, "%s %s %s %d %d %d\n", slist[i].name, slist[i].carName, slist[i].location, &slist[i].price, &slist[i].rentalTime, &slist[i].rentalType);
		if(feof(fp)) break;
		count++;
 	}
	fclose(fp);
 printf("=>파일 불러옴!\n");
 }

 return count;

}


