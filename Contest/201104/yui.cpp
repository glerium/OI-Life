#include <iostream>
#include <cstdio>
using namespace std;
int n,a[2333],ans;
void dfs(int x){
	if(x==n+1){
		int xs=0;
		for(int i=1;i<=n;i++) xs^=a[i];
		if(xs) ans++;
		return;
	}
	for(int i=1;i<(1<<n);i++){
		bool flag=true;
		for(int j=1;j<x;j++){
			if(a[j]==i){
				flag=false;
				break;
			}
		}
		if(flag){
			a[x]=i;
			dfs(x+1);
		}
	}
}
int main(){
	freopen("yui.in","r",stdin);
	freopen("yui.out","w",stdout);
	cin>>n;
	dfs(1);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
