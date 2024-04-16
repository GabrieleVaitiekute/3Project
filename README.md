# 2Project
Programa (vector) su meniu skirtingos programos eigos pasirinkimui:
1 - ranka suvesti viską,
2 - generuoti tik pažymius,
3 - generuoti ir pažymius ir studentų vardus, pavardes,
4 - nuskaityti duomenis iš failo (galima pasirinkti iš 4 skirtingų failų, programa apskaičiuoja ir pateikia, kiek laiko užtruko nuskaityti failą), 
5 - sugeneruoti failus (5 dydžių pasirinkimai), 
6 - baigti darbą

Studentai suskirstomi į galvočius ir nepažangius pagal medianą arba vidurkį (leidžiama pasirinkti).

Programos eigoje suteikiama galimybė pasirinkti rikiavimą pagal vardą, pavardę, galutini balą, apskaičiuotą su mediana arba vidurkiu.

Kur buvo reikalinga panaudotas išimčių valdymas (vartotojui įvedant informaciją tikrinama, ar įvestas reikiamas ir taisyklingas skaičius, simbolis, žodis).

Programa apskaičiuoja nuskaitymo, rūšiavimo didėjimo tvarka ir rūšiavimo į dvi grupes trukmes. Naudojant trukmes atliekama programų analizė. Atliktas structure ir class tyrimas su optimizavimo "flagais" (yra lentelė: greitis, exe failo dydis) 

![Screenshot 2024-04-16 190448](https://github.com/GabrieleVaitiekute/2Project/assets/147078486/275c8296-07dc-4bc4-949f-ae35edea983d)


![Screenshot 2024-04-16 190452](https://github.com/GabrieleVaitiekute/2Project/assets/147078486/4de65e33-aaa3-4185-9186-df777511df3f)


Iš šių lentelių galima teigti, jog greičiausiai programa veikia naudojant class bei 03 optimizatorių.

DIEGIMO INSTRUKCIJA

1. Atsisiųskite ir įdiekite „Visual Studio“ ir „CMake“ bei šios programos failus;

2. Atsivėrę terminalą su komanda cd nueikite į šios programos failų folderį;

3. Į terminalą įveskite mkdir build;
   
5. Į terminalą įveskite  cd build;

6. Į terminalą įveskite cmake -G "Visual Studio 17 2022" .. ( metai priklauso nuo jūsų VS versijos)

7. Į terminalą įveskite start V1.1.sln

8. Atsivėrus Visual Studio atsidarykite "Solution explorer" langelį ir dešiniuoju klavišu paspauskite ant norimo (Class ar Structure) projekto ir paspauskite "Set as a Startup Project". (Tai reikės padaryti kiekvieną kartą norint pasirinkti kitą projektą);

9. Paleiskite programą.

NAUDOJIMOSI INSTRUKCIJA

Paleidus programą pradiniame meniu suteikiami 6 pasirinkimai 1 - ranka suvesti visus studentų duomenis, 2 - generuoti pažymius ir suvesti vardus bei pavardes, 3 - generuoti ir pažymius, ir studentų vardus, pavardes, 4 - nuskaityti duomenis iš failo (galima pasirinkti iš 4 skirtingų failų, programa apskaičiuoja ir pateikia, kiek laiko užtruko nuskaityti failą), 5 - sugeneruoti failus (5 dydžių pasirinkimai), 6 - baigti darbą.

Vėliau leidžiama pasirinkti strategiją (1, 2, 3)

Pasirinkus 1 būdą suteikiama galimybė įvesti studento vardą ir pavardę, vėliau pažymius. Po kiekvieno pažymio yra galimmybė pasirinkti, ar norima įvesti dar viena pažymį (įvesti T jei taip, N jei ne). Baigus įvesti pažymius galima įvesti egzamino balą. Tuomet duodama galimybė pasirinkti, ar norima įvesti dar vieną studentą (įvesti T jei taip, N jei ne). Baigus studentų įvedimą duodamas pasirinkimas pasirinkti studentų grupavimą pagal galutinį balą, apskaičiuotą su pažymių mediana arba vidurkiu, vėliau leidžiama pasirinkti rikiavimą pagal vardą, pavardę, galutini balą, apskaičiuotą su mediana arba vidurkiu. Rezultatus galima rasti "Galvociai.txt" ir "Nepazangus.txt" failuose.

Pasirinkus 2 būdą suteikiama galimybė įvesti studento vardą ir pavardę, vėliau prašoma įvesti norimą kiekį namų darbų pažymių.Tuomet duodama galimybė pasirinkti, ar norima įvesti dar vieną studentą (įvesti T jei taip, N jei ne). Baigus studentų įvedimą duodamas pasirinkimas pasirinkti studentų grupavimą pagal galutinį balą, apskaičiuotą su pažymių mediana arba vidurkiu, vėliau leidžiama pasirinkti rikiavimą pagal vardą, pavardę, galutini balą, apskaičiuotą su mediana arba vidurkiu. Rezultatus galima rasti "Galvociai.txt" ir "Nepazangus.txt" failuose.

Pasirinkus 3 būdą prašoma įvesti, kiek norima sugeneruoti studentų ir vėliau kiek norima sugeneruoti jų pažymių. Baigus generavimą duodamas pasirinkimas pasirinkti studentų grupavimą pagal galutinį balą, apskaičiuotą su pažymių mediana arba vidurkiu, vėliau leidžiama pasirinkti rikiavimą pagal vardą, pavardę, galutini balą, apskaičiuotą su mediana arba vidurkiu. Rezultatus galima rasti "Galvociai.txt" ir "Nepazangus.txt" failuose.

Pasirinkus 4 būdą prašoma pasirinkti nuo kurio failo norite nuskaityti duomenis. Tuomet duodamas pasirinkimas pasirinkti studentų grupavimą pagal galutinį balą, apskaičiuotą su pažymių mediana arba vidurkiu, vėliau leidžiama pasirinkti rikiavimą pagal vardą, pavardę, galutini balą, apskaičiuotą su mediana arba vidurkiu. Rezultatus galima rasti "Galvociai.txt" ir "Nepazangus.txt" failuose.

Pasirinkus 5 būda prašoma pasirinkti kūrį failą norite sugeneruoti, jei failas jau egzistuoja nuo jo nuskaitomi duomenis. Tuomet duodamas pasirinkimas pasirinkti studentų grupavimą pagal galutinį balą, apskaičiuotą su pažymių mediana arba vidurkiu, vėliau leidžiama pasirinkti rikiavimą pagal vardą, pavardę, galutini balą, apskaičiuotą su mediana arba vidurkiu. Rezultatus galima rasti "Galvociai.txt" ir "Nepazangus.txt" failuose.

Pasirinkus 6 būdą darbas baigiamas.
