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

int n, a[110], b[110], t[110];

void solve(){
	cin>>n;

	frr(i, n)
		cin>>a[i]>>b[i];
	frr(i, n){
		cin>>t[i];
		t[i] += a[i] - b[i - 1];
	}

	int now = 0;
	
	frr(i, n - 1){
		now += t[i]; // tempo de viagem
		int aux = (b[i] - a[i] + 1)/2;
		now = max({now + aux, b[i]});
	}
	now += t[n];
	cout<<now<<endl;	

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();

}