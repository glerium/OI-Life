#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
const int maxn=1007;
int n,a[maxn];
map<int,vector<pair<int,int> > > mp;
int main(){
	while(~scanf("%d",&n)&&n){
		map<int,vector<pair<int,int> > > empty;
		mp.clear();
		mp.swap(empty);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(!mp.count(a[i]-a[j])) mp.insert(make_pair(a[i]-a[j],vector<pair<int,int> >()));
				mp[a[i]-a[j]].push_back(make_pair(i,j));
				if(!mp.count(a[j]-a[i])) mp.insert(make_pair(a[j]-a[i],vector<pair<int,int> >()));
				mp[a[j]-a[i]].push_back(make_pair(j,i));
			}
		}
		long long ans=-1e18;
		bool found=false;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(!mp.count(a[i]+a[j])) continue;
				int sz=mp[a[i]+a[j]].size();
				for(int k=0;k<sz;k++){
					pair<int,int> &pi=mp[a[i]+a[j]][k];
					if(i==pi.first||j==pi.second||i==pi.second||j==pi.first) continue;
					ans=max(ans,1ll*a[pi.first]);
					found=true;
				}
			}
		}
		if(found) printf("%d\n",ans);
		else puts("no solution");
	}
	return 0;
}
