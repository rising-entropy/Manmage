#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
/////////////////
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include"main_menu.h"

void teacher_data_enter();
void adminwin1();
void adminpasschange();
void create_db();
void real_create_db();
void student_data_enter();
void list_subject();
void list_student();
void display_admin_line();
void remove_old();

void Admin()
{
    system("cls");
    display_admin_line();
    char inputed_pass[25], actual_pass[25];
    int i=0;
    int opt;
    char ch;
    FILE *filePointer;
    ///
    /*
    declaration completed
    */
    ///
    filePointer = fopen("Admin/password.txt", "r");
    fscanf(filePointer, "%s", &actual_pass);
    printf("\n\n\tEnter ADMIN password: ");
    while(1)///i is already initialize to zero
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
    fclose(filePointer);
    if(strcmp(actual_pass, inputed_pass) == 0)
        adminwin1();
    else
    {
    	i=0;
        printf("\n\tInvalid Password.\n\n");
        printf("\tWhat you want to Do:\n");
        printf("\t\t1. Try Again.\n");
        printf("\t\t2. Go Back.\n\n\t");
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
        		Admin();
        		break;
        	case(2):
        		main_menu(); //change this to actual main later
        		break;

        }
    }
    Admin();
}

void adminwin1()
{
	system("cls");
	display_admin_line();
	int opt,i=0;
	char ch;
	printf("\n\t==============================================================================================================");
    printf("\n\t Welcome to Admin Mode.\n");
    printf("\t==============================================================================================================");
	printf("\n\n\t Choose your option :\n");
        printf("\t\t1. Change Password.\n");
        printf("\t\t2. Create New Database.\n");
        printf("\t\t3. Show the List of Subjects.\n");
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
        		adminpasschange();
        		break;
            case(2):
        		create_db();
        		break;
            case 3:
                list_subject();
                break;
            case 4:
                list_student();
                break;
        	case(5):
        		main_menu();
        		break;

        }
        adminwin1();
}
void adminpasschange()
{
	system("cls");
	display_admin_line();
	char string1[10], string2[10];
	int i=0;
	char ch;
	printf("\t|| ADMIN PASSWORD CHANGE ||");
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
	printf("\n\tRe-Enter New Password: ");
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
	if(strcmp(string1, string2)==0)
	{
		FILE *filePointer;
    	filePointer = fopen("Admin/password.txt", "w");
    	fprintf(filePointer, "%s",string1);
    	fclose(filePointer);
    	printf("\n\tPassword Changed Successfully!\n");
    	printf("\n\tPress Any Key to Continue.\n");
    	getch();
		adminwin1();
	}
	else
	{
		printf("\n\tInvalid Password.");
		printf("\n\tSending you back.");
		printf("\n\tPress Any Key to Continue...\n");
		getch();
		adminwin1();
	}
}
void create_db()
{
	char c,extra;
	scanf("%c",&extra);///extra new line issue
	printf("\nAre you Sure?\nPress 'Y' to proceed else any other key to Go Back\n");
	scanf("%c", &c);
	if(c == 'Y' || c == 'y')
        real_create_db();
	else
    {
        adminwin1();
    }
}
void real_create_db()
{
	system("cls");
	display_admin_line();
	int student_number=0,teacher_number=0,i=0;
	char ch;
	printf("\n\tEnter Number of Students: ");
	///
	while(1)
        {
            ch=getch();
            if(ch == 13 && i > 0)
            {
                break;
            }
            else if(ch == 8 && i>0)
            {
                i--;
                printf("\b \b");
                student_number/=10;
            }
            else if(ch >='0' && ch <='9')
            {
                if(ch== '0' && i==0)
                    continue;
                printf("%c",ch);
                student_number*=10;
                student_number+= ch - 48;
                i++;
            }
        }
	///

	printf("\n\n\tEnter Number of Subjects: ");
	//scanf("%d", &tea);
	///
	i=0;
	while(1)
        {
            ch=getch();
            if(ch == 13 && i > 0)
            {
                break;
            }
            else if(ch == 8 && i>0)
            {
                i--;
                printf("\b \b");
                teacher_number/=10;
            }
            else if(ch >= '0' && ch <= '9')
            {
                if(ch== '0' && i==0)
                    continue;
                printf("%c",ch);
                teacher_number*=10;
                teacher_number+= ch - 48;
                i++;
            }
        }
	///

	FILE *filePointer ;
	filePointer= fopen("Admin/student_and_teacher_number.txt", "w");
	fprintf (filePointer,"%d %d",student_number,teacher_number);
	fclose(filePointer);
	remove_old();///to remove old directory
	student_data_enter();
}
void remove_old()
{
    char subject[25],tea_firstname[25],tea_middlename[25],tea_lastname[25],path[50],tea_password[25];
    char filepath[50];///to store attendance sheet.txt filp path
    FILE *fp1;///to open teadata
    fp1=fopen("Admin/teadata.txt","r");
    if(fp1==NULL)
    {
        return;
    }
    while(fscanf(fp1,"%s %s %s %s %s %s",subject,tea_firstname,tea_middlename,tea_lastname,path,tea_password) != EOF)
    {
        strcpy(filepath,path);
        strcat(filepath,"Attendance Sheet.txt");
        remove(filepath);
        strcpy(filepath,"Admin/");
        strcat(filepath,subject);
        rmdir(filepath);
    }
    fclose(fp1);
    return;
}
void student_data_enter()
{
	int num;
	int i,j=0,k,z;
    char ch;
    display_admin_line();
	FILE *filePointer ;
	filePointer= fopen("Admin/student_and_teacher_number.txt", "r");
	fscanf(filePointer, "%d",&num);
	fclose(filePointer);
	filePointer= fopen("Admin/studdata.txt", "w");
	int *student_PRN_array=malloc(sizeof(int)*num);
	printf("\n\t|| STUDENT DATA ENTER ||");
	for(i=0; i<num; i++)
	{
        int prn=0;
		char student_password[25];
		char stu_firstname[20],stu_middlename[20],stu_lastname[20];
		again:
		printf("\n\n\tEnter PRN of %dth Student(Only Integer Value): ", i+1);
		k=0;
		prn=0;
        while(1)
        {
            ch=getch();
            if(ch == 13 && k > 0)
            {

                student_password[k]='\0';
                break;
            }
            else if(ch == 8 && k>0)
            {
                k--;
                printf("\b \b");
                prn/=10;
            }
            else if(ch >= '0' && ch <= '9')
            {
                if(ch== '0' && k==0)
                    continue;
                printf("%c",ch);
                student_password[k]=ch;
                prn*=10;
                prn+= ch - 48;
                k++;
            }
        }
		///
		for(k=0;k<j;k++)
        {
            if(prn == *(student_PRN_array+k))
            {
                printf("\n\tAlready Exists.");
                goto again;
            }
        }
        *(student_PRN_array+j)=prn;
        j++;
		printf("\n\tEnter Name of %dth with PRN %d Student: ", i+1,prn);
		printf("\n\t\tFirst Name: ");
		///
		z=0;
		while(1)
        {
            ch=getch();
            if(ch==13 && z>0)
            {
                stu_firstname[z]='\0';
                break;
            }
            else if(ch == 8 && z>0)
            {
                printf("\b \b");
                z--;
            }
            else if(ch>='a' && ch<='z' || ch>='A' && ch<='Z')
            {
                printf("%c",ch);
                stu_firstname[z]=ch;
                z++;
            }
        }
		printf("\n\t\tMiddle Name: ");
		z=0;
		while(1)
        {
            ch=getch();
            if(ch==13 && z>0)
            {
                stu_middlename[z]='\0';
                break;
            }
            else if(ch == 8 && z>0)
            {
                printf("\b \b");
                z--;
            }
            else if(ch>='a' && ch<='z' || ch>='A' && ch<='Z')
            {
                printf("%c",ch);
                stu_middlename[z]=ch;
                z++;
            }
        }
		printf("\n\t\tLast Name: ");
		z=0;
		while(1)
        {
            ch=getch();
            if(ch==13 && z>0)
            {
                stu_lastname[z]='\0';
                break;
            }
            else if(ch == 8 && z>0)
            {
                printf("\b \b");
                z--;
            }
            else if(ch>='a' && ch<='z' || ch>='A' && ch<='Z')
            {
                printf("%c",ch);
                stu_lastname[z]=ch;
                z++;
            }
        }
		fprintf(filePointer, "%d %s %s %s %s\n",prn,stu_firstname,stu_middlename,stu_lastname,student_password);
	}
	fclose(filePointer);
	teacher_data_enter();
}
void teacher_data_enter()
{
	system("cls");
	display_admin_line();
	int num1,num2;
	int k;
	FILE *filePointer ;
	printf("\n\t|| TEACHER AND SUBJECT DETAILS ||\n");
	filePointer= fopen("Admin/student_and_teacher_number.txt", "r");
	fscanf(filePointer, "%d %d",&num1,&num2);
	fclose(filePointer);
	filePointer= fopen("Admin/teadata.txt", "w");
	for(k=0; k<num2; k++)
	{
		char subject[20],path[30]="Admin/",ch;
		int i=0,check;
		char tea_firstname[20],tea_middlename[20],tea_lastname[20],password[20];
		printf("\n\tEnter Name of %dth Subject: ",k+1);
		i=0;
		while(1)
        {
            ch=getch();
            if(ch==13 && i>0)
            {
                subject[i]='\0';
                break;
            }
            else if(ch == 8 && i>0)
            {
                printf("\b \b");
                i--;
            }
            else if(ch>='a' && ch<='z' || ch>='A' && ch<='Z')
            {
                printf("%c",ch);
                subject[i]=ch;
                i++;
            }
        }
		printf("\n\tEnter Name of %dth Subject Teacher: ", k+1);
		printf("\n\t\tFirst Name : ");
		i=0;
		while(1)
        {
            ch=getch();
            if(ch==13 && i>0)
            {
                tea_firstname[i]='\0';
                break;
            }
            else if(ch == 8 && i>0)
            {
                printf("\b \b");
                i--;
            }
            else if(ch>='a' && ch<='z' || ch>='A' && ch<='Z')
            {
                printf("%c",ch);
                tea_firstname[i]=ch;
                i++;
            }
        }
		printf("\n\t\tMiddle Name : ");
		i=0;
		while(1)
        {
            ch=getch();
            if(ch==13 && i>0)
            {
                tea_middlename[i]='\0';
                break;
            }
            else if(ch == 8 && i>0)
            {
                printf("\b \b");
                i--;
            }
            else if(ch>='a' && ch<='z' || ch>='A' && ch<='Z')
            {
                printf("%c",ch);
                tea_middlename[i]=ch;
                i++;
            }
        }
		printf("\n\t\tLast Name : ");
		i=0;
		while(1)
        {
            ch=getch();
            if(ch==13 && i>0)
            {
                tea_lastname[i]='\0';
                break;
            }
            else if(ch == 8 && i>0)
            {
                printf("\b \b");
                i--;
            }
            else if(ch>='a' && ch<='z' || ch>='A' && ch<='Z')
            {
                printf("%c",ch);
                tea_lastname[i]=ch;
                i++;
            }
        }
        strcpy(password,subject);
		strcat(path,subject);
		check = mkdir(path);
		strcat(path,"/");
		fprintf(filePointer,"%s %s %s %s %s %s\n",subject,tea_firstname,tea_middlename,tea_lastname,path,password);
	}
	fclose(filePointer);
}
void list_subject()
{
    system("cls");
    display_admin_line();
    FILE *listofsubject;
    int cnt=1;
    char subject[25],firstname[75],middlename[25],lastname[25],password[25],path[50];
    listofsubject = fopen("Admin/teadata.txt","r");
    if( listofsubject == NULL)
    {
        printf("\n\tFile is empty.\nPlease create new database");
        printf("\n\tPress Any Key to Continue.\n");
        getch();
        adminwin1();
    }
    printf("\t|| LIST OF SUBJECT AND TEACHER ||");
    printf("\n\n\t%10s || %-20s || %-45s ||\n","Sr. No.","Subject","Teacher Information");
    printf("\t=======================================================================================\n");
    while( fscanf(listofsubject,"%s %s %s %s %s %s",subject,firstname,middlename,lastname,path,password) != EOF)
    {
        strcat(firstname," ");
        strcat(firstname,middlename);
        strcat(firstname," ");
        strcat(firstname,lastname);
        printf("\t%10d || %-20s || %-45s ||\n",cnt,subject,firstname);
        cnt++;
    }
    fclose(listofsubject);
    printf("\t=======================================================================================");
    printf("\n\n\nTask Completed Sucessfully!");
    printf("\nPress Any Key to Continue...\n");
    getch();
    adminwin1();

}
void list_student()
{
    system("cls");
    display_admin_line();
    FILE *listofstudent;
    int cnt=1,PRN;
    char firstname[75],middlename[25],lastname[25],password[25];
    listofstudent = fopen("Admin/studdata.txt","r");
    if( listofstudent == NULL)
    {
        printf("\n\tFile is Empty.\nCreate New Database.");
        printf("\n\tPress Any Key to Continue...\n");
        getch();
        adminwin1();
    }
    printf("\t|| LIST OF STUDENTS ||");
    printf("\n\n\t%10s || %-10s || %-75s ||\n","Sr. No.","PRN","Student Information");
    printf("\t==========================================================================================================\n");
    while(fscanf(listofstudent,"%d %s %s %s %s",&PRN,firstname,middlename,lastname,password) != EOF)
    {
        strcat(firstname," ");
        strcat(firstname,middlename);
        strcat(firstname," ");
        strcat(firstname,lastname);
        printf("\t%10d || %-10d || %-75s ||\n",cnt,PRN,firstname);
        cnt++;
    }
    fclose(listofstudent);
    printf("\t==========================================================================================================");
    printf("\n\n\nTask Completed Sucessfully!");
    printf("\nPress Any Key to Continue...\n");
    getch();
    adminwin1();
}

void display_admin_line()
{
    printf("\n\n");
    printf("\t* ADMIN MODE *");
    printf("\n\t==============================================================================================================\n");
    return;
}


#endif // ADMIN_H_INCLUDED
