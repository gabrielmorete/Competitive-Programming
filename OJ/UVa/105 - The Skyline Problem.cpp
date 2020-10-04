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
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 6e3 + 10;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int l, r, h;
	int cnt, hgt[MAXN + 1];
	vector<tuple<int, int, int>> event;

	cnt = 0;
	while (cin>>l>>h>>r){
		event.pb({l, 0, cnt}); // in
		event.pb({r, 1, cnt}); // out
		hgt[cnt] = h;
		cnt++;
	}

	sort(all(event));

	vii ans;
	set<pii> q;
	
	h = 0;
	q.insert({0, MAXN});
	hgt[MAXN] = 0;

	int x, typ, num, id, hh;
	for (auto e : event){
		tie(x, typ, num) = e;
		tie(h, id) = *q.begin();

		h = -h;
		if (typ == 0){
			if (hgt[num] > h){
				h = hgt[num];
				if (!ans.empty() and ans.back().fst == x) // os predios começam ao mesmo tempo
					ans.back().snd = hgt[num] > hgt[ans.back().snd] ? num : ans.back().snd;
				else
					ans.pb({x, num});
			}
			q.insert({-hgt[num], num});
		}
		else{
			q.erase({-hgt[num], num});
			if (id == num){ // o topo é o maior
				if (ans.back() == make_pair(x, num)) // coloquei o cara saindo
					ans.pop_back();
				tie(hh, id) = *q.begin();
				ans.pb({x, id});
			}
		}
	}

	bool ok = 0;	
	for (auto x : ans){
		if (ok)
			cout<<' ';
		cout<<x.fst<<' '<<hgt[x.snd];
		ok = 1;
	}

	gnl;
}