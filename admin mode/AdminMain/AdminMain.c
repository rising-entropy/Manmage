#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int stud_enter();
int admin()
{
    //clrscr();
    char pass[10], s[10];
    FILE *filePointer; 
    filePointer = fopen("password.txt", "r");
    fscanf(filePointer, "%s", &pass);
    printf("\nEnter ADMIN password: ");
    scanf("%s", &s);
    fclose(filePointer);
    if(strcmp(s, pass) == 0)
    adminwin1();
    else
    {
    	int opt;
        printf("Invalid Password.\n\n");
        printf("What you want to Do:\n");
        printf("\t1. Try Again.\n");
        printf("\t2. Go Back.\n\n\t");
        printf("Your Choice: ");
        scanf("%d", &opt);
        switch(opt){
        	case(1):
        		main();
        		break;
        	case(2):
        		exit(1); //change this to actual main later
        		break;
        	default:
        		printf("\nInvalid Choice.\n");
        		main();
        		break;
        	}
    }
    
}
int adminwin1()
{
    printf("\n\n\n=========================================================");
    printf("\nWelcome to Admin Mode.\n");
    printf("=========================================================");
    printf("\nPress Any Key to Continue...\n\n\n");
    getch();
    adminwin2();
}
int adminwin2()
{
	//getch();
	int opt;
	printf("What you wanna Do:\n");
        printf("\t1. Change Password.\n");
        printf("\t2. Create new database.\n");
        printf("\t3. Go Back.\n\n\t");
        scanf("%d", &opt);
        switch(opt){
        	case(1):
        		adminpasschange();
        		break;
        	case(2):
        		create_db();
        		break;
        	case(3):
        		exit(1); //change it in main codebase
        		break;
        	default:
        		printf("\nInvalid Choice.\n");
        		adminwin2();
        		break;
        	}
}
int adminpasschange()
{
	char s[10], s1[10];
	printf("\nEnter New Password: ");
	scanf("%s", &s);
	printf("\nRe-enter New Password: ");
	scanf("%s", &s1);
	if(strcmp(s, s1)==0)
	{
		FILE *filePointer; 
    	filePointer = fopen("password.txt", "w");
    	fprintf(filePointer, "%s",s);
    	printf("\nPassword Changed Successfully!\n");
    	printf("\nPress Any Key to Continue...\n");
    	getch();
		adminwin2();
	}
	else
	{
		printf("\nInvalid Password.");
		printf("\nSending you back.");
		printf("\nPress Any Key to Continue...\n");
		getch();
		adminwin2();
	}
}
int create_db()
{
	char c;
	printf("\nAre you Sure?\nPress 'Y' to proceed else Go Back\n");
	//scanf("%c", &c);
	//if(c == 'Y')
	real_create_db();
	//else
	//adminwin1();
	//exit(1);
	//return 0;
}
int real_create_db()
{
	int stud, tea;
	printf("\nEnter Number of Students: ");
	scanf("%d", &stud);
	printf("\nEnter Number of Subjects: ");
	scanf("%d", &tea);
	FILE *filePointer ; 
	filePointer= fopen("studnum.txt", "w");
	fprintf (filePointer, "%d",stud);
	fclose(filePointer);
	filePointer= fopen("teanum.txt", "w");
	fprintf (filePointer, "%d",tea);
	fclose(filePointer);
	stud_enter();
}
int stud_enter()
{
	int num;
	struct Student
	{
		int prn;
		char stu_name[20];	
	};
	int i;
	FILE *filePointer ; 
	filePointer= fopen("studnum.txt", "r");
	fscanf(filePointer, "%d",num);
	fclose(filePointer);
	filePointer= fopen("studdata.txt", "w");
	struct Student s[num];
	for(i=0; i<num; i++)
	{
		int prn;
		char stu_name[20];
		printf("\nEnter PRN of %d student: ", i+1);
		scanf("%d", &prn);
		printf("\nEnter Name of %d student: ", i+1);
		scanf("%s", &stu_name);
		fprintf(filePointer, "%d %s\n", prn, stu_name);
	}
	fclose(filePointer);
	tea_enter();
}
int tea_enter()
{
	int num;
	struct Teacher
	{
		char subject[20];
		char tea_name[20];	
	};
	int i;
	FILE *filePointer ; 
	filePointer= fopen("teanum.txt", "r");
	fscanf(filePointer, "%d",num);
	fclose(filePointer);
	filePointer= fopen("teadata.txt", "w");
	struct Teacher t[num];
	for(i=0; i<num; i++)
	{
		char subject[20];
		char tea_name[20];
		printf("\nEnter Name of %d Subject: ", i+1);
		scanf("%s", &subject);
		printf("\nEnter Name of %d Subject Teacher: ", i+1);
		scanf("%s", &tea_name);
		fprintf(filePointer, "%s %s\n", subject, tea_name);
	}
	fclose(filePointer);
}
int main()
{
    admin();
}
