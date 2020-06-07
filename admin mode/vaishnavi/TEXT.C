#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{int gd=DETECT,gm,font=10;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 setcolor(LIGHTGREEN);
 settextstyle(1,0,2);
 outtextxy(20,20,"WELCOME TO..");
 settextstyle(font,0,4);
 outtextxy(40,60,"ATTENDENCE MANAGER ");
 settextstyle(11,0,2);
 outtextxy(300,300,"POJECT BY:ONKAR GAVALI");
 outtextxy(380,310,"DEVANG KAMBLE");
 outtextxy(380,320,"VAISHNAVI BELGAMWAR");
 outtextxy(300,340,"MENTORS:NISHI BHATE");
 outtextxy(360,350,"ABHISHEK MORE");
 setcolor(9);
 //person1
 circle(181,225,30);
 arc(181,295,0,180,40);
 line(141,295,221,295);
 //peron2
 circle(40,225,30);
 arc(40,295,0,180,40);
 line(0,295,80,295);
 //person3
 circle(110,205,28);
 arc(110,269,0,180,36);
 line(74,269,146,269);
 getch();
 delay(100);
 cleardevice();
 closegraph();
 return;
}