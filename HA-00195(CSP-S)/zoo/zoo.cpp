#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,m,c,k,head[maxn],cnt;
ll a[maxn],p[maxn],q[maxn];
bool exi[maxn],exilist[maxn];
set<int> buy,nobuy;
struct Item{
	ll to;
	int nxt;
}itm[maxn];
template<typename T>void read(T&x){
	T v=0,w=1; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')v=v*10+ch-'0',ch=getchar();
	x=v*w; return;
}
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	read(n),read(m),read(c),read(k);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=m;i++){
		read(p[i]),read(q[i]);
		itm[++cnt]=(Item){q[i],head[p[i]]};
		head[p[i]]=cnt;
		exilist[p[i]]=true;	//在列表中 
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<k;j++){
			if(a[i]&(1ll<<j)){
				exi[j]=true;	//存在二进制位 
			}
		}
	}
	int ans=0;	//不在列表中的数量 
	for(int i=0;i<k;i++){
		if(exi[i])
			for(int j=head[i];j;j=itm[j].nxt){
				buy.insert(itm[j].to);
			}
	}
//	for(set<int>::iterator it=buy.begin();it!=buy.end();it++) printf("%d\n",*it);
	for(int i=0;i<k;i++){
		if(exi[i]) ans++;
		else ans+=!exilist[i];
	}
	printf("%d\n",(1ll<<ans)-n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
