/**
* File management utilities
*
*/

struct date_and_time
{
    int dy,mth;

};

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

FILE *file_store,*file_temp;//file declaration
int mm,dd;//mm=month, dd=day

adding_records(int j)
{
    int df,clrdate,duedte,mh=0;//cdat=month till which fee is cleared
    float fee_fee;//used in calculatin of fee of different class
    char cs='y';
    system("clear");

    printf("\n\t******************************************************************");

    printf("\n\t                     ***************************                  ");

    printf("\n\t*********************          ADD RECORD       *******************");

    printf("\n\t                     ***************************                  ");

    printf("\n\t******************************************************************");
    if (j==1)
    {
        while(cs=='y'||cs=='Y')
        {
            int a=1;
            printf("\n\nEnter the name of student: ");
            fflush(stdin);
            scanf("%[^\n]",std.names);
            printf("\nEnter the class: ");
            fflush(stdin);
            std.cl=check_class();
            printf("\nEnter the Roll No.:");
            fflush(stdin);
            scanf("%2d",&std.ro);
            printf("\nEnter month and day till which fee is paid:");
            fflush(stdin);
            scanf("%2d%2d",&clrdate,&duedte);
            clrdate=checking_date(clrdate,duedte);
            std.dte_tme.mth=clrdate;
            fee_fee=std.cl/10.0;
            std.fes=1000*(1+fee_fee);//fee of different classes
            df=mm-std.dte_tme.mth;//months of fee left to be paid
            std.debt=(df*std.fes)*1/100;
            std.duedate=(df)*std.fes;//fees left to be paid
            if(df==1)
            {
                std.total=std.fes;
                std.debt=0;
            }
            else
            {
                std.total=std.debt+std.duedate;
            }//for calculation of total fee
            file_store=fopen("student","ab+");//opening a binary file in append mode
            fwrite(&std,sizeof(std),1,file_store);
            fclose(file_store);
            printf("\n\nDo you want to continue with the process(press y or n)");
            fflush(stdin);
            cs=getchlin();
        }
        getchlin();
    }
    if (j==2)
    {
        while(cs=='y'||cs=='Y')
        {
            int a=1;
            printf("\n\nEnter name of teacher/staff:" );
            fflush(stdin);
            scanf("%[^\n]",techr.names);
            printf("\nEnter teacher/staff id: ");
            fflush(stdin);
            scanf("%d",&techr.t_id);
            printf("\nEnter number of class/shift per month:: ");
            scanf("%d",&techr.t_no);
            fflush(stdin);
            printf("\nEnter month and day till which salary is paid::");
            scanf("%d %d",&techr.dte_tme.mth,&techr.dte_tme.dy);
            clrdate=checking_date(clrdate,duedte);
            techr.dte_tme.mth=clrdate;
            techr.slry=techr.t_no*500;
            techr.advanced=(techr.dte_tme.mth-mm-1)*techr.slry;
            if (techr.advanced<0) techr.advanced=0;
            techr.total=techr.slry;
            file_temp=fopen("teacher","ab+");
            fwrite(&techr,sizeof(techr),1,file_temp);
            fclose(file_temp);
            printf("\n\nDo you want to continue with the process(press y or n");
            fflush(stdin);
            cs=getchlin();
        }
        fflush(stdin);
        printf("\n\n");
        system("pause");
    }
}

void searching_records(int j)
{
    char name_s[50],name_t[50];
    int p=1,option;
    char cs='y';
    if (j==1)
    {
        while(cs=='y'||cs=='Y')
        {
            int p=1;
            system("clear");
            printf("\n\t******************************************************************");

            printf("\n\t                    ***************************                  ");

            printf("\n\t*********************   SEARCH RECORD     *******************");

            printf("\n\t                     ***************************                  ");

            printf("\n\t******************************************************************");
            printf("\n\n\t\tPLEASE CHOOSE SEARCH TYPE::");
            printf("\n\n\t\t1::Search by Name::");
            printf("\n\n\t\t2::Search by Cass::");
            printf("\n\n\t\t3::Search by Roll No::");
            printf("\n\n\t\t4::Exit");
            printf("\n\n\t\t::Enter your Choice:: ");
            fflush(stdin);
            scanf("%d",&option);
            if (option==1)
            {
                p=1;
                printf("\n\nEnter name of student to search: ");
                fflush(stdin);
                scanf("%[^\n]",name_s);
                file_store=fopen("student","rb");
                while(fread(&std,sizeof(std),1,file_store)==1)
                {
                    if (strcasecmp(name_s,std.names)==0)
                    {
                        p=0;
                        printf("\nname = %s",std.names);
                        printf("\nclass = %d",std.cl);
                        printf("\nroll no = %d",std.ro);
                        printf("\nmonthy fee =%.2f",std.fes);
                        printf("\nlast fee paid in month =%2d",std.dte_tme.mth);
                        printf("\n due=%.2f",std.duedate);
                        printf("\n fine=%.2f",std.debt);
                        printf("\n total=%.2f\n\n",std.total);
                    }
                }
                if (p==1)
                    printf("\n\nRECORD NOT FOUND");
                printf("\n\n");
                system("pause");
                fflush(stdin);
                fclose(file_store);
            }
            else if (option==2)
            {
                int cl;
                p=1;
                printf("\n\nEnter class of student to search: ");
                fflush(stdin);
                cl=check_class();
                file_store=fopen("student","rb");
                while(fread(&std,sizeof(std),1,file_store)==1)
                {
                    if (std.cl==cl)
                    {
                        p=0;
                        printf("\nname = %s",std.names);
                        printf("\nclass = %d",std.cl);
                        printf("\nroll no = %d",std.ro);
                        printf("\nmonthy fee =%.2f",std.fes);
                        printf("\nlast fee paid in month =%2d",std.dte_tme.mth);
                        printf("\n due=%.2f",std.duedate);
                        printf("\n fine=%.2f",std.debt);
                        printf("\n total=%.2f",std.total);
                    }
                }
                if (p==1)
                    printf("\n\nRECORD NOT FOUND");
                printf("\n\n");
                system("pause");
                fflush(stdin);
                fclose(file_store);
            }
            else if (option==3)
            {
                int rll;
                p=1;
                printf("\n\nEnter roll of student to search: ");
                fflush(stdin);
                rll=check_class();
                file_store=fopen("student","rb");
                while(fread(&std,sizeof(std),1,file_store)==1)
                {
                    if (strcasecmp(name_s,std.names)==0)
                    {
                        p=0;
                        printf("\nname = %s",std.names);
                        printf("\nclass = %d",std.cl);
                        printf("\nroll no = %d",std.ro);
                        printf("\nmonthy fee =%.2f",std.fes);
                        printf("\nlast fee paid in month =%2d",std.dte_tme.mth);
                        printf("\n due=%.2f",std.duedate);
                        printf("\n fine=%.2f",std.debt);
                        printf("\n total=%.2f",std.total);
                    }
                }
                if (p==1)
                    printf("\n\nRECORD NOT FOUND");
                printf("\n\n");
                system("pause");
                fflush(stdin);
                fclose(file_store);
            }
            else if(option==4)
            {
                exits();
            }
            else
            {
                printf("\n\n\n\t\tINVALID ENTRY!!!!\n\n\t\t");
                system("pause");
                searching_records(1);
            }
            printf("\n\nDo you want to continue with the process(press y or n");
            fflush(stdin);
            cs=getchlin();
        }
        getchlin();
    }
    if (j==2)
    {
        while(cs=='y'||cs=='Y')
        {
            int p=1;
            printf("\n\nname of teacher/staff to search: ");
            fflush(stdin);
            scanf("%[^\n]",name_t);
            file_temp=fopen("teacher","rb");
            while(fread(&techr,sizeof(techr),1,file_temp)==1)
            {
                if (strcasecmp(name_t,techr.names)==0)
                {
                    p=0;
                    printf("\nname = %s",techr.names);
                    printf("\nteacher/staff id = %d",techr.t_id);
                    printf("\nmonth till when salary is paid =%d",techr.dte_tme.mth);
                    printf("\nmonthy salary = %.2f",techr.slry);
                    printf("\nadvance paid = %.2f",techr.advanced);
                }
            }
            if (p==1)
                printf("\n\nRECORD NOT FOUND");
            printf("\n\n");
            system("pause");
            fflush(stdin);
            fclose(file_temp);
            printf("\n\nDo you want to continue with the process(press y or n");
            fflush(stdin);
            cs=getchlin();
        }
        getchlin();
    }

}

void update_records(int j)
{

    char name_s[50];
    int p=1,option,cll,roll_no;
    char cs='y';
    if (j==1)
    {
        while(cs=='y'||cs=='Y')
        {
            system("clear");
            printf("\n\t******************************************************************");

            printf("\n\t                    ***************************                  ");

            printf("\n\t*********************   MODIFY RECORD     *******************");

            printf("\n\t                     ***************************                  ");

            printf("\n\t******************************************************************");
            printf("\n\n\t\tPLEASE CHOOSE MODIFY TYPE::");
            printf("\n\n\t\t1::Modify by Name::");
            printf("\n\n\t\t2::Modify by Name &Class::");
            printf("\n\n\t\t3::Modify by Name,Class & Roll No::");
            printf("\n\n\t\t4::Exit");
            printf("\n\n\t\t::Enter your Choice:: ");
            fflush(stdin);
            scanf("%d",&option);
            if (option==1)
            {
                int p=0;
                printf("\n\nEnter Name of Student to Modify: ");
                fflush(stdin);
                scanf("%[^\n]",name_s);
                file_store=fopen("student","rb+");
                while(fread(&std,sizeof(std),1,file_store)==1)
                {
                    p=1;
                    if (strcasecmp(name_s,std.names)==0)
                    {
                        p=0;
                        printf("\nEnter New Name of Student: ");
                        fflush(stdin);
                        scanf("%[^\n]",std.names);
                        printf("\nEnter New Class of Student: ");
                        fflush(stdin);
                        std.cl=check_class();
                        printf("\nEnter New Roll of Student: ");
                        fflush(stdin);
                        scanf("%d",&std.ro);
                        fseek(file_store,-sizeof(std),SEEK_CUR);
                        fwrite(&std,sizeof(std),1,file_store);
                        fclose(file_store);
                    }
                }
                if (p==1)
                    printf("\n\nRECORDS NOT FOUND");
                else
                    printf("\n\nRECORDS SUCCESSFULLY  MODIFIED");
                printf("\n\n");
                system("pause");
            }
            else if (option==2)
            {
                int p=0;
                printf("\n\nEnter Name of Student to Modify: ");
                fflush(stdin);
                scanf("%[^\n]",name_s);
                printf("\n\nEnter Class of Student to Modify: ");
                fflush(stdin);
                cll=check_class();
                file_store=fopen("student","rb+");
                while(fread(&std,sizeof(std),1,file_store)==1)
                {
                    p=1;
                    if (strcasecmp(name_s,std.names)==0 && cll==std.cl)
                    {
                        p=0;
                        printf("\nEnter New Name of Student: ");
                        fflush(stdin);
                        scanf("%[^\n]",std.names);
                        printf("\nEnter New Class of Student: ");
                        fflush(stdin);
                        std.cl=check_class();
                        printf("\nEnter New Roll of Student: ");
                        fflush(stdin);
                        scanf("%d",&std.ro);
                        fseek(file_store,-sizeof(std),SEEK_CUR);
                        fwrite(&std,sizeof(std),1,file_store);
                        fclose(file_store);
                    }
                }
                if (p==1)
                    printf("\n\nRECORDS NOT FOUND");
                else
                    printf("\n\nRECORDS SUCCESSFULLY  MODIFIED");
                printf("\n\n");
                system("pause");
            }
            else if (option==3)
            {
                int p=0;
                printf("\n\nenter name of student to modify: ");
                fflush(stdin);
                scanf("%[^\n]",name_s);
                printf("\n\nenter class of student to modify: ");
                fflush(stdin);
                cll=check_class();
                printf("\n\nenter roll of student to modify: ");
                fflush(stdin);
                scanf("%d",&roll_no);
                file_store=fopen("student","rb+");
                while(fread(&std,sizeof(std),1,file_store)==1)
                {
                    p=1;
                    if (strcasecmp(name_s,std.names)==0 && cll==std.cl &&roll_no==std.ro)
                    {
                        p=0;
                        printf("\nenter new name of student: ");
                        fflush(stdin);
                        scanf("%[^\n]",std.names);
                        printf("\nenter new class of student: ");
                        fflush(stdin);
                        std.cl=check_class();
                        printf("\nenter new roll of student: ");
                        fflush(stdin);
                        scanf("%d",&std.ro);
                        fseek(file_store,-sizeof(std),SEEK_CUR);
                        fwrite(&std,sizeof(std),1,file_store);
                        fclose(file_store);
                    }
                }
                if (p==1)
                    printf("\n\nRECORDS NOT FOUND");
                else
                    printf("\n\nRECORDS SUCCESSFULLY  MODIFIED");
                printf("\n\n");
                system("pause");
            }
            else if (option==4) exits();
            else
            {
                printf("\n\n\n\t\tINVALID ENTRY!!!!\n\n\t\t");
                system("pause");
                update_records(1);
            }

            printf("\n\nDo you want to continue with the process(press y or n");
            fflush(stdin);
            cs=getchlin();
        }
        getchlin();
    }

    if (j==2)
    {
        while(cs=='y'||cs=='Y')
        {
            int p=1;
            printf("enter name of teacher to modify: ");
            fflush(stdin);
            scanf("%[^\n]",name_s);
            file_temp=fopen("teacher","rb+");
            while(fread(&techr,sizeof(techr),1,file_temp)==1)
            {
                if (strcasecmp(name_s,techr.names)==0)
                {
                    p=0;
                    printf("\nenter new name of teacher: ");
                    fflush(stdin);
                    scanf("%[^\n]",techr.names);
                    printf("\nenter new id of teacher: ");
                    fflush(stdin);
                    scanf("%d",&techr.t_id);
                    fseek(file_temp,-sizeof(techr),SEEK_CUR);
                    fwrite(&techr,sizeof(techr),1,file_temp);
                    fclose(file_temp);
                }
            }

            if (p==1)
                printf("\n\nRECORD NOT FOUND");
            else
                printf("\n\nRECORD SUCCESSFULLY  MODIFIED");
            printf("\n\n");
            system("pause");
            fflush(stdin);

            printf("\n\nDo you want to continue with the process(press y or n");
            fflush(stdin);
            cs=getchlin();
        }
        getchlin();
    }
}

void deleting_records(int j)
{
    system("clear");
    printf("\n\t******************************************************************");

    printf("\n\t                     ***************************                  ");

    printf("\n\t*********************          DELETE RECORD     *******************");

    printf("\n\t                     ***************************                  ");

    printf("\n\t******************************************************************");
    FILE *temporary,*tmp1;
    int p=1;
    char name_s[50],cs='y';
    if (j==1)
    {
        while(cs=='y'||cs=='Y')
        {
            int p=1;
            printf("\n\nenter name of student to delete: ");
            fflush(stdin);
            scanf("%[^\n]",name_s);
            file_store=fopen("student","rb");
            temporary=fopen("tempfile","wb");//opening of temporary file for deleting process
            while (fread(&std,sizeof(std),1,file_store)==1)
            {
                if (strcmp(std.names,name_s)==0)
                {
                    p=0;
                    continue;
                }
                else
                {
                    fwrite(&std,sizeof(std),1,temporary);
                }
            }

            if (p==1)
                printf("\n\nRECORD NOT FOUND");
            else
                printf("\n\nRECORD SUCCESSFULLY  DELETED");
            printf("\n\n");
            system("pause");
            fflush(stdin);

            fclose(file_store);
            fclose(temporary);
            system("del student");/*all data except the data to be
            deleted in student were 1st moved to temp and data in student
            was deleted*/
            system("ren tempfile, student");//renaming temp to student
            printf("\n\nDo you want to continue with the process(press y or n");
            fflush(stdin);
            cs=getchlin();
        }
        getchlin();
    }

    if (j==2)
    {
        p=1;
        char name_t[50];
        while(cs=='y'||cs=='Y')
        {
            printf("\n\nEnter name of teacher to delete record: ");
            fflush(stdin);
            scanf("%[^\n]",name_t);
            file_temp=fopen("teacher","rb");
            tmp1=fopen("tempfile1","wb");
            while (fread(&techr,sizeof(techr),1,file_temp)==1)
            {
                if (strcmp(techr.names,name_t)==0)
                {
                    p=0;
                    continue;
                }
                else
                {
                    fwrite(&techr,sizeof(techr),1,tmp1);
                }
            }

            if (p==1)
                printf("\n\nRECORD NOT FOUND");
            else
                printf("\n\nRECORD SUCCESSFULLY  DELETED");
            printf("\n\n");
            system("pause");
            fflush(stdin);

            fclose(file_temp);
            fclose(tmp1);
            system("del teacher");
            system("ren tempfile1, teacher");
            printf("\n\nDo you want to continue with the process(press y or n");
            fflush(stdin);
            cs=getchlin();
        }
        getchlin();
    }
}

void salary(int mm)
{
    system("clear");
    printf("\n\t******************************************************************");

    printf("\n\t                     ***************************                  ");

    printf("\n\t*********************          SALARY     *******************");

    printf("\n\t                     ***************************                  ");

    printf("\n\t******************************************************************");
    FILE *files,*temp_f;
    int p=1,day_s;
    char name_s[50],cs='y';
    int months,df,ids;
    while(cs=='y'||cs=='Y')
    {
        int p=1;
        fflush(stdin);
        printf("\n\nEnter name:: ");
        scanf("%[^\n]",name_s);
        printf("\n\nEnter ID:: ");
        scanf("%d",&ids);
        files=fopen("teacher","rb+");
        temp_f=fopen("te","wb+");
        while(fread(&techr,sizeof(techr),1,files)==1)//file opened
        {
            if(strcmp(techr.names,name_s)==0 )//name entered is compared to the existing name in file
            {
                float lsal;
                p=0;
                printf("\n\nEnter the month till which salary is to be paid:: ");
                fflush(stdin);
                scanf("%d",&months);
                months=checking_date(months,day_s);
                techr.advanced=(months-mm-1)*techr.slry;
                if (techr.advanced<0) techr.advanced=0;
                lsal=mm-techr.dte_tme.mth;//months of salary left to be paid
                if(lsal<0) lsal=0;
                techr.total=techr.advanced+techr.slry*(1+lsal);
                if(months==techr.dte_tme.mth) techr.total=0;
                printf("\nmonthy salary left to be paid:: %.2f",lsal);
                printf("\ntotal :: %.2f",techr.total);
                printf("\nadvance :: %.2f",techr.advanced);
                techr.dte_tme.mth=months;
                fwrite(&techr,sizeof(techr),1,temp_f);
                fclose(files);
                fclose(temp_f);

                if (p==1)
                    printf("\n\nRECORD NOT FOUND");
                printf("\n\n");
                system("pause");
                fflush(stdin);
                system("del teacher");
                system("ren te, teacher");
            }
        }
        printf("\n\nDo you want to continue with the process(press y or n");
        fflush(stdin);
        cs=getchlin();
    }
    getchlin();
}
