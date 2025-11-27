#include <stdio.h>
#include "score_management.h"

int main(void)
{
    Student stu[MAX_N];
    int n=0;

    n=load_students(stu);

    int choice=-1;

    do
    {
        printf("Menu(please enter a number)\n"
            "1.Display all students\n"
            "2.Add student \n"
            "3.Delete student\n"
            "4.Sort and display by subject\n"
            "5.Search by student ID\n"
            "6.Search by name\n"
            "0.Save and Exit\n");

        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            {
                print_students(stu,n);
                break;
            }
            case 2:
            {
                int t=0;
                Student input=(Student){0};
                printf("Enter the number of students you want to add:");
                scanf("%d",&t);
                printf("Enter your data\n");
                for (size_t i = 0; i < t; i++)
                {
                    scanf(" %s %s %lf %lf %lf",
                        input.id,input.name,//数组名就是地址无需&
                        &input.math,&input.english,
                        &input.moral);
                    add_student(stu,&n,input);
                }
                break;
            }
            case 3:
            {
                printf("Enter this student's id\n");
                char id[10]="";
                scanf(" %s",id);
                delete_student(stu,&n,id);
                break;
            }
            case 4:
            {
                int su=0; 
                printf("1-math 2-English 3-moral 4-total score,please enter\n");
                scanf("%d",&su);
                sort_students(stu,n,su);
                break;
            }
            case 5:
            {
                char s_id[10]="";
                printf("Please enter the student id:");
                scanf(" %s",s_id);
                search_by_id(stu,n,s_id);
                break;
            }
            case 6:
            {
                char s_name[10]="";
                printf("Please enter the student's name:");
                scanf(" %s",s_name);
                search_by_name(stu,n,s_name);
                break;
            }
            case 0:
            {
                break;
            }
            default:
            {
                printf("Invalid input\n");
            }
        }
    } while (choice!=0);
    
    save_students(stu,n);

    return 0;
}

