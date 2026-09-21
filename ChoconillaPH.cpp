//Añadir destructor + cambiar clase "Mono" -> "Ser"

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Ser{
private:
	string nombre;
	int hp;
	int energia;
	int ataque;
	bool vivo;
	
public:
    Ser(){ //Constructor por defecto
		nombre="Nadie"; hp=50; energia=30; ataque=10; vivo=true;
	}
	
	Ser(string n, int h, int e, int a, bool v){ //Constructor por parametros
		nombre=n;
		hp=h;
		energia=e;
		ataque=a;
	}
	
    ~Ser(){ //Destructor
	}
	
	void mostrar(){//Mirar datos
	cout << " | Nombre: " << nombre << " | Vida: " << hp << " | Estamina: " << energia << " | Ataque : " << ataque << " | Estado: " << vivo << endl;
	cout << endl;
	}
	
		void atk(Ser& obj){ //atacar
 	     int vida;
 	     vida = obj.hp - ataque; 
 	     obj.hp = vida;
 	     cout << obj.nombre << " recibio " << ataque << " puntos de danio por parte de " << nombre << endl;
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
	
	Ser Roedor("Rata", 20, 50, 8, true);
    Ser Who;

    //Roedor.mostrar();
    Who.mostrar();
    
    /*Roedor.correr();
    Roedor.mostrar();
    
    Roedor.rest();
    Roedor.mostrar();*/
    
    Roedor.atk(Who);
    Who.mostrar();
    
	return 0;
}
