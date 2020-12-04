#include <bits/stdc++.h>
using namespace std;
struct pii{
	int first,second;
	bool operator<(const pii& rhs)const{return first==rhs.first?second>rhs.second:first<rhs.first;}
};
const int maxn=1e6+10;
unsigned t,m,n,seed;
multiset<pii> st;
multiset<pii>::iterator rt[maxn];
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch))v=v*10+ch-'0',ch=getchar();
	x=v*w;return;
}
template<typename T>void write(T x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
typedef unsigned int ui;
ui last=7;
ui randNum(){ 
    seed=seed*17+last;
	return seed%m+1;
}
int main(){
	read(t);
	while(t--){
		st.clear();
		read(m),read(n),read(seed);
		for(int i=1;i<=m;i++) rt[i]=st.insert((pii){0,0});
		for(int i=1;i<=n;i++){
			unsigned ria=randNum(),rib=randNum();
			pii las=*rt[ria];
			st.erase(rt[ria]);
			las.first++,las.second+=rib;
			rt[ria]=st.insert(las);
			unsigned ans=distance(st.upper_bound(las),st.end());
			last=ans;
			write(ans),putchar('\n');
		}
	}
}
