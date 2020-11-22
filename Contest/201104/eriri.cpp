#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn=2e5+10;
typedef long long ll;
int n,t,a[maxn],b[maxn];
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar ();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar ();}
	while(ch<='9'&&ch>='0')v=v*10+ch-'0',ch=getchar ();
	x=v*w; return;
}
int main(){
	freopen("eriri.in","r",stdin);
	freopen("eriri.out","w",stdout);
	read(n),read(t);
	for(int i=1;i<=n;i++) read(a[i]),read(b[i]);
	int od[10];
	for(int i=1;i<=n;i++) od[i]=i;
	int ans=0;
	do{
//		for(int i=1;i<=n;i++) printf("%d ",od[i]);
//		puts("");
		int cur=0;
		ll ti=1;
		for(int i=1;i<=n&&ti<=t;i++){
//			cout<<"t="<<ti<<": "<<od[i]<<endl;
			ti+=a[od[i]]*ti+b[od[i]];
			if(ti>t) break;
			cur++;
		}
		ans=max(ans,cur);
	}while(next_permutation(od+1,od+1+n));
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0x0;
}
