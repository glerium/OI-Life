#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int p=998244353;
int t,n,sz,q,fail[maxn];
ll s[maxn];
char u[maxn];
ll qpow(ll x,ll y){
	ll ans=1;
	while(y){
		if(y&1) ans=ans*x%p;
		x=x*x%p,y>>=1;
	}
	return ans;
}
void getfail(int l){
	for(int i=l;i<sz;i++){
		int j=fail[i];
		while(u[i]!=u[j]&&j) j=fail[j];
		if(u[j]==u[i]) fail[i+1]=j+1;
	}
}
int main(){
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		sz=0;
		memset(fail,0,sizeof(fail));
		scanf("%s%d%d",u,&n,&q);
		sz=strlen(u);
		int cur=1;
		while(sz<=n){
			getfail(cur);
//			for(int i=1;i<=sz;i++) printf("%d ",fail[i]);
			cur=sz;
			int odsz=sz,k=fail[odsz];
			if(k*2==sz){
				if(fail[odsz-1]==k-1) k--;
				else k=0;
			} 
			for(int i=odsz,j=k;j<odsz;i++,j++){
				u[i]=u[j];
				sz++;
			}
//			printf("%s\n",u);
		}
		for(int i=1;i<=n;i++) s[i]=(s[i-1]*10%p+(u[i]-'0'))%p;
		s[0]=1;
		for(int i=1,x,y;i<=q;i++){
			scanf("%d%d",&x,&y);
			printf("%lld\n",s[y]*qpow(s[x-1],p-2));
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
