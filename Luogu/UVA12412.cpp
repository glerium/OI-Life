#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
const double eps=1e-5;
struct Student{
	string sid;
	int cid;
	string name;
	int rank;
	int s1,s2,s3,s4;
	int id=0;
	int total()const{return s1+s2+s3+s4;}
	bool operator<(const Student& rhs)const{return total()>rhs.total();}
}a[207];
bool cmp(const Student& lhs,const Student& rhs){
	return lhs.id<rhs.id;
}
multiset<Student> st;
int cnt,id;
void menu(){
	puts("Welcome to Student Performance Management System (SPMS).");
	puts("");
	puts("1 - Add");
	puts("2 - Remove");
	puts("3 - Query");
	puts("4 - Show ranking");
	puts("5 - Show Statistics");
	puts("0 - Exit");
	puts("");
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	int op;
	menu();
	cin>>op;
	while(op){
		if(op==1){
			Student tmp;
			puts("Please enter the SID, CID, name and four scores. Enter 0 to finish.");
			cin>>tmp.sid;
			while(tmp.sid!="0"){
				cin>>tmp.cid>>tmp.name>>tmp.s1>>tmp.s2>>tmp.s3>>tmp.s4;
				bool flag=true;
				for(multiset<Student>::iterator it=st.begin();it!=st.end();it++){
					if(it->sid==tmp.sid){
						puts("Duplicated SID.");
						flag=false;
						break;
					}
				}
				if(flag) tmp.id=++id, st.insert(tmp);
				puts("Please enter the SID, CID, name and four scores. Enter 0 to finish.");
				cin>>tmp.sid;
			} 
		}else if(op==2){
			string str;
			puts("Please enter SID or name. Enter 0 to finish.");
			cin>>str;
			while(str!="0"){
				int remove_cnt=0;
				multiset<Student>::iterator rem[207];
				for(multiset<Student>::iterator it=st.begin();it!=st.end();it++){
					if(it->sid==str||it->name==str)
						rem[++remove_cnt]=it;
				}
				for(int i=1;i<=remove_cnt;i++) st.erase(rem[i]);
				printf("%d student(s) removed.\n",remove_cnt);
				puts("Please enter SID or name. Enter 0 to finish.");
				cin>>str;
			}
		}else if(op==3){
			string str;
			puts("Please enter SID or name. Enter 0 to finish.");
			cin>>str;
			Student stu[207]; int wzl=0;
			for(multiset<Student>::iterator it=st.begin();it!=st.end();it++) stu[++wzl]=*it;
			while(str!="0"){
				int rank=0,dup=0,last;
				Student sss[207];
				int _cnt=0;
				for(int i=1;i<=wzl;i++){
					if(i!=1){
						if(stu[i].total()==last) dup++;
						else rank+=dup+1,dup=0;
					}else rank=1;
					last=stu[i].total();
					if(stu[i].sid==str||stu[i].name==str)
						sss[++_cnt]=stu[i],sss[_cnt].rank=rank;
				}
				sort(sss+1,sss+_cnt+1,cmp);
				for(int i=1;i<=_cnt;i++){
					cout<<sss[i].rank<<' '<<sss[i].sid<<' '<<sss[i].cid<<' '<<sss[i].name<<' '<<sss[i].s1<<' '<<sss[i].s2<<' '<<sss[i].s3<<' '<<sss[i].s4<<' ';
					printf("%d %.2f\n",sss[i].total(),1.0*sss[i].total()/4+eps);
				}
				puts("Please enter SID or name. Enter 0 to finish.");
				cin>>str;
			}
		}else if(op==4){
			puts("Showing the ranklist hurts students' self-esteem. Don't do that.");
		}
		else if(op==5){
			puts("Please enter class ID, 0 for the whole statistics.");
			int cid; cin>>cid;
			int tot1=0,tot2=0,tot3=0,tot4=0;
			int ps1=0,ps2=0,ps3=0,ps4=0;
			int psc1=0,psc2=0,psc3=0,psc4=0;
			int ccnt=0;
			for(multiset<Student>::iterator it=st.begin();it!=st.end();it++){
				if(cid&&cid!=it->cid) continue;
				ccnt++;
				int psc=0;
				tot1+=it->s1, tot2+=it->s2, tot3+=it->s3, tot4+=it->s4;
				if(it->s1>=60) ps1++,psc++; if(it->s2>=60) ps2++,psc++;
				if(it->s3>=60) ps3++,psc++; if(it->s4>=60) ps4++,psc++;
				if(psc==1) psc1++;
				else if(psc==2) psc2++,psc1++;
				else if(psc==3) psc3++,psc2++,psc1++;
				else if(psc==4) psc4++,psc3++,psc2++,psc1++;
			}
			printf("Chinese\nAverage Score: "); ccnt?printf("%.2lf\n",1.0*tot1/ccnt+eps):printf("-nan\n");
			printf("Number of passed students: %d\nNumber of failed students: %d\n\n",ps1,ccnt-ps1);
			printf("Mathematics\nAverage Score: "); ccnt?printf("%.2lf\n",1.0*tot2/ccnt+eps):printf("-nan\n");
			printf("Number of passed students: %d\nNumber of failed students: %d\n\n",ps2,ccnt-ps2);
			printf("English\nAverage Score: "); ccnt?printf("%.2lf\n",1.0*tot3/ccnt+eps):printf("-nan\n");
			printf("Number of passed students: %d\nNumber of failed students: %d\n\n",ps3,ccnt-ps3);
			printf("Programming\nAverage Score: "); ccnt?printf("%.2lf\n",1.0*tot4/ccnt+eps):printf("-nan\n");
			printf("Number of passed students: %d\nNumber of failed students: %d\n\n",ps4,ccnt-ps4);
			printf("Overall:\nNumber of students who passed all subjects: %d\nNumber of students who passed 3 or more subjects: %d\nNumber of students who passed 2 or more subjects: %d\nNumber of students who passed 1 or more subjects: %d\nNumber of students who failed all subjects: %d\n\n",psc4,psc3,psc2,psc1,ccnt-psc1);
		}
		menu();
		cin>>op;
	}
	return 0;
}
