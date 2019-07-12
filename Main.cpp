#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()


using namespace std;

vector <string> modelli;
vector <string> nomi;
vector <string> produttori;
vector <string> tipo;

string crea() {
	string a = "(";
	int r = (rand() % modelli.size());
	int r0 = (rand() % tipo.size());
	int r1 = (rand() % produttori.size());

	string b = (r % 2) == 0 ? "false" : "true";
	string c = (r0 % 2) == 0 ? "false" : "true";
	string d = c == b ? "false" : "true";
	a = a + modelli.at(r) + "," + produttori.at(r1) + "," + tipo.at(r0) + "," + c + "," + b + ", " + d + "," + to_string((rand() % 200) + 100) + "X" + to_string((rand() % 200) + 400) + "X" + to_string((rand() % 200) + 100) + "," + to_string((rand() % 930) + 70) + "CV," + to_string((rand() % 3) + 2) + "," + to_string((rand() % 3) + 2) + "," + to_string((rand() % 100) + 100) + "," + to_string((rand() % 20) + 10);
	a = a;
	return a+")";
}

int main() {
	srand(time(0));
	ifstream myfile, myfile2, myfile3, myfile4;
	myfile.open("C:\\Users\\Nazmul\\Desktop\\produttore.txt");
	myfile2.open("C:\\Users\\Nazmul\\Desktop\\modello.txt");
	myfile3.open("C:\\Users\\Nazmul\\Desktop\\name.txt");
	myfile4.open("C:\\Users\\Nazmul\\Desktop\\type.txt");


	string line;
	while (getline(myfile, line))
	{
		produttori.push_back(line);
	}
	while (getline(myfile2, line))
	{
		modelli.push_back(line);
	}
	while (getline(myfile3, line))
	{
		nomi.push_back(line);
	}
	while (getline(myfile4, line))
	{
		tipo.push_back(line);
	}
	string b="INSERT INTO carsharing.modello(nome, produttore, tipo, servosterzo, airbag, ac, dimensioni, motorizzazione, nporte, nposti, vmax, consumoav) VALUES";
	for(int i = 0; i<100; ++i)
		b+=crea()+",\n";
	cout << b;

	return 0;
}