

#include "Graph.h"
#include <iostream>


/**
 * @brief Constructor for the Vertex class.
 *
 * @param in The information/content of the vertex.
 */
Vertex::Vertex(string in): info(in) {
    inDegree = 0;
    outDegree = 0;
    num = 0;
    low = 0;
}

/**
 * @brief Constructor for the Edge class.
 *
 * @param d The destination vertex.
 * @param line The airline associated with the edge.
 * @param w The distance/weight of the edge.
 */
Edge::Edge(Vertex *d, string line,float w): dest(d), airline(line),distance(w) {}


/**
 * @brief Get the number of vertices in the graph.
 *
 * @return The number of vertices in the graph.
 *
 * @complexity Time Complexity: O(1)
 */
int Graph::getNumVertex() const {
    return vertexSet.size();
}

/**
 * @brief Gets the vector of vertices in the graph.
 *
 * @return The vector of vertices.
 *
 * @complexity Time Complexity: O(1)
 */
vector<Vertex * > Graph::getVertexSet() const {
    return vertexSet;
}

/**
 * @brief Gets the information/content of the vertex.
 *
 * @return The information/content of the vertex.
 *
 * @complexity Time Complexity: O(1)
 */
string Vertex::getInfo() const {
    return info;
}

/**
 * @brief Sets the information/content of the vertex.
 *
 * @param in The new information/content of the vertex.
 *
 * @complexity Time Complexity: O(1)
 */
void Vertex::setInfo(string in) {
    Vertex::info = in;
}

/**
 * @brief Checks if the vertex is in processing state.
 *
 * @return True if the vertex is in processing state, false otherwise.
 *
 * @complexity Time Complexity: O(1)
 */
bool Vertex::isProcessing() const {
    return processing;
}

/**
 * @brief Gets the destination vertex of the edge.
 *
 * @return The destination vertex of the edge.
 *
 * @complexity Time Complexity: O(1)
 */
void Vertex::setProcessing(bool p) {
    Vertex::processing = p;
}


/**
 * @brief Gets the destination vertex of the edge.
 *
 * @return The destination vertex of the edge.
 *
 * @complexity Time Complexity: O(1)
 */
Vertex *Edge::getDest() const {
    return dest;
}
/**
 * @brief Sets the destination vertex of the edge.
 *
 * @param d The new destination vertex of the edge.
 *
 * @complexity Time Complexity: O(1)
 */
void Edge::setDest(Vertex *d) {
    Edge::dest = d;
}

/**
 * @brief Gets the distance/weight of the edge.
 *
 * @return The distance/weight of the edge.
 *
 * @complexity Time Complexity: O(1)
 */
float Edge::getDistance() const {
    return distance;
}

/**
 * @brief Sets the distance/weight of the edge.
 *
 * @param weight The new distance/weight of the edge.
 *
 * @complexity Time Complexity: O(1)
 */
void Edge::setDistance(float weight) {
    Edge::distance = distance;
}

/**
 * @brief Sets the airline associated with the edge.
 *
 * @param line The new airline associated with the edge.
 *
 * @complexity Time Complexity: O(1)
 */
void Edge::setAirline(string line) {
    Edge::airline = line;
}

/**
 * @brief Gets the airline associated with the edge.
 *
 * @return The airline associated with the edge.
 *
 * @complexity Time Complexity: O(1)
 */
string Edge::getAirline() {
    return airline;
}

/**
 * @brief Constructor for the Graph class.
 *
 * @param airports The map of airports.
 */
Graph::Graph(unordered_map<string, Airport> airports) {
    for(auto airport:airports){
        addVertex(airport.first);
    }
}

Graph::Graph() {
}


/**
 * @brief Finds a vertex with a given content.
 *
 * @param in The content of the vertex.
 *
 * @return A pointer to the vertex if found, otherwise nullptr.
 *
 * @complexity Time Complexity: O(V), where V is the number of vertices in the graph.
 */
Vertex * Graph::findVertex(const string &in) const {
    for (auto v : vertexSet)
        if (v->info == in)
            return v;
    return NULL;
}

/**
 * @brief Checks if the vertex is visited.
 *
 * @return True if the vertex is visited, false otherwise.
 *
 * @complexity Time Complexity: O(1)
 */
bool Vertex::isVisited() const {
    return visited;
}

/**
 * @brief Gets the outdegree of the vertex.
 *
 * @return The outdegree of the vertex.
 *
 * @complexity Time Complexity: O(1)
 */
int Vertex::getOutdegree() const {
    return outDegree;
}
/**
 * @brief Sets the outdegree of the vertex.
 *
 * @param outdegree The new outdegree of the vertex.
 *
 * @complexity Time Complexity: O(1)
 */
void Vertex::setOutdegree(int outdegree) {
    Vertex::outDegree = outdegree;
}
/**
 * @brief Gets the indegree of the vertex.
 *
 * @return The indegree of the vertex.
 *
 * @complexity Time Complexity: O(1)
 */
int Vertex::getIndegree() const {
    return inDegree;
}

/**
 * @brief Sets the indegree of the vertex.
 *
 * @param indegree The new indegree of the vertex.
 *
 * @complexity Time Complexity: O(1)
 */
void Vertex::setIndegree(int indegree) {
    Vertex::inDegree = indegree;
}

/**
 * @brief Gets the number of the vertex.
 *
 * @return The number of the vertex.
 *
 * @complexity Time Complexity: O(1)
 */
int Vertex::getNum() const {
    return num;
}

/**
 * @brief Sets the number of the vertex.
 *
 * @param num The new number of the vertex.
 *
 * @complexity Time Complexity: O(1)
 */
void Vertex::setNum(int num) {
    Vertex::num = num;
}

/**
 * @brief Gets the low of the vertex.
 *
 * @return The low of the vertex.
 *
 * @complexity Time Complexity: O(1)
 */
int Vertex::getLow() const {
    return low;
}

/**
 * @brief Sets the low of the vertex.
 *
 * @param low The new low of the vertex.
 *
 * @complexity Time Complexity: O(1)
 */
void Vertex::setLow(int low) {
    Vertex::low = low;
}

/**
 * @brief Sets the visited state of the vertex.
 *
 * @param v The new visited state of the vertex.
 *
 * @complexity Time Complexity: O(1)
 */
void Vertex::setVisited(bool v) {
    Vertex::visited = v;
}

/**
 * @brief Gets the adjacent vertices of the vertex.
 *
 * @return The adjacent vertices of the vertex.
 *
 * @complexity Time Complexity: O(1)
 */
const vector<Edge> &Vertex::getAdj() const {
    return adj;
}

/**
 * @brief Sets the adjacent vertices of the vertex.
 *
 * @param adj The new adjacent vertices of the vertex.
 *
 * @complexity Time Complexity: O(1)
 */
void Vertex::setAdj(const vector<Edge> &adj) {
    Vertex::adj = adj;
}


/**
 * @brief Adds a vertex with a given content to the graph.
 *
 * @param in The content of the vertex.
 * @return True if successful, false if the vertex already exists.
 *
 * Time Complexity: O(1)
 */
bool Graph::addVertex(const string &in) {
    if ( findVertex(in) != NULL)
        return false;
    vertexSet.push_back(new Vertex(in));
    return true;
}


/**
 * @brief Adds an edge to the graph.
 *
 * @param sourc The source vertex content.
 * @param dest The destination vertex content.
 * @param airline The airline associated with the edge.
 * @param w The distance/weight of the edge.
 * @return True if successful, false if the source or destination vertex does not exist.
 *
 * Time Complexity: O(V), where V is the number of vertices in the graph.
 */
bool Graph::addEdge(const string &sourc, const string &dest,string airline, float w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == NULL || v2 == NULL)
        return false;
    v1->addEdge(v2,airline,w);
    return true;
}

/**
 * @brief Adds an outgoing edge to a vertex with a given destination vertex and edge distance.
 *
 * @param d The destination vertex.
 * @param airline The airline associated with the edge.
 * @param w The distance/weight of the edge.
 *
 * Time Complexity: O(1)
 */
void Vertex::addEdge(Vertex *d,string airline, float w) {
    adj.push_back(Edge(d,airline, w));
}


/**
 * @brief Removes an edge from the graph.
 *
 * @param sourc The source vertex content.
 * @param dest The destination vertex content.
 * @return True if successful, false if the edge does not exist.
 *
 * Time Complexity: O(V), where V is the number of vertices in the graph.
 */
bool Graph::removeEdge(const string &sourc, const string &dest) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == NULL || v2 == NULL)
        return false;
    return v1->removeEdgeTo(v2);
}

/**
 * @brief Removes an outgoing edge from a vertex.
 *
 * @param d The destination vertex.
 * @return True if successful, false if the edge does not exist.
 *
 * Time Complexity: O(E), where E is the number of edges in the graph.
 */
bool Vertex::removeEdgeTo(Vertex *d) {
    for (auto it = adj.begin(); it != adj.end(); it++)
        if (it->dest  == d) {
            adj.erase(it);
            return true;
        }
    return false;
}


/**
 * @brief Removes a vertex and all its outgoing and incoming edges from the graph.
 *
 * @param in The content of the vertex to be removed.
 * @return True if successful, false if the vertex does not exist.
 *
 * Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
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


/**
 * @brief Perform a depth-first search (DFS) in the graph.
 *
 * @return Vector of vertex contents in DFS order.
 *
 * @complexity Time Complexity: O(N + E), where V is the number of vertices and E is the number of edges.
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



void Graph::dfsVisit(Vertex *v, vector<string> & res) const {
    v->visited = true;
    res.push_back(v->info);
    for (auto & e : v->adj) {
        auto w = e.dest;
        if ( ! w->visited)
            dfsVisit(w, res);
    }
}


/**
 * @brief Perform a depth-first search (DFS) in the graph from a specific source.
 *
 * @param source The source vertex for DFS.
 *
 * @return Vector of vertex contents in DFS order.
 *
 * @complexity Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
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


/**
 * @brief Perform a breadth-first search (BFS) in the graph from a specific source.
 *
 * @param source The source vertex for BFS.
 *
 * @return Vector of vertex contents in BFS order.
 *
 * @complexity Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
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

/**
 * @brief Check if the graph is a Directed Acyclic Graph (DAG).
 *
 * @return True if the graph is a DAG, false otherwise.
 *
 * @complexity Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
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


/**
 * @brief Perform topological sorting of the graph.
 *
 * @return Vector of vertex contents in topological order.
 *
 * @complexity Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
 */
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

/**
 * @brief Find nodes at a certain distance from a source using BFS.
 *
 * @param source The source vertex.
 * @param k The distance.
 *
 * @return Vector of vertex contents at the specified distance.
 *
 * @complexity Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
 */

vector<string> Graph::nodesAtDistanceBFS(const string &source, int k) const {
    vector<string> res;
    queue<Vertex*> temp;
    for (auto v : vertexSet){
        v->setVisited(false);
    }
    Vertex* start = findVertex(source);
    start->setVisited(true);
    temp.push(start);
    while (!temp.empty()&&k>=0){
        int size=temp.size();
        while (size>0) {
            Vertex* adj = temp.front();
            temp.pop();

            res.push_back(adj->getInfo());

            for (const auto& v: adj->getAdj()) {
                Vertex* adj2 = v.getDest();
                if (!adj2->isVisited()) {
                    adj2->setVisited(true);
                    temp.push(adj2);
                }
            }
            size--;
        }
        k--;
    }
    return res;
}

/**
 * @brief Perform a depth-first search (DFS) in the graph with a specified maximum number of stops.
 *
 * @param maxStops The maximum number of stops allowed in the DFS.
 * @param res Vector to store pairs of vertices representing the DFS paths.
 *
 * @return Vector of pairs of vertices representing the DFS paths.
 *
 * @complexity Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
 */
vector<pair<string,string>> Graph::dfs(int& maxStops, vector<pair<string,string>>& res) const {
    for (auto v : vertexSet)
        v->setVisited(false);
    for (auto v : vertexSet)
        if (! v->visited)
            dfsVisit(v, res, maxStops, 0, v->getInfo());
    return res;
}


/**
 * @brief Helper function for DFS with a specified maximum number of stops.
 *
 * @param v The current vertex.
 * @param res Vector to store pairs of vertices representing the DFS paths.
 * @param maxStops The maximum number of stops allowed in the DFS.
 * @param stops The current number of stops.
 * @param source The source vertex content.
 *
 * @complexity Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
 */
void Graph::dfsVisit(Vertex *v, vector<pair<string,string>>& res, int& maxStops, int stops, const string &source) const {

    v->setVisited(true);

    if (stops > maxStops) {

        maxStops = stops;

        res.clear();

        res.push_back({source, v->getInfo()});

    } else if (stops == maxStops) {

        res.push_back({source, v->getInfo()});

    }

    for (auto &e: v->adj) {

        auto w = e.dest;

        if (!w->visited)

            dfsVisit(w, res, maxStops, stops + 1, source);

    }
}


void dfs_art(Vertex *v, stack<string> &s, unordered_set<string> &res, int &i);

/**
 * @brief Find articulation points in the graph.
 *
 * @return Set of articulation points.
 *
 * @complexity Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
 */
unordered_set<string> Graph::articulationPoints() const {
    unordered_set<string> res;

    for (auto v : vertexSet)
        v->setVisited(false);

    int i = 0;
    stack<string> s;  // Criar a pilha aqui
    for (auto v : vertexSet) {
        if (!v->isVisited()) {
            dfs_art(v, s, res, i);
        }
    }

    return res;
}

/**
 * @brief Perform a depth-first search to find articulation points.
 *
 * @param v The current vertex.
 * @param s Stack used in the DFS.
 * @param l Set to store articulation points.
 * @param i Counter used in DFS.
 *
 * @complexity Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
 */
void dfs_art(Vertex *v, stack<string> &s, unordered_set<string> &l, int &i){
    v->setVisited(true);
    v->setNum(i);
    v->setLow(i);
    i++;

    int children = 0;
    bool isArticulation = false;

    for (auto &e : v->getAdj()) {
        auto w = e.getDest();

        if (!w->isVisited()) {
            children++;
            s.push(v->getInfo());
            s.push(w->getInfo());

            w->setNum(i);
            w->setLow(i);
            i++;

            dfs_art(w, s, l, i);

            v->setLow(min(v->getLow(), w->getLow()));

            if ((v->getNum() == 0 && children > 1) || (v->getNum() != 0 && w->getLow() >= v->getNum())) {
                isArticulation = true;
            }

            if (w->getLow() > v->getNum()) {
                l.insert(v->getInfo());
            }
        } else if (w->getInfo() != s.top()) {
            v->setLow(min(v->getLow(), w->getNum()));
            s.push(w->getInfo());
        }
    }

    if (v->getNum() == 0 && children > 1) {
        isArticulation = true;
    }

    if (isArticulation) {
        l.insert(v->getInfo());
    }
}

/**
     * @brief Find the shortest path between two vertices using BFS.
     *
     * @param source The source vertex.
     * @param destination The destination vertex.
     *
     * @return Vector of vertex contents representing the shortest path.
     *
     * @complexity Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
     */
vector<string> Graph::shortestPathBFS(const string &source, const string &destination) const {
    unordered_map<string, string> prev;
    queue<string> queue;
    unordered_set<string> visited;

    queue.push(source);
    visited.insert(source);

    while (!queue.empty()) {
        string node = queue.front();
        queue.pop();

        if (node == destination) {
            vector<string> path;
            for (string s = destination; !s.empty(); s = prev[s]) {
                path.push_back(s);
            }
            reverse(path.begin(), path.end());
            return path;
        }

        Vertex* vertex = findVertex(node);
        for (const Edge& edge : vertex->getAdj()) {
            string neighbour = edge.getDest()->getInfo();
            if (visited.find(neighbour) == visited.end()) {
                queue.push(neighbour);
                visited.insert(neighbour);
                prev[neighbour] = node;
            }
        }
    }

    return {};
}

/**
 * @brief Find the shortest path between two vertices using BFS with selected airlines.
 *
 * @param source The source vertex.
 * @param destination The destination vertex.
 * @param selectedAirlines Vector of selected airlines.
 *
 * @return Vector of vertex contents representing the shortest path.
 *
 * @complexity Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
 */
vector<string> Graph::shortestPathBFS(const string &source, const string &destination,const vector<string> &selectedAirlines) const {
    unordered_map<string, string> prev;
    queue<string> queue;
    unordered_set<string> visited;

    queue.push(source);
    visited.insert(source);

    while (!queue.empty()) {
        string node = queue.front();
        queue.pop();

        if (node == destination) {
            vector<string> path;
            for (string at = destination; at != ""; at = prev[at]) {
                path.push_back(at);
            }
            reverse(path.begin(), path.end());
            return path;
        }

        Vertex* vertex = findVertex(node);
        for (const Edge& edge : vertex->getAdj()) {
            string neighbour = edge.getDest()->getInfo();
            string airline = edge.airline;

            if (visited.find(neighbour) == visited.end() && find(selectedAirlines.begin(), selectedAirlines.end(), airline) != selectedAirlines.end()) {
                queue.push(neighbour);
                visited.insert(neighbour);
                prev[neighbour] = node;
            }
        }
    }

    return vector<string>();
}


/**
 * @brief Calculate the diameter of the graph, which is the maximum distance between any two vertices.
 *
 * @return The diameter of the graph.
 *
 * @complexity Time Complexity: O(V * (V + E)), where V is the number of vertices and E is the number of edges.
 */
int Graph::calculateDiameter() const {
    int diameter = 0;

    for (auto v : vertexSet) {
        unordered_set<string> visited;
        bfsVisitForDiameter(v, diameter, visited);
    }

    return diameter;
}
/**
 * @brief Helper function for BFS to calculate the diameter of the graph.
 *
 * @param start The starting vertex for BFS.
 * @param diameter Reference to the variable storing the current diameter.
 * @param visited Set of visited vertices.
 *
 * @complexity Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
 */
void Graph::bfsVisitForDiameter(Vertex* start, int& diameter, unordered_set<string>& visited) const {
    queue<pair<Vertex*, int>> queue;

    queue.push({start, 0});
    visited.insert(start->getInfo());

    while (!queue.empty()) {
        auto front = queue.front();
        Vertex* v = front.first;
        int currentDistance = front.second;
        queue.pop();

        for (auto& e : v->adj) {
            auto w = e.dest;
            if (visited.find(w->getInfo()) == visited.end()) {
                queue.push({w, currentDistance + 1});
                visited.insert(w->getInfo());
            }
        }

        if (currentDistance > diameter) {
            diameter = currentDistance;
        }
    }
}
