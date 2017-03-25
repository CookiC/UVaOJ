#include<iostream>
#include<iomanip>
#include<string>
#include<queue>
#include<cstring>
using namespace std;

struct Patient{
	string name;
	unsigned st,rt;
	unsigned room,b1,e1,bed,b2,e2;
};

struct Event{
	unsigned type,fid,pid;
	Event(unsigned type,unsigned fid,unsigned pid):type(type),fid(fid),pid(pid){};
	bool operator < (const Event &b) const{
		if(type==b.type){
		  return fid>b.fid;
		}
		return type<b.type;
	}
};

unsigned n,m,k,T,t1,t2,t3;
unsigned i,j,curt,last,sum;
unsigned room[20],bed[40];
Patient p[110];
priority_queue<Event> line[2000];
bool bempty[40];

void Initial(){
	T*=60;
	sum=last=T;
	j=1;
	memset(bempty,1,sizeof(bempty));
	memset(room,0,sizeof(room));
	memset(bed,0,sizeof(bed));
	
	for(i=1;i<=n;++i)
	  line[T].push(Event(1,i,0));
}

//0
void SurgeryEnd(unsigned fid,unsigned pid,unsigned curt){
	line[curt+t2].push(Event(1,fid,0));
	for(i=1;i<=m&&!bempty[i];++i);
	line[curt+t1+p[pid].rt+t3].push(Event(2,i,0));
	p[pid].bed=i;
	p[pid].b2=curt+t1;
	p[pid].e2=curt+t1+p[pid].rt;
	if(p[pid].e2>sum)
	  sum=p[pid].e2;
	if(curt+t1+p[pid].rt+t3>last)
	  last=curt+t1+p[pid].rt+t3;
	bed[i]+=p[pid].rt;
	bempty[i]=false;
}

//1
void RoomEmpty(unsigned fid,unsigned &pid,unsigned curt){
	if(pid<=k){
	  line[curt+p[pid].st].push(Event(0,fid,pid));
	  p[pid].room=fid;
	  p[pid].b1=curt;
	  p[pid].e1=curt+p[pid].st;
	  if(p[pid].e1>last)
	    last=p[pid].e1;
	  room[fid]+=p[pid].st;
	  ++pid;
	}
}

//2
void BedEmpty(unsigned fid){
//	if(fid==4)
//	  cout<<setw(2)<<curt/60<<':'<<setw(2)<<curt%60<<" Four Empty."<<endl;
	bempty[fid]=true;
}

void Output(){
	cout<<" Patient          Operating Room          Recovery Room\n"
      <<" #  Name     Room#  Begin   End      Bed#  Begin    End\n"
      <<" ------------------------------------------------------\n";
	for(i=1;i<=k;++i)
    cout<<setw(2)<<i<<"  "<<left<<setw(10)<<p[i].name
		    <<right<<setw(2)<<p[i].room<<
				setw(5)<<p[i].b1/60<<':'<<setfill('0')<<setw(2)<<p[i].b1%60<<setfill(' ')<<
				setw(5)<<p[i].e1/60<<':'<<setfill('0')<<setw(2)<<p[i].e1%60<<setfill(' ')<<
				setw(7)<<p[i].bed<<
				setw(5)<<p[i].b2/60<<':'<<setfill('0')<<setw(2)<<p[i].b2%60<<setfill(' ')<<
				setw(5)<<p[i].e2/60<<':'<<setfill('0')<<setw(2)<<p[i].e2%60<<setfill(' ')<<
        endl;
	cout<<endl;
	
	cout<<"Facility Utilization\n"
      <<"Type  # Minutes  % Used\n"
      <<"-------------------------\n";
  for(i=1;i<=n;++i)
    cout<<"Room"<<setw(3)<<i<<setw(8)<<room[i]<<setw(8)<<fixed<<setprecision(2)<<(double)room[i]/(sum-T)*100<<endl;
  for(i=1;i<=m;++i)
    cout<<"Bed "<<setw(3)<<i<<setw(8)<<bed[i]<<setw(8)<<fixed<<setprecision(2)<<(double)bed[i]/(sum-T)*100<<endl;
  cout<<endl;
}

int main(){
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
	while(cin>>n){
    cin>>m>>T>>t1>>t2>>t3>>k;
    for(i=1;i<=k;++i)
      cin>>p[i].name>>p[i].st>>p[i].rt;

    Initial();
    for(curt=T;curt<=last;++curt){
      while(!line[curt].empty()){
			  Event e=line[curt].top();
    	  line[curt].pop();
    	  switch(e.type){
    		  case 0:SurgeryEnd(e.fid,e.pid,curt);break;
    		  case 1:RoomEmpty(e.fid,j,curt);break;
    		  case 2:BedEmpty(e.fid);
			  }
		  }
		}
	  Output();
	}
  return 0;
}

