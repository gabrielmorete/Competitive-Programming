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

int n, a[MAXN];

void solve(){
	cin>>n;
	frr(i, n)
		cin>>a[i];

	ll ans = 0;
	
	fr(k, 3){
		int p = 2, q = 2; // na esquerda e na direita

		for (int i = 2; i < n; i++){

			q = max({q, i + 1});

			while (a[i] > 1){

				while (p < i and (a[p]%2 == 0))
					p++;
				while (q < n and (a[q]%2 == 0))
					q++;

				if (p == i and q == n){ // já foi
					int r = a[i]/2;
					ans += r;
					a[i] -= 2*r;
				}
				else{
					if (p == i)
						a[1]++;
					else
						a[p]++;

					a[q]++;
					a[i] -= 2;
					ans++;
				}
			}
		}
	}

	for (int i = 2; i < n; i++)
		if (a[i] > 0){
			cout<<-1<<endl;
			return;
		}

	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}