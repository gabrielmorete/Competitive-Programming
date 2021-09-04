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
priority_queue<int, vi, greater<int>> pq;
deque<int> dq;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	int typ, x;
	while (n--){
		cin>>typ;
		if (typ == 1){
			cin>>x;
			dq.pb(x);
		}
		if (typ == 2){
			if (!pq.empty()){
				x = pq.top();
				pq.pop();
			}
			else{
				x = dq[0];
				dq.pop_front();
			}
			cout<<x<<endl;
		}
		if (typ == 3){
			while (!dq.empty()){
				pq.push(dq.back());
				dq.pop_back();
			}
		}
	}	
}