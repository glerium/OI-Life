#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn=5e5+10;
string s1,s2;
int n,m;

int gcd(int x,int y){return y?gcd(y,x%y):x;}
void yf(int& x,int& y){
	int k=gcd(x,y);
	x/=k,y/=k;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>s1>>s2;
	n=s1.size(),m=s2.size();
	for(int i=1;i<=min(n,m);i++){
		int pa=0,pb=0,pt=0;
		for(int l=0,r=l+i-1;l<n&&r<n;l++,r++){
			for(int l2=0,r2=l2+i-1;l2<m&&r2<m;l2++,r2++){
				string tmp1=s1.substr(l,i),tmp2=s2.substr(l2,i);
				if(tmp1>tmp2) pa++;
				else if(tmp1<tmp2) pb++;
				else pt++;
			}
		}
		int ss=pa+pb+pt;
		int s1=ss,s2=ss,s3=ss;
		yf(pa,s1),yf(pb,s2),yf(pt,s3);
		printf("%d/%d %d/%d %d/%d\n",pb,s2,pt,s3,pa,s1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
