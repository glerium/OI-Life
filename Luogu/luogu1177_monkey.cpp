#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,a[maxn];
int main(){
	srand(time(0));
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int isSort=0;
    int i;
    while(!isSort){
        isSort=1;
        for(i=1;i<n;i++){
            if(a[i]>a[i+1]){
                isSort=0;
                break;
            }
        }
        random_shuffle(a+1,a+1+n);
    }
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    return 0;
}
