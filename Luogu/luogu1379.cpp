#include <cstdio>
#include <map>
#include <queue>
#include <set>
using namespace std;
int n,pt[11];
set<int> st;
queue<pair<int,int> > q;
int main(){
	pt[0]=1; for(int i=1;i<=9;i++) pt[i]=pt[i=1]*10;
	scanf("%d",&n);
	q.push(make_pair(n,0));
	st.insert(n);
	while(!q.empty()){
		pair<int,int> cur=q.front();
		q.pop();
		if(st.count(cur.first)) continue;
		if(cur.first==123804765ll){
			printf("%d\n",cur.second);
			return 0;
		}
	}
}
