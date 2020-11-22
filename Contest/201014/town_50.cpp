#include <cstdio>
using namespace std;
int n,ct,f[10007],pr[10007];
typedef long long ll;
bool isprime(int x){
	if(x<=1) return 0;
	for(int i=1;pr[i]*pr[i]<=x&&i<=ct;i++) if(x%pr[i]==0) return 0;
	return 1;
}
int main(){
	scanf("%d",&n);
	f[2]=true;
	for(int i=1;i<=10000;i++){
		if(f[i]){
			for(int j=i+i;j<=10000;j++)
				f[j]=false;
		}
	}
	
	ll ans=0;
	for(int i=1;i<=10000;i++) if(f[i]) pr[++ct]=i;
	for(int i=1;i<=n;i++){
		if(isprime(i)) ans++;
		else{
			if(i%2==0){
				int cur=i,acns=0;
				while(cur%2==0) acns++,cur>>=1;
				ans+=acns*2-1;
			}else{
				
			}
		}
	}
	printf("%lld\n",ans*4);
	return 0;
}
