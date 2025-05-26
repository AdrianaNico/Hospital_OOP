// Folosim #include doar acolo unde chiar avem nevoie de corpul complet al clasei (ex: când apelăm metode sau accesăm membri).
// Folosim class NumeClasa; acolo unde avem doar pointeri sau referințe, și nu apelăm metode.

//a se rula cu: g++ main.cpp consultatie.cpp medic.cpp pacient.cpp persoana.cpp reteta.cpp spital.cpp sectie_cardiologie.cpp sectie_chirurgie.cpp sectie_pediatrie.cpp -o main.exe

#include <iostream>
#include <cctype> //pt toupper
#include <string>
#include <vector>
#include <sstream> //pt istringstream
#include <limits>//pt numeric_limits
#include "spital.h"
#include "sectie_cardiologie.h"
#include "sectie_chirurgie.h"
#include "sectie_pediatrie.h"

int main() {
    Spital spital;
    SectieCardiologie sectie_cardiologie;
    SectieChirurgie sectie_chirurgie;
    SectiePediatrie sectie_pediatrie;


    bool ok=true;
    int optiune;
    std::string account;
    bool logged_in=false;
    bool inapoi_la_meniu=false;

    auto clear_screen = []() {//functie lambda pt curatarea terminalului
#ifdef _WIN32
        system("cls");//pt Windows
#else
        std::cout << "\033[2J\033[1;1H";//linux, macos
#endif
        std::cout.flush();
    };
    while (true) {
        do {
            clear_screen();
            std::cout << "         ------SPITAL------" << std::endl;
            std::cout << "Ca ce vrei sa te loghezi?" << std::endl;
            std::cout << "1. Medic [M]" << std::endl;

            std::cout << "2. Pacient [P]" << std::endl;
            std::cout << "Alegerea ta: ";
            std::cin >> account;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch (toupper(account[0])) {
                case 'M':
                    logged_in = true;
                    account = "medicului";
                    break;
                case 'P':
                    logged_in = true;
                    account = "pacientului";
                    break;
                default:
                clear_screen();
                std::cout << "Cont invalid! Te rog sa alegi M (medic) sau P (pacient)." << std::endl;
                std::cout << "Apasa Enter pentru a continua...";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
            }

        } while (!logged_in);

        inapoi_la_meniu = false;

        while (!inapoi_la_meniu) {
            clear_screen();
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
                    clear_screen();
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
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        getline(std::cin, nume);
                        std::cout << "Introduceti varsta medicului: ";
                        std::cin >> varsta;
                        std::cout << "Introduceti CNP-ul medicului: ";
                        std::cin >> cnp;
                        std::cout << "Introduceti specializarea medicului: ";
                        std::cin.ignore();
                        getline(std::cin, specializare);
                        bool cnp_valid = false;
                        while(!cnp_valid){
                            if(Persoana::IsValidCnp(cnp)){
                                cnp_valid = true;
                            }
                            else{
                                clear_screen();
                                std::cout << "CNP invalid! Te rog sa introduci un CNP valid: ";
                                std::cin >> cnp;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                        }
                        Medic medic(nume, varsta, cnp, specializare);
                        spital.AdaugaMedic(medic);
                        clear_screen();
                        std::cout << "Medicul " << medic.GetNumeMedic() << " a fost adaugat cu succes!" << std::endl;
                        std::cout << "Apasa Enter pentru a continua...";
                        std::cin.get();
                        break;
                    }
                    case 2:{//adauga in sectie
                        std::string nume_medic;
                        std::string sectie;
                        Medic* medic_gasit = nullptr;
                        std::cout << "Introduceti numele medicului: ";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        getline(std::cin, nume_medic);
                        medic_gasit = spital.CautaMedic(nume_medic);
                        if(!medic_gasit){
                            clear_screen();
                            std::cout << "Medicul " << nume_medic << " nu exista!" << std::endl;
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
                            sectie_cardiologie.AdaugaMedicSectieCardiologie(*medic_gasit);  
                            clear_screen();
                            std:: cout << "Medicul " <<medic_gasit->GetNumeMedic() << " a fost adaugat in sectia de cardiologie!" << std::endl;
                            std::cout << "Apasa Enter pentru a continua...";
                            std::cin.get();
                        }
                        else if(sectie == "CH"){
                            sectie_chirurgie.AdaugaMedicSectieChirurgie(*medic_gasit);
                            clear_screen();
                            std:: cout << "Medicul " <<medic_gasit->GetNumeMedic() << " a fost adaugat in sectia de chirurgie!" << std::endl;
                            std::cout << "Apasa Enter pentru a continua...";
                            std::cin.get();
                        }
                        else if(sectie == "PD"){
                            sectie_pediatrie.AdaugaMedicSectiePediatrie(*medic_gasit);
                            clear_screen();
                            std:: cout << "Medicul " <<medic_gasit->GetNumeMedic() << " a fost adaugat in sectia de pediatrie!" << std::endl;
                            std::cout << "Apasa Enter pentru a continua...";
                            std::cin.get();
                        }
                        else{
                            clear_screen();
                            std:: cout << "Sectia nu exista!" << std::endl;
                            std::cout << "Apasa Enter pentru a continua...";
                            std::cin.get();
                        }
                        
                    break;
                    }
                    case 3: {//afiseaza consultatii
                        std::string nume_medic;
                        std::cout << "Numele medicului pentru care doriti sa vedeti consultatiile: ";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        getline(std::cin, nume_medic);
                        std::vector<std::unique_ptr<Medic>>& lista_medici = spital.GetMedici();
                        Medic* medic_gasit = nullptr;
                        for (const auto& medic_ptr : lista_medici) {
                            if (medic_ptr->GetNumeMedic() == nume_medic) {
                                medic_gasit = medic_ptr.get(); // Obținem pointerul brut( il "de-pointuim")
                                break;
                            }
                        }
                        if (!medic_gasit) {
                            clear_screen();
                            std::cout << std::endl << "Medic inexistent!" << std::endl << std::endl;
                            std::cout << "Apasa Enter pentru a continua...";
                            std::cin.get();
                            break;
                        }
                        clear_screen();
                        std::cout << "Consultatiile medicului " << medic_gasit->GetNumeMedic() << " sunt: " << std::endl<< std::endl;
                        medic_gasit->AfisareConsultatii(spital.GetConsultatii(), medic_gasit);
                        std::cout<< "Apasa Enter pentru a continua...";
                        std::cin.get();
                        break;
                    }
                    case 4: {//afiseaza pacientii
                        std:: string nume;
                        std::cout<<"Introduceti numele medicului: "<<std::endl;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        getline(std::cin, nume);
                        Medic* medic_gasit = spital.CautaMedic(nume);
                        if (!medic_gasit) {
                            clear_screen();
                            std::cout << "Medicul " << nume << " nu exista!" << std::endl;
                            std::cout << "Apasa Enter pentru a continua...";
                            std::cin.get();
                            break;
                        }
                        clear_screen();
                        std::vector<Consultatie>& lista_consultatii = spital.GetConsultatii();
                        bool pacienti_gasiti = false;
                        std::cout << "Pacientii medicului "<<nume<< " sunt: "<<std::endl;
                        for(auto& consultatie: lista_consultatii){
                            Medic* medic = consultatie.GetMedic();
                            Pacient* pacient = consultatie.GetPacient();
                            if (medic && pacient && medic->GetNumeMedic() == nume) {
                                pacient->AfisareDetalii();
                                pacienti_gasiti = true;
                                std::cout<<std::endl<<std::endl;
                            }
                        }
                        if (!pacienti_gasiti) {
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
                        Pacient* pacient_gasit = spital.CautaPacient(nume);
                        if (!pacient_gasit) {
                            clear_screen();
                            std::cout << "Pacientul " << nume << " nu exista!" << std::endl;
                            std::cout << "Apasa Enter pentru a continua...";
                            std::cin.get();
                            break;
                        }
                        clear_screen();
                        std::cout << *pacient_gasit;
                        bool retete_gasite = false;
                        std::cout<<"Retetele pacientului: \n";
                        for(auto& reteta: spital.GetRetete()){
                            if(reteta.GetPacient()->GetNumePacient()==pacient_gasit->GetNumePacient()){
                                retete_gasite = true;
                                reteta.AfisareReteta();
                            }
                        }
                        if(!retete_gasite){
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
                        Medic* medic_gasit = spital.CautaMedic(nume_medic);
                        Pacient* pacient_gasit = spital.CautaPacient(nume_pacient);
                        if (!medic_gasit) {
                            clear_screen();
                            std::cout << "Medicul " << nume_medic << " nu exista!" << std::endl;
                            std::cout << "Apasa Enter pentru a continua...";
                            std::cin.get();
                            break;
                        }
                        if (!pacient_gasit) {
                            clear_screen();
                            std::cout << "Pacientul " << nume_pacient << " nu exista!" << std::endl;
                            std::cout << "Apasa Enter pentru a continua...";
                            std::cin.get();
                            break;
                        }
                        if(!spital.ExistaConsultatie(nume_medic, nume_pacient)){
                            std::cout << "Nu exista consultatie intre medicul " << nume_medic << " si pacientul " << nume_pacient << std::endl;
                            std::cout << "Apasa Enter pentru a continua...";
                            std::cin.get();
                        }else{
                            clear_screen();
                            std::cout<<"Introduceti medicamentele prescrise (separati prin spatiu): ";
                            std::string medicamente_input;
                            getline(std::cin, medicamente_input);
                            std::istringstream ss(medicamente_input);// trateaza stringul ca pe un stream, adica vede cuvintele ca fiind separate prin spatiu

                            std::string medicament;
                            while(ss >>medicament){//se iau cuvintele pe rand din ss si se pun in medicament
                                medicamente.push_back(medicament);
                            }
                            Reteta reteta(pacient_gasit, medic_gasit, medicamente);
                            spital.AdaugaReteta(reteta);
                            clear_screen();
                            std::cout << "Reteta a fost creata cu succes!" << std::endl;
                            std::cout << "Apasa Enter pentru a continua...";
                            std::cin.get();
                        }
                        
                        break;
                    }
                    case 7:
                        clear_screen();
                        inapoi_la_meniu = true;
                        logged_in = false;
                        break;
                    
                    case 8:
                    std::cout << "\033[2J\033[1;1H";
                    std::cout << "Multumesc ca ai folosit aplicatia!<3" << std::endl;
                    return 0;
                        
                    default:
                    clear_screen();
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
                    clear_screen();
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
                        bool cnp_valid = false;
                        while(!cnp_valid){
                            if(Persoana::IsValidCnp(cnp)){
                                cnp_valid = true;
                            }
                            else{
                                clear_screen();
                                std::cout << "CNP invalid! Te rog sa introduci un CNP valid: ";
                                std::cin >> cnp;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                        }
                        Pacient pacient(nume, varsta, cnp);
                        spital.AdaugaPacient(pacient);
                        clear_screen();
                        std::cout<<"Pacientul "<<pacient.GetNumePacient()<< " a fost adaugat cu succes!"<<std::endl;
                        std::cout << "Apasa Enter pentru a continua...";
                        std::cin.get();
                        break;
                    }
                    case 2: {//adauga consultatie
                        std::string nume_pacient, nume_medic, data, diagnostic;
                        std:: cout << "Introduceti numele pacientului: ";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        getline(std::cin, nume_pacient);
                        std::cout << "Introduceti numele medicului: ";
                        getline(std::cin, nume_medic);
                        Pacient* pacient_gasit = spital.CautaPacient(nume_pacient);
                        Medic* medic_gasit = spital.CautaMedic(nume_medic);

                        if (!pacient_gasit) {
                            clear_screen();
                            std::cout << "Pacientul " << nume_pacient << " nu exista!" << std::endl;
                            std::cout << "Apasa Enter pentru a continua...";
                            std::cin.get();
                            break;
                        }
                        if (!medic_gasit) {
                            clear_screen();
                            std::cout << "Medicul " << nume_medic << " nu exista!" << std::endl;
                            std::cout << "Apasa Enter pentru a continua...";
                            std::cin.get();
                            break;
                        }

                        std::cout << "Introduceti data consultatiei(ZZ-LL-AAAA): ";
                        std::cin >> data;
                        std::cout << "Introduceti problema pe care o aveti: ";
                        std::cin.ignore();
                        getline(std::cin, diagnostic);
                        pacient_gasit->AdaugaIstoricMedical(diagnostic);


                        Consultatie consultatie(pacient_gasit, medic_gasit, data, diagnostic);
                        spital.AdaugaConsultatie(consultatie);
                        std::cout << "\033[2J\033[1;1H";
                        std::cout << "Programarea a fost facuta cu succes!" << std::endl;
                        std::cout << "Apasa Enter pentru a continua...";
                        std::cin.get();
                        break;
                    }
                    case 3:{//afiseaza medicii
                        clear_screen();
                        std::cout << "Medicii disponibili sunt: " << std::endl;
                        for (const auto& medic_ptr :spital.GetMedici()){
                            std::cout << "Medicul: "<<medic_ptr->GetNumeMedic()<<" are specializarea: "<<medic_ptr->GetSpecializare() << std::endl;
                        }
                        std::cout << "Apasa Enter pentru a continua...";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // In case a previous std::cin left a newline
                        std::cin.get();
                        break;
                    }
                    case 4:{//medicii pe sectii
                        clear_screen();
                        std::cout << "Medicii din sectia de cardiologie sunt: " << std::endl;
                        sectie_cardiologie.GetMediciCardiologie();
                        std::cout << std::endl;
                        std::cout << "Medicii din sectia de chirurgie sunt: " << std::endl;
                        sectie_chirurgie.GetMediciChirurgie();
                        std::cout << std::endl;
                        std::cout << "Medicii din sectia de pediatrie sunt: " << std::endl;
                        sectie_pediatrie.GetMediciPediatrie();
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
                        Pacient* pacient_gasit = spital.CautaPacient(nume);
                        if (!pacient_gasit) {
                            clear_screen();
                            std::cout << "Pacientul " << nume << " nu exista!" << std::endl;
                            std::cout << "Apasa Enter pentru a continua...";
                            std::cin.get();
                            break;
                        }
                        clear_screen();
                        std::cout << *pacient_gasit;
                        std::cout<<std::endl;
                        std::cout << "Apasa Enter pentru a continua...";
                        std::cin.get();
                        break;
                    }
                    case 6:{//detalii consulatie si retete
                        std::string nume;
                        std::cout << "Numele pacientului pentru care doriti sa vedeti consultatiile: ";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        getline(std::cin, nume);
                        Pacient* pacient_gasit = spital.CautaPacient(nume);
                        if (!pacient_gasit) {
                            clear_screen();
                            std::cout << "Pacientul " << nume << " nu exista!" << std::endl;
                            std::cout << "Apasa Enter pentru a continua...";
                            std::cin.get();
                            break;
                        }
                        std::cout << "\033[2J\033[1;1H";
                        std::cout << "Consultatiile pacientului " << nume << ":" << std::endl<< std::endl;

                        std::vector<Consultatie> lista_consultatii = spital.GetConsultatii();
                        for (auto& consultatie : lista_consultatii) {
                            if (consultatie.GetPacient() == pacient_gasit) {
                                consultatie.AfisareDetalii();
                            }
                        }

                        std::cout<<std::endl<< "Retelele pacientului "<<nume<< " sunt: \n";
                        for(auto& reteta: spital.GetRetete()){
                            if(reteta.GetPacient()==pacient_gasit){
                                reteta.AfisareReteta();
                            }
                        }
                        std::cout << "Apasa Enter pentru a continua...";
                        std::cin.get();
                        break;
                    }
                    case 7:
                        clear_screen();
                        inapoi_la_meniu = true;
                        logged_in = false;
                        break;
                    
                    case 8:
                    clear_screen();
                    std::cout << "Multumesc ca ai folosit aplicatia!<3" << std::endl;
                        return 0;

                    default:
                    clear_screen();
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