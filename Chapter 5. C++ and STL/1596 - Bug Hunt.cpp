#include<iostream>
#include<string>
#include<cctype>
#include<map>
using namespace std;

struct Array{
  int size;
  map<int,unsigned> value;
};

map<string,Array> a;


void Separate(string s,string& name,string& expression){
  unsigned i;
  for(i=0;s[i]!='[';++i);
  name=s.substr(0,i);
  expression=s.substr(i+1,s.size()-i-2);
}

int ExpressionValue(string s){
  unsigned i;
  if(isdigit(s[0])){
  	unsigned sum=0;
  	for(i=0;i<s.size();++i)
  	  sum=sum*10+s[i]-'0';
  	return sum;
  }
  string name,expression;
  int index;
  Separate(s,name,expression);
  index=ExpressionValue(expression);
  if(!a[name].value.count(index)||index<0||index>=a[name].size)
    return -1;
  return a[name].value[index];
}

unsigned i,j;
bool isdef,valid;
unsigned linenum;
unsigned twice;
string line,expression,name;

int main(){
  //freopen("test.in","r",stdin);
  //freopen("test.out","w",stdout);
 
  do{
  	a.clear();
  	valid=true;
  	linenum=0;
  	for(i=0;cin>>line&&line[0]!='.'&&valid;++i){
  	  twice=0;
  	  isdef=true;
  	  for(j=0;j<line.size();++j)
  		if(line[j]=='='){
  	      isdef=false;
  	      break;
  	    }
  	  if(isdef){
  	    Separate(line,name,expression);
  	    Array t;
  	    t.size=ExpressionValue(expression);
  	    t.value.clear();
  	    if(t.size<0)
  	      valid=false;
  	    else
  	      a[name]=t;
	  }
  	  else{
  	  	string front,back;
		int index,value;
  	  	for(j=0;j<line.size()&&line[j]!='=';++j);
  	  	front=line.substr(0,j);
  	  	back=line.substr(j+1,line.size()-j-1);
  	  	Separate(front,name,expression);
  	  	index=ExpressionValue(expression);
  	  	value=ExpressionValue(back);
  	  	if(index<0||index>=a[name].size||value<0)
  	      valid=false;
  	    else
  	  	  a[name].value[index]=value;
	  }
 	}
 	while(line[0]!='.')
	  cin>>line;
	++twice;
  	if(!valid)
  	  linenum=i;
  	if(twice<=1)
  	  cout<<linenum<<endl;
  }while(twice<=1);
  return 0;
}

