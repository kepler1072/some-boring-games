#include <stdlib.h>//��һ�������������ֱ�Ӵ����ϰ������ģ�
#include <stdio.h> //��Ϊ�����������������ɵ�ԭ��......������
#include <time.h> //�ð���ʵ���Ǹ�ʱ��û���ü������Ͼ���һ�������������Ķ�����
int main( )        //�Ժ���������^_^
{int a[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};//��Ϊˮƽ������
int x[4]={0,0,0,0};                                    //����������һ�����ص�bug���һ�����������������������Ҹ㲻������
	int num=0,i=0,m=0,n=0,k=0,b=0,max=0;               //���������ٶȲ��������⣬��������ߣ��һ�����ڲŸ㶨�ģ������ķ��������Ǿ��ϴ��ˣ�
	char w=' ' ;                                       //�����ſ���

while(max==0){

srand( (unsigned)time( NULL ) ); 
num = 2*(rand()%2+1);
for(i=0;i<=1;){
srand( (unsigned)time( NULL ) );
m=rand()%4;
srand( (unsigned)time( NULL ) );
n=rand()%4;
if(a[m][n]==0){
	a[m][n]=num;
    i=i+1;}}
i=0;m=0;n=0;		

while(i<=3){
	printf("%d\t%d\t%d\t%d\n",a[i][0],a[i][1],a[i][2],a[i][3]);
    i=i+1;}	

i=0,m=0,n=0;k=0;
scanf("%c",&w);

if(w=='a'){
	m=0,n=0;k=0;b=0;
	while(m<=3){                          //��ʮ���д������ٻ����������Сʱ......
		while(n<=3){
			if(a[m][n]!=0){
				x[b]=a[m][n];
				b=b+1;}
		n=n+1;}
		n=0;b=0;
		while(n<=3){
			a[m][n]=x[b];
			n=n+1;
		    b=b+1;}
		n=0;b=0;                          //�ѷ�0�����Ƶ���Ļ��Ե

		while(b<=3){
		x[b]=0;
		b=b+1;}
		b=0;
	
		while(n<=2){
			if(a[m][n]==a[m][n+1]){
				//���ʽa[m][n]=a[m][n]*2��������Ͳ���ִ�У�Ϊʲô��
				k=n;
				while(k<=2){
					a[m][k]=a[m][k+1];
					k=k+1;}
                a[m][n]=a[m][n]*2;   //�������ִ����......            
				a[m][k]=0;
				k=0;}
			n=n+1;}
		n=0;                            //���ֺϲ�
		m=m+1;}
}
//�����ˣ����þ��У���������Ҳ������

if(w=='w'){
	m=0,n=0;k=0;b=0;
	while(n<=3){
		while(m<=3){
			if(a[m][n]!=0){
				x[b]=a[m][n];
				b=b+1;}
			m=m+1;}
		m=0;b=0;
		while(m<=3){
			a[m][n]=x[b];
			m=m+1;
			b=b+1;}
		m=0;b=0;

		while(b<=3){
			x[b]=0;
			b=b+1;}
		b=0;
		
		while(m<=2){
			if(a[m][n]==a[m+1][n]){
				k=m;
				while(k<=2){ 
					a[k][n]=a[k+1][n];
					k=k+1;}
                a[m][n]=a[m][n]*2;           
				a[k][n]=0;
				k=0;}
			m=m+1;}
		m=0;
		n=n+1;}
}

if(w=='d'){	
	n=3;b=3;m=0;k=0;
	while(m<=3){
		
		while(n>=0){
			if(a[m][n]!=0){
				x[b]=a[m][n];
				b=b-1;}
			n=n-1;}
		n=3;b=3;

		while(n>=0){
			a[m][n]=x[b];
			n=n-1;
			b=b-1;}
		n=3;b=3;

		while(b>=0){
			x[b]=0;
			b=b-1;}
		b=3;

		while(n>=1){
			if(a[m][n]==a[m][n-1]){
				k=n;
				while(k>=1){
					a[m][k]=a[m][k-1];
					k=k-1;}
                a[m][n]=a[m][n]*2;            
				a[m][k]=0;
				k=0;}
			n=n-1;}
		n=3;
		m=m+1;}
}

if(w=='s'){	
	m=3;b=3;n=0;k=0;
	while(n<=3){
		
		while(m>=0){
			if(a[m][n]!=0){
				x[b]=a[m][n];
				b=b-1;}
			m=m-1;}
		
		m=3;b=3;
		while(m>=0){
			a[m][n]=x[b];
			m=m-1;
			b=b-1;}
		m=3;b=3;

		while(b>=0){
			x[b]=0;
			b=b-1;}
		b=3;
		
		while(m>=1){
			if(a[m][n]==a[m-1][n]){
				k=m;
				while(k>=1){
					a[k][n]=a[k-1][n];
					k=k-1;}
                a[m][n]=a[m][n]*2;           
				a[k][n]=0;
				k=0;}
			m=m-1;}
		m=3;
		n=n+1;}

}
}
return 0;
}
