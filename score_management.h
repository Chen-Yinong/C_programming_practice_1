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


#endif//一上来就写好了