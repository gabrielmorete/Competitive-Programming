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

int n, a[MAXN], lst[MAXN], id_lst[MAXN], dpt;

string ans[MAXN];

void solve(){
	cin>>n;
	frr(i, n)
		cin>>a[i];

	ans[0] = "";

	dpt = 0; // produndidade
	lst[1] = id_lst[0] = 0; // ultimo numero dessa profundidade 
	for (int i = 1; i <= n; i++){
		if (a[i] == 1){
			dpt++;

			if (dpt > 1)
				ans[i] = ans[id_lst[dpt - 1]] + "." + to_string(a[i]);
			else
				ans[i] = to_string(a[i]);

			lst[dpt] = 1;
			id_lst[dpt] = i;
		}
		else{
			while (lst[dpt] + 1 != a[i]){
				lst[dpt] = id_lst[dpt] = 0;
				dpt--;
			}
			
			if (dpt > 1)
				ans[i] = ans[id_lst[dpt - 1]] + "." + to_string(a[i]);
			else
				ans[i] = to_string(a[i]);			
		
			lst[dpt]++;
			id_lst[dpt] = i;
		}
	}
	
	frr(i, n)
		cout<<ans[i]<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}