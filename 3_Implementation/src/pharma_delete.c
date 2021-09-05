#include<pharma_operations.h>
void deleterec()
{
    char stname[20];
    FILE *fp,*ft;
    struct medicine m;
    system("cls");
    gotoxy(10,3);
    printf("<--:DELETE RECORD:-->");
    gotoxy(10,5);
    printf("Enter name of medicine to delete record : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&m,sizeof(m),1,fp) == 1){
        if(strcmp(stname,m.name)!=0)
            fwrite(&m,sizeof(m),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("record.txt");
    rename("temp.txt","record.txt");
    gotoxy(10,10);
    printf("Press any key to continue.");
    getch();
    menu();
}
