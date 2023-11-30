#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int lengStr(char *str){
	int cnt=0;
	while(*str!='\0'){
		cnt++;
		str++;
	}
	return cnt;
}

void print(int n,char *str){
    for(int i=0;i<n;i++){
    	printf("%c",*(str+i));
	}
}
void cpyStr(char *str,char *new_str,int n){
	for(int i=0;i<n;i++){
		*(new_str+i)=*(str+i);
	}
}

int main(){
    char str[100];
    char new_str[100];
    char newStr[100];
    int length,lengthNew;
    char addStr[100];
	do{
		printf("\n1.Nhap vao chuoi\n");
		printf("2.In ra chuoi\n");
		printf("3.Sao chep vao chuoi khac\n");
		printf("4.Nhap vao chuoi khac,so sanh voi chuoi ban dau\n");
		printf("5.In ra chuoi dao nguoc\n");
		printf("6.Nhap vao chuoi khac, them chuoi do vao chuoi ban dau\n");
		printf("7.Thoat\n");
		printf("Lua chon cua ban la:");
		int choice;
		scanf("%d",&choice);
		switch(choice){
			case 1:
				getchar();
				gets(str);
				break;
			case 2:
				length=lengStr(str);
				print(length,str);
				break;
			case 3:
				length=lengStr(str);
				cpyStr(str,new_str,length);
				puts(new_str);
				break;
			case 4:
				length=lengStr(str);
				printf("Nhap vao chuoi khac:");
				getchar();
				fgets(newStr,100,stdin);
				lengthNew=lengStr(newStr);
				if(length<lengthNew){
					printf("chuoi moi dai hon");
				} else if(length=lengthNew){
					printf("2 chuoi dai bang nhau");
				}else{
					printf("chuoi moi ngan hon");
				}
				break;
			case 5:
				length=lengStr(str);
				for(int i=length-1;i>=0;i--){
					printf("%c",*(str+i));
				}
				break;
			case 6:
				//nhap chuoi khac
				getchar();
				length=lengStr(str);
				fgets(addStr,100-length,stdin);
				lengthNew=lengStr(addStr);
				//nhap chuoi moi vao chuoi goc
				for(int i=0;i<lengthNew;i++){
					*(str+i+length)=*(addStr+i);
				}
				break;
			case 7:
				exit(0);
			default:
				printf("Lua chon tu 1 den 7");
		}
	}while(1==1);
}
