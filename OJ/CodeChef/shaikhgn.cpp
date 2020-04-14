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
//cout << setprecision(9)<<fixed;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

int n;
bitset<501> adj[31][501];

int main(){
	scanf("%d", &n);

	bool a;
	fr(i, n)
		fr(j, n){
			scanf("%d", &a);
			adj[1][i][j] = a;
		}

	for (int pwr = 2; pwr <= 30; pwr++){
		fr(i, n){
			fr(j, n){
				if (adj[pwr - 1][i][j])
					adj[pwr][i] |= adj[pwr - 1][j];
			}
		}
	}

	int m, k, x, cnt;
	vi v;
	
	scanf("%d", &m);
	
	bitset<501> aux, aux2;
	while (m--){
		scanf("%d %d", &k, &x);
		if (k == 0){
			printf("1\n%d\n", x);
			continue;
		}
		aux ^= aux;
		aux2 ^= aux2;

		v.clear();

		cnt = 1;
		while (k > 0){
			if (k % 2){
				v.pb(cnt);
			}
			cnt++;
			k /= 2;
		}

		aux = adj[v[0]][x - 1];

		frr(i, v.size() - 1){
			aux2 ^= aux2;
			fr (j, n)
				if (aux[j])
					aux2 |= adj[v[i]][j]; 
			aux = aux2;
		}

		if (aux.count() == 0){
			printf("0\n-1\n");
			continue;
		}
		printf("%d\n", aux.count() );

		fr(i, n)
			if (aux[i])
				printf("%d ",i + 1);
		printf("\n");		
	}

}