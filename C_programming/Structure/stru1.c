#include <stdio.h>
#define SUB 3

typedef struct
{
    char name[50];
    int roll;
    int marks[3];
} student;

void printStud(student s[], int);
void inputStu(student s[], int);

int main()
{
    int n;
    printf("Enter the no. of student: ");
    scanf("%d", &n);

    student stud[n];
    void printStud(stud, n);
    void inputStu(stud, n);
    return 0;
}

void inputStu(student s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n---- Student %d ----\n", i + 1);
        printf("\nEnter name: ");
        scanf("%[^\n]s", s[i].name);
        printf("Enter the roll: ");
        scanf("%d", &s[i].roll);
        for (int j = 0; j < SUB; j++)
        {
            printf("Enter subject %d marks: ", j + 1);
            scanf("%d", &s[i].marks[j]);
        }
    }
}

void printStud(student s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n---- Student Record ----\n");
        printf("\nName: %s", s[i].name);
        printf("\nName: %d", s[i].roll);
        for (int j = 0; j < SUB; j++)
        {
            printf("Marks: %d", s[i].marks[j]);
        }
    }
}