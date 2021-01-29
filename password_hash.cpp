#include <bits/stdc++.h>
using namespace std;
const int mod=1e6,base=256;
int main(){
	char s[]="wenzelin";
	int ans=0,n=strlen(s);
	for(int i=0;i<n;i++) ans=(ans*base+s[i])%mod;
	printf("%06d\n",ans);
	return 0;
}
