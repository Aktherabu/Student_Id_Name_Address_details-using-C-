//Program to demonstrate Addition deletion and updation of student data using C program
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

void strt();
void add();
void display();
void search_student();
void delete_student();
void update_student();

struct data
{
    int id;
    char name[25];
    char address[30];
}s;

void main()
{
    strt();
    getch();
}

void strt()
{
    system("CLS");
    int c;
    printf("\n\n");
    printf("\n\t------Select Your Preference------\n");
    printf("(1)\tAdd Student\n");
    printf("(2)\tView All Student's\n");
    printf("(3)\tSearch Student\n");
    printf("(4)\tDelete A Student\n");
    printf("(5)\tUpdate A Student\n");
    printf("(6)\tExit\n\n\t\t");

    printf("\nEnter Your Choice... ");
    scanf("%d",&c);
    switch(c)
    {
    case 1:
        add();
        break;
    case 2:
        display();
        break;
    case 3:
        //system("CLS");
        //printf("Search Student");
        search_student();
        break;
    case 4:
        //system("CLS");
        //printf("Delete A Student");
        delete_student();
        break;
    case 5:
        //system("CLS");
        //printf("Update A Student");
        update_student();
        break;
    case 6:
        system("CLS");
        exit(0);
    default:
        system("CLS");
        printf("Wrong Choice Please Re-Enter Your Choice... ");
        main();
    }
}

void add()
{
    system("CLS");
    printf("Add Student option is selected... ");
    FILE *fp;

    fp=fopen("D:/Record.csv","a");
    printf("\n\tEnter the Student Id: ");
    scanf("%d",&s.id);

    getchar();// USed to consume the \n produced by the scanf function
    //so that next step which terminate with \n is not affected
    printf("\n\tEnter the Student Name: ");
    scanf("%[^\n]s",&s.name);

    getchar();

    printf("\n\tEnter the Student Address: ");
    scanf("%[^\n]s",&s.address);

    fwrite(&s,sizeof(s),1,fp);
    fclose(fp);

    printf("\n\n\t\tData added successfully... ");

    sleep(5);
    strt();
}
void display()
{
    system("CLS");
    printf("View All Student's");

    FILE *fp2;
    fp2 = fopen("D:/Record.csv","r");
    printf("\n\tRoll_No\t\tName\t\tAddress\n\n");
    while (fread(&s, sizeof(s), 1, fp2))
    {
        printf("\t%d\t\t%s\t\t%s\n",s.id,s.name,s.address);
    }
    fclose(fp2);
    printf("\n\n\tAutomatically proceed to main menu in 5 seconds... ");
    sleep(5);
    strt();
}
void search_student()
{
    FILE *fp3;
    int w;
    int s_id;
    char s_name[25];
    printf("Enter the way you Want to search... \n");
    printf("\n<Enter 1> Search by Id... ");
    printf("\n<Enter 2> Search by Name... ");
    printf("\n<Enter 3> Search by Id and Name... ");
    printf("\nEnter your choice... ");
    scanf("%d",&w);
   // printf("%d",w);
    //getchar();
    switch(w)
    {
    case 1:
        fp3 = fopen("D:/Record.csv","r");
        printf("Enter the Id to search... ");
        scanf("%d",&s_id);
        while(fread(&s,sizeof(s),1,fp3))
        {
            if(s_id==s.id)
            {
                printf("\n\t\tStudent Id: %d",s.id);
                printf("\n\t\tStudent name: %s",s.name);
                printf("\n\t\tStudent Address: %s",s.address);

            }
        }
        fclose(fp3);
        printf("\n\n\tAutomatically proceed to main menu in 5 seconds... ");
        sleep(5);
        strt();
        break;
    case 2:
        //printf("\n\t\tStudent name: %d",s.id);
        fp3 = fopen("D:/Record.csv","r");
        printf("Enter the Name to search... ");
        getchar();
        scanf("%[^\n]s",&s_name);
        //printf("%s",s_name);
        while(fread(&s,sizeof(s),1,fp3))
        {
            if(strcmp(s_name,s.name)==0)
            {
                printf("\n\t\tStudent Id: %d",s.id);
                printf("\n\t\tStudent name: %s",s.name);
                printf("\n\t\tStudent Address: %s",s.address);
            }
        }
        fclose(fp3);
        printf("\n\n\tAutomatically proceed to main menu in 5 seconds... ");
        sleep(5);
        strt();
        break;
    case 3:
        fp3 = fopen("D:/Record.csv","r");
        printf("\nEnter the Id to search... ");
        scanf("%d",&s_id);
        getchar();
        printf("\nEnter the Name to search... ");
        scanf("%[^\n]s",&s_name);
        while(fread(&s,sizeof(s),1,fp3))
        {
            if(s_id==s.id && strcmp(s_name,s.name)==0)
            {
                printf("\n\t\tStudent Id: %d",s.id);
                printf("\n\t\tStudent name: %s",s.name);
                printf("\n\t\tStudent Address: %s",s.address);
            }
        }
        fclose(fp3);
        printf("\n\n\tAutomatically proceed to main menu in 5 seconds... ");
        sleep(5);
        strt();
        break;
    }
}
void delete_student()
{
    system("CLS");
    int d_id;
    FILE *fp4;
    FILE *fp5;
    printf("Enter the Student ID to Delete... ");
    scanf("%d",&d_id);

    //printf("Struct Student Id %d",s.id);

    fp4 = fopen("D:/Record.csv","rb");
    fp5 = fopen("D:/tempfile.csv","wb");
    while(fread(&s,sizeof(s),1,fp4)==1)
    {
        if(s.id!=d_id)
        {
            fwrite(&s,sizeof(s),1,fp5);
        }

    }
    fclose(fp4);
    fclose(fp5);
    fp4 = fopen("D:/Record.csv","wb");
    fp5=fopen("D:/tempfile.csv","rb");
    while(fread(&s,sizeof(s),1,fp5)==1)
    {
        fwrite(&s,sizeof(s),1,fp4);
    }
    fclose(fp4);
    fclose(fp5);
   // remove("D:\Record.csv")
    //("D:/Record.csv
    printf("\n\t\tRecord Successfully Deleted... ");
    printf("\n\n\tAutomatically proceed to Student List in 5 seconds... ");
    sleep(5);
    display();
}

void update_student()
{
    system("CLS");
    int choice;
    int u_id;
    char u_name[25];
    char u_address[25];
    FILE *inputFile;
    FILE *outFile;
    printf("Enter the Student ID to update... ");
    scanf("%d",&u_id);
    inputFile = fopen("D:/Record.csv","r");
    outFile = fopen("D:/tempfile.csv","w");
    while(fread(&s,sizeof(s),1,inputFile)==1)
    {
        if(u_id!=s.id)
        {
            fwrite(&s,sizeof(s),1,outFile);
        }
        else
        {
            printf("<Enter 1> Update the Name...\n");
            printf("<Enter 2> Update the Address...\n");
            printf("<Enter 3> Update the Name and Address...\n");
            printf("Enter your choice: ");
            scanf("%d",&choice);
            switch(choice)
            {
            case 1:
                getchar();
                printf("Enter the Name...");
                scanf("%[^\n]s",&s.name);
                break;
            case 2:
                getchar();
                printf("Enter the Address...");
                scanf("%[^\n]s",&s.address);\
                break;
            case 3:
                getchar();
                printf("Enter the Name...");
                scanf("%[^\n]s",&s.name);
                getchar();
                printf("Enter the Address...");
                scanf("%[^\n]s",&s.address);
                break;
            }
            fwrite(&s,sizeof(s),1,outFile);
        }
    }
    fclose(inputFile);
    fclose(outFile);
    inputFile = fopen("D:/Record.csv","w");
    outFile = fopen("D:/tempfile.csv","r");
    while(fread(&s,sizeof(s),1,outFile)==1)
    {
        fwrite(&s,sizeof(s),1,inputFile);
    }
    fclose(inputFile);
    fclose(outFile);

    printf("\n\n\t\tRECORD UPDATED\n");
    printf("\n\n\tAutomatically proceed to Student List in 5 seconds... ");
    sleep(5);
    display();
}
