#include <bits/stdc++.h>
using namespace std;


bool isVisited[1000];
vector< vector<int> >  adj(1000);

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    isVisited[src] = true;

    while ( !q.empty() )
    {

        // step 1:
        // parent ba first node ta k ber kore ano 
        int par = q.front();
        q.pop();
        
        // step 2:
        // parent k print koro
        cout << par << " ";


        // step 3:
        // oi node r child k push koro 
        for( int child: adj[par] )
        {
            if(isVisited[child] == false)
            {
                // cout << child << " ";
                isVisited[child] = true;
                q.push(child);
            }

        }
    }
    
}

int main() {
  
    int n, e;
    cin >> n >> e;

    

    for(int i = 0; i < e; i++)
    {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);   // a is connected to b 
        adj[v].push_back(u);  // so b is connected to a also

    }

  

    bfs(1);

    return 0;
}