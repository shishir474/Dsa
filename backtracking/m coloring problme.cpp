 // soL1 using baCKTRACKING
#include <iostream>
using namespace std;

// Number of vertices in the graph
#define V 4

void printSolution(int color[]);

bool isSafe(int v, bool graph[V][V],
			int color[], int c)
{
	for(int i = 0; i < V; i++)
		if (graph[v][i] && c == color[i])
			return false;
			
	return true;
}

bool graphColoringUtil(bool graph[V][V], int m,
					int color[], int v)
{
	
	/* base case: If all vertices are
	assigned a color then return true */
	if (v == V)
		return true;

	/* Consider this vertex v and
	try different colors */
	for(int c = 1; c <= m; c++)
	{
		
		/* Check if assignment of color
		c to v is fine*/
		if (isSafe(v, graph, color, c))
		{
			color[v] = c;

			/* recur to assign colors to
			rest of the vertices */
			if (graphColoringUtil(
				graph, m, color, v + 1) == true)
				return true;

			/* If assigning color c doesn't
			lead to a solution then remove it */
			color[v] = 0;
		}
	}

	/* If no color can be assigned to
	this vertex then return false */
	return false;
}

bool graphColoring(bool graph[V][V], int m)
{
	
	// Initialize all color values as 0.
	// This initialization is needed
	// correct functioning of isSafe()
	int color[V];
	for(int i = 0; i < V; i++)
		color[i] = 0;

	// Call graphColoringUtil() for vertex 0
	if (graphColoringUtil(graph, m, color, 0) == false)
	{
		cout << "Solution does not exist";
		return false;
	}

	// Print the solution
	printSolution(color);
	return true;
}

/* A utility function to print solution */
void printSolution(int color[])
{
	cout << "Solution Exists:"
		<< " Following are the assigned colors"
		<< "\n";
	for(int i = 0; i < V; i++)
		cout << " " << color[i] << " ";
		
	cout << "\n";
}

// Driver code
int main()
{
	bool graph[V][V] = { { 0, 1, 1, 1 },
						{ 1, 0, 1, 0 },
						{ 1, 1, 0, 1 },
						{ 1, 0, 1, 0 }, };
						
	// Number of colors
	int m = 3;
	graphColoring(graph, m);
	return 0;
}

// Complexity Analysis: 

// Time Complexity: O(m^V). 
// There are total O(m^V) combination of colors. So time complexity is O(m^V). The upperbound time complexity remains the same but the average time taken will be less.
// Space Complexity: O(V). 
// Recursive Stack of graphColoring(…) function will require O(V) space.






// MOST OPTIMAL: BFS APPROACH this METHOD ALLOWS US TO COMPUTE MIN NO OF COLORS REQUIRED TO COLOR THE GRAPH
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool graphColoring() {
    // your code here
    int n = 4;
	bool graph[n][n] = {
	{ 0, 1, 1, 1 },
	{ 1, 0, 1, 0 },
	{ 1, 1, 0, 1 },
	{ 1, 0, 1, 0 }};
	int m = 3; // Number of colors
	
    vector<bool> vis(n, false);
    vector<int> color(n,1); // all vertex are initially painted 1
    int maxcolors=1;
    
    // for all connected components
    for(int i=0;i<n;i++){
        if (vis[i]) continue;
        
        queue<int> q; q.push(i); // i as sv 
        vis[i] = true;
        while(!q.empty()){
            int f=q.front(); q.pop();
            for(int j=0;j<101;j++){ // explore all nb's of i
                if (i!=j and graph[i][j]){
                    if (color[i]==color[j]){
                        color[j]++; 
                        maxcolors = max(maxcolors, color[j]);
                        if (maxcolors > m) return false;
                    }
                    if (!vis[j]){
                        q.push(j);
                        vis[j] = true;
                    }
                }
            }
        }
    }
    
    return true;
}


// Driver code
int main()
{
    cout<<graphColoring();
	return 0;
}

// Complexity Analysis:

// Time Complexity: O(V + E).
// Space Complexity: O(V). For Storing Visited List.
