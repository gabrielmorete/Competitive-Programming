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

ll a[10], b[10];

void pick(int x, int y){
	ll aux = min(a[x], b[y]);
	a[x] -= aux;
	b[y] -= aux;
	b[y - x] += aux;
}

void solve(){
	ll sum = 0;

	for (ll i = 1; i <= 5; i++){
		cin>>a[i];
		sum += i * a[i];
	}

	for (ll i = 1; i <= 5; i++){
		cin>>b[i];
		sum -= i * b[i];
	}

	pick(5, 5);
	pick(4, 4);
	pick(4, 5);
	pick(3, 3);
	pick(3, 5);
	pick(3, 4);
	pick(2, 5);
	pick(2, 4);
	pick(2, 3);
	pick(2, 2);
	pick(1, 5);
	pick(1, 4);
	pick(1, 3);
	pick(1, 2);
	pick(1, 1);

	frr(i, 5)
		if (a[i] > 0){
			cout<<"No"<<endl;
			return;
		}

	cout<<"Yes"<<endl;	
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll T;
	cin>>T;
	while (T--)
		solve();

}