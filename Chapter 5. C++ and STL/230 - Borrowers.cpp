#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

struct Book{
  string title,author;
  
  void clear(){
    title.clear();
    author.clear();
  }
  
  Book(){  clear();  }
  
  bool input(){
  	string line;
  	
  	getline(cin,line);
  	if(line=="END")
  	  return false;
	unsigned i,begin;
  	for(i=0;i<line.size()&&line[i]!='"';++i);
	for(begin=i++;i<line.size()&&line[i]!='"';++i);
	title=line.substr(begin,i+1);
	author=line.substr(i+5,line.size());
	return true;
  }
  
  void output(){
  	cout<<title<<' '<<author<<endl;
  }
};

struct command{
  string cmd,title;
  bool input(){
  	cin>>cmd;
	if(cmd=="END")
  	  return false;
  	if(cmd!="SHELVE"){
  	  getchar();
  	  getline(cin,title);
    }
	return true;
  }
};

vector<Book> inf;

struct bookcmp1{
  bool operator ()(const unsigned& a,const unsigned& b){
  	if(inf[a].author==inf[b].author)
  	  return inf[a].title<inf[b].title;
  	return inf[a].author<inf[b].author;
  }
};

struct bookcmp2{
  bool operator ()(const unsigned& a,const unsigned& b){
  	if(inf[a].author==inf[b].author)
  	  return inf[a].title>inf[b].title;
  	return inf[a].author>inf[b].author;
  }
};

map<string,unsigned> bookid;
set<unsigned,bookcmp1> shelf;
priority_queue<unsigned,vector<unsigned>,bookcmp2> que;
Book b;
command c;
unsigned i;

inline void BORROW(string title){
  shelf.erase(bookid[title]);
}

inline void RETURN(string title){
  que.push(bookid[title]);
}

inline void SHELVE(){
  while(!que.empty()){
  	auto it=shelf.insert(que.top()).first;
  	que.pop();
  	if(it==shelf.begin())
  	  cout<<"Put "<<inf[*it].title<<" first"<<endl;
	else{
  	  cout<<"Put "<<inf[*++it].title<<" after "<<inf[*--it].title<<endl;
    }
  }
  cout<<"END"<<endl;
}

int main(){
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);

  for(i=0;b.input();++i){
  	inf.push_back(b);
  	shelf.insert(i);
  	bookid[inf[i].title]=i;
  	b.clear();
  }
  
//  for(auto it=shelf.begin();it!=shelf.end();++it)
//    cout<<inf[*it].title<<' '<<inf[*it].author<<endl;
  for(i=0;c.input();++i){
    if(c.cmd=="BORROW")
      BORROW(c.title);
	else if(c.cmd=="RETURN")
	  RETURN(c.title);
	else
	  SHELVE();
  }
  return 0;
}

