#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,m;
struct Block{
	ll cnt;
	int color;
};
vector<Block> v[maxn];
void push(ll x,int y,int z){
	v[z].push_back((Block){x,y});
}
int pop(int x,int z){
	ll ima=0;
	int sz=v[z].size();
	for(int i=sz-1;i>=0;i--){
		if(ima+v[z][i].cnt>=x){
			if(ima+v[z][i].cnt==x) v[z].pop_back();
			v[z][i].cnt-=x-ima;
			return v[z][i].color;
		}
		ima+=v[z][i].cnt;
		v[z].pop_back();
	}
}
void put(int x,int y){
	int sz=v[x].size();
	for(int i=sz-1;i>=0;i--) v[y].push_back(v[x][i]);
	v[x].clear();
	vector<Block>().swap(v[x]);
}
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d%d",&n,&m);
	{
		char op[10];
		for(int i=1,x,y,z;i<=m;i++){
			scanf("%s",op);
			if(strcmp(op,"push")==0){
				scanf("%d%d%d",&x,&y,&z);
				push(x,y,z);
			}else if(strcmp(op,"pop")==0){
				scanf("%d%d",&x,&y);
				printf("%d\n",pop(x,y));
			}else{	//put
				scanf("%d%d",&x,&y);
				put(x,y);
			}
//			for(int i=1;i<=2;i++){
//				for(int j=0;j<v[i].size();j++){
//					for(int k=1;k<=v[i][j].cnt;k++){
//						printf("%d ",v[i][j].color);
//					}
//				}
//				puts("");
//			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
