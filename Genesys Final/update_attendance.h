#ifndef UPDATE_ATTENDANCE_H_INCLUDED
#define UPDATE_ATTENDANCE_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

void update_attendance(char *path)
{
    system("cls");
    int i, j, k,present,absent;
    int number_of_students;
    int check;

    int dd = 0, mm = 0, yyyy = 0, yyyymmdd=0;//input date
    char ch;//tmp char
    char filepath[50];

    FILE *f_attendance_sheet,*f_rollno_sheet,*f_student_count ;
    f_student_count=fopen("Admin/student_and_teacher_number.txt","r");
    if(f_student_count == NULL)
    {
        printf("\nPlease Create Database.");
        printf("\nPress Any Key to Continue...\n");
        getch();
        exit(1);               //later main_menu
    }
    fscanf(f_student_count,"%d",&number_of_students);
    fclose(f_student_count);
    date_enter:                       //for re-entering date
    strcpy(filepath,path);
    printf("Enter Data:\n");

    dd = day_enter();
    mm = month_enter();
    yyyy = year_enter();
    // date inputed
    check=is_valid_date(dd, mm, yyyy);
    switch(check)
    {
    case -1:
        printf("\nInvalid Day...\nPlease Re-Enter.");
        printf("\nPress Any Key to Continue...\n");
        getch();
        system("cls");
        goto date_enter;
    case -2:
        printf("\nInvalid Month...\nPlease Re-Enter.");
        printf("\nPress Any Key to Continue...\n");
        getch();
        system("cls");
        goto date_enter;
    default:
        system("cls");
    }
    // Date part complete
    /*
    check date
    */
    printf("Attendance Update:-");
    printf("\nDate : %d / %d / %d \n\n",dd, mm, yyyy);
    yyyymmdd+=yyyy*10000;
    yyyymmdd+=mm*100;
    yyyymmdd+=dd;
    strcat(filepath,"Attendance Sheet.txt");
    check=is_already_exist(yyyymmdd,filepath);
    if(check == 1)
    {
        printf("\nInput Date Already Exists.\nPress 'Y' To Re-Enter Date.");
        printf("\nPress Any Key to Continue...\n");
        again_try:
        ch=getch();
        if(ch == 13)
            goto again_try;
        else if(ch =='y' || ch =='Y')
        {
            system("cls");
            goto date_enter;
        }
        else
            exit(0);//change to back page later
    }
    else if(check == 0)
    {
        f_attendance_sheet=fopen(filepath,"a+");
    }
    else if(check == 2)
    {
        f_attendance_sheet=fopen(filepath,"w");
    }

    f_rollno_sheet=fopen("Admin/studdata.txt","r");

    int cnt=0,tmp_roll,scaned_rollno;
    char *attendance_string=malloc(sizeof(char)*(number_of_students+1));
    char first_name[20],middle_name[20],last_name[20],student_pass[25];
    for(cnt=0;cnt<number_of_students;cnt++)
        attendance_string[cnt]='1';
    attendance_string[cnt]='\0';

    attendance_status_page:
    cnt=0;
    i=0;
    present=0;
    absent=0;
    printf("Attendance Status:\n");
    printf("========================================================================================================================\n\t");
    for(i=0,j=0;i<number_of_students;i++,j++)
    {
        ch='A';
        fscanf(f_rollno_sheet,"%d %s %s %s %s",&scaned_rollno,first_name,middle_name,last_name,student_pass);
        if(attendance_string[i]=='1')
        {
            ch='P';
            present++;
        }
        else
        {
            absent++;
        }
        printf("%d - %c\t",scaned_rollno,ch);
        if( j == 7)
        {
            printf("\n\t");
            j=0;
        }
    }
    printf("\n========================================================================================================================\n");
    printf("\n\tTotal Present: %d\n\tTotal Absent: %d\n\tTotal: %d",present,absent,present+absent);
    rewind(f_rollno_sheet);
    i=0;
    printf("\nEnter Roll Number(s) one-by-one.\nEnter '0' to complete the entries.");
    while(1)
    {
        printf("\nEnter Roll No. to Change Status:");
        i=0;
        tmp_roll=0;
        while(1)
        {
            ch=getch();
            if(ch == 13 && i > 0)
            {
                break;
            }
            else if(ch == 8 && i>0)
            {
                while(i != 0)
                {
                    printf("\b \b");
                    i--;
                }
                tmp_roll=0;
            }
            else if( ch >= '0' && ch <= '9')
            {
                i++;
                tmp_roll*=10;
                tmp_roll+= (ch-'0');
                printf("%c",ch);
            }
        }
        if(tmp_roll == 0)
        {
            printf("\nSave the Attendance?\n\tFor YES press 'Y' \n\tFor NO press 'N'");
            again_check:
            ch=getch();
            if(ch == 13)
                goto again_check;
            else if(ch =='N'|| ch =='n')
            {
                fclose(f_rollno_sheet);
                fclose(f_attendance_sheet);
                FILE *fp;
                char subject[20],firstname[20],middlename[20],lastname[20],fpath[20],actual_pass[20];
                fp=fopen("Admin/teadata.txt", "r");
                while( fscanf(fp,"%s %s %s %s %s %s",subject,firstname,middlename,lastname,fpath,actual_pass) != EOF)
                {
                    if(!strcmp(fpath,path))
                    {
                        fclose(fp);
                        teacherlogined(subject,firstname,middlename,lastname,path,actual_pass);
                        return;
                    }
                }// go to teacherlogined in teacher.c
            }
            else if( ch == 'Y' || ch == 'y')
            {
                fprintf(f_attendance_sheet,"%d %s\n",yyyymmdd,attendance_string);
                ///
                //sort_date(yyyymmdd,attendance_string,path,number_of_students);
                printf("\nAttendance Updated Successfully!");
                printf("\nPress Any Key to Continue...\n");
                getch();
                fclose(f_rollno_sheet);
                fclose(f_attendance_sheet);
                FILE *fp;
                char subject[20],firstname[20],middlename[20],lastname[20],fpath[20],actual_pass[20];
                fp=fopen("Admin/teadata.txt", "r");
                while( fscanf(fp,"%s %s %s %s %s %s",subject,firstname,middlename,lastname,fpath,actual_pass) != EOF)
                {
                    if(!strcmp(fpath,path))
                    {
                        fclose(fp);
                        teacherlogined(subject,firstname,middlename,lastname,path,actual_pass);// go to teacherlogined in teacher.c
                        return;
                    }
                }
            }
            else
                goto again_check;
        }
        cnt=1;
        while(fscanf(f_rollno_sheet,"%d %s %s %s %s",&scaned_rollno,first_name,middle_name,last_name,student_pass) != EOF)
        {

            if(tmp_roll == scaned_rollno)
            {
                if(attendance_string[cnt-1]== '1')
                {
                    attendance_string[cnt-1]='0';
                    printf("\nAttendance Updated for Roll No. %d: Absent",tmp_roll);
                }
                else
                {
                    attendance_string[cnt-1]='1';
                    printf("\nAttendance Updated for Roll No. %d: Present",tmp_roll);
                }
                printf("\nPress Any Key to Continue...\n");
                getch();
                break;
            }
            cnt++;
        }
        rewind(f_rollno_sheet);
        if(cnt>number_of_students)
        {
            printf("\nInvalid Roll Number");
            printf("\nPress Any Key to Continue...\n");
            getch();
        }
        system("cls");
        printf("Attendance Update:-");
        printf("\nDate: %d / %d / %d \n\n",dd, mm, yyyy);
        goto attendance_status_page;
    }
    getch();
    free(attendance_string);
    return ;
}
/*
function to enter day...
*/
int day_enter()
{
    int i=0,dd=0;
    char ch;
    printf("Date(DD):");
    while(i <= 2)
    {
        ch=getch();
        if(i > 0 && ch == 13)
            break;
        else if(ch == 8 && i > 0)
        {
            i--;
            printf("\b \b");
            if(i == 0)
                dd = 0;
            else if(i == 1)
            {
                dd = dd / 10;
            }
        }
        else if(ch >= '0' && ch <= '9' && i < 2)
        {

            printf("%c",ch);
            if(i == 0)
                dd += (ch-48);
            else if(i == 1)
            {
                dd = dd * 10;
                dd += (ch-48);
            }
            i++;
        }
    }
    return dd;
}
/*
function to enter month...
*/
int month_enter()
{
    int i=0,mm=0;
    char ch;
    printf("\nMonth(MM):");
    while(i <= 2)
    {
        ch = getch();
        if(i > 0 && ch == 13)
            break;
        else if(ch == 8 && i > 0)
        {
            i--;
            printf("\b \b");
            if(i == 0)
                mm = 0;
            else if(i == 1)
            {
                mm = mm / 10;
            }
        }
        else if(ch >= '0' && ch <= '9' && i < 2)
        {
            if(i == 0)
                mm += (ch-48);
            else if(i == 1)
            {
                mm = mm * 10;
                mm += (ch-48);
            }
            printf("%c",ch);
            i++;
        }
    }
    return mm;
}
/*
function to enter year...
*/
int year_enter()
{
    int i=0,yyyy=0,j=1,flag=0;
    char ch;
    printf("\nYear(YYYY):");
    while(i <= 4)
    {
        again:
        ch=getch();
        if(flag==0 && i==0)
        {
            if(ch=='0')//to avoid enter 0000 as a year
                goto again;
            else if(ch>='1' && ch<='9')
            {
                flag=1;
            }
        }
        if(i == 4 && ch == 13)
            break;
        else if(ch==8 && i>0)
        {
            i--;
            printf("\b \b");
            if(i == 0)
            {
                yyyy = 0;
                flag=0;
            }
            else
            {
                yyyy=yyyy/10;
            }
        }
        else if(ch >= '0' && ch<= '9' && i < 4 )
        {
            if(i != 0)
                yyyy *= 10;
            yyyy += (ch-48);
            printf("%c",ch);
            i++;
        }
    }
    return yyyy;
}
/*
function to check date...
*/
int is_valid_date(int dd, int mm, int yyyy)
{
    int is_leap_year=0;
    if(yyyy % 4 == 0 && (yyyy % 100 != 0) || (yyyy % 400 == 0))
        is_leap_year=1;//leap year confirm
    if( mm > 0 && mm <= 12)
    {
        switch(mm)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(dd > 0 && dd <= 31)
                return 0;// Valid date...
            break;
        case 2:
            if((dd > 0 && dd <=28) || (is_leap_year && dd == 29 ))
                return 0;//Valid date...
            break;
        default:
            if(dd>0 && dd <= 30)
                return 0;//Valid date...
        }
        return -1;//Invalid day...
    }
    else
        return -2;//Invalid month...
}
int is_already_exist(int yyyymmdd,char *filepath)
{
    char ch,attendance[1000];
    int date;
    FILE *f_attendance_sheet;
    f_attendance_sheet=fopen(filepath,"r");
    if(f_attendance_sheet == NULL)
    {
        fclose(f_attendance_sheet);
        f_attendance_sheet=fopen(filepath,"w");
        fclose(f_attendance_sheet);
        return 2;
    }
    while( fscanf( f_attendance_sheet,"%d %s",&date,attendance) != EOF )
    {
        if(date == yyyymmdd)
        {
            fclose(f_attendance_sheet);
            return 1;//date found
        }
    }
    fclose(f_attendance_sheet);
    return 0;//date not found
}

/*void sort_date(int yyyymmdd,char* attendance_string,char *path,int number_of_students)
{
    FILE *fp1,*fp2;//one for original and 2nd for tmp file
    char file1[50],file2[50],*attendance=malloc(sizeof(char)*(number_of_students+1));
    int date,flag=0;//flag for to update in tmp file check purpose
    strcpy(file1,path);
    strcpy(file2,path);
    strcat(file1,"Attendance Sheet.txt");
    strcat(file2,"Attendance Sheet_tmp.txt");
    fp1=fopen(file1,"r");
    fp2=fopen(file2,"w");
    while(fscanf( fp1,"%d %s",&date,attendance) != EOF)
    {
        if(date>yyyymmdd && flag==0)
        {
            fprintf(fp2,"%d %s\n",yyyymmdd,attendance_string);
            flag=1;
        }
        fprintf(fp2,"%d %s\n",date,attendance);
    }
    fclose(fp1);
    fclose(fp2);
    free(attendance);
    if(remove(file1))
        printf("error1\n");
    rename(file2,file1);
    return ;
}*/



#endif // UPDATE_ATTENDANCE_H_INCLUDED
