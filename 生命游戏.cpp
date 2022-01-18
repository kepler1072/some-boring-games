/***********************************************************
每个细胞有两种状态——存活或者死亡，每个细胞只与以其自身为中心的细胞产生互动。

当细胞为死亡状态，若周围有3个存活细胞，则该细胞变成存活状态(模拟繁殖)

当细胞为存活状态，若周围有2个或3个存活细胞，保持原样

　　　　若周围有3个以上存活细胞，该细胞变成死亡(模拟极度拥挤)

　　　　若周围有2个以下存活细胞，该细胞死亡(模拟人口稀疏)
*************************************************************/
#include<stdio.h>
#include<Windows.h>
int main(){
	int a[10][10]={0},b[10][10]={0},x=0,y=0,round=0;
	int *pa[10],*pb[10];//用一维指针运算二维数组，没错，我又是闲的
	int i,j,li,lj,ni,nj,t;
	for (i=0;i<=9;i++){
		pa[i]=&a[i][0];
	    pb[i]=&b[i][0];} //建立指针
	for(i=0;i<=9;i++){
		for(j=0;j<=9;j++){
			printf("%d  ",a[i][j]);}
		printf("%d\n\n",i+1);}
//显示初始矩阵
	
	scanf("%d,%d",&x,&y);  //输入格式为“x，y”，当x或y超出范围时结束输入
	while(x>=1&&x<=10||y>=1&&y<=10){
	    a[y-1][x-1]=1-a[y-1][x-1];//重复输入同一格数据可置零
    	for(i=0;i<=9;i++){
		    for(j=0;j<=9;j++){
			    printf("%d  ",a[i][j]);}
		    printf("%d\n\n",i+1);}
		scanf("%d,%d",&x,&y);}

//单次输入（这里依然有问题，不会print）//输入模块成功了！芜湖！！！（2021.12.2）
//以上为输入模块（现在支持多次输入了）


while(1){
	for(i=0;i<=9;i++){
		for(j=0;j<=9;j++){
	        b[i][j]=a[i][j];}
			}
//第一步：将原数组存入b（n）

	for(i=0;i<=9;i++){
		for(j=0;j<=9;j++){                   //关于i-1<0和i+1>9该如何处理，应该可以使用约瑟夫环
		        li=(i+9)%10;lj=(j+9)%10;ni=(i+1)%10;nj=(j+1)%10;
				round=0;              
				pa[i]=&a[i][j];    
				pa[li]=&a[li][j];    //检测上方一行对应单元
				pa[ni]=&a[ni][j];    //检测下方一行对应单元
				round=round+*pa[i]+*pa[li]+*pa[ni];    //正中央列数据叠加
			    
				pa[i]=&a[i][nj];
				pa[li]=&a[li][nj];
				pa[ni]=&a[ni][nj];
				round=round+*pa[i]+*pa[li]+*pa[ni];    //右侧列数据叠加

				pa[i]=&a[i][lj];
				pa[li]=&a[li][lj];
				pa[ni]=&a[ni][lj];
				round=round+*pa[i]+*pa[li]+*pa[ni];    //左侧列数据叠加

				pa[i]=&a[i][j];
				pb[i]=&b[i][j];

				if(*pa[i]==0){
					if(round==3){
				    *pb[i]=1;}}      //此时round值为以a[i][j]为中心且包含a[i][j]的九宫格的数值
				else if(*pa[i]==1){
					if(round==4||round==3){
						*pb[i]=1;}
					else{*pb[i]=0;}}
				//a[i][j]单元生死判断,结果在b（n）中显示

		}
	}
//第二步，计算某个单元的生死并在b（n）中表示（无报错）

	for(i=0;i<=9;i++){
		pa[i]=&a[i][0];
		pb[i]=&b[i][0];
		for(j=0;j<=9;j++){
			*pa[i]=*pb[i];
			printf("%d  ",*pb[i]);
			*pb[i]=0;
			pa[i]=pa[i]+1;
			pb[i]=pb[i]+1;
		}
		printf("\n\n");
	}
	printf("-------------------------------------------------\n\n");
//第三步，b（n）中的数组存回a（n），b（n）显示并置零，准备开始下一轮循环（未报错）

//运算模块  思路：先将原数组存至暂存数组b（n）中，再分别计算每个单元的生死，并在b（n）中叠加
	
Sleep(1*1000);
}

	return 0;
}
