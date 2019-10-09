    #include "bits/stdc++.h"
    using namespace std;
     
    #define pb push_back
    #define mp make_pair
    #define fst first
    #define snd second
     
    #define fr(i,n)     for(int i=0;i<n;i++)
    #define frr(i,n)    for(int i=1;i<=n;i++)
     
    #define ms(x,i) memset(x,i,sizeof(x))
    #define dbg(x)  cout << #x << " = " << x << endl
    #define all(x)  x.begin(),x.end()
     
    #define gnl cout << endl
    #define chapa cout << "oi meu chapa" << endl
    #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
    //cout << setprecision(9)<<fixed;
     
    typedef long long int ll;
    typedef pair<int,int> pii;
    typedef vector<int> vi;
    typedef vector<ll> vll;
    typedef vector<pii> vii;
    typedef pair<ll,ll> pll;
     
    const int INF = 0x3f3f3f3f;
    const ll llINF = (long long)(1e18) + 100;   
    const int MAXN = 100100;
    const int MAXM = 1001000;
    const ll mod=1e9+7;
    const int LMAXN = 25;
     
    ll n, m, k;
    ll p[5123];
    ll memo[5123][5123];
     
    ll pd(){
    	for(int i = n + 1; i < 5123; i++)
    		for(int j = 0; j < 5123; j++)
    			memo[i][j] = -llINF;
    	for(int i = 0; i < 5123; i++)
    		memo[i][0] = 0;

    	for(int pos = n; pos >= 1; pos--)
    		for(int kk = k; kk > 0; kk--){
    			memo[pos][kk] = memo[pos + 1][kk];
    			if(pos + m <= n + 1)
    				memo[pos][kk] = max(memo[pos][kk], memo[pos + m][kk - 1] + p[pos + m - 1] - p[pos - 1]);
    		}		
    	return memo[1][k];	
    }
     
     
    int main(){
    	fastio;
    	cin>>n>>m>>k;
     
    	p[0] = 0;
    	frr(i,n)
    		cin>>p[i];
    	frr(i,n)
    		p[i] += p[i-1];	
     
    	cout<<pd()<<endl;	
    }

    // Memoized Recursion
    //ll pd(int pos, int kk){
    // 	if (kk == 0)
    // 		return 0;
    // 	if (pos > n)
    // 		return -llINF;
    // 	ll &pdm = memo[pos][kk];
    // 	if (pdm != -1)
    // 		return pdm;
    // 	pdm = pd( pos+1, kk);
    // 	if (pos + m <= n+1)
    // 	pdm = max( pdm, pd( pos + m, kk - 1) + p[ pos + m - 1] - p[pos - 1]);
    // 	return pdm;
    // }