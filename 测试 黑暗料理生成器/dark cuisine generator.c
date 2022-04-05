#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct word
{
    char str[100]; //name
}a[100000]={" "};  //initialize

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

int Generate_dishes(word *a,word *b,int n,int m,int t)
{
	int whoa=0,whob=0,w=0;
	srand(time(NULL));
	for(int j=0;j<t;j++){
			printf("%d.",j+1);
            whoa=rand()%n;
            printf("%s",a[whoa].str);
            w=rand()%(m/4);
            printf("%s",b[4*w].str);
            whob=rand()%n;
            puts(a[whob].str);
            printf("这道菜的做法如下:\n");
            printf("%s",b[4*w+1].str);
            printf("%s",a[whoa].str);
            printf("%s",b[4*w+2].str);
            printf("%s",a[whob].str);
            printf("%s",b[4*w+3].str);
            printf("\n\n");}
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

int write()
{
    FILE *fp=fopen("out.txt","w");//指针指向out.txt文件
	fprintf(fp,"%d",a+b);//将结果写入out.txt文件中
	fclose(fp);//关闭文件
}

int Inport_Food(word p)
{
    printf("请输入您要导入的食材\n");
    scanf("%s",&p);
}

int main()
{
	int n=Get_Foodbank(a);
    int m=Get_Verbbank(way);
    int t=0;
    printf("已导入%d种食材\n",n);
    printf("已导入%d种烹饪方式\n",m);
    printf("请输入您要生成多少种菜肴>>>>>>");
    scanf("%d",&t);
    printf("\n");
	Generate_dishes(a,way,n,m,t);
    scanf("%d",&n);
	return 0;
}
