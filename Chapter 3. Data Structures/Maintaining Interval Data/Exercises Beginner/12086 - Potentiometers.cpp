//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cstring>
#define maxN 200010
#define lowbit(x) (x&-x)
//#pragma warning(disable : 4996)
using namespace std;

bool quickIn(int &x){
	char c;
	while((c=getchar())!=EOF&&!isdigit(c));
	if(c==EOF)
		return false;
	x=0;
	do{
		x*=10;
		x+=c-'0';
	}while((c=getchar())!=EOF&&isdigit(c));
	return true;
}

bool quickIn(char *p){
	char c;
	while((c=getchar())!=EOF&&(c==' '||c=='\n'));
	if(c==EOF)
		return false;
	do{
		*p++=c;
	}while((c=getchar())!=EOF&&c!=' '&&c!='\n');
	return true;
}

void quickOut(int x){
	char str[13];
	if(x){
		int i;
		for(i=0;x;++i){
			str[i]=x%10+'0';
			x/=10;
		}
		while(i--)
			putchar(str[i]);
	}
	else
		putchar('0');
}

void quickOut(char *p){
	while(*p)
		putchar(*p++);
}

class FenwickTree{
private:
	int C[maxN];
public:
	int maxLen;
	
	FenwickTree(){
		memset(C,0,maxN*sizeof(int));
		maxLen=maxN-1;
	}

	void clear(){
		memset(C,0,(maxLen+1)*sizeof(int));
	}
	
	int sum(unsigned x){
		int sum=0;
		while(x>0){
			sum+=C[x];
			x-=lowbit(x);
		}
		return sum;
	}

	int add(unsigned x,int d){
		while(x<=maxLen){
			C[x]+=d;
			x+=lowbit(x);
		}
	}
};

FenwickTree fTree;
int a[maxN];

int main(){
	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);

	int i,N,x,y,T;
	char s[10];
	for(T=1;quickIn(N)&&N;++T){
		quickOut("Case ");
		quickOut(T);
		quickOut(":\n");
		fTree.maxLen=N;
		fTree.clear();
		for(i=1;i<=N;++i){
			quickIn(a[i]);
			fTree.add(i,a[i]);
		}
		while(quickIn(s)){
			if(!strcmp(s,"END")){
				break;
			}
			quickIn(x);
			quickIn(y);
			if(s[0]=='S'){
				fTree.add(x,y-a[x]);
				a[x]=y;
			}
			else{
				quickOut(fTree.sum(y)-fTree.sum(x-1));
				putchar('\n');
			}
		}
		putchar('\n');
	};	
	return 0;
}

