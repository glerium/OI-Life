#include <bits/stdc++.h>
using namespace std;
struct Point{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){};
}A,B,C;
typedef Point Vector;
double Length(Vector A){
	return sqrt(A.x*A.x+A.y*A.y);
}
Vector operator-(Point A,Point B){
	return Vector(A.x-B.x,A.y-B.y);
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y);
		double a=Length(A-B),b=Length(A-C),c=Length(B-C),p=(a+b+c)/2;
		printf("%.0lf\n",(sqrt(p*(p-a)*(p-b)*(p-c)))/7);
	}
	return 0;
}
