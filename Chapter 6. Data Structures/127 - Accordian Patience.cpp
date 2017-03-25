#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> p[53];

void Move(unsigned i){
	unsigned j;
	if(!p[i].size()){
		j=i;
		do{
			p[j]=p[j+1];
			++j;
		}while(p[j].size());
	}
};

int main(){
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  string s;
  int i,j;
  bool change;
  while(cin>>s&&s[0]!='#'){
  	for(i=0;i<=52;++i)
  	  p[i].clear();
  	p[0].push_back(s);
  	for(i=1;i<52;++i){
  	  cin>>s;
  	  p[i].push_back(s);
    }
    change=true;
    while(change){
    	change=false;
		  for(i=1;p[i].size();++i){
			  if(i-3>=0&&(p[i-3][p[i-3].size()-1][0]==p[i][p[i].size()-1][0]||p[i-3][p[i-3].size()-1][1]==p[i][p[i].size()-1][1])){
			    p[i-3].push_back(p[i][p[i].size()-1]);
			    p[i].pop_back();
			    Move(i);
			    change=true;
			    break;
		    }
		    if(p[i-1][p[i-1].size()-1][0]==p[i][p[i].size()-1][0]||p[i-1][p[i-1].size()-1][1]==p[i][p[i].size()-1][1]){
			    p[i-1].push_back(p[i][p[i].size()-1]);
					p[i].pop_back();
					Move(i);
					change=true;
			    break;
		    }
		  }
		}
		for(i=0;p[i].size();++i);
		if(i==1)
		  printf("1 pile remaining:");
		else
		  printf("%d piles remaining:",i);
		for(i=0;p[i].size();++i)
		  printf(" %u",p[i].size());
		printf("\n");
	}
  return 0;
}

