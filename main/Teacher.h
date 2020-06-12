#ifndef TEACHER_H_INCLUDED
#define TEACHER_H_INCLUDED



#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include"main_menu.h"
#include"display_main_page.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include"update_attendance.h"

void Teacher()
{
    system("cls");
    char inputed_pass[25], actual_pass[25],inputed_subject[25];
    char subject[25],firstname[75],middlename[25],lastname[25],path[50];
    int i=0,opt;
    char ch;
    FILE *filePointer;
    filePointer = fopen("Admin/teadata.txt", "r");
    if(filePointer== NULL)//if file is absent or mostly database not added
    {
        printf("Create Database ");
        getch();
        main_menu();
    }
    printf("\nEnter Subject name: ");
    ///
    while(1)
    {
        ch=getch();
        if(ch==13 && i>0)
        {
            inputed_subject[i]='\0';
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
            printf("%c",ch);
            inputed_subject[i]=ch;
            i++;
        }
    }
    i=0;
    printf("\nEnter Password: ");
    while(1)
    {
        ch=getch();
        if(ch==13 && i>0)
        {
            inputed_pass[i]='\0';
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
            printf("%c",ch);
            inputed_pass[i]=ch;
            i++;
        }
    }
    while( fscanf(filePointer,"%s %s %s %s %s %s",subject,firstname,middlename,lastname,path,actual_pass) != EOF)
    {
        if(!strcmp(inputed_pass,actual_pass) && !strcmp(inputed_subject,subject) )
        {
            fclose(filePointer);
            teacherlogined(subject,firstname,middlename,lastname,path,actual_pass);
            break;
        }
    }
    fclose(filePointer);
    printf("\nChoose your option.\n\n");
    printf("What you want to Do:\n");
    printf("\t1. Try Again.\n");
    printf("\t2. Go Back.\n\n\t");
    printf("Your Choice: ");
    i=0;
    while(1)
    {
        ch=getch();
        if(ch == 13 && i == 1)
        {
            break;
        }
        else if(ch == 8 && i==1)
        {
            i--;
            printf("\b \b");
        }
        else if(ch > '0' && ch < '3' && i == 0)
        {
                printf("%c",ch);
                opt = ch - '0';
                i++;
        }
    }
    switch(opt)
    {
    case(1):
        Teacher();
        break;
    case(2):
        exit(1); //change this to actual main later
        break;
    }

}
void teacherlogined(char* subject,char* firstname,char* middlename,char* lastname,char* path,char* actual_pass)
{
    system("cls");
	int opt,i=0;
	char ch;
	printf("\n=========================================================");
    printf("\n Welcome to Teacher Mode.\n");
    printf("=========================================================");
	printf("\n\n Choose your option :\n");
    printf(" \t1. Change Password.\n");
    printf(" \t2. update attendance\n");
    printf(" \t3. Show attendance.\n");
    printf(" \t4. Show list of students.\n");
    printf(" \t5. Go Back.\n\n\t");
    printf("Option : ");
    while(1)
    {
        ch=getch();
        if(ch == 13 && i == 1)
        {
                break;
        }
        else if(ch == 8 && i==1)
        {
            i--;
            printf("\b \b");
        }
        else if(ch > '0' && ch < '6' && i == 0)
        {
            printf("%c",ch);
            opt=ch-'0';
            i++;
        }
    }
    switch(opt)
        {
        	case(1):
        		teacherpasswordchange(subject,firstname,middlename,lastname,path,actual_pass);
        		break;
            case(2):
        		update_attendance(path);
        		break;
            case 3:
                showattendance(subject,firstname,middlename,lastname,path,actual_pass);
                break;
            case 4:
                list_student();//already in admin.h
                break;
        	case(5):
        		main_menu();
        		break;

        }

}
void teacherpasswordchange(char* subject,char* firstname,char* middlename,char* lastname,char* path,char* actual_pass)
{

    char string1[20], string2[20];
	int i=0;
	char ch;
	printf("\nEnter New Password: ");
	while(1)
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
            printf("%c",ch);
            string1[i]=ch;
            i++;
        }
    }
	printf("\nRe-enter New Password: ");
	i=0;
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
            printf("%c",ch);

            string2[i]=ch;
            i++;
        }
    }
	if(strcmp(string1, string2)==0)
    {
        FILE *filePointer,*tmpfilePointer;
        char f_subject[25],f_firstname[75],f_middlename[25],f_lastname[25],f_path[50],f_actual_pass[25];
        filePointer = fopen("Admin/teadata.txt", "r");
        tmpfilePointer = fopen("Admin/teadatatmp.txt", "w");
        while(fscanf(filePointer,"%s %s %s %s %s %s",f_subject,f_firstname,f_middlename,f_lastname,f_path,f_actual_pass) != EOF)
        {
            if(!strcmp(f_firstname,firstname) && !strcmp(f_subject,subject))
            {
                fprintf(tmpfilePointer,"%s %s %s %s %s %s\n",f_subject,f_firstname,f_middlename,f_lastname,f_path,string1);
            }
            else
            {
                fprintf(tmpfilePointer,"%s %s %s %s %s %s\n",f_subject,f_firstname,f_middlename,f_lastname,f_path,f_actual_pass);
            }
        }
        fclose(filePointer);
        fclose(tmpfilePointer);
        remove("Admin/teadata.txt");
        rename("Admin/teadatatmp.txt","Admin/teadata.txt");
        printf("\nPassword updatd");
    }
    else
    {
        printf("\nInvalid Password.");
		printf("\nSending you back.");
		printf("\nPress Any Key to Continue...\n");
		getch();
		teacherpasswordchange(subject,firstname,middlename,lastname,path,actual_pass);
    }
    getch();
    teacherlogined(subject,firstname,middlename,lastname,path,string1);
    return;
}

void showattendance(char* subject,char* firstname,char* middlename,char* lastname,char* path,char* actual_pass)
{
    system("cls");
    FILE *fp;
    int i=0,opt=0,flag=0,number_of_students;
    char ch;
    char filepath[50];//to specify file location
    strcpy(filepath,path);
    strcat(filepath,"Attendance Sheet.txt");
    printf("\n\n\tChoose yore option");
    printf("\n\t\t1. Search by PRN.");
    printf("\n\t\t2.Search by date.");
    printf("\n\t\t3.Go back.");
    printf("\n\t\tOption : ");
    while(1)
    {
        ch=getch();
        if(ch == 13 && i == 1)
        {
                break;
        }
        else if(ch == 8 && i==1)
        {
                i--;
                printf("\b \b");
        }
        else if(ch > '0' && ch < '4' && i == 0)
        {
                printf("%c",ch);
                opt = ch - '0';
                i++;
        }
    }
    switch(opt)
    {
    case 1:
        flag=1;
        break;
    case 2:
        flag=2;
        break;
    case 3:
        teacherlogined(subject,firstname,middlename,lastname,path,actual_pass);//teacher_details
        break;
    }
    fp=fopen("Admin/student_and_teacher_number.txt","r");
    if(fp == NULL)//to check file exist or not
    {
        printf("Please create database");
        getch();
        exit(1);//later main_menu
    }
    fscanf(fp,"%d",&number_of_students);
    fclose(fp);
    if(flag==1)
    {

        system("cls");
        again_to_search_PRN:
        i=0;
        int prn=0,scaned_PRN=0,cnt=1,check=0;
        char first_name[20],middle_name[20],last_name[20],student_pass[25];

        system("cls");

        printf("Enter PRN : ");
        while(1)
        {
            ch=getch();
            if( ch == 13 && i>0)
            {
                break;
            }
            else if(ch == 8 && i>0)
            {
                printf("\b \b");
                i--;
                prn/=10;
            }
            else if(ch >= '0' && ch <= '9')
            {
                printf("%c",ch);
                if(i!=0)
                    prn*=10;
                prn+=ch-'0';
                i++;
            }
        }
        FILE *fp1,*fp2;//1st for student data and 2nd for attendance sheet and for scanf number of students
        cnt=1;//initia;ize to 1st position
        fp1=fopen("Admin/studdata.txt","r");


        while(fscanf(fp1,"%d %s %s %s %s",&scaned_PRN,first_name,middle_name,last_name,student_pass))
        {
            if(prn==scaned_PRN)
            {
                check=1;//to notify PRN find in further code
                fclose(fp1);
                int cnt_present=0,cnt_absent=0,total=0,date;//need in below function
                char *attendance=malloc(sizeof(char)*(number_of_students+1));
                float per_present=0,per_absent=0;
                fp2=fopen(filepath,"r");
                while(fscanf(fp2,"%d %s",&date,attendance) != EOF)
                {
                    if(attendance[cnt-1]=='1')
                    {
                        cnt_present++;
                    }
                    else
                    {
                        cnt_absent++;
                    }
                    total++;
                }
                fclose(fp2);
                printf("\n==============================");
                printf("\n* Name of student : %s %s %s",first_name,middle_name,last_name);
                printf("\n* PRN : %d",scaned_PRN);
                printf("\n* Total number of Lecture : %d",total);
                printf("\n < Present : %d > || < Absent : %d >",cnt_present,cnt_absent);
                per_present=(((float)cnt_present)/total)*100.0;
                per_absent=100.00-per_present;
                printf("\n %% Present : %0.2f%%",per_present);
                printf("\n %% Absent : %0.2f%%",per_absent);
                getch();
                //show details ended
                printf("\n\nChoose your Option :");
                printf("\n\t1. Again search.");
                printf("\n\t2. Go back");
                i=0;
                while(1)
                {
                    ch=getch();
                    if(ch == 13 && i == 1)
                    {
                        break;
                    }
                    else if(ch == 8 && i==1)
                    {
                        i--;
                        printf("\b \b");
                    }
                    else if(ch > '0' && ch < '3' && i == 0)
                    {
                        printf("%c",ch);
                        opt = ch - '0';
                        i++;
                    }
                }
                switch(opt)
                {
                case 1:
                    system("cls");
                    goto again_to_search_PRN;
                    break;
                case 2:
                   showattendance(subject,firstname,middlename,lastname,path,actual_pass);//parameters are of teacher
                   break;
                }
                break;
            }
            cnt++;//count to specify attendance position
        }
        if(check==0)
        {
            printf("\nInvalid PRN");
            getch();
            system("cls");
            goto again_to_search_PRN;
        }

    }
    else
    {
        system("cls");
        //
        int dd=0,mm=0,yyyy=0,yyyymmdd=0,check,cnt=1,j,scaned_PRN,date;//date month,year;
        char first_name[20],middle_name[20],last_name[20],student_pass[25];
        char *attendance_string=malloc(sizeof(char)*(number_of_students+1));
        again_to_search_date:
        date_enter:
        dd=0;mm=0;yyyy=0;yyyymmdd=0;
        dd = day_enter();
        mm = month_enter();
        yyyy = year_enter();
        // date inputed
        check=is_valid_date(dd, mm, yyyy);
        switch(check)
        {
        case -1:
            printf("\nInvalid day...\nPlease re-enter the date... ");
            getch();
            system("cls");
            goto date_enter;
        case -2:
            printf("\nInvalid month...\nPlease re-enter the date... ");
            getch();
            system("cls");
            goto date_enter;
        default:
            system("cls");
        }
        yyyymmdd+=yyyy*10000;
        yyyymmdd+=mm*100;
        yyyymmdd+=dd;
        //
        FILE *fp1,*fp2;
        fp1=fopen("Admin/studdata.txt","r");
        fp2=fopen(filepath,"r");
        check=0;
        while(fscanf(fp2,"%d %s",&date,attendance_string) != EOF)
        {
            printf("%d %d\n",yyyymmdd,date);
            if(date==yyyymmdd)
            {
                check=1;
                break;
            }
        }
        fclose(fp2);
        if(check==0)
        {
            printf("\nDate does not Exists");
            getch();
            system("cls");
            showattendance(subject,firstname,middlename,lastname,path,actual_pass);
        }


        /////
        cnt=0;
        i=0;
        int present=0;
        int absent=0;

        printf("Attendance Update:-");
        printf("\nDate : %d / %d / %d \n\n",dd, mm, yyyy);
        printf("Attendance Status:\n");
        printf("========================================================================================================================\n\t");
        for(i=0,j=0;i<number_of_students;i++,j++)
        {
            ch='A';
            fscanf(fp1,"%d %s %s %s %s",&scaned_PRN,first_name,middle_name,last_name,student_pass);
            if(attendance_string[i]=='1')
            {
                ch='P';
                present++;
            }
            else
            {
                absent++;
            }
            printf("%d - %c\t",scaned_PRN,ch);
            if( j == 7 )
            {
                printf("\n\t");
                j=0;
            }
        }
        printf("\n========================================================================================================================\n");
        printf("\n\tTotal present : %d\n\tTotal absent : %d\n\tTotal : %d",present,absent,present+absent);
        fclose(fp1);
        printf("\n\tChoose your option : ");
        printf("\n\t\t1. Search Again");
        printf("\n\t\t2. Go back");
        printf("\n\t\tOption : ");
        i=0;
        while(1)
        {
            ch=getch();
            if(ch == 13 && i == 1)
            {
                break;
            }
            else if(ch == 8 && i==1)
            {
                i--;
                printf("\b \b");
            }
            else if(ch > '0' && ch < '3' && i == 0)
            {
                printf("%c",ch);
                opt = ch - '0';
                i++;
            }
        }
        switch(opt)
        {
            case 1:
                system("cls");
                goto again_to_search_date;
                break;
            case 2:
                showattendance(subject,firstname,middlename,lastname,path,actual_pass);//parameters are of teacher
                break;
        }

        //
    }

}
void list_student(char* subject,char* firstname,char* middlename,char* lastname,char* path,char* actual_pass)
{
    system("cls");
    FILE *listofstudent;
    int cnt=1,PRN;
    char first_name[75],middle_name[25],last_name[25],password[25];
    listofstudent = fopen("Admin/studdata.txt","r");
    if( listofstudent == NULL)
    {
        printf("File is empty\nPlease create new database");
        getch();
        exit(3);
        //main_menu();
    }
    printf("List of students");
    printf("\n================");
    printf("\n========================");
    printf("\n\t%10s %-10s %-75s \n","Sr. No.","PRN","Student Information");
    while(fscanf(listofstudent,"%d %s %s %s %s",&PRN,first_name,middle_name,last_name,password) != EOF)
    {
        strcat(first_name," ");
        strcat(first_name,middle_name);
        strcat(first_name," ");
        strcat(first_name,last_name);
        printf("\t%10d %-10d %-75s\n",cnt,PRN,first_name);
        cnt++;
    }
    fclose(listofstudent);
    getch();
    teacherlogined(subject,firstname,middlename,lastname,path,actual_pass);
    return;
}


#endif // TEACHER_H_INCLUDED
