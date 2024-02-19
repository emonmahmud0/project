#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student record
struct Student
{
    char name[50];
    int id;
    char depertment[100];
    float CGPA;
    char phone[12];
    char gmail[40];
    char address[100];
    char blood_group[5];

    struct Student *next;
    struct Student *prev;
};

typedef struct Student student;
student *newStudent, *temp, *head;


//Home page of project
void home_secreen()
{
    printf("\t\t\tWelcome to student record management\n\n\n");
    printf("\t\t\t1. Add Student Record\n");
    printf("\t\t\t2. Display Student Records\n");
    printf("\t\t\t3. Search Student Record\n");
    printf("\t\t\t4. Delete Student Record\n");
    printf("\t\t\t5. Display Gold medelists Records(Those who have got CGPA-4.00)\n");
    printf("\t\t\t0. Exit\n");
    printf("\n\n");
}

//get input for new student
void get_input()
{
    printf("\t\t\tEnter all Information for adding student:\n\n");
    getchar();
    printf("\t\t\tEnter student's name: ");
    gets(newStudent->name);

    printf("\t\t\tEnter student id    : ");
    scanf("%d",&newStudent->id);

    getchar();
    printf("\t\t\tEnter depertment    : ");
    gets(newStudent->depertment);

    printf("\t\t\tEnter CGPA.         : ");
    scanf("%f",&newStudent->CGPA);

    getchar();
    printf("\t\t\tEnter Phone Number  : ");
    gets(newStudent->phone);

    printf("\t\t\tEnter gmail address : ");
    gets(newStudent->gmail);

    printf("\t\t\tEnter adress        : ");
    gets(newStudent->address);

    printf("\t\t\tEnter blood group   : ");
    gets(newStudent->blood_group);

    printf("\n\n\t\t\tStudent added successfully......\n\n");
}

// for show one student inforation
void show(student *sh)
{
    printf("\t\t\tName        : %s\n",sh->name);
    printf("\t\t\tID          : %d\n",sh->id);
    printf("\t\t\tDepertment  : %s\n",sh->depertment);
    printf("\t\t\tCGPA        : %.2f\n",sh->CGPA);
    printf("\t\t\tPhone       : %s\n",sh->phone);
    printf("\t\t\tEmail       : %s\n",sh->gmail);
    printf("\t\t\tAddress     : %s\n",sh->address);
    printf("\t\t\tBlood group : %s\n",sh->blood_group);
}

//for display all student information
void full_display()
{
    //system("clear");   //for macbook
    system("cls");       //for windows
    
    printf("\n\t\t\tDisplay Student Records\n\n\n");

    if(head == NULL)
    {
        printf("\t\t\tNo student found in record\n");
    }
    student *dis;
    dis = head;

    int count = 1;

    while(dis != NULL)
    {
        printf("\n\n\t\tStudent:%d->\n\n",count++);
        show(dis);
        dis = dis->next;
    }
}

//Add student record
void add_student()
{
    printf("\n\t\t\tAdd Student Record\n\n\n");

    newStudent = (student*)malloc(sizeof(student));
    newStudent->prev = NULL;
    newStudent->next = NULL;
    get_input();

    if(head == NULL)
    {
        head = newStudent;
        temp = head;
    }
    else
    {
        temp->next = newStudent;
        newStudent->prev = temp;
        temp = temp->next;
    }
}

//Search student by id
void search()
{
    printf("\n\t\t\tSearch Student Record\n\n\n");
    int num;
    printf("\n\t\t\tPlz enter student ID to search information: ");
    scanf("%d",&num);

    printf("\n\n\n\t\tInformation for searching student ->\n\n");
    student *src = head;

    while(src != NULL)
    {
        if(num == src->id)
        {
            show(src);
            return;
        }
        src = src->next;
    }
}

//delete student by id
void delete()
{
    printf("\n\t\t\tDelete Student Record\n\n\n");
    int num;
    printf("\n\t\t\tPlz enter student ID to delete information: ");
    scanf("%d",&num);

    student *current,*del,*before,*after;

    if(head->id == num)
    {
        current = head;
        head = head->next;
        free(current);
        return;
    }

    del = head;

    while(del != NULL)
    {
        if(num == del->id)
        {
            current = del;
            if(current->next == NULL)
            {
                before = current->prev;

                before->next = NULL;
                free(current);
            }
            else
            {
                before = current->prev;
                after = current->next;

                before->next = after;
                after->prev = before;
                free(current);
            }
        }
        del = del->next;
    }
}

void show_goldmedelist()
{
    printf("\n\t\t\tDisplay Gold medelists Records(Those who have got CGPA-4.00)\n\n\n");

    int count = 1;
    student *sh = head;
    while(sh != NULL)
    {
        if(sh->CGPA == 4.00)
        {
            printf("\n\n\t\tStudent:%d->\n\n",count++);
            show(sh);
        }
        sh = sh->next;
    }
}

int main()
{
    head = NULL;

    while(1)
    {
        //system("clear");   //for macbook
        system("cls");       //for windows
        home_secreen();

        int opt;
        printf("\n\t\t\tEnter your choice: ");
        scanf("%d",&opt);

        switch(opt)
        {
            case 1:
                //system("clear");   //for macbook
                system("cls");       //for windows
                add_student();
                break;

            case 2:
                //system("clear");   //for macbook
                system("cls");       //for windows
                full_display();
                getchar();
                break;

            case 3:
                //system("clear");   //for macbook
                system("cls");       //for windows
                search();
                getchar();
                break;

            case 4:
                //system("clear");   //for macbook
                system("cls");       //for windows
                delete();
                printf("\n\n\t\t\tDelete information succefully.....\n\n\n");
                getchar();
                break;

            case 5:
                //system("clear");   //for macbook
                system("cls");       //for windows
                show_goldmedelist();
                getchar();
                break;

            case 0:
                printf("\n\n\t\t\tThank You for Stay with us.....\n\n");
                return 0;

        }
        printf("\n\n\t\t\tPress any key to continue....");
        getchar();
    }

    return 0;
}

