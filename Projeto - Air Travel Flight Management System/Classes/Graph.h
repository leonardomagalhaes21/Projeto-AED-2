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
    int outdegree;         // auxiliary field
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
};

/****************** Provided constructors and functions ********************/


Vertex::Vertex(string in): info(in) {

}


Edge::Edge(Vertex *d, string line,float w): dest(d), airline(line),distance(w) {}



int Graph::getNumVertex() const {
    return vertexSet.size();
}


vector<Vertex * > Graph::getVertexSet() const {
    return vertexSet;
}


string Vertex::getInfo() const {
    return info;
}

void Vertex::setInfo(string in) {
    Vertex::info = in;
}

bool Vertex::isProcessing() const {
    return processing;
}

void Vertex::setProcessing(bool p) {
    Vertex::processing = p;
}

Vertex *Edge::getDest() const {
    return dest;
}

void Edge::setDest(Vertex *d) {
    Edge::dest = d;
}

float Edge::getDistance() const {
    return distance;
}

void Edge::setDistance(float weight) {
    Edge::distance = distance;
}

void Edge::setAirline(string line) {
    Edge::airline = line;
}

string Edge::getAirline() {
    return airline;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */

Vertex * Graph::findVertex(const string &in) const {
    for (auto v : vertexSet)
        if (v->info == in)
            return v;
    return NULL;
}

bool Vertex::isVisited() const {
    return visited;
}

int Vertex::getOutdegree() const {
    return outdegree;
}

void Vertex::setOutdegree(int outdegree) {
    Vertex::outdegree = outdegree;
}

int Vertex::getIndegree() const {
    return inDegree;
}

void Vertex::setIndegree(int indegree) {
    Vertex::inDegree = indegree;
}

int Vertex::getNum() const {
    return num;
}

void Vertex::setNum(int num) {
    Vertex::num = num;
}

int Vertex::getLow() const {
    return low;
}

void Vertex::setLow(int low) {
    Vertex::low = low;
}

void Vertex::setVisited(bool v) {
    Vertex::visited = v;
}

const vector<Edge> &Vertex::getAdj() const {
    return adj;
}

void Vertex::setAdj(const vector<Edge> &adj) {
    Vertex::adj = adj;
}


/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
bool Graph::addVertex(const string &in) {
    if ( findVertex(in) != NULL)
        return false;
    vertexSet.push_back(new Vertex(in));
    return true;
}


/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge distance (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
bool Graph::addEdge(const string &sourc, const string &dest,string airline, float w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == NULL || v2 == NULL)
        return false;
    v1->addEdge(v2,airline,w);
    return true;
}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge distance (w).
 */
void Vertex::addEdge(Vertex *d,string airline, float w) {
    adj.push_back(Edge(d,airline, w));
}


/*
 * Removes an edge from a graph (this).
 * The edge is identified by the source (sourc) and destination (dest) contents.
 * Returns true if successful, and false if such edge does not exist.
 */

bool Graph::removeEdge(const string &sourc, const string &dest) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == NULL || v2 == NULL)
        return false;
    return v1->removeEdgeTo(v2);
}

/*
 * Auxiliary function to remove an outgoing edge (with a given destination (d))
 * from a vertex (this).
 * Returns true if successful, and false if such edge does not exist.
 */

bool Vertex::removeEdgeTo(Vertex *d) {
    for (auto it = adj.begin(); it != adj.end(); it++)
        if (it->dest  == d) {
            adj.erase(it);
            return true;
        }
    return false;
}

/*
 *  Removes a vertex with a given content (in) from a graph (this), and
 *  all outgoing and incoming edges.
 *  Returns true if successful, and false if such vertex does not exist.
 */

bool Graph::removeVertex(const string &in) {
    for (auto it = vertexSet.begin(); it != vertexSet.end(); it++)
        if ((*it)->info  == in) {
            auto v = *it;
            vertexSet.erase(it);
            for (auto u : vertexSet)
                u->removeEdgeTo(v);
            delete v;
            return true;
        }
    return false;
}


/****************** DFS ********************/
/*
 * Performs a depth-first search (dfs) traversal in a graph (this).
 * Returns a vector with the contents of the vertices by dfs order.
 * Follows the algorithm described in theoretical classes.
 */

vector<string> Graph::dfs() const {
    vector<string> res;
    for (auto v : vertexSet)
        v->visited = false;
    for (auto v : vertexSet)
        if (! v->visited)
            dfsVisit(v, res);
    return res;
}

/*
 * Auxiliary function that visits a vertex (v) and its adjacent, recursively.
 * Updates a parameter with the list of visited node contents.
 */

void Graph::dfsVisit(Vertex *v, vector<string> & res) const {
    v->visited = true;
    res.push_back(v->info);
    for (auto & e : v->adj) {
        auto w = e.dest;
        if ( ! w->visited)
            dfsVisit(w, res);
    }
}


/****************** DFS ********************/
/*
 * Performs a depth-first search (dfs) in a graph (this).
 * Returns a vector with the contents of the vertices by dfs order,
 * from the source node.
 */

vector<string> Graph::dfs(const string  &source) const {
    vector<string> res;
    auto s = findVertex(source);
    if (s == nullptr)
        return res;

    for (auto v : vertexSet)
        v->visited = false;

    dfsVisit(s, res);
    return res;
}


/****************** BFS ********************/
/*
 * Performs a breadth-first search (bfs) in a graph (this), starting
 * from the vertex with the given source contents (source).
 * Returns a vector with the contents of the vertices by bfs order.
 */

vector<string> Graph::bfs(const string & source) const {
    vector<string> res;
    auto s = findVertex(source);
    if (s == NULL)
        return res;
    queue<Vertex *> q;
    for (auto v : vertexSet)
        v->visited = false;
    q.push(s);
    s->visited = true;
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        res.push_back(v->info);
        for (auto & e : v->adj) {
            auto w = e.dest;
            if ( ! w->visited ) {
                q.push(w);
                w->visited = true;
            }
        }
    }
    return res;
}


/****************** isDAG  ********************/
/*
 * Performs a depth-first search in a graph (this), to determine if the graph
 * is acyclic (acyclic directed graph or DAG).
 * During the search, a cycle is found if an edge connects to a vertex
 * that is being processed in the stack of recursive calls (see theoretical classes).
 * Returns true if the graph is acyclic, and false otherwise.
 */


bool Graph::isDAG() const {
    for (auto v : vertexSet) {
        v->visited = false;
        v->processing = false;
    }
    for (auto v : vertexSet)
        if (! v->visited)
            if ( ! dfsIsDAG(v) )
                return false;
    return true;
}

/**
 * Auxiliary function that visits a vertex (v) and its adjacent, recursively.
 * Returns false (not acyclic) if an edge to a vertex in the stack is found.
 */

bool Graph::dfsIsDAG(Vertex *v) const {
    v->visited = true;
    v->processing = true;
    for (auto & e : v->adj) {
        auto w = e.dest;
        if (w->processing)
            return false;
        if (! w->visited)
            if (! dfsIsDAG(w))
                return false;
    }
    v->processing = false;
    return true;
}


/****************** toposort ********************/

vector<string> Graph::topsort() const {
    vector<string> res;
    queue<Vertex*> temp;
    if (!isDAG()){
        return res;
    }
    for(auto t: vertexSet){
        t->setVisited(false);
        t->setIndegree(0);
    }
    for(auto t: vertexSet){
        for(Edge e:t->adj){
            e.getDest()->setIndegree(e.getDest()->getIndegree()+1);
        }
    }
    for(auto t:vertexSet){
        if(t->getIndegree()==0){
            temp.push(t);
        }
    }
    while (!temp.empty()){
        Vertex * adj=temp.front();
        temp.pop();
        res.push_back(adj->getInfo());
        for(Edge e:adj->getAdj()){
            Vertex* adj2=e.getDest();
            adj2->setIndegree(adj2->getIndegree()-1);
            if(adj2->getIndegree()==0){
                temp.push(adj2);
            }
        }
    }

    return res;
}
#endif //PROJETO2_GRAPH_H