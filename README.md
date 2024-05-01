# 2Project

## VISŲ RELEASE APRAŠYMAI

### v.pradine
Programą nuskaito vartotojų įvedamus studento duomenis. Baigus duomenų įvedimą, suskaičiuoja galutinį balą pasirinktu būdu ( su vidurkiu arba mediana ) ir jį pateikia į ekraną.

### v0.1 subrelease
Studentų informaciją apdorojanti programa su meniu skirtingos programos eigos pasirinkimui (1 - ranka suvesti visą studentų informaciją, 2 - generuoti pažymius, bet suvesti vardus ir pavardes, 3 - generuoti ir pažymius, ir studentų vardus, pavardes, 4 - baigti darbą). Programa tur dvi versijas: viena laiko studentų zelutatus masyvuose, kita vector tipo konteineryje.

### v0.2 subrelease
Patobulinta v0.1 versija. Prie meniu pasirinkimo prodėta galimybė nuskaityti informacjia iš failo (galima pasirinki iš 4 skirtingų failų). Pasirinkus nuskaitymą iš failo yra apskaičiuojama nuskaitymo turkmė. Programos eigoje yra galimybė pasirinkti studentų rikiavimą pagal vardą, pavardę, galutini balą, apskaičiuotą su mediana arba vidurkiu. Taip pat vartotojas dabar gali pasirinkti, kur nori spausdinti duomenis: ekrane ar į failą. Išvestis sulygiuota.

### v0.2.2 subrelease
Pataisyta v0.2. Pridėti nuskaitymo laikų vidurkiai.

### v0.3 subrelease
Patobulinta v0.2 versija. Prie programos pridėtas išimčių valdymas (vartotojui įvedant informaciją tikrinama, ar įvestas reikiamas ir taisyklingas skaičius, simbolis, žodis taip pat norint informaciją nuskaityti nuo failo, patikrinama, ar failas egzistuoja nurodytoje vietoje). Taip pat duomenų tipas "studentas" bei dauguma funkcijų perkeltos į kitus failus.

### v0.4 subrelease
Patobulinta v0.3 versija. Prie meniu pasirinkimo prodėta galimybė generuoti failus (sudarytus iš: 1 000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų. Vardai ir pavardės  sugeneruoti "šabloniniai", kaip Vardas1 Pavarde1). Studentai suskirstomi į galvočius (galutinis balas >= 5.0) ir nepažangius( galutinis balas < 5.0). Naudotojas gali pasirinkti, ar studentus suskirstyti pagal galutinį balą, apskaičiuota su mediana arba vidurkiu). Surūšiuoti studentai išvedami į du naujus failus ( Galvočiai.txt ir Nepažangieji.txt atitinkamai). Atlikta programos veikimo greičio (spartos) analizė: apskaičiuojama generavimo, nuskaitymo, rūšiavimo, spausdinimo ir visos programos trukmės. Tyrimas turi išsamų aprašą README.md.

### v0.4.2 subrelease
Pataisyta v0.4subrelease, apskaičiuoti trukmių vidurkiai.

### v1.0 pradinis 
Patobulintos v0.4. Išmatuota realizacijos veikimo sparta priklausomai nuo naudojamų trijų skirtingų tipų konteinerių (std::vector, std::list, std::deque). Yra sukurtos trys skirtingsos programos su atitinkamais konteineriais.  Atlikta programų veikimo greičio (spartos) analizė: nuskaitymo, rūšiavimo didėjimo tvarka ir rūšiavimo į dvi grupes trukmė. Visi rezultatai apdoroti ir aprašyti readme.md faile, pateikiant testavimo sistemos parametrus (CPU, RAM, HDD).

### v1.0.2pradinis ir v1.0.3pradinis
Pataisytas v1.0pradinio realizas.

### v1.0subrelease
Patobulintos v1.0pradinis. Optimizuotas studentų rūšiavimo (dalijimo) į dvi kategorijas ("nepažangiųjų" ir "galvočių") realizaciją: t.y. visiems trims konteinerių tipams (vector, list ir deque) išmatuota programų veikimo sparta priklausomai nuo studentų dalijimo į dvi kategorijas strategijos:
  1 strategija(kaip ir v1.0pradinis): Bendro studentai konteinerio (vector, list ir deque tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "nepažangiųjų" ir "galvočių".
  2 strategija: Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai". Tokiu būdu, jei studentas yra vargšiukas, jis  įkeliamas į naująjį "vargšiukų" konteinerį ir ištrinamas iš bendro studentai konteinerio.
  3 strategija: Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas) panaudojant 2 strategiją įtraukiant į ją "efektyvius" darbo su konteineriais metodus.
ReadMe faile pateikta diegimo ir naudojimo instrukcijos.

### v1.0.2subrelease ir v1.0.3finalinis
Pataisytas v1.0subrelease realizas.

### v1.1 
Patobulintos v1.0. Programa apskaičiuoja nuskaitymo, rūšiavimo didėjimo tvarka ir rūšiavimo į dvi grupes trukmes ( 100000 ir 1000000 dydžio failus ).  Atliktas structure ir class tyrimas su optimizavimo "flagais" (yra lentelė: greitis, exe failo dydis)

### v1.1.2
Pataisyta v1.1

### v1.2
Praplėsta v1.1 versija, kurioje realizuoti reikiami "Rule of five", įvesties/išvesties operatoriai ir testavimas.

### v1.2.2 ir v1.2.3
Pataisyta v1.2 versija.

### v1.5
Praplėsta v1.2 versija. Vietoje vienos klasės "studentas" sukurtos dvi: bazinė (abstrakti) klasė "zmogus", skirta bendrai aprašyti žmogų, ir iš jos išvestinė (derived) klasė - "studentas".

### v1.5.2 ir v1.5.3
Pataisyta v1.5 versija.

### v2.0
Praplėsta v1.5 versija. Sukurta dokumentacija panaudojant Doxygen. Realizuoti Unit Testai naudodojant........ README.md faile aprašyti visi releasai, pateiktos diegimo ir naudojimo instrukcijos.

## Testavimo aprašymas


## DIEGIMO INSTRUKCIJA


1.Atsisiųskite ir įdiekite „Visual Studio“ ir „CMake“ bei šios programos failus;

2.Atsivėrę terminalą su komanda cd nueikite į šios programos failų folderį. Tuomet į terminalą įveskite;

⋅⋅* mkdir build;

⋅⋅* cd build;

⋅⋅* cmake -G "Visual Studio 17 2022" .. ( metai priklauso nuo jūsų VS versijos)

⋅⋅* start V2.sln

3.Atsivėrus Visual Studio atsidarykite "Solution explorer" langelį ir dešiniuoju klavišu paspauskite V2 projekto ir paspauskite "Set as a Startup Project".

4.Paleiskite programą.

## NAUDOJIMOSI INSTRUKCIJA

Paleidus programą pradiniame meniu suteikiami 6 pasirinkimai 1 - ranka suvesti visus studentų duomenis, 2 - generuoti pažymius ir suvesti vardus bei pavardes, 3 - generuoti ir pažymius, ir studentų vardus, pavardes, 4 - nuskaityti duomenis iš failo (galima pasirinkti iš 4 skirtingų failų, programa apskaičiuoja ir pateikia, kiek laiko užtruko nuskaityti failą), 5 - sugeneruoti failus (5 dydžių pasirinkimai), 6 - baigti darbą.

Vėliau leidžiama pasirinkti strategiją (1, 2, 3)

Pasirinkus 1 būdą suteikiama galimybė įvesti studento vardą ir pavardę, vėliau pažymius. Po kiekvieno pažymio yra galimmybė pasirinkti, ar norima įvesti dar viena pažymį (įvesti T jei taip, N jei ne). Baigus įvesti pažymius galima įvesti egzamino balą. Tuomet duodama galimybė pasirinkti, ar norima įvesti dar vieną studentą (įvesti T jei taip, N jei ne). Baigus studentų įvedimą duodamas pasirinkimas pasirinkti studentų grupavimą pagal galutinį balą, apskaičiuotą su pažymių mediana arba vidurkiu, vėliau leidžiama pasirinkti rikiavimą pagal vardą, pavardę, galutini balą, apskaičiuotą su mediana arba vidurkiu. Rezultatus galima rasti "Galvociai.txt" ir "Nepazangus.txt" failuose.

Pasirinkus 2 būdą suteikiama galimybė įvesti studento vardą ir pavardę, vėliau prašoma įvesti norimą kiekį namų darbų pažymių.Tuomet duodama galimybė pasirinkti, ar norima įvesti dar vieną studentą (įvesti T jei taip, N jei ne). Baigus studentų įvedimą duodamas pasirinkimas pasirinkti studentų grupavimą pagal galutinį balą, apskaičiuotą su pažymių mediana arba vidurkiu, vėliau leidžiama pasirinkti rikiavimą pagal vardą, pavardę, galutini balą, apskaičiuotą su mediana arba vidurkiu. Rezultatus galima rasti "Galvociai.txt" ir "Nepazangus.txt" failuose.

Pasirinkus 3 būdą prašoma įvesti, kiek norima sugeneruoti studentų ir vėliau kiek norima sugeneruoti jų pažymių. Baigus generavimą duodamas pasirinkimas pasirinkti studentų grupavimą pagal galutinį balą, apskaičiuotą su pažymių mediana arba vidurkiu, vėliau leidžiama pasirinkti rikiavimą pagal vardą, pavardę, galutini balą, apskaičiuotą su mediana arba vidurkiu. Rezultatus galima rasti "Galvociai.txt" ir "Nepazangus.txt" failuose.

Pasirinkus 4 būdą prašoma pasirinkti nuo kurio failo norite nuskaityti duomenis. Tuomet duodamas pasirinkimas pasirinkti studentų grupavimą pagal galutinį balą, apskaičiuotą su pažymių mediana arba vidurkiu, vėliau leidžiama pasirinkti rikiavimą pagal vardą, pavardę, galutini balą, apskaičiuotą su mediana arba vidurkiu. Rezultatus galima rasti "Galvociai.txt" ir "Nepazangus.txt" failuose.

Pasirinkus 5 būda prašoma pasirinkti kūrį failą norite sugeneruoti, jei failas jau egzistuoja nuo jo nuskaitomi duomenis. Tuomet duodamas pasirinkimas pasirinkti studentų grupavimą pagal galutinį balą, apskaičiuotą su pažymių mediana arba vidurkiu, vėliau leidžiama pasirinkti rikiavimą pagal vardą, pavardę, galutini balą, apskaičiuotą su mediana arba vidurkiu. Rezultatus galima rasti "Galvociai.txt" ir "Nepazangus.txt" failuose.

Pasirinkus 6 būda darbas baigiamas.

Pasirinkus 7 būdą atliekamas class Studentas testavimas.
