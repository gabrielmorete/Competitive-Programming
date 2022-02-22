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

void solve(){
	int v[3];
	cin>>v[0]>>v[1]>>v[2];

	sort(v, v + 3);

	fr(i, 3){
		if (v[i] == v[(i + 1) % 3] and v[(i + 2) % 3]%2 == 0){
			cout<<"Yes"<<endl;
			return;
		}
	}

	fr(i, 3){
		int aux = v[(i + 1) % 3] + v[(i + 2) % 3];
		
		if (v[i] == aux){
			cout<<"Yes"<<endl;
			return;
		}
	}	

	cout<<"No"<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}