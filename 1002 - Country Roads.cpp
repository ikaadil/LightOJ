#include<bits/stdc++.h>
using namespace std;
const int MAX = 510;
typedef pair<long long, int> PII;
bool marked[MAX];
vector <PII> adj[MAX];
int ans[MAX];
long long int c;
long long prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    int y;
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();
        Q.pop();
        x = p.second;
        // Checking for cycle
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
        c=max(c,p.first);
        marked[x] = true;
        for(int i = 0; i < adj[x].size(); ++i)
        {
            y = adj[x][i].second;
            if(marked[y] == false)
                Q.push(adj[x][i]);
        }
    }
    return minimumCost;
}

int main()
{
    int nodes, edges, x, y;
    long long weight, minimumCost;
    cin >> nodes >> edges;
    for(int i = 0; i < edges; ++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }
    int a;
    cin>>a;
    c=0;
    minimumCost = prim(a);
    for(int i=0; i<nodes; i++)
    {
        if(marked[i])
            cout<<c<<"\n";
        else cout<<"Impossible\n";
    }
//    cout << minimumCost << endl;
    return 0;
}
