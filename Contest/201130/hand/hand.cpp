#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int threshold=10000000;
const int maxn=5e6+10;
const int maxm=maxn*3;
ull k1,k2,f[maxm];
ull Rand(){
	ull k3=k1,k4=k2;
	k1=k4;
	k3^=(k3<<23);
	k2=k3^k4^(k3>>17)^(k4>>26);
	return k2+k4;
}

int n,m,a[maxn],b[maxn];
void gen(int n,ull _k1,ull _k2){
	k1=_k1,k2=_k2;
	for(int i=1;i<=n;i++){
		a[i]=Rand()%threshold+1;
		b[i]=Rand()%threshold+1;
	}
}

int main(){
	freopen("hand.in","r",stdin);
	freopen("hand.out","w",stdout);
	cin>>n>>m>>k1>>k2;
	gen(n,k1,k2);
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			f[j]=max(f[j],f[j-1]+a[i]);
			if(j>=2) f[j]=max(f[j],f[j-2]+a[i]+b[i]);
			if(j>=3) f[j]=max(f[j],f[j-3]+a[i]+b[i]+a[i]);
		}
	}
	ull ans=0;
	for(int i=1;i<=m;i++) ans^=f[i];
	cout<<ans<<endl;
	fclose(stdin); fclose(stdout);
	return 0;
}
