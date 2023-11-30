#include<stdio.h>

int swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

int main(){
	int a=10,b=5;
	int *ptrA=&a;
	int *ptrB=&b;
	printf("Hieu cua 2 so truoc khi doi cho :%d",a-b);
	swap(ptrA,ptrB);
	printf("\nHieu cua 2 so truoc khi doi cho :%d",a-b);
}

