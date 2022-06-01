#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    fp=fopen("a.txt","r+");
    if(fp==NULL)
    {
        printf("Unable to open the file\n");
        exit(0);
    }
    char ch;
    ch=getc(fp);
        printf("%c",ch);
        ch=getc(fp);
        fclose(fp);
}
