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

int n, used[MAXN];
string s;

stack<int> stk[300];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>s;

	fr(i, n)
		stk[s[i] - 'a'].push(i);

	int rgt = n;
	for (int i = 0; i < n; i++){
		if (used[i]) // já fui trocado por alguem 
			 break;

		for (int j = 0; j < s[i] - 'a'; j++){
			while (!stk[j].empty() and stk[j].top() > rgt)
				stk[j].pop();
		
			if (!stk[j].empty() and stk[j].top() > i){
				int x = stk[j].top();
				stk[j].pop();
				swap(s[i], s[x]);
				used[x] = 1;
				rgt = x;	
				break;
			}
		}
	}	

	cout<<s<<endl;
}