
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

