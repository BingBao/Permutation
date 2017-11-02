//字典序全排列生成 
#include<stdio.h>
int mid[20];//中介数 mid[i]：第i位右边比当前位数字小的个数 
int re[21];//排列 
int flag[21];//flag[i]=1:表示 i这个数字在一个排列中已经排好了 
int main(){
	int n;
	while (scanf("%d", &n) != EOF)//表示对1~n进行全排列生成
	{
		int i;
		if (n == 1){
			printf("%d\n", 1);
			continue;
		}
		for (i = 1; i <= n; i++)
		{
			mid[i] = 0;//中介数的起始值每位都是0 
		}
		for (i = 1; i <= n; i++)
		{
			flag[i] = 0;//初始时，每一位上都没有数字 
		}
		while (mid[n] != n)
		{
			//根据中介数 得到排列并输出 从最高位开始得到 
			for (i = n; i >= 1; i--)
			{
				
				
				//在没有被排过的数中 找出第mid[i]+1个小的数 那么 re[i]=这个数
				int j;
				int num=0;
				for(j=1;j<=n;j++){
					if(flag[j]==0){
						num++;
					}
					if(num==mid[i]+1){
						re[i]=j;
						flag[j]=1;
						break;
					}
				}
					
			}
			//输出一个排列 
			for (i = n; i >= 1; i--){
				printf("%d", re[i]);
				re[i] = 0;
			}
			printf(" ");
			for (i = 1; i <= n; i++)
			{
				flag[i] = 0;//初始时，每一位上都没有数字 
			}
			//中介数+1
			for (i = 2; i <= n; i++)
			{

				if (mid[i] + 1 >= i){
					if (i == n)
					{
						mid[i] = n;
						break;
					}
					mid[i] = mid[i] + 1 - i;
				}
				else{
					mid[i]++;
					break;
				}

			}

		}
		printf("\n");
	}
}
