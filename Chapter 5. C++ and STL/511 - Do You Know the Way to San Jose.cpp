#include<cstdio>
#include<string>
#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<cmath>
#define prec 1e-6
using namespace std;

struct LocationClass{
    string name;
	double x,y;
};

struct MapClass{
  double x1,x2,y1,y2;
  string name;
  inline double Area()
	{ return (x2-x1)*(y2-y1); }
  
	inline double Dist(LocationClass &Loc)
	{ return ((x1+x2)/2-Loc.x)*((x1+x2)/2-Loc.x)+((y1+y2)/2-Loc.y)*((y1+y2)/2-Loc.y);}
  
	inline double Prop()
	{ return (x2-x1)/(y2-y1); }
  
	inline double RiButtom(LocationClass &Loc)
	{ return (Loc.x-x2)*(Loc.x-x2)+(Loc.y-y1)*(Loc.y-y1); }
};

string name;
vector<MapClass> Maps;
map<string,LocationClass> Locs;

bool Compare(MapClass &a,MapClass &b,LocationClass &Loc){
  if(fabs(a.Area()-b.Area())<prec){
	  if(fabs(a.Dist(Loc)-b.Dist(Loc))<prec){
	    if(fabs(fabs(a.Prop()-0.75)-fabs(b.Prop()-0.75))<prec){
		    if(fabs(a.RiButtom(Loc)-b.RiButtom(Loc)<prec)){
		  	  return a.x1>b.x1;
		    }
		    return a.RiButtom(Loc)<b.RiButtom(Loc);
	    }
	    return fabs(a.Prop()-0.75)>fabs(a.Prop()-0.75);
	  }
  	return a.Dist(Loc)>b.Dist(Loc);
  }
  return a.Area()<b.Area();
}

void Request(LocationClass &Loc,unsigned k){
  list<MapClass> l;
  for(auto i=Maps.begin();i!=Maps.end();++i){
  	if(i->x1<=Loc.x&&Loc.x<=i->x2&&i->y1<=Loc.y&&Loc.y<=i->y2){
  	  auto j=l.begin();
			while(j!=l.end()&&Compare(*i,*j,Loc))
			  ++j;
  	  l.insert(j,*i);
    }
  }
/*  
  for(auto it=l.begin();it!=l.end();++it)
    cout<<it->name<<' ';
  cout<<endl;
*/  
  if(l.begin()==l.end())
  	cout<<" no map contains that location\n";
  else{
	  unsigned i=1;
	  auto it=l.begin();
	  string MapName=l.begin()->name;
    for(auto last=it++;it!=l.end();++it)
  	  if(fabs(it->Area()-last->Area())>=prec){
  	  	++i;
  	    if(i<=k)
  	      MapName=it->name;
  	  }
  	if(i<k)
  	  cout<<" no map at that detail level; using "<<MapName<<'\n';
  	else
  	  cout<<" using "<<MapName<<'\n';
	}
}



int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  LocationClass Loc;
  MapClass Map;
  
  do cin>>name;
  while(name!="MAPS");
  while(cin>>name&&name!="LOCATIONS"){
  	Map.name=name;
  	cin>>Map.x1>>Map.y1>>Map.x2>>Map.y2;
  	if(Map.x1>Map.x2){
  	  double t=Map.x1;
  	  Map.x1=Map.x2;
  	  Map.x2=t;
	  }
	  if(Map.y1>Map.y2){
	    double t=Map.y1;
	    Map.y1=Map.y2;
	    Map.y2=t;
	  }
  	Maps.push_back(Map);
  };
  while(cin>>name&&name!="REQUESTS"){
  	Loc.name=name;
  	cin>>Loc.x>>Loc.y;
  	Locs[name]=Loc;
  }
/*
  cout<<"Maps:\n";
  for(auto it=Maps.begin();it!=Maps.end();++it)
    cout<<it->name<<' '<<it->x1<<' '<<it->y1<<' '<<it->x2<<' '<<it->y2<<'\n';
  cout<<"Locs:\n";
  for(auto it=Locs.begin();it!=Locs.end();++it)
    cout<<it->second.name<<' '<<it->second.x<<' '<<it->second.y<<'\n';
*/
  while(cin>>name&&name!="END"){
  	unsigned k;
  	cin>>k;
  	cout<<name<<" at detail level "<<k;
  	if(!Locs.count(name)){
  		cout<<" unknown location\n";
  		continue;
		}
  	Loc=Locs[name];
  	Request(Loc,k);
  }
  return 0;
}
