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


int findPageFault(vi &v, int n, int capacity) {

	list<int> dq;
	unordered_map<int, list<int> :: iterator> mp;
	int page_fault = 0;

	for (int i = 0; i < n; i++) {

		if(mp.find(v[i]) != mp.end()) dq.erase(mp[v[i]]);

		else {

			page_fault++;
			if(dq.size() == capacity) {

				int last = dq.back();
				mp.erase(last);
				dq.pop_back();
			}
		}

		dq.push_front(v[i]);
		mp[v[i]] = dq.begin();

	}

	return page_fault;
}

int32_t main() {
    
    // file_io();
    
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T; cin>>T; while(T--) 
    {
        
    	int n;
    	cin >> n;
    	vi v(n);
    	for (auto &ele : v) cin >> ele;
    	int capacity;
    	cin >> capacity;

    	int answer = findPageFault(v, n, capacity);
    	cout << answer << endl;

    }    
    
    return 0;
}   
