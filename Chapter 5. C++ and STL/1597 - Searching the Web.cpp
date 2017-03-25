#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cctype>
#include<sstream>
#include<set>
#define dash "----------"
#define equal "=========="
using namespace std;

const set<string> invalid={"","the","a","to","end","or","not"};
vector<string> article[110];
map<string,vector<unsigned>> quiry;

inline void Output(const vector<string> &a){
  for(unsigned i=0;i<a.size();++i)
    cout<<a[i]<<endl;
}

void Preprocess(string line,unsigned artnum,unsigned linenum){
  set<string> words;
  string word;
  line.push_back('\n');
  word.clear();
  words.clear();
  for(unsigned i=0;i<line.size();++i)
    if(isalpha(line[i]))
      word.push_back(tolower(line[i]));
    else{
	  if(invalid.find(word)==invalid.end())
        words.insert(word);
	   word.clear();
    }
  for(auto it=words.begin();it!=words.end();++it)
    quiry[*it].push_back(artnum*10000+linenum);
}

void Output(const vector<unsigned> &a){
  unsigned artnum,linenum,i=0;
  if(a.size()==0){
    cout<<"Sorry, I found nothing."<<endl;
    return;
  }
  while(i<a.size()){
  	artnum=a[i]/10000;
  	linenum=a[i]%10000;
  	cout<<article[artnum][linenum]<<endl;
  	if(i<a.size()-1&&artnum!=a[i+1]/10000)
  	  cout<<dash<<endl;
  	++i;
  }
}

vector<unsigned> Intersection(const vector<unsigned> &a,const vector<unsigned> &b){
  vector<unsigned> c;
  auto i=a.begin();
  auto j=b.begin();
  c.clear();
  while(i!=a.end()&&j!=b.end())
  	if(*i/10000<*j/10000) ++i;
  	else if(*j/10000<*i/10000) ++j;
  	else{
  	  unsigned artnum=*i/10000;
  	  while(i!=a.end()&&*i/10000==artnum&&j!=b.end()&&*j/10000==artnum)
  	  	if(*i<*j){
		  c.push_back(*i);++i;  }
  	    else if(*j<*i){
		  c.push_back(*j);++j;  }
  	    else{
		  c.push_back(*i);
		  ++i;
		  ++j;
	    }
  	  if(i==a.end()||*i/10000!=artnum)
  	    while(j!=b.end()&&*j/10000==artnum){
		  c.push_back(*j);++j;  }
  	  if(j==b.end()||*j/10000!=artnum)
  	    while(i!=a.end()&&*i/10000==artnum){
		  c.push_back(*i);++i;  }
    }
  return c;
}

vector<unsigned> Union(const vector<unsigned> &a,const vector<unsigned> &b){
  vector<unsigned> c;
  auto i=a.begin();
  auto j=b.begin();
  while(i!=a.end()&&j!=b.end())
    if(*i<*j){
	  c.push_back(*i);++i;  }
	else if(*j<*i){
	  c.push_back(*j);++j;  }
    else{
      c.push_back(*i);
      ++i;
      ++j;
    }
  if(j==b.end())
    while(i!=a.end()){
	  c.push_back(*i);++i;  }
  if(i==a.end())
    while(j!=b.end()){
	  c.push_back(*j);++j;  }
  return c;
}

unsigned n,m,i,j;
string line;

int main(){
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);

  cin>>n;
  getline(cin,line);
  for(i=0;i<n;++i)
  	while(getline(cin,line)&&line!="**********")
  	    article[i].push_back(line);

  for(i=0;i<n;++i)
    for(j=0;j<article[i].size();++j)
      Preprocess(article[i][j],i,j);

  cin>>m;
  string cmd[3];
  getline(cin,line);
  for(i=0;i<m;++i){
  	getline(cin,line);
  	istringstream ss(line);
  	for(j=0;j<3&&ss>>cmd[j];++j);
  	if(j==1)
  	  Output(quiry[cmd[0]]);
  	else if(j==2){
  	  bool inart[110]={0};
  	  unsigned k;
  	  for(k=0;k<quiry[cmd[1]].size();++k)
  	    inart[quiry[cmd[1]][k]/10000]=true;
  	  bool first=true;
	  for(k=0;k<n;++k)
  	    if(!inart[k]){
  	      if(!first)
  	        cout<<dash<<endl;
  	      first=false;
  	      Output(article[k]);
  	    }
  	  if(first)
  	    cout<<"Sorry, I found nothing."<<endl;
    }
    else if(cmd[1]=="AND")
      Output(Intersection(quiry[cmd[0]],quiry[cmd[2]]));
    else
      Output(Union(quiry[cmd[0]],quiry[cmd[2]]));
    cout<<equal<<endl;
  }
  return 0;
}

