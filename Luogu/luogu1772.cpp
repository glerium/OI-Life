#include <bits/stdc++.h>
using namespace std;
const int maxn=107;
int n,m,k,e,cnt,head[maxn];
bool avai[maxn][maxn];
struct Edge{
	int to,dis,nxt;
}a[maxn*maxn<<1];
struct Node{
	int id,dis;
	bool operator<(const Node& rhs)const{return dis>rhs.dis;}
};
priority_queue<Node> q;
void add(int x,int y,int z){
	a[++cnt]=(Edge){y,z,head[x]};
	head[x]=cnt;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&e);
	for(int i=1,x,y,z;i<=e;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z),add(y,x,z);
	}
	memset(avai,1,true);
	for(int i=1,p,a,b;i<=n;i++){
		scanf("%d%d%d",&p,&a,&b);
		for(int j=a;j<=b;j++) avai[i][j]=false;
	}
	
}
