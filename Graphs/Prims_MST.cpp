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

struct Edge {

	int wt =  INT_MAX, to = -1;
};


int32_t main() {
	
	// file_io();
	
	ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	// int T; cin>>T; while(T--) 
	{
		
		int n, m;
		cin>>n>>m;
		vb visited(n+1, false);

		vvi graph(n+1, vi (n+1, INT_MAX));
		int answer = 0;

		while(m--) {

			int u, v, wt;
			cin>>u>>v>>wt;
			graph[u][v] = wt;
			graph[v][u] = wt;
		}

		vector<Edge> min_edge_to(n+1);
		min_edge_to[1].wt = 0;

		for (int i = 0; i < n; i++) {

			int vtx = -1;

			for (int j = 1; j <= n; j++) {
				if(!visited[j] && (vtx == -1 || min_edge_to[j].wt < min_edge_to[vtx].wt)) vtx = j;				
			}

			answer += min_edge_to[vtx].wt;
			visited[vtx] = true;

			for (int j = 1; j <= n; j++) {

				if(graph[vtx][j] < min_edge_to[j].wt) {
					min_edge_to[j] = {graph[vtx][j], vtx};
				}
			}

		}

		cout<<answer;

	}	
	
	return 0;
}   
