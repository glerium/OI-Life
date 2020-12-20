#include <bits/stdc++.h>
using namespace std;
const int a[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n;
struct Point{
	int x,y,dir;
	bool operator<(const Point& rhs)const{return dir!=rhs.dir?dir<rhs.dir:x!=rhs.x?x<rhs.x:y<rhs.y;}
};
set<Point> q[1007];
struct P2{
	int x,y;
	bool operator<(const P2& rhs)const{return x!=rhs.x?x<rhs.x:y<rhs.y;}
};
set<P2> q2;
int main(){
	for(int n=1;n<=20;n++){
	q[0].clear();
	for(int i=0;i<4;i++) q[0].insert((Point){0,0,i});
	for(int i=1;i<=n;i++){
		q[i].clear();
		for(set<Point>::iterator it=q[i-1].begin();it!=q[i-1].end();it++){
			Point cur=*it;
			if(cur.dir==2||cur.dir==3) q[i].insert((Point){cur.x+1,cur.y,0}),q[i].insert((Point){cur.x-1,cur.y,1});
			else if(cur.dir==1||cur.dir==0) q[i].insert((Point){cur.x,cur.y+1,2}),q[i].insert((Point){cur.x,cur.y-1,3});
		}
	}
	q2.clear();
	for(set<Point>::iterator it=q[n].begin();it!=q[n].end();it++) q2.insert((P2){it->x,it->y});
	printf("%d\n",q2.size());
	}
//	scanf("%d",&n);
	return 0;
}
