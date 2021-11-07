#include <stdlib.h>//这一段随机数生成是直接从网上扒下来的，
#include <stdio.h> //因为我死活看不懂随机数生成的原理......（汗）
#include <time.h> //好吧其实就是赶时间没来得及看，毕竟是一个星期整出来的东西，
int main( )        //以后慢慢补吧^_^
{int a[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};//因为水平不够，
int x[4]={0,0,0,0};                                    //这个程序存在一个严重的bug（我怀疑问题出在随机数那里，但是我搞不定），
	int num=0,i=0,m=0,n=0,k=0,b=0,max=0;               //而且运行速度不尽如人意，但这是我撸了一个星期才搞定的，不忍心废弃，于是就上传了，
	char w=' ' ;                                       //将就着看吧

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
	while(m<=3){                          //这十几行代码至少花了我四五个小时......
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
		n=0;b=0;                          //把非0数字移到屏幕边缘

		while(b<=3){
		x[b]=0;
		b=b+1;}
		b=0;
	
		while(n<=2){
			if(a[m][n]==a[m][n+1]){
				//表达式a[m][n]=a[m][n]*2放在这里就不会执行，为什么啊
				k=n;
				while(k<=2){
					a[m][k]=a[m][k+1];
					k=k+1;}
                a[m][n]=a[m][n]*2;   //放这就能执行了......            
				a[m][k]=0;
				k=0;}
			n=n+1;}
		n=0;                            //数字合并
		m=m+1;}
}
//不管了，能用就行，反正程序也不复杂

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
