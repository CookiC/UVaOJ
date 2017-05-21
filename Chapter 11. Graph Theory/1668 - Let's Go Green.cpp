//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<vector>
#include<cstring>
#define maxn 100010
//#pragma warning(disable : 4996)
using namespace std;

bool QIn(int &x){
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

void QOut(int x){
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

void QOut(char *p){
	while(*p)
		putchar(*p++);
}

int d[maxn],md[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
//	ios::sync_with_stdio(false);
	
	int T,M,N,u,v,w,i,ans;
	QIn(M);
	for(T=1;T<=M;++T){
		memset(d,0,sizeof(d));
		memset(md,0,sizeof(md));
		QIn(N);
		ans=0;
		for(i=0;i<N-1;++i){
			QIn(u);
			QIn(v);
			QIn(w);
			d[u]+=w;
			d[v]+=w;
			if(w>md[u])
				md[u]=w;
			if(w>md[v])
				md[v]=w;
			ans+=w;
		}
		
		for(i=1;i<=N;++i)
			if((md[i]<<1)<=d[i])
				ans-=d[i]>>1;
			else
				ans-=d[i]-md[i];
		QOut("Case #");
		QOut(T);
		QOut(": ");
		QOut(ans);
		putchar('\n');
	}
	return 0;
}

