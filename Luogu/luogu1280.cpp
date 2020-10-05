#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e4+10;
int n,k,cur=1,ct[maxn],f[maxn];
struct Task{
	int s,l;
	bool operator<(const Task& rhs)const {return s>rhs.s;}
}a[maxn];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++) scanf("%d%d",&a[i].s,&a[i].l);
	sort(a+1,a+1+k);
	for(int i=1;i<=k;i++) ct[a[i].s]++;
	for(int i=n;i>=1;i--){
		if(!ct[i]) f[i]=f[i+1]+1;
		else{
			while(ct[i]--){
				f[i]=max(f[i],f[i+a[cur].l]);
				cur++;
			}
		}
	}
	printf("%d\n",f[1]);
	return 0;
}
