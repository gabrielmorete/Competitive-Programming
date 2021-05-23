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
	int n, x1, y1, x2, y2;
	x1 = y1 = 100000;
	x2 = y2 = -100000;


	cin>>n;

	string s;
	fr(i, n){
		cin>>s;
		if (s == "p"){
			int x, y;
			cin>>x>>y;
			x1 = min(x1, x);
			x2 = max(x2, x);
			y1 = min(y1, y);
			y2 = max(y2, y);
		}else if (s == "c"){
			int x, y, r;
			cin>>x>>y>>r;
			x1 = min(x1, x + r);
			x1 = min(x1, x - r);
			x2 = max(x2, x + r);
			x2 = max(x2, x - r);
			y1 = min(y1, y + r);
			y1 = min(y1, y - r);
			y2 = max(y2, y + r);
			y2 = max(y2, y - r);
		}else{
			int x, y;
			cin>>x>>y;
			x1 = min(x1, x);
			x2 = max(x2, x);
			y1 = min(y1, y);
			y2 = max(y2, y);
			cin>>x>>y;
			x1 = min(x1, x);
			x2 = max(x2, x);
			y1 = min(y1, y);
			y2 = max(y2, y);
		}
	}
	cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;	
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}