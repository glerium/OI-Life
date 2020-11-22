#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,a,b,c;
ll t[maxn],s[maxn];
template<typename T>void read(T& x){
	T v=0,w=1; char ch=getchar ();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar ();}
	while(ch<='9'&&ch>='0')v=v*10+ch-'0',ch=getchar ();
	x=v*w;return;
}
ll sm(int x,int y){return s[y]-s[x-1];}
int main(){
	freopen("sunny.in","r",stdin);
	freopen("sunny.out","w",stdout);
	read(n),read(a),read(b),read(c);
	for(int i=1;i<=n;i++) read(t[i]),s[i]=s[i-1]+t[i];
	if(a==0){
		printf("%lld\n",s[n]*b+n*c);
		return 0;
	}
	if(n<=20){
		ll maxs=1<<(n-1),ans=-1e18;
		for(int i=0;i<maxs;i++){
			ll cur=0;
			int last=0;
			for(int j=1;j<n;j++){
				if(i&(1<<(j-1))){
					cur+=a*sm(last+1,j)*sm(last+1,j)+b*sm(last+1,j)+c;
					last=j;
				}
			}
			cur+=a*sm(last+1,n)*sm(last+1,n)+b*sm(last+1,n)+c;
			ans=max(ans,cur);
//			printf("%d: %lld\n",i,cur);
		}
		printf("%lld\n",ans);
	}else{
		ll ans1=0,curs=0,ct=0;
		for(int i=1;i<=n;i++){
			if(!ct) curs+=t[i],ct++;
			else if(curs+t[i]<0) ans1+=a*curs*curs+b*curs+c,curs=t[i],ct=1;
			else curs+=t[i],ct++;
		}
		if(ct) ans1+=a*curs*curs+b*curs+c;
		ll ans2=0;
		for(int i=1;i<=n;i++){
			if(!ct) curs+=t[i],ct++;
			else if(curs+t[i]>0) ans2+=a*curs*curs+b*curs+c,curs=t[i],ct=1;
			else curs+=t[i],ct++;
		}
		if(ct) ans2+=a*curs*curs+b*curs+c;
		ll ans3=0;
		for(int i=1;i<=n;i++) ans3+=a*t[i]*t[i]+b*t[i]+c;
		printf("%lld\n",max(ans1,max(ans2,ans3)));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
