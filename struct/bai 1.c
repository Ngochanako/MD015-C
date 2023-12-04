#include<stdio.h>

struct Student{
		char name[50];
		int age;
		char phone[20];
		char email[50];
	};

int main(){
	int n;
	printf("Nhap so sinh vien");
	scanf("%d",&n);	
	struct Student listStudent[n];
	for(int i=0;i<n;i++){
		getchar();
		printf("Nhap ten sinh vien:");
		fgets(listStudent[i].name,50,stdin);
		printf("Nhap tuoi sinh vien:");
		scanf("%d",&listStudent[i].age);
		printf("Nhap so dien thoai sinh vien:");
		scanf("%20s",&listStudent[i].phone);
		printf("Nhap email sinh vien:");
		scanf("%50s",&listStudent[i].email);
	}
	for(int i=0;i<n;i++){
		printf("%20s %5d %20s %20s\n",listStudent[i].name,listStudent[i].age,listStudent[i].phone,listStudent[i].email);
	}
}
