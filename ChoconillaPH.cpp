#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <limits>

using namespace std;

class Ser {
protected:
    string nombre; int max_hp; int hp; int atk;
    
public:
    Ser(){nombre="Nadie"; max_hp=1; hp=1; atk=1;}
    Ser(string n, int maxh, int h, int a) { 
        nombre = n; max_hp = maxh; hp = h; atk = a; 
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
    
    // Getters
    string getNombre() const { return nombre; }
    int getHp() const { return hp; }
    int getAtk() const { return atk; }
    int getMaxHp() const { return max_hp; }
    
    // FUNCIONES
    virtual void mostrar() const = 0;
    virtual void atacar(Ser& obj) = 0;
    virtual void curar() = 0;
    virtual void habilidad(Ser& obj) = 0;
    virtual void combatir(Ser& obj) = 0;
};    

void iniciarCombate(vector<Ser*>& combatientes) {
    cout << "TE ENCONTRO QUIEN MENOS QUERIAS" << endl << endl;

    int turno = 0;
    int cont = 1;

    while (combatientes[0]->getHp() > 0 && combatientes[1]->getHp() > 0) {
        Ser* atacante = combatientes[turno];
        Ser* objetivo = combatientes[1 - turno]; 

        cout << "-> Turno #" << cont << endl;
        cout << "De: "; atacante->mostrar();
        cout << "A: "; objetivo->mostrar();
        cout << endl;

        atacante->combatir(*objetivo);

        turno = 1 - turno;
        cont++;
        cout << "--------------------------------------------" << endl << endl;
    }

    cout << "-> Resultado:" << endl;
    if (combatientes[0]->getHp() > 0) {
        cout << "Victoria para " << combatientes[0]->getNombre() << "!" << endl << endl;
    } else {
        cout << "   Derrota! " << endl;
    }
}

class Enemigo: public Ser {
private:
    int htoken;
public:
    Enemigo(string n, int maxh, int h, int a, int ht) : Ser(n, maxh, h, a) { htoken = ht; }
    ~Enemigo() {}
    
    void mostrar() const override {
        cout << nombre << " | Vida: " << hp << "/" << max_hp << " | Ataque : " << atk << " | Token: " << htoken << endl;
    }
    
    void atacar(Ser& obj) override {
        int danio = atk;
        int vidaA = obj.getHp() - danio; 
        obj.setHp(vidaA);
        cout << "-> " << obj.getNombre() << " recibio " << danio << " puntos de danio por parte de " << nombre << endl << endl;
    }   
    
    void curar() override {
        int vidaA = hp + (max_hp/4);
        cout << "-> " << nombre << " se cura " << (max_hp/4) << " puntos de vida." << endl << endl;
        setHp(vidaA);
        htoken = htoken + 1;
    }

    void combatir(Ser& obj) override {
        int critico = (max_hp / 4);
        int prob = (rand() % 12) + 1;
        
        if (htoken < 3) {
            if (hp < max_hp && hp > critico) {
                if (prob <= 2) curar();
                else if (prob < 8) atacar(obj);
                else habilidad(obj);
            } else if (hp <= critico) {
                if (prob <= 6) curar();
                else if (prob < 10) atacar(obj);
                else habilidad(obj);
            } else {
                if (prob <= 8) atacar(obj);
                else habilidad(obj);
            }
        } else {
            if (prob > 6) atacar(obj);
            else habilidad(obj);
        }
    }
};

class Gato : public Enemigo { 
public:
    Gato(string n, int maxh, int h, int a, int ht) : Enemigo(n, maxh, h, a, ht) {}
    ~Gato() {}
    
    void habilidad(Ser& obj) override {
        cout << "Hola se uso habilidad jeje" << endl << endl;
    }
};

class Serpiente : public Enemigo { 
public:
    Serpiente(string n, int maxh, int h, int a, int ht) : Enemigo(n, maxh, h, a, ht) {}
    ~Serpiente() {}
    
    void habilidad(Ser& obj) override {
        cout << "Habilidad? que habilidad?" << endl << endl;
    }
};

class Mapa {
public:
    ~Mapa(){}
    
    virtual void stats() = 0;
    virtual void full()= 0;
    virtual void compra() = 0;
    virtual void regresar() = 0;
    
    void movimiento(){
        int op;
        
        do {
            cout << "|°  ~ - - - ú - - - ~  °| " << endl 
                 << "|  [1]  Madriguera      |" << endl 
                 << "|  [2]    Tienda        |" << endl 
                 << "|  [3]    Afuera        |" << endl 
                 << "|  [4]     Fin          |" << endl 
                 << "|°  ~ - - - ú - - - ~  °| " << endl;
            cout << "        ... "; 
            
            if (!(cin >> op)) {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                op = 0;
            }
            cout << endl;
            
            switch(op){
                case 1:
                    cout << "Volviendo Casa..." << endl << endl;
                    int hacer;
                    do{
                        cout << "|°  ~ - - - ú - - - ~  °| " << endl 
                             << "|  [1] Ver estadisticas |" << endl 
                             << "|  [2] Restablecerse    |" << endl 
                             << "|  [3]    Cerrar        |" << endl 
                             << "|°  ~ - - - ú - - - ~  °| " << endl;
                        cout << "        ... "; 
                        
                        if (!(cin >> hacer)) {
                            cin.clear(); 
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            hacer = 0;
                        }
                        cout << endl;
                        
                        switch(hacer){
                            case 1: stats(); cout << endl; break;
                            case 2: full(); break;
                            case 3: cout << "Volviendo..." << endl << endl; break;
                            default: cout << "Opcion no valida" << endl << endl; break;
                        }
                    } while (hacer != 3);
                    break;
                    
                case 2:
                    cout << "Visitando la tienda..." << endl << endl;
                    compra();
                    break;
                    
                case 3: {
                    cout << "Aventurandose..." << endl << endl;
                    
                    Ser* npc = nullptr;
                    int enemigoRand = (rand() % 2);
                    if (enemigoRand == 0) {
                        npc = new Gato("Zeus", 100, 100, 25, 0);
                    } else {
                        npc = new Serpiente("Aja", 10, 10, 10, 0);
                    }

                    Ser* jugador = dynamic_cast<Ser*>(this);

                    vector<Ser*> combatientes;
                    combatientes.push_back(jugador);
                    combatientes.push_back(npc);

                    iniciarCombate(combatientes);

                    if (jugador->getHp() <= 0) {
                        op = 4; 
                    }

                    regresar();
					delete npc;
                    break;
                }
                    
                case 4:
                    cout << "Cerrando..." << endl;
                    break;
                    
                default:
                    cout << "Opcion no valida" << endl << endl;
                    break;
            }
        } while (op != 4);
    }
};

class Roedor : public Ser, public Mapa {
private:
    int max_eng;
    int energia;
    int queso;
    int base_atk;
    
public:
    Roedor(string n, int maxh, int h, int maxe, int e, int a, int ba, int q) : Ser(n, maxh, h, a) {queso = q; max_eng=maxe; energia=e; base_atk=ba;}
    ~Roedor() {}
    
    //Funciones propias
    int getEnergia() const { return energia; }
    int getMaxEng() const { return max_eng; }
    void setEnergia(int e) {
        if (e < 0) e = 0;
        if (e > max_eng) e = max_eng; 
        energia = e;
    }
    
        void rest(){ 
        int estaminaA = energia + (max_eng/2);
        cout << "-> " << nombre << " descansa y consigue " << estaminaA << " puntos de energia" << endl << endl;
        setEnergia(estaminaA);
    }    
    
    //Funciones de Ser
    void mostrar() const override {
        cout << nombre << " | Vida: " << hp << "/" << max_hp << " | Estamina: " << energia << "/" << max_eng << " | Ataque : " << atk << " | Queso: " << queso << endl;
    }
    
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
    
    void habilidad(Ser& obj) override {
        cout << "-> " << nombre << " se concentra para subir su ataque." << endl;
        int atkA = atk + 10;
        atk = atkA;
    }
    
    void curar() override {
        int vidaA = hp + (max_hp/2);
        cout << "-> " << nombre << " se cura " << (max_hp/2) << " puntos de vida." << endl << endl;
        setHp(vidaA);
        queso = queso - 1;
    }

    void combatir(Ser& obj) override {
        int des;
        
        cout << "|°  ~ - - - ú - - - ~  °| " << endl;
        cout << "|  [1]   Atacar         |" << endl 
             << "|  [2]  Habilidad       |" << endl 
             << "|  [3]    Curar         |" << endl 
             << "|  [4]  Descansar       |" << endl;
        cout << "|°  ~ - - - ú - - - ~  °| " << endl;
        cout << "        ... "; 
        
        if (!(cin >> des)) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            des = 0;
        }
        cout << endl;
        
        switch(des) {
            case 1: atacar(obj); break;
            case 2: habilidad(obj); break;
            case 3: curar(); break;
            case 4: rest(); break;
            default: cout << "Opcion no valida" << endl << endl; break;
        }
    }

//Funciones de Mapa
    void stats() override {
        mostrar();
    }
    
    void full() override {
        setEnergia(max_eng);
        setHp(max_hp);
        cout << "-> " << nombre << " se restaura por completo." << endl << endl;
    }

    void compra() override {
        int quesoA = queso + 3;
        queso = quesoA;
        cout << "-> " << nombre << " compra 3 piezas de queso para más tarde." << endl << endl;
    }
    
	void regresar() override{
	atk=base_atk;
	}
};


int main(int argc, char** argv) {
    srand(time(NULL));

    Roedor Us("Choconilla", 50, 50, 80, 0, 20, 20, 10);

    Us.movimiento();

    return 0;
}
/* SIMBOLOGÍA DE COUT
-> Afirmación del programa
... El programa espera respuesta
<- Respuesta del usuario

*/
