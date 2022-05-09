#include "car.h"

int selectMenu(){
int menu;
 printf("\n*** 렌터카 서비스 ***\n");
 printf("1. 조회\n");
 printf("2. 추가\n");
 printf("3. 수정\n");
 printf("4. 삭제\n");
 printf("5. 대여 시간 계산\n");
 printf("6. 가격 계산\n");
 printf("0. 종료\n\n");
 printf("=> 원하는 메뉴는? ");
 scanf("%d", &menu);
return menu;
}

int createInfo(Car *s1){
    printf("사용자 이름은? ");
    scanf("%s",s1->name);
    printf("차 이름은? ");
    scanf("%s",s1->carName);
    printf("목적지는? ");
    scanf("%s",s1->location);
    printf("가격은? ");
    scanf("%d",&s1->price);
    printf("대여유형은? (왕복:1, 편도:0) ");
    scanf("%d",&s1->rentalType);
    printf("대여시간은? (단위: 분)");
    scanf("%d",&s1->rentalTime);
    printf("=> 추가됨!");
    return 1;
}


int updateInfo(Car *s1){
    printf("사용자 이름은? ");
    scanf("%s",s1->name);
    printf("차 이름은? ");
    scanf("%s",s1->carName);
    printf("목적지는? ");
    scanf("%s",s1->location);
    printf("가격은? ");
    scanf("%d",&s1->price);
    printf("대여유형은? (왕복:1, 편도:0) ");
    scanf("%d",&s1->rentalType);
    printf("대여시간은? (단위: 분)");
    scanf("%d",&s1->rentalTime);
    printf("=> 수정됨!");
    return 1;
}

void calculateTime(){
    
    char startTime[20],tmpstTime[20]="";
    char tmpMin[2]="";
    char buf[3]={0};
    int rentalTime;
    int hr,min,totalMin,resMin,resHr;
    totalMin=0;
    printf("대여 시작시각을 입력하세요(ex.16:00)\n");
    scanf("%s",startTime);
    strcpy(tmpstTime,startTime);
    printf("%s\n",tmpstTime);
    printf("대여 시간을 입력하세요(단위:분)\n");
    scanf("%d",&rentalTime);
    char *ptr = strtok(startTime, ":");  
    hr=atoi(ptr);
    totalMin+=hr*60;          
    ptr = strtok(NULL, ":");
    min=atoi(ptr);
    totalMin+=min;
    totalMin+=rentalTime;
    if(totalMin>=1440){
        totalMin-=1440;
    }
    resHr=totalMin/60;
    resMin=totalMin%60;
    itoa(resMin,buf,10);
    if(resMin<10){
        strcat(tmpMin,"0");
    }
    printf("대여 시간은 %s ",tmpstTime);
    strcat(tmpMin,buf);
    printf("~ %d:%s 입니다\n",resHr,tmpMin);    
}

void calculatePrice(Car slist){
    int tprice=(slist.price)*(slist.rentalTime);
    printf("총가격은: %d원 입니다.\n",tprice);
}

void searchByName (Car *slist, int count){
    int scnt = 0;
    char search[20];

    printf("");
    scanf("%s", search);
 
    printf("\nNo\tName\tCar Name\tprice\tRental Time\tRental Type\n");
    printf("====================================================\n");
    for (int i = 0; i < count; i++){
        if (slist[i].price == -1) continue;
        if (strstr(slist[i].name, search)){
            printf("%2d", i+1);
            readInfo(slist[i]);
            scnt++;
        }
    }
    if (scnt == 0) printf("");
    printf("\n");
}

void searchByModel (Car *slist, int count){
    int scnt = 0;
    char search[20];

    printf("");
    scanf("%s", search);

    printf("\nNo\tName\tCar Name\tprice\tRental Time\tRental Type\n");
    printf("====================================================\n");
    for (int i = 0; i < count; i++){
        if (slist[i].price == -1) continue;
        if (strstr(slist[i].carName, search)){
            printf("%2d", i+1);
            readInfo(slist[i]);
            scnt++;
        }
    }
    if (scnt == 0) printf("");
    printf("\n");
}
void searchByTime (Car *slist, int count);

