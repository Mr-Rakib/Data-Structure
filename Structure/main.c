#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int   id;
    char  name[50];
    int  class_name;
    char  address[50];
};


void printProfile( struct Student st )
{
    printf( "ID: %d\t NAME: %s\t CLASS: %d\t ADDRESS: %s\n", st.id, st.name, st.class_name, st.address);
}


int main( )
{
/*
    struct Student s;
    s.id = 10;
    strcpy(s.name,"Rakib Hasan");
    s.class_name = 10;
    strcpy(s.address,"Dhaka, Bangladesh");

    printProfile(s);
*/
    struct Student st[2];

    for(int x=0; x<2; x++)
    {
        printf("Enter the ID: ");
        scanf("%d", &st[x].id);

        printf("Enter the NAME: ");
        scanf("%s", &st[x].name);

        printf("Enter the CLASS: ");
        scanf("%d", &st[x].class_name);

        printf("Enter the ADDRESS: ");
        scanf("%s", &st[x].address);

        printf("---------------------------\n");
    }


    for(int s=0; s<2; s++)
    {
        printProfile(st[s]);
    }

    return 0;
}
