void fee(int mm)
{
    system("clear");
    printf("\n\t******************************************************************");

    printf("\n\t                     ***************************                  ");

    printf("\n\t*********************          FEE     *******************");

    printf("\n\t                     ***************************                  ");

    printf("\n\t******************************************************************");
    FILE *files,*temp_f;
    int p=0;
    char name_s[50],cs='y';
    int clears, rollss,monthss,diffs;
    while(cs=='y'||cs=='Y')
    {
        int p=1,day=0;
        fflush(stdin);
        printf("\n\nEnter name:: ");
        scanf("%[^\n]",name_s);
        printf("\n\nEnter class:: ");
        fflush(stdin);
        clears=check_class();
        printf("\n\nEnter roll:: ");
        fflush(stdin);
        scanf("%d",&rollss);
        files=fopen("student","rb+");
        temp_f=fopen("te","wb");
        while(fread(&std,sizeof(std),1,files)==1)
        {
            if(strcmp(std.names,name_s)==0 && clears==std.cl && rollss==std.ro)
            {
                p=0;
                printf("\n\nEnter the month till which fee to be paid:: ");
                fflush(stdin);
                scanf("%d",&monthss);
                monthss=checking_date(monthss,day);
                diffs=mm-std.dte_tme.mth;
                std.debt=(diffs*std.fes)*0.01;
                std.duedate=(diffs)*std.fes;
                if (std.debt<0) std.debt=0;
                if (std.duedate<0) std.duedate=0;
                if (std.total<0) std.total=0;
                std.total=std.debt+std.duedate+std.advanced;
                printf("\nfine :: %.2f",std.debt);
                printf("\ndue :: %.2f",std.duedate);
                printf("\ntotal :: %.2f",std.total);
                printf("\nadvance :: %.2f",std.advanced);
                std.dte_tme.mth=monthss;
                std.total=0;
                std.debt=0;
                std.duedate=0;
                fwrite(&std,sizeof(std),1,temp_f);
            }
        }
        if (p==1)
            printf("\n\nRECORD NOT FOUND");
        printf("\n\n");
        system("pause");
        fflush(stdin);

        fclose(files);
        fclose(temp_f);
        system("del student");
        system("ren te, student");
        printf("\n\nDo you want to continue with the process(press y or n");
        fflush(stdin);
        cs=getchlin();
    }
    getchlin();
}

