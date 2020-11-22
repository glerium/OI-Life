#include <cstdio>
#include <functional>
#include <map>
#include <set>
using namespace std;
int n,m;
typedef long long ll;
map<ll,int,greater<ll> > mp;
map<ll,int> deld;
set<ll> st;
template<typename T> void read(T& x){
	T v=0,w=1; char ch=getchar ();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1; ch=getchar ();}
	while(ch<='9'&&ch>='0'){v=v*10+ch-'0'; ch=getchar ();}
	x=v*w; return;
}
void ins(ll x){
	if(mp.count(x)) mp[x]++;
	else mp.insert(make_pair(x,1));
}
void ins2(ll x){
	if(deld.count(x)) deld[x]++;
	else deld.insert(make_pair(x,1));
}
void del(ll x){
	mp[x]--;
	if(!mp[x]) mp.erase(x);
}
void mk(ll x){
	del(x);
	ins2(x);
}
int main(){
	freopen("fish.in","r",stdin);
	freopen("fish.out","w",stdout);
	read(n);
	int curcnt=n;
	ll x;
	for(int i=1;i<=n;i++) read(x),ins(x);
	read(m);
	ll y;
	for(int i=1,op;i<=m;i++){
		read(op),read(x);
		if(op==1){
			read(y);
			ll cnt=0;
			st.clear();
			while(x<y&&cnt<curcnt){
				map<ll,int>::iterator tmp=mp.upper_bound(x);
				if(tmp==mp.end()) break;
				mk(tmp->first), cnt++, x+=tmp->first;
//				printf("eat: %lld %lld %d %d\n",tmp->first,x,deld.size(),mp.size());
			}
			if(x<y) puts("-1");
			else printf("%lld\n",cnt);
			for(map<ll,int>::iterator it=deld.begin();it!=deld.end();it++){
				if(mp.count(it->first)) mp[it->first]+=it->second;
				else mp.insert(*it);
			}
			deld.clear();
		}else if(op==2) ins(x),curcnt++;
		else del(x),curcnt--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
