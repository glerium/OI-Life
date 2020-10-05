#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e3+10;
int n,m,f;
struct Ans{
	bool col;
	int id;
	int cnt;
	bool operator<(const Ans& rhs)const{return cnt<rhs.cnt;}
}c[maxn<<1];
bool is[maxn][maxn],v[maxn][maxn];
bool check(int x){
	bool col=c[x].col;
	int id=c[x].id;
	for(int i=1;i<=n;i++){
		if(col&&v[id][i]) return false;
		else if(!col&v[i][id]) return false;
	}
	return true;
}
void dye(int x){
	bool col=c[x].col;
	int id=c[x].id;
	for(int i=1;i<=n;i++){
		if(col&&is[id][i]) v[id][i]=true;
		else if(!col&&is[i][id]) v[i][id]=true;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		is[x][y]=true;
	}
	for(int i=1;i<=n;i++) c[i].id=c[i+n].id=i;
	for(int i=1;i<=n;i++) c[i].col=true;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(is[i][j]){
				c[i].cnt++;
				c[j+n].cnt++;
			}
		}
	}
	sort(c+1,c+2*n+1);
	f=1;
	int ans=0;
	for(int i=1;i<=2*n;i++){
		if(check(f)){
			dye(f);
			ans+=n;
		}
		f++;
	}
	printf("%d\n",ans);
	return 0;
}
