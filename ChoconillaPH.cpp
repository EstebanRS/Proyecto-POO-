#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Ser{
private:
	string nombre;
	int max_hp;
	int hp;
	int max_eng;
	int energia;
	int atk;
	bool vivo;
	
public:
	//Constructor por defecto
    Ser(){ 
		nombre="Nadie"; max_hp=50; hp=50; max_eng=30; energia=30; atk=10; vivo=true;
	}
	
	//Constructor por parametros
	Ser(string n, int maxh, int h, int maxe, int e, int a, bool v){ 
		nombre=n;
		max_hp=maxh;
		hp=h;
		max_eng=maxe;
		energia=e;
		atk=a;
		vivo=v;
	}
	
	//Destructor
    ~Ser(){ 
	}

    //Setter
	void setNombre(string n){
	nombre = n;
	
}
	
	//Getters
	string getNombre() const { return nombre;}
	
	//FUNCIONES
	
	//Mirar datos
	void mostrar(){
	cout << "[*] Nombre: " << nombre << " | Vida: " << max_hp << "/" << hp << " | Estamina: " << max_eng << "/" << energia << " | Ataque : " << atk << endl;
	cout << endl;
	}
	
    //atacar
	void atacar(Ser& obj){ 
	     if (energia<=0){cout << "[!] No puedes realizar esta accion." << endl;
	      cout << endl;}
	     else{
 	     int vida;
 	     vida = obj.hp - atk; 
 	     obj.hp = vida;
 	     if(obj.hp<=0){obj.hp=0;}
 	     cout << "[-] " << obj.nombre << " recibio " << atk << " puntos de danio por parte de " << nombre << endl; cout << endl;
 	     energia = energia-51;
 	     if (energia<0){energia=0;}
		}
	}
	
	//descansar	
	void rest(){ 
		int tiempo;
		    cout << "[?] Por cuantos minutos descansa " << nombre << "?" << endl;
		    cout << "[->] "; cin >> tiempo;
		    energia = energia + (tiempo*2);
		    if (energia > max_eng){energia = max_eng;}
		cout << "[+] " << nombre << "recupero " << tiempo*2 << " puntos de energia!" << endl; cout << endl;
		} 
	
};	

int main(int argc, char** argv) {
	
	//Uso Contructores
	//Se crean los objetos
	Ser Roedor("Rata", 20, 20, 50, 50, 25, true); //Por parametros
	Ser Who; //Por defecto
	
	Roedor.mostrar(); //Datos iniciales
	Who.mostrar(); //Datos iniciales
	
	//Uso getters y setters
	//opcion de cambiar tu nombre
	string res;
	cout << "[*] Te llamas: " << Roedor.getNombre() << endl << " [?] Quieres cambiar tu nombre? (Responder en mayusculas)"<< endl;
	cout << "[->] "; cin >> res; cout << endl;
	
	if(res=="SI"){
	string nom;
	cout << "[?] Como te quieres llamar ahora?" << endl;
	cout << "[->] "; cin >> nom; 
	Roedor.setNombre(nom);
	cout << "[*] Ahora te llamas " << Roedor.getNombre() << "!" << endl; cout << endl;
	Roedor.mostrar();} //Info con el nuevo nombre

    //Uso Metodos
    Roedor.atacar(Who); //Roedor ataca a who
    Roedor.atacar(Who);//Esta vez roedor no puede hacer la acción por falta de energia
    Roedor.mostrar(); //Datos actualizados
    Who.mostrar(); //Datos actualizados
    
    Roedor.rest();//Roedor descansa para ganar energia
    Roedor.atacar(Who);//Podrá hacerlo según el tiempo asignado
    Roedor.mostrar(); //Datos actualizados (Otra vez)
    Who.mostrar(); //Datos actualizados (Otra vez)
    
    //Uso destructor
    Who.~Ser();//Destruimos el objeto porque está muerto
    
	return 0;
}

/* SIMBOLOGÍA DE COUT
[*] Afirmación del programa
[->] Respuesta del usuario
[?] Pregunta
[!] La accion no es posible
[-] Las estadisticas de un objeto bajan
[+] Las estadisticas de un objeto suben
*/
