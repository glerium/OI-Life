#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int p=1000;
int k,x,m;
struct bigInt{
	int v[101],size;
	bigInt(long long x=0) {memset(v,0,sizeof(v)); size=0; while(x) v[++size]=x%10,x/=10;}
	void write(){
		if(size==0) {putchar('0'); return;}
		for(int i=size;i>=1;i--) putchar(v[i]+'0');
	}
	bigInt operator+(const bigInt& rhs) {
		bigInt ans=0;
		ans.size=max(size,rhs.size);
		int kk=0;
		for(int i=1;i<=ans.size;i++){
			ans.v[i]=v[i]+rhs.v[i]+kk;
			kk=ans.v[i]/10;
			ans.v[i]%=10;
		}
		while(kk){
			ans.v[++ans.size]=kk%10;
			kk/=10;
		}
		return ans;
	}
}f[1007][1007];
int qpow(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=ans*x%p;
		x=x*x%p; y>>=1;
	}
	return ans;
}
int main(){
	scanf("%d%d",&k,&x);
	x%=1000;
	m=qpow(x,x);
	f[0][0].size=1,f[0][0].v[1]=1;
	for(int i=0;i<=1000;i++){
		for(int j=0;j<=i;j++){
			if(!(i+j)) continue;
			else f[i][j]=f[i-1][j]+f[i-1][j-1];
		}
	}
	f[m-1][k-1].write();
	return 0;
}
