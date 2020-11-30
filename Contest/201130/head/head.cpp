#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,cnt,head[maxn];
struct Edge{
	int to,nxt;
}a[maxn<<1];
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch))v=v*10+ch-'0',ch=getchar();
	x=v*w;return;
}
void add(int x,int y){
	a[++cnt]=(Edge){y,head[x]};
	head[x]=cnt;
}
int main(){
	freopen("head.in","r",stdin);
	freopen("head.out","w",stdout);
	read(n);
	for(int i=1,x,y;i<=n-1;i++){
		read(x),read(y);
		add(x,y),add(y,x);
	}
	
	fclose(stdin); fclose(stdout);
	return 0;
}
