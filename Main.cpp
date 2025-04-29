//single functionality, design pattern
// Folosim #include doar acolo unde chiar avem nevoie de corpul complet al clasei (ex: când apelăm metode sau accesăm membri).

// Folosim class NumeClasa; acolo unde avem doar pointeri sau referințe, și nu apelăm metode.



#include <iostream>
#include <cctype> //pt toupper
#include <string>
#include <vector>
#include <limits>//pt numeric_limits
#include "Spital.h"
using namespace std;

int main() {
    Spital spital;
    bool ok=true;
    int optiune;
    string account;
    bool loggedIn=false;
    bool inapoiLaMeniu=false;

    while (true) {
        do {
            cout << "         ------SPITAL------" << endl;
            cout << "Ca ce vrei sa te loghezi?" << endl;
            cout << "1. Medic [M]" << endl;

            cout << "2. Pacient [P]" << endl;
            cout << "Alegerea ta: ";
            cin >> account;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
                    cout << "Cont invalid! Te rog sa alegi M (medic) sau P (pacient)." << endl;
                    cout << "Apasa Enter pentru a continua...";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
            }

            system("cls");
        } while (!loggedIn);

        inapoiLaMeniu = false;

        while (!inapoiLaMeniu) {
            if (account == "medicului") {
                cout << "         ------SPITAL------" << endl;
                cout << "~~~~~~~~Bun venit in meniul " << account << "!~~~~~~~~" << endl;
                cout << "1. Inregistreaza medic" << endl;
                cout << "2. Afiseaza consultatii" << endl;
                cout << "3. Afiseaza pacientii" << endl;
                cout << "4. Afiseaza detalii pacient" << endl;
                cout << "5. Afiseaza detalii consultatie" << endl;
                cout << "6. Iesi din program" << endl;
                cout << "7. Inapoi la meniul principal" << endl;
                cout << "Introduceti optiunea: ";
                cin >> optiune;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\033[2J\033[1;1H";
                    cout << "Optiune invalida! Te rog sa introduci un numar valid." << endl;
                    continue;
                }

                switch (optiune) {
                    case 1: {//adauga medic
                        string nume;
                        int varsta;
                        string cnp;
                        string specializare;
                        cout << "Introduceti numele medicului: ";
                        cin.ignore();//curata buffer ul pentru a nu citi si din cin ul precedent
                        getline(cin, nume);
                        cout << "Introduceti varsta medicului: ";
                        cin >> varsta;
                        cout << "Introduceti CNP-ul medicului: ";
                        cin >> cnp;
                        cout << "Introduceti specializarea medicului: ";
                        cin >> specializare;
                        Medic medic(nume, varsta, cnp, specializare);
                        spital.adaugaMedic(medic);
                        cout << "\033[2J\033[1;1H";
                        cout << "Medicul " << medic.getNumeMedic() << " a fost adaugat cu succes!" << endl;
                        break;
                    }
                    case 2: {//afiseaza consultatii
                        string numeMedic;
                        cout << "Numele medicului pentru care doriti sa vedeti consultatiile: ";
                        cin >> numeMedic;
                        vector<Medic>& listaMedici = spital.getMedici();
                        Medic* medicGasit = nullptr;
                        for (auto& medic : listaMedici) {
                            if (medic.getNumeMedic() == numeMedic) {
                                medicGasit = &medic;
                                break;
                            }
                        }
                        if (!medicGasit) {
                            cout << endl << "Medic inexistent!" << endl << endl;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cin.get();
                            cout << "\033[2J\033[1;1H";
                            break;
                        }
                        medicGasit->afisareConsultatii(spital.getConsultatii(), medicGasit);
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin.get();
                        cout << "\033[2J\033[1;1H";
                        break;
                    }
                    case 3: {//afiseaza pacientii
                        string nume;
                        cout<<"Introduceti numele medicului: "<<endl;
                        cin.ignore();
                        getline(cin,nume);
                        cout<<"\033[2J\033[1;1H";
                        Medic* medicGasit = spital.cautaMedic(nume);
                        if (!medicGasit) {
                            cout << "\033[2J\033[1;1H";
                            cout << "Medicul " << nume << " nu exista!" << endl;
                            
                            break;
                        }
                        vector<Consultatie>& listaConsultatii = spital.getConsultatii();
                        bool pacientiGasiti = false;
                        cout << "Pacientii medicului "<<nume<< " sunt: "<<endl;
                        for(auto& consultatie: listaConsultatii){
                            Medic* medic = consultatie.getMedic();
                            Pacient* pacient = consultatie.getPacient();
                            if (medic && pacient && medic->getNumeMedic() == nume) {
                                pacient->afisareDetalii();
                                pacientiGasiti = true;
                                cout<<endl<<endl;
                            }
                        }
                        if (!pacientiGasiti) {
                            cout << "Nu exista pacienti pentru acest medic." << endl;
                        }
                        break;
                    }
                    case 4:{//
                        break;
                    }
                    case 5:
                    case 6:
                        cout << "\033[2J\033[1;1H";
                        cout << "Multumesc ca ai folosit aplicatia!<3" << endl;
                        return 0;
                    case 7:
                        cout << "\033[2J\033[1;1H";
                        inapoiLaMeniu = true;
                        loggedIn = false;
                        break;
                        // case 8: {//cu retetaaaaaa
                        //     string numePacient, data;
                        //     cout << "Introduceti numele pacientului: ";
                        //     cin.ignore();
                        //     getline(cin, numePacient);
                        //     cout << "Introduceti data consultatiei (ex: 2025-04-23): ";
                        //     getline(cin, data);
                        
                        //     vector<Consultatie>& listaConsultatii = spital.getConsultatii();
                        //     Consultatie* consultatieGasita = nullptr;
                        //     for (auto& consultatie : listaConsultatii) {
                        //         if (consultatie.getPacient() && consultatie.getPacient()->getNumePacient() == numePacient && consultatie.getData() == data) {
                        //             consultatieGasita = &consultatie;
                        //             break;
                        //         }
                        //     }
                        
                        //     if (!consultatieGasita) {
                        //         cout << "Consultatie inexistenta!" << endl;
                        //         break;
                        //     }
                        
                        //     cout << "Detalii consultatie:" << endl;
                        //     consultatieGasita->afisareDetalii();
                        
                        //     Reteta& reteta = consultatieGasita->getReteta();
                        //     if (!reteta.getMedicamente().empty()) {
                        //         cout << "Reteta exista deja. Iata medicamentele:\n";
                        //         reteta.afisareReteta();
                        //         cout << "Doriti sa adaugati si alte medicamente? (da/nu): ";
                        //         string raspuns;
                        //         getline(cin, raspuns);
                        //         if (raspuns != "da") break;
                        //     }
                        
                        //     while (true) {
                        //         string medicament;
                        //         cout << "Introduceti un medicament (sau scrie 'stop' pentru a termina): ";
                        //         getline(cin, medicament);
                        //         if (medicament == "stop") break;
                        //         reteta.adaugaMedicament(medicament);
                        //     }
                        
                        //     cout << "Reteta a fost actualizata cu succes!" << endl;
                        //     break;
                        // }
                        
                    default:
                        cout << "\033[2J\033[1;1H";
                        cout << "Optiune invalida! Te rog sa alegi o optiune valida." << endl;
                        break;
                }
            } else if (account == "pacientului") {
                cout << "         ------SPITAL------" << endl;
                cout << "~~~~~~~~Bun venit in meniul " << account << "!~~~~~~~~" << endl;
                cout << "1. Inregistreaza-te" << endl;
                cout << "2. Programeaza consultatie" << endl;
                cout << "3. Afiseaza medicii" << endl;
                cout << "4. Afiseaza detalii pacient" << endl;
                cout << "5. Afiseaza detalii consultatie" << endl;
                cout << "6. Iesi din program" << endl;
                cout << "7. Inapoi la meniul principal" << endl;
                cout << "Introduceti optiunea: ";
                cin >> optiune;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\033[2J\033[1;1H";
                    cout << "Optiune invalida! Te rog sa introduci un numar valid." << endl;
                    continue;
                }
                switch (optiune) {
                    case 1: {//inregistrare pacient

                        string nume;
                        int varsta;
                        string cnp;
                        cout << "Introduceti numele pacientului: ";
                        cin.ignore();
                        getline(cin, nume);
                        cout << "Introduceti varsta pacientului: ";
                        cin >> varsta;
                        cout << "Introduceti CNP-ul pacientului: ";
                        cin >> cnp;
                        Pacient pacient(nume, varsta, cnp);
                        spital.adaugaPacient(pacient);
                        cout << "\033[2J\033[1;1H";
                        cout<<"Pacientul "<<pacient.getNumePacient()<< " a fost adaugat cu succes!"<<endl;
                        
                        break;
                    }
                    case 2: {//adauga consultatie
                        string numeP, numeM, data, diagnostic;
                        cout << "Introduceti numele pacientului: ";
                        cin.ignore();
                        getline(cin, numeP);
                        cout << "Introduceti numele medicului: ";
                        getline(cin, numeM);
                        Pacient* pacientGasit = spital.cautaPacient(numeP);
                        Medic* medicGasit = spital.cautaMedic(numeM);

                        if (!pacientGasit) {
                            cout << "\033[2J\033[1;1H";
                            cout << "Pacientul " << numeP << " nu exista!" << endl;
                            
                            break;
                        }
                        if (!medicGasit) {
                            cout << "\033[2J\033[1;1H";
                            cout << "Medicul " << numeM << " nu exista!" << endl;
                            
                            break;
                        }

                        cout << "Introduceti data consultatiei(ZZ-LL-AAAA): ";
                        cin >> data;
                        cout << "Introduceti problema pe care o aveti: ";
                        cin.ignore();
                        getline(cin, diagnostic);
                        pacientGasit->adaugaIstoricMedical(diagnostic);


                        Consultatie consultatie(pacientGasit, medicGasit, data, diagnostic);
                        spital.adaugaConsultatie(consultatie);
                        cout << "\033[2J\033[1;1H";
                        cout << "Programarea a fost facuta cu succes!" << endl;
                        
                        break;
                    }
                    case 3:{//afiseaza medicii
                        cout << "\033[2J\033[1;1H";
                        cout << "Medicii disponibili sunt: " << endl;
                        for (auto& medic :spital.getMedici()){
                            cout << "Medicul: "<<medic.getNumeMedic()<<" are specializarea: "<<medic.getSpecializare() << endl;
                        }
                        break;
                    }
                    case 4:{//afiseaza detalii pacient
                        string nume;
                        cout << "Introduceti numele pacientului: ";
                        cin>>nume;
                        Pacient* pacientGasit = spital.cautaPacient(nume);
                        if (!pacientGasit) {
                            cout << "\033[2J\033[1;1H";
                            cout << "Pacientul " << nume << " nu exista!" << endl;
                            
                            break;
                        }
                        pacientGasit->afisareDetalii();
                        
                        break;
                    }
                    case 5:{//detalii consulatie
                        // string nume;
                        // cout << "Numele pacientului pentru care doriti sa vedeti consultatiile: ";
                        // cin >> nume;
                        // Pacient* pacientGasit = spital.cautaPacient(nume);
                        // if (!pacientGasit) {
                        //     cout << "\033[2J\033[1;1H";
                        //     cout << "Pacientul " << nume << " nu exista!" << endl;
                        //     break;
                        // }
                        // cout << "\033[2J\033[1;1H";
                        // cout << "Consultatiile pacientului " << nume << ":" << endl;

                        // vector<Consultatie> listaConsultatii = spital.getConsultatii();
                        // bool gasit = false;
                        // for (auto& consultatie : listaConsultatii) {
                        //     if (consultatie.getPacient() == pacientGasit) {
                        //         consultatie.afisareDetalii();
                        //         gasit = true;
                        //     }
                        // }

                        // if (!gasit) {
                        //     cout << "Nu exista consultatii pentru acest pacient." << endl;
                        // }

                        break;
                    }
                    case 6:
                        cout << "\033[2J\033[1;1H";
                        cout << "Multumesc ca ai folosit aplicatia!<3" << endl;
                        return 0;
                    case 7:
                        cout << "\033[2J\033[1;1H";
                        inapoiLaMeniu = true;
                        loggedIn = false;
                        break;
                    default:
                        cout << "\033[2J\033[1;1H";
                        cout << "Optiune invalida! Te rog sa alegi o optiune valida." << endl;
                        break;
                }
            }
        }
    }

    return 0;
}
