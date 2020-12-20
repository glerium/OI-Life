#include <bits/stdc++.h>
using namespace std;
int t;
struct Point{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){};
};
typedef Point Vector;
Vector operator-(Point a,Point b){
	return Vector(a.x-b.x,a.y-b.y);
}
Vector operator*(Vector a,double x){
	return Vector(a.x*x,a.y*x);
}
Vector operator*(double x,Vector a){
	return a*x;
}
Point operator+(Point x,Vector a){
	return Point(x.x+a.x,x.y+a.y);
}
double Dot(Vector a,Vector b){
	return a.x*b.x+a.y*b.y;
}
double Cross(Vector a,Vector b){
	return a.x*b.y-a.y*b.x;
}
Vector Rotate(Vector v,double rad){
	return Vector(v.x*cos(rad)-v.y*sin(rad),v.x*sin(rad)+v.y*cos(rad));
}
double Length(Vector A){
	return sqrt(Dot(A,A));
}
double Angle(Vector A,Vector B){
	return acos(Dot(A,B)/Length(A)/Length(B));
}
Point Intersection(Point a,Vector v,Point b,Vector w){
	Vector u=a-b;
	double t=Cross(w,u)/Cross(v,w);
	return a+t*v;
}
Point getD(Point A,Point B,Point C){
	double angB=Angle(A-B,C-B),angC=Angle(A-C,B-C);
	Vector ta=Rotate(C-B,angB/3),tb=Rotate(B-C,-angC/3);
	return Intersection(B,ta,C,tb);
}
int main(){
	scanf("%d",&t);
	while(t--){
		Point A,B,C;
		scanf("%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y);
		Point ansA=getD(A,B,C),ansB=getD(B,C,A),ansC=getD(C,A,B);
		printf("%.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n",ansA.x,ansA.y,ansB.x,ansB.y,ansC.x,ansC.y);
	}
	return 0;
}
