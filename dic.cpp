//�ֵ���ȫ�������� 
#include<stdio.h>
int mid[20];//�н��� mid[i]����iλ�ұ߱ȵ�ǰλ����С�ĸ��� 
int re[21];//���� 
int flag[21];//flag[i]=1:��ʾ i���������һ���������Ѿ��ź��� 
int main(){
	int n;
	while (scanf("%d", &n) != EOF)//��ʾ��1~n����ȫ��������
	{
		int i;
		if (n == 1){
			printf("%d\n", 1);
			continue;
		}
		for (i = 1; i <= n; i++)
		{
			mid[i] = 0;//�н�������ʼֵÿλ����0 
		}
		for (i = 1; i <= n; i++)
		{
			flag[i] = 0;//��ʼʱ��ÿһλ�϶�û������ 
		}
		while (mid[n] != n)
		{
			//�����н��� �õ����в���� �����λ��ʼ�õ� 
			for (i = n; i >= 1; i--)
			{
				
				
				//��û�б��Ź������� �ҳ���mid[i]+1��С���� ��ô re[i]=�����
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
			//���һ������ 
			for (i = n; i >= 1; i--){
				printf("%d", re[i]);
				re[i] = 0;
			}
			printf(" ");
			for (i = 1; i <= n; i++)
			{
				flag[i] = 0;//��ʼʱ��ÿһλ�϶�û������ 
			}
			//�н���+1
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
