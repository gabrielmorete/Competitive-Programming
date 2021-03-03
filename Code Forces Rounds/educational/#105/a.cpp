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
	string s;
	cin>>s;

	if (s.size() < 2){
		cout<<"NO"<<endl;
		return;
	}


	int v[3];
	v[0] = v[1] = v[2] = 0;

	for (auto x : s){
		if (x == 'A')
			v[0]++;
		if (x == 'B')
			v[1]++;
		if (x == 'C')
			v[2]++;
	}

	bool ok = 0;
	if (v[0] + v[1] == v[2])
		ok = 1;
	if (v[0] + v[2] == v[1])
		ok = 1;
	if (v[1] + v[2] == v[0])
		ok = 1;

	if (!ok){
		cout<<"NO"<<endl;
		return;
	}

	int n = s.size();
	char aux = s[0];
	int cnt = 0;

	fr(i, n)
		if (s[i] == aux){
			s[i] = '(';
			cnt++;
		}

	// cout<<s<<endl;	

	if (s[n - 1] == '('){
		cout<<"NO"<<endl;
		return;
	}	

	aux = s[n - 1];

	fr(i, n)
		if (s[i] == aux)
			s[i] = ')';

	fr(i, n){
		if (s[i] != '(' and s[i] != ')'){
			if (cnt >= n/2)
				s[i] = ')';
			else
				s[i] = '(';
		}
	}	

	// cout<<s<<endl;

	cnt = 0;
	for (auto x : s){
		if (x == '(')
			cnt++;
		else{
			cnt--;
			if (cnt < 0){
				cout<<"NO"<<endl;
				return;
			}
		}
	}

	if (cnt != 0)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}