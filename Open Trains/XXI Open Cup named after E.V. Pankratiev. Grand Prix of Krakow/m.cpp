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
const int MAXN = 2e5 + 10;

ll n, a[MAXN], b[MAXN], p, q;

ll getitv(){
	ll ini = 1, fim = n, bst = -1;

	while (ini <= fim){
		ll mid = (ini + fim)/2;
		bool ok = 0;
		ll sum = 0, ptr1 = 0, ptr2 = -1;

		while (ptr2 < mid - 1){
			ptr2++;
			sum += a[ptr2];
		}
		while (ptr2 < n){
			if (sum * p >= q * mid * a[ptr2]) 
				ok = 1;
			sum += a[++ptr2];
			sum -= a[ptr1++];
		}

		if (ok){
			bst = mid;
			ini = mid + 1;
		}
		else
			fim = mid - 1;
	}

	return bst; 	
}

ll ans[MAXN];

void mark(ll lft, ll rgt, ll sum, ll opt){
	ll ini = 0, fim = lft - 1;

	while (ini <= fim){
		ll mid = (ini + fim)/2;

		sum += a[mid];

		if (sum * p >= a[rgt] * q * opt){
			ans[mid]++;
			ans[rgt + 1]--;
			
			fim = mid - 1;
		}
		else
			ini = mid + 1;	

		sum -= a[mid];
	}
}


void solve(){
	cin>>n;
	fr(i, n)
		cin>>a[i];
	cin>>p>>q;
	
	fr(i, n)
		b[i] = a[i];

	sort(a, a + n);

	ll opt = getitv();

	if (opt == 1){
		cout<<"0"<<endl<<endl;
		return;
	}

	fr(i, n) ans[i] = 0;

	ll sum = 0, ptr1 = 0, ptr2 = -1;
	while (ptr2 < opt - 2){
		ptr2++;
		sum += a[ptr2];
	}
	while (ptr2 < n){
		mark(ptr1, ptr2, sum, opt);
		sum += a[++ptr2];
		sum -= a[ptr1++];
	}

	set<int> in;
	int s = 0;
	fr(i, n){
		s += ans[i];
		if (s > 0) in.insert(a[i]);
	}
	
	set<int> out;
	fr(i, n)
		if (!in.count(b[i]))
			out.insert(i + 1);

	cout<<out.size()<<endl;
	while (!out.empty()){
		cout<<*out.begin();
		out.erase(*out.begin());
		if (!out.empty())
			cout<<" ";
	}
	gnl;	
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}