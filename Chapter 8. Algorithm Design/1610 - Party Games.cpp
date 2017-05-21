#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

unsigned n;
int i,j;
string str[1010],a,b,m;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	while(cin>>n&&n){
		for(i=0;i<n;++i)
			cin>>str[i];
		sort(str,str+n);

		//a长度更短或有字母在前
		a=str[n/2-1];
		b=str[n/2];
		for(i=1;i<a.size();++i){
			m=a.substr(0,i);
			if(m[i-1]<'Z'){
				++m[i-1];
				if(m<b)
					break;
			}
		}
		if(i>=a.size())
			m=a;
		cout<<m<<endl;
	}
	return 0;
}

