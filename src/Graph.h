#pragma once

#include "Matrix.h"

#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

typedef int Vertex;

/**
 * Graph representation of friend network
*/
class Graph
{
    public:
        /**
         * Default Constructor to create an empty graph.
        */
        Graph();

        /**
         * Destructor
        */
        ~Graph();

        /**
         * Builds a graph from a file of edges.
         * Format should be two int ids seperated by space per line.
         * @param filename - the path of file from which to build the graph
        */
        void BuildGraph(const string & filename);

        /**
         * Return all Vertices of graph
         * @return - A std::vector of Vertices in graph
        */
        vector<Vertex> getAllVertices();

        /**
         * Return adjacency list of a Vertex with passed id
         * @param id - ID of the vertex we want adj list for
         * @return - A std::list of Vertices that the passed Vertex is adj to
         *         - Empty list if Vertex is not connected
         *         - list with -1 if vertex doesn't exist
        */
        list<Vertex> getAdjacencyList (int id);

        /**
         * Adds a vertex to the graph
        */
        void AddVertex(int id);

        /**
         * Adds an edge between two vertices
         * Since this is undirected, we add to both adj lists
        */
        void AddEdge(int id1, int id2);

        /**
         * Check if a vertex with passed id exists
         * @param id - ID of vertex we want to find
        */
        bool vertexExists(int id);
        
        /**
         * Check if an edge between two vertices exists
         * @param id1 - First vertex ID
         * @param id2 - Second vertex ID
         * @return - True or False depending on if there is an edge
         *         - Should Throw error if any of the ids aren't in the graph
        */
        bool edgeExists(int id1, int id2);

        /**
         * Returns the Size of the graph which will be the number of nodes
        */
        int getSize();

        /**
         * Performs BFS traversal of the graph including ALL components (connected and disconnected)
         * @returns - vector of Vertices in BFS order
        */
        vector<Vertex> BFS();

        /**
         * Helper for BFS traversal of the graph used for testing
         * @param - Starting Vertex ID
         * @param - Reference of output list from BFS function
        */
        void BFSHelper(Vertex id, vector<Vertex>& out);
        /**
         * Performs PageRank on our graph to see who the "most important/popular" person is
         * @param num_places -How many places of rankings to return (eg top 5, 10, etc)
         * @param num_iter - How many times to run the iteration for PageRank
         * @param alpha - The dampening factor for the PageRank Matrix, defaults to 0.85, this value must be 
         * @param tol - tolerance for stopping iterations early, if the difference in norms between two iterations
         *  is smaller than tol, we stop iterating
         *  a probablity, e.g. a number 0 to 1
         *  Dampening factor is the "The probability, at any step, that the person will continue is a damping factor d."
         *  https://en.wikipedia.org/wiki/PageRank#Damping_factor 
         * @return -List of size num_places with the top num_places vertices in the graph according to PageRank
        */
        vector<Vertex> PageRank(int num_places = 10, int num_iter=20, double alpha=0.85, double tol=1e-6);

        /**
         * Performs BetweenessCentrality on our Graph to see who the most important people are in the network
         * @return - vector of all vertices' betweenness centrality values
        */
        void BetweennessCentrality();

        /**
         * Displays most popular users/vertices in graph based on betweenness centrality
         * @param num_places - How many places of rankings to return (eg: top 5, 10, etc.)
         * @return void - prints out num_places number of vertices / users and their betweenness centrality value
        */
        vector<Vertex> getTopIDs(int num_places);

        /**
         * Returns Betweenness Centrality value for one user
         * @param id - vertex ID for user
         * @return - number representing how many shortest paths in network user is a part of
        */
        float getUserBetweennessCentrality(int id);

        /**
         * Returns BC Value for one user in terms of percentage
         * @param id - vertex ID for user
         * @return - number representing normalized BC Value for user
        */
        float getPercentUserBetweennessCentrality(int id);

        /**
         * returns Betweenness Centrality map which holds user and their BC value
         * @return - betweenessCentrality map of all users
        */
        unordered_map<Vertex, float> getAllBetweennessCentrality();

        /**
         * Prints graph in adj list format for testing 
        */
        void print() const;

    private:
        /**
         * Calculates 1 norm of vector to help PageRank calculation
        */
        double calcNorm(Matrix vec) const;
        /**
         * Create Normalized Adjacency Matrix where all columns have a norm of 1
         * Meaning the sum of column / non zero elements == 1
        */
        Matrix makeAdjMatrix(unordered_map<Vertex, int>& reverse_idx);
        // Adjancency List of Vertex and all its neighbors
        unordered_map<Vertex, list<Vertex>>* adj_list;
        // Map of all vertices and whether they've been visited or not
        unordered_map<Vertex, bool> visited;
        // Map of all vertices and their BC value
        unordered_map<Vertex, float> betweennessCentrality;
        // Bool to check whether betweenessCentrality has been calculated or not
        bool calculatedBC;
        // Size of graph which we define to be number of vertices
        int size;

};
