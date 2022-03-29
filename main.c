#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
int courses=0;
struct course;
struct student;
typedef struct course *course;
typedef struct student *student;
void read(course clist,student slist);                              //function to read the files
course creatC();                                                    //function to creat empty node
student creatS();                                                   //function to creat empty node
void insertC(course l,course c);                                    //function to insert node to courses list
void insertS(student l,student s);                                  //function to insert node to student list
int available(course clist,char course_id[20],student s);           //function to check if the student can register in the course
void enroll(course c,student s);                                    //function to enroll the student in the course
course searchC(course clist,char course_id[20]);                    //function to search if the course is available this semester
void printC(course l,char course_id[20]);                           //function to print courses
int enrolled(course c);                                             //function to count # of students enrolled in a course
int waiting(course c);                                              //function to count # of students  in waiting list in a course
void searchS(course l,int student_id,char course_id[20]);           //function to search for students
void lessC(course clist);                                           //function to print courses with students # less than 5
void sortC(course clist);                                           //function to sort courses
void swapC(course c1, course c2);                                   //function to swap courses
void printSortedC(course clist);                                    //function to print sorted courses
void sortS(course clist);                                           //function to sort students
void swapS(course c,int i);                                         //function to swap students
void printSortedS(course clist);                                    //function to print sorted students
void menu();                                                        //menu function
int already(course c,student s,char token[20]);
struct course{                                                      //course struct
    char course_name[2000];
    char course_id[20];
    int year;
    int max_students;
    student enrolled[1000];
    student waiting[1000];
    course next;
};
struct student{                                                     //student struct
    char student_name[20];
    int student_id;
    char courses[999999];
    student next;
};
int main() {
    int op;
    char c[20];                                                             //to store course id entered by the user
    int id;                                                                 //to store student id entered by the user
    course clist = creatC();
    student slist = creatS();
    printf("Reading files");
    read(clist,slist);                                                      //read files
    menu();
    scanf("%d",&op);
    while (op!=6){
        switch (op) {                                                       //switch to call the function based on what user wants
            case 1:
                printSortedS(clist);
                break;
            case 2:
                printSortedC(clist);
                break;
            case 3:
                lessC(clist);
                break;
            case 4:
                printf("Please enter course ID:\n");
                scanf("%s",&c);
                printC(clist,c);
                break;
            case 5:
                printf("Please enter student ID:\n");
                scanf("%d",&id);
                printf("Please enter course ID:\n");
                scanf("%s",&c);
                searchS(clist,id,c);
                break;
            default:
                printf("Invalid option\n");
                break;
        }
        printf("-------------------------\n");
        menu();
        scanf("%d",&op);
    }

    return 0;
}
void read(course clist,student slist){
    FILE *ptr;
    char text[999]="";
    ptr = fopen("/home/hamza/Desktop/project1Data/Courses.txt","r");
    char *token;                                                                    //to divide each line in the file
    if(ptr==NULL){
        printf("Courses file not found\n");
    } else {
        while (fgets(text, 999, ptr) && ptr != EOF) {
            course c = creatC();                                                    //creat empty node
            token = strtok(text, ",");
            int index = 0;                                                          //to determine each field
            while (token != NULL ) {
                if(token != ""){                                                    //to prevent empty fields
                switch (index) {
                    case 0:                                                         //set course name
                        strcpy(c->course_name, token);
                        index++;
                        break;
                    case 1:                                                         //set course id
                        strncpy(c->course_id, token, 8);
                        index++;
                        break;
                    case 2:
                        c->year = atoi(token);                                      //set course year
                        index++;
                        break;
                    case 3:
                        c->max_students = atoi(token);                              //set course max student num.
                        if (!strncmp(c->course_id, "COMP", 4)) {                    //check if the course id is valid
                            insertC(clist, c);                                      //insert node to clist
                            courses++;
                        } else {
                            printf("Can't add course\n");
                        }
                        index++;
                        break;
                    default:
                        index = 0;
                        break;

                }
            }
                token = strtok(NULL, ",");
            }
        }

        fclose(ptr);
        ptr = fopen("/home/hamza/Desktop/project1Data/Students.txt", "r");
        if (ptr == NULL) {
            printf("Courses file not found");
        } else {
            while (fgets(text, 999, ptr) && ptr != EOF) {
                student s = creatS();
                token = strtok(text, "#");                                  //to divide each line in the file
                int index = 0;                                                    //to determine each field
                int courses = 0;
                while (token != NULL) {
                    if(token != "") {                                             //to prevent empty fields
                        switch (index) {
                            case 0:
                                strcpy(s->student_name, token);                   //set student name
                                index++;
                                break;
                            case 1:
                                s->student_id = atoi(token);                      //set student id
                                index++;
                                break;
                            case 2:
                                strcpy(s->courses, token);                      //set student course
                                if (available(clist, token, s) && courses < 5 && !already(clist,s,token) ) {        //check if the students can enroll the course
                                        enroll(searchC(clist, token), s);                   //enroll function
                                        courses++;
                                } else if (courses >= 5) {
                                    printf("can't register more than 5 courses to student %d\n", s->student_id);
                                }
                                break;
                            default:
                                index = 0;
                                break;
                        }

                        token = strtok(NULL, "#");
                    }
                }
            }

        }
    }
}
course creatC(){
    course c = (course)malloc(sizeof(struct course));
    c->next=NULL;
    return c;
}
student creatS(){
    student s = (student) malloc(sizeof (struct student));
    s->next = NULL;
    return s;
}
void insertC(course l,course c){
    if(c != NULL && l != NULL){
        c->next=l->next;
        l->next=c;
    }
}
void insertS(student l,student s){
    if(s != NULL && l != NULL){
        s->next=l->next;
        l->next=s;
    }
}
int available(course clist,char course_id[20],student s){
    course c = clist->next;
        while (c!= NULL){
            c = c->next;
            if(searchC(clist,course_id) != NULL && searchC(clist,course_id)->year >= (s->student_id/10000)){        //check if the course is available and the student can enroll in it
                return 1;
            }
        }
        if(searchC(clist,course_id)==NULL){
            printf("course %s not found\n",course_id);
        }else {
            printf("course %s is not available for student %d\n", course_id, s->student_id);
        }
    return 0;
}
course searchC(course clist,char course_id[20]){
    course c = clist->next;
        while (c != NULL){
            if((!strncmp(c->course_id,course_id,7) && strlen(c->course_id) == 7 ) || !strncmp(c->course_id,course_id,8) ){     //to ckeck if the course is in the clist based on course id
                return c;
            }
            c = c->next;
        }
    return NULL;
}
int enrolled(course c){
    int enrolled = 0;
    for(int i =0;i < 1000;i++){                  //to count the # of enrolled student
        if(c->enrolled[i] != NULL){
            enrolled++;
        }else{
            break;
        }
    }
    return enrolled;
}
int waiting(course c){
    int waiting = 0;
    for(int i =0;i < 1000;i++){                 //to count the # of waiting student
        if(c->waiting[i] != NULL){
            waiting++;
        }else{
            break;
        }
    }
    return waiting;
}
void enroll(course c,student s){
    if(enrolled(c) < c->max_students){
        c->enrolled[enrolled(c)] = s;
        printf("Student %d enrolled in course %s\n",s->student_id,c->course_id);
    } else {
        c->waiting[waiting(c)] = s;
        printf("Course %s is full student %d added to waiting list\n",c->course_id,s->student_id);
    }
}

void printC(course l,char course_id[20]){
    FILE *fp= fopen("/home/hamza/Desktop/project1Data/Search course.txt","w");       //file pointer
    course c = searchC(l,course_id);                                                                //to search for the entered course
    if(c != NULL){
        for(int i = 0; i< enrolled(c);i++){
            printf("%s %d\n",c->enrolled[i]->student_name,c->enrolled[i]->student_id);
            fprintf(fp,"%s %d\n",c->enrolled[i]->student_name,c->enrolled[i]->student_id);
        }
    }else
        printf("Course %s not found\n",course_id);
    fclose(fp);
}
void searchS(course l,int student_id,char course_id[20]){
    FILE *fp= fopen("/home/hamza/Desktop/project1Data/Search student","w");
    course c = searchC(l,course_id);
    int reg=0;                                                                                      //a var as a flag if the student is in the course
    if(c != NULL){
        for(int i=0; i<enrolled(c); i++){
            if(c->enrolled[i]->student_id == student_id){                                           //if student found -> reg = 1
                reg=1;
            }
        }
        if(reg){
            printf("Student %d is registered in course %s\n",student_id,course_id);
            fprintf(fp,"Student %d is registered in course %s\n",student_id,course_id);
        } else if(!reg) {
            printf("Student %d is not registered in course %s\n", student_id, course_id);
            fprintf(fp, "Student %d is not registered in course %s\n", student_id, course_id);
        }
    }else
        printf("Course %s not found\n",course_id);
    fclose(fp);
}
void lessC(course clist){
    course c = clist->next;
    int num=1;
    FILE *fp = fopen("/home/hamza/Desktop/project1Data/Courses with student number less than 5.txt","w");
    while(c != NULL){
        if(enrolled(c) < 5){                                                        //check if enrolled students is less than 5
            printf("%d- %s-%s\n",num,c->course_id,c->course_name);
            fprintf(fp,"%d- %s-%s\n",num,c->course_id,c->course_name);
            num++;
        }
        c=c->next;
    }
    fclose(fp);
}
void sortC(course clist){
    for(int i=0;i<courses-1 ;i++) {
        struct course *c = clist->next;
            while (c->next != NULL) {
                if (strcmp(c->course_name, c->next->course_name) > 0) {                         //check if the nodes needs to be swapped
                    swapC(c, c->next);
                }
                c = c->next;
            }
    }
}
void swapC(struct course *c1,struct course *c2){
    //swap nodes by swapping data
    char course_id[20];
    char course_name[2000];
    int year;
    int max_students;
    student enrolled[1000];
    student waiting[1000];
    for(int i=0;i < 1000;i++){
        enrolled[i] = c1->enrolled[i];
        waiting[i] = c1->waiting[i];
        c1->enrolled[i] = c2->enrolled[i];
        c1->waiting[i] = c2->waiting[i];
        c2->enrolled[i] = enrolled[i];
        c2->waiting[i] = waiting[i];
    }
    strcpy(course_id,c1->course_id);
    strcpy(c1->course_id,c2->course_id);
    strcpy(c2->course_id,course_id);
    strcpy(course_name,c1->course_name);
    strcpy(c1->course_name,c2->course_name);
    strcpy(c2->course_name,course_name);
    year=c1->year;
    c1->year=c2->year;
    c2->year=year;
    max_students=c1->max_students;
    c1->max_students=c2->max_students;
    c2->max_students=max_students;
}
void printSortedC(course clist){
    FILE *fp = fopen("/home/hamza/Desktop/project1Data/Course list.txt","w");
    sortC(clist);
    course c = clist->next;
    while (c != NULL){
        printf("Course name: %s\n",c->course_name);
        printf("Course ID: %s\n",c->course_id);
        printf("Year : %d\n",c->year);
        printf("max # of students: %d\n",c->max_students);
        printf("# of enrolled students: %d\n", enrolled(c));
        printf("# of students in waiting list: %d\n", waiting(c));
        printf("---------------\n");
        fprintf(fp,"Course name: %s\n",c->course_name);
        fprintf(fp,"Course ID: %s\n",c->course_id);
        fprintf(fp,"Year : %d\n",c->year);
        fprintf(fp,"max # of students: %d\n",c->max_students);
        fprintf(fp,"# of enrolled students: %d\n", enrolled(c));
        fprintf(fp,"# of students in waiting list: %d\n", waiting(c));
        fprintf(fp,"---------------\n");
        c = c->next;
    }
    fclose(fp);
}
void sortS(course clist){
    course c = clist->next;
    while(c != NULL){
        for(int j = 0;j< enrolled(c);j++) {
            for (int i = 0; i < enrolled(c) - 1; i++) {
                if (c->enrolled[i]->student_id > c->enrolled[i + 1]->student_id) {           //check if the nodes needs to be swapped
                    swapS(c, i);
                }
            }
        }
        c= c->next;
    }

}
void swapS(course c,int i){
    student temp =c->enrolled[i];
    c->enrolled[i]=c->enrolled[i+1];
    c->enrolled[i+1] = temp;
}
void printSortedS(course clist){
    FILE *fp;
    fp= fopen("/home/hamza/Desktop/project1Data/Student list.txt","w");
    sortS(clist);
    course c = clist->next;
    while (c!=NULL){
        printf("---------------\n");
        printf("%s - %s\n",c->course_name,c->course_id);
        printf("---------------\n");
        for (int i =0;i< enrolled(c);i++){
            printf("%d %s\n",c->enrolled[i]->student_id,c->enrolled[i]->student_name);
        }
        fprintf(fp,"---------------\n");
        fprintf(fp,"%s - %s\n",c->course_name,c->course_id);
        fprintf(fp,"---------------\n");
        for (int i =0;i< enrolled(c);i++){
            fprintf(fp,"%d %s\n",c->enrolled[i]->student_id,c->enrolled[i]->student_name);
        }
        c =c->next;
    }
    fclose(fp);
}
void menu(){
    printf("-------------------------\n");
    printf("Choose an option\n");
    printf("1-Print students list on each course\n");
    printf("2-Print course list\n");
    printf("3-Print courses with students less than 5\n");
    printf("4-Search for a course\n");
    printf("5-Search for a student in a course\n");
    printf("6-Exit\n");
    printf("-------------------------\n");
}
int already(course c,student s,char token[20]){
    course c1 = searchC(c,token);
    for(int i =0 ; i<enrolled(c1);i++){
        if(c1->enrolled[i]->student_id == s->student_id){
            return 1;
        }
    }
    for(int i =0 ; i< waiting(c1);i++){
        if(c1->enrolled[i]->student_id == s->student_id){
            return 1;
        }
    }
    return 0;
}