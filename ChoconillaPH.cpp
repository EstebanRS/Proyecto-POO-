#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Mono{
public:
	string nombre;
	int hp;
	int energia;
	int ataque;
	bool vivo;
	
    Mono (){ //Por defecto
		nombre="nadie"; hp=50; energia=30; ataque=10; vivo=true;
	}
	
	Mono (string n, int h, int e, int a, bool v){ //Constructor
		nombre=n;
		hp=h;
		energia=e;
		ataque=a;
	}
	
	void mostrar(){//Mirar datos
	cout << " | Nombre: " << nombre << " | Vida: " << hp << " | Estamina: " << energia << " | Ataque : " << ataque << " | Estado: " << vivo << endl;

	}
	
	 
	   
		//void atk(){ //atacar
		
		void danio(){ // recibir ataque
		
		}
		
		void rest(){ // descansar
		int tiempo;
		int max=50;
				
		    cout << "¿Por cuanto tiempo descansa " << nombre << "?" << endl;
		    cin >> tiempo;
		    energia = energia+(tiempo*2);
		    if (energia > max){energia = max;}
		} 
		
		void correr(){ // perder energia
		int tiempo;
		
		    cout << "¿Por cuanto tiempo corre " << nombre << "?" << endl;
			cin >> tiempo;
			
			energia = energia-(tiempo*2);
			if (energia<0){energia=0;}
		} 
	
};
	

int main(int argc, char** argv) {
	
	Mono Roedor("Rata", 20, 50, 8, true);
    //Mono Who();

    Roedor.mostrar();
    //Who.mostrar();
    
    Roedor.correr();
    Roedor.mostrar();
    
    Roedor.rest();
    Roedor.mostrar();
    
    
	return 0;
}
