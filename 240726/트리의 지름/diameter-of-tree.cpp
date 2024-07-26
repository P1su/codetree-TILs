#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 100000

int N, ans = 0, End = 0;
vector<pair<int, int>> edges[MAX];
bool visited[MAX];

void DFS(int x, int dist){
    if(visited[x])return;

    if(ans < dist){
        ans = dist;
        End = x;
    }
    for(int i = 0 ; i < edges[x].size() ; i++){
        visited[x] = true;
        DFS(edges[x][i].first, dist + edges[x][i].second);
    }
}

int main() {
    cin>>N;

    for(int i = 0 ; i < N ; i++){
        int a, b, c;
        cin>>a>>b>>c;

        edges[a].push_back({b, c});
        edges[b].push_back({a, c});

    }

    DFS(1, 0);
    memset(visited, false, sizeof(visited));
    DFS(End, 0);

    cout<<ans;
    return 0;
}