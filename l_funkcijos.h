#ifndef L_FUNKCIJOS_H
#define L_FUNKCIJOS_H

////// NETINKAMA IVESTIS
void Netinkamas_Ivestis(std::string Problema);

//// DUOMENU RUSIAVIMAS
bool VarduRusiavimas(const studentas& a, const studentas& b);
bool PavardziuRusiavimas(const studentas& a, const studentas& b);
bool MedianuRusiavimas(const studentas& a, const studentas& b);
bool VidurkiuRusiavimas(const studentas& a, const studentas& b);
void Rusiuoti_Duomenis(std::list<studentas>& N, std::list<studentas>& G);

//// GENERAVIMAS
void GeneruotiNDPazymius(studentas& S, int ND_kiekis);
void GeneruotiVardus(studentas& S);
void GeneruotiFailus(int reserveDydis, std::string& failoPav);

//// IVEDIMAS
void Ivesti_Pazymius(studentas& S);
void Ivesti_Varda(studentas& S);

//// NUSKAITYMAS NUO FAILO
std::list<studentas> Nuskaityti_Is_Failo(const std::string& Failo_Pavadinimas, int reserveDydis);

//// REZULTATU APSKAICIAVIMAS IRSKIRSTYMAS I GRUPES
void Apskaiciuoti_Rezultatus(std::list<studentas>& S, std::list<studentas>& N, std::list<studentas>& G);

//// REZULTATU SPAUSDINIMAS
void Spausdinti_Rezultatus(const std::list<studentas>& N, const std::list<studentas>& G);
#endif 

