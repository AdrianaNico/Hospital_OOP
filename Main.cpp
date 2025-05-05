//single functionality, design pattern
// Folosim #include doar acolo unde chiar avem nevoie de corpul complet al clasei (ex: când apelăm metode sau accesăm membri).

// Folosim class NumeClasa; acolo unde avem doar pointeri sau referințe, și nu apelăm metode.



#include <iostream>
#include <cctype> //pt toupper
#include <string>
#include <vector>
#include <limits>//pt numeric_limits
#include "Spital.h"

int main() {
    Spital spital;
    bool ok=true;
    int optiune;
    std::string account;
    bool loggedIn=false;
    bool inapoiLaMeniu=false;

    while (true) {
        do {
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
                std::cout << "Cont invalid! Te rog sa alegi M (medic) sau P (pacient)." << std::endl;
                std::cout << "Apasa Enter pentru a continua...";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
            }

            system("cls");
        } while (!loggedIn);

        inapoiLaMeniu = false;

        while (!inapoiLaMeniu) {
            if (account == "medicului") {
                std::cout << "         ------SPITAL------" << std::endl;
                std:: cout << "~~~~~~~~Bun venit in meniul " << account << "!~~~~~~~~" << std::endl;
                std::cout << "1. Inregistreaza medic" << std::endl;
                std::cout << "2. Afiseaza consultatii" << std::endl;
                std::cout << "3. Afiseaza pacientii" << std::endl;
                std::cout << "4. Afiseaza detalii pacient" << std::endl;
                //std::cout << "5. Afiseaza detalii consultatie" << std::endl;
                std::cout<< "5.prescriere reteta"<<std::endl;
                std::cout << "6. Iesi din program" << std::endl;
                std::cout << "7. Inapoi la meniul principal" << std::endl;
                std::cout << "Introduceti optiunea: ";
                std::cin >> optiune;

                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std:: cout<< "\033[2J\033[1;1H";
                    std::cout << "Optiune invalida! Te rog sa introduci un numar valid." << std::endl;
                    continue;
                }

                switch (optiune) {
                    case 1: {//adauga medic
                        std::string nume;
                        int varsta;
                        std::string cnp;
                        std::string specializare;
                        std::cout << "Introduceti numele medicului: ";
                        std::cin.ignore();//curata buffer ul pentru a nu citi si din cin ul precedent
                        getline(std::cin, nume);
                        std::cout << "Introduceti varsta medicului: ";
                        std::cin >> varsta;
                        std::cout << "Introduceti CNP-ul medicului: ";
                        std::cin >> cnp;
                        std::cout << "Introduceti specializarea medicului: ";
                        std::cin >> specializare;
                        Medic medic(nume, varsta, cnp, specializare);
                        spital.adaugaMedic(medic);
                        std::cout << "\033[2J\033[1;1H";
                        std::cout << "Medicul " << medic.getNumeMedic() << " a fost adaugat cu succes!" << std::endl;
                        break;
                    }
                    case 2: {//afiseaza consultatii
                        std::string numeMedic;
                        std::cout << "Numele medicului pentru care doriti sa vedeti consultatiile: ";
                        std::cin >> numeMedic;
                        std::vector<Medic>& listaMedici = spital.getMedici();
                        Medic* medicGasit = nullptr;
                        for (auto& medic : listaMedici) {
                            if (medic.getNumeMedic() == numeMedic) {
                                medicGasit = &medic;
                                break;
                            }
                        }
                        if (!medicGasit) {
                            std::cout << std::endl << "Medic inexistent!" << std::endl << std::endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cin.get();
                            std::cout << "\033[2J\033[1;1H";
                            break;
                        }
                        medicGasit->afisareConsultatii(spital.getConsultatii(), medicGasit);
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin.get();
                        std::cout << "\033[2J\033[1;1H";
                        break;
                    }
                    case 3: {//afiseaza pacientii
                        std:: string nume;
                        std::cout<<"Introduceti numele medicului: "<<std::endl;
                        std::cin.ignore();
                        getline(std::cin,nume);
                        std::cout<<"\033[2J\033[1;1H";
                        Medic* medicGasit = spital.cautaMedic(nume);
                        if (!medicGasit) {
                            std::cout << "\033[2J\033[1;1H";
                            std::cout << "Medicul " << nume << " nu exista!" << std::endl;
                            
                            break;
                        }
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
                        break;
                    }
                    case 4:{//
                        break;
                    }
                    case 5:
                    case 6:
                    std::cout << "\033[2J\033[1;1H";
                    std::cout << "Multumesc ca ai folosit aplicatia!<3" << std::endl;
                        return 0;
                    case 7:
                    std::cout << "\033[2J\033[1;1H";
                        inapoiLaMeniu = true;
                        loggedIn = false;
                        break;
                        // case 8: {//cu retetaaaaaa
                        //     std::string numePacient, data;
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
                        //        std:: string raspuns;
                        //         getline(cin, raspuns);
                        //         if (raspuns != "da") break;
                        //     }
                        
                        //     while (true) {
                        //         std::string medicament;
                        //         cout << "Introduceti un medicament (sau scrie 'stop' pentru a termina): ";
                        //         getline(cin, medicament);
                        //         if (medicament == "stop") break;
                        //         reteta.adaugaMedicament(medicament);
                        //     }
                        
                        //     cout << "Reteta a fost actualizata cu succes!" << endl;
                        //     break;
                        // }
                        
                    default:
                    std::cout << "\033[2J\033[1;1H";
                    std::cout << "Optiune invalida! Te rog sa alegi o optiune valida." << std::endl;
                        break;
                }
            } else if (account == "pacientului") {
                std::cout << "         ------SPITAL------" << std::endl;
                std::cout << "~~~~~~~~Bun venit in meniul " << account << "!~~~~~~~~" << std::endl;
                std::cout << "1. Inregistreaza-te" << std::endl;
                std::cout << "2. Programeaza consultatie" << std::endl;
                std::cout << "3. Afiseaza medicii" << std::endl;
                std::cout << "4. Afiseaza detalii pacient" << std::endl;
                std::cout << "5. Afiseaza detalii consultatie" << std::endl;
                std::cout << "6. Iesi din program" << std::endl;
                std::cout << "7. Inapoi la meniul principal" << std::endl;
                std::cout << "Introduceti optiunea: ";
                std::cin >> optiune;

                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\033[2J\033[1;1H";
                    std::cout << "Optiune invalida! Te rog sa introduci un numar valid." << std::endl;
                    continue;
                }
                switch (optiune) {
                    case 1: {//inregistrare pacient

                        std:: string nume;
                        int varsta;
                        std:: string cnp;
                        std::cout << "Introduceti numele pacientului: ";
                        std::cin.ignore();
                        getline(std::cin, nume);
                        std::cout << "Introduceti varsta pacientului: ";
                        std::cin >> varsta;
                        std::cout << "Introduceti CNP-ul pacientului: ";
                        std::cin >> cnp;
                        Pacient pacient(nume, varsta, cnp);
                        spital.adaugaPacient(pacient);
                        std::cout << "\033[2J\033[1;1H";
                        std::cout<<"Pacientul "<<pacient.getNumePacient()<< " a fost adaugat cu succes!"<<std::endl;
                        
                        break;
                    }
                    case 2: {//adauga consultatie
                        std::string numeP, numeM, data, diagnostic;
                        std:: cout << "Introduceti numele pacientului: ";
                        std::cin.ignore();
                        getline(std::cin, numeP);
                        std::cout << "Introduceti numele medicului: ";
                        getline(std::cin, numeM);
                        Pacient* pacientGasit = spital.cautaPacient(numeP);
                        Medic* medicGasit = spital.cautaMedic(numeM);

                        if (!pacientGasit) {
                            std:: cout << "\033[2J\033[1;1H";
                            std::cout << "Pacientul " << numeP << " nu exista!" << std::endl;
                            
                            break;
                        }
                        if (!medicGasit) {
                            std::cout << "\033[2J\033[1;1H";
                            std::cout << "Medicul " << numeM << " nu exista!" << std::endl;
                            
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
                        
                        break;
                    }
                    case 3:{//afiseaza medicii
                        std::cout << "\033[2J\033[1;1H";
                        std::cout << "Medicii disponibili sunt: " << std::endl;
                        for (auto& medic :spital.getMedici()){
                            std::cout << "Medicul: "<<medic.getNumeMedic()<<" are specializarea: "<<medic.getSpecializare() << std::endl;
                        }
                        break;
                    }
                    case 4:{//afiseaza detalii pacient
                        std::string nume;
                        std::cout << "Introduceti numele pacientului: ";
                        std::cin>>nume;
                        Pacient* pacientGasit = spital.cautaPacient(nume);
                        if (!pacientGasit) {
                            std::cout << "\033[2J\033[1;1H";
                            std::cout << "Pacientul " << nume << " nu exista!" << std::endl;
                            
                            break;
                        }
                        std::cout << "\033[2J\033[1;1H";
                        pacientGasit->afisareDetalii();
                        
                        break;
                    }
                    case 5:{//detalii consulatie
                        // std::string nume;
                        // std::cout << "Numele pacientului pentru care doriti sa vedeti consultatiile: ";
                        // cin >> nume;
                        // Pacient* pacientGasit = spital.cautaPacient(nume);
                        // if (!pacientGasit) {
                        //     std::cout << "\033[2J\033[1;1H";
                        //     std::cout << "Pacientul " << nume << " nu exista!" << endl;
                        //     break;
                        // }
                        // std::cout << "\033[2J\033[1;1H";
                        // std::cout << "Consultatiile pacientului " << nume << ":" << endl;

                        // vector<Consultatie> listaConsultatii = spital.getConsultatii();
                        // bool gasit = false;
                        // for (auto& consultatie : listaConsultatii) {
                        //     if (consultatie.getPacient() == pacientGasit) {
                        //         consultatie.afisareDetalii();
                        //         gasit = true;
                        //     }
                        // }

                        // if (!gasit) {
                        //     std::cout << "Nu exista consultatii pentru acest pacient." << endl;
                        // }

                        break;
                    }
                    case 6:
                    std::cout << "\033[2J\033[1;1H";
                    std::cout << "Multumesc ca ai folosit aplicatia!<3" << std::endl;
                        return 0;
                    case 7:
                    std::cout << "\033[2J\033[1;1H";
                        inapoiLaMeniu = true;
                        loggedIn = false;
                        break;
                    default:
                    std::cout << "\033[2J\033[1;1H";
                    std::cout << "Optiune invalida! Te rog sa alegi o optiune valida." << std::endl;
                        break;
                }
            }
        }
    }

    return 0;
}