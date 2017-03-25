#include<iostream>
#include<set>
#include<string>
using namespace std;

string s;
set<string> word;

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  while(cin>>s)
  	word.insert(s);
  for(auto i=word.begin();i!=word.end();++i)
  {
  	auto j=i;
  	while(j!=word.begin()&&(*i)[0]==(*j)[0])
	{ 
	  --j;
  	  if(*j==(*i).substr(0,(*j).size())&&word.find((*i).substr((*j).size(),(*i).size()))!=word.end())
  	  {
	    cout<<*i<<endl;
	    break;
      }
    }
  }
  return 0;
}

