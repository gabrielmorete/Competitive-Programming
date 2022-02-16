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
const int MAXN = 4e5 + 10;

int n, k, freq[MAXN], a[MAXN];

bool test(int x, int y){
	int aux = freq[y] - freq[x - 1];
	int aux2 = n - aux;

	return aux - aux2 >= k;
}

void solve(){
	cin>>n>>k;

	fr(i, n + 10)
		freq[i] = 0;

	frr(i, n){
		cin>>a[i];
		freq[a[i]]++;
	}	

	frr(i, n)
		freq[i] += freq[i - 1];

	int x = 1;
	int y = n;
	
	for (int i = 1; i <= n; i++){
		int ini = i, fim = n;

		while (ini <= fim){
			int meio = (ini + fim)/2;

			// cout<<i<<' '<<meio<<endl;

			if (test(i, meio)){
				if (meio - i < y - x){
					x = i;
					y = meio;
				}
				fim = meio - 1;
			}
			else
				ini = meio + 1;
		}
	}	

	if (k == 1){
		cout<<x<<' '<<y<<endl;
		cout<<1<<' '<<n<<endl;
		return;
	}

	vii ans;

	// achei, hora do guloso
	int p = 1;
	while (p <= n){
		int dlt = 0;
		int q = p;

		while (q <= n and dlt <= 0){
			if (x <= a[q] and a[q] <= y)
				dlt++;
			else
				dlt--;
			q++;
		}

		ans.pb({p, q - 1});
		k--;

		p = q;

		if (k == 1){
			ans.pb({q, n});
			p = n + 1;
		}
	}

	cout<<x<<' '<<y<<endl;
	for (auto u : ans)
		cout<<u.fst<<' '<<u.snd<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}	