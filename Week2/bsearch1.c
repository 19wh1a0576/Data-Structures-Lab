#include<stdio.h>
int binary_search(int first,int last,int a[50], int key)
{
	int mid;
	int pos = -1;
	while(first  <= last)
	{
		mid = (first + last)/2;
		if(a[mid] == key)
		{
			pos = mid;
			break;
		}
		else if(a[mid] < key)
		{
			first = mid + 1;
		}
		else
		{
			last = mid - 1;
		}

	}	
	return pos;
	
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
	pos = binary_search(0,n-1,a,key);
	if (pos == -1)
	{
		printf("element not found");
	}
	else
	{
		printf("element is at position %d",pos+1);
	}

}


		
