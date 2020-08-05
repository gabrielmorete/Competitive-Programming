#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define endl '\n'
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  

const int MAXN = 3e5 + 10;

int seg[4*MAXN], delta[4*MAXN];

void unlazy(int node, int l, int r){
	if(l!=r){
		delta[node<<1] += delta[node];
		delta[node<<1|1] += delta[node];
	}
	seg[node] += delta[node];
	delta[node] = 0;
}

void update(int node,int l,int r,int ul,int ur,int val){
	unlazy(node,l,r);
	if(r<ul || ur<l)
		return; 
	if(ul<=l && r<=ur){
		delta[node] += val; 
		unlazy(node, l, r);
		return;
	}
	int meio=(l+r)/2;
	update(node<<1,l, meio, ul, ur, val);
	update(node<<1|1, meio + 1, r, ul, ur, val);
	seg[node] = min(seg[node<<1], seg[node<<1|1]);
}

int n, pos[MAXN], q[MAXN];

bool dec(int x){
	update(1, 0, n, 0, pos[x], -1);
	
	if (seg[1] >= 0)
		return true;
	
	update(1, 0, n, 0, pos[x], 1);
	return false;
}

int main(){
	fastio;

	cin>>n;

	int x;
	fr(i, n){
		cin>>x;
		pos[x] = i + 1;
	}

	fr(i, n)
		cin>>q[i];

	x = n;
	for (int i = 0; i < n; i++){
		while (dec(x)) // resposta só diminui
			x--;
		cout<<x<<' ';
		update(1, 0, n, 0, q[i], 1);
	}
	gnl;	
}