
#ifndef __PHARMA_OPERATIONS_H__
#define __PHARMA_OPERATIONS_H__

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>

typedef struct medicine
{
    char name[20];
    char cname[10];
    int price;
    char mfg_date[20];
    char exp_date[20];
};

void gotoxy(int ,int );
void menu();
void add();
void display();
void search();
void modify();
void deleterec();

#endif  /* __PHARMA_OPERATIONS_H__*/