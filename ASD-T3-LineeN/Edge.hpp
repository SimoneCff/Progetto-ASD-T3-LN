//
//  Edge.h
//  ASD-T3-LineeN
//
//  Created by Simone Cioffi on 11/06/22.
//

#ifndef Edge_hpp
#define Edge_hpp

template <class T> class Vertex;

template <class T> class Edge {
private:
    int ID;
    int weight;
    Vertex<T> * source; //vertice d'inizio dell'arco
    Vertex<T> * destination; //Vertice di destinazione
    
    //Metodi set privati, accessibili solo dal builder
    void setSource(Vertex<T> * newSource);
    void setDestination(Vertex<T> * newDestination);
    void setWeight(int nw);
public:
    //Builder
    Edge(Vertex<T> * S, Vertex<T> * D, int NID, int nw) {
        setSource(S);
        setDestination(D);
        setWeight(nw);
        this->ID=NID;
    }
    
    // Destroyer
    ~Edge() { }
    
    //metodi get publici
    Vertex <T> * getSource();
    Vertex <T> * getDestination();
    int getID();
    int getWeight();

    
};

template <class T> void Edge<T>::setSource(Vertex<T> * newSource) {
    this->source=newSource;
}

template <class T> void Edge<T>::setDestination(Vertex<T> * newDestination) {
    this->destination=newDestination;
}

template <class T> Vertex <T> * Edge<T>::getSource(){
    return this->source;
    
}

template <class T> Vertex <T> * Edge<T>::getDestination(){
    return this->destination;
}

template <class T> int Edge<T>::getID(){
    return this->ID;
}

template <class T> void Edge<T>::setWeight(int nw){
    this->weight=nw;
}

template <class T> int Edge<T>::getWeight(){
    return this->weight;
}


#endif /* Edge_h */
