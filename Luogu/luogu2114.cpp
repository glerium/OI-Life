#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
int n,m,t[12],ct,ans;
struct Action{
	int op,t;	//1:AND, 2:OR, 3:XOR
}a[maxn];
int solve(int dep,int x){
	
}
void dfs(int dep,bool full){
	int a[2],up=full?t[dep]:1;
	
}
int main(){
	scanf("%d%d",&n,&m);
	{
		char op[3]; int t;
		for(int i=1;i<=n;i++){
			scanf("%s%d",op,&t);
			if(op[0]=='A') a[i].op=1;
			else if(op[0]=='O') a[i].op=2;
			else a[i].op=3;
			a[i].t=t;
		}
	}
	while(m){
		t[++ct]=m%10;
		m/=10;
	}
	dfs(ct,false);
	printf("%d\n",ans);
	return 0; 
}
