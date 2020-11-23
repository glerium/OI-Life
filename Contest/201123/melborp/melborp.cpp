#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=5e6+10;
int n,ix[maxn][26];
char s[maxn];
int main(){
	freopen("melborp.in","r",stdin);
	freopen("melborp.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	//[1,i),[i,j),[j,k),[k,l),[l,n]
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k;l<=n+1;l++){
					int x=1,y=n;
					if(x==i) x=j;
					if(x==k) x=l;
					if(y==l-1) y=k-1;
					if(y==j-1) y=i-1;
					bool flag=true;
					while(x<y){
						if(s[x]!=s[y]){
							flag=false;
							break;
						}
						x++,y--;
						if(x==i) x=j;
						if(x==k) x=l;
						if(y==l-1) y=k-1;
						if(y==j-1) y=i-1;
					}
					if(flag) ans=max(ans,i-1+k-j+n-l+1);
				}
			}
		}
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
