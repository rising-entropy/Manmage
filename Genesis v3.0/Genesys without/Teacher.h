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
void display_teacher_line();
void teacherlogined(char*,char*,char*,char*,char*,char*);
void teacherpasswordchange(char* ,char* ,char*,char*,char*,char* );
void showattendance(char*,char*,char*,char*,char* path,char*);
void list_student_t(char*,char* ,char* ,char*,char*,char*);
void Teacher()
{
    system("cls");
    display_teacher_line();
    char inputed_pass[25], actual_pass[25],inputed_subject[25];
    char subject[25],firstname[75],middlename[25],lastname[25],path[50];
    int i=0,opt;
    char ch;
    FILE *filePointer;
    filePointer = fopen("Admin/teadata.txt", "r");
    if(filePointer== NULL)                               //if the file is absent or database not added
    {
        printf("\n\tCreate Database.");
        printf("\n\tPress any key to Continue...");
        getch();
        main_menu();
    }
    printf("\n\tEnter Subject Name: ");
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
    printf("\n\tEnter Password: ");
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
            printf("*",ch);
            inputed_pass[i]=ch;
            i++;
        }
    }
    while( fscanf(filePointer,"%s %s %s %s %s %s",subject,firstname,middlename,lastname,path,actual_pass) != EOF)///Teacher data
    {
        if(!strcmp(inputed_pass,actual_pass) && !strcmp(inputed_subject,subject) )
        {
            fclose(filePointer);
            teacherlogined(subject,firstname,middlename,lastname,path,actual_pass);
            break;
        }
    }
    fclose(filePointer);
    printf("\n\tChoose Your Option.\n\n");
    printf("\n\tChoose your option :\n");
    printf("\t\t1. Try Again.\n");
    printf("\t\t2. Go Back.\n\n\t");
    printf("\tYour Choice: ");
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
        main_menu();
        break;
    }
     main_menu();
}
void teacherlogined(char* subject,char* firstname,char* middlename,char* lastname,char* path,char* actual_pass)
{
    system("cls");
    display_teacher_line();
	int opt,i=0;
	char ch;
	printf("\n\t==============================================================================================================");
    printf("\n\tWelcome to Teacher Mode.");
    printf("\n\t==============================================================================================================");
	printf("\n\n\t Choose Your Option :\n");
    printf("\t\t1. Change Password.\n");
    printf("\t\t2. Update Attendance\n");
    printf("\t\t3. Show Attendance.\n");
    printf("\t\t4. Show the List of Students.\n");
    printf("\t\t5. Go Back.\n\n\t");
    printf("\tYour Choice: ");
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
        		update_attendance(subject,firstname,middlename,lastname,path,actual_pass);
        		break;
            case 3:
                showattendance(subject,firstname,middlename,lastname,path,actual_pass);
                break;
            case 4:
                list_student_t(subject,firstname,middlename,lastname,path,actual_pass);
                break;
        	case(5):
        		main_menu();
        		break;
        }
        teacherlogined(subject,firstname,middlename,lastname,path,actual_pass);
}
void teacherpasswordchange(char* subject,char* firstname,char* middlename,char* lastname,char* path,char* actual_pass)
{
    system("cls");
    display_teacher_line();
    printf("\n\t|| CHANGE PASSWORD ||");
    char string1[20], string2[20];
	int i=0;
	char ch;
	printf("\n\n\tEnter New Password: ");
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
            printf("*",ch);
            string1[i]=ch;
            i++;
        }
    }
	printf("\n\n\tRe-Enter New Password: ");
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
            printf("*",ch);

            string2[i]=ch;
            i++;
        }
    }
	if(strcmp(string1, string2)==0)     //both the passwords match and hence pass is changed
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
        printf("\nPassword Updated Successfully!");
        printf("\nPress Any Key to Continue...\n");
    }
    else
    {
        printf("\n\n\tInvalid Password.");
		printf("\n\tSending you back.");
		printf("\n\tPress Any Key to Continue...\n");
		getch();
		teacherlogined(subject,firstname,middlename,lastname,path,actual_pass);
    }
    getch();
    teacherlogined(subject,firstname,middlename,lastname,path,string1);
    return;
}

void showattendance(char* subject,char* firstname,char* middlename,char* lastname,char* path,char* actual_pass)
{
    system("cls");
    display_teacher_line();
    FILE *fp;
    int i=0,opt=0,flag=0,number_of_students;
    char ch;
    char filepath[50];//to specify file location
    strcpy(filepath,path);
    strcat(filepath,"Attendance Sheet.txt");
    printf("\n\n\tChoose Your Option:");
    printf("\n\t\t1. Search by PRN.");
    printf("\n\t\t2.Search by Date.");
    printf("\n\t\t3.Go back.");
    printf("\n\t\tYour Choice: ");
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
    if(fp == NULL)                                          //to check if file exists
    {
        printf("\n\tPlease create database");
        getch();
        printf("\n\tPress Any Key to Continue.");
        main_menu();
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
        display_teacher_line();
        printf("\n\t|| SEARCH BY PRN ||\n");
        printf("\n\tEnter PRN : ");
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
        FILE *fp1,*fp2;                           ///1st for student data and 2nd for attendance sheet and for scanf number of students
        cnt=1;                                    ///initialize to 1st position
        fp1=fopen("Admin/studdata.txt","r");
        while(fscanf(fp1,"%d %s %s %s %s",&scaned_PRN,first_name,middle_name,last_name,student_pass) != EOF)
        {
            if(prn==scaned_PRN)
            {
                check=1;                          //to notify PRN find in further code
                fclose(fp1);
                int check_data=0;///to see empty file
                int cnt_present=0,cnt_absent=0,total=0,date;//need in below function
                char *attendance=malloc(sizeof(char)*(number_of_students+1));
                float per_present=0,per_absent=0;
                fp2=fopen(filepath,"r");
                while(fscanf(fp2,"%d %s",&date,attendance) != EOF)
                {
                    check_data=1;
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
                per_present=(((float)cnt_present)/total)*100.0;
                per_absent=100.00-per_present;
                if(check_data==0)
                {
                    cnt_present=0;cnt_absent=0;total=0;
                    per_present=0;per_absent=0;
                }
                printf("\n\t==============================================================================================================");
                printf("\n\t* Name of the Student: %s %s %s",first_name,middle_name,last_name);
                printf("\n\n\t* PRN: %d",scaned_PRN);
                printf("\n\n\t* Total Number of Lectures: %d",total);
                printf("\n\n\t\tPresent: %d\n\tAbsent: %d",cnt_present,cnt_absent);

                printf("\n\t %% Present: %0.2f%%",per_present);
                printf("\n\t %% Absent: %0.2f%%",per_absent);
                printf("\n\n\tPress Any Key to Continue...\n");
                getch();
                //show details ended
                printf("\n\n\tChoose Your Option :");
                printf("\n\t\t1. Search Again.");
                printf("\n\t\t2. Go Back");
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
                    goto again_to_search_PRN;
                    break;
                case 2:
                   showattendance(subject,firstname,middlename,lastname,path,actual_pass);       //parameters of the teacher
                   break;
                }
                break;
            }
            cnt++;                //count to specify attendance position
        }
        if(check==0)
        {
            printf("\n\tInvalid PRN");
            printf("\n\tPress Any Key to Continue...\n");
            getch();
            system("cls");
            goto again_to_search_PRN;
        }

    }
    else
    {
        system("cls");
        int dd=0,mm=0,yyyy=0,yyyymmdd=0,check,cnt=1,j,scaned_PRN,date;                    //DD MM YYYY;
        char first_name[20],middle_name[20],last_name[20],student_pass[25];
        char *attendance_string=malloc(sizeof(char)*(number_of_students+1));
        again_to_search_date:
        date_enter:
        display_teacher_line();
        printf("\n\t|| SEARCH BY DATE ||");
        dd=0;mm=0;yyyy=0;yyyymmdd=0;
        dd = day_enter();
        mm = month_enter();
        yyyy = year_enter();
        // date inputed
        check=is_valid_date(dd, mm, yyyy);
        switch(check)
        {
        case -1:
            printf("\n\tInvalid Day...\n\tPlease Re-Enter");
            printf("\n\tPress any key to Continue.\n");
            getch();
            system("cls");
            goto date_enter;
        case -2:
            printf("\n\tInvalid Month...\n\tPlease Re-Enter");
            printf("\n\nPress any key to Continue.\n");
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
            if(date==yyyymmdd)
            {
                check=1;
                break;
            }
        }
        fclose(fp2);
        if(check==0)
        {
            printf("\n\tDate Does Not Exist");
            printf("\n\tPress Any Key to Continue...\n");
            getch();
            system("cls");
            showattendance(subject,firstname,middlename,lastname,path,actual_pass);
        }
        cnt=0;
        i=0;
        int present=0;
        int absent=0;
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
        printf("\n\tTotal Present: %d\n\tTotal Absent: %d\n\tTotal: %d",present,absent,present+absent);
        fclose(fp1);
        printf("\n\tChoose Your Option: ");
        printf("\n\t\t1. Search Again: ");
        printf("\n\t\t2. Go Back: ");
        printf("\n\t\tYour Choice: ");
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
                showattendance(subject,firstname,middlename,lastname,path,actual_pass);//Parameters of the Teacher
                break;
        }

        //
    }

}
void list_student_t(char* subject,char* firstname,char* middlename,char* lastname,char* path,char* actual_pass)
{
    system("cls");
    display_teacher_line();
    FILE *listofstudent;
    int cnt=1,PRN;
    char first_name[75],middle_name[25],last_name[25],password[25];
    listofstudent = fopen("Admin/studdata.txt","r");
    if( listofstudent == NULL)
    {
        printf("File is Empty.\nCreate New Database.");
        printf("\nPress Any Key to Continue...\n");
        getch();
        main_menu();
    }
    printf("\n\t|| LIST OF STUDENTS ||\n");
    printf("\n\t%10s || %-10s || %-75s ||\n","Sr. No.","PRN","Student Information");
    printf("\t==========================================================================================================\n");
    while(fscanf(listofstudent,"%d %s %s %s %s",&PRN,first_name,middle_name,last_name,password) != EOF)
    {
        strcat(first_name," ");
        strcat(first_name,middle_name);
        strcat(first_name," ");
        strcat(first_name,last_name);
        printf("\t%10d || %-10d || %-75s ||\n",cnt,PRN,first_name);
        cnt++;
    }
    printf("\t==========================================================================================================");
    fclose(listofstudent);
    getch();
    teacherlogined(subject,firstname,middlename,lastname,path,actual_pass);
    return;
}
void display_teacher_line()
{
    printf("\n\n");
    printf("\t* TEACHER MODE *");
    printf("\n\t==============================================================================================================\n");
    return;
}

#endif // TEACHER_H_INCLUDED
