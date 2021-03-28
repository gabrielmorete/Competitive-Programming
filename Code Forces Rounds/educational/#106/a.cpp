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

void solve(){
	int n, k1, k2, q1, q2, w, b;

	cin>>n>>k1>>k2;
	cin>>w>>b;

	q1 = n - k1;
	q2 = n - k2;

	int aux = min(k1, k2);
	w -= aux;
	k1 -= aux;
	k2 -= aux;

	w -= (k1 + k2)/2;
	w = max(w, 0);

	aux = min(q1, q2);
	b -= aux;
	q1 -= aux;
	q2 -= aux;

	b -= (q1 + q2)/2;
	b = max(b, 0);

	if (w + b == 0)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

}	

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}