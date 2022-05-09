#include "car.h"

int selectMenu(){
int menu;
 printf("\n*** ����ī ���� ***\n");
 printf("1. ��ȸ\n");
 printf("2. �߰�\n");
 printf("3. ����\n");
 printf("4. ����\n");
 printf("5. �뿩 �ð� ���\n");
 printf("6. ���� ���\n");
 printf("0. ����\n\n");
 printf("=> ���ϴ� �޴���? ");
 scanf("%d", &menu);
return menu;
}

int createInfo(Car *s1){
    printf("����� �̸���? ");
    scanf("%s",s1->name);
    printf("�� �̸���? ");
    scanf("%s",s1->carName);
    printf("��������? ");
    scanf("%s",s1->location);
    printf("������? ");
    scanf("%d",&s1->price);
    printf("�뿩������? (�պ�:1, ��:0) ");
    scanf("%d",&s1->rentalType);
    printf("�뿩�ð���? (����: ��)");
    scanf("%d",&s1->rentalTime);
    printf("=> �߰���!");
    return 1;
}


int updateInfo(Car *s1){
    printf("����� �̸���? ");
    scanf("%s",s1->name);
    printf("�� �̸���? ");
    scanf("%s",s1->carName);
    printf("��������? ");
    scanf("%s",s1->location);
    printf("������? ");
    scanf("%d",&s1->price);
    printf("�뿩������? (�պ�:1, ��:0) ");
    scanf("%d",&s1->rentalType);
    printf("�뿩�ð���? (����: ��)");
    scanf("%d",&s1->rentalTime);
    printf("=> ������!");
    return 1;
}

void calculateTime(){
    
    char startTime[20],tmpstTime[20]="";
    char tmpMin[2]="";
    char buf[3]={0};
    int rentalTime;
    int hr,min,totalMin,resMin,resHr;
    totalMin=0;
    printf("�뿩 ���۽ð��� �Է��ϼ���(ex.16:00)\n");
    scanf("%s",startTime);
    strcpy(tmpstTime,startTime);
    printf("%s\n",tmpstTime);
    printf("�뿩 �ð��� �Է��ϼ���(����:��)\n");
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
    printf("�뿩 �ð��� %s ",tmpstTime);
    strcat(tmpMin,buf);
    printf("~ %d:%s �Դϴ�\n",resHr,tmpMin);    
}

void calculatePrice(Car slist){
    int tprice=(slist.price)*(slist.rentalTime);
    printf("�Ѱ�����: %d�� �Դϴ�.\n",tprice);
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

