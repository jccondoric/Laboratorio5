#include<iostream>
#include<list>
#include<vector>
#include <ctime> //para funciones como clock 

using namespace std;

class Persona {

public:

	Persona(int ci, int altura, int peso) {
		this->ci = ci;
		this->altura = altura;
		this->peso = peso;
	};

	int ci;
	int altura;
	int peso;
};
int main() {

	vector<Persona*> vPersonas; //Creando vector Persona
	list<Persona*> lPersonas; //Creando lista Persona

	unsigned t0 = clock(); //Inicio para medir la ejucion vector

	for (int idx = 1; idx <= 100; idx++) { //LLenado el vector y la Lista

		Persona* p = new Persona(rand() % (100 - 1 + 1) + 1, rand() % (100 - 1 + 1) + 1, rand() % (100 - 1 + 1) + 1);
		vPersonas.push_back(p);

		Persona* l = new Persona(rand() % (100 - 1 + 1) + 1, rand() % (100 - 1 + 1) + 1, rand() % (100 - 1 + 1) + 1);
		lPersonas.push_back(l);
	}

	for (int i = 0; i < vPersonas.size(); i++) {//Imprimiendo el contenido del Vector
		cout << "Persona " << i << " su CI es: " << vPersonas[i]->ci << endl;
		cout << "Persona " << i << " su Altura es: " << vPersonas[i]->altura << endl;
		cout << "Persona " << i << " su Peso es: " << vPersonas[i]->peso << endl;
	}
	unsigned t1 = clock();//Final para medir ejecucion vector

	//codigo que calcula la ejecucion de una parte del codigo Vector
	double time = (double(t1 - t0) / CLOCKS_PER_SEC);

	unsigned t2 = clock();//Inicio para medir la ejucion de la Lista

	////////////////////////////////////////////////////////
	for (int i = 0; i < lPersonas.size(); i++) {
		cout << "persona " << i << " su CI es: " << vPersonas[i]->ci << endl;
		cout << "persona " << i << " su altura es: " << vPersonas[i]->altura << endl;
		cout << "persona " << i << " su peso es: " << vPersonas[i]->peso << endl;
	}
	//En esta parte del codigo:
	//Cambiando vPersonas por lPersonas no funciona sale un error(tendria que ser lPersonas), deberia funcionar ya que ahi estamos
	//llenado con valores random lPersonas , si no  se cambia entonces es como estarimos  utlizando el mismo codigo de la linea
	//38

	unsigned t3 = clock();//Final para medir ejecucion de la Lista

	//codigo que calcula la ejecucion de una parte del codigo Lista
	double time1 = (double(t3 - t2) / CLOCKS_PER_SEC);

	cout << "tiempo de Ejecucion: " << time << " en llenar el vector" << endl;//cuanto tardo ejecucion de vector
	cout << "tiempo de Ejecucion: " << time1 << " en llenar la lista" << endl;//cuanto tardo ejecucion de Lista


	system("pause");
	return 0;

};


