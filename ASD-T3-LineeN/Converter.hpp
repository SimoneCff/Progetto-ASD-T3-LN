//
//  Converter.h
//  ASD-T3-LineeN
//
//  Created by Simone Cioffi on 12/06/22.
//

#ifndef Converter_hpp
#define Converter_hpp
#include <fstream>
#include <string>
#include "Graph.hpp"

template <class T> class Converter{
private:
    fstream file;
    void setFile(string text);
    void checkfile();
    
public:
    Converter(){
        setFile("input0_3_2.txt");
       // setFile("test.txt");
        checkfile();
    }
    
    //Func per convertire il file txt nel popolamento del grafo
    void InitGraph(Graph<T> * graph);
};

template <class T> void Converter<T>::setFile(string text){
    this->file.open(text, ios::in | ios::out);
}

template <class T> void Converter<T>::checkfile(){
    if (this->file.is_open()) {
        cout << "\t File aperto con successo \n" << endl;
    } else{
        //if is not open close all
        cout << "\t Errore Apertura File, uscita in corso" << endl;
        exit(1);
    }
}


template <class T> void Converter<T>::InitGraph(Graph<T> * graph){
    //init file temp
    int n, p; // N vertici, P archi
    cout << "\t Inizializzazione del grafo ..." << endl;

    int i, j, w; // ID Vertici per arco
    int k = 0; // ID archi

    //Conversione file.txt
    this->file.seekg(ios::beg); //posiziono puntatore a inizio file
    this->file >> n >> p; // prendo dalla riga
    if ((n > 1000 || n < 0) || (p> 10000 || p<0)) { //Check assunzioni per gli N vertici e i p archi
        cout << "Numero di Vertici e/o Archi non accettato, chiusura programma" << endl;
        this->file.close();
        exit(4);
      }
    //inserimento N veritic nell' arco
    for (int v = 0; v<=n; v++){ //Si suppone di base che i vertici vanno da 0 fino ad N
        graph->addVertex(new Vertex(v, v));
    }
    
    //Puntatore dalla seconda riga fino a quando non incotra una riga vuota
    this->file.seekg(1,ios::cur);
    while (this->file >> i >> j >> w) { // Fino a quando c'e scritto qualcosa
        if (w < 1 || w >10000) {
            cout << "valore del peso w non accettato, chiusura progrtamma" << endl;
            this->file.close();
            exit(4);
        }
        graph->addEdge(new Edge<T>(graph->searchVertex(i),graph->searchVertex(j),k,w));
        k++;
    }

   cout << "\t Graph inizializzato con successo \n" << endl;

}


#endif /* Converter_h */
