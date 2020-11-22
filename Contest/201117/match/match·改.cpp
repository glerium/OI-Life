#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n;
struct Bracket{
	int a,b;
	bool operator<(const Bracket& rhs)const{return a-b>rhs.a-rhs.b;}
}t[maxn],t1[maxn],t2[maxn];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&t[i].a);
	for(int i=1;i<=n;i++) scanf("%d",&t[i].b);
	for(int i=1;i<=n;i+=2) t1[(i+1)/2]=t[i];
	for(int i=2;i<=n;i+=2) t2[i/2]=t[i];
	sort(t1+1,t1+n/2+1);
	sort(t2+1,t2+n/2+1);
	int i=1;
	ll ans=0;
	for(i=1;i<=n/2&&t1[i].a+t2[i].a-t1[i].b-t2[i].b>=0;i++)
		ans+=t1[i].a+t2[i].a;
	for(;i<=n/2;i++) ans+=t1[i].b+t2[i].b;
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
