#ifndef MAIN_MENU_H_INCLUDED
#define MAIN_MENU_H_INCLUDED
#include<stdio.h>
#include<conio.h>
#include"Admin.h"
//#include"Teacher.h"
//#include"Student.h"
void main_menu()
{
    int i;int option;
    char ch;
    system("cls");
    printf("ATTENDANCE MANAGER");
    printf("\n*Choose your mode :- ");
    printf("\n\n1. Admin");
    printf("\n2. Teacher");
    printf("\n3. Student");
    printf("\n4. EXIT");
    printf("\n\nOption : ");
    i=0;
    while(1)
    {
        ch=getch();
        if(ch == 13 && i>0)
        {
            break;
        }
        else if(ch ==8 && i == 1)
        {
            printf("\b \b");
            i--;
        }
        else if(i==0 && ch >= '1' && ch <= '4' )
        {
            printf("%c",ch);
            option = ch-48;
            i++;
        }
    }
    switch(option)
    {
    case 1:
        Admin();
        return;
    case 2:
        //Teacher();
        return ;
    case 3:
        //student();
        return ;
    case 4:
        exit(1);
    }
    return;//header file end
}
#endif // MAIN_MENU_H_INCLUDED
