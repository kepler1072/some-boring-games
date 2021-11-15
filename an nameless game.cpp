#include<stdio.h>//这个程序是负责判断胜利的，也就是最终程序
int main(){
	char a[7]={'d','d','d','_','b','b','b'},t=0;
	int flag=0,int in=0;
	printf("你好！");
	printf("这是个很简单的小游戏，只要把b和d全部换个位置，你就赢了\n");
	printf("“b”和“d”可以前进一步或两步，但只能前进到“_”处且不能后退\n");
    printf("使用键盘上的数字键控制对应位置的“b”或“d”移动\n");
    printf("另外，由于开发时间不足（我懒），这个游戏没有后撤键，走错了请重来哦^_^\n");
	printf("由于是v1.0版本，可能存在bug，多多见谅\n");
	printf("1234567\n");
	puts(a);
	for( ;flag==0; ){
		if(a[0]=='b'&&a[1]=='b'&&a[2]=='b'&&a[3]=='_'&&a[4]=='d'&&a[5]=='d'&&a[6]=='d'){
			flag=1;
		}
		else{
		scanf("%d",&in);
	if (a[in-1]=='d'){
		if(a[in]=='_'){
		t=a[in-1];
		a[in-1]=a[in];
		a[in]=t;}
		else if(a[in+1]=='_'){
		t=a[in-1];
		a[in-1]=a[in+1];
		a[in+1]=t;
	}}
	else if(a[in-1]=='b'){
		if(a[in-2]=='_'){
		t=a[in-1];
		a[in-1]=a[in-2];
		a[in-2]=t;}
		else if(a[in-3]=='_'){
		t=a[in-1];
		a[in-1]=a[in-3];
		a[in-3]=t;
	}}
		
    printf("1234567");
	printf("%s\n",a);
		}
	}
	printf("恭喜！你赢了！很简单又很好玩的一个小游戏，不是么？\n");
	return 0;
}