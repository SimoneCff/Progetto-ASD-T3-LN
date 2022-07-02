//
//  main.cpp
//  ASD-T3-LineeN
//
//  Created by Simone Cioffi on 11/06/22.
//

/*
    Per abilitare l'abilità di lettura del file all'interno della cartella del progetto si deve andare su:
        Product -> Scheme -> Edit Scheme.
    Dopodiche  poi selezionare : Run -> Options -> Use custom working directory e selezionare la cartella nella quale è situato il file di input.txt
 */


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
