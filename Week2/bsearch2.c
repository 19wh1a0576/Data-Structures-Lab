#include<stdio.h>
int binary_search(int first,int last,int a[50], int key)
{
	int mid;
	int pos = -1;
	if(first  <= last)
	{
		mid = (first + last)/2;
		if(a[mid] == key)
		{
			return mid;
		}
		else if(a[mid] < key)
		{
			binary_search(mid+1,last,a,key);
		}
		else
		{
			binary_search(first,mid-1,a,key);
		}

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
	pos =binary_search(0,n-1,a,key);
	if (pos == -1)
	{
		printf("element not found");
	}
	else
	{
		printf("element is at position %d",pos+1);
	}

}


		