#include <bits/stdc++.h>
using namespace std;
int parent[100000];
int r[100000];
// int n;
// n is no. of component of a graph
// or say the no of vertex
void makeset(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        r[i] = 0;
    }
}
// this function will find the parent of node
int find_parent(int x)
{
    if (parent[x] != x)
    {
        parent[x] = find_parent(parent[x]);
    }
    return parent[x];
}
void Union(int x, int y)
{
    int xset = find_parent(x);
    int yset = find_parent(y);
    if (xset == yset)
    {
        return;
    }
    if (r[xset] < r[yset])
    {
        parent[xset] = yset;
    }
    else if (r[xset] > r[yset])
    {
        parent[yset] = xset;
    }
    // kise ko bhi khi bhi laga sakte ho
    else
    {
        parent[yset] = xset;
        r[xset]++;
    }
}
int main()
{
    int n;
    cout << "enter the number of items" << endl;
    // cin >> n;
    makeset(5);
    Union(0, 2);
    Union(4, 2);
    Union(3, 1);
    if (find_parent(4) == find_parent(0))
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    if (find_parent(1) == find_parent(0))
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    return 0;
}