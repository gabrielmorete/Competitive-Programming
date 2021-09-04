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
const int MAXN = 2e5 + 10;

ll n, a[MAXN];

ll se, so, p, ans;
void calc(){
	for (int i = 0; i < n - (n & 1); i += 2){
		if (se == 0){
			while (p < n and a[p] != 0){
				so++;
				p++;
			}
			p++;
		}
		else
			se--;

		ans += so;
		
		if (so == 0){
			while (p < n and a[p] != 1){
				se++;
				p++;
			}
			p++;
		}	
		else
			so--;

		ans += se;
	}
}



void solve(){
	cin>>n;

	ll od = 0;
	fr(i, n){
		cin>>a[i];
		a[i] %= 2;
		od += a[i];
	}

	ll ev = n - od;

	if (n&1 and abs(ev - od) != 1){ // impar
		cout<<-1<<endl;
		return;
	}
	if ((n&1) == 0 and ev != od){
		cout<<-1<<endl;
		return;
	}

	if (ev > od){
		fr(i, n)
			a[i] = 1 - a[i];
		swap(ev, od);
	}
	

	// se tem mais é impar;
	se = so = p = ans = 0;
	if (od > ev){
		while (p < n and a[p] != 1){
			se++; // cara par
			p++;
		}
		p++;
		// achei
		ans += se; // caras pares no caminho
	}

	calc();

	ll bst = ans;



	if (ev == od){
		ans = 0;

		fr(i, n)
			a[i] = 1 - a[i];

		p = se = so = 0;
		calc();	
		bst = min(bst, ans);
	}


	cout<<bst<<endl;

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}