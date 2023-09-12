#include <random>
#include "process.h"
#include <omnetpp.h>
#include "int_m.h"
#include "vector_m.h"
#include <algorithm>
#include <iterator>


using namespace omnetpp;

class process : public cSimpleModule {
    //std::vector<int> lista;
private:
    int *variabile2;
    int num = 0;
    int numSubmodules;
    int myNum;
    bool infected = 0;

//public:
   // process() : variabile2 =  // Inizializzata a 0 per ogni istanza

protected:
    virtual void initialize() ;
    virtual void handleMessage(cMessage *msg);
    virtual void printVector(int id,int* vector, std::string nomeVettore,int numSubmodules);
    virtual bool generateInfections(int numProcesses, int numInfected, int process,int correctProcess, std::mt19937* rng);

};

Define_Module(process);

bool process::generateInfections(int numProcesses, int numInfected, int process,int correctProcess, std::mt19937* rng){

    std::vector<int> processes;
    for (int i = 0 ; i < numProcesses; i++){
        processes.push_back(i);
    }
    std::shuffle(processes.begin(), processes.end(), *rng);
    for( int i = 0; i<numInfected; i++){
        if( processes[i] == process){
            return 1;
        }
    }
    return 0;

}




void process::printVector(int id,int* vector, std::string nomeVettore,int numSubmodules){
    std::string vec = "";
    for(int i = 0; i<numSubmodules; i++){
                vec += std::to_string(vector[i]) + " | ";
            }
    EV << id << " vettore " + nomeVettore + " = " << vec;
}

void process::initialize() {
        cModule* topLevelModule = getModuleByPath("Topology");
        numSubmodules = topLevelModule->getSubmoduleVectorSize("process");
        variabile2 = new int[numSubmodules]();
    //if (strcmp(getName(), "process0") == 0) {
        // Inizializza il generatore di numeri casuali con un seed
        std::mt19937 rng(42);
        if (generateInfections(4,1,getIndex(),&rng)){
            infected = 1;
            EV << getIndex() << " is infected\n";
        }
        std::random_device rd;
        std::mt19937 generator(rd());

        // Definisci la distribuzione per generare numeri tra 0 e 1 inclusi
        std::uniform_int_distribution<int> distribution(0, 10);

        // Genera un numero casuale tra 0 e 1
        myNum = distribution(generator);
        EV << getIndex() << " sceglie num " << myNum << "\n";
        //lista.push_back(numeroCasuale);
        //variabile2[0] = numeroCasuale;
        //std::string numeroCasualeString = std::to_string(numeroCasuale);
        //std::string messaggio =  numeroCasualeString;

        IntegerMsg* msg = new IntegerMsg("starter");
        msg->setIntMsg(myNum);
        msg->setSender(getIndex());
        send(msg,"gate$o", 0);
    //}
}
void process::handleMessage(cMessage* msg) {
        cGate* arrivalGate = msg->getArrivalGate();


        std::string mes = msg->getFullName();

        IntegerMsg *my_msg = check_and_cast<IntegerMsg *>(msg);

        variabile2[my_msg->getSender()] = my_msg->getIntMsg();
        for(int i = 0; i<numSubmodules; i++){
            WATCH(variabile2[i]);
        }
        //IntegerMsg* msg2 = my_msg->dup();
        if (num < gateSize("gate")-1){
            IntegerMsg* msg2 = new IntegerMsg("mid");
            msg2->setIntMsg(myNum);
            msg2->setSender(getIndex());
            send(msg2, "gate$o",++num);
        }
        else{
            printVector(getIndex(),variabile2,"variabile2",numSubmodules);
        }

    }



    /*
     if(arrivalGate == gate("in3")){
     std::string mes = msg->getFullName();
     send(msg, "ou0");
     }*/

