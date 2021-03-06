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
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod=1e9+7;

int main(){
	fastio; 
	
	int n,v[112];
	
	cin>>n;
	fr(i,n){
		cin>>v[i];
	}
	int tot=0;
	int m[5]={1,0,1,0,1}; 
	
	for(int i=0;i<=n-5;i++){
		bool ok=1;
		for(int j=0;j<5;j++){
			if(v[i+j]!=m[j])
				ok=0;
		}
		if(ok){
			tot++; 
			v[i+2]=0;
		}
	}

	for(int i=1;i<n-1;i++){
		if(v[i-1]==1 && v[i]==0 && v[i+1]==1){
			tot++;
			v[i+1]=0;
		}
	}
	
	cout<<tot<<endl;	
}