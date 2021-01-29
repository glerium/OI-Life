#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
const double eps=1e-6;
int dcmp(double x);
struct Point{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){};
	Point operator+(const Point& rhs)const{return Point(x+rhs.x,y+rhs.y);}
	Point operator-(const Point& rhs)const{return Point(x-rhs.x,y-rhs.y);}
	Point operator*(double t)const{return Point(x*t,y*t);}
	bool operator==(const Point& rhs)const{return dcmp(x-rhs.x)==0&&dcmp(y-rhs.y)==0;}
	bool operator<(const Point& rhs)const{return x<rhs.x||x==rhs.x&&y<rhs.y;}
}a[maxn];
typedef Point Vector;
double Dot(Vector A,Vector B){
	return A.x*B.x+A.y*B.y;
}
double Cross(Vector A,Vector B){
	return A.x*B.y-A.y*B.x;
}
double Length(Vector A){
	return sqrt(Dot(A,A));
}
int dcmp(double x){
	if(abs(x)<eps) return 0;
	return x>0?1:-1;
}
Point GetlineInt(Point A,Vector v,Point B,Vector w){
	Vector u=A-B;
	return A+v*(Cross(w,u)/Cross(v,w));
}
bool SegProperInt(Point A,Point B,Point C,Point D){
	Vector seg1=A-B,seg2=C-D;
	return dcmp(Cross(A-C,seg1)*Cross(A-D,seg1))<0&&dcmp(Cross(C-A,seg2)*Cross(C-B,seg2))<0;
}
bool OnSegment(Point P,Point A,Point B){
	return dcmp(Cross(P-A,P-B))==0&&dcmp(Dot(P-A,P-B))<0;
}
int kase,n;
Point ans[maxn*maxn];
int main(){
//	freopen("test.out","w",stdout);
	while(~scanf("%d",&n)&&n){
		for(int i=0;i<n;i++) scanf("%lf%lf",&a[i].x,&a[i].y),ans[i]=a[i];
		n--;
		int c=n,e=n;	//¦Ì?¨ºy,¡À?¨ºy
		for(int i=0;i<n;i++){
			for(int j=0;j<i-1;j++){
				if(SegProperInt(a[i],a[i+1],a[j],a[j+1]))
					ans[c++]=GetlineInt(a[i],a[i+1]-a[i],a[j],a[j+1]-a[j]);
			}
		}
		sort(ans,ans+c);
		c=unique(ans,ans+c)-ans;
		for(int i=0;i<n;i++){
			for(int j=0;j<c;j++)
				if(OnSegment(ans[j],a[i],a[i+1])) e++;
		}
		printf("Case %d: There are %d pieces.\n",++kase,e+2-c);
	}
	return 0;
}
