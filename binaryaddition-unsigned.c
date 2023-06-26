#include<stdio.h>
#include<math.h>
void decimaltobinary(int,int[]);
int binarytodecimal(int[]);
void showbinary(int[],int);
void showbinary1(int numb[]);
int addbinary(int[],int[],int[]);
void main()
{
	int num,dec,num1,sum;
	int numb[8]={0,0,0,0,0,0,0,0};
	int numb1[8]={0,0,0,0,0,0,0,0};
	int result[8]={0,0,0,0,0,0,0,0};
	printf("Enter decimal number: ");
	scanf("%d",&num);
	printf("Enter decimal number: ");
	scanf("%d",&num1);
	decimaltobinary(num,numb);
	decimaltobinary(num1,numb1);
	showbinary(numb,num);
	showbinary(numb1,num1);
	sum=addbinary(numb,numb1,result);
	if(!sum)
	{
		showbinary1(result);
		dec=binarytodecimal(result);
		printf("equivalent decimal: %d\n",dec);
	}
	else
	{
		printf("overflow");
	}
	
}
int addbinary(int numb[8],int numb1[8],int result[8])
{
	int i,c=0;
	for(i=7;i>=0;i--)
	{
		result[i]=(numb[i] ^ numb1[i] ^ c);
		c=((numb[i] & numb1[i]) | (numb[i] & c) | (numb1[i] & c));
	}
	result[i]=c;
	return c;
}
void decimaltobinary(int num,int numb[8])
{
	int rem,i=7;
	while(num!=0)
	{
		rem=num%2;
		numb[i--]=rem;
		num=num/2;
	}
}
int binarytodecimal(int numb[])
{
	int i,dec=0,j=7;
	for(i=0;i<8;i++)
	{
		dec=dec+numb[j--]*pow(2,i);
	}
	return dec;
}
void showbinary(int numb[8],int num)
{
	int i;
	printf("binary of %d :",num);
		for(i=0;i<8;i++)
	{
		printf("%d",numb[i]);
	}
	printf("\n");
}
void showbinary1(int numb[8])
{
	int i;
	printf("equivalent binary: ");
		for(i=0;i<8;i++)
	{
		printf("%d",numb[i]);
	}
	printf("\n");
}
