 #include<stdio.h>
 
char getchlin(void); /* Prototype */

char getchlin()  /*definition */
{
	char c;/*return value*/
	char test; /*to retain the screen*/
 
	scanf("%c",&c);
	scanf("%c",&test);
	return (c);
}
