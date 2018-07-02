#include "Matrice3D.h"

///////////////////////////////////////////////////////////////////////////////////////////////

float convertiEAggiungiMezzo(const int& a) {
	return (float)(a)+0.5f;
}

float convertiEAggiungiMezzoD(const double& a) {
	return (float)(a)+0.5f;
}

int convertiAint(const char& a) {
	return (int)(a);
}

///////////////////////////////////////////////////////////////////////////////////////////////

//class Persona
class persona{

public:
	string nome;
	int anni;
	char genere;

	persona():nome(""),anni(0),genere(0){
	}

	persona(string nome,int anni,char genere){
		this->nome=nome;
		this->anni=anni;
		this->genere=genere;
	}
	
	~persona() {
		nome = "";
		anni = 0;
		genere= 0;
	}
		
};

///////////////////////////////////////////////////////////////////////////////////////////////

//class Studente
class studente{

public:
	string nome;
	int anni,matricola;
	char genere;

	studente():nome(""),anni(0),genere(0),matricola(0){
	}

	studente(string nome,int anni,char genere,int matricola){
		this->nome=nome;
		this->anni=anni;
		this->genere=genere;
		this->matricola=matricola;
	}
	
	~studente() {
		nome = "";
		anni = 0;
		genere= 0;
		matricola=0;
	}
		
};

///////////////////////////////////////////////////////////////////////////////////////////////

//Conversione da Persona a Studente
studente convertiAstudente(const persona& a) {
	studente s;
	s.nome=a.nome;
	s.anni=a.anni;
	s.genere=a.genere;
	s.matricola=000000;

	return s;
}

///////////////////////////////////////////////////////////////////////////////////////////////

//Test Char
void testchar(){

	Matrice3D<char>a1(2, 2, 2);
	a1(1, 1, 1) = 'c';
	a1(0, 0, 0) = 'b';
	a1(0, 1, 1) = 'n';
	a1(1, 1, 0) = 's';
	cout<<"valore ottenuto tramite operator() prima matrice :"<<endl<<a1(1,1,0)<<endl;
	Matrice3D<char>a2 = a1;
	cout<<"valore ottenuto tramite operator() matrice copiata :"<<endl<<a2(1,1,0)<<endl;
	Matrice2D<char>am1 = a1.slice(0);
	cout<<"valore ottenuto tramite operator() matrice slice :"<<endl<<am1(1,1)<<endl;
	Matrice3D<int>a3(a2);
	cout<<"valore ottenuto tramite operator() matrice int convertita :"<<endl<<a1(1,1,0)<<endl;

	cout << "=================================" << endl;

	cout << "Stampa matrice slice 2D tramite Iteratori" << endl;

	cout << "=================================" << endl;
	Matrice2D<char>::const_iterator itm;
	for (itm = am1.cbegin(); itm != am1.cend(); itm++) {
		cout << " Matrix 2D ConstIt ++ = " << *(itm) << endl;
	}

	cout << "=================================" << endl;

	cout << "Stampa matrice 3D 'int convertita' tramite Iteratori" << endl;

	cout << "=================================" << endl;
	Matrice3D<int>::const_iterator itd;
	for (itd = a3.cbegin(); itd != a3.cend(); itd++) {
	cout << " Matrix 3D ConstIt int ++ = " << *(itd) << endl;
	}

	cout << "=================================" << endl;

	cout << "Stampa prima matrice 3D tramite Iteratori ++" << endl;

	cout << "=================================" << endl;
	Matrice3D<char>::const_iterator itc;
	for (itc = a1.cbegin(); itc != a1.cend(); itc++) {
		cout << " Matrix 3D ConstIt ++ = " << *(itc) << endl;
	}

	cout << "=================================" << endl;

	cout << "Stampa prima matrice 3D tramite Iteratori --" << endl;

	cout << "=================================" << endl;
	for (itc = a1.cend(); itc != a1.cbegin(); itc--) {
		if (itc != a1.cend()) {
			cout << " Matrix 3D ConstIt -- = " << *(itc) << endl;
		}
	}
	cout << " Matrix 3D ConstIt -- = " << *(itc) << endl;

	cout << "=================================" << endl;

	cout << "Stampa funzione trasforma" << endl;

	cout << "=================================" << endl;
	Matrice3D<int> BBB = trasforma<char, int>(a1, &convertiAint);
	cout << "Matrice input:" << endl;
	Matrice3D<char>::const_iterator itc1;
	for (itc1 = a1.cbegin(); itc1 != a1.cend(); itc1++) {
		if (itc1 != a1.cend()) {
			cout << *(itc1) << endl;
		}
	}

	cout << "Matrice Trasformata:" << endl;
	Matrice3D<int>::const_iterator itc2;
	for (itc2 = BBB.cbegin(); itc2 != BBB.cend(); itc2++) {
		cout << *(itc2) << endl;
	}

}

///////////////////////////////////////////////////////////////////////////////////////////////

//Test Int
void testInt(){

	Matrice3D<int>a1(2, 2, 2);
	a1(1, 1, 1) = 2;
	a1(0, 0, 0) = 8;
	a1(0, 1, 1) = 3;
	a1(1, 1, 0) = 10;
	cout<<"valore ottenuto tramite operator() prima matrice :"<<endl<<a1(1,1,0)<<endl;
	Matrice3D<int>a2 = a1;
	cout<<"valore ottenuto tramite operator() matrice copiata :"<<endl<<a2(1,1,0)<<endl;
	Matrice2D<int>am1 = a1.slice(0);
	cout<<"valore ottenuto tramite operator() matrice slice :"<<endl<<am1(1,1)<<endl;
	Matrice3D<float>a3(a2);
	cout<<"valore ottenuto tramite operator() matrice Float convertita :"<<endl<<a1(1,1,0)<<endl;

	cout << "=================================" << endl;

	cout << "Stampa matrice slice 2D tramite Iteratori" << endl;

	cout << "=================================" << endl;
	Matrice2D<int>::const_iterator itm;
	for (itm = am1.cbegin(); itm != am1.cend(); itm++) {
		cout << " Matrix 2D ConstIt ++ = " << *(itm) << endl;
	}

	cout << "=================================" << endl;

	cout << "Stampa matrice 3D 'Float convertita' tramite Iteratori" << endl;

	cout << "=================================" << endl;
	Matrice3D<float>::const_iterator itd;
	for (itd = a3.cbegin(); itd != a3.cend(); itd++) {
	cout << " Matrix 3D ConstIt Float ++ = " << *(itd) << endl;
	}

	cout << "=================================" << endl;

	cout << "Stampa prima matrice 3D tramite Iteratori ++" << endl;

	cout << "=================================" << endl;
	Matrice3D<int>::const_iterator itc;
	for (itc = a1.cbegin(); itc != a1.cend(); itc++) {
		cout << " Matrix 3D ConstIt ++ = " << *(itc) << endl;
	}

	cout << "=================================" << endl;

	cout << "Stampa prima matrice 3D tramite Iteratori --" << endl;

	cout << "=================================" << endl;
	for (itc = a1.cend(); itc != a1.cbegin(); itc--) {
		if (itc != a1.cend()) {
			cout << " Matrix 3D ConstIt -- = " << *(itc) << endl;
		}
	}
	cout << " Matrix 3D ConstIt -- = " << *(itc) << endl;

	cout << "=================================" << endl;

	cout << "Stampa funzione trasforma" << endl;

	cout << "=================================" << endl;
	Matrice3D<float> BBB = trasforma<int, float>(a1, &convertiEAggiungiMezzo);
	cout << "Matrice input:" << endl;
	Matrice3D<int>::const_iterator itc1;
	for (itc1 = a1.cbegin(); itc1 != a1.cend(); itc1++) {
		if (itc1 != a1.cend()) {
			cout << *(itc1) << endl;
		}
	}

	cout << "Matrice Trasformata:" << endl;
	Matrice3D<float>::const_iterator itc2;
	for (itc2 = BBB.cbegin(); itc2 != BBB.cend(); itc2++) {
		cout << *(itc2) << endl;
	}

}

///////////////////////////////////////////////////////////////////////////////////////////////

//Test Double
void testdouble(){

	Matrice3D<double>a1(2, 2, 2);
	a1(1, 1, 1) = 2;
	a1(0, 0, 0) = 8;
	a1(0, 1, 1) = 3;
	a1(1, 1, 0) = 10;
	cout<<"valore ottenuto tramite operator() prima matrice :"<<endl<<a1(1,1,0)<<endl;
	Matrice3D<double>a2 = a1;
	cout<<"valore ottenuto tramite operator() matrice copiata :"<<endl<<a2(1,1,0)<<endl;
	Matrice2D<double>am1 = a1.slice(0);
	cout<<"valore ottenuto tramite operator() matrice slice :"<<endl<<am1(1,1)<<endl;
	Matrice3D<float>a3(a2);
	cout<<"valore ottenuto tramite operator() matrice Float convertita :"<<endl<<a1(1,1,0)<<endl;

	cout << "=================================" << endl;

	cout << "Stampa matrice slice 2D tramite Iteratori" << endl;

	cout << "=================================" << endl;
	Matrice2D<double>::const_iterator itm;
	for (itm = am1.cbegin(); itm != am1.cend(); itm++) {
		cout << " Matrix 2D ConstIt ++ = " << *(itm) << endl;
	}

	cout << "=================================" << endl;

	cout << "Stampa matrice 3D 'Float convertita' tramite Iteratori" << endl;

	cout << "=================================" << endl;
	Matrice3D<float>::const_iterator itd;
	for (itd = a3.cbegin(); itd != a3.cend(); itd++) {
	cout << " Matrix 3D ConstIt Float ++ = " << *(itd) << endl;
	}

	cout << "=================================" << endl;

	cout << "Stampa prima matrice 3D tramite Iteratori ++" << endl;

	cout << "=================================" << endl;
	Matrice3D<double>::const_iterator itc;
	for (itc = a1.cbegin(); itc != a1.cend(); itc++) {
		cout << " Matrix 3D ConstIt ++ = " << *(itc) << endl;
	}

	cout << "=================================" << endl;

	cout << "Stampa prima matrice 3D tramite Iteratori --" << endl;

	cout << "=================================" << endl;
	for (itc = a1.cend(); itc != a1.cbegin(); itc--) {
		if (itc != a1.cend()) {
			cout << " Matrix 3D ConstIt -- = " << *(itc) << endl;
		}
	}
	cout << " Matrix 3D ConstIt -- = " << *(itc) << endl;

	cout << "=================================" << endl;

	cout << "Stampa funzione trasforma" << endl;

	cout << "=================================" << endl;
	Matrice3D<float> BBB = trasforma<double, float>(a1, &convertiEAggiungiMezzoD);
	cout << "Matrice input:" << endl;
	Matrice3D<double>::const_iterator itc1;
	for (itc1 = a1.cbegin(); itc1 != a1.cend(); itc1++) {
		if (itc1 != a1.cend()) {
			cout << *(itc1) << endl;
		}
	}

	cout << "Matrice Trasformata:" << endl;
	Matrice3D<float>::const_iterator itc2;
	for (itc2 = BBB.cbegin(); itc2 != BBB.cend(); itc2++) {
		cout << *(itc2) << endl;
	}

}

///////////////////////////////////////////////////////////////////////////////////////////////

//Override operator <<
std::ostream &operator<<(std::ostream &os, const persona &p){
  std::cout<<"("<<p.nome<<","<<p.anni<<","<<p.genere<<")";
  return os;
}

std::ostream &operator<<(std::ostream &os, const studente &p){
  std::cout<<"("<<p.nome<<","<<p.anni<<","<<p.genere<<","<<p.matricola<<")";
  return os;
}

///////////////////////////////////////////////////////////////////////////////////////////////

//Test Persona
void testpersona(){

	Matrice3D<persona>a1(2, 2, 2);
	a1(1, 1, 1) = persona("antonio", 20, 'M');
	a1(0, 0, 0) = persona("amilcare", 24, 'M');
	a1(0, 1, 1) = persona("giulia", 24, 'F');
	a1(1, 1, 0) = persona("sara", 25, 'F');
	cout<<"valore ottenuto tramite operator() prima matrice :"<<endl<<a1(1,1,0)<<endl;
	Matrice3D<persona>a2 = a1;
	cout<<"valore ottenuto tramite operator() matrice copiata :"<<endl<<a2(1,1,0)<<endl;
	Matrice2D<persona>am1 = a1.slice(0);
	cout<<"valore ottenuto tramite operator() matrice slice :"<<endl<<am1(1,1)<<endl;

	cout << "=================================" << endl;

	cout << "Stampa matrice slice 2D tramite Iteratori" << endl;

	cout << "=================================" << endl;
	Matrice2D<persona>::const_iterator itm;
	for (itm = am1.cbegin(); itm != am1.cend(); itm++) {
		cout << " Matrix 2D ConstIt ++ = " << *(itm) << endl;
	}

	cout << "=================================" << endl;

	cout << "Stampa prima matrice 3D tramite Iteratori ++" << endl;

	cout << "=================================" << endl;
	Matrice3D<persona>::const_iterator itc;
	for (itc = a1.cbegin(); itc != a1.cend(); itc++) {
		cout << " Matrix 3D ConstIt ++ = " << *(itc) << endl;
	}

	cout << "=================================" << endl;

	cout << "Stampa prima matrice 3D tramite Iteratori --" << endl;

	cout << "=================================" << endl;
	for (itc = a1.cend(); itc != a1.cbegin(); itc--) {
		if (itc != a1.cend()) {
			cout << " Matrix 3D ConstIt -- = " << *(itc) << endl;
		}
	}
	cout << " Matrix 3D ConstIt -- = " << *(itc) << endl;

	cout << "=================================" << endl;

	cout << "Stampa funzione trasforma" << endl;

	cout << "=================================" << endl;
	Matrice3D<studente> BBB = trasforma<persona, studente>(a1, &convertiAstudente);
	cout << "Matrice input:" << endl;
	Matrice3D<persona>::const_iterator itc1;
	for (itc1 = a1.cbegin(); itc1 != a1.cend(); itc1++) {
		if (itc1 != a1.cend()) {
			cout << *(itc1) << endl;
		}
	}

	cout << "Matrice Trasformata:" << endl;
	Matrice3D<studente>::const_iterator itc2;
	for (itc2 = BBB.cbegin(); itc2 != BBB.cend(); itc2++) {
		cout << *(itc2) << endl;
	}

}
///////////////////////////////////////////////////////////////////////////////////////////////

//Main
int main() {
	testInt();
	testpersona();
	testdouble();
	testchar();
	return 0;
}






