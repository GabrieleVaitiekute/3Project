#ifndef L2_FUNKCIJOS_H
#define L2_FUNKCIJOS_H

//// NETINKAMA IVESTIS
void Netinkamas_Ivestis(std::string Problema);

//// RUSIAVIMAS
bool VarduRusiavimas(const studentas& a, const studentas& b);
bool PavardziuRusiavimas(const studentas& a, const studentas& b);
bool MedianuRusiavimas(const studentas& a, const studentas& b);
bool VidurkiuRusiavimas(const studentas& a, const studentas& b);
void Rusiuoti_Duomenis(std::list<studentas>& S, std::list<studentas>& N);

//// GENERAVIMAS
void GeneruotiNDPazymius(studentas& S, int ND_kiekis);
void GeneruotiVardus(studentas& S);
void GeneruotiFailus(int reserveDydis, std::string& failoPav);

//// IVEDIMAS
void Ivesti_Pazymius(studentas& S);
void Ivesti_Varda(studentas& S);

//// NUSKAITYAMAS NUO FAILO
std::list<studentas> Nuskaityti_Is_Failo(const std::string& Failo_Pavadinimas, int reserveDydis);

//// REZULTATU APSAKICIAVIMAS
void Apskaiciuoti_Rezultatus(std::list<studentas>& S, std::list<studentas>& N);

//// SPAUSDINIMAS
void Spausdinti_Rezultatus(const std::list<studentas>& S, const std::list<studentas>& N);

#endif 
