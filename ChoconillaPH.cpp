#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Ser {
protected:
    string nombre; int max_hp; int hp; int max_eng; int energia; int atk;
    
public:
    Ser() { 
        nombre = "Serpiente"; max_hp = 50; hp = 50; max_eng = 30; energia = 30; atk = 10;
    }
    
    Ser(string n, int maxh, int h, int maxe, int e, int a) { 
        nombre = n; max_hp = maxh; hp = h; max_eng = maxe; energia = e; atk = a; 
    }
    
    virtual ~Ser() {}

    // Setters
    void setNombre(string n) {
        nombre = n;
    }

    void setHp(int h) {
        if (h < 0) h = 0;
        if (h > max_hp) h = max_hp;
        hp = h;
    }
            
    void setEnergia(int e) {
        if (e < 0) e = 0;
        if (e > max_eng) e = max_eng; 
        energia = e;
    }
    
    // Getters
    string getNombre() const { return nombre; }
    int getHp() const { return hp; }
    int getAtk() const { return atk; }
    int getEnergia() const { return energia; }
    int getMaxHp() const { return max_hp; }
    int getMaxEng() const { return max_eng; }
    
    // FUNCIONES
    void mostrar() const {
        cout << "Nombre: " << nombre << " | Vida: " << hp << "/" << max_hp << " | Estamina: " << energia << "/" << max_eng << " | Ataque : " << atk << endl << endl;
    }
    
    virtual void atacar(Ser& obj) = 0;
    virtual void rest() = 0;
    virtual void curar() = 0;
    virtual void habilidad() = 0;
    virtual void combatir(Ser& obj) = 0;
};    

class Roedor : public Ser {
private:
    int queso;
    
public:
    Roedor(string n, int maxh, int h, int maxe, int e, int a, int q) : Ser(n, maxh, h, maxe, e, a) {queso = q;}
    ~Roedor() {}
    
    void atacar(Ser& obj) override {
        int danio = atk;
        
        if (energia <= 0) {
            int vidaB = hp - 10;
            danio = atk/2;
            
            setHp(vidaB);
            cout << "-> " << nombre << " hizo demasiado esfuerzo y ha perdido 10 puntos de vida al atacar" << endl;
        }
        
        int vidaA = obj.getHp() - danio; 
        obj.setHp(vidaA);
        cout << "-> " << obj.getNombre() << " recibio " << danio << " puntos de danio por parte de " << nombre << endl << endl;
        setEnergia(energia - 5);
    }
    
    void habilidad() override {
        cout << "D" << endl;
    }
    
    void rest() override { 
        int estaminaA = energia+(max_eng/2);
        cout << "-> " << nombre << "Descansa y consigue" << estaminaA << "puntos de energia" << endl << endl;
        setEnergia(estaminaA);
    }    
    
    void curar() override {
    	int vidaA= hp+(max_hp/3);
        cout << "-> " << nombre << " se cura " << vidaA << " puntos de vida." << endl << endl;
        setHp(vidaA);
    }

    void combatir(Ser& obj) override {
        int des;
        cout << "[1] Atacar" << endl 
             << "[2] Habilidad" << endl 
             << "[3] Curar" << endl 
             << "[4] Descansar" << endl 
             << "... ";
        cin >> des; 
        cout << endl;
        
        switch(des) {
            case 1:
                atacar(obj); 
                break;
            case 2:
                habilidad();
                break;
            case 3:
                curar();
                break;
            case 4:
                rest();
                break;
            default:
                cout << "Opcion no valida" << endl << endl;
                break;
	}
}
};

class Enemigo: public Ser {
	private:
		int htoken=0;
		int rtoken=0;
	public:
	Enemigo(string n, int maxh, int h, int maxe, int e, int a, int ht, int rt) : Ser(n, maxh, h, maxe, e, a) {htoken=ht, rtoken=rt;}
    ~Enemigo() {}
    
     void atacar(Ser& obj) override {
        int danio = atk;
        
        if (energia <= 0) {
            int vidaB = hp - 20;
            danio = atk/3;
            
            setHp(vidaB);
            cout << "-> " << nombre << " hizo demasiado esfuerzo y ha perdido 20 puntos de vida al atacar" << endl;
        }
        
        int vidaA = obj.getHp() - danio; 
        obj.setHp(vidaA);
        cout << "-> " << obj.getNombre() << " recibio " << danio << " puntos de danio por parte de " << nombre << endl << endl;
        setEnergia(energia - 5);
    }  
    
    void rest() override {
    	int estaminaA = energia+(max_eng/3);
        cout << "-> " << nombre << "Descansa y consigue" << estaminaA << "puntos de energia" << endl << endl;
        setEnergia(estaminaA);
        rtoken==rtoken+1;
    }
    
    void curar() override {
    	int vidaA= hp+(max_hp/4);
        cout << "-> " << nombre << " se cura " << vidaA << " puntos de vida." << endl << endl;
        setHp(vidaA);
        htoken==htoken+1;
    }

    void combatir(Ser& obj) override {
    	 int des;
    	 srand(time(NULL));
		 int prob= (rand() % 100)+1;
        
        switch(des) {
            case 1:
                atacar(obj); 
                break;
            case 2:
                habilidad();
                break;
            case 3:
                curar();
                break;
            case 4:
                rest();
                break;
            default:
                cout << "Opcion no valida" << endl << endl;
                break;
	}
    }
    
};

class Gato : public Enemigo { 
public:
    Gato(string n, int maxh, int h, int maxe, int e, int a, int ht, int rt) : Enemigo(n, maxh, h, maxe, e, a, ht, rt) {}
    ~Gato() {}
    
};

int main(int argc, char** argv) {

    
    return 0;
}

/* SIMBOLOGÍA DE COUT
-> Afirmación del programa
... El programa espera respuesta
<- Respuesta del usuario

*/
