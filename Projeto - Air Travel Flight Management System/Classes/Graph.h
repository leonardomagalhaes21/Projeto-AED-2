//
// Created by tiago on 18-12-2023.
//

#ifndef PROJETO2_GRAPH_H
#define PROJETO2_GRAPH_H
#include <cstddef>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include "Airport.h"
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Edge;
class Graph;
class Vertex;


/****************** Provided structures  ********************/

class Vertex {
    string info;           // aiport code
    vector<Edge > adj;     // list of outgoing edges
    bool visited;          // auxiliary field
    bool processing;       // auxiliary field
    int inDegree;          // auxiliary field
    int outDegree;         // auxiliary field
    int num;               // auxiliary field
    int low;               // auxiliary field


    void addEdge(Vertex *dest,string airline, float w);
    bool removeEdgeTo(Vertex *d);
public:
    Vertex(string in);
    string getInfo() const;
    void setInfo(string in);
    bool isVisited() const;
    void setVisited(bool v);
    bool isProcessing() const;
    void setProcessing(bool p);
    const vector<Edge> &getAdj() const;
    void setAdj(const vector<Edge> &adj);

    int getIndegree() const;

    void setIndegree(int indegree);
    void setOutdegree(int outdegree);
    int getOutdegree() const;
    int getNum() const;

    void setNum(int num);

    int getLow() const;

    void setLow(int low);

    friend class Graph;
};


class Edge {
    Vertex * dest;      // destination vertex
    float distance;         // edge distance
    string airline;
public:
    Edge(Vertex *d, string airline,float w);
    Vertex *getDest() const;
    void setDest(Vertex *dest);
    float getDistance() const;
    void setDistance(float distance);
    friend class Graph;
    friend class Vertex;

    void setAirline(string line);
    string getAirline();
};


class Graph {
    vector<Vertex *> vertexSet;      // vertex set
    int _index_;                        // auxiliary field
    stack<Vertex> _stack_;           // auxiliary field
    list<list<string>> _list_sccs_;        // auxiliary field

    void dfsVisit(Vertex *v,  vector<string> & res) const;
    bool dfsIsDAG(Vertex *v) const;
public:
    Vertex *findVertex(const string &in) const;
    int getNumVertex() const;
    bool addVertex(const string &in);
    bool removeVertex(const string &in);
    bool addEdge(const string &sourc, const string &dest, string airline,float w);
    bool removeEdge(const string &sourc, const string &dest);
    vector<Vertex * > getVertexSet() const;
    vector<string> dfs() const;
    vector<string> dfs(const string & source) const;
    vector<string> bfs(const string &source) const;
    vector<string> topsort() const;
    bool isDAG() const;

    Graph();
    Graph(unordered_map<std::string, Airport> airports);
    vector<string> nodesAtDistanceBFS(const string &source, int k) const;
    vector<pair<string,string>> dfs(int& maxStops, vector<pair<string,string>>& res) const;
    void dfsVisit(Vertex *v, vector<pair<string,string>>& res, int& maxStops, int stops, const string &source) const;
    unordered_set<string> articulationPoints() const;
    vector<string> shortestPathBFS(const string &source, const string &destination) const;
    vector<string> shortestPathBFS(const string &source, const string &destination,const std::vector<std::string> &selectedAirlines) const;
};


#endif //PROJETO2_GRAPH_H