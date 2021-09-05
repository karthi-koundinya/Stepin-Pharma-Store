#include<pharma_operations.h>

void menu()
{
    int choice;
    system("cls");
    gotoxy(10,3);
    printf("<--:MENU:-->");
    gotoxy(10,5);
    printf("Enter appropriate number to perform following task.");
    gotoxy(10,7);
    printf("1 : Add Record.");
    gotoxy(10,8);
    printf("2 : Display Record.");
    gotoxy(10,9);
    printf("3 : Search Record.");
    gotoxy(10,10);
    printf("4 : Modify Record.");
    gotoxy(10,11);
    printf("5 : Delete Record.");
    gotoxy(10,12);
    printf("6 : Exit.");
    gotoxy(10,13);
    printf("Enter your choice.");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        add();
        break;

    case 2:
        display();
        break;

    case 3:
        search();
        break;

    case 4:
        modify();
        break;

    case 5:
        delete();
        break;

    case 6:
        exit(1);
        break;

    default:
        gotoxy(10,17);
        printf("Invalid Choice.");
    }
}
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
void search()
{
    FILE *fp;
    struct medicine m;
    char stname[20];
    system("cls");
    gotoxy(10,3);
    printf("<--:SEARCH RECORD:-->");
    gotoxy(10,5);
    printf("Enter name of medicine : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&m,sizeof(m),1,fp ) == 1){
        if(strcmp(stname,m.name) == 0){
            gotoxy(10,8);
            printf("Name : %s",m.name);
            gotoxy(10,9);
            printf("Company Name : %s",m.cname);
            gotoxy(10,10);
            printf("Price : %d",m.price);
            gotoxy(10,11);
            printf("Manufacture Date : %s",m.mfg_date);
            gotoxy(10,12);
            printf("Expiry Date : %s",m.exp_date);
        }
    }
    fclose(fp);
    gotoxy(10,16);
    printf("Press any key to continue.");
    getch();
    menu();
}
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
void gotoxy(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
