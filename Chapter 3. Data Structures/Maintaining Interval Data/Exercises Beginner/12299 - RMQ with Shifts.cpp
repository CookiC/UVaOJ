//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cctype>
//#pragma warning(disable : 4996)
#define maxn 100010
#define maxlen 400010
#define INF 0x7FFFFFFF
using namespace std;

bool qIn(int &x){
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

bool qIn(char *p){
	char c;
	while((c=getchar())!=EOF&&(c==' '||c=='\n'));
	if(c==EOF)
		return false;
	do{
		*p++=c;
	}while((c=getchar())!=EOF&&c!=' '&&c!='\n');
	*p=0;
	return true;
}

void qOut(int x){
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

void qOut(char *p){
	while(*p)
		putchar(*p++);
}

struct TreeNode{
	int min;
	int L,R;
};

class SegmentTree{
private:
	TreeNode tree[maxlen];
	int *a,qL,qR,uX,uN;
	
	void build(int o,int L,int R){
		tree[o].L=L;
		tree[o].R=R;
		if(L==R){
			tree[o].min=a[L];
			return;
		}
		int M=L+(R-L)/2;
		build(o*2,L,M);
		build(o*2+1,M+1,R);
		tree[o].min=min(tree[o*2].min,tree[o*2+1].min);
	}
	
	int query(int o){
		int L=tree[o].L;
		int R=tree[o].R;
		if(qL<=L&&R<=qR)
			return tree[o].min;
		int ans=INF,M=L+(R-L)/2;
		if(qL<=M) ans=min(ans,query(o*2));
		if(M<qR) ans=min(ans,query(o*2+1));
		return ans;
	}
	
	void update(int o){
		int L=tree[o].L;
		int R=tree[o].R;
		if(L==R){
			tree[o].min=uX;
			return;
		}
		int M=L+(R-L)/2;
		if(uN<=M) update(o*2);
		else update(o*2+1);;
		tree[o].min=min(tree[o*2].min,tree[o*2+1].min);
	}
public:	
	void build(int *array,int len){
		a=array;
		build(1,1,len);
	}
	
	int query(int L,int R){
		qL=L;
		qR=R; 
		return query(1);
	}
	
	void update(int N,int X){
		uX=X;
		uN=N;
		update(1);
	}
};

SegmentTree Tree;
int n,q,i,j,k;
char *p;
char op[40];
int a[maxn],b[30];

void split(){
	k=0;
	while(*p){
		int x=0;
		while(isdigit(*p))
			x=x*10+*p++-'0';
		if(x)
			b[k++]=x;
		++p;
	}
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	qIn(n);
	qIn(q);
	for(i=1;i<=n;++i)
		qIn(a[i]);
	Tree.build(a,n);
	for(i=0;i<q;++i){
		qIn(op);
		p=op+5;
		if(op[0]=='q'){
			split();
			qOut(Tree.query(b[0],b[1]));
			putchar('\n');
		}
		else{
			split();
			int t=a[b[0]];
			for(j=0;j<k-1;++j){
				a[b[j]]=a[b[j+1]];
				Tree.update(b[j],a[b[j]]);
			}
			a[b[k-1]]=t;
			Tree.update(b[k-1],t);
		}
	}
	return 0;
}

