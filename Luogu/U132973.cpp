#include <bits/stdc++.h>
using namespace std;
char s[10];
int todec(char c){
	if(isdigit(c)) return c-'0';
	return c-'A'+10;
}
char t[4];
void tohex(int x){
	int a=x/16,b=x%16;
	if(a<=9) t[1]=a+'0';
	else t[1]=a-10+'A';
	if(b<=9) t[2]=b+'0';
	else t[2]=b-10+'A';
}
int main(){
	scanf("%s",s); putchar('#');
	tohex(255-todec(s[1])*16-todec(s[2]));
	printf("%s",t+1);
	tohex(255-todec(s[3])*16-todec(s[4]));
	printf("%s",t+1);
	tohex(255-todec(s[5])*16-todec(s[6]));
	printf("%s",t+1);
	return 0;
}
