#include <cstdio>
#include <cstring>
using namespace std;
int t,n,m;
char s[107];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%s",&n,&m,s+1);
		for(int i=1,l,r;i<=m;i++){
			scanf("%d%d",&l,&r);
			if(l==r){
				puts("NO");
				continue;
			}else{
				bool f1=false,f2=false;
				for(int i=1;i<l;i++) f1|=(s[i]==s[l]);
				for(int i=r+1;i<=n;i++) f2|=(s[i]==s[r]);
				puts((f1||f2)?"YES":"NO");
			}
		}
	}
	return 0;
}
