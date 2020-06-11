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

int main()
{
    int check;
    FILE *filePointer;
    display_main_page();//by header file
    system("cls");
    system("color f1");
    check = mkdir("Admin");
    filePointer = fopen("Admin/password.txt", "r");
    if(filePointer == NULL)
    {
        filePointer = fopen("Admin/password.txt","w");
        fprintf(filePointer,"%s\n","admin");
    }
    fclose(filePointer);
    main_menu();//by header file
    return 0;
}
