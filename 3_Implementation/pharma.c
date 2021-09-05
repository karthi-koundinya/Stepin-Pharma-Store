/**
 * @file pharma.c
 * @author Karthik S (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-09-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include<pharma_operations.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
void gotoxy(int ,int );
void menu();
void add();
void display();
void search();
void modify();
void deleterec();
typedef struct medicine
{
    char name[20];
    char cname[10];
    int price;
    char mfg_date[20];
    char exp_date[20];
}m;
int main()
{
    gotoxy(15,8);
    printf("<--:Pharma Store Management System:-->");
    gotoxy(19,15);
    printf("\nPress any key to continue.");
    getch();
    menu();
    return 0;
}

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
void gotoxy(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}