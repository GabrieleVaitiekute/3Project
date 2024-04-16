#ifndef CLASS_FUNKCIJOS_H
#define CLASS_FUNKCIJOS_H
#include "class_studentai.h"


////////// NETINKAMA IVESTIS //////////////
void Netinkamas_Ivestis(std::string Problema);

///////// GENERAVIMAS /////////////////////
void GeneruotiNDPazymius(studentas& S, int ND_kiekis);
void GeneruotiVardus(studentas& S);
void GeneruotiFailus(int reserveDydis, std::string& failoPav);

////////// IVEDIMAS ///////////////////////
void Ivesti_Pazymius(studentas& S);
void Ivesti_Varda(studentas& S);

////////// NUSKAITYMAS NUO FAILO /////////////////
std::vector<studentas> Nuskaityti_Is_Failo(const std::string& Failo_Pavadinimas, int reserveDydis);

//////// DUOMENU RUSIAVIMAS ///////////
bool VarduRikiavimas(const studentas& a, const studentas& b);
bool PavardziuRikiavimas(const studentas& a, const studentas& b);
bool MedianuRikiavimas(const studentas& a, const studentas& b);
bool VidurkiuRikiavimas(const studentas& a, const studentas& b);
void Rikiuoti_Duomenis(std::vector<studentas>& S);

////////// SKIRSTYMAS STUDENTU I GRUPES
void Skirstyti_Studentus(std::vector<studentas>& S, std::vector<studentas>& N, std::vector<studentas>& G, int Strategija);

///////// REZULTATU SPAUSDINIMAS ///////////////////////////
void Spausdinti_Rezultatus(const std::vector<studentas>& N, const std::vector<studentas>& G);

#endif
