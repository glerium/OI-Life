#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,oi[maxn],to[maxn],w[maxn],t[maxn];
struct Num{
	int id;
	int val;
	bool operator<(const Num& rhs)const{return val<rhs.val;}
}a[maxn];
map<int,int> mp;
int lowbit(int x){
	return x&-x;
}
void add(int x){
	while(x<=n){
		t[x]++;
		x+=lowbit(x);
	}
}
int query(int x){
	int ans=0;
	while(x){
		ans+=t[x];
		x-=lowbit(x);
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i].val),oi[i]=a[i].val,a[i].id=i;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) mp.insert(make_pair(a[i].val,mp.size()+1));
	for(int i=1;i<=n;i++) oi[i]=mp[oi[i]];
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=query(n)-query(oi[i]);
		add(oi[i]);
	}
	printf("%d\n",ans);
	return 0;
}
