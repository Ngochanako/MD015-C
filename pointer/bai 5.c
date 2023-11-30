#include<stdio.h>

void incSort(int n,int *arr){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(*(arr+j)>*(arr+j+1)){
				int temp=*(arr+j);
				*(arr+j)=*(arr+j+1);
				*(arr+j+1)=temp;
			}
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		printf("arr[%d]=",i);
		scanf("%d",&arr[i]);
	}
	incSort(n,arr);
	//in mang
	for(int i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}	
}
