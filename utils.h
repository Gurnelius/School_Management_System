
int checking_date(int,int); //* Prototype */


int checking_date(int mnt,int dnt)
{
    int monthsss,daysss;
    if (mnt>12 || mnt<1 || dnt<1 || dnt>32)
    {
        printf("Invalid Date! Enter Again:");

        fflush(stdin);
        scanf("%d%d",&monthsss,&daysss);
        monthsss=checking_date(monthsss,daysss);
    }
    else
        return (mnt);
}
