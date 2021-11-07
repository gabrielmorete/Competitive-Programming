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

int n;
vii v;

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	int x, y;
	fr(i, n){
		cin>>x>>y;
		v.pb({x, y});
	}

	set<pii> ans;

	fr(i, n)
		fr(j, n){
			if (i != j){
				int dx = abs(v[i].fst - v[j].fst);
				int dy = abs(v[i].snd - v[j].snd);
				int mdc = __gcd(dx, dy);
				dx /= mdc;
				dy /= mdc;

				if (v[i].fst > v[j].fst) dx = -dx;
				if (v[i].snd > v[j].snd) dy = -dy;

				ans.insert({dx, dy});
			}
		}

	cout<<ans.size()<<endl;
}