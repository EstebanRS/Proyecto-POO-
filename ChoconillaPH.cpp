#include <iostream>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

class Ser{
protected:
	string nombre; int max_hp; int hp; int max_eng; int energia; int atk;
	
public:
    Ser(){ 
		nombre="Serpiente"; max_hp=50; hp=50; max_eng=30; energia=30; atk=10;
	}
	
	//Constructor por parametros
	Ser(string n, int maxh, int h, int maxe, int e, int a){ 
		nombre=n; max_hp=maxh; hp=h; max_eng=maxe; energia=e; atk=a; }
	
	//Destructor
    ~Ser(){}

    //Setters
	void setNombre(string n){
	    nombre = n;}

    void setHp(int h) {
        if (h < 0) h = 0;
        if (h > max_hp) h = max_hp;
        hp = h;}
        
    void setEnergia(int e) {
        if (e < 0) e = 0;
        if (e > max_eng) e = max_eng; 
        energia = e;}

	
	//Getters
	string getNombre() const { return nombre;}
	
	//FUNCIONES
	void mostrar() const{
	cout << "Nombre: " << nombre << " | Vida: " << hp << "/" << max_hp << " | Estamina: " << energia << "/" << max_eng << " | Ataque : " << atk << endl;
	cout << endl;
	}
	
	virtual void atacar() = 0;

    virtual void rest() = 0;
	
	virtual void curar() = 0;
	
	virtual void habilidad() = 0;

};	

class Usuario: public Ser{
	private:
    int queso;
    
	public:
	Usuario(string n, int maxh, int h, int maxe, int e, int a, int q): Ser(n, maxh, h, maxe, e, a){queso=q;}
	~Usuario(){}
	
	void habilidad() override{
	cout << "D" << endl;
	}
	
	void atacar() override{
	 	cout << "A" << endl;
		}
	
	void rest() override{ 
	int tiempo;
		    cout << "... Por cuantos minutos descansa " << nombre << "?" << endl;
		    cout << "<- "; cin >> tiempo;
		    setEnergia(energia + (tiempo*2));
		cout << endl << "-> " << nombre << " recupero " << tiempo*2 << " puntos de energia!" << endl << endl;
	} 
	
	void curar() override{
	cout << "-> " << nombre << " usa curacion basica (+10 de vida)." << endl << endl;
        setHp(hp + 10);
    }

};

class Enemigo{
	private:
		int heal_token;
	public:
	~Enemigo(){}
	
    void atacar(Ser& obj){ 
		}
	
	
	void rest(){ 
		} 
	
	void curar() { 
    }
	
};

class Gato: public Enemigo, public Ser{
	public:
	~Gato(){}
	
};

int main(int argc, char** argv) {
	Usuario Primer("YO", 1 , 2, 100 , 4 ,5, 6);
    
    Primer.mostrar();
    Primer.rest();
    Primer.mostrar();
    
	return 0;
}

/* SIMBOLOGÍA DE COUT
-> Afirmación del programa
... El programa espera respuesta
<- Respuesta del usuario

*/
