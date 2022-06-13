//
//  DisjoinSets.h
//  ASD-T3-LineeN
//
//  Created by Simone Cioffi on 12/06/22.
//

#ifndef DisjoinSets_hpp
#define DisjoinSets_hpp

#include <vector>

template <class T> class DisjoinSets{
private:
//    si crea una classe per gli insieme disguinti contenete i vettori dei rank e dei parent, l' index del vettore coincide con l' id del Vertice
    vector<int> * rank;
    vector<int> * parent;
    
    void setRank(vector<int> * NR);
    void setParent(vector<int> * NP);
    
    vector<int> * getRank();
    vector<int> * getParent();
    
public:
    DisjoinSets(int NV) {
        setRank(new vector<int>(NV, 0));
        setParent(new vector<int>(NV, 0));
        for (int i = 0; i<=NV; i++){
            getRank()->push_back(0);
            getParent()->push_back(i);
        }
    }
    
    void make_set(int x);
    void Union(int x, int y);
    void Link(int x, int y);
    int Find_set(int x);
};

template <class T> void DisjoinSets<T>::setRank(vector<int> * NR){
    this->rank=NR;
}

template <class T> void DisjoinSets<T>::setParent(vector<int> * NP) {
    this->parent=NP;
}

template <class T> vector<int> * DisjoinSets<T>::getRank(){
    return this->rank;
}

template <class T> vector<int> * DisjoinSets<T>::getParent(){
    return this->parent;
}

template <class T> void DisjoinSets<T>::make_set(int x){
    getParent()->at(x) = x;
    getRank()->at(x) = 0;
}

template <class T> void DisjoinSets<T>::Union(int x, int y){
    Link(Find_set(x), Find_set(y));
}

template <class T> void DisjoinSets<T>::Link(int x, int y){
    if (getRank()->at(x) > getRank()->at(y)){
        getParent()->at(y) = x;
    } else {
        getParent()->at(x) = y;
        if (getRank()->at(x)==getRank()->at(y)){
            getRank()->at(y)=getRank()->at(y)+1;
        }
    }
    
}

template <class T> int DisjoinSets<T>::Find_set(int x){
    if (x != getParent()->at(x)){
        getParent()->at(x)=Find_set(getParent()->at(x));
    }
    return getParent()->at(x);
}

#endif /* DisjoinSets_h */
