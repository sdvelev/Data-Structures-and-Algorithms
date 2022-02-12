#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct EdgeMade {
    long long fromVertex;
    long long toVertex;
    long long cost;
    long long reward;
    long long index;

    bool operator<(const EdgeMade& rightEdge) const {
        if (this->cost == rightEdge.cost) {
            if(this->reward != rightEdge.reward){
                return this->reward > rightEdge.reward;
            }
        }
        else {
            return this->cost < rightEdge.cost;
        }
        return true;
    }
};

const long long MAX_NUMBER_OF_VERTICES = 200007;

long long numberOfVertices;
long long numberOfEdges;

vector<EdgeMade> edgeListMade;
long long parentArrayMade[MAX_NUMBER_OF_VERTICES];
long long depthArrayMade[MAX_NUMBER_OF_VERTICES];
vector<long long> indexesAnswer;

long long findIfConnected(long long vertex) {
    if (parentArrayMade[vertex] == vertex) {
        return vertex;
    }
    
    long long root = findIfConnected(parentArrayMade[vertex]);
    
    parentArrayMade[vertex] = root;
    
    return root;
}

void uniteDifferentComponents(long long fromVertex, long long toVertex) {

    if (depthArrayMade[fromVertex] > depthArrayMade[toVertex]) {
        parentArrayMade[toVertex] = fromVertex;
    }
    else if(depthArrayMade[fromVertex] < depthArrayMade[toVertex])
    {
        parentArrayMade[fromVertex] = toVertex;
    }
    else {
        parentArrayMade[toVertex] = fromVertex;
        depthArrayMade[fromVertex]++;
    }
}


void kruskalMade() {

    sort(edgeListMade.begin(), edgeListMade.end());

    long long addedEdges = 0;

    for (auto edgeToFollow : edgeListMade) {

        long long fromVertex = edgeToFollow.fromVertex;
        long long toVertex = edgeToFollow.toVertex;

        long long rootFromVertex = findIfConnected(fromVertex);
        long long rootToVertex = findIfConnected(toVertex);

        if (rootFromVertex != rootToVertex) {
            uniteDifferentComponents(rootFromVertex, rootToVertex);
            indexesAnswer.push_back(edgeToFollow.index);
            ++addedEdges;
        }

        if (addedEdges == numberOfVertices - 1) {
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> numberOfVertices;
    cin >> numberOfEdges;

    long long fromVertex;
    long long toVertex;
    long long cost;
    long long reward;
    EdgeMade toAdd;

    for (long long i = 1; i <= numberOfEdges; i++) {
        cin >> fromVertex >> toVertex >> cost >> reward;

        toAdd.fromVertex = fromVertex;
        toAdd.toVertex = toVertex;
        toAdd.cost = cost;
        toAdd.reward = reward;
        toAdd.index = i;
        edgeListMade.push_back(toAdd);
    }

    for (long long i = 1; i <= numberOfVertices; i++) {
        parentArrayMade[i] = i;
        depthArrayMade[i] = 0;
    }

    kruskalMade();

    long long size = indexesAnswer.size();
    
    for (long long i = 0; i < size; i++) {
        printf("%lld\n", indexesAnswer[i]);
    }
    return 0;
}
