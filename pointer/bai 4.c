#include<stdio.h>
#include<stdlib.h>

void coppyArray(int *arr,int *arr1,int n){
	for(int i=0;i<n;i++){
		*(arr1+i)=*(arr+i);
	}
}
void deleteArray(int n,int arr[n]){
	for(int i=0;i<n;i++){
		arr[i]=0;
	}
}
void print(int n,int a[n]){
	for(int i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}

int main(){
	int arr[100];
	int newArr[100];
	int tempArray1[100],tempArray2[100];
	int n,m,currentIndex=0;
	int reverseArray[100];
	int num;
	do{
	    int new_arr[100];
		printf("\n1.Nhap vao mang\n");
		printf("2.In ra mang\n");
		printf("3.Sao chep vao mang khac\n");
		printf("4.Nhap vao mang khac,doi cho 2 mang voi nhau\n");
		printf("5.Dao nguoc mang\n");
		printf("6.Nhap vao 1 ky tu, tim kiem ky tu do trong mang\n");
		printf("7.Thoat\n");
		printf("Lua chon cua ban la:");
		int choice;
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Nhap so phan tu cua mang:");
				scanf("%d",&n);
				for(int i=0;i<n;i++){
					printf("arr[%d]=",currentIndex);
					scanf("%d",&arr[currentIndex]);
					currentIndex++;
				}
				break;
			case 2:
				for(int i=0;i<currentIndex;i++){
					printf("%d\t",*(arr+i));
				}
				break;
			case 3:
				coppyArray(arr,new_arr,currentIndex);
				for(int i=0;i<currentIndex;i++){
					printf("%d\t",new_arr[i]);
				}
				break;
			case 4:
				printf("Nhap so phan tu cua mang moi:");
				scanf("%d",&m);
				printf("Nhap vao mang moi:");
				for(int i=0;i<m;i++){
					printf("arr[%d]=",i);
					scanf("%d",&newArr[i]);
				}
				//sao chep chuoi arr sang tempArr1;
				coppyArray(arr,tempArray1,currentIndex);
				//sao chep chuoi newArr sang tempArr2;
				coppyArray(newArr,tempArray2,m);
				//xoa 2 mang da tao
				deleteArray(currentIndex,arr);
				deleteArray(m,newArr);
				//sao chep ve mang
				coppyArray(tempArray1,newArr,currentIndex);
				coppyArray(tempArray2,arr,m);
				currentIndex=m;
				break;
			case 5:
				coppyArray(arr,reverseArray,currentIndex);
	// dao nguoc mang
				for(int i=0;i<currentIndex;i++){
					*(arr+i)=*(reverseArray+currentIndex-i-1);
				}
				break;
			case 6:
				printf("Nhap vao 1 so bat ky");
				scanf("%d",num);
				for(int i=0;i<currentIndex;i++){
					if(*(arr+i)==num){
						printf("Phan tu thu %d co gia tri bang %d\n",i,num);
					}
				}
				break;
			case 7:
				exit(0);
			default:
				printf("Lua chon tu 1 den 7");
		}
	}while(1==1);
}
