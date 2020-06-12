#ifndef MAIN_MENU_H_INCLUDED
#define MAIN_MENU_H_INCLUDED
#include<stdio.h>
#include<conio.h>
#include"Admin.h"
#include"Teacher.h"
#include"Student.h"
void display_main_line();
void cgpa();
void main_menu()
{
    system("cls");
    int i=0;///Basic declaration
    int option;///Basic declaration
    char ch;///Basic declaration
    ///
    /*
    declaration completed
    */
    ///
    display_main_line();
	printf("\n\n\tPlease Select your Choice:\n");
	printf("\t\t1. Admin Mode.\n");
	printf("\t\t2. Teacher Mode.\n");
	printf("\t\t3. Student Mode.\n");
	printf("\t\t4. CGPA Calculator.\n");
    printf("\t\t5. Credits.\n");
	printf("\t\t6. Exit.\n");
	printf("\n\t\tYour Choice: ");
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
        else if(i==0 && ch >= '1' && ch <= '7' )
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
        break;
    case 2:
        Teacher();
        break;
    case 3:
        Student();
        break;
    case 4:
        cgpa();
        break;
    case 5:
        creds();
        break;
    case 6:
        exit(1);
    }
    main_menu();//header file end
}
void cgpa()
{
	system("cls");
    printf("\n\n");
    printf("\t* CGPA Calculator *");
    printf("\n\t==============================================================================================================\n");
    int i=0,j;///Basic declaration
    char ch;///Basic declaration
    int d_subjects, d_sumcred=0, d_total=0;
    int credit,grade;
    ///
    /*
    declaration completed
    */
    ///
    printf("\n\n\tEnter the Number of Subjects: ");
    scanf("%d", &d_subjects);                    ///including practicals etc not non-credit subjects
    for(i=1; i<=d_subjects; i++)
    {
        printf("\n\tEnter grade points for Subject No. %d: ", i); /// prompt to get of the form AA = 10
        j=0;
        grade=0;
        while(1)
        {
            ch=getch();
            if( ch == 13 && j > 0 )
            {
                break;
            }
            else if(ch == 8 && j>0)
            {
                j--;
                printf("\b \b");
                grade/=10;
            }
            else if(ch>= '0' && ch<='9')
            {
                if(j!=0)
                {
                    grade*=10;
                }
                grade+=ch-'0';
                printf("%c",ch);
                j++;
            }
        }
        if(grade>10 || grade<0 || grade==3 || grade==2 || grade==1)
        {
        	int yeet=0;
            printf("\n\tInvalid Grade.");
            printf("\n\t\tWhere To:\n");
            printf("\t\t1. Try Again.\n");
            printf("\t\t2. Go Back.\n");
            printf("\n\t\tYour Choice: ");
            j=0;
            while(1)
            {
                ch=getch();
                if(ch == 13 && j == 1)
                {
                    break;
                }
                else if(ch == 8 && j==1)
                {
                    j--;
                    printf("\b \b");
                }
                else if(ch > '0' && ch < '3' && j == 0)
                {
                    printf("%c",ch);
                    yeet = ch - '0';
                    j++;
                }
            }
            switch(yeet)
            {
            case(1):
                cgpa();
                break;
            case(2):
                main_menu();
                break;
            }
             main_menu();
        }
        printf("\n\tEnter Credits for Subject No. %d: ", i);
        j=0;
        credit=0;
        while(1)
        {
            ch=getch();
            if( ch == 13 && j > 0 )
            {
                break;
            }
            else if(ch == 8 && j>0)
            {
                j--;
                printf("\b \b");
                credit/=10;
            }
            else if(ch>= '0' && ch<='9')
            {
                if(j!=0)
                {
                    credit*=10;
                }
                credit+=ch-'0';
                printf("%c",ch);
                j++;
            }
        }
        printf("\n");
        d_sumcred = d_sumcred + credit;
        d_total = d_total + grade*credit;
    }
    double d_cgpa = (float)d_total/(float)d_sumcred;
    printf("\n\t* Your CGPA is: %.2lf", d_cgpa);
	printf("\n\tPress Any Key to Continue...");
	getch();
	return;
}
void creds()
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t======================================================================================\n");
    printf("\t\t\tGreetings and Thanks for Using the Application!\n\n");
    printf("\t\t\tThis Application is made under Genesis Venture of ACSES Club of WCE, Sangli.\n\n");
    printf("\t\t\tCreated By:\n");
    printf("\t\t\t\tOnkar Gavali.\n");
    printf("\t\t\t\tVaishnavi Belgamwar.\n");
    printf("\t\t\t\tDevang Kamble.\n\n");
    printf("\t\t\tUnder the Mentorship of:\n");
    printf("\t\t\t\tAbhishek More.\n");
    printf("\t\t\t\tNishi Bhate.\n\n");
    printf("\t\t\t======================================================================================\n\n\n\n");
    printf("Press any key to Continue.\n");
    getch();
    return;
}
void display_main_line()
{
    printf("\n\n");
    printf("\t* MAIN MENU *");
    printf("\n\t==============================================================================================================\n");
    return;
}
#endif // MAIN_MENU_H_INCLUDED
