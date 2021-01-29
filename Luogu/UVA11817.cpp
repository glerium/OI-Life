#include <bits/stdc++.h>
using namespace std;
const double R=6371009;
int t;
double x,y,z,w;
struct Point{
	double x,y,z;
}A,B;
void torad(double &x){
	x=x/180*acos(-1);
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lf%lf%lf%lf",&x,&y,&z,&w);
		torad(x),torad(y),torad(z),torad(w);
		A.x=R*cos(x)*cos(y);
		A.y=R*cos(x)*sin(y);
		A.z=R*sin(x);
		B.x=R*cos(z)*cos(w);
		B.y=R*cos(z)*sin(w);
		B.z=R*sin(z);
		double ans1=sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y)+(A.z-B.z)*(A.z-B.z));
		double ans2=R*2*asin(ans1/2/R);
//		printf("%lf %lf\n",ans1,ans2);
		printf("%.0lf\n",ans2-ans1);
	}
	return 0;
}
