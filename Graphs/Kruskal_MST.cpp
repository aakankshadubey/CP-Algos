#include<bits/stdc++.h>
using namespace std;
#define int long long
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
	int u, v, wt;

	bool operator < (Edge a) {
		return wt < a.wt;
	}
};


int32_t main() {
	
	// file_io();
	
	ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	// int T; cin>>T; while(T--) 
	{
		
		int n, m;
		cin>>n>>m;

		vector<Edge> graph;
		while(m--) {
			int u, v, wt;
			cin>>u>>v>>wt;
			graph.P_B({u, v, wt});
		}

		int answer = 0;

		sort(graph.begin(), graph.end());

		vi tree_id(n+1);
		for (int i = 1; i <= n; i++) tree_id[i] = i;

		for (int i = 0; i < n-1; i++) {

			int x = graph[i].u, y = graph[i].v;

			if(tree_id[x] != tree_id[y]) {

				answer += graph[i].wt;
				int new_id = tree_id[y], old_id = tree_id[x];

				for (int j = 1; j <= n; j++) {
					if(tree_id[j] == old_id) {
						tree_id[j] = new_id;
					}
				}

			}
		}

		cout<<answer;

	}	
	
	return 0;
}   
