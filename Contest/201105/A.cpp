#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1e5+10;
int t,n,w[30],r[maxn];
bool vcnt=false;
char s[maxn],tos[10][4]={"a","n","an","v","av","nv","anv"};
bool A(int x){return x&1;}
bool N(int x){return x&2;}
bool V(int x){return x&4;}
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		vcnt=0;
		
		for(int i=0;i<26;i++) scanf("%d",&w[i]);
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=1;i<=n;i++) r[i]=w[s[i]-'a'];
		bool varu=false;
		if(n<3){
			puts("No");
			goto end;
		}
//		for(int i=1;i<=n;i++) printf("%s ",tos[r[i]-1]);
		if(r[1]==4||r[n]==1||r[n]==4){
			puts("No");
			goto end;
		}
		for(int i=1;i<=n;i++){
			if(r[i]==4){
				if(vcnt){
					puts("No");
					goto end;
				}
				vcnt=true;
			}
			else if(r[i-1]==1&&r[i]==4){
				puts("No");
				goto end;
			}
		}
		for(int i=2;i<=n-1;i++)
			if(V(r[i])&&r[i-1]!=1) varu=true;
		if(!varu) puts("No");
		else puts("Yes");
end:;
	}
	return 0;
}
