#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
int cnt;
ll l,r;
vector<vector<int> > vec;
map<vector<int>,ll> mp;
void dfs(int x,int s,vector<int>& v){
	if(x==10&&(vec.empty()||v!=vec.back())){
		vec.push_back(v);
//		for(int i=0;i<=9;i++) printf("%d ",v[i]);
		puts("");
		return;
	}
	for(int i=0;i<=cnt;i++){
		if(s+i<=cnt){
			v[x+1]=i;
			dfs(x+1,s+i,v);
		}
	}
}
int main(){
	scanf("%lld%lld",&l,&r);
	{
		ll al=l,ar=r;
		int c1=0,c2=0;
		while(al) al/=10,c1++;
		while(ar) ar/=10,c2++;
		cnt=max(c1,c2);
	}
	{
		vector<int> tmp;
		for(int i=1;i<=10;i++) tmp.push_back(0);
		dfs(-1,0,tmp);
	}
	printf("%d\n",vec.size());
}
