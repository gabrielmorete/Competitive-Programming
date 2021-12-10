#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

#define endl '\n'
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
const int MAXN = 1e3 + 10;

ll n, m, bx, by, mrk[MAXN];
vector<pair<ll, ll>> adj[MAXN];

ll memo[MAXN][MAXN][2];

void pd(){
	fr(i, n + 10)
		fr(j, n + 10)
			fr(k, 2)
				memo[i][j][k] = llINF;


	memo[bx][0][1] = 0; // 1 - só passou por marcado, 0 -passou por desmarcado

	frr(i, n)
		frr(v, n)
			for (auto x : adj[v]){
				if (mrk[x.fst]){
					memo[x.fst][i][1] = min(memo[x.fst][i][1], memo[v][i - 1][1] + x.snd); // marcado
					memo[x.fst][i][0] = min(memo[x.fst][i][0], memo[v][i - 1][0] + x.snd); // não marcado
				}
				else{
					memo[x.fst][i][0] = min(memo[x.fst][i][0], memo[v][i - 1][1] + x.snd); // marcado
					memo[x.fst][i][0] = min(memo[x.fst][i][0], memo[v][i - 1][0] + x.snd); // não marcado
				}
			}
}

vector<pair<ll, ll>> in, out;

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m>>bx>>by;

	fr(i, m){
		ll a, b, c;
		cin>>a>>b>>c;

		adj[a].pb({b, c});
		adj[b].pb({a, c});
	}

	int q;
	cin>>q;
	while (q--){
		int x;
		cin>>x;
		mrk[x] = 1;
	}

	pd();

	frr(i, n){
		if (memo[by][i][0] < llINF)
			out.pb({memo[by][i][0], i}); // passou por não marcado
		if (memo[by][i][1] < llINF)
			in.pb({memo[by][i][1], i}); // só marcado
	}

	ll ans = -llINF;

	for (auto x : in){
		ll lb = -INF, ub = llINF;

		// quero que a reta x seja menor

		for (auto y : out){

			if (x.snd == y.snd){ // paralelas
				if (y.fst <= x.fst)
					ub = -1;

				continue;
			}

			// as retas se cruzam

			if (y.fst == x.fst){ // se cruzam no zero
				if (x.snd < y.snd)
					lb = max(lb, 1ll);
				else
					ub = -1;
			}	
			else if (y.fst < x.fst){ // x é maior no zero
				if (x.snd <= y.snd){ // se cruzam no positivo
					
					if (lb <= (abs<ll>(y.fst - x.fst) + abs<ll>(x.snd - y.snd) - 1)/abs<ll>(x.snd - y.snd)){
						lb = (abs<ll>(y.fst - x.fst) + abs<ll>(x.snd - y.snd) - 1)/abs<ll>(x.snd - y.snd);
						if (abs<ll>(y.fst - x.fst) % abs<ll>(x.snd - y.snd) == 0) // se cruzam no ponto inteiro
							lb++;
					}
				}
				else
					ub = -1;
			}
			else{ // x é menor no zero
				if (x.snd >= y.snd){ // cruza no positivo
					if (ub >= (y.fst - x.fst) / (x.snd - y.snd)){
						ub = (y.fst - x.fst) / (x.snd - y.snd);
						if ((y.fst - x.fst) % (x.snd - y.snd) == 0) // cruza em ponto inteiro
							ub--;
					}
				}
			}
		}

		if (ub > 0 and lb <= ub)
			ans = max(ans, ub);
	}

	if (ans <= 0)
		cout<<"Impossible"<<endl;
	else if (ans >= llINF/2)
		cout<<"Infinity"<<endl;
	else
		cout<<ans<<endl;
}