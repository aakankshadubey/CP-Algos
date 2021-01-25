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

int backtrack(vector<vector<pii>> &graph, int node, vb &visited, int cnt, int n, int parent = -1) {

	if(cnt == n) return graph[node][0].S;

	int answer = INT_MAX;
	for (auto ngb : graph[node]) {

		if(visited[ngb.F] || ngb.F == parent) continue;
		visited[ngb.F] = true;
		answer = min(answer, ngb.S + backtrack(graph, ngb.F, visited, cnt+1, n, node));
		visited[ngb.F] = false;

	}

	return answer;

}


int32_t main() {
    
    // file_io();
    
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // int T; cin>>T; while(T--) 
    {
        
    	int n, e;
    	cin >> n >> e; 
    	vector<vector<pii>> graph(n+1);
    	
    	while(e--) {

    		int u, v, wt;
    		cin >> u >> v >> wt;
    		graph[u].P_B({v, wt});
    		graph[v].P_B({u, wt});

    	}

    	vb visited(n+1, false);
    	visited[1] = true;
    	cout << backtrack(graph, 1, visited, 1, n) << endl;


    }    
    
    return 0;
}   
