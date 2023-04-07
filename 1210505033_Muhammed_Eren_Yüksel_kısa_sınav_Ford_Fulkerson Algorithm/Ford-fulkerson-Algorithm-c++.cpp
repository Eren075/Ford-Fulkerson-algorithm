#include<bits/stdc++.h>
using namespace std;

#define V 6 // Graph'un toplam düðüm sayýsý

bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    bool visited[V];
    memset(visited, 0, sizeof(visited)); // visited dizisini sýfýrla

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) // BFS algoritmasýný uygula
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++)
        {
            if (visited[v] == false && rGraph[u][v] > 0) // Eðer henüz ziyaret edilmemiþ ve artan bir yol varsa
            {
                q.push(v); // Kuyruða ekle
                parent[v] = u; // Parent dizisini güncelle
                visited[v] = true; // Ziyaret edildi olarak iþaretle
            }
        }
    }
    return (visited[t] == true); // Hedef düðüme ulaþýlabildi mi?
}

int fordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;

    int rGraph[V][V];
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v]; // Residual Graph'u baþlangýçta graf ile ayný yap

    int parent[V];
    int max_flow = 0;

    while (bfs(rGraph, s, t, parent)) // BFS algoritmasýný kullanarak artan bir yol bulana kadar döngüyü sürdür
    {
        int path_flow = INT_MAX; // Artan yoldaki minimum kapasiteyi bulmak için MAX_INT ile baþlat

        for (v = t; v != s; v = parent[v]) // Yolun tüm düðümlerini dolaþarak minimum kapasiteyi bul
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v = t; v != s; v = parent[v]) // Yolu yeniden dolaþarak residual graph'u güncelle
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow; // Artan yoldaki minimum kapasiteyi maksimum akýþa ekle
    }

    return max_flow; // Maksimum akýþý döndür
}

int main()
{
    int graph[V][V] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      }; // Örnek bir graph

     cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 5);

    return 0;
}
