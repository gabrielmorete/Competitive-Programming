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
const int MAXN = 1e5 + 10;

map<int, pii> frq;

void solve(){
	frq.clear();

	int n, l, r;

	cin>>n>>l>>r;

	int x;
	fr(i, n){
		cin>>x;
		if (i < l)
			frq[x].fst++;
		else
			frq[x].snd++;
	}

	int cntl, cntr, ans, revl, revr;
	ans = cntl = cntr = revl = revr = 0;

	int a, b;
	for (auto &it : frq){
		tie(a, b) = it.snd;
		int mn = min(a, b);
		a -= mn;
		b -= mn; // casei os pares
		int mx = max(a, b);
		if (mx % 2 == 1){
			if (mx == a){
				cntl++;
				revl += mx - 1;
			}
			else{
				cntr++;
				revr += mx - 1;
			}
		}
		else{
			if (mx == a)
				revl += mx;
			else
				revr += mx;
		}
	}

	int aux = min(cntl, cntr); // pode ser impar
	ans += aux;
	cntl -= aux;
	cntr -= aux;

	if (cntl > 0){
		aux = min(cntl, revr); // é par
		ans += aux;
		cntl -= aux;
		revr -= aux;
	}
	else{
		aux = min(cntr, revl); // é par
		ans += aux;
		cntr -= aux;
		revr -= aux;
	}	

	ans += cntl;
	ans += cntr;
	ans += revr/2;
	ans += revl/2;

	cout<<ans<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}