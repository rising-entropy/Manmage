#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED


#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include<stdlib.h>
#include<math.h>
void display_line();
void studentlogined(int ,char *,char *,char *,char *);
void change_student_password(int ,char *,char *,char *,char *);
void show_attendance(int ,char *,char *,char *,char *);
int position_of_PRN(int ,char *,char *,char *,char *);                  ///to find position in file
void Student()
{
    system("cls");
    display_line();
    char ch;                                ///basic variable
    int i,opt;                              ///basic variables
    int inputed_PRN=0,actual_PRN=0;///for PRN
    char inputed_password[25],actual_password[25];///for password
    char student_firstname[75],student_middlename[25],student_lastname[25];
    FILE *f_stu_data;
    ///
    /*
    declaration completed
    */
    ///
    printf("\n\n");
    printf("\tSTUDENT LOGIN");
    printf("\n\n\tEnter your PRN No. : ");
    i=0;///initialize to zero
    inputed_PRN=0;///initialize to zero
    while(1)
    {
        ch=getch();
        if( ch== 13 && i>0)
        {
            break;
        }
        else if(ch==8 && i>0)
        {
            printf("\b \b");
            i--;
            inputed_PRN /=10;
        }
        else if(ch >= '0' && ch <= '9')
        {
            printf("%c",ch);
            if(i != 0)
                inputed_PRN *=10;
            inputed_PRN += ch-'0';
            i++;
        }

    }
    printf("\n\tEnter Your Password: ");
    i=0;///initialize to zero
    while(1)
    {
        ch=getch();
        if( ch == 13 && i>0 )///something inputed && enter pressed condition
        {
            inputed_password[i]='\0';///at end inputed password null is added
            break;
        }
        else if( ch == 8 )///fot backspace
        {
            if(i>0)
            {
                printf("\b \b");
                i--;
            }
        }
        else if ( ch == 32 )/// space bar not allowed
        {
            continue;
        }
        else
        {
            printf("*");                                ///printing on screen
            inputed_password[i]=ch;                     ///storing
            i++;
        }
    }
    f_stu_data=fopen("Admin/studdata.txt","r");//student data file
    if( f_stu_data == NULL)
    {
        printf("\n\tDatabase is not Created Yet.\n\tPlease Contact Admin.");//file is not created by admin
        printf("\nPress any key to Continue.\n");
        getch();
        main_menu();
    }
    while(fscanf(f_stu_data,"%d %s %s %s %s",&actual_PRN,student_firstname,student_middlename,student_lastname,actual_password) != EOF)
    {
        if(actual_PRN == inputed_PRN && !strcmp(actual_password,inputed_password))
        {
            fclose(f_stu_data);///file closed
            studentlogined(actual_PRN,student_firstname,student_middlename,student_lastname,actual_password);
            return ;
        }
    }
    system("cls");
    printf("\n\tInvalid Data entered.\n\tChoose your option :");
    printf("\n\t\t1. Try again.");
    printf("\n\t\t2. Go back.");
    printf("\n\n\tYour Choice: ");
    i=0;///initialize to zero
    while(1)
    {
        ch=getch();
        if(ch == 13 && i == 1)///data inputed and enter key pressed
        {
            break;
        }
        else if(ch == 8 && i==1)///backspace pressed and something printed that is removed
        {
            i--;
            printf("\b \b");
        }
        else if(ch > '0' && ch < '3' && i == 0)///To print valid data
        {
                printf("%c",ch);
                opt = ch - '0';
                i++;
        }
    }
    switch(opt)
    {
    case 1:
        Student();///go back to teacher
        break;
    case 2:
        main_menu();
        break;
    }
    main_menu();
}
void studentlogined(int actual_PRN,char *student_firstname,char *student_middlename,char *student_lastname,char *actual_password)
{
    system("cls");
    display_line();
    int i=0,opt;///basic variables
    char ch;///basic variables
    ///
    /*
    declaration completed
    */
    ///
    printf("\n\tChoose Your Option");
    printf("\n\n\t\t1. Change Password.");
    printf("\n\t\t2. Display Attendance.");
    printf("\n\t\t3. Main Menu.");
    printf("\n\n\t\tYour Choice: ");
    while(1)///i is already initialize to zero
    {
        ch=getch();
        if(ch == 13 && i == 1)///data inputed and enter key pressed
        {
            break;
        }
        else if(ch == 8 && i==1)///backspace pressed and something printed that is removed
        {
            i--;
            printf("\b \b");
        }
        else if(ch > '0' && ch < '4' && i == 0)///To print valid data
        {
                printf("%c",ch);
                opt = ch - '0';
                i++;
        }
    }
    switch(opt)
    {
    case 1:
        change_student_password(actual_PRN,student_firstname,student_middlename,student_lastname,actual_password);
        break;
    case 2:
        show_attendance(actual_PRN,student_firstname,student_middlename,student_lastname,actual_password);
        break;
    case 3:
        main_menu();
        break;
    }
    studentlogined(actual_PRN,student_firstname,student_middlename,student_lastname,actual_password);

}
void change_student_password(int actual_PRN,char *student_firstname,char *student_middlename,char *student_lastname,char *actual_password)
{
    system("cls");
    display_line();
    int i=0;///Basic variable
    char string1[20], string2[20];///Two strings to confirm passwords
    char ch;///Basic variable
    FILE *f_stu_data,*f_stu_datatmp;///Two files :- 1 for original and 2nd for tmp
    ///variables for file copying
    int f_actual_PRN=0;///for PRN
    char f_actual_password[25];///for password
    char f_student_firstname[75],f_student_middlename[25],f_student_lastname[25];
    ///
    /*
    declaration completed
    */
    ///
    printf("\n\n\tEnter New Password : ");
    while(1)///i is already initialize to zero
    {
        ch=getch();
        if(ch==13 && i>0)
        {
            string1[i]='\0';
            break;
        }
        else if(ch==13)
                continue;
        else if(ch == 8)
        {
            if(i>0)
            {
                printf("\b \b");
                i--;
            }
        }
        else if(ch == 32)
        {
            continue;
        }
        else
        {
            printf("*",ch);
            string1[i]=ch;
            i++;
        }
    }
	printf("\n\tRe-Enter New Password: ");
	i=0;///Initialize to zero
	while(1)
    {
        ch=getch();
        if(ch==13 && i>0)
        {
            string2[i]='\0';
            break;
        }
        else if(ch==13)
                continue;
        else if(ch == 8)
        {
            if(i>0)
            {
                printf("\b \b");
                i--;
            }
        }
        else if(ch == 32)
        {
            continue;
        }
        else
        {
            printf("*",ch);
            string2[i]=ch;
            i++;
        }
    }
    if(strcmp(string1,string2)==0)
    {
        f_stu_data=fopen("Admin/studdata.txt","r");///open for copying
        f_stu_datatmp=fopen("Admin/studdatatmp.txt","w");
        while(fscanf(f_stu_data,"%d %s %s %s %s",&f_actual_PRN,f_student_firstname,f_student_middlename,f_student_lastname,f_actual_password)!= EOF)
        {
            if(f_actual_PRN == actual_PRN )
            {
                fprintf(f_stu_datatmp,"%d %s %s %s %s\n",f_actual_PRN,f_student_firstname,f_student_middlename,f_student_lastname,string1);
            }
            else
            {
                fprintf(f_stu_datatmp,"%d %s %s %s %s\n",f_actual_PRN,f_student_firstname,f_student_middlename,f_student_lastname,f_actual_password);
            }
        }
        fclose(f_stu_data);
        fclose(f_stu_datatmp);
        remove("Admin/studdata.txt");
        rename("Admin/studdatatmp.txt","Admin/studdata.txt");
        printf("\n\n\tPassword Updated Successfully");
    }
    else
    {
        printf("\n\n\tInvalid Password.");
		printf("\n\tSending you back.");
		printf("\n\tPress Any Key to Continue...\n");
		getch();
		studentlogined(actual_PRN,student_firstname,student_middlename,student_lastname,actual_password);
		return;
    }
    printf("\nPress any key to Continue.\n");
    getch();
    studentlogined(actual_PRN,student_firstname,student_middlename,student_lastname,string1);
    return;
}
void show_attendance(int actual_PRN,char *student_firstname,char *student_middlename,char *student_lastname,char *actual_password)
{
    system("cls");
    display_line();
    int i,cnt=1,flag=0;
    char ch;
    int position_in_file=position_of_PRN(actual_PRN,student_firstname,student_middlename,student_lastname,actual_password);///in attendance string
    int student_total_count;///total count of students
    int present_cnt,absent_cnt,total_cnt;
    int lec_to_attend;///to check 75% attendance
    float present_per;///% of present absent
    char subject[20],tea_firstname[20],tea_middlename[20],tea_lastname[20],path[50],tea_password[20];///to handle file of teacher data
    char filepath[50];///to store path of file
    FILE *f_subject,*f_student_attendance,*f_student_total_count;
    ///
    /*
    declaration completed
    */
    ///
    ///file open ;- to get total count of students
    f_student_total_count=fopen("Admin/student_and_teacher_number.txt","r");
    if(f_student_total_count == NULL)
    {
        printf("Please create database");
        printf("\nPress Any Key to Continue.\n");
        getch();
        main_menu();
    }
    fscanf(f_student_total_count,"%d",&student_total_count);
    fclose(f_student_total_count);
    ///file closed
    char *attendance=malloc(sizeof(char)*(student_total_count + 1));///to store string
    int date;///to store date
    printf("\n\n\tStudent Details:-");
    printf("\n\n\t* Name : %s %s %s",student_firstname,student_middlename,student_lastname);
    printf("\n\n\t* PRN No. : %d",actual_PRN);
    printf("\n\n");
    printf("\t%6s||%-15s||%-15s||%-15s||%-15s||%-15s||%-15s||","Sr.No.","Subject","Present count","Absent count","Total lectures","% Present","NeedToAttend");
    printf("\n\t==============================================================================================================\n");
    f_subject=fopen("Admin/teadata.txt", "r");
    if(f_subject== NULL)//if file is absent or mostly database not added
    {
        printf("Create Database ");
        getch();
        main_menu();
    }
    while(fscanf(f_subject,"%s %s %s %s %s %s",subject,tea_firstname,tea_middlename,tea_lastname,path,tea_password) != EOF)
    {
        flag=0;///to check atleast one attendance filled or not
        present_cnt=0;absent_cnt=0;total_cnt=0;present_per=0;
        strcpy(filepath,path);
        strcat(filepath,"Attendance Sheet.txt");
        f_student_attendance=fopen(filepath,"r");
        while(fscanf(f_student_attendance,"%d %s",&date,attendance) != EOF)
        {
            flag=1;
            if(attendance[position_in_file-1]=='1')
                present_cnt++;
            else
                absent_cnt++;
            total_cnt++;
        }
        fclose(f_student_attendance);
        present_per= ((((float)(present_cnt))/total_cnt)*100.0);
        lec_to_attend=(int)ceil(((0.75*total_cnt)-present_cnt)/0.25);
        if(lec_to_attend<0)
            lec_to_attend=0;///already attendance above 75 %
        if(flag==0)
        {
            present_cnt=0;absent_cnt=0;total_cnt=0;present_per=0;lec_to_attend=0;///all to zero
        }
        printf("\t%6d||%-15s||%-15d||%-15d||%-15d||%-15.2f||%-15d||\n",cnt,subject,present_cnt,absent_cnt,total_cnt,present_per,lec_to_attend);
        cnt++;
    }
    printf("\t==============================================================================================================\n");
    fclose(f_subject);
    getch();
    studentlogined(actual_PRN,student_firstname,student_middlename,student_lastname,actual_password);
}
int position_of_PRN(int actual_PRN,char *student_firstname,char *student_middlename,char *student_lastname,char *actual_password)
{
    int cnt=1;///position count
    int f_actual_PRN;///for file data
    char f_student_firstname[25],f_student_middlename[25],f_student_lastname[25],f_actual_password[25];///for file
    FILE *f_student_data;


    f_student_data=fopen("Admin/studdata.txt","r");//student data file
    while(fscanf(f_student_data,"%d %s %s %s %s",&f_actual_PRN,f_student_firstname,f_student_middlename,f_student_lastname,f_actual_password) != EOF)
    {
        if(f_actual_PRN == actual_PRN )
        {
            fclose(f_student_data);///file closed
            return cnt;
        }
        cnt++;
    }
    return cnt;
}
void display_line()
{
    printf("\n\n");
    printf("\t* STUDENT MODE *");
    printf("\n\t==============================================================================================================\n");

}


#endif // STUDENT_H_INCLUDED
