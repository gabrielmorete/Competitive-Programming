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

typedef tuple<int, int, int> tup;

string s;
int m;

map<tup, ll> dp_now, dp_lst;

int get_nxt(int id, vi frq){
	fr(i, s.size()){
		if (s[i] == 'K') frq[0]--;
		if (s[i] == 'E') frq[1]--;
		if (s[i] == 'Y') frq[2]--;

		if (frq[id] < 0){
			frq[id] = 0;
			int sum = 0;
			fr(i, 3) 
				sum += abs(min(0, frq[i]));
			return sum;
		}
	}	

	return -1;		
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>s>>m;

	int n = s.size();

	dp_lst[{0, 0, 0}] = 1;

	int e, x, y, k;
	fr(pos, n){
		dp_now.clear();
		for (auto w : dp_lst){
			tie(x, e, y) = w.fst;
			k = pos - e - y;

			vi f = {k, e, y};

			int p = get_nxt(0, f);

			if (p != -1){
				int ax = x + p;
				dp_now[make_tuple(ax, e, y)] += w.snd;
			}
			p = get_nxt(1, f);

			if (p != -1){
				int ax = x + p;
				dp_now[make_tuple(ax, e + 1, y)] += w.snd;
			}

			p = get_nxt(2, f);
			if (p != -1){
				int ax = x + p;
				dp_now[make_tuple(ax, e, y + 1)] += w.snd;
			}
		}

		dp_lst = dp_now;
	}

	ll ans = 0;
	for (auto w : dp_now){
		if (get<0>(w.fst) <= m)
			ans += w.snd;
	}

	cout<<ans<<endl;
}