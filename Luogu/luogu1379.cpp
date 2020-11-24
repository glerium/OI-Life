#include <cstdio>
#include <map>
#include <queue>
#include <set>
using namespace std;
const int mv[4][2]={0,1,0,-1,1,0,-1,0};
int n,pt[11];
set<int> st;
queue<pair<int,int> > q;
int main(){
	pt[0]=1; for(int i=1;i<=9;i++) pt[i]=pt[i-1]*10;
	scanf("%d",&n);
	q.push(make_pair(n,0));
	while(!q.empty()){
		pair<int,int> cur=q.front();
		q.pop();
		if(st.count(cur.first)) continue;
		st.insert(cur.first);
//		printf("%d\n",cur.first);
		if(cur.first==123804765ll){
			printf("%d\n",cur.second);
			return 0;
		}
		int a[3][3]={},x,y;
		for(int i=2;i>=0;i--) for(int j=2;j>=0;j--){
			a[i][j]=cur.first%10,cur.first/=10;
			if(!a[i][j]) x=i,y=j;
		}
		for(int i=0;i<4;i++){
			if(x+mv[i][0]>=0&&x+mv[i][0]<=2&&y+mv[i][1]>=0&&y+mv[i][1]<=2){
				swap(a[x][y],a[x+mv[i][0]][y+mv[i][1]]);
				int cr=0;
				for(int i=0;i<=2;i++) for(int j=0;j<=2;j++) cr=cr*10+a[i][j];
				if(!st.count(cr)) q.push(make_pair(cr,cur.second+1));
				swap(a[x][y],a[x+mv[i][0]][y+mv[i][1]]);
			}
		}
	}
	return 0;
}
