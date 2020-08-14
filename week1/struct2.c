#include<stdio.h>
struct student
{
	char name[30];
	char rollno[10];
	int m[4];

};

int main()
{
	struct student s[30];
	int i,j,n;
	float avg,sum;
	char grade;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		sum = 0;
		scanf("%s",s[i].rollno);
		scanf("%s",s[i].name);
		for(j=0;j<4;j++)
		{
			scanf("%d",&s[i].m[j]);  
			sum = sum + s[i].m[j];
		}
		avg = sum/4.0;
		if(avg >= 50.0)
		{
			grade = 'A';
		}
		else
		{
			grade = 'B';
		}
	}
	for(i=0;i<n;i++)
	{
		printf("rollno = %s\t name = %s\t grade = %c\n",s[i].rollno,s[i].name,grade);
	}
	
}
