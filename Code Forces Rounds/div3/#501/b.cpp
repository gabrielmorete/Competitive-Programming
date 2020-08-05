#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100; 

int c1[28],c2[28],n;

int rola(char s[],char t[]){
	int i;
	for(i=1;i<=n;i++) 
		c1[s[i]-'a']++; 
	for(i=1;i<=n;i++) 
		c2[t[i]-'a']++;
	for(i=0;i<28;i++) 
		if(c1[i]!=c2[i]) 
			return 0; 
	return 1;	
}


int main(){
	int i,count,j,k; 
	char s[52], t[52],c;
	pii mov[11234]; 
	scanf("%d",&n); 
	scanf("%c",&c); 

	frr(i,n)
		scanf("%c",&s[i]); 
	scanf("%c",&c);	 
	frr(i,n)
		scanf("%c",&t[i]);	 
	
	if(!rola(s,t)) 
		printf("-1\n"); 
	else{
		frr(i,n){
			if(t[i]==s[i]) 
				continue; 
			else{
				for(j=i+1;j<=n && s[j]!=t[i];j++); 
				k=j; 
				while(k!=i){
					mov[count].fst=k; 
					mov[count].snd=k-1; 
					count++; 
					k--;
				}	
				c=s[j]; 
				for(k=j;k>i;k--) 
					s[k]=s[k-1]; 
				s[i]=c;
			}
		}
		cout<<count<<endl; 
		fr(i,count) 
			cout<<mov[i].snd<<' '; 
		cout<<endl;	



	}		


	return 0;
}