#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(), x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pair<ll, ll>> vll;


const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(6e18) + 100;   
const int MAXN = 1e6 + 10;

int n, m, u[MAXN];
vll blue, red;

ll getarea(int i, int j){
	if ((red[j].fst - blue[i].fst) < 0 and (red[j].snd - blue[i].snd) < 0)
		return -llINF;
	return (red[j].fst - blue[i].fst) * (red[j].snd - blue[i].snd);
}

void solve(int lb, int rb, int lr, int rr){ // [l, r] 
	if (lb > rb)
		return;

	int mid = (lb + rb)/2;

	ll bst = getarea(mid, lr);
	ll id = lr;
	
	for (int i = lr; i <= rr; i++){
		if (getarea(mid, i) >= bst){
			bst = getarea(mid, i);
			id = i;
		}
	}
	
	u[mid] = id;

	solve(lb, mid - 1, lr, u[mid]);
	solve(mid + 1, rb, u[mid], rr);
}


vll vb, vr;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	m = n;

	ll x;
	for (int i = 0; i < n; i++){
		cin>>x;
		vb.pb({-x, i});
		vr.pb({x, i});
	}

	sort(all(vb));
	sort(all(vr));

	ll hgt = 1e9 + 10;
	for (int i = 0; i < n; i++){ // quero menor x e y
		if (vb[i].snd < hgt){
			hgt = vb[i].snd;
			blue.pb(vb[i]);
		}
	}

	hgt = -1;
	for (int i = m - 1; i >= 0; i--){ // quero maior x e y
		if (vr[i].snd > hgt){
			hgt = vr[i].snd;
			red.pb(vr[i]);
		}
	}

	reverse(all(red));

	n = blue.size();
	m = red.size();

	solve(0, n - 1, 0, m - 1);

	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, getarea(i, u[i]));

	cout<<ans<<endl;
}