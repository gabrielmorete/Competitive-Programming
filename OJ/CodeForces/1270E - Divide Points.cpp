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

void solve_ev_od(){
	vi a;

	fr(i, n){
		if (abs(v[i].fst) % 2 == abs(v[i].snd) % 2)
			a.pb(i);
	}

	cout<<a.size()<<endl;
	for (auto x : a)
		cout<<x + 1<<' ';
	gnl;
	
	exit(0);
}

void solve_ev_ev(){
	vi a;

	fr(i, n){
		if (abs(v[i].fst) % 2 == 1 and abs(v[i].snd) % 2 == 1)
			a.pb(i);
	}

	cout<<a.size()<<endl;
	for (auto x : a)
		cout<<x + 1<<' ';
	gnl;
	
	exit(0);
}

int ee, oo, eo, oe;

void count(){
	ee = oo = eo = oe = 0;
	fr(i, n){
		if (abs(v[i].fst) % 2 == 0 and abs(v[i].snd) % 2 == 0)
			ee++;
		if (abs(v[i].fst) % 2 == 1 and abs(v[i].snd) % 2 == 1)
			oo++;
		if (abs(v[i].fst) % 2 == 0 and abs(v[i].snd) % 2 == 1)
			eo++;
		if (abs(v[i].fst) % 2 == 1 and abs(v[i].snd) % 2 == 0)
			oe++;
	}
}



int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	int x, y;
	fr(i, n){
		cin>>x>>y;
		v.pb({x, y});
	}

	here:

	count();

	if (ee + oo > 0 and ee + oo < n)
		solve_ev_od();
	
	if (ee > 0 and oo > 0)
		solve_ev_ev();

	if (eo + oe == n){
		fr(i, n)
			v[i].fst++;
		goto here;
	}

	if (oo == n){
		fr(i, n){
			v[i].fst++;
			v[i].snd++;
		}
	}

	bool ok = 1;
	while (ok){
		ok = 1;
		fr(i, n){
			v[i].fst /= 2; 
			v[i].snd /= 2;
			if (!(abs(v[i].fst) % 2 == 0 and abs(v[i].snd) % 2 == 0))
				ok = 0;
		}
	}

	goto here;
}