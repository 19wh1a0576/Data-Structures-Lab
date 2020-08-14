#include<stdio.h>
int linear_search(int n,int a[50], int key)
{
	static int i;
	if(a[i] == key)
	{
		return i;
	}
	else if(i<n)
	{
		i++;
		linear_search(n,a,key);
	}
	else
	{
		return -1;
	}
	
	
}
int main()
		
{
	int n,key,pos;
	scanf("%d",&n);
	int a[n];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&key);
	pos = linear_search(n,a,key);
	if (pos == -1)
	{
		printf("element not found");
	}
	
	else
	{
		printf("element is at position %d",pos+1);
	}

}


		
