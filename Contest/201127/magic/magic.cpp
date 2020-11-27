#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,a[maxn],b[maxn];
multiset<int> st;
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar ();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar ();}
	while(isdigit(ch)){v=v*10+ch-'0';ch=getchar ();}
	x=v*w; return;
}
int main(){
	freopen("magic.in","r",stdin); freopen("magic.out","w",stdout);
	int mi=10000,mx=0;
	read(n); for(int i=1;i<=n;i++) read(a[i]); for(int i=1;i<=n;i++) read(b[i]);
	for(int i=1;i<=n;i++) mi=min(mi,min(a[i],b[i])),mx=max(mx,max(a[i],b[i]));
	int curr=0;
	for(int i=mi;i<=mx;i++){
		int ans=0;
		for(int i=1;i<=n;i++) st.insert(a[i]);
		for(int j=1;j<=n;j++){
			multiset<int>::iterator it=st.find(i-b[i]);
			if(it!=st.end()){
				st.erase(it);
				ans++;
			}
		}
		curr=max(curr,ans);
	}
	printf("%d\n",curr);
	return 0;
}
