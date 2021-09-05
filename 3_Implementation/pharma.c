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

