#ifndef LIST_FUNKCIJOS_H
#define LIST_FUNKCIJOS_H

////// NETINKAMA IVESTIS
void Netinkamas_Ivestis(std::string Problema);



//// GENERAVIMAS
void GeneruotiNDPazymius(studentas& S, int ND_kiekis);
void GeneruotiVardus(studentas& S);
void GeneruotiFailus(int reserveDydis, std::string& failoPav);

//// IVEDIMAS
void Ivesti_Pazymius(studentas& S);
void Ivesti_Varda(studentas& S);

//// NUSKAITYMAS NUO FAILO
std::list<studentas> Nuskaityti_Is_Failo(const std::string& Failo_Pavadinimas, int reserveDydis);

//// REZULTATU APSKAICIAVIMAS
void Apskaiciuoti_Rezultatus(std::list<studentas>& S);

//// DUOMENU RUSIAVIMAS
bool VarduRikiavmas(const studentas& a, const studentas& b);
bool PavardziuRikiavmas(const studentas& a, const studentas& b);
bool MedianuRikiavmas(const studentas& a, const studentas& b);
bool VidurkiuRikiavmas(const studentas& a, const studentas& b);
void Rikiuoti_Duomenis(std::list<studentas>& S);

//// STUDENTU SKIRSTYMAS
void Skirstyti_Studentus(std::list<studentas>& S, std::list<studentas>& N, std::list<studentas>& G, int Strategjia);

//// REZULTATU SPAUSDINIMAS
void Spausdinti_Rezultatus(const std::list<studentas>& N, const std::list<studentas>& G);


#endif 


