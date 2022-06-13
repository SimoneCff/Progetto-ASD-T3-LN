//
//  main.cpp
//  ASD-T3-LineeN
//
//  Created by Simone Cioffi on 11/06/22.
//

#include <iostream>
#include "Graph.hpp"
#include "Converter.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Converter<int> conv;
    Graph<int> * graph = new Graph<int>;
    conv.InitGraph(graph);
    
    cout << "Grafo Inizializzato :" << "\n" << endl;
    
    for (auto& vert : *graph->getVertices()){
        cout << "Vertice : " << vert->getData() << " ID: " << vert->getID() << endl;
    }
    cout << endl;
    
    for (auto& node: *graph->getEdges()){
        cout << "Arco: " << node->getSource()->getData() << "-" << node->getDestination()->getData() << " w: " << node->getWeight() << endl;
    }
    cout << endl;
    
    graph->MST_Kruskal();
}
