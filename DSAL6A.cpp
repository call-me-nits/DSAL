
/*
6.Represent a given graph using adjacency matrix/list to perform DFS and using adjacency list to
perform BFS. Use the map of the area around the college as the graph. Identify the prominent land
marks as nodes and perform DFS and BFS on that.
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int cost[10][10], i, j, k, n, qu[10], front, rear, v, visit[10], visited[10];
int stk[10], top, visit1[10], visited1[10];

int main() {
    int m;
    cout << "Enter no. of vertices : ";
    cin >> n;
    cout << "Enter no. of edges : ";
    cin >> m;
    cout << "\nEDGES \n";
    for(k = 0; k < m; k++) {
        cin >> i >> j;
        cost[i-1][j-1] = 1;
        cost[j-1][i-1] = 1;
    }
    cout << "The adjacency matrix of the graph is" << endl;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            cout << " " << cost[i][j];
        }
        cout << endl;
    }
    cout << "Enter initial vertex for BFS : ";
    cin >> v;
    cout << "The BFS of the Graph is : \n";
    cout << v << " ";
    visited[v-1] = 1;
    k = 1;
    while(k < n) {
        for(j = 0; j < n; j++) {
            if(cost[v-1][j]!=0 && visited[j]!=1 && visit[j]!=1) {
                visit[j] = 1;
                qu[rear++] = j+1;
            }
        }
        v = qu[front++];
        cout << v << " ";
        k++;
        visit[v-1] = 0;
        visited[v-1] = 1;
    }
    cout << "\nEnter initial vertex for DFS : ";
    cin >> v;
    cout << "The DFS of the Graph is\n";
    cout << v << " ";
    visited[v-1] = 1;
    k = 1;
    while(k < n) {
        for(j = n-1; j >= 0; j--) {
            if(cost[v-1][j]!=0 && visited1[j]!=1 && visit1[j]!=1) {
                visit1[j] = 1;
                stk[top] = j+1;
                top++;
            }
        }
        v = stk[--top];
        cout << v << " ";
        k++;
        visit1[v-1] = 0;
        visited1[v-1] = 1;
    }
    cout << endl;
    return 0;
}

