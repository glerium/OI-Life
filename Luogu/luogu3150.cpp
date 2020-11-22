#include <cstdio>
using namespace std;
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n&1) puts("zs wins");
        else puts("pb wins");
    }
    return 0;
}
