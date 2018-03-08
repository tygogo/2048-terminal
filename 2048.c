#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
#include<conio.h>
#define N 4 
int star(int (*p)[N]);
int sencen(int (*p)[N]);
int dayin(int (*p)[N]);
int panduan(int (*p)[N]);
int up(int (*p)[N]);
int left(int (*p)[N]);
int right(int (*p)[N]);
int down(int (*p)[4]);
int df=0;//全局变量 得分 

int main(void)
{
	int aa[N][N];
	char ch ;	
	srand((unsigned)time(NULL));//随机数种子 
	
	printf("\n#####################2048#####################\n");
	printf("\n\n\n任意键开始"); 
	if(getch())star(aa);
}
int star(int (*p)[N]) 
{
	int key,i,j;
	df=0; 
	for(i=0;i<N;i++)
	for(j=0;j<N;j++)
	p[i][j]=0;
	system("cls");	
	sencen(p);
	sencen(p);
	dayin(p);
	while(1)
	{
		key=getch();
		switch(key)
		{
			case 72 : up(p),dayin(p),panduan(p);break;
		 	case 75 : left(p),dayin(p),panduan(p);break;
			case 77 : right(p),dayin(p),panduan(p);break;
			case 80 : down(p),dayin(p),panduan(p);break;
			case 27 : return 0;break; 
			case 32 : star(p);break; 
		}
	}
}
int sencen(int (*p)[N])//在表中生成一个数 
{
	int s,j,i;
	while(1){
		s=rand()%(4);//随机数0-3 
		j=rand()%(4);
		if(p[s][j]==0)
	 	{
		p[s][j]=2*(rand()%2+1);
		break;
		}
	}
	return 0;
}
int dayin(int (*p)[N])//打印数字 
{
		int i,j;
	printf("\n#####################2048#####################\n\n");
	for(i=0;i<N;i++)
	{
	for(j=0;j<N;j++)
	if(p[i][j]==0)printf("%4c ",'-'); 
	else printf("%4d ",p[i][j]);	
	printf("\n");
	}
	printf("\n  得分:%d",df);
	printf("\n\n方向键:控制\tESC:退出\t空格:重置");
	printf("\n\n\n#####################2048#####################\n\n");
	return 0;
}
int panduan(int (*p)[N])//判断游戏胜利与结束 
{
	int i,j,flag1=1,flag2=1;//flag1=0时,表中有0, flag2=0时表中相邻数存在相等的. 
	for(i=0;i<N;i++)
	{
		if((i<N-1) && (p[i][N-1]==p[i+1][N-1])) flag2=0;
		for(j=0;j<N;j++){
			if((j<N) && (p[N-1][j]==p[N-1][j+1])) flag2=0;
			if(p[i][j]==0) flag1=0;
			if(p[i][j]==2048)printf("\n#####################WIN#####################\n");
			if((i<N-1&&j<N-1) && (p[i][j]==p[i][j+1]) || (p[i][j]==p[i+1][j]))flag2=0;			
		}
	}
	if((flag1)&&(flag2)){
		system("cls");
		printf("\n\n\n\n#############游戏结束#############\n\n\nESC:退出\n空格:重来");
	}
return 0; 
}
//按键操作 
int up(int (*p)[N])
{
	int i,j,k,flag=0;
	for(j=0;j<N;j++)
	{
		for(i=0;i<N-1;i++){
			while(p[i][j]==0&&p[i+1][j]!=0){//当前项为0 后一项非0 
				flag=1;
				p[i][j]=p[i+1][j];
				p[i+1][j]=0;
				if(i>0)i--;
			}
			while((p[i][j]==p[i+1][j])&&p[i][j]!=0){
				flag=1;
				p[i][j]=2*p[i+1][j];
				p[i+1][j]=0;
				df=df+p[i][j];//得分 
				if( (i>0) && (p[i][j]==p[i-1][j]) )continue;//如果相加后与上一项相等 就不再与上一项相加 
			}
		}
	}
	if(flag)
	sencen(p);
	system("cls");
	return 0;
}
int left(int (*p)[N])
{
	int i,j,flag=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N-1;j++){
		
			while(p[i][j]==0&&p[i][j+1]!=0){
				flag=1;
				p[i][j]=p[i][j+1];
				p[i][j+1]=0;
				if(j>0)j--;
			}
			while((p[i][j]==p[i][j+1])&&p[i][j]!=0){
					flag=1;
					p[i][j]=2*p[i][j+1];
					p[i][j+1]=0;
					df=df+p[i][j];//得分 
					if((j>0) && (p[i][j]==p[i][j-1]) )continue;
			} 	
		}
	}
	if(flag)
	sencen(p);
	system("cls");
	return 0;
}
int right(int (*p)[N])
{
	int i,j,flag=0;
	for(i=0;i<N;i++)
	{
		for(j=N-1;j>0;j--){
			while(p[i][j]==0&&p[i][j-1]!=0){
				flag=1;
				p[i][j]=p[i][j-1];
				p[i][j-1]=0;
				if(j<N-1)j++;
			}
			while((p[i][j]==p[i][j-1])&& p[i][j]!=0 ){
					flag=1;
					p[i][j]=2*p[i][j-1];
					p[i][j-1]=0;
					df=df+p[i][j];//得分 
					if((j<N) && (p[i][j]==p[i][j+1]) )continue;
			}
		}
	}
	if(flag)
	sencen(p);
	system("cls");
	return 0;
}
int down(int (*p)[N])
{
	int i,j,flag=0;
	for(j=0;j<N;j++)
	{
		for(i=N-1;i>0;i--){
			while(p[i][j]==0&&p[i-1][j]!=0){
				flag=1;
				p[i][j]=p[i-1][j];
				p[i-1][j]=0;
				if(i<N-1)i++;

			}
			while((p[i][j]==p[i-1][j])&&p[i][j]!=0){
				flag=1;
				p[i][j]=2*p[i-1][j];
				p[i-1][j]=0;
				df=df+p[i][j];//得分 
				if( (i<N) && (p[i][j]==p[i-1][j]))continue;
			}
		}
	}
	if(flag)
	sencen(p);
	system("cls");
	return 0;
}
