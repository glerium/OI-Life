#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e7+10;
const int maxa=1e7+7;
int n,m,a[maxn],use[maxn],atk[maxn];
inline int _read(){
    char ch=getchar ();int sum=0;
    while(!(ch>='0'&&ch<='9'))ch=getchar ();
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=getchar ();
    return sum;
}
int main(){
	n=_read(),m=_read();
	for(int i=1;i<=n;i++) a[i]=_read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		use[i]=a[i]/3;
		atk[i]=a[i]%3;
		if(!atk[i]) use[i]--,atk[i]+=3;
	}
	int ans1=0,cur=0;
	for(int i=1;i<=n&&cur<m;i++){
		cur+=atk[i];
		ans1=use[i];
	}
	if(cur<m){
		puts("-1");
		return 0;
	}
	int ct=0;
	for(int i=1;i<=n&&a[i]<=ans1*3+3;i++) if(a[i]<=ans1*3+3) ct=i;
	int curAtk=0,ans2=0,tt[4]={0,1,1,4};
	for(int i=ct;i>=1&&curAtk<m;i--){
		ans2+=tt[atk[i]];
		curAtk+=atk[i];
	}
	ans2+=ans1;
	printf("%d %d\n",ans1,ans2);
	return 0;
}
