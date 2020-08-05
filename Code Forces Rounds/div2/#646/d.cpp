#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e3 + 10;
const ll mod = 1e9+7;

int n, k;
int ans[MAXN];

void print(){
	cout<<"! ";
	frr(i, k)
		cout<<ans[i]<<' ';
	gnl;
	
	string s;
	cin>>s;
	assert(s == "Correct");
}


void solve(){
	vi sets[MAXN];

	cin>>n>>k;

	int x, y;
	fr(i, k){
		cin>>x;
		fr(j, x){
			cin>>y;
			sets[i].pb(y);
		}
	}

	int max;

	// Query maximo do vetor
	cout<<"? "<<n;
	frr(i, n)
		cout<<' '<<i;
	gnl;
	cin >> max;

	frr(i, k)
		ans[i] = max;

	// Query posição do máximo
	int ini, fim, meio, aux;
	ini = 1;
	fim = n;

	while (ini < fim){
		meio = (ini + fim)/2;
		cout<<"? "<<meio - ini + 1;
		fr(i, meio - ini + 1)
			cout<<' '<<ini + i;
		gnl;

		cin>>aux;

		if (aux != max)
			ini = meio + 1;
		else
			fim = meio;
	}

	// Decidir se algum conjunto contém o máximo

	int cnj = -1;	

	fr(i, k)
		for (auto x : sets[i])
			if (x == ini)
				cnj = i;
	
	if (cnj == -1){
		print();	
		return;		
	}

	// Last query, value of cnj

	int v[MAXN];
	fill(v, v + MAXN, 0);

	for (auto x : sets[cnj])
		v[x] = 1;
	
	cout<<"? "<<n - (int) sets[cnj].size();
	frr(i, n)
		if (!v[i])			
			cout<<' '<<i;
	gnl;

	cin>>ans[cnj + 1];
	print();
}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}