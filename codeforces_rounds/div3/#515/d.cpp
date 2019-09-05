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
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod=1e9+7;

int main(){
	fastio; 
	int n,m,k,x;
	cin>>n>>m>>k; 
	vi v;
	fr(i,n){
		cin>>x; 
			v.pb(i);
	} 
	reverse(all(v)); 
	int bx,sz,tot; 
	bx=0,sz=0;
	tot=n;
	fr(i,n){
		if(sz+v[i]<=k)
			sz+=v[i]; 
		while(sz+v[i]>k){
			sz=0; 
			bx++;
		}



		if(sz==k){
			sz=0;
			bx++;
		}
		if(bx>=m){
			tot=n-i;
			break;
		}
	}
	cout<<tot<<endl;
}