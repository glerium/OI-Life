#include <cstdio>
#include <cstring>
using namespace std;
const int p=10000;
struct Matrix{
    int n,m;
    int a[3][3];
    Matrix operator*(const Matrix& rhs) const{
        Matrix ret;
        ret.n=n, ret.m=rhs.m;
        for(int i=1;i<=ret.n;i++){
        	for(int j=1;j<=ret.m;j++)
        		ret.a[i][j]=0;
		}
        for(int i=1;i<=n;i++){
            for(int j=1;j<=rhs.m;j++){
                for(int k=1;k<=rhs.n;k++)
                    ret.a[i][j]=(ret.a[i][j]+a[i][k]*rhs.a[k][j])%p;
            }
        }
        return ret;
    }
    void operator*=(const Matrix& rhs){
    	*this=*this*rhs;
	}
};
Matrix qpow(Matrix x,int y){
    Matrix ans;
    ans.n=ans.m=x.n;
    ans.a[1][1]=ans.a[1][2]=ans.a[2][1]=ans.a[2][2]=0;
    for(int i=1;i<=ans.n;i++) ans.a[i][i]=1;
    while(y){
        if(y&1) ans*=x;
        x*=x;
        y>>=1;
    }
    return ans;
}
int main(){
	int n=0;
	while(~scanf("%d",&n)&&n!=-1){
	    Matrix ans;
	    ans.n=ans.m=2;
	    ans.a[1][1]=ans.a[1][2]=ans.a[2][1]=1;
	    ans.a[2][2]=0;
	    if(n==0) puts("0");
	    else if(n==1||n==2) puts("1");
	    else{
	    	ans=qpow(ans,n-1);
	    	printf("%d\n",ans.a[1][1]);
		}
	}
    return 0;
}
