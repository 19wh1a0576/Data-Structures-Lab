#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
char inf[100],pf[100],stack[100];
int i,j,top=-1;
void push(char x)
{
	top++;
	stack[top]=x;
}
char pop()
{
	return(stack[top--]);
}
int prec(char c)
{
	if(c=='*' || c=='/' || c=='%')
	return 4;
	else if(c=='+' || c=='-')
	return 3;
	if(c=='(')
	return 2;
}
void postfix(char in[100])
{
	char x;
	for(i=0;in[i]!='\0';i++)
	{
		if(in[i]=='(')
			push(in[i]);
		else if(isalpha(in[i]) || isdigit(in[i]))
			pf[j++]=in[i];
		else if(in[i]==')')
		{
			while(stack[top]!='(')
				pf[j++]=pop();
			x=pop();
		}
		else
		{
			while(prec(stack[top])>=prec(in[i]))
				pf[j++]=pop();
			push(in[i]);
		}
	
	}
	while(top!=-1)
		pf[j++]=pop();
	pf[j]='\0';

}
int main()
{
	printf("Enter infix expression\n");
	gets(inf);
	postfix(inf);
	printf("The postfix expression is:\n");
	puts(pf);
}
