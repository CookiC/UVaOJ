#include<string>
#include<map>
#include<iostream>
using namespace std;

int T;
string Old,New;
map<string,string> OldMap,NewMap;

void SaveInMap(string &str,map<string,string> &Map){
  string key,value;
  unsigned i=0;
  while(i<str.size()){
  	key.clear();
  	value.clear();
  	while(str[i]!=':'&&i<str.size())
  	  key.push_back(str[i++]);
  	++i;
  	while(str[i]!=','&&i<str.size())
  	  value.push_back(str[i++]);
  	++i;
  	Map[key]=value;
  }
}

bool CompareMap(map<string,string> a,map<string,string> b){
  bool incf,decf,chaf,change;
  incf=true;
  for(auto it=b.begin();it!=b.end();++it)
    if(!a.count(it->first))
      if(incf){
        cout<<'+'<<it->first;
        incf=false;
      }
      else
        cout<<','<<it->first;
  if(!incf)
    cout<<endl;

  decf=true;
  for(auto it=a.begin();it!=a.end();++it)
    if(!b.count(it->first))
      if(decf){
        cout<<'-'<<it->first;
        decf=false;
      }
      else
        cout<<','<<it->first;
  if(!decf)
    cout<<endl;

  chaf=true;
  for(auto it=a.begin();it!=a.end();++it)
    if(b.count(it->first)&&b[it->first]!=it->second)
      if(chaf){
        cout<<'*'<<it->first;
        chaf=false;
      }
      else
        cout<<','<<it->first;
  if(!chaf)
    cout<<endl;
  
  return !(incf&&decf&&chaf);
}

int main(){
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  cin>>T;
  while(T--){
  	OldMap.clear();
  	NewMap.clear();
  	
  	cin>>Old>>New;
  	Old=Old.substr(1,Old.size()-2);
  	New=New.substr(1,New.size()-2);
  	SaveInMap(Old,OldMap);
  	SaveInMap(New,NewMap);
  	if(!CompareMap(OldMap,NewMap))
	  cout<<"No changes"<<endl;
  	cout<<endl;
  }
  return 0;
}

