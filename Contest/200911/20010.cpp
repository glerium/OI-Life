#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=5e4+10;
int n,cnt;
double ang[1000007];
const double PI=acos(-1);
struct Point{
	long long x,y;
}a[maxn];
double getang(double x,double y){
	double c=sqrt(x*x+y*y);
	return asin(x/c);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld%lld",&a[i].x,&a[i].y);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ang[++cnt]=(a[j].x!=a[i].x)?atan((a[j].y-a[i].y)/(a[j].x-a[i].x)):(PI/2);
			if(ang[cnt]<-1e-7) ang[cnt]+=PI;
			if(ang[cnt]>PI+1e-7) ang[cnt]-=PI;
			printf("%.13lg\n",ang[cnt]);
		}
	}
	sort(ang+1,ang+cnt+1);
	if(cnt&1) printf("%.13lg\n",ang[cnt/2+1]);
	else printf("%.13lg\n",(ang[cnt/2]+ang[cnt/2+1])/2);
	return 0;
}
