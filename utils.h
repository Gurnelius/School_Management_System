/**
* Important utilty functions
*
*/
void exits()
{
    int l;
    //system("color 0c");
    printf("\n\n\t\t Thank you for using Chmsc School Billing System Project\n\n");
    system("pause");
    system("clear");
    printf("\n\n\t\t\t Exiting\n\n");
    for(l=1; l<=80; l++)
    {
        sleep(50);
        printf("*");
    }
    exit(0);
}

int checking_date(int mnt,int dnt)
{
    int monthsss,daysss;
    if (mnt>12 || mnt<1 || dnt<1 || dnt>32)
    {
        printf("Invalid Date, Try again:");

        fflush(stdin);
        scanf("%d%d",&monthsss,&daysss);
        monthsss=checking_date(monthsss,daysss);
    }
    else
        return (mnt);
}
int check_class()
{
    int mntttt,monsss;
    fflush(stdin);
    scanf("%d",&mntttt);
    if (mntttt>12 ||mntttt<1)
    {

        printf("Invalid Class, Try again:");
        fflush(stdin);
        monsss=check_class();
    }
    else
        return mntttt;
}

