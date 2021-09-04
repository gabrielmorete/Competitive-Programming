#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(), x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

#define int ll


ll n, k, v[MAXN];

ll rel[6];
// a & b
// a & c
// b & c
// a | b
// a | c
// b | c


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n>>k;

	// descobrir o primeiro

	cout<<"and 1 2"<<endl;
	cin>>rel[0];	

	cout<<"and 1 3"<<endl;
	cin>>rel[1];

	cout<<"and 2 3"<<endl;
	cin>>rel[2];

	cout<<"or 1 2"<<endl;
	cin>>rel[3];

	cout<<"or 1 3"<<endl;
	cin>>rel[4];

	cout<<"or 2 3"<<endl;
	cin>>rel[5];


	v[1] = rel[0] | rel[1]; // or dos &


	ll aux = rel[3] & rel[4];

	for (ll i = 35; i >= 0; i--){ // só o que está no A
		if (((aux & (1ll<<i)) != 0) and ((rel[5] & (1ll<<i)) == 0) ){ // está no or com ambos e não nos and
			// chapa;
			v[1] |= (1ll<<i);
		}
	}	

	v[2] = (rel[3] - rel[0])^v[1];
	v[3] = (rel[4] - rel[1])^v[1];	


	ll ande, ore;
	for (int i = 4; i <= n; i++){
		cout<<"and 1 "<<i<<endl;
		cin>>ande;

		if (ande == -1) assert(0);

		cout<<"or 1 "<<i<<endl;
		cin>>ore;
		if (ore == -1) assert(0);
		v[i] = (ore - ande)^v[1];
	}

	sort(v + 1, v + n + 1);

	cout<<"finish "<<v[k]<<endl;
}