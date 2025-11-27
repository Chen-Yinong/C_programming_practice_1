#ifndef SCORE_MANAGEMENT_H
#define SCORE_MANAGEMENT_H

typedef struct 
{
    char id[10];
    char name[10];
    double math;
    double english;
    double moral;
}Student;

int load_students(Student stu[]);

void save_students(Student stu[],int n);

void print_students(Student stu[],int n);

void add_student(Student stu[],int* n,Student newdata);

void delete_student(Student stu[],int *n,
    char a[]);

double score_get(Student stu,
    int subject);

void sort_students(Student stu[],int n,
    int subject);

void search_by_id(Student stu[],int n,
    char id[]);

void search_by_name(Student stu[],int n,
    char name[]);

#endif//一上来就写好了