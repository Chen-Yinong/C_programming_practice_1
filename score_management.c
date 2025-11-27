#include <stdio.h>
#include <string.h>//头文件无需，.c里有即可
#include "score_management.h"

int load_students(Student stu[])
{
    FILE *fp=fopen("student.txt","r");
    if (fp==NULL)
    {
        printf("The file doesn't exist ,new file will be created .\n");
        return 0;
    }
    
    int n=0;

    while (fscanf(fp,"%s %s %lf %lf %lf",
        stu[n].id,stu[n].name,//数组名就是地址无需&
        &stu[n].math,&stu[n].english,
        &stu[n].moral)!=EOF)//逗号处可换行，避免一行太长
    {
        n++;
    }
    
    fclose(fp);
    fp=NULL;
    return n;
}

void save_students(Student stu[],int n)
{
    FILE *fp = fopen("student.txt","w");
    if (fp==NULL)
    {
        printf("Fail to open file for writing .\n");
        return;
    }
    
    for (size_t i = 0; i < n; i++)
    {
        fprintf(fp,"%s %s %lf %lf %lf\n",
            stu[i].id,stu[i].name,
            stu[i].math,stu[i].english,
            stu[i].moral
        );
    }
    
    fclose(fp);
    fp=NULL;
}

void print_students(Student stu[],int n)
{
    printf("ID        Name      Math   English  Moral\n");
    for (size_t i = 0; i < n; i++)
    {
        printf("%s %s %lf %lf %lf\n",
            stu[i].id,stu[i].name,
            stu[i].math,stu[i].english,
            stu[i].moral);
    }
}

void add_student(Student stu[],int* n,Student newdata)
{
    for (size_t i = 0; i < *n; i++)
    {
        if (strcmp(stu[i].id,newdata.id)==0)
        {
            printf("Duplicate student ID detected,operation denied\n");
            return;
        }
    }
    stu[*n]=newdata;
    (*n)++;
}

void delete_student(Student stu[],int *n,
    char a[])
{
    int t=-1;
    for (size_t i = 0; i < *n; i++)
    {
        if (strcmp(stu[i].id,a)==0)
        {
            t=i;
            break;
        }
    }

    if (t==-1)
    {
        printf("The specified student cannot be found\n");
        return;
    }
    
    stu[t]=(Student){0};
    for (size_t i = t; i < *n-1; i++)
    {
        stu[i]=stu[i+1];
    }
    (*n)--;
}

double score_get(Student stu,
    int s)
{
    //1-math 2-English 3-moral 4-total score
    if (s==1)
    {
        return stu.math;
    }
    else if (s==2)
    {
        return stu.english;
    }
    else if (s==3)
    {
        return stu.moral;
    }
    else if (s==4)
    {
        return stu.math+stu.english+stu.moral;
    }
    else
    {
        printf("Required subject does not exist\n");
        return 0.0;
    }
}

void sort_students(Student stu[],int n,
    int subject)
{
    //1-math 2-English 3-moral 4-total score
    Student sorted_stu[n],t=(Student){0};
    for (size_t i = 0; i < n; i++)
    {
        sorted_stu[i]=stu[i];
    }
    for (size_t i = 0; i < n-1; i++)
    {
        for (size_t j = 0; j < n-1; j++)
        {
            if (score_get(sorted_stu[j],subject)
            <score_get(sorted_stu[j+1],subject))
            {
                t=sorted_stu[j];
                sorted_stu[j]=sorted_stu[j+1];
                sorted_stu[j+1]=t;
            }
            
        }
    }
    print_students(sorted_stu,n);
}

void search_by_id(Student stu[],int n,
    char id[])
{
    for (size_t i = 0; i < n; i++)
    {
        if (strcmp(stu[i].id,id)==0)
        {
            printf("ID        Name      Math   English  Moral\n");
            printf("%s %s %lf %lf %lf\n",
            stu[i].id,stu[i].name,
            stu[i].math,stu[i].english,
            stu[i].moral);
            return;
        }
        
    }
    printf("Not found\n");
}

void search_by_name(Student stu[],int n,
    char name[])
{
    int t=0;//是否找到
    for (size_t i = 0; i < n; i++)
    {
        if (strcmp(stu[i].name,name)==0)
        {
            printf("ID        Name      Math   English  Moral\n");
            printf("%s %s %lf %lf %lf\n",
            stu[i].id,stu[i].name,
            stu[i].math,stu[i].english,
            stu[i].moral);
            t=1;
        }
        
    }
    if(t==0)
    {
        printf("Not found\n");
    }
}
