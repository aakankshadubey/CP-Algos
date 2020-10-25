#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ll long long 
#define F first
#define S second
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define P_B push_back
#define M_P make_pair
#define endl "\n"

#define MOD 1000000007
#define pi 3.141592653589793238


// void file_io()
// {
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
// }


const int N = 1e5 + 5;


int32_t main() {
	
	// file_io();
	
	ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	// int T; cin>>T; while(T--) 
	{
		
		int n, m, q;
		cin>>n>>m>>q;

		vvi DP(n+1, vi(n+1, 1e18L));
		vvi M(n+1, vi(n+1, 1e18L));

		for (int i = 0; i < m; i++) {
			int u, v, c;
			cin>>u>>v>>c;

			DP[u][v] = min(DP[u][v], c);
			DP[v][u] = min(DP[v][u], c);
		}

		for (int i = 1; i <= n; i++) DP[i][i] = 0;

		for (int v = 1; v <= n; v++) {

			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {

					if(i == v || j == v) continue;

					DP[i][j] = min(DP[i][j], DP[i][v] + DP[v][j]);

				}
			}
		}


		for (int i = 0; i < q; i++) {

			int u, v;
			cin>>u>>v;
			if(DP[u][v] != 1e18L) cout<<DP[u][v]<<endl;
			else cout<<-1<<endl;
		}

	}	
	
	return 0;
}   
