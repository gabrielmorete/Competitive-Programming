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

int a[300], b[300];

void solve(){
	fr(i, 300)
		a[i] = b[i] = 0;

	int n;
	cin>>n;
	fr(i, n){
		int x;
		cin>>x;
		a[x + 100]++;
	}	

	fr(i, n){
		int x;
		cin>>x;
		b[x + 100]++;
	}

	bool ok = 1;

	int cr = 0;
	fr(i, 300){
		if (cr > 0){
			b[i] -= cr;
			cr = 0;
			if (b[i] < 0){
				ok = 0;
			}
		}

		int aux = min(b[i], a[i]);
		b[i] -= aux;
		a[i] -= aux;
		cr = a[i];
	}


	if (ok)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}