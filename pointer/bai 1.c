#include<stdio.h>

int main(){
	int n=10;
	int *ptrN=&n;
	//in ra gia tri va dia chi cua bien
	printf("%d\n",n);
	printf("%d\n",&n);
	//in ra gia tri va dia chi cua bien
	printf("%d\n",*ptrN);
	printf("%d\n",ptrN);
}
