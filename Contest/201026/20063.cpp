#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
int t;
ll a,b,c,d;
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		cin>>a>>b>>c>>d;
		ll m=gcd(a,b);
		if(!gcd(c,m)) puts(!d?"YES":"NO");
		else if(d%gcd(c,m)==0) puts("YES");
		else puts("NO");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
