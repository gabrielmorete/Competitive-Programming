#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

// #define endl '\n'
#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(), x.end()

typedef long long int ll;


#define int ll

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

int n;
vi v[3], R, G, B;

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	int x;
	char c;
	fr(i, 2*n){
		cin>>x>>c;
		if (c == 'R') R.pb(x);
		else if (c == 'G') G.pb(x);
		else B.pb(x);
	}

	if ((R.size() % 2 == 0) and (G.size() % 2 == 0) and (B.size() %2 == 0)){
		cout<<0<<endl;
		return 0;
	}

	if (R.size()%2 == 0){
		v[0] = B;
		v[1] = G;
		v[2] = R;
	}
	else if (G.size() %2 == 0){
		v[0] = R;
		v[1] = B;
		v[2] = G;
	}
	else{
		v[0] = R;
		v[1] = G;
		v[2] = B;
	}

	fr(i, 3)
		sort(all(v[i]));

	ll ans = llINF;

	// tentativa 1
	vii a;
	fr(i, 2)
		for(auto x : v[i])
			a.pb({x, i});
		
	sort(all(a));
	fr(i, a.size() - 1)
		if (a[i].snd != a[i + 1].snd){
			ans = min(ans, abs(a[i].fst - a[i + 1].fst));
		}

	// tentativa 2
	ll df[2][2], men[2];
	fr(j, 2){
		vi dfa;
		ll menor = llINF;

		fr(i, v[2].size()){
			int p = (int)(lower_bound(all(v[j]), v[2][i]) - v[j].begin());
			ll aux = llINF;

			if (p < v[j].size()){
				if (menor > abs(v[2][i] - v[j][p]))
					men[j] = i;
				aux = abs(v[2][i] - v[j][p]);
				menor = min(menor, aux);
			}
			if (p > 0){
				if (menor > abs(v[2][i] - v[j][p - 1]))
					men[j] = i;

				aux = min(aux, abs(v[2][i] - v[j][p - 1]));
				menor = min(menor, aux);
			}
			dfa.pb(aux);
		}	

		fr(k, 2)
			df[j][k] = llINF;

		sort(all(dfa));

		fr(k, min<int>({2, dfa.size()}))
			df[j][k] = dfa[k];
	}

	if (men[0] != men[1])// menores diferentes
		ans = min({ans, df[0][0] + df[1][0]});
	else
		ans = min({ans, df[0][0] + df[1][1], df[0][1] + df[1][0]});

	cout<<ans<<endl;
}