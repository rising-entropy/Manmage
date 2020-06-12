#ifndef MAIN_MENU_H_INCLUDED
#define MAIN_MENU_H_INCLUDED
#include<stdio.h>
#include<conio.h>
#include"Admin.h"
#include"Teacher.h"
#include"Student.h"
void main_menu()
{
    system("cls");
	printf("Please Select your Choice:\n");
	printf("\t1. Admin Mode.\n");
	printf("\t2. Teacher Mode.\n");
	printf("\t3. Student Mode.\n");
	printf("\t4. CGPA Calculator.\n");
    printf("\t5. Credits.\n");
	printf("\t6. Exit.\n");
	int inp;
	printf("Your Choice: ");
	scanf("%d", &inp);
	if(inp>6 || inp<1)
	{
		printf("\nInvalid Choice.\n");
		printf("Press any Key to Continue...");
		getch();
		main_menu();
	}
	if(inp == 1)
	Admin();
	else if(inp == 2)
	Teacher();
	else if(inp == 3)
	Student();
	else if(inp == 4)
	cgpa();
    else if(inp == 5)
    creds();
	else
	exit(1);
    return;//header file end
}
int cgpa()
{
	system("cls");
    int d_subjects, d_sumcred=0, d_total=0, i;
    printf("Enter the Number of Subjects: ");
    scanf("%d", &d_subjects);                    //including practicals etc not non-credit subjects
    for(i=1; i<=d_subjects; i++)
    {
        int credit;
        int grade;
        printf("\nEnter grade points for Subject No. %d: ", i); // prompt to get of the form AA = 10
        scanf("%d", &grade);
        if(grade>10 || grade<0 || grade==3 || grade==2 || grade==1)
        {
        	int yeet;
            printf("\nInvalid Grade.");
            printf("\nWhere To:\n");
            printf("\t1. Try Again.\n");
            printf("\t2. Go Back.\n");
            printf("Your Choice: ");
            scanf("%d", &yeet);
            if(yeet==1)
            cgpa();
            else
            main_menu();
        }
        printf("\nEnter Credits for Subject No. %d: ", i);
        scanf("%d", &credit);
        printf("\n");
        d_sumcred = d_sumcred + credit;
        d_total = d_total + grade*credit;
    }
    double d_cgpa = (float)d_total/(float)d_sumcred;
    printf("Your CGPA is: %.2lf", d_cgpa);
	printf("\nPress Any Key to Continue...");
	getch();
	main_menu();
}
int creds()
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
    main_menu();
}
#endif // MAIN_MENU_H_INCLUDED
