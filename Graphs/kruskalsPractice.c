#include <stdio.h>
#include <stdlib.h>

#define MAX_FLIGHTS 100

// Define the structure for flights
typedef struct {
    int source;       // Source city
    int destination;  // Destination city
    int cost;         // Cost of the flight
} Flight;

// Define the structure for subsets (for Union-Find)
typedef struct {
    int parent;  // Parent of the subset
    int rank;    // Rank of the subset
} Subset;

// Function prototypes
int compareFlights(const void *a, const void *b); // Function to compare flights by cost
int find(Subset subsets[], int i);               // Function to find the root of a set
void unionSets(Subset subsets[], int x, int y);  // Function to union two sets
void kruskalMST(Flight flights[], int numFlights, int numCities); // Kruskal's MST algorithm

int main() {
    int numCities, numFlights;
    Flight flights[MAX_FLIGHTS];

    // Input the number of cities and flights
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);
    printf("Enter the number of flights: ");
    scanf("%d", &numFlights);

    // Input flight data
    for (int i = 0; i < numFlights; i++) {
        printf("Enter source, destination, and cost for flight %d: ", i + 1);
        scanf("%d %d %d", &flights[i].source, &flights[i].destination, &flights[i].cost);
    }

    // Call Kruskal's algorithm to find the MST
    kruskalMST(flights, numFlights, numCities);

    return 0;
}

// Function to compare flights by their cost (used in sorting)
int compareFlights(const void *a, const void *b) {
    // TODO: Implement comparison logic for sorting flights by cost
    Flight *f1 = (Flight *)a;
    Flight *f2 = (Flight *)b;
    return f1->cost - f2->cost;
}

// Function to find the root of a set (with path compression)
int find(Subset subsets[], int i) {
    // TODO: Implement find with path compression
    if(subsets[i].parent != i){
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Function to union two sets (by rank)
void unionSets(Subset subsets[], int x, int y) {
    // TODO: Implement union by rank
    int root1 = find(subsets, x);
    int root2 = find(subsets, y);
    
    if(subsets[root1].rank < subsets[root2].rank){
        subsets[root1].parent = root2;
    }else if(subsets[root1].rank > subsets[root2].rank){
        subsets[root2].parent = root1;
    }else{
        subsets[root2].parent = root1;
        subsets[root1].rank++;
    }
}

// Function to compute the MST using Kruskal's algorithm
void kruskalMST(Flight flights[], int numFlights, int numCities) {
    // TODO: Sort flights by cost
    qsort(flights, numFlights, sizeof(Flight), compareFlights);
    
    // TODO: Initialize subsets
    Subset s[numCities];
    for(int i = 0; i < numCities; i++){
        s[i].parent = i;
        s[i].rank = 0;
    }
    
    int mstCost = 0;
    
    if(numCities > numFlights){
        printf("The graph is not fully connected; MST cannot be formed.");
        return;
    }
    
    printf("Minimum Spanning Tree:\n");
    
    // TODO: Iterate through sorted flights and construct the MST
    for(int i = 0; i < numFlights; i++){
        Flight nextFlight = flights[i];
        
        int roo1 = find(s, nextFlight.source);
        int roo2 = find(s, nextFlight.destination);
        
        if(roo1 != roo2){
            printf("Edge: %d - %d, Cost: %d\n", nextFlight.source, nextFlight.destination, nextFlight.cost);
            mstCost += nextFlight.cost;
            unionSets(s, roo1, roo2);
        }
    }
    // TODO: Print the MST and total cost
    printf("Total cost of the MST: %d\n", mstCost);
}