#include <stdio.h>
#define N 4

// Distance matrix
int dist[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}};

// Function to calculate total distance
int pathCost(int path[])
{
    int cost = 0;
    for (int i = 0; i < N - 1; i++)
        cost += dist[path[i]][path[i + 1]];
    cost += dist[path[N - 1]][path[0]]; // Return to start
    return cost;
}

// Swap two cities
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hill Climbing for TSP
void travellingSalesmanHillClimbing(int path[])
{
    int improved = 1;
    int currentCost = pathCost(path);

    while (improved)
    {
        improved = 0;
        for (int i = 1; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                swap(&path[i], &path[j]);
                int newCost = pathCost(path);
                if (newCost < currentCost)
                {
                    currentCost = newCost;
                    improved = 1;
                }
                else
                {
                    swap(&path[i], &path[j]); // revert swap
                }
            }
        }
    }

    // Print result
    printf("Best path: ");
    for (int i = 0; i < N; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]); // Return to start
    printf("Minimum cost: %d\n", currentCost);
}

int main()
{
    int path[N];
    for (int i = 0; i < N; i++)
        path[i] = i; // Initial path

    travellingSalesmanHillClimbing(path);

    return 0;
}
