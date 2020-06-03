#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
void stud_enter();
void admin()
{
    //clrscr();
    system("cls");
    char pass[10], s[10];
    int i=0;
    char ch;
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
        		main();
        		break;
        	case(2):
        		exit(1); //change this to actual main later
        		break;

        }
    }


}
void adminwin1()
{
    system("cls");
    printf("\n\n\n=========================================================");
    printf("\nWelcome to Admin Mode.\n");
    printf("\n=========================================================");
    printf("\nPress Any Key to Continue...\n\n\n");
    getch();
    adminwin2();
}

void adminwin2()
{
	system("cls");
	int opt,i=0;
	char ch;
	printf("\n=========================================================");
    printf("\n Welcome to Admin Mode.\n");
    printf("=========================================================");
	printf("\n\n What you wanna Do:\n");
        printf(" \t1. Change Password.\n");
        printf(" \t2. Create new database.\n");
        printf(" \t3. Go Back.\n\n\t");
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
        	case(3):
        		exit(1); //change it in main codebase
        		break;

        }
}
void adminpasschange()
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

void stud_enter()
{
	int num;
	int i;
	FILE *filePointer ;
	filePointer= fopen("studnum.txt", "r");
	fscanf(filePointer, "%d",&num);
	fclose(filePointer);
	filePointer= fopen("studdata.txt", "w");
	for(i=0; i<num; i++)
	{
		int prn;
		char stu_name[20];
		printf("\nEnter PRN of %d student: ", i+1);
		char stu_firstname[20],stu_middlename[20],stu_lastname[20];
		printf("\nEnter PRN of %d student(only integer value): ", i+1);
		scanf("%d", &prn);
		printf("\nEnter Name of %d student: ", i+1);
		printf("\n\tFirst name : ");
		scanf("%s", &stu_firstname);
		printf("\tMiddle name : ");
		scanf("%s", &stu_middlename);
		printf("\tLast name : ");
		scanf("%s", &stu_lastname);
		fprintf(filePointer, "%d %s %s %s\n", prn, stu_firstname,stu_middlename,stu_lastname);
	}
	fclose(filePointer);
	tea_enter();
}
void tea_enter()
{
	system("cls");
	printf("Teacher and Subject details\n\n");
	int num;
	int i;
	FILE *filePointer ;
	filePointer= fopen("teanum.txt", "r");
	fscanf(filePointer, "%d",&num);
	fclose(filePointer);
	filePointer= fopen("teadata.txt", "w");
	for(i=0; i<num; i++)
	{
		char subject[20];
		char tea_firstname[20],tea_middlename[20],tea_lastname[20];
		printf("\nEnter Name of %d Subject: ", i+1);
		scanf("%s", &subject);
		printf("\nEnter Name of %d Subject Teacher: ", i+1);
		printf("\n\tFirst name : ");
		scanf("%s", &tea_firstname);
		printf("\tMiddle name : ");
		scanf("%s", &tea_middlename);
		printf("\tLast name : ");
		scanf("%s", &tea_lastname);
		fprintf(filePointer, "%s %s %s %s\n", subject, tea_firstname ,tea_middlename,tea_lastname);
	}
	fclose(filePointer);
}
int main()
{
    admin();
    return 0;
}
