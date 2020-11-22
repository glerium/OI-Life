#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e7+10;
int a,b,f[maxn];
bool prm[maxn];
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	cin>>a>>b;
	int k=max(a,b);
	memset(prm,1,sizeof(prm)); prm[1]=false;
	for(int i=1;i<=k;i++){
		if(prm[i]){
			for(int j=i+i;j<=k;j+=i)
				prm[j]=false;
		}
	}
	for(int i=1;i<=k;i++){
		if(prm[i]){
			for(long long j=i;j<=k;j*=i)
				f[j]=i;
		}
	}
	long long ans=0;
	for(int i=a;i<=b;i++) ans+=f[i]?f[i]:1;
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
