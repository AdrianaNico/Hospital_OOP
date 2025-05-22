// Folosim #include doar acolo unde chiar avem nevoie de corpul complet al clasei (ex: când apelăm metode sau accesăm membri).
// Folosim class NumeClasa; acolo unde avem doar pointeri sau referințe, și nu apelăm metode.

//a se rula cu: g++ Main.cpp Consultatie.cpp Medic.cpp Pacient.cpp Persoana.cpp Reteta.cpp Spital.cpp SectieCardiologie.cpp SectieChirurgie.cpp SectiePediatrie.cpp -o main.exe

#include <iostream>
#include <cctype> //pt toupper
#include <string>
#include <vector>
#include <sstream> //pt istringstream
#include <limits>//pt numeric_limits
#include "Spital.h"
#include "SectieCardiologie.h"
#include "SectieChirurgie.h"
#include "SectiePediatrie.h"

// setter cnp, sa aiba 13 cifre si sa inceapa cu 1,2,5 sau 6
//sa pot scrie reteta doar daca exista consultatie intre medic si pacient
//redefinire
int main() {
    Spital spital;
    SectieCardiologie sectieCardiologie;
    SectieChirurgie sectieChirurgie;
    SectiePediatrie sectiePediatrie;


    bool ok=true;
    int optiune;
    std::string account;
    bool loggedIn=false;
    bool inapoiLaMeniu=false;

    auto clearScreen = []() {//functie lambda pt curatarea terminalului
#ifdef _WIN32
        system("cls");//pt Windows
#else
        std::cout << "\033[2J\033[1;1H";//linux, macos
#endif
        std::cout.flush();
    };
    while (true) {
        do {
            clearScreen();
            std::cout << "         ------SPITAL------" << std::endl;
            std::cout << "Ca ce vrei sa te loghezi?" << std::endl;
            std::cout << "1. Medic [M]" << std::endl;

            std::cout << "2. Pacient [P]" << std::endl;
            std::cout << "Alegerea ta: ";
            std::cin >> account;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch (toupper(account[0])) {
                case 'M':
                    loggedIn = true;
                    account = "medicului";
                    break;
                case 'P':
                    loggedIn = true;
                    account = "pacientului";
                    break;
                default:
                clearScreen();
                std::cout << "Cont invalid! Te rog sa alegi M (medic) sau P (pacient)." << std::endl;
                std::cout << "Apasa Enter pentru a continua...";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
            }

        } while (!loggedIn);

        inapoiLaMeniu = false;

        while (!inapoiLaMeniu) {
            clearScreen();
            if (account == "medicului") {
                std::cout << "         ------SPITAL------" << std::endl;
                std:: cout << "~~~~~~~~Bun venit in meniul " << account << "!~~~~~~~~" << std::endl;
                std::cout << "1. Inregistreaza medic" << std::endl;
                std::cout << "2. Inregistreaza-te intr-o sectie" << std::endl;
                std::cout << "3. Afiseaza consultatii" << std::endl;
                std::cout << "4. Afiseaza pacientii" << std::endl;
                std::cout << "5. Afiseaza detalii pacient" << std::endl;
                std::cout<< "6. Prescriere reteta"<<std::endl;
                std::cout << "7. Inapoi la meniul principal" << std::endl;
                std::cout << "8. Iesi din program" << std::endl;
                std::cout << "Introduceti optiunea: ";
                std::cin >> optiune;

                if (std::cin.fail()) {//verifica daca valoarea primta este un int
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    clearScreen();
                    std::cout << "Optiune invalida! Te rog sa introduci un numar valid." << std::endl;
                    std::cout << "Apasa Enter pentru a continua...";
                    std::cin.get();//asteapta sa apesi enter
                    continue;
                }

                switch (optiune) {
                    case 1: {//adauga medic
                        
                        std::string nume;
                        int varsta;
                        std::string cnp;
                        std::string specializare;
                        std::cout << "Introduceti numele medicului: ";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// sa nu se ia in considerare cin-ul precedent(optiune)
                        getline(std::cin, nume);
                        std::cout << "Introduceti varsta medicului: ";
                        std::cin >> varsta;
                        std::cout << "Introduceti CNP-ul medicului: ";
                        std::cin >> cnp;
                        std::cout << "Introduceti specializarea medicului: ";
                        std::cin.ignore();
                        getline(std::cin, specializare);
                        bool cnpValid = false;
                        while(!cnpValid){
                            if(Persoana::isValidCNP(cnp)){
                                cnpValid = true;
                            }
                            else{
                                clearScreen();
                                std::cout << "CNP invalid! Te rog sa introduci un CNP valid: ";
                                std::cin >> cnp;
                            }
                        }// SA SE AFISEZE MEDICUL A FOST ADUGAT CU SUCCES DUPA CE CNP UL NU ESTE INTRODUS CUM TREBUIE
                        Medic medic(nume, varsta, cnp, specializare);
                        spital.adaugaMedic(medic);
                        clearScreen();
                        std::cout << "Medicul " << medic.getNumeMedic() << " a fost adaugat cu succes!" << std::endl;
                        std::cout << "Apasa Enter pentru a continua...";
                        std::cin.get();
                        break;
                    }
                    case 2:{//adauga in sectie
                        std::string numeMedic;
                        std::string sectie;
                        Medic* medicGasit = nullptr;
                        std::cout << "Introduceti numele medicului: ";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        getline(std::cin, numeMedic);
                        medicGasit = spital.cautaMedic(numeMedic);
                        if(!medicGasit){
                            clearScreen();
                            std::cout << "Medicul " << numeMedic << " nu exista!" << std::endl;
                            std::cout << "Apasa Enter pentru a continua...";
                            std::cin.get();
                            break;
                        }
                        std::cout << "In ce sectie va inscrieti? (cardiologie - CD, chirurgie - CH, pediatrie - PD): ";
                        std::getline(std::cin, sectie);
                        for(auto& litera :sectie){
                            litera = toupper(litera);
                        }
                        if(sectie == "CD"){
                            sectieCardiologie.adaugaMedicSectieCardiologie(*medicGasit);  
                            clearScreen();
                            std:: cout << "Medicul " <<medicGasit->getNumeMedic() << " a fost adaugat in sectia de cardiologie!" << std::endl;
                            std::cout << "Apasa Enter pentru a continua...";
                            std::cin.get();
                        }
                        else if(sectie == "CH"){
                            sectieChirurgie.adaugaMedicSectieChirurgie(*medicGasit);
                            clearScreen();
                            std:: cout << "Medicul " <<medicGasit->getNumeMedic() << " a fost adaugat in sectia de chirurgie!" << std::endl;
                            std::cout << "Apasa Enter pentru a continua...";
                            std::cin.get();
                        }
                        else if(sectie == "PD"){
                            sectiePediatrie.adaugaMedicSectiePediatrie(*medicGasit);
                            clearScreen();
                            std:: cout << "Medicul " <<medicGasit->getNumeMedic() << " a fost adaugat in sectia de pediatrie!" << std::endl;
                            std::cout << "Apasa Enter pentru a continua...";
                            std::cin.get();
                        }
                        else{
                            clearScreen();
                            std:: cout << "Sectia nu exista!" << std::endl;
                            std::cout << "Apasa Enter pentru a continua...";
                            std::cin.get();
                        }
                        
                    break;
                    }
                    case 3: {//afiseaza consultatii
                        std::string numeMedic;
                        std::cout << "Numele medicului pentru care doriti sa vedeti consultatiile: ";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        getline(std::cin, numeMedic);
                        std::vector<Medic>& listaMedici = spital.getMedici();
                        Medic* medicGasit = nullptr;
                        for (auto& medic : listaMedici) {
                            if (medic.getNumeMedic() == numeMedic) {
                                medicGasit = &medic;
                                break;
                            }
                        }
                        if (!medicGasit) {
                            clearScreen();
                            std::cout << std::endl << "Medic inexistent!" << std::endl << std::endl;
                            std::cout << "Apasa Enter pentru a continua...";
                            std::cin.get();
                            break;
                        }
                        clearScreen();
                        medicGasit->afisareConsultatii(spital.getConsultatii(), medicGasit);
                        std::cout<< "Apasa Enter pentru a continua...";
                        std::cin.get();
                        break;
                    }
                    case 4: {//afiseaza pacientii
                        std:: string nume;
                        std::cout<<"Introduceti numele medicului: "<<std::endl;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        getline(std::cin, nume);
                        Medic* medicGasit = spital.cautaMedic(nume);
                        if (!medicGasit) {
                            clearScreen();
                            std::cout << "Medicul " << nume << " nu exista!" << std::endl;
                            std::cout << "Apasa Enter pentru a continua...";
                            std::cin.get();
                            break;
                        }
                        clearScreen();
                        std::vector<Consultatie>& listaConsultatii = spital.getConsultatii();
                        bool pacientiGasiti = false;
                        std::cout << "Pacientii medicului "<<nume<< " sunt: "<<std::endl;
                        for(auto& consultatie: listaConsultatii){
                            Medic* medic = consultatie.getMedic();
                            Pacient* pacient = consultatie.getPacient();
                            if (medic && pacient && medic->getNumeMedic() == nume) {
                                pacient->afisareDetalii();
                                pacientiGasiti = true;
                                std::cout<<std::endl<<std::endl;
                            }
                        }
                        if (!pacientiGasiti) {
                            std::cout << "Nu exista pacienti pentru acest medic." << std::endl;
                        }
                        std::cout << "Apasa Enter pentru a continua...";
                        std::cin.get();
                        break;
                    }
                    case 5:{//detalii pacient
                        std::string nume;
                        std::cout << "Introduceti numele pacientului: ";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        getline(std::cin, nume);
                        Pacient* pacientGasit = spital.cautaPacient(nume);
                        if (!pacientGasit) {
                            clearScreen();
                            std::cout << "Pacientul " << nume << " nu exista!" << std::endl;
                            std::cout << "Apasa Enter pentru a continua...";
                            std::cin.get();
                            break;
                        }
                        clearScreen();
                        pacientGasit->afisareDetalii();
                        bool reteteGasite = false;
                        std::cout<<"Retetele pacientului: \n";
                        for(auto& reteta: spital.getRetete()){
                            if(reteta.getPacient()->getNumePacient()==pacientGasit->getNumePacient()){
                                reteteGasite = true;
                                reteta.afisareReteta();
                            }
                        }
                        if(!reteteGasite){
                            std::cout << "Nu exista retete pentru acest pacient." << std::endl;
                        }
                        std::cout << "Apasa Enter pentru a continua...";
                        std::cin.get();
                        break;
                    }
                    case 6:{//prescrie reteta
                        std:: string nume_medic, nume_pacient;
                        std::vector<std::string> medicamente;
                        std::cout << "Introduceti numele dvs(medic): ";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        getline(std::cin, nume_medic);
                        std::cout << "Introduceti numele pacientului: ";
                        getline(std::cin, nume_pacient);
                        Medic* medicGasit = spital.cautaMedic(nume_medic);
                        Pacient* pacientGasit = spital.cautaPacient(nume_pacient);
                        if (!medicGasit) {
                            clearScreen();
                            std::cout << "Medicul " << nume_medic << " nu exista!" << std::endl;
                            std::cout << "Apasa Enter pentru a continua...";
                            std::cin.get();
                            break;
                        }
                        if (!pacientGasit) {
                            clearScreen();
                            std::cout << "Pacientul " << nume_pacient << " nu exista!" << std::endl;
                            std::cout << "Apasa Enter pentru a continua...";
                            std::cin.get();
                            break;
                        }
                        std::cout<<"Introduceti medicamentele prescrise (separati prin spatiu): ";
                        std::string medicamente_input;
                        getline(std::cin, medicamente_input);
                        std::istringstream ss(medicamente_input);// trateaza stringul ca pe un stream, adica vede cuvintele ca fiind separate prin spatiu

                        std::string medicament;
                        while(ss >>medicament){//se iau cuvintele pe rand din ss si se pun in medicament
                            medicamente.push_back(medicament);
                        }
                        Reteta reteta(pacientGasit, medicGasit, medicamente);
                        spital.adaugaReteta(reteta);
                        clearScreen();
                        std::cout << "Reteta a fost creata cu succes!" << std::endl;
                        std::cout << "Apasa Enter pentru a continua...";
                        std::cin.get();
                        break;
                    }
                    case 7:
                        clearScreen();
                        inapoiLaMeniu = true;
                        loggedIn = false;
                        break;
                    
                    case 8:
                    std::cout << "\033[2J\033[1;1H";
                    std::cout << "Multumesc ca ai folosit aplicatia!<3" << std::endl;
                    return 0;
                        
                    default:
                    clearScreen();
                    std::cout << "Optiune invalida! Te rog sa alegi o optiune valida." << std::endl;
                        break;
                }
            } else if (account == "pacientului") {
                std::cout << "         ------SPITAL------" << std::endl;
                std::cout << "~~~~~~~~Bun venit in meniul " << account << "!~~~~~~~~" << std::endl;
                std::cout << "1. Inregistreaza-te" << std::endl;
                std::cout << "2. Programeaza consultatie" << std::endl;
                std::cout << "3. Afiseaza medicii" << std::endl;
                std::cout << "4. Afiseaza sectiile" << std::endl;//sa vezi medicii pe sectii, alegi sectia, apoi vezi medicii
                std::cout << "5. Afiseaza detalii pacient" << std::endl;
                std::cout << "6. Afiseaza detalii consultatie" << std::endl;//vezi consultatiile pacientului
                //vezi retetele primite
                std::cout << "7. Inapoi la meniul principal" << std::endl;
                std::cout << "8. Iesi din program" << std::endl;
                std::cout << "Introduceti optiunea: ";
                std::cin >> optiune;

                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    clearScreen();
                    std::cout << "Optiune invalida! Te rog sa introduci un numar valid." << std::endl;
                    std::cout << "Apasa Enter pentru a continua...";
                    std::cin.get();
                    continue;
                }
                switch (optiune) {
                    case 1: {//inregistrare pacient

                        std:: string nume;
                        int varsta;
                        std:: string cnp;
                        std::cout << "Introduceti numele pacientului: ";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        getline(std::cin, nume);
                        std::cout << "Introduceti varsta pacientului: ";
                        std::cin >> varsta;
                        std::cout << "Introduceti CNP-ul pacientului: ";
                        std::cin >> cnp;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        Pacient pacient(nume, varsta, cnp);
                        spital.adaugaPacient(pacient);
                        clearScreen();
                        std::cout<<"Pacientul "<<pacient.getNumePacient()<< " a fost adaugat cu succes!"<<std::endl;
                        std::cout << "Apasa Enter pentru a continua...";
                        std::cin.get();
                        break;
                    }
                    case 2: {//adauga consultatie
                        std::string numePacient, numeMedic, data, diagnostic;
                        std:: cout << "Introduceti numele pacientului: ";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        getline(std::cin, numePacient);
                        std::cout << "Introduceti numele medicului: ";
                        getline(std::cin, numeMedic);
                        Pacient* pacientGasit = spital.cautaPacient(numePacient);
                        Medic* medicGasit = spital.cautaMedic(numeMedic);

                        if (!pacientGasit) {
                            clearScreen();
                            std::cout << "Pacientul " << numePacient << " nu exista!" << std::endl;
                            std::cout << "Apasa Enter pentru a continua...";
                            std::cin.get();
                            break;
                        }
                        if (!medicGasit) {
                            clearScreen();
                            std::cout << "Medicul " << numeMedic << " nu exista!" << std::endl;
                            std::cout << "Apasa Enter pentru a continua...";
                            std::cin.get();
                            break;
                        }

                        std::cout << "Introduceti data consultatiei(ZZ-LL-AAAA): ";
                        std::cin >> data;
                        std::cout << "Introduceti problema pe care o aveti: ";
                        std::cin.ignore();
                        getline(std::cin, diagnostic);
                        pacientGasit->adaugaIstoricMedical(diagnostic);


                        Consultatie consultatie(pacientGasit, medicGasit, data, diagnostic);
                        spital.adaugaConsultatie(consultatie);
                        std::cout << "\033[2J\033[1;1H";
                        std::cout << "Programarea a fost facuta cu succes!" << std::endl;
                        std::cout << "Apasa Enter pentru a continua...";
                        std::cin.get();
                        break;
                    }
                    case 3:{//afiseaza medicii
                        clearScreen();
                        std::cout << "Medicii disponibili sunt: " << std::endl;
                        for (auto& medic :spital.getMedici()){
                            std::cout << "Medicul: "<<medic.getNumeMedic()<<" are specializarea: "<<medic.getSpecializare() << std::endl;
                        }
                        std::cout << "Apasa Enter pentru a continua...";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // In case a previous std::cin left a newline
                        std::cin.get();
                        break;
                    }
                    case 4:{//medicii pe sectii
                        clearScreen();
                        std::cout << "Medicii din sectia de cardiologie sunt: " << std::endl;
                        sectieCardiologie.getMediciCardiologie();
                        std::cout << std::endl;
                        std::cout << "Medicii din sectia de chirurgie sunt: " << std::endl;
                        sectieChirurgie.getMediciChirurgie();
                        std::cout << std::endl;
                        std::cout << "Medicii din sectia de pediatrie sunt: " << std::endl;
                        sectiePediatrie.getMediciPediatrie();
                        std::cout << std::endl;
                        std::cout << "Apasa Enter pentru a continua...";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin.get();
                        break;
                    }
                    case 5:{//afiseaza detalii pacient
                        std::string nume;
                        std::cout << "Introduceti numele pacientului: ";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        getline(std::cin, nume); 
                        Pacient* pacientGasit = spital.cautaPacient(nume);
                        if (!pacientGasit) {
                            clearScreen();
                            std::cout << "Pacientul " << nume << " nu exista!" << std::endl;
                            std::cout << "Apasa Enter pentru a continua...";
                            std::cin.get();
                            break;
                        }
                        clearScreen();
                        pacientGasit->afisareDetalii();
                        std::cout << "Apasa Enter pentru a continua...";
                        std::cin.get();
                        break;
                    }
                    case 6:{//detalii consulatie si retete
                        std::string nume;
                        std::cout << "Numele pacientului pentru care doriti sa vedeti consultatiile: ";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        getline(std::cin, nume);
                        Pacient* pacientGasit = spital.cautaPacient(nume);
                        if (!pacientGasit) {
                            clearScreen();
                            std::cout << "Pacientul " << nume << " nu exista!" << std::endl;
                            break;
                        }
                        std::cout << "\033[2J\033[1;1H";
                        std::cout << "Consultatiile pacientului " << nume << ":" << std::endl<< std::endl;

                        std::vector<Consultatie> listaConsultatii = spital.getConsultatii();
                        for (auto& consultatie : listaConsultatii) {
                            if (consultatie.getPacient() == pacientGasit) {
                                consultatie.afisareDetalii();
                            }
                        }

                        std::cout<<std::endl<< "Retelele pacientului "<<nume<< " sunt: \n";
                        for(auto& reteta: spital.getRetete()){
                            if(reteta.getPacient()==pacientGasit){
                                reteta.afisareReteta();
                            }
                        }
                        std::cout << "Apasa Enter pentru a continua...";
                        std::cin.get();
                        break;
                    }
                    case 7:
                        clearScreen();
                        inapoiLaMeniu = true;
                        loggedIn = false;
                        break;
                    
                    case 8:
                    clearScreen();
                    std::cout << "Multumesc ca ai folosit aplicatia!<3" << std::endl;
                        return 0;

                    default:
                    clearScreen();
                    std::cout << "Optiune invalida! Te rog sa alegi o optiune valida." << std::endl;
                    std::cout << "Apasa Enter pentru a continua...";
                    std::cin.get();
                    break;
                }
            }
        }
    }

    return 0;
}