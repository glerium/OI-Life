#include <cstdio>
#include <cctype>
using namespace std;
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch))v=v*10+ch-'0',ch=getchar();
	x=v*w;return;
}
int main(){
	freopen("detonator.in","r",stdin);
	freopen("detonator.out","w",stdout);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
