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

vii ob;
set<pii> clue;


int main(){
	fastio;
	int n;

	cin>>n;
	int x,y;

	fr(i,n){
		cin>>x>>y;
		ob.pb({x,y});
	}

	fr(i,n){
		cin>>x>>y;
		clue.insert({x,y});
	}

	pii tr;
	int i;

	for(auto x:clue){
		tr=mp(ob[0].fst+x.fst , ob[0].snd+x.snd);
		bool ok=1;
		for(i=1;i<n;i++){
			auto aux=clue.find(mp(tr.fst-ob[i].fst ,tr.snd-ob[i].snd ));
				if(aux==clue.end())
					ok=0;
		}

		if(ok){
			cout<<tr.fst<<' '<<tr.snd<<endl;
			return 0;
		}


	}


}