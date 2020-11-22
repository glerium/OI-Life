#include <cstdio>
#include <cstring>
using namespace std;
int n,m,f[20][20];	//i digits, j ending
int t[20];
int dfs(int idx,bool six,bool flag){
	if(idx<0) return 0;
	int up=(flag?t[idx]:9);
	if(!flag&&f[idx][0]) return f[idx][0];
	for(int i=0;i<=9;i++){
		if(i==4||six&&i==2) continue;
		
	}
}
int getans(int x){
	int pos=0;
	while(x){
		t[++pos]=x%10;
		x/=10;
	}
	return dfs(pos-1,0,1);
}
int main(){
	while(~scanf("%d%d",&n,&m)&&(n||m)){
		memset(f,0,sizeof(f));
		printf("%d\n",getans(m)-getans(n-1));
	}
	return 0;
}
