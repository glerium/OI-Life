#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,m,head[maxn],cnt;
ll in[maxn],out[maxn];
bool vis[maxn];
struct Edge{
	int to,nxt;
}a[maxn];
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
struct Frac{
	ll x,y;
	Frac operator+(const Frac& rhs)const{
		Frac ans;
		ans.y=y*rhs.y;
		ans.x=x*rhs.y+y*rhs.x;
		ll tt=gcd(ans.x,ans.y);
		ans.x/=tt; ans.y/=tt;
		return ans;
	}
	Frac operator+=(const Frac& rhs){
		*this=*this+rhs;
		return *this;
	}
}f[maxn];
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)){v=v*10+ch-'0';ch=getchar();}
	x=v*w; return;
}
template<typename T>void write(T x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void add(int x,int y){
	a[++cnt]=(Edge){y,head[x]};
	head[x]=cnt;
}
void dfs(int x){
	vis[x]=true;
	for(int i=head[x];i;i=a[i].nxt){
		if(!vis[a[i].to]) dfs(a[i].to);
		f[x]+=(Frac){f[a[i].to].x,f[a[i].to].y*out[a[i].to]};
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n),read(m);
	for(int i=1,x;i<=n;i++){
		read(x);
		for(int j=1,y;j<=x;j++){
			read(y);
			add(y,i);
			in[y]++,out[i]++;
		}
		f[i].y=1;
	}
	for(int i=1;i<=n;i++) if(!in[i]) f[i].x=f[i].y=1;
	for(int i=1;i<=n;i++) if(!out[i]&&!vis[i]) dfs(i);
	for(int i=1;i<=n;i++){
		if(out[i]) continue;
		ll t=gcd(f[i].x,f[i].y);
		write(f[i].x/t),putchar(' ');
		write(f[i].y/t),putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
