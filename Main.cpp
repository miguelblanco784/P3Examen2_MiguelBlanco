#include <iostream>
#include <iomanip>
#include <string.h>
#include <vector>
#include <bits/stdc++.h>
#include <typeinfo>
#include <string>
#include <fstream>
#include "Pila.cpp"

using namespace std;

vector<string> separacion(string expresion);
int metodoevaluar(Pila* pila);

int main(){
	Pila* pila = new Pila();
	while(true){
		string expresionaritmetica;
		cout<<"Ingrese la expresion: ";
		cin>> expresionaritmetica;
		vector<string> listado;
		listado = separacion(expresionaritmetica);
		
		int p = listado.size();
		
		for(int i = 0; i < listado.size();i++){
			pila->push(listado.at(i));
		}
		
		
		int evaluar = metodoevaluar(pila);
		cout<<evaluar<<endl;
		
		char resp;
		cout<<"Desea continuar (s/n): ";
		cin>>resp;
		if(resp != 's'){
			exit(0);
		}	
	}
	return 0;
}

vector<string> separacion(string expresion){
	vector<string> temp;
	int recibidor = 0;
	int hasta;
	for(int i = 0; i < expresion.size(); i++){
		switch(expresion[i]){
			case '+':{
				hasta = i;
				temp.push_back(expresion.substr(recibidor,hasta-recibidor));
				temp.push_back("+");
				recibidor = hasta+1;
				break;
			}
			case '-':{
				hasta = i;
				temp.push_back("-"+expresion.substr(recibidor,hasta-recibidor));
				temp.push_back("+");
				recibidor = hasta+1;
				break;
			}
			case '/':{
				hasta = i;
				temp.push_back(expresion.substr(recibidor,hasta-recibidor));
				temp.push_back("/");
				recibidor = hasta+1;
				break;
			}
			case '*':{
				hasta = i;
				temp.push_back(expresion.substr(recibidor,hasta-recibidor));
				temp.push_back("*");
				recibidor = hasta+1;
				break;
			}
			default:{
				
				break;
			}
		}
	}
	temp.push_back(expresion.substr(recibidor,hasta-recibidor));
	return temp;
}

int metodoevaluar(Pila* pila){
	int acum;
	while(true){
	//for(int i = 0; i < tam; i++){
		int opa, opc;
		string opb;
		
		opa = atoi(pila->pop()->getData().c_str());
		acum = opa;
		if(pila->isEmpty() == NULL){
			opb = pila->pop()->getData();
			opc = atoi(pila->pop()->getData().c_str());
			
			char temp;
			temp = opb[0];
			switch(temp){
				int result;
				case '+':{
					result = opa+opc;
					stringstream bb;
					bb << result;
					pila->push(bb.str());
					break;
				}
				case '/':{
					result = opa/opc;
					stringstream bb;
					bb << result;
					pila->push(bb.str());
					break;
				}
				case '*':{
					result = opa*opc;
					stringstream bb;
					bb << result;
					pila->push(bb.str());
					break;
				}
			}			
		}else{
			break;
		}
 
	}
	return acum;
}
