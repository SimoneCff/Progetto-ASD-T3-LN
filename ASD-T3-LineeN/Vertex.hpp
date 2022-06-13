//
//  Vertex.h
//  ASD-T3-LineeN
//
//  Created by Simone Cioffi on 11/06/22.
//

#ifndef Vertex_hpp
#define Vertex_hpp

#include <vector>
#include <limits>

using namespace std;

template <class T> class Vertex {
private:
    int ID; //Id vertex
    T data; // Dato satellite
    vector<Vertex<T> *> * AdjList; //Lista nodi Adiacenti
    
    void setAdjList(vector<Vertex<T> *> * NewADJ); //Setting Adj
    void setID(int ID);
    void setData(T data);

    
public:
    Vertex(int ID, T data) {
        setID(ID);
        setData(data);
        setAdjList(new vector<Vertex<T> *>);
    }
    
    ~Vertex() {
        delete getAdjList();
    }
    
    vector<Vertex<T> *> * getAdjList();
    int getID();
    T getData();

    
    void InsertADJ(Vertex<T> * Nadj);
    void RemoveADJ(Vertex<T> * Radj);
};

template <class T> void Vertex<T>::setAdjList(vector<Vertex <T> *> * newAdjList) {
    this->AdjList=newAdjList;
}

template <class T> vector<Vertex<T>*> * Vertex<T>::getAdjList(){
    return this->AdjList;
}

template <class T> int Vertex<T>::getID(){
    return this->ID;
}

template <class T> void Vertex<T>::setID(int NID){
    this->ID=NID;
}

template <class T> void Vertex<T>::setData(T Ndata){
    this->data=Ndata;
}

template <class T> void Vertex<T>::InsertADJ(Vertex <T> * NewAdj){
    getAdjList()->push_back(NewAdj);
}

template <class T> void Vertex<T>::RemoveADJ(Vertex<T> * DeleteAdj){
    getAdjList()->erase(getAdjList()->begin()-DeleteAdj->getID()-1);
}

template <class T> T Vertex<T>::getData(){
    return this->data;
}


#endif /* Vertex_h */
