#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,cnt0;
ll cnt[50][50];
char s[maxn][20];
bool vis[36][36][36][36];
struct Number{
	ll val;
	int pos;
	int ct2,ct5;
}a[maxn];
int main(){
	freopen("check.in","r",stdin);
	freopen("check.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%s",s[i]);
	for(int i=1;i<=n;i++){
		int sz=strlen(s[i]),j=0;
		for(j=0;j<sz&&s[i][j]!='.';j++) a[i].val=a[i].val*10+s[i][j]-'0';
		if(s[i][j]=='.') a[i].pos=sz-j-1,j++;
		for(;j<sz;j++) a[i].val=a[i].val*10+s[i][j]-'0';
//		printf("input: %lld %d\n",a[i].val,a[i].pos);
	}
	for(int i=1;i<=n;i++){
		if(a[i].val==0) continue;
		ll tmp=a[i].val;
		while(tmp%2==0){tmp/=2;a[i].ct2++;}
		while(tmp%5==0){tmp/=5;a[i].ct5++;}
		a[i].ct2-=a[i].pos;
		a[i].ct5-=a[i].pos;
//		printf("::%d %d\n",a[i].ct2,a[i].ct5);
	}
	for(int i=1;i<=n;i++){
		if(a[i].val==0) cnt0++;
		else cnt[a[i].ct2+12][a[i].ct5+12]++;
	}
	ll ans=0;
	for(int i=1;i<=35;i++){
		for(int j=1;j<=35;j++){
			for(int i2=1;i2<=35;i2++){
				for(int j2=1;j2<=35;j2++){
					if(i+i2-24<0||j+j2-24<0) continue;
					if(vis[i][j][i2][j2]) continue;
					vis[i][j][i2][j2]=vis[i2][j2][i][j]=true;
					if(!(cnt[i][j]*cnt[i2][j2])) continue; 
//					int tmp=ans;
 					if(i!=i2||j!=j2) ans+=cnt[i][j]*cnt[i2][j2];
 					else ans+=cnt[i][j]*(cnt[i][j]-1)/2;
//					if(cnt[i][j]*cnt[i2][j2]) printf("%d %d %d %d %d\n",i,j,i2,j2,ans-tmp);
				}
			}
		}
	}
	ans+=cnt0*(n-1);
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
