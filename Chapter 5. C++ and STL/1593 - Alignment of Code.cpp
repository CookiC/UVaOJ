#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

unsigned i,j,m,n;
string line,word;
vector<unsigned> maxlen;
vector<string> code[1001];

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  m=0;
  for(i=0;getline(cin,line);++i)
  {
  	istringstream ss(line);
  	for(j=0;ss>>word;j++)
  	  code[i].push_back(word);
  	if(j>m)
  	  m=j;
  }
  n=i;
  
  maxlen.resize(m,0);
  for(j=0;j<m;++j)
    for(i=0;i<n;++i)
      if(code[i].size()>j&&maxlen[j]<code[i][j].size())
      	  maxlen[j]=code[i][j].size();

  for(i=0;i<n;++i)
  {
    for(j=0;j<m;++j)
      if(code[i].size()>j)
      {
      	if(j)
      	{
          string space(maxlen[j-1]-code[i][j-1].size()+1,' ');
          cout<<space;
        }
        cout<<code[i][j];
	  }
	cout<<endl;
  }
  return 0;
}

