#include<pharma_operations.h>
void add()
{
    FILE *fp;
    struct medicine m;
    char another ='y';
    system("cls");

    fp = fopen("record.txt","ab+");
    if(fp == NULL){
        gotoxy(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxy(10,3);
        printf("<--:ADD RECORD:-->");
        gotoxy(10,5);
        printf("Enter details of medicine.");
        gotoxy(10,7);
        printf("Enter Name : ");
        gets(m.name);
        gotoxy(10,8);
        printf("Enter Company Name  : ");
        gets(m.cname);
        gotoxy(10,9);
        printf("Enter Price : ");
        scanf("%d",&m.price);
        fflush(stdin);
        gotoxy(10,10);
        printf("Enter Manufacture Date : ");
        gets(m.mfg_date);
        gotoxy(10,11);
        printf("Enter Expiry Date : ");
        gets(m.exp_date);
        fwrite(&m,sizeof(m),1,fp);
        gotoxy(10,15);
        printf("Want to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy(10,18);
    printf("Press any key to continue.");
    getch();
    menu();
}

