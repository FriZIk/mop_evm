#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct query
{
	int value;
	int t_start;
	int t_finish;
	int sum;
};
typedef struct query query;

int main()
{
	setlocale(P_ALL,"Russian");
	printf("Введите количество элементов:");
	int count = 0;
	int MaxSum = 0;

	scanf("%d",&count);
	query *Query = (query*)malloc(sizeof(query) * count);

	for(int i = 0;i < count;i++)
	{
		scanf("%d %d %d",&Query[i].value,&Query[i].t_start,&Query[i].t_finish);
		if(i > 0)
		{
			for(int j = 0;j < i;j++)
			{
				int t11,t12,t21,t22;
				t11 = Query[i].t_start;
				t12 = Query[i].t_finish;
				t21 = Query[j].t_start;
				t22 = Query[i].t_finish;
				if(((t11<t22 && t12>t21)||(t21<t12 && t22>t11)) && !((t11==t22)||(t21==t12)))
					Query[i].sum += Query[j].sum;
			}
		}
		Query[i].sum += Query[i].sum;
		if(Query[i].sum > MaxSum)
			MaxSum = Query[i].sum;
	}
	printf("%d",MaxSum);
	free(Query);	
	return 0;
}

