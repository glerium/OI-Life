#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int maxm=4e6+10;
const int p=1e9+7;
int n,m,head[maxn],cnt;
ll dis[maxn];
long double dis2[maxn];
struct Edge{
	int to,dis,nxt;
}a[maxn];
struct State{
	int id;
	long double dis;
	bool operator<(const State& rhs)const{return dis>rhs.dis;}
};
priority_queue<State> q;
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar ();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar ();}
	while(ch>='0'&&ch<='9')v=v*10+ch-'0',ch=getchar ();
	x=v*w; return;
}
template<typename T>void write(T x){
	if(x<0) putchar ('-'),x=-x;
	if(x>9) write(x/10);
	putchar (x%10+'0');
}
void add(int x,int y,int z){
	a[++cnt]=(Edge){y,z,head[x]};
	head[x]=cnt;
}
int main(){
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	read(n),read(m);
	for(int i=1,x,y,z;i<=m;i++) read(x),read(y),read(z),add(x,y,z);
	for(int i=2;i<=n;i++) dis[i]=-1,dis2[i]=INFINITY;
	q.push((State){1,0});
	const long double s2=sqrt(2.0);
	while(!q.empty()){
		State cr=q.top(); q.pop();
		for(int i=head[cr.id];i;i=a[i].nxt){
			if(dis2[a[i].to]>sqrt((dis2[cr.id]*s2+a[i].dis)*(dis2[cr.id]*s2-a[i].dis)+2*a[i].dis)){
//				cout<<":"<<dis[a[i].to]<<' '<<dis2[a[i].to]<<endl;
				dis2[a[i].to]=sqrt((dis2[cr.id]*s2+a[i].dis)*(dis2[cr.id]*s2-a[i].dis)+2*a[i].dis);
				dis[a[i].to]=(dis[cr.id]*2+a[i].dis)%p;
//				cout<<dis[a[i].to]<<' '<<dis2[a[i].to]<<endl;
				q.push((State){a[i].to,dis2[a[i].to]});
			}
		}
	}
	for(int i=2;i<=n;i++) write(dis[i]),i^n?putchar (' '):0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
