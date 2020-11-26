#include <cstdio>
using namespace std;
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')v=v*10+ch-'0',ch=getchar();
	x=v*w; return;
}
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
