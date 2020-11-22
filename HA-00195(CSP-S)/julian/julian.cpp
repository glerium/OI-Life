#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int dy[13]={0,31,0,31,30,31,30,31,31,30,31,30,31};
int q;
ll n;
template<typename T>void read(T&x){
	T v=0,w=1; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')v=v*10+ch-'0',ch=getchar();
	x=v*w; return;
}
bool leap(ll x){
	if(x>1582) return !(x%400)||!(x%4)&&(x%100);
	else if (x<0) return (x+1)%4==0;
	else return x%4==0;
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	read(q);
	while(q--){
		read(n);n++;
		ll year=-4713;
		if(n>2299000) year+=2299000/(365*3+366)*4,n-=2299000/(365*3+366)*(365*3+366);
		else year+=n/(365*3+366)*4,n-=n/(365*3+366)*(365*3+366);
		if(year>0) year++;
		while(n>365+leap(year)&&year<1582){
			n-=365+leap(year);
			if(year!=-1) year++;
			else year=1;
		}
		if(year>=1582&&n>=278) n+=10;
		year+=n/(365*303+366*97)*400,n-=n/(365*303+366*97)*(365*303+366*97);
		year+=((n/400+bool(n%400))*400-n)/(365*3+366)*4,n-=((n/400+bool(n%400))*400-n)/(365*3+366)*(365*3+366);
		while(n>365+leap(year)){
			n-=365+leap(year);
			if(year!=-1) year++;
			else year=1;
		}
		int i;
		for(i=1;i<=12&&n>(i!=2?dy[i]:leap(year)+28);i++) n-=(i!=2?dy[i]:leap(year)+28);
		if(year<0) printf("%lld %d %lld BC\n",n,i,-year);
		else printf("%lld %d %lld\n",n,i,year);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
