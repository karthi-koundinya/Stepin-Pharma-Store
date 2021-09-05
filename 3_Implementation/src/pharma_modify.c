#include<pharma_operations.h>
void modify()
{
    char stname[20];
    FILE *fp;
    struct medicine m;
    system("cls");
    gotoxy(10,3);
    printf("<--:MODIFY RECORD:-->");
    gotoxy(10,5);
    printf("Enter name of medicine to modify: ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&m,sizeof(m),1,fp) == 1)
    {
        if(strcmp(stname,m.name) == 0){
            gotoxy(10,7);
            printf("Enter Name: ");
            gets(m.name);
            gotoxy(10,8);
            printf("Enter Company Name  : ");
            gets(m.cname);
            gotoxy(10,9);
            printf("Enter Price : ");
            scanf("%d",&m.price);
            gotoxy(10,10);
            printf("Enter Manufacture Date : ");
            fflush(stdin);
            gets(m.mfg_date);
            gotoxy(10,11);
            printf("Enter Expiry Date : ");
            fflush(stdin);
            gets(m.exp_date);
            fseek(fp ,-sizeof(m),SEEK_CUR);
            fwrite(&m,sizeof(m),1,fp);
            break;
        }
    }
    fclose(fp);
    gotoxy(10,16);
    printf("Press any key to continue.");
    getch();
    menu();
}
