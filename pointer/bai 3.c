#include<stdio.h>
#include<string.h>
int strenglen(char *str){
	int cnt=0;
	while(*str!='\0'){
		cnt++;
		str++;
	}
	return cnt;
}

int main(){
    char str1[100],str2[100];
    gets(str1);
    gets(str2);
    printf("Do dai chuoi 1 la %d\n",strenglen(str1));
	printf("Do dai chuoi 2 la %d\n",strenglen(str2));	
	if(strenglen(str1)>strenglen(str2)){
		printf("Chuoi 1 dai hon chuoi 2");
	}else if(strenglen(str1)<strenglen(str2)){
		printf("Chuoi 2 dai hon chuoi 1");
	}else{
		printf("Chuoi 2 dai bang chuoi 1");
	}
}
