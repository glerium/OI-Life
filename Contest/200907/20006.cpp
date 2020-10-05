#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,a[maxn];
ll fi[maxn];
set<ll> st;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	fi[1]=fi[2]=1;
	st.insert(1);
	for(int i=3;fi[i-1]<=2e9+10;i++){
		fi[i]=fi[i-1]+fi[i-2];
		st.insert(fi[i]);
	}
	int ans=0,from=1;
	for(int i=2;i<=n;i++){
		bool flag=true;
		for(int j=from;j<i;j++){
			if(st.count(a[j]+a[i])){
				flag=false;
				break;
			}
		}
		if(!flag){
			ans++;
			from=i;
		}
	}
	printf("%d\n",ans+1);
}
