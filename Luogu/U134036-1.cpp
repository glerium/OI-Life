#include <iostream>
using namespace std;
#define MAXN 20
int gu[MAXN][MAXN];
int luo(int n,int m){
	if(n<=1||m<2) return 1;
	if(gu[n][m]!=-1) return gu[n][m];
	int ans=0;
	for(int i=0;i<m;i+=2) ans+=luo(n-1,i);
	gu[n][m]=ans;
	return ans;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<MAXN;i++) for(int j=0;j<MAXN;j++) gu[i][j]=-1;
	cout<<luo(n,m);
	return 0;
}
