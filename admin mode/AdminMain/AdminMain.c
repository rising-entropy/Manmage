#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
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
        printf("What you wanna Do:\n");
        printf("\t1. Try Again.\n");
        printf("\t2. Go Back.\n\n\t");
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
    printf("=========================================================");
    printf("\nWelcome to Admin Mode.\n");
    printf("=========================================================");
    printf("\nPress Any Key to Continue...\n");
    getch();
    adminwin2();
}
int adminwin2()
{
	int opt;
	printf("What you wanna Do:\n");
        printf("\t1. Change Password.\n");
        printf("\t2. Create the database.\n");
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
	exit(1);
}
int main()
{
    admin();
}
