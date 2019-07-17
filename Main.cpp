#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <algorithm> 
#include <cctype>
#include <locale>

using namespace std;

string rtrim(string& s) {
	int last = s.size() - 1;
	while (last >= 0 && s[last] == ' ')
		--last;
	return s.substr(0, last + 1);
}

class chiave {
	public:
		string nome;
		string produttore;
		int porte;

		chiave(string a, string b, int c) {
			nome = a;
			produttore = b;
			porte = c;
		}
};

class giorno {
public:
	int d;
	int m;
	int y;

	giorno(int a, int b, int c) {
		d = a;
		m = b;
		y = c;
	}
};

vector <chiave> validKey_modello;
vector <string> validKey_parcheggio;
vector <string> validKey_vettura;
int utenti_inseriti = 0;

vector <string> tipi;

vector <string> modelli;
vector <string> nomi;
vector <string> cognomi;

vector <string> produttori;
vector <string> indirizzi;
vector <string> zone;


string add(string s) {
	return "'" + s + "'";
}

string add(int n) {
	return to_string(n);
}

string add(bool b) {
	if (b) return "true";
	return "false";
}

string add(giorno d) {
	return "date '" + to_string(d.y) + "-" + to_string(d.m) + "-" +  to_string(d.d) + "'";
}

string create_parcheggio_value() {
	string value = "";
	string par = "Parcheggio " + nomi[rand() % nomi.size()];
	value += add(par) + ", ";
	validKey_parcheggio.push_back(par);
	value += add(zone[rand() % zone.size()]) + ", ";
	value += add((rand() % 20) + 5) + ", ";
	value += add((rand() % 90) ) + ", "; 
	value += add((rand() % 90) ) + ", ";
	value += add(indirizzi[rand() % indirizzi.size()]);
	return value;
}

string rand_colore() {
	switch (rand() % 6) {
		case 0: 
			return "bianco";
		case 1:
			return "nero";
		case 2:
			return "rosso";
		case 3:
			return "blu";
		case 4:
			return "giallo";
		case 5:
			return "verde";
	}
	return "nero";
}



giorno rand_date() {
	int d = (rand() % 29) + 1;
	int m = (rand() % 12) + 1;
	int a = (rand() % 50) + 1960;
	return giorno(d,m,a);
}

string rand_string(int len) {
	string s = "";
	for (int i = 0; i < len; ++i) {
		int randomChar = rand() % (26 + 10);
		if (randomChar < 26)
			s += ('A' + randomChar);
		else
			s += ('0' + randomChar - 26 );
	}
	return s;
}

string rand_cf() {
	string value = "";
	for (int i = 0; i < 6; ++i)
		value += 'A' + (rand() % 26);
	for (int i = 0; i < 2; ++i)
		value += '0' + (rand() % 10);
	value += 'A' + (rand() % 26);
	for (int i = 0; i < 2; ++i)
		value += '0' + (rand() % 10);
	value += 'A' + (rand() % 26);
	for (int i = 0; i < 3; ++i)
		value += '0' + (rand() % 10);
	value += 'A' + (rand() % 26);

	return value;
}

string rand_professione() {
	switch (rand() % 6) {
	case 0:
		return "Impiegato";
	case 1:
		return "Imprenditore";
	case 2:
		return "Studente";
	case 3:
		return "Medico";
	case 4:
		return "Avvocato";
	}
	return "Pizzaiolo";
}

string create_vettura_value() {
	string value = "";
	string vet = nomi[rand() % nomi.size()];
	value += add(vet) + ", ";
	
	chiave mod = validKey_modello[rand() % validKey_modello.size()];
	value += add(mod.nome) + ", ";
	value += add(mod.produttore) + ", ";
	value += add(mod.porte) + ", ";
	value += add(rand_string(7)) + ", ";
	value += add(rand_colore()) + ", ";
	value += add(validKey_parcheggio[rand() % validKey_parcheggio.size()]) + ", ";
	value += add(0) + ", ";
	value += add(rand() % 2 == 0) + ", ";
	value += add(rand() % 2 == 0);

	return value;
}

string create_modello_value() {
	string value = "";
	string mod = modelli[rand() % modelli.size()];
	value += add(mod) + ", ";
	string prod = produttori[rand() % produttori.size()];
	value += add(prod) + ", ";
	
	value += add(tipi[rand() % tipi.size()]) + ", ";
	value += add(rand() % 2 == 0) + ", ";
	value += add(rand() % 2 == 0) + ", ";
	value += add(rand() % 2 == 0) + ", ";
	value += add(to_string((rand() % 200) + 100) + "X" + to_string((rand() % 200) + 400) + "X" + to_string((rand() % 200) + 100)) + ", ";
	value += add(to_string((rand() % 930) + 70) + "CV") + ", ";
	int porte = (rand() % 3) + 2;
	value += add(porte) + ", ";
	value += add((rand() % 3) + 2) + ", ";
	value += add((rand() % 100) + 100) + ", ";
	value += add((rand() % 10));
	validKey_modello.push_back(chiave(mod, prod, porte));
	return value;
}

string create_datianagrafici_value() {
	string value = "";
	value += add(rand_cf()) + ", ";
	value += add(++utenti_inseriti) + ", ";
	value += add(nomi[rand() % nomi.size()]) + ", ";
	value += add(cognomi[rand() % cognomi.size()]) + ", ";
	value += add((string)"Genova") + ", ";
	value += add(rand_date()) + ", ";
	value += add((string)((rand()%2)==0?"M":"F")) + ", ";
	value += add(rand_professione()) + ", ";
	value += add(rand_string(9)) + ", ";
	value += add(rand_string(10)) + ", ";
	value += add((string)"B");
	return value;
}

string create_posti_value() {
	string value = "";
	for (int i = 0; i < validKey_parcheggio.size(); ++i)
		for (int j = 0; j < tipi.size(); ++j)
			value += "("+add(tipi[j]) + ", " + add(validKey_parcheggio[i])+"),\n";
	
	value.erase(value.size() - 1);
	value.erase(value.size() - 1);
	return value;
}

string create_tariffa_value() {
	string value = "";
	for (int i = 0; i < validKey_modello.size(); ++i)
			value += "("+ add(validKey_modello[i].nome) + "," + add(validKey_modello[i].produttore) + "," + add(validKey_modello[i].porte) + ","+ add((rand()%3)+1) + "," + add((rand() % 3) + 1) + "," + add((rand() % 10) + 1) + "," + add((rand() % 10) + 1) + "," + add((rand() % 10) + 1) + "," +	"),\n";

	value.erase(value.size() - 1);
	value.erase(value.size() - 1);
	return value;
}

string create_abbonamento_value() {
	string value = "";
	for (int i = 1; i <= utenti_inseriti; ++i)
		value += "(" + add(i) + "," + add(giorno(1,1,2019)) + "," + add((rand()%9000)+1000) + "," + add((string)"annuale") + "),\n";

	value.erase(value.size() - 1);
	value.erase(value.size() - 1);
	return value;
}

string create_value(string tabella) {
	string value = "(";
	if (tabella == "modello") value += create_modello_value();
	if (tabella == "parcheggio") value += create_parcheggio_value();
	if (tabella == "vettura") value += create_vettura_value();
	if (tabella == "datianagrafici") value += create_datianagrafici_value();

	if (tabella == "posti") return create_posti_value();
	if (tabella == "tariffa") return create_tariffa_value();
	if (tabella == "abbonamento") return create_abbonamento_value();



	return value + ")";
}

string create_query(int values, string tabella) {
	string query;
	if (tabella == "modello")
		query = "INSERT INTO carsharing.modello(nome, produttore, tipo, servosterzo, airbag, ac, dimensioni, motorizzazione, nporte, nposti, vmax, consumoav) VALUES\n";
	if (tabella == "parcheggio")
		query = "INSERT INTO carsharing.parcheggio(nome, zona, nposti, long, lat, indirizzo) VALUES\n";
	if (tabella == "tariffa")
		query = "INSERT INTO carsharing.tariffa(nome, produttore, nporte, costokm, costoora, costogiorno, costogiornosettimana, costogiornoaggiuntivo) VALUES\n";
	if (tabella == "vettura") 
		query = "INSERT INTO carsharing.vettura(nome, modello, produttore, nporte, targa, colore, parcheggio, km, bimbi, animali) VALUES\n";
	if (tabella == "datianagrafici")
		query = "INSERT INTO carsharing.datianagrafici(cf, utente, nome, cognome, luogon, datan, sesso, professione, estremoid, estremopatente, categoriapatente) VALUES\n";
	if (tabella == "posti") {
		query = "INSERT INTO carsharing.posti(tipo, nome) VALUES\n";
	}
	if (tabella == "abbonamento") {
		query = "INSERT INTO carsharing.abbonamento(codiceutente, datainizio, pin, tipo) VALUES\n";
	}
	for (int i = 0; i < values; ++i)
			query += create_value(tabella) + ",\n";

	query.erase(query.size() - 1); //Tolgo ultimi caratteri a capo e virgola
	query.erase(query.size() - 1);
	return query + ";";
}

	
void vector_init(vector<string> &v, string file_name) {
	ifstream myfile;
	myfile.open(file_name);
	string line;
	while (getline(myfile, line))
	{
		line = rtrim(line);
		v.push_back(line);
	}
	return;
}

int main() {
	srand(time(0));
	
	vector_init(modelli, "C:\\Users\\Nazmul\\Desktop\\FILES\\modello.txt");
	vector_init(produttori, "C:\\Users\\Nazmul\\Desktop\\FILES\\produttore.txt");
	vector_init(nomi, "C:\\Users\\Nazmul\\Desktop\\FILES\\name.txt");
	vector_init(cognomi, "C:\\Users\\Nazmul\\Desktop\\FILES\\cognome.txt");
	vector_init(tipi, "C:\\Users\\Nazmul\\Desktop\\FILES\\type.txt");
	vector_init(indirizzi, "C:\\Users\\Nazmul\\Desktop\\FILES\\indirizzo.txt");
	vector_init(zone, "C:\\Users\\Nazmul\\Desktop\\FILES\\zona.txt");

	//Inserire manualmente categoria
	cout << create_query(5, "parcheggio") + "\n\n";
	cout << create_query(1, "posti") + "\n\n";
	cout << create_query(10, "modello") + "\n\n";
	cout << create_query(5, "vettura") + "\n\n";
	cout << create_query(1, "tariffa") + "\n\n";
	cout << create_query(10, "datianagrafici") + "\n\n";
	cout << create_query(1, "abbonamento") + "\n\n";


	return 0;
}