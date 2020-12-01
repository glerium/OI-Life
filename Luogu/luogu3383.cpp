#include <bits/stdc++.h>
using namespace std;
const int maxn=1e8+10;
int n,m,p[maxn],ct;
bool f[maxn];
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch))v=v*10+ch-'0',ch=getchar();
	x=v*w; return;
}
template<typename T>void write(T &x){
	if(x<0) putchar('-'),x=-x;
	if(!x){putchar('0');return;}
	T stk[15],ct=0;
	while(x) stk[++ct]=x%10,x/=10;
	for(int i=ct;i>=1;i--) putchar(stk[i]+'0');
}
int main(){
	read(n),read(m);
	memset(f,1,sizeof(f));
	f[1]=true;
	for(int i=2;i<=n;i++){
		if(f[i]) p[++ct]=i;
		for(int j=1;j<=ct&&i*p[j]<=n;j++){
			f[i*p[j]]=false;
			if(i*p[i]) break;
		}
	}
	for(int i=1,x;i<=m;i++){
		read(x);
		write(p[x]),putchar('\n');
	}
	return 0;
}
