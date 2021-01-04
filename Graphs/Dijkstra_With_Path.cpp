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

void dijkstra(vvi &graph, vi &distance, int n, vi &parent) {

	vb visited(n, false);
	for (int i = 0; i < n; i++) {

		int vtx = -1;
		for (int j = 0; j < n; j++) {

			if(!visited[j] && (vtx == -1 || distance[vtx]  > distance[j])) vtx = j;
		}

		if(distance[vtx] == INT_MAX) {cout << "a"; return;}
		visited[vtx] = true;
		for (int ngb = 0; ngb < n; ngb++) {

			if(graph[vtx][ngb] != 0) {
				
				if(distance[ngb] >  distance[vtx] + graph[vtx][ngb]) {

					distance[ngb] = distance[vtx] + graph[vtx][ngb];
					parent[ngb] = vtx;
				}
			}
		
		}

	}

}


int32_t main() {
    
    // file_io();
    
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T; cin>>T; while(T--) 
    {
        
    	int n;
    	cin >> n;

    	vvi graph(n, vi(n, 0));
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < n; j++) cin >> graph[i][j];
    	}

    	int src, dest;
    	cin >> src >> dest;
    	vi distance(n, INT_MAX), parent(n, -1);
    	distance[src] = 0;

    	dijkstra(graph, distance, n, parent);
    	cout << distance[dest] << endl;
    	// for (auto ele : distance) cout << ele << " ";
    	vi answer;
    	int beg = dest;
    	while(beg != src) {

    		answer.P_B(beg);
    		beg = parent[beg];
    	}
    	answer.P_B(src);
    	reverse(answer.begin(), answer.end());
    	for (auto ele : answer) cout << ele << " " ;
    	cout << endl; 

    }    
    
    return 0;
}   
