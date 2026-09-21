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
    Ser(){ //Constructor por defecto
		nombre="Nadie"; max_hp=50; hp=50; max_eng=30; energia=30; atk=10; vivo=true;
	}
	
	Ser(string n, int maxh, int h, int maxe, int e, int a, bool v){ //Constructor por parametros
		nombre=n;
		max_hp=maxh;
		hp=h;
		max_eng=maxe;
		energia=e;
		atk=a;
		vivo=v;
	}
	
    ~Ser(){ //Destructor
	}
	
	//FUNCIONES
	void mostrar(){//Mirar datos
	cout << " | Nombre: " << nombre << " | Vida: " << max_hp << "/" << hp << " | Estamina: " << max_eng << "/" << energia << " | Ataque : " << atk << endl;
	cout << endl;
	}
	
		void atacar(Ser& obj){ //atacar
 	     int vida;
 	     vida = obj.hp - atk; 
 	     obj.hp = vida;
 	     if(obj.hp<=0){obj.hp=0;}
 	     cout << obj.nombre << " recibio " << atk << " puntos de danio por parte de " << nombre << endl;
		}
		
		void rest(){ // descansar
		int tiempo;
				
		    cout << "¿Por cuanto tiempo descansa " << nombre << "?" << endl;
		    cin >> tiempo;
		    energia = energia + (tiempo*2);
		    if (energia > max_eng){energia = max_eng;}
		} 
		
		void correr(){ // perder energia
		int tiempo;
		
		    cout << "¿Por cuanto tiempo corre " << nombre << "?" << endl;
			cin >> tiempo;
			
			energia = energia - (tiempo*2);
			if (energia<0){energia=0;}
		} 
	
};
	

int main(int argc, char** argv) {
	
	Ser Roedor("Rata", 20, 20, 50, 50, 100, true);
    Ser Who;

    Roedor.mostrar();
    Who.mostrar();
    
    /*Roedor.correr();
    Roedor.mostrar();
    
    Roedor.rest();
    Roedor.mostrar();*/
    
    Roedor.atacar(Who);
    Who.mostrar();
    
	return 0;
}
