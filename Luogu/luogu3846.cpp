#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+10;
int p,b,n,head[maxn],nxt[maxn],ct,sz,f[maxn],l[maxn],ml[maxn];
int hs(int x){return x%100003;}
void insert(int x,int k){
	f[++ct]=x; l[ct]=k;
	nxt[ct]=head[hs(x)];
	head[hs(x)]=ct;
}
int qpow(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=1ll*ans*x%p;
		x=1ll*x*x%p; y>>=1;
	}
	return ans;
}
signed main(){
	scanf("%lld%lld%lld",&p,&b,&n);
	sz=ceil(sqrt(p));
	ml[0]=1%p;
	for(int i=0;i<=sz;i++){
		if(i) ml[i]=1ll*ml[i-1]*b%p;
		insert(ml[i],i);
		if(ml[i]==n){
			printf("%lld\n",i);
			return 0;
		}
	}
	for(int i=1;i<=sz;i++){
		int ans=-1,tmp=1ll*n*qpow(qpow(b,sz*i),p-2)%p;
		for(int j=head[hs(tmp)];j;j=nxt[j]){
//			printf("%lld\n",tmp);
			if(f[j]==tmp)
				ans=l[j]+sz*i;
		}
		if(ans^-1ll){
			printf("%lld\n",ans);
			return 0;
		}
	}
	puts("no solution");
	return 0;
}
