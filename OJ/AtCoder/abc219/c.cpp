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

string alph;
char to[450];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>alph;

	for (char a = 'a'; a <= 'z'; a++)
		to[alph[a - 'a']] = a;

	vector<string> s;

	int n;

	cin>>n;

	s.resize(n);

	fr(i, n){
		cin>>s[i];
		for (auto &x : s[i])
			x = to[x];
	}

	sort(all(s));

	fr(i, n){
		for (auto &x : s[i])
			x = alph[x - 'a'];
		cout<<s[i]<<endl;
	}



}