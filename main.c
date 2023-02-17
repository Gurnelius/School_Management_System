#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include "getch.h"
#include "utils.h"
#include "database.h"
#include "calculations.h"

void start(void);

void main(void)
{
    int l,m,o;
    for(l=0; l<80; l++)
    {
        printf("\xdb");
    }
    printf("\n");
    for(l=0; l<80; l++)
    {
        printf("\xdb");
    }
    

    printf(" \n\t|________________________________________________________|\n");
    printf("\t|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n");
    printf("\t|  **WELCOME TO STAR SCHOOL MANAGEMENT SYSTEM	       |  ** |\n");
    printf("\n\t|                                                      |\n");
    printf("\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("\t|             DEVELOPED BY GURNELIUS TERER               |\n");
    printf("\t|________________________________________________________|\n");
    printf("\t|    *****************************************           |\n");
    printf("\t|    *****************************************           |\n");
    printf("\t|________________________________________________________|\n");
    
    printf("\n\tENTER ANY KEY TO CONTINUE");
    
    for(l=0; l<5; l++)
    {
        printf(".");
        sleep(500);//after printing one . another comes after 0.5 seconds
    }
    getchlin();
    system("clear");//clears the screen
    printf("\n");
    for(l=0; l<80; l++)
    {
        printf("\xdb");
    }
  
    printf("\n\n\t** WELCOME TO STAR SCHOOL MANAGEMENT SYSTEM **\n\n\n");

    for(l=0; l<80; l++)
    {
        printf("\xdb");
    }
    printf("\nPLEASE ENTER ANY KEY TO START\n");
    for(l=0; l<5; l++)
    {
        printf(".");
        sleep(500);
    }
    fflush(stdin);
    getchlin();
    system("clear");
    printf("\n\t\tPLEASE ENTER CURRENT DATE\nmm dd\n ");
    scanf("%d%d",&mm,&dd);
    mm=checking_date(mm,dd);
    start();
}

void start()
{
    int l,m;//j is for selection of account type
    system("clear");
    printf("\n\t\tPLEASE ENTER ACCOUNT TYPE");
    printf("\n\t\t1:: Student");
    printf("\n\t\t2:: Teachers and Staffs");
    printf("\n\t\t3:: Exit");
    printf("\n\t\tAccount Type Choice  ");
    fflush(stdin);
    scanf("%d",&m);
    switch (m)
    {
    case 3:
        exits();
    case 1:
    {
        system("clear");
        printf("\n\t\tPLEASE ENTER THE CHOICE");
        printf("\n\t\t1:: Add Record");
        printf("\n\t\t2:: Search Record");
        printf("\n\t\t3:: Modify Record");
        printf("\n\t\t4:: Delete Record");
        printf("\n\t\t5:: Calculate Fee");
        printf("\n\t\t6:: Exit");
        printf("\n\n Enter Choice  ");
        fflush(stdin);
        scanf("%d",&l);
        switch (l)
        {
        case 1:
            adding_records(m);//function call
            start();//function call
        case 2:
            searching_records(m);
            start();
        case 3:
            update_records(m);
            start();
        case 4:
            deleting_records(m);
            start();
        case 5:
            fee(mm);
            start();
        case 6:
            exits();
        default :
        {
            printf("\n\n\tInvalid Entry!!");
            printf("\n\nTo Account Type\n\n\t");
            system("Pause");
            start();
        }
        }
    }
    case 2:
    {

        system("clear");
        printf("\n\t\tPLEASE ENTER THE CHOICE");
        printf("\n\t\t1:: Add Record");
        printf("\n\t\t2:: Search Record");
        printf("\n\t\t3:: Modify Record");
        printf("\n\t\t4:: Delete Record");
        printf("\n\t\t5:: Calculate Salary");
        printf("\n\t\t6:: Exit");
        printf("\n\n Enter Choice  ");
        fflush(stdin);
        scanf("%d",&l);
        switch (l)
        {
        case 1:
            adding_records(m);
            start();
        case 2:
            searching_records(m);
            start();
        case 3:
            update_records(m);
            start();
        case 4:
            deleting_records(m);
        case 5:
            salary(mm);
            start();
        case 6:
            exits();
        default :
        {
            printf("\n\n\tInvalid entry!!");
            printf("\n\nTo Account Type\n\n\t");
            system("Pause");
            start();
        }

        }
    }
    default :
    {
        printf("\n\n\tInvalid Entry!!");
        printf("\n\nTo Account Type\n\n\t");
        system("Pause");
        start();
    }
    }
}

