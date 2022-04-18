#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define Max 20
#define INF 1e9

using namespace std;

int n, m, w;
int init, des;
int res;
int deg[Max];
bool visit[Max];
vector<int> Odddegs;
int dist[Max][Max];

int WeightToReduceOddDeg(int idx, int w) {
    if(idx == Odddegs.size())     return w;
    if(visit[idx])          return WeightToReduceOddDeg(idx + 1, w);
    int ans = INF;
    
    for(int cur = idx + 1; cur < Odddegs.size(); cur++) {
        if(!visit[cur]) {
            visit[cur] = true;
            ans = min(ans, WeightToReduceOddDeg(idx + 1, w + dist[Odddegs[idx]][Odddegs[cur]]));
            visit[cur] = false;
        }
    }
    return ans;
}

int main() {
    
    cin >> n;
    cin >> m;
    
    for(int i=0; i<n ;i++) {
        for(int j=0; j<n; j++) {
            dist[i][j] = INF;
        }
    }
    res = 0;

    for(int i=0; i<m ;i++) {
        cin >> init  >> des >> w;
        init--, des--;
        dist[init][des] = dist[des][init] = min(dist[init][des] , w);
        deg[init]++;
        deg[des]++;
        res += w;
    }
    
    for(int k=0; k<n ;k++) {
        for(int i=0; i<n ;i++) {
            for(int j=0; j<n ;j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    if(m == 0 && deg[0] == 0) {
        cout << -1;
        return 0;
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(dist[i][j] == INF && deg[i] ==0 && deg[j] == 0) {
                cout << -1;
                return 0;
            }
        }
    }
    for(int i=0; i<n ;i++) {
        if(deg[i] % 2 != 0)  Odddegs.push_back(i);
    }
    res += WeightToReduceOddDeg(0, 0);
    cout << res;
    
    return 0;
}
