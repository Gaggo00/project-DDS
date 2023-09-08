#include <random>
#include "process.h"
#include <omnetpp.h>
#include "int_m.h"
#include "vector_m.h"

using namespace omnetpp;

class process : public cSimpleModule {
    //std::vector<int> lista;
private:
    int *variabile2;
    int num = 0;
    int numSubmodules;
    int myNum;

//public:
   // process() : variabile2 =  // Inizializzata a 0 per ogni istanza

protected:
    virtual void initialize() ;
    virtual void handleMessage(cMessage *msg);
    virtual void printVector(int id,int* vector, std::string nomeVettore,int numSubmodules);

};

Define_Module(process);


void process::printVector(int id,int* vector, std::string nomeVettore,int numSubmodules){
    std::string vec = "";
    for(int i = 0; i<numSubmodules; i++){
                vec += std::to_string(vector[i]) + " | ";
            }
    EV << id << " vettore " + nomeVettore + " = " << vec;
}

void process::initialize() {
        // si salva il numero di moduli presenti e inizializza il vettore in modo che abbia una cella per ogni modulo
        cModule* topLevelModule = getModuleByPath("Topology");
        numSubmodules = topLevelModule->getSubmoduleVectorSize("process");
        variabile2 = new int[numSubmodules]();

        // Inizializza il generatore di numeri casuali con un seed
        std::random_device rd;
        std::mt19937 generator(rd());

        // Definisci la distribuzione per generare numeri tra 0 e 1 inclusi
        std::uniform_int_distribution<int> distribution(0, 10);

        // Genera un numero casuale tra 0 e 1
        myNum = distribution(generator);

        //stampa il numero scelto dal modulo per verificare alla fine che si trovi nella posizione giusta di ciascun vettore
        EV << getIndex() << " sceglie num " << myNum << "\n";

        //crea il nuovo messaggio da spedire e setta valore da spedire e sender (potrebbe essere implementato anche in una funzione a parte)
        IntegerMsg* msg = new IntegerMsg("starter");
        msg->setIntMsg(myNum);
        msg->setSender(getIndex());

        //spedisce il messaggio sul primo gate
        send(msg,"gate$o", 0);


}
void process::handleMessage(cMessage* msg) {
        cGate* arrivalGate = msg->getArrivalGate();

        //puo essere usato per identificare il tipo di messaggio
        std::string mes = msg->getName();

        //fa un cast safe al tipo indicato
        IntegerMsg *my_msg = check_and_cast<IntegerMsg *>(msg);
        // inserisce il numero ricevuto nell array del modulo ricevente nella posizione dedicata al modulo sende
        variabile2[my_msg->getSender()] = my_msg->getIntMsg();
        for(int i = 0; i<numSubmodules; i++){
            WATCH(variabile2[i]);
        }
        //crea il nuovo messaggio da spedire e setta valore da spedire e sender (potrebbe essere implementato anche in una funzione a parte)
        IntegerMsg* msg2 = new IntegerMsg("mid");
        msg2->setIntMsg(myNum);
        msg2->setSender(getIndex());

        // finché il numero di messaggi inviati non supera quello dei gates disponibili per inviare i messaggi invia un messagggio al prossimo gate
        if (num < gateSize("gate")-1){

            send(msg2, "gate$o",++num);
        }
        else{
            // se ha finito i gates disponibili su cui inviare messaggi si invia un messaggio da solo
            if (num < gateSize("gate")){
                scheduleAt(simTime(),msg2);
                num++;
            }
            else{
                // una volta inviati tutti i messaggi stampa il vettore variabile 2 in modo da modtrare il risultato dello scambio di messaggi
                printVector(getIndex(),variabile2,"variabile2",numSubmodules);
            }
        }

    }



    /*
     if(arrivalGate == gate("in3")){
     std::string mes = msg->getFullName();
     send(msg, "ou0");
     }*/

