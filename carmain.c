#include "manager.h"

int main(){
    Car slist[20];
    int count = loadData(slist);
    int index = count;
    int menu;
    while (1) {
        menu = selectMenu();
        if (menu == 0) {
            printf("�����!");
            break;
        }
        if (menu == 1) {
            if (count > 0)
            listInfo(slist, index);
            continue;
        } else if (menu == 2) {
            count += createInfo(&slist[index ++]);
            continue;
        } else if (menu == 3) {
            int no = selectDataNum(slist, index);
            if (no == 0) {
                printf("=> ��ҵ�!\n");
                continue;
            }
            updateInfo(&slist[no - 1]);
            continue;
        } else if (menu == 4) {
            int no = selectDataNum(slist, index);
            if (no == 0) {
                printf("=> ��ҵ�!\n");
                continue;
            }
            int deleteok;
            printf("������ �����Ͻðڽ��ϱ�?(���� :1)");
            scanf("%d", & deleteok);
            if (deleteok == 1) {
                if (deleteInfo(& slist[no - 1])) {
                    count --;
                    printf("=> ������!\n ");
                };
                continue;
            }
        } else if (menu ==5){
            calculateTime();
            continue;
        } else if (menu==6){
            int no = selectDataNum(slist, index);
            calculatePrice(&slist[no-1]);
            continue;
        } else if (menu==7){
            searchByName(slist, index);
            continue;
        } else if (menu==8){
            searchByTime(slist, index);
            continue;
        } else if (menu==9){
            searchByModel(slist, index);
            continue;
        } else if (menu==10){
            saveData(slist, index);
            continue;
        }
        
    }
    return 0;
}