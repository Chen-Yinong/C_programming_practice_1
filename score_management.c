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
        if (stu[i].id==newdata.id)
        {
            printf("Duplicate student ID detected,operation denied\n");
            return;
        }
    }
    stu[*n]=newdata;
    *n++;
    free(n);
    n=NULL;
}

void deleta_student(Student stu[],int *n,
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
        free(n);
        n=NULL;
        return;
    }
    
    stu[t]=(Student){0};
    for (size_t i = t; i < *n-1; i++)
    {
        stu[i]=stu[i+1];
    }
    *n--;
    free(n);
    n=NULL;
}

