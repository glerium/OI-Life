#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn=1e6+10;
int t,n;
struct Work{
	int x,t;
	bool operator<(const Work& rhs)const{return x<rhs.x;}
}a[maxn];
priority_queue<Work> q;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].t);
		int cur=0;
		
	}
	return 0;
}
