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
	int ans = s.size();

	stack<char> stk;
	for (auto x : s){
		if (stk.empty() or x == 'A')
			stk.push(x);
		else{
			if (stk.top() == 'A'){ // AB
				stk.pop();
				ans -= 2;
			}
			else
				stk.push(x);	
		}
	}
	// METEI OS PARES AB


	if (!stk.empty()){
		char lst = stk.top();
		stk.pop();
		while (!stk.empty()){
			if (stk.top() == lst and lst == 'B'){
				ans -= 2;
				lst = 'C';
			}
			else
				lst = stk.top();
			stk.pop();
		}
	}

	cout<<ans<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}