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

int n;
vi v,x,ans;

bool check(int p2){
	for(int i=p2;i<x.size();i++){
		if(x[i]!=x[i%p2])
			return false;
	}
	return true;
}

int main(){
	fastio; 
	cin>>n; 
	v.pb(0);
	int y;
	fr(i,n){
		cin>>y; 
		x.pb(y-v.back());
		v.pb(y); 
		
	}
	int p1,p2;
	p1=0,p2=1; 
	while(p2!=n){
		if(x[p1]==x[p2]){
			if(check(p2))
				ans.pb(p2);
		}
		p2++;
	}	
	ans.pb(n); 
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<' ';
	}	
	gnl;

}