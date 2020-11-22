#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
const int maxn=1e6+10;
int n,m,a[maxn];
bool exi[maxn];
using namespace std;
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar ();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar ();}
	while(ch<='9'&&ch>='0'){v=v*10+ch-'0';ch=getchar ();}
	x=v*w; return;
}
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int k=0;
	read(n),read(m);
	for(int i=1;i<=n;i++) read(a[i]),exi[a[i]]=true,k=max(k,a[i]);
	sort(a+1,a+1+n,greater<int>());
	for(int i=1,x;i<=m;i++){
		read(x);
		bool flag=false;
		for(int j=x;j<=k;j++){
			if((x&j)==x&&exi[j]){
				puts("yes");
				flag=true;
				break;
			}
		}
		if(!flag) puts("no");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
