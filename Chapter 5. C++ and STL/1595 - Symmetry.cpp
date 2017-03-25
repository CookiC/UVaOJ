#include<cstdio>
#include<set>
#include<algorithm>
#include<iostream>
using namespace std;

struct Point{
  int x,y;
  bool operator < (const Point &b) const{
  	if(x==b.x)
  	  return y<b.y;
    return x<b.x;
  }
};
Point p[1010];
int T;
unsigned n;

bool Symmetry(unsigned lefti,unsigned righti){
  unsigned i;
  multiset<Point> s;
  s.clear();
  for(i=0;i<n;++i){
    if(p[lefti].x==p[righti].x&&p[lefti].x==p[i].x)
      continue;
  	Point tp;
  	tp.x=p[lefti].x+p[righti].x-p[i].x;
  	tp.y=p[i].y;
  	
	auto it=s.find(tp);
    if(it==s.end()){
      //cout<<"push "<<p[i].x<<' '<<p[i].y<<endl;
      s.insert(p[i]);
    }
    else{
      //cout<<it->x<<' '<<it->y<<" | "<<p[i].x<<' '<<p[i].y<<endl;
      s.erase(it);
	}
  }
  if(s.empty())
    return true;
  return false;
}

int main(){
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  scanf("%d",&T);
  while(T--){
    unsigned lefti,righti;
	
	scanf("%u",&n);
    for(unsigned i=0;i<n;++i)
      scanf("%d%d",&p[i].x,&p[i].y);
    sort(p,p+n);

    if(n%2==0)
    {
	  lefti=n/2-1;
      righti=n/2;
    }
    else
      lefti=righti=n/2;
    if(Symmetry(lefti,righti))
	  printf("YES\n");
	else
	  printf("NO\n");
  }
  return 0;
}

