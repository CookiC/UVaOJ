//Author:CookiC
//#include "stdafx.h"
#include<iostream>
#include<algorithm>
#define maxN 100010
//#pragma warning(disable : 4996)
using namespace std;

struct Node{
	int k,s,v,mink,min;
	bool f;
	Node *c[2];
	
	Node():f(0){}
	
	void pushdown(){
		if(f){
			Node *t;
			t=c[0];
			c[0]=c[1];
			c[1]=t;
			if(c[0]!=NULL)
				c[0]->f^=f;
			if(c[1]!=NULL)
				c[1]->f^=f;
			f=0;
		}
	}
	
	void pushup(){
		s=1;
		mink=k;
		min=v;
		if(c[0]!=NULL){
			if(min>c[0]->min||min==c[0]->min&&mink>c[0]->mink){
				mink=c[0]->mink;
				min=c[0]->min;
			}
			s+=c[0]->s;
		}
		if(c[1]!=NULL){
			if (min>c[1]->min || min == c[1]->min&&mink>c[1]->mink){
				mink=c[1]->mink;
				min=c[1]->min;
			}
			s+=c[1]->s;
		}
	}
	
	int cmp(int x){
		if(k==x)
			return -1;
		if(c[0]!=NULL&&c[0]->mink==x)
			return 0;
		else
			return 1;
	}
};

class SplayTree{
private:
	Node *rear;
	Node nodes[maxN];
	int *a;
	
	void rotate(Node* &o,bool d){
		Node* k=o->c[d^1];
		o->c[d^1]=k->c[d];
		k->c[d]=o;
		o->pushup();
		k->pushup();
		o=k;
	}
	
	void build(Node *o,int L,int R){
		int M=L+(R-L)/2;
		o->v=a[M];
		o->k=M;
		if(M>L){
			o->c[0]=++rear;
			build(rear,L,M-1);
		}
		else
			o->c[0]=NULL;
		if(M<R){
			o->c[1]=++rear;
			build(rear,M+1,R);
		}
		else
			o->c[1]=NULL;
		o->pushup();
	}
	
	void Splay(Node* &o,int k){
		o->pushdown();
		int d1=o->cmp(k);
		if(d1!=-1){
			Node *p=o->c[d1];
			p->pushdown();
			int d2=p->cmp(k);
			if(d2!=-1){
				Splay(p->c[d2],k);
				if(d1==d2)
					rotate(o,d1^1);
				else
					rotate(o->c[d1],d1);
			}
			rotate(o,d1^1);
		}
	}
public:
	Node* build(int *A,int len){
		rear=nodes;
		a=A;
		build(nodes,1,len);
		return nodes;
	}
	
	Node* merge(Node *left,Node *right){
		if (left == NULL)
			return right;
		left->pushdown();
		while (left->c[1] != NULL){
			left->c[1]->pushdown();
			rotate(left, 0);
		}
		left->c[1]=right;
		left->pushup();
		return left;
	}
	
	void split(Node *o,Node* &left,Node* &right){
		Splay(o,o->mink);
		left=o;
		right=o->c[1];
		left->c[1]=NULL;
		left->pushup();
	}
};

int N,i;
int a[maxN];
Node *root,*L,*R,*P;
Node *S[maxN];
SplayTree st;

bool cmp(const Node *a,const Node *b){
	return a->v<b->v;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	while (cin >> N&&N){
		for (i = 1; i <= N; ++i)
			cin >> a[i];
		root = st.build(a, N);
		for (int i = 0; i < N; ++i){
			st.split(root, L, R);
			if (i)
				cout << ' ';
			cout << L->s + i;
			L->f ^= 1;
			st.split(L, P, L);
			root = st.merge(L, R);
		}
		cout << endl;
	}
	return 0;
}

