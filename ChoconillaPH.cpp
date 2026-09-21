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
		nombre="Nadie"; max_hp=50; max_eng=30; atk=10; vivo=true;
        setHp(50);
        setEnergia(30);
	}
	
	Ser(string n, int maxh, int h, int maxe, int e, int a, bool v){ //Constructor por parametros
		nombre=n;
		max_hp=maxh;
		max_eng=maxe;
		atk=a;
		vivo=v;
        setHp(h);
        setEnergia(e);
	}
	
    ~Ser(){ //Destructor
        cout << "[Destruido] " << nombre << " se libero de la memoria." << endl;
	}
	
    void setHp(int h) {
        if (h < 0) h = 0;
        if (h > max_hp) h = max_hp;
        hp = h;
        if (hp == 0) vivo = false;
    }
    int getHp() const { return hp; }

    void setEnergia(int e) {
        if (e < 0) e = 0;
        if (e > max_eng) e = max_eng;
        energia = e;
    }
    int getEnergia() const { return energia; }
    
    string getNombre() const { return nombre; }

	//FUNCIONES
	void mostrar(){ //Mirar datos
	    cout << " | Nombre: " << nombre << " | Vida: " << max_hp << "/" << hp 
             << " | Estamina: " << max_eng << "/" << energia << " | Ataque : " << atk << endl;
	}
	
    void atacar(Ser& obj){ //atacar
        int nueva_vida = obj.getHp() - atk; 
        obj.setHp(nueva_vida);
        cout << obj.getNombre() << " recibio " << atk << " puntos de danio por parte de " << nombre << endl;
    }

    void curar() { 
        cout << nombre << " usa curacion basica (+10 de vida)." << endl;
        setHp(hp + 10);
    }

    void curar(int cantidad) { 
        cout << nombre << " usa una pocion y se cura por " << cantidad << " puntos de vida." << endl;
        setHp(hp + cantidad);
    }
		
    void rest(){ // descansar
        int tiempo;
        cout << "¿Por cuanto tiempo descansa " << nombre << "?" << endl;
        cin >> tiempo;
        setEnergia(energia + (tiempo*2));
    } 
		
    void correr(){ // perder energia
        int tiempo;
        cout << "¿Por cuanto tiempo corre " << nombre << "?" << endl;
        cin >> tiempo;
        setEnergia(energia - (tiempo*2));
    } 
};
	
int main(int argc, char** argv) {
	
	Ser* Roedor = new Ser("Rata", 20, 20, 50, 50, 100, true);
    Ser Who;

    Roedor->mostrar();
    Who.mostrar();
    
    /*Roedor->correr();
    Roedor->mostrar();
    
    Roedor->rest();
    Roedor->mostrar();*/

    cout << "\n--- Prueba ---" << endl;
    Roedor->setHp(-999);
    Roedor->mostrar();
    
    Roedor->setHp(20);

    cout << "\n--- Combate ---" << endl;
    Roedor->atacar(Who);
    Who.mostrar();
    
    Who.curar();       
    Who.mostrar();

    Who.curar(20);     
    Who.mostrar();
    cout << endl;
    
    delete Roedor;
    
	return 0;
}
