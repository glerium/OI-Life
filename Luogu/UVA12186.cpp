#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=2e5+10;
int n,t,cnt,head[maxn],f[maxn],tmp[maxn],chu[maxn];
struct Edge{
	int to,nxt;
}a[maxn];
void add(int x,int y){a[++cnt]=(Edge){y,head[x]};head[x]=cnt;}
void dfs(int x,int fa){
	vector<int> tmp;
	if(!chu[x]){
		f[x]=1;
		return;
	}
	int cts=0;
	for(int i=head[x];i;i=a[i].nxt){
		dfs(a[i].to,x);
		tmp.push_back(f[a[i].to]);
	}
	sort(tmp.begin(),tmp.end());
	int k=tmp.size()*t/100+bool(tmp.size()*t%100);
	for(int i=0;i<k;i++) f[x]+=tmp[i];
}
int main(){
	while(~scanf("%d%d",&n,&t)&&n&&t){
		memset(f,0,sizeof(f));
		memset(head,0,sizeof(head));
		memset(chu,0,sizeof(chu));
		cnt=0;
		for(int i=1,x;i<=n;i++) scanf("%d",&x),add(x,i),chu[x]++;
		dfs(0,0);
		printf("%d\n",f[0]);
	}
	return 0;
}
