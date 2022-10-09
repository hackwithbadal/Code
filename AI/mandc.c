#include<stdio.h>
int move(int,int);
int rmove(int,int);
int m=3,c=3,m1=0,c1=0;
void main()
{
	int flag=1,p,q,r,a[20],b[20],i=0,x,z,n;
	printf("\nRules are:\n 1.Boat capacity = 2\n 2.entered m and c must be >=3\n 3.m and c values must also be less than available m and c values at river sides\n 4.m=c=0 not possible for moving boat\n \t\t ***********************START PLAYING********************* \n");
	while(flag==1)
	{
		printf("\nleft side=>(%dM,%dC)///// <bo(M,C)at> ==> ///// right side=>(%dM,%dC) \n",m,c,m1,c1);
		printf("Enter m and c to move from left to right\n");
		scanf("%d%d",&p,&q);
		r=move(p,q);
		if(r==1)
		{
			a[i]=p;
			b[i]=q;
			flag=1;
			i++;
			if(m1==3 && c1==3)
			{
					printf("solution found\n\n\n\n ********************Succesful***********\n");
					break;
			}
		}
		else
		{
			printf("Not possible move\n \n\n\n ********************Game Over***********\n");
			flag=0;
		}
		if(flag==1)
		{
			printf("\nleft side=>(%dM,%dC)///// <== <bo(M,C)at> ///// right side=>(%dM,%dC)\n",m,c,m1,c1);
			printf("Enter m and c to move from right to left\n");
			scanf("%d%d",&x,&z);
			r=rmove(x,z);
			if(r==1)
			{
				a[i]=x;
				b[i]=z;
				flag=1;
				i++;				
			}
			else
			{
				printf("move Not possible \n\n\n\n ********************Game Over***********\n");
				flag=0;
			}
		}
		
		
	}
		n=0;
		printf("Moves taken are:\n");
		while(n<i)
		{
			printf("\\\\<(%dM,%dC)>\\\\\ \n",a[n],b[n]);
			n++;
		}
		return 0;
}

int move(int e,int f)
{
	m=m-e;
	c=c-f;
	m1=m1+e;
	c1=c1+f;
	if(m!=0 && m1!=0)
	{
		if(m<c||m1<c1)
			return (0);
		else
			return (1);
	}
	else if(m==0 || m1==0)
		return (1);
	return 0;
}

int rmove(int g,int h)
{
	m1=m1-g;
	c1=c1-h;
	m=m+g;
	c=c+h;
	if(m!=0&&m1!=0)
	{
		if(m<c||m1<c1)
			return (0);
		else
			return (1);
	}
	else if(m1==0 || m==0)
			return (1);
	return 0;
}


// Rules are:
//  1.Boat capacity = 2
//  2.entered m and c must be >=3
//  3.m and c values must also be less than available m and c values at river sides
//  4.m=c=0 not possible for moving boat
//  		 ***********************START PLAYING********************* 

// left side=>(3M,3C)///// <bo(M,C)at> ==> ///// right side=>(0M,0C) 
// Enter m and c to move from left to right
// 3 3
// solution found



//  ********************Succesful***********
// Moves taken are:
// \\<(3M,3C)>\\ 
