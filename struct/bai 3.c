#include<stdio.h>
#include<string.h>

struct Student{
	char code[20];
	int age;
	char phone[20];
	char email[20];
};
typedef struct Student SV;
//ham nhap phan tu
void input(SV *listStudent,int currentIndex){
		printf("Nhap ma sinh vien:");
					scanf("%20s",listStudent[currentIndex].code);
					printf("Nhap tuoi:");
					scanf("%d",&listStudent[currentIndex].age);
					printf("Nhap so dien thoai:");
					scanf("%20s",listStudent[currentIndex].phone);
					printf("Nhap email:");
					scanf("%20s",listStudent[currentIndex].email);
}
//ham xuat phan tu mang
void print(SV list){
	printf("%10s",list.code);
	printf("%10d",list.age);
	printf("%20s",list.phone);
	printf("%20s",list.email);
}
void printN(SV listStudent[],int currentIndex){
	for(int i=0;i<currentIndex;i++){
		print(listStudent[i]);
		printf("\n");
	}					
}
//ham sua thong tin theo id
void edit(int i,SV *listStudent){
	printf("Nhap tuoi:");
	scanf("%d",&listStudent[i].age);
	printf("Nhap so dien thoai:");
	scanf("%20s",listStudent[i].phone);
	printf("Nhap email:");
	scanf("%20s",listStudent[i].email);
}
//ham xoa thong tin theo id
void deleteN(SV list[],char id[],int n){
	int check=0;
	for(int i=0;i<n;i++){
		if(strcmp(list[i].code,id)==0){
			check=1;
			for(int j=i;j<n;j++){
				list[j]=list[j+1];
			}
			break;
		}
	}
	if(check=0){
		printf("Khong co ma sinh vien la %s",id);
	}
}

int main(){
	int n,m;
	struct Student listStudent[1000];
	char id[20];
	int currentIndex=0;
	do{
		printf("\n1.Nhap sinh vien\n");
		printf("2.Them sinh vien\n");
		printf("3.Sua thong tin\n");
		printf("4.Xoa thong tin\n");
		printf("Lua chon cua ban la:");
		int choice;
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Nhap so sinh vien");
	            scanf("%d",&n);
				for(int i=0;i<n;i++){
					input(listStudent,currentIndex);
					currentIndex++;
				}
				printN(listStudent,currentIndex);				
			   break;
			case 2:
				printf("Nhap so sinh vien can them");
	            scanf("%d",&m);
				for(int i=0;i<m;i++){
					input(listStudent,currentIndex);
					currentIndex++;
				}
				printN(listStudent,currentIndex);
			   break;
			case 3:
					printf("Nhap ma sinh vien can sua:");
					scanf("%20s",&id);
					for(int i=0;i<currentIndex;i++){
						if(strcmp(listStudent[i].code,id)==0){
							printf("Cap nhap thong tin co ma sinh vien la %s:\n",id);
						    edit(i,listStudent);
						    break;
						}
					}
					printN(listStudent,currentIndex);
			   break;
			case 4:
				printf("Nhap ma sinh vien can xoa");
				scanf("%20s",&id);
				deleteN(listStudent,id,currentIndex);
				currentIndex--;
				printN(listStudent,currentIndex);
               
			   break;
			default:
			   printf("Lua chon tu 1 den 4");	
		}
	}while(1==1);
	
}
