#include<stdio.h>
#include<conio.h>
void main()
{
    FILE *fp;
    char ch;
    fp = fopen("hello.txt", "w");
    printf("Enter Data\n");
    while((ch=getchar())!=EOF)
    {
        putc(ch,fp);
    }

    fclose(fp);
    fp = fopen("hello.txt", "r");

    while((ch=getc(fp))!=EOF)
        printf("%c", ch);

    fclose(fp);

}
