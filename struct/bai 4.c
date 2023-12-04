#include<stdio.h>
#include<string.h>

struct Books{
	char code[20];
	char name[50];
	char author[50];
	int price;
	char type[20];
};

typedef struct Books BK;
//ham nhap phan tu cua mang
void input(BK *list,int i){
	printf("Nhap ma sach:");
	scanf("%20s",list[i].code);
	getchar();
	printf("Nhap ten sach:");
	fgets(list[i].name,50,stdin);
	list[i].name[strlen(list[i].name)-1]='\0';
	printf("Nhap ten tac gia:");
	fgets(list[i].author,50,stdin);
	list[i].author[strlen(list[i].author)-1]='\0';
	printf("Nhap gia sach:");
	scanf("%d",&list[i].price);
	getchar();
	printf("Nhap loai sach:");
	fgets(list[i].type,20,stdin);
	list[i].type[strlen(list[i].type)-1]='\0';
}
//ham xuat phan tu cua mang
void print(BK list){
	printf("%10s",list.code);
	printf("%20s",list.name);
	printf("%20s",list.author);
	printf("%10d",list.price);
	printf("%20s",list.type);
}
//ham xuat mang
void printN(BK list[],int currentIndex){
	for(int i=0;i<currentIndex;i++){
		print(list[i]);
		printf("\n");
	}}
//ham them phan tu vao vi tri
void addBook(int n,int *currentIndex,BK list[],BK *listBook){
	if(n<0||n>999){
		printf("Nhap vi tri them lon hon bang 0 va nho hon 1000");
	}else{
		if(n>=*currentIndex){
//			for(int i=currentIndex;i<n;i++){
//				list[i]=;
//			}
			input(listBook,n);
			*currentIndex=n+1;
		} else{
			for(int i=*currentIndex;i>n;i--){
				list[i]=list[i-1];
			}
			input(listBook,n);
			(*currentIndex)++;
		}
	}
}
//ham xoa sach theo ma sach
void deleteBook(int *n,BK list[],char id[]){
	int check=1;
	for(int i=0;i<*n;i++){
		if(strcmp(list[i].code,id)==0){
			check=0;
			for(int j=i;j<*n;j++){
				list[j]=list[j+1];
			}
			(*n)--;
			break;
		}
	}
	if(check){
		printf("Khong co sach co ma can xoa");
	}
}
//ham cap nhap thong tin sach theo ma sach
void updateBook(int n,char id[],BK *list){
	int check=1;
	for(int i=0;i<n;i++){
		if(strcmp((list+i)->code,id)==0){
			input(list,i);
		}
	}
}
//ham sap xep sach theo gia tang
void incSort(int n,BK list[]){
	for(int i=0;i<n;i++){
		BK tmpBook;
		for(int j=0;j<n-i-1;j++){
			if(list[j].price>list[j+1].price){
				tmpBook=list[j];
				list[j]=list[j+1];
				list[j+1]= tmpBook;
			}
		}
	}
}
int main(){
	BK listBook[1000];
	int n,indexAdd;
	char idDelete[20],idUpdate[20],lookBook[50];
	int priceUp,priceDown;
	int currentIndex=0;
	do{
		printf("\n1.Nhap thong tin sach\n");
		printf("2.In thong tin sach\n");
		printf("3.Them sach\n");
		printf("4.Xoa sach theo ma sach\n");
		printf("5.Cap nhap thong tin sach theo ma sach\n");
		printf("6.Sap xep sach theo gia tang\n");
		printf("7.Tim kiem sach theo ten sach\n");
		printf("8.Tim kiem sach theo khoang gia\n");
		printf("Lua chon cua ban la:");
		int choice;
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Nhap so sach can ghi thong tin");
	            scanf("%d",&n);
				for(int i=0;i<n;i++){
					input(listBook,i);
					currentIndex++;
				}
				printN(listBook,currentIndex);				
			   break;
			case 2:
			   printN(listBook,currentIndex);
			   break;
			case 3:
			   scanf("%d",&indexAdd);
			   addBook(indexAdd,&currentIndex,listBook,listBook);
			   printf("%d\n",currentIndex);
			   printN(listBook,currentIndex);	
			   break;
			case 4:
               scanf("%20s",idDelete);
               deleteBook(&currentIndex,listBook,idDelete);
               printN(listBook,currentIndex);
			   break;
			case 5:
				scanf("%20s",idUpdate);
				updateBook(currentIndex,idUpdate,listBook);
				 printN(listBook,currentIndex);
				break;
			case 6:
         		incSort(currentIndex,listBook);
				 printN(listBook,currentIndex);
                break;
			case 7:
				printf("Nhap ten sach can tim kiem:");
				fgets(lookBook,50,stdin);
				lookBook[strlen(lookBook)-1]='\0';
				for(int i=0;i<currentIndex;i++){
					if(strcmp(listBook[i].name,lookBook)==0){
						print(listBook[i]);
						printf("\n");
					}
				}
				break;
			case 8:
				printf("Nhap khoang gia can tim kiem, gia be nhap truoc, gia lon nhap sau:");
				scanf("%d%d",priceDown,priceUp);
				for(int i=0;i<currentIndex;i++){
					if(listBook[i].price>=priceDown && listBook[i].price<=priceUp){
						print(listBook[i]);
						printf("\n");
					}
				}
				break;
			default:
			   printf("Lua chon tu 1 den 8");	
		}
	}while(1==1);
}
