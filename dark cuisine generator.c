#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct word
{
    char str[20]; //name
}a[100000]={" ",0};  //initialize

struct word way[100];

int Get_Foodbank(word *a)
{
    FILE *fp;
    char ch;
    int i,n=0,choice,who;
    fp=fopen("food.txt","r");
    if(fp==NULL)
    {
        printf("can not open the file\n");
        return 1;
    }
    while((ch=fgetc(fp))!=EOF)
    {
        if(ch=='\n')n++; //size
    }  
    rewind(fp);
    for(i=0;i<n;i++)
    {
        fscanf(fp,"%s\n",a[i].str);
    }
    fclose(fp);
    return n;
}

int Generate_dishes(word *a,word *b,int n,int m)
{
	int who=0,w=0;
    srand(time(NULL));
    for(int i=1;i<n;i++)
    {
            who=rand()%n;
            printf("%s",a[who].str);
            w=rand()%m;
            printf("%s",b[w].str);
            who=rand()%n;
            puts(a[who].str);
    }
    return 0;
}

int Get_Verbbank(word *a)
{
    FILE *fp;
    char ch;
    int i,n=0,choice,who;
    fp=fopen("way_to_process.txt","r");
    if(fp==NULL)
    {
        printf("can not open the file\n");
        return 1;
    }
    while((ch=fgetc(fp))!=EOF)
    {
        if(ch=='\n')n++; //size
    }  
    rewind(fp);
    for(i=0;i<n;i++)
    {
        fscanf(fp,"%s\n",a[i].str);
    }
    fclose(fp);
    return n;
}

int main()
{
	int n=Get_Foodbank(a);
    int m=Get_Verbbank(way);
	Generate_dishes(a,way,n,m);
    scanf("%d",&n);
	return 0;
}
