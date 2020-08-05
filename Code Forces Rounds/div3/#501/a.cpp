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


int main(){
	fastio; 
	int seg[102],n,m,i,j,a,b,cont; 
	for(i=0;i<102;i++) 
		seg[i]=0; 
	cin>>n>>m; 
	cont=0;
	fr(i,n){ 
		cin>>a>>b; 
		for(j=a;j<=b;j++) 
			if(seg[j]!=1){
				seg[j]=1;
				cont++;
			}
	}
	cout<<m-cont<<endl; 
	for(i=1;i<=m;i++) 
		if(seg[i]==0) 
			cout<<i<<' '; 
	cout<<endl;	
	return 0;
}