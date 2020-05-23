#include<math.h>
#include<stdio.h>
//#include<conio.h>
void CGPA()
{
    int d_subjects, d_sumcred=0, d_total=0;
    printf("Enter the Number of Subjects: ");
    scanf("%d", &d_subjects);                    //including practicals etc not non-credit subjects
    for(int i=1; i<=d_subjects; i++)
    {
        int credit;
        int grade;
        printf("\nEnter grade for Subject No. %d: ", i); // prompt to get of the form AA = 10
        scanf("%d", &grade);
        if(grade>10 || grade<0 || grade==3 || grade==2 || grade==1)
        {
            printf("\nInvalid Grade.");
            break;
        }
        printf("\nEnter Credits for Subject No. %d: ", i);
        scanf("%d", &credit);
        d_sumcred = d_sumcred + credit;
        d_total = d_total + grade*credit;
    }
    double d_cgpa = (float)d_total/(float)d_sumcred;
    printf("Your CGPA is: %.2lf", d_cgpa);
}

int main()
{
    CGPA();
}