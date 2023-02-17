#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include "getch.h"
#include "utils.h"

struct date_and_time

{
    int dy,mth;

};

int check_class();//check class (1-12)

struct student
{
    struct date_and_time dte_tme;
    float fes,debt,total,advanced,duedate;
    char names[50];
    int ro,cl;
} std,s;

struct teacher
{
    struct date_and_time dte_tme;
    char names[50];
    float slry,advanced,total;
    int t_id,t_no;
} techr,temp_f;

void adding_records(int);//for adding records
void update_records(int);//for modifying records
void searching_records(int);//for searching records
void deleting_records(int);//for deleting records
void salary(int);//for the calculation of salary of teacher and staff
FILE *file_store,*file_temp;//file declaration

int mm,dd;//mm=month, dd=day
void exits();//for exiting

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
    system("color 9b");
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
    //start();
}
