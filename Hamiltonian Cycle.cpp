// Program to Find Hamiltonian Cycle


#include <iostream>
#include <cstdio>
#include <cstdlib>
#define V 5
using namespace std;
 
void printSolution(int path[]);

bool isSafe(int v, bool graph[V][V], int path[], int pos)
{
    if (graph [path[pos-1]][v] == 0)
        return false;
   for (int p = 0; p < pos; p++)
        if (path[p] == v)
            return false;
    return true;
}
 

bool hamCycleUt(bool graph[V][V], int path[], int pos)
{
    if (pos == V)
    {
        if (graph[ path[pos-1] ][ path[0] ] == 1)
            return true;
        else
            return false;
    }
 
    for (int v = 1; v < V; v++)
    {
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;
            if (hamCycleUt (graph, path, pos+1) == true)
                return true;
            path[pos] = -1;
        }
    }
    return false;
}
 
bool hamCycle(bool graph[V][V])
{
    int *path = new int[V];
    for (int n = 0; n < V; n++)
        path[n] = -1;
    path[0] = 0;
    if (hamCycleUt(graph, path, 1) == false)
    {
        cout<<"\nSolution does not exist"<<endl;
        return false;
    }
    printSolution(path);
    return true;
}
 
//main function//
void printSolution(int path[])
{
    cout<<"Solution Exists:";
    cout<<" Following is a Hamiltonian Cycle \n"<<endl;
    for (int m = 0; m < V; m++)
        cout<<path[m]<<"  ";
    cout<< path[0]<<endl;
}
 
int main()
{
   bool graph1[V][V] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                     };
   hamCycle(graph1);
 
   
    bool graph2[V][V] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 0},
                      {0, 1, 1, 0, 0},
                     };
    hamCycle(graph2);
    return 0;
}
