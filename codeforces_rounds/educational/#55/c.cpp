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
const int LMAXN = 20;

int freq[112345];
vi v[112345];

int main(){
	fastio;
	int n,m,s,r;
	bool ok=1;
	cin>>n>>m;

	fr(i,n){
		cin>>s>>r;

		if(r>=0)
			ok=0;

		v[s].pb(r);
	}

	if(ok){
		cout<<0<<endl;
		return 0;
	}

	frr(i,m){
		sort(all(v[i]));
	}
	
	frr(i,m){
		
		int cnt=1;
		int fim=v[i].size()-1;
		v[i].pb(0);
		
		for(int j=fim ; j>=0 ; j-- , cnt++){

				v[i][j]+=v[i][j+1];
				if(v[i][j]>0)
					freq[cnt]+=v[i][j];
			
		}	
	}
	
	int best=0;

	fr(i,n+50){
		if(freq[i]>best)
			best=freq[i];
	}

	cout<<best<<endl;

}


	
