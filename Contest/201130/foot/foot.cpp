#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
const int p=1e9+7;
int n,f[maxn][2];
char s1[20],s2[20];
int main(){
	freopen("foot.in","r",stdin);
	freopen("foot.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		strcpy(s1,s2); scanf("%s",s2);
		if(i==1){
			f[i][0]=1; f[i][1]=0;
			continue;
		}
		if(strcmp(s1,s2)==0){
			if(i==2){
				f[i][0]=1; f[i][1]=0;
				continue;
			}
			f[i][0]=(f[i-1][0]+f[i-1][1])%p;
		}else{
			if(i==2){
				f[i][1]=1; f[i][0]=1;
				continue;
			}
			f[i][0]=(f[i-1][0]+f[i-1][1])%p;
			f[i][1]=(f[i-2][0]+f[i-2][1])%p;
		}
	}
	printf("%d\n",(f[n][0]+f[n][1])%p);
	fclose(stdin); fclose(stdout);
	return 0;
}
