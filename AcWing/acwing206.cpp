//石头游戏--矩阵快速幂 
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;
int n,m,t,act,r[70];
char op[15][15];
struct Matrix{
	int n,m;
	ll a[70][70];
	Matrix operator*(const Matrix& rhs)const{
		Matrix ans;
		memset(&ans,0,sizeof(ans));
		ans.n=n,ans.m=rhs.m;
		for(int i=0;i<=ans.n;i++){
			for(int j=0;j<=ans.m;j++){
				for(int k=0;k<=m;k++)
					ans.a[i][j]+=a[i][k]*rhs.a[k][j];
			}
		}
		return ans;
	}
	Matrix() {n=m=0;memset(a,0,sizeof(a));}
	void operator*=(const Matrix& rhs) {*this=*this*rhs;}
};
Matrix qpow(Matrix x,int y){
	Matrix ans;
	memset(&ans,0,sizeof(ans));
	ans.n=ans.m=x.n;
	for(int i=0;i<=n*m;i++) ans.a[i][i]=1;
	while(y){
		if(y&1) ans*=x;
		x*=x; y>>=1;
	}
	return ans;
}
int id(int x,int y) {return (x-1)*m+y;}
int mod(int x,int y){return x%y?x%y:y;}
signed main(){
	scanf("%d%d%d%d",&n,&m,&t,&act);
	{
		char tmp[15];
		for(int i=1;i<=n;i++){
			scanf("%s",tmp+1);
			for(int j=1;j<=m;j++) r[id(i,j)]=tmp[j]-'0'+1;
		}
	}
	for(int i=1;i<=act;i++) scanf("%s",op[i]+1);
	
	/* computing */
	Matrix tt[65];
	memset(tt,0,sizeof(tt));
	for(int i=1;i<=60;i++){			//for 1 to 60 sec(matrix)
		tt[i].n=tt[i].m=n*m;
		tt[i].a[0][0]=1;
		for(int j=1;j<=n;j++){		//for line 1 to n
			for(int k=1;k<=m;k++){	//for col 1 to n
				char cop=op[r[id(j,k)]][mod(i,strlen(op[r[id(j,k)]]+1))];
				if(cop=='N'&&j>1) tt[i].a[id(j,k)][id(j-1,k)]=1;
				else if(cop=='W'&&k>1) tt[i].a[id(j,k)][id(j,k-1)]=1;
				else if(cop=='S'&&j<n) tt[i].a[id(j,k)][id(j+1,k)]=1;
				else if(cop=='E'&&k<m) tt[i].a[id(j,k)][id(j,k+1)]=1;
				else if(isdigit(cop)){
					tt[i].a[id(j,k)][id(j,k)]=1;
					tt[i].a[0][id(j,k)]=cop-'0';
				}
			}
		}
	}
	
	Matrix eps;
	eps.n=eps.m=n*m;
	for(int i=0;i<=eps.n;i++) eps.a[i][i]=1;
	for(int i=1;i<=60;i++){
		eps*=tt[i];
	}
	
	Matrix final;
	final.n=final.m=n*m;
	final=qpow(eps,t/60);
	for(int i=1;i<=t%60;i++) final*=tt[i];
	
	Matrix original;
	original.n=1,original.m=n*m;
	original.a[1][0]=1;
	original*=final;
	
	ll ans=0;
	for(int i=1;i<=n*m;i++) ans=max(ans,original.a[1][i]);
	printf("%lld\n",ans);
	return 0;
}
