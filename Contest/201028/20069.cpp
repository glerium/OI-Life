#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1e3+10;
char s[maxn],t[maxn];
int n,len;
int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%s%d",s+1,&n);
	len=strlen(s+1);
	for(int i=1;i<=n;i++){
		scanf("%s",t+1);
		int lpcnt=0,j=1,k=1;
		int lent=strlen(t+1);
		for(j=1;j<=lent;){
//			printf("%d \n",j);
			if(k==len+1) k=1,lpcnt++;
			for(;k<=len&&j<=lent;k++){
				if(k==len+1) k=1,lpcnt++;
//				printf(":%d %d %c %c\n",j,k,s[k],t[j]);
				if(s[k]==t[j]||t[j]=='*'){
					k++,j++;
					break;
				}
			}
		}
		printf("%d\n",lpcnt*len+k-1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
