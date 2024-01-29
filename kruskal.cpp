#include <bits/stdc++.h>
using namespace std;
const int MAX = 50;
int root[MAX];
const int nodes = 4, edges = 5;
pair<long long, pair<int, int> > p[MAX];

int parent(int a)                                                      
//find the parent of the given node
{
while(root[a] != a)
    {
root[a] = root[root[a]];
        a = root[a];
    }
return a;
}

void union_find(int a, int b)                                      
  //check if the given two vertices are in the same "union" or not
{
int d = parent(a);
int e = parent(b);
root[d] = root[e];
}




long kruskal()
{
int a, b;
long cost, minCost = 0;
for(int i = 0 ; i< edges ; ++i)
    {
        a = p[i].second.first;
        b = p[i].second.second;
cost = p[i].first;
if(parent(a) != parent(b))                                  
//only select edge if it does not create a cycle (i.e. the two nodes forming it have different root nodes)
        {
minCost = minCost + cost;
            union_find(a, b);
        }
    }
return minCost;
}
/*
1. Initialization:
" int a, b;: Variables to store the endpoints of an edge.
" longlong cost, minCost = 0;: Variables to store the weight of the current edge (cost) and the total minimum cost (minCost). minCost is initialized to 0.
2. Iterating Through Sorted Edges:
" for (inti = 0; i< edges; ++i): Loop through the sorted array of edges.
" a = p[i].second.first; and b = p[i].second.second;: Extract the endpoints of the current edge from the sorted array p.
" cost = p[i].first;: Extract the weight of the current edge.
3. Checking for Cycle:
" if (parent(a) != parent(b)) {: Check if including the current edge would create a cycle in the minimum spanning tree. This is done by comparing the parent of the endpoints (a andb) using the parent function.
" parent(a) and parent(b) return the representative nodes (root nodes) of the sets to which a and b belong.
" If the endpoints have different representative nodes, adding the edge doesn't create a cycle.
4. Updating Minimum Cost and Union Operation:
" minCost += cost;: If the edge doesn't create a cycle, add its weight to the total minimum cost.
" union_find(a, b);: Perform the union operation to merge the sets containing nodes a and b.
5. Return Minimum Cost:
" returnminCost;: After processing all edges, return the total minimum cost of the spanning tree.
*/
int main()
{
int x, y;
long long weight, cost, minCost;
for(int i = 0;i < MAX;++i)                        
               //initialize the array groups
    {
root[i] = i;
    }
p[0] = make_pair(10, make_pair(0, 1));
p[1] = make_pair(18, make_pair(1, 2));
p[2] = make_pair(13, make_pair(2, 3));
p[3] = make_pair(21, make_pair(0, 2));
p[4] = make_pair(22, make_pair(1, 3));
sort(p, p + edges);
               //sort the array of edges
minCost = kruskal();
cout<< "Minimum cost is: "<<minCost<<endl;
return 0;
}
