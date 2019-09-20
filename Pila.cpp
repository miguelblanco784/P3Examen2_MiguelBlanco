#include <iostream>
#include <iomanip>
#include <string.h>
#include <vector>
#include <bits/stdc++.h>
#include <typeinfo>
#include <string>
#include <fstream>
#include "Nodo.cpp"


#ifndef PILA_CPP
#define PILA_CPP
using namespace std;
class Pila{
	private:
		Nodo* head;
	public:
		Pila(){
			head = NULL;
		}
		
		void push(string data){
			if(head == NULL){
				head = new Nodo(data);
			} else {
				Nodo* nodo = new Nodo(data);
				nodo->setNodo(head);
				head = nodo;
			}
		}
		
		Nodo* pop(){
			Nodo* temp = head;
			head = head->getNodo();
			return temp;
		}
		
		Nodo* top(){
			return head;
		}
		
		bool isEmpty(){
			if(head == NULL){
				return true;
			} else {
				return false;
			}
		}
};
#endif
