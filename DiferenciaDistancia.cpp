#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	struct treeNode{
		int dato;
		treeNode *rightPtr;
		treeNode *leftPtr;
	};
	
	typedef struct treeNode TREENODE;
	typedef TREENODE * TREE;
	
	void insertar (TREE *, int );
	void enOrden (TREE);
	void postOrden (TREE);
	void contar (TREE, int*);
	void altura (TREE, int, int *);
	
	TREE left(TREE nodoLeft){
		return (nodoLeft)->leftPtr;
	}
	
	TREE right(TREE nodoRight){
		return (nodoRight)->rightPtr;
	}
	
	void resultados(){
		cout<<"\n-----------------------------RESULTADOS-----------------------------"<<endl<<endl;
	}

	void hr(){
		cout<<endl;	
	}

void insertar (TREE *treePtr, int valor){
	if  (*treePtr == NULL){
		*treePtr = new (TREENODE);
		if (*treePtr !=NULL){
			(*treePtr)->dato =valor;
			(*treePtr)->leftPtr =NULL;
			(*treePtr)->rightPtr=NULL;
		}else
			cout<<"No hay memoria"<<endl;
		}
		else
		if (valor < (*treePtr)->dato){
			insertar (&((*treePtr)->leftPtr), valor);
		}else 
		if (valor > (*treePtr)->dato){
			insertar (&((*treePtr)->rightPtr), valor);
		}else 
			cout<<"DUPLICADO"<<endl;
	
}

TREE diferenciaDistancia(TREE *treePtr){
	int valorRaiz, valor1, valor2;
	unsigned int result;
	
	TREE rootAux = NULL, treeResultado = NULL , treeResultado2 = NULL;
	rootAux = *treePtr;
	if (treePtr != NULL){
		
		valorRaiz = rootAux->dato;
		
		while(left(rootAux)!=NULL){
			rootAux = left(rootAux);
			valor1 = rootAux->dato;
			treeResultado = rootAux;
		}
		
		rootAux = *treePtr;
		
		while(right(rootAux)!=NULL){
			rootAux = right(rootAux);
			valor2 = rootAux->dato;
			treeResultado2 = rootAux;
		}
		
		result = valorRaiz-valor1;
		
		if((valorRaiz-valor1) < (valor2-valorRaiz)){
			//cout<<"Dato dos"<<endl;
			treeResultado = treeResultado2;
			result = valor2-valorRaiz;
		}
		cout<<"La diferencia: "<<result<<endl<<endl;
	}
	return treeResultado;
}




int main(int argc, char** argv) {
	int x=0, item, n=0, hmax=0, ban=0, him = 999, count = 0, max = 0, valor;
	TREE rootPtr=NULL;
	cout<<"Ingresar un numero, -1: ";
	cin>>item;
	
	while(item!=-1){
		insertar(&rootPtr,item);
		cout<<"Ingresar un numero, -1: ";
		cin>>item;
	}; 
	
	resultados();
	cout<<"La direccion de memoria es: "<<diferenciaDistancia(&rootPtr);
 	hr();
	
	return 1;
	
}


