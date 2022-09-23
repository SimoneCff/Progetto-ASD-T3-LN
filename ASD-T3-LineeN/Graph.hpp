//
//  Graph.h
//  ASD-T3-LineeN
//
//  Created by Simone Cioffi on 11/06/22.
//

#ifndef Graph_hpp
#define Graph_hpp

#include "Edge.hpp"
#include "Vertex.hpp"
#include "DisjoinSets.hpp"
#include <algorithm>
#include <queue>
#include <iostream>

template <class T> class Graph {
private:
    vector<Vertex<T> *> * Vertices; //Vettore dei Vertici
    vector<Edge<T>* > * Edges ;// vettore dei archi
    
    //Set Privati
    void setVertices(vector<Vertex<T> *> * NVert);
    void setEdges(vector<Edge<T>* > * NEdg);
    
public:
    Graph() {
        setVertices(new vector<Vertex<T> *>);
        setEdges(new vector<Edge<T> *>);
    }
    
    ~Graph() {
        for (int i=0; i<getVertices()->size(); i++) delete getVertices()->at(i); //Cancellazione Vertici
        getVertices()->clear();
        delete getVertices();
        
        for (int i=0; i<getEdges()->size(); i++) delete getEdges()->at(i); //Cancellazione Archi
        getEdges()->clear();
        delete getEdges();
        Vertex<T> * searchVertex(int id);
    }
    
    vector<Vertex<T> *> * getVertices();
    vector<Edge<T> *> * getEdges();
    
    Vertex<T> * searchVertex(int id);
    
    void addVertex(Vertex<T> * Nvertex);
    void addEdge(Edge<T> * Nedge);
    bool findEdge(Edge<T> * FEdge);
    Edge<T> * findEdgeID(int i, int j);
    void delEdge(Edge<T> * Nedge);
    
//   void MST_Prim(Vertex<T> * r);
    void MST_Kruskal();
    void MST_SKruskal();
    
};

template <class T> void Graph<T>::setVertices(vector<Vertex<T> *> * NVert) {
    this->Vertices=NVert;
}

template <class T> void Graph<T>::setEdges(vector<Edge<T>* > * NEdg) {
    this->Edges=NEdg;
}


template <class T> vector<Vertex<T> *> * Graph<T>::getVertices() {
    return this->Vertices;
}

template <class T> vector<Edge<T> *> * Graph<T>::getEdges() {
    return this->Edges;
}


template <class T> void Graph<T>::addVertex(Vertex<T> * Nvertex){
    this->Vertices->push_back(Nvertex);
}

template <class T> void Graph<T>::addEdge(Edge<T> * Nedge){
    //Add new Edge inside Vertex
    this->Edges->push_back(Nedge);
    //Add Dest inside adj of Source
    Nedge->getSource()->InsertADJ(Nedge->getDestination());
}

template <class T> bool Graph<T>::findEdge(Edge<T> * FEdge){
    for (auto& Edge : *(getEdges())) {
        if (Edge == FEdge){
            return true;
        }
    }
    return false;
}

template <class T> void Graph<T>::delEdge(Edge<T> * Nedge){
    //remove edge from adjlist of source
    Nedge->getSource()->DeleteEdge(Nedge->getDestination());
    
    //Remove edge from vector
    getEdges()->erase(getEdges()->begin()+Nedge->getID()-1);
    delete Nedge;
}

template <class T> Vertex<T> * Graph<T>::searchVertex(int id){
    //essendo l'id la posizione nel vettore
    return this->Vertices->at(id);
}

template <class T> void Graph<T>::MST_Kruskal(){
    int size = getVertices()->size();
    DisjoinSets<int> dist = *new DisjoinSets<int>(size);
    vector<Edge<T> *> A = *new vector<Edge<T>*>;
    int Totalw = 0;
    int secondw = 0;
    int tempw;
    
    for (auto& v: *getVertices()){
        dist.make_set(v->getData());
    }
    
    sort(getEdges()->begin(),getEdges()->end(),[] (Edge<T> * v1,Edge<T> * v2 ){
        return v1->getWeight() < v2->getWeight();
    });
    
    
    for (auto& e: *getEdges()){
        if (dist.Find_set(e->getSource()->getData()) != dist.Find_set( e->getDestination()->getData())){
            A.push_back(e);
            dist.Union(e->getSource()->getData(), e->getDestination()->getData());
            Totalw = Totalw + e->getWeight();
        }
    }
    //Print Albero e costo
    cout << "MST : con costo minore"<< endl;
    for (auto& x: A){
        cout << x->getSource()->getID() << "-> " << x->getDestination()->getID() << "; ";
    }
    
    cout << "= "<< Totalw << endl;
    
    //Secondo MST
    vector<Edge<T> *> B = A;
    Edge<T> * removedEdge;
    queue <Edge<T> *> SecMST;

    //Popolamento Queue
    for(auto&a : B){
        SecMST.push(a);
    }
    
    //Check Secondo MST
    while(!SecMST.empty()){
        Edge<T> * u = SecMST.front();
        SecMST.pop();
        tempw = Totalw - u->getWeight();
        if(tempw < secondw) {
            secondw=tempw;
            removedEdge=u;
            }
        }
    //Rimozione Edge
    B.erase(remove(B.begin(),B.end(),removedEdge), B.end());
    
    cout << "MST : con costo succesivo "<< endl;
    for (auto& x: B){
        cout << x->getSource()->getID() << "->" << x->getDestination()->getID() << "; ";
    }
    
    cout << "= "<< secondw << endl;

}


#endif /* Graph_h */

