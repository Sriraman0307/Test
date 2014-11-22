#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
int main()
{
	int i,j,Vert,randcheck,MaxEdges,edges,adj[10][10];
	int count=0,degseq=0;
	int Emergency = 0;
	float density;
	clrscr();
	while(1)
	{
		printf("Enter the number of vertices\n");
		scanf("%d",&Vert);
		if(Vert<5 || Vert>10)
		{
			printf("Enter values between 5 and 10\n");
		}
		else{break;}
	}
	while(1)
	{

		printf("Enter the density\n");
		scanf("%f",&density);
		if(density<0.3 || density>0.7)
		{
			printf("Enter values between 0.3 and 0.7\n");
		}
		else{break;}
	}
	MaxEdges=Vert*(Vert-1)/2;
	edges = density*MaxEdges;
	printf("Max Edges = %d\n",edges);
	/*Creating the upper triangular matrix*/
	for(i = 1; i <=Vert; i++)
	{
		for(j = 1; j <=Vert; j++)
			adj[i][j]=0;
	}
	while(count<edges || Emergency<10000)
	{
		for(i=1;i<Vert;i++)
		{
			for(j=i;j<Vert;j++)
			{
				if(adj[i][j]!=1 && j!=i)
				{
					srand (time(NULL));
					randcheck=rand()%2;
					if(randcheck==0 && count<edges)
					{
						adj[i][j]=1;
						count++;
					}
				}
			}
		}
		Emergency++;
	}
	for(i = 1; i <= Vert; i++)
	{
		for(j = 1; j <= Vert; j++)
		{
			if(adj[i][j]==1)
				adj[j][i]=1;
			else
				adj[j][i]=0;
		}
	}
	printf("\n");
	for(i = 1; i <= Vert; i++)
	{
		for(j = 1; j <= Vert; j++)
			printf("%d\t",adj[i][j]);
		printf("\n");
	}
	printf("Degree Sequence:\n");
	for(i=1;i<=Vert;i++)
	{
		for(j=1;j<=Vert;j++)
		{
			if(adj[i][j]==1)
				degseq++;
		}
		printf(" %d,",degseq);
		degseq=0;
	}
	return(0);
}