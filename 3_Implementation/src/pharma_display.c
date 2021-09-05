#include<pharma_operations.h>
void display()
{
    FILE *fp;
    int i=1,j;
    struct medicine m;
    system("cls");
    gotoxy(10,3);
    printf("<--:Display RECORD:-->");
    gotoxy(10,5);
    printf("ID   Name of medicine   Company Name  Price      mfg_date     exp_date");
    gotoxy(10,6);
    printf("===========================================================================");
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,8);
        printf("Error opening file.");
        exit(1);
    }
    j=8;
    while(fread(&m,sizeof(m),1,fp) == 1){
        gotoxy(10,j);
        printf("%-7d%-22s%-12s%-10d%-13s%-13s",i,m.name,m.cname,m.price,m.mfg_date,m.exp_date);
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(10,j+3);
    printf("Press any key to continue.");
    getch();
    menu();
}
