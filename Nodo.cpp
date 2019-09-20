#include <iostream>
#include <iomanip>
#include <string.h>
#include <vector>
#include <bits/stdc++.h>
#include <typeinfo>
#include <string>
#include <fstream>

#ifndef NODO_CPP
#define NODO_CPP
using namespace std;
class Nodo{
	private:
		string data;
		Nodo* nodo;
	public:
		Nodo(string data){
			this->data = data;
			nodo = NULL;
		}
		
		void setNodo(Nodo* nodo){
			this->nodo = nodo;
		}
		
		Nodo* getNodo(){
			return nodo;
		}
		
		string getData(){
			return data;
		}
};
#endif
