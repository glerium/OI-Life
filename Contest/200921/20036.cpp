#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=2e5+10;
int n,a[maxn],ans,d[maxn];
vector<int> vec1[maxn],vec2[maxn];
template<typename T> void read(T& x){
	T v=0,w=1; char ch=getchar ();
	while(ch>'9'||ch<'0'){if(ch=='-') w=-1; ch=getchar ();}
	while(ch<='9'&&ch>='0'){v=v*10+ch-'0'; ch=getchar ();}
	x=v*w; return;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	int maxx=0,mi=-1;
	for(int i=1;i<=n;i++){
		if(a[i]>maxx){
			maxx=a[i];
			mi=i;
		}
	}
	if(n<=5000){
		for(int i=1;i<mi;i++){
			for(int j=1;j<mi;j++){
				if(a[j]>a[j+1]){
					swap(a[j],a[j+1]);
					ans++;
				}
			}
		}
		for(int i=mi+1;i<n;i++){
			for(int j=mi+1;j<n;j++){
				if(a[j]<a[j+1]){
					swap(a[j],a[j+1]);
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}else{
		for(int i=1;i<=100000;i++){
			vec1[i].clear();
			vec2[i].clear();
		}
		for(int i=1;i<mi;i++) vec1[a[i]].push_back(i);
		sort(a+1,a+1+mi);
		for(int i=1;i<mi;i++) vec2[a[i]].push_back(i);
		for(int i=1;i<=100000;i++){
			int sz=vec1[i].size();
			for(int j=0;j<sz;j++)
				if(vec1[i][j]<vec2[i][j]) ans+=vec2[i][j]-vec1[i][j];
		}
		
		for(int i=1;i<=100000;i++){
			vec1[i].clear();
			vec2[i].clear();
		}
		for(int i=mi+1;i<=n;i++) vec1[a[i]].push_back(i);
		sort(a+mi+1,a+n+1,cmp);
		for(int i=mi+1;i<=n;i++) vec2[a[i]].push_back(i);
		for(int i=1;i<=100000;i++){
			int sz=vec1[i].size();
			for(int j=0;j<sz;j++)
				if(vec1[i][j]<vec2[i][j]) ans+=vec2[i][j]-vec1[i][j];
		}
		printf("%d\n",ans);
	}
	return 0;
}
