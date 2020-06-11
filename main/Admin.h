#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
/////////////////

///

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
void Admin()
{
    system("cls");
    char inputed_pass[25], actual_pass[25];
    int i=0;
    char ch;
    FILE *filePointer;
    filePointer = fopen("Admin/password.txt", "r");
    fscanf(filePointer, "%s", &actual_pass);
    printf("\nEnter ADMIN password: ");
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
    //scanf("%s", &inputed_pass);
    fclose(filePointer);
    if(strcmp(actual_pass, inputed_pass) == 0)
        adminwin1();
    else
    {
    	int opt;
    	i=0;
        printf("\nInvalid Password.\n\n");
        printf("What you want to Do:\n");
        printf("\t1. Try Again.\n");
        printf("\t2. Go Back.\n\n\t");
        printf("Your Choice: ");
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
}

void adminwin1()
{
	system("cls");
	int opt,i=0;
	char ch;
	printf("\n=========================================================");
    printf("\n Welcome to Admin Mode.\n");
    printf("=========================================================");
	printf("\n\n Choose your option :\n");
        printf(" \t1. Change Password.\n");
        printf(" \t2. Create new database.\n");
        printf(" \t3. Show list of subject.\n");
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
        		exit(1); //change it in main codebase
        		break;

        }
}
void adminpasschange()
{
	char string1[10], string2[10];
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
		FILE *filePointer;
    	filePointer = fopen("Admin/password.txt", "w");
    	fprintf(filePointer, "%s",string1);
    	printf("\nPassword Changed Successfully!\n");
    	printf("\nPress Any Key to Continue...\n");
    	getch();
		adminwin1();
	}
	else
	{
		printf("\nInvalid Password.");
		printf("\nSending you back.");
		printf("\nPress Any Key to Continue...\n");
		getch();
		adminwin1();
	}
}
void create_db()
{
	char c,garbage;
	scanf("%c", &garbage);//because of new line scan issue
	printf("\nAre you Sure?\nPress 'Y' to proceed else any other key to Go Back\n");
	scanf("%c", &c);
	getch();
	if(c == 'Y' || c == 'y')
        real_create_db();
	else
        adminwin1();
}
void real_create_db()
{
	int student_number=0,teacher_number=0,i=0;
	char ch;
	printf("\nEnter Number of Students: ");
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

	printf("\nEnter Number of Subjects: ");
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
	/*filePointer= fopen("teanum.txt", "w");
	fprintf (filePointer, "%d",tea);
	fclose(filePointer);*/
	student_data_enter();
}

void student_data_enter()
{
	int num;
	int i,j=0,k,z;
    char ch;
	FILE *filePointer ;
	filePointer= fopen("Admin/student_and_teacher_number.txt", "r");
	fscanf(filePointer, "%d",&num);
	fclose(filePointer);
	filePointer= fopen("Admin/studdata.txt", "w");
	int *student_PRN_array=malloc(sizeof(int)*num);
	for(i=0; i<num; i++)
	{

        int z;

		char student_password[25];
		char stu_firstname[20],stu_middlename[20],stu_lastname[20];
		again:
		printf("\nEnter PRN of %dth student(only integer value): ", i+1);
		//scanf("%d", &prn);
		///
		int prn=0;
		k=0;
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
                printf("\n Already exists\n");
                goto again;
            }
        }
        *(student_PRN_array+j)=prn;
        j++;
		printf("\nEnter Name of %dth with PRN %d student: ", i+1,prn);
		printf("\n\tFirst name : ");
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
		///
		//scanf("%s", &stu_firstname);
		printf("\n\tMiddle name : ");
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
		//scanf("%s", &stu_middlename);
		printf("\n\tLast name : ");
		//scanf("%s", &stu_lastname);
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
	printf("Teacher and Subject details\n\n");
	int num1,num2;
	int k;
	FILE *filePointer ;
	filePointer= fopen("Admin/student_and_teacher_number.txt", "r");
	fscanf(filePointer, "%d %d",&num1,&num2);
	fclose(filePointer);
	filePointer= fopen("Admin/teadata.txt", "w");
	for(k=0; k<num2; k++)
	{
		char subject[20],path[30]="Admin/",ch;

		int i=0,check;
		char tea_firstname[20],tea_middlename[20],tea_lastname[20],password[20];
		printf("\nEnter Name of %dth Subject: ",k+1);
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
		//scanf("%s", &subject);
		printf("\nEnter Name of %dth Subject Teacher: ", k+1);
		printf("\n\tFirst name : ");
		//scanf("%s", &tea_firstname);
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
		printf("\n\tMiddle name : ");
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
		printf("\n\tLast name : ");
		//scanf("%s", &tea_lastname);
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
    FILE *listofsubject;
    int cnt=1;
    char subject[25],firstname[75],middlename[25],lastname[25],password[25],path[50];
    listofsubject = fopen("Admin/teadata.txt","r");
    if( listofsubject == NULL)
    {
        printf("File is empty\nPlease create new database");
        getch();
        adminwin1();
    }
    printf("LIst of students");
    printf("\n-------------------------------");
    printf("\n--------------------------");
    printf("\n\t%10s %-20s %-45s\n","Sr. No.","Subject","Teacher Information");
    while( fscanf(listofsubject,"%s %s %s %s %s %s",subject,firstname,middlename,lastname,path,password) != EOF)
    {
        strcat(firstname," ");
        strcat(firstname,middlename);
        strcat(firstname," ");
        strcat(firstname,lastname);
        printf("\t%10d %-20s %-45s\n",cnt,subject,firstname);
        cnt++;
    }
    getch();
    adminwin1();

}
void list_student()
{
    system("cls");
    FILE *listofstudent;
    int cnt=1,PRN;
    char firstname[75],middlename[25],lastname[25],password[25];
    listofstudent = fopen("Admin/studdata.txt","r");
    if( listofstudent == NULL)
    {
        printf("File is empty\nPlease create new database");
        getch();
        adminwin1();
    }
    printf("List of students");
    printf("\n================");
    printf("\n========================");
    printf("\n\t%10s %-10s %-75s \n","Sr. No.","PRN","Student Information");
    while(fscanf(listofstudent,"%d %s %s %s %s",&PRN,firstname,middlename,lastname,password) != EOF)
    {
        strcat(firstname," ");
        strcat(firstname,middlename);
        strcat(firstname," ");
        strcat(firstname,lastname);
        printf("\t%10d %-10d %-75s\n",cnt,PRN,firstname);
        cnt++;
    }
    getch();
    adminwin1();
}



///
///


#endif // ADMIN_H_INCLUDED
