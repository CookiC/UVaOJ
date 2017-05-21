/*********************************************************************************************
*先用set记录s 后再改写                                                                       *
*用刷表法递推                                                                                *
*状态s(i,x1,x2,x3)由可进行转移的s(i-1, , , )转移过来                                         *
*用刷表法 若为空则无法转移到 刷表法可以使用算出即丢弃的方法                                  *
*s(i-1,x1,x2,x3)可影响的范围是s(i,x1+1,x2,x3),s(i,x1,x2+1,x3),s(i,x1,x2,x3+1),s(i,x1,x2,x3)  *
*所以可以采取后往前刷的方法                                                                  *
*若s(i-1,x1,x2,x3)无法到达s(i,x1,x2,x3),则将s(i,x1,x2,x3)置为空 #include<cstdio>             *
*********************************************************************************************/
#include<cstdio>
#include<cstring>
#include<set>
#include<cstdlib>
using namespace std;

int i,j,x1,x2,x3,x4;
unsigned n;
unsigned p[4][41];
set<unsigned> s[45][45][45];

void Shift(set<unsigned> u,set<unsigned> &v,unsigned p){
	v=u;
	set<unsigned>::iterator it=v.find(p); 
	if(it!=v.end())
		v.erase(it);
	else
		v.insert(p); 
}



int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	while(scanf("%u",&n)!=EOF&&n){
		for(x1=0;x1<=n+1;++x1)
			for(x2=0;x2<=n+1;++x2)
				for(x3=0;x3<=n+1;++x3){
					s[x1][x2][x3].clear();
					s[x1][x2][x3].insert(21);
					s[x1][x2][x3].insert(22);
					s[x1][x2][x3].insert(23);
					s[x1][x2][x3].insert(24);
					s[x1][x2][x3].insert(25);
				}
		
		for(j=0;j<n;++j)
			for(i=0;i<4;++i)
				scanf("%u",&p[i][j]);
		 
		bool found=1;
		s[0][0][0].clear();
		for(i=0;i<4*n&&found;++i){
			found=0;
			for(x1=n>i?i:n;x1>=0;--x1)
				for(x2=n>i?i:n;x2>=0;--x2)
					for(x3=n>i?i:n;x3>=0;--x3){
						x4=i-x1-x2-x3;
						if(0<=x4&&x4<=n){
							if(s[x1][x2][x3].size()<5){
								Shift(s[x1][x2][x3],s[x1+1][x2][x3],p[0][x1]);
								Shift(s[x1][x2][x3],s[x1][x2+1][x3],p[1][x2]);
								Shift(s[x1][x2][x3],s[x1][x2][x3+1],p[2][x3]);
								Shift(s[x1][x2][x3],s[x1][x2][x3],p[3][i-x1-x2-x3]);
								found=1;
							}
						}
					}
					//如果s(i,x1,x2,x3)无法转移 则s(i+1,x1,x2,x3)被更新前也无法转移 
		}
		if(i==4*n){ 
			printf("%d\n",(4*n-s[n][n][n].size())/2);
		} 
		else
			printf("%d\n",i-6<0?0:(i-6)/2);
	}
	return 0;
}
