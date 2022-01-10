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

ll p, q, n, a[MAXN], b[MAXN];

void solve(int ans){
	int mx = 1, mn = 1; 

	frr(i, n){
		if (a[i] * b[mx] > a[mx] * b[i])
			mx = i;
		if (a[i] * b[mn] < a[mn] * b[i])
			mn = i;
	}

	if (a[mn] * b[mx] * q > a[mx] * b[mn] * p){
		cout<<ans<<endl;
		exit(0);
	}

	b[mx]++;
	solve(ans + 1);
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	cin>>s>>n;

	reverse(all(s));
	s.pop_back();
	s.pop_back();
	reverse(all(s));
	
	p = stoi(s);
	q = 100;

	frr(i, n){
		cin>>a[i];
		b[i] = 1;
	}

	solve(0);
}