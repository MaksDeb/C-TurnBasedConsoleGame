//
// Created by maksd on 14.06.2022.
//

#include "Stworzenie.h"
#include <iostream>
/***
 * Funkcja wyprowadzajaca atak. W parametrze podajemy referencje do obiektu stworzenia. W ten sposob unikamy kopiowania obiektu i jestesmy w stanie zmienic jego wartosci.
 * Przy pomocy setterow oraz getterow jestesmy w stanie ustalic sile obiektu ktory wywolal funkcje, ktora nastepnie jest mnozona przez wartosc zwrocona z funkcji tabelasil.
 * Ostatecznie ustawiamy HP obiektu podanego w parametrze na jego obecne HP - sila*int z  tabelisil
 * @param stworzenie
 */
void Stworzenie::atak(Stworzenie& stworzenie) {
    stworzenie.setHp(stworzenie.getHp() - (getSila() * this->tabelasil(stworzenie)));
    std::cout << this->getNazwaStworzenia() << " zaatakowal "  << stworzenie.getNazwaStworzenia() << std::endl;
}
//void Stworzenie::wymiana() {
    //std::cout << "Wymieniam stworzenie!" << std::endl;
//}
/***
 * Funkcja wyprowadzajaca atak specjalny. W parametrze podajemy referencje do obiektu stworzenia. W ten sposob unikamy kopiowania obiektu i jestesmy w stanie zmienic jego wartosci.
 * Aby rozgrywka byla ciekawsza zalozylem, ze stworzenia o rodzaju WODA,OGIEN,LOD posiadaja ataki specjalne ktora zadaja obrazenia. Natomiast POWIETRZE,STAL i ZIEMIA korzystaja z atakow ktore dodaja HP.
 * Funkcja sprawdza czy obiekt wywolujacy ja posiada liczbe uzyc ataku > 0 po czym korzystamy z logiki uzywanej przy zwyklym ataku. Rozni sie tym, ze przy stworzeniach posiadajacych ataki leczace
 * nie odwolujemy sie do obiektu podanego w parametrze, poniewaz nie jest on dla nas istotny, a dodajemy HP do obiektu ktory wywolal dana funkcje. Co wazne po wykonaniu ataku i wyswietleniu komunikatu
 * zmniejszamy liczbe uzyc o 1 oraz sledzimy pozostala liczbe uzyc ataku specjalnego.
 * @param stworzenie
 */
void Stworzenie::atakspecjalny(Stworzenie& stworzenie){
    if(this->rodzaj == WODA || this->rodzaj == OGIEN || this->rodzaj == LOD) {
        if (this->maxuzycia > 0) {
            stworzenie.setHp(stworzenie.getHp() - (getSilaSpec() * this->tabelasil(stworzenie)));
            std::cout << this->getNazwaStworzenia() << " wykonal " << this->getNazwaMocy() << " na: "
                      << stworzenie.getNazwaStworzenia() << std::endl;
            this->setMaxuzycia(this->getMaxuzycia() - 1);
            std::cout << "Liczba pozostalych mocy specjalnych wynosi " << this->maxuzycia << std::endl;
        }else{
            std::cout << "***********WYKORZYSTANO ATAKI SPECJALNE!***********"<< std::endl;
        }
    }if (this->rodzaj == POWIETRZE || this->rodzaj == STAL || this->rodzaj == ZIEMIA) {
        if (this->maxuzycia > 0) {
            this->setHp(this->getHp() + (this->getSilaSpec() * this->tabelasil(stworzenie)));
            std::cout << this->getNazwaStworzenia() << " uzyl mocy specjalnej i zdobywa wiecej HP!" << std::endl;
            this->setMaxuzycia(this->getMaxuzycia() - 1);
        }else{
            std::cout << "***********WYKORZYSTANO ATAKI SPECJALNE!***********"<< std::endl;
        }
    }
}
//void Stworzenie::ewolucja() {
    //std::cout << "Ewooluje!" << std::endl;
//}


const std::string &Stworzenie::getNazwaStworzenia() const {
    return nazwaStworzenia;
}

void Stworzenie::setNazwaStworzenia(const std::string &nazwaStworzenia) {
    Stworzenie::nazwaStworzenia = nazwaStworzenia;
}

int Stworzenie::getHp() {
    return HP;
}

void Stworzenie::setHp(int hp) {
    HP = hp;
}

int Stworzenie::getSila(){
    return sila;
}

void Stworzenie::setSila(int sila) {
    Stworzenie::sila = sila;
}

int Stworzenie::getZrecznosc() const {
    return zrecznosc;
}

void Stworzenie::setZrecznosc(int zrecznosc) {
    Stworzenie::zrecznosc = zrecznosc;
}

const std::string &Stworzenie::getNazwaMocy() const {
    return nazwaMocy;
}

void Stworzenie::setNazwaMocy(const std::string &nazwaMocy) {
    Stworzenie::nazwaMocy = nazwaMocy;
}

int Stworzenie::getMaxuzycia() const {
    return maxuzycia;
}

void Stworzenie::setMaxuzycia(int maxuzycia) {
    Stworzenie::maxuzycia = maxuzycia;
}

int Stworzenie::getSilaSpec() const {
    return silaSpec;
}

void Stworzenie::setSilaSpec(int silaSpec) {
    Stworzenie::silaSpec = silaSpec;
}

int Stworzenie::getPunktyExp() const {
    return punktyExp;
}

void Stworzenie::setPunktyExp(int punktyExp) {
    Stworzenie::punktyExp = punktyExp;
}

Stworzenie::Stworzenie(Rodzaj rodzaj, const std::string &nazwaStworzenia, int hp, int sila, int zrecznosc,
                       const std::string &nazwaMocy, int maxuzycia, int silaSpec, int wymaganePunktyExp) :
                       rodzaj(rodzaj),nazwaStworzenia(nazwaStworzenia),HP(hp), sila(sila),zrecznosc(zrecznosc),nazwaMocy(nazwaMocy),
                       maxuzycia(maxuzycia),silaSpec(silaSpec),wymaganePunktyExp(wymaganePunktyExp){
            punktyExp = 0;
            wszystkieStworzenia.push_back(*this);
}

Rodzaj Stworzenie::getRodzaj() const {
    return rodzaj;
}

void Stworzenie::setRodzaj(Rodzaj rodzaj) {
    Stworzenie::rodzaj = rodzaj;
}

void Stworzenie::printvector(std::vector<Stworzenie> myvector) {
    for (int i = 0; i < myvector.size(); ++i) {
        std::cout<<myvector.at(i).getNazwaStworzenia() << " " << myvector.at(i).getRodzaj();
    }
}

std::string Stworzenie::getRodzajString(int a) {
    switch (a) {
        case 0:
            return "WODA";
        case 1:
            return "ZIEMIA";
        case 2:
            return "POWIETRZE";
        case 3:
            return "OGIEN";
        case 4:
            return "LOD";
        case 5:
            return "STAL";
    }
}
/***
 * Funkcja sprawdzajaca czy stworzenie zyje. Uzywane przy wykonywaniu atakow.
 * Zwraca bool w zaleznosci od HP ktore posiada stworzenie.
 * @return
 */
bool Stworzenie::isAlive() {
    if(this -> getHp() > 0){
        return true;
    }else{
        return false;
    }
}

int Stworzenie::getWymaganePunktyExp() const {
    return wymaganePunktyExp;
}

void Stworzenie::setWymaganePunktyExp(int wymaganePunktyExp) {
    Stworzenie::wymaganePunktyExp = wymaganePunktyExp;
}
/***
 * Funkcja implementujaca unikanie atakow.
 * W parametrze podajemy referencje do obiektu stworzenia. W ten sposob unikamy kopiowania obiektu i jestesmy w stanie zmienic jego wartosci.
 * Za pomoca funkcji std::rand() losujemy liczbe z zakresu 1-100. Jezeli liczba ta jest w zakresie 1 - [zrecznosc stworzenia podanego w parametrze] to zwracamy wartosc true i atak zostal unikniety.
 * W innym przypadku zwracamy wartosc false, a atak zostaje wykonany.
 * @param stworzenie
 * @return
 */
bool Stworzenie::szansanaunik(Stworzenie &stworzenie) {
    int randomunik = (std::rand() % 100 + 1);
    if(randomunik > 1 && randomunik < stworzenie.getZrecznosc()){
        return true;
    } else{
        return false;
    }

}
/***
 * Funkcja implementujaca interakcje miedzy rodzajamy stowrzen.
 * Za pomoca rozbudowanego switcha dla kazdego rodzaju stworzenia sprawdzamy jak reaguje na dany rodzaj stworzenia.
 * Jezeli jest on slabszy - zwracamy double o wartosci 0.8
 * Jezeli jest on normalny - zwracamy double o wartosci 1.0
 * Jezeli jest on mocny - zwracamy double o wartosci 1.25
 * Zwrocone wartosci sa dla nas kluczowe, poniewaz wykorzystujemy jej pozniej w funkcjach atak oraz atakspecjalny.
 * Mnozymy sile stworzenia wykonujac atak przez wartosc zwrocona z tej funkcji.
 * @param stworzenie
 * @return
 */
double Stworzenie::tabelasil(Stworzenie &stworzenie) {
    switch (stworzenie.getRodzaj()) {
        case WODA:
            switch (this->getRodzaj()) {
                case WODA:
                    std::cout << "Zmniejszono moc ataku!" << std::endl;
                    return 0.8;
                case ZIEMIA:
                    return 1;
                case POWIETRZE:
                    return 1;
                case OGIEN:
                    std::cout << "Zmniejszono moc ataku!" << std::endl;
                    return 0.8;
                case LOD:
                    std::cout << "Zmniejszono moc ataku!" << std::endl;
                    return 0.8;
                case STAL:
                    return 1.25;
            }
        case ZIEMIA:
            switch (this->getRodzaj()) {
                case WODA:
                    std::cout << "Wykonano mocniejszy atak!" << std::endl;
                    return 1.25;
                case ZIEMIA:
                    return 1;
                case POWIETRZE:
                    std::cout << "Zmniejszono moc ataku!" << std::endl;
                    return 0.8;
                case OGIEN:
                    std::cout << "Zmniejszono moc ataku!" << std::endl;
                    return 0.8;
                case LOD:
                    std::cout << "Wykonano mocniejszy atak!" << std::endl;
                    return 1.25;
                case STAL:
                    return 1;
            }
        case POWIETRZE:
            switch (this->getRodzaj()) {
                case WODA:
                    return 1;
                case ZIEMIA:
                    std::cout << "Zmniejszono moc ataku!" << std::endl;
                    return 0.8;
                case POWIETRZE:
                    return 1;
                case OGIEN:
                    return 1;
                case LOD:
                    return 1;
                case STAL:
                    std::cout << "Zwiekszono moc ataku!" << std::endl;
                    return 1.25;
            }
        case OGIEN:
            switch (this->getRodzaj()) {
                case WODA:
                    std::cout << "Zwiekszono moc ataku!" << std::endl;
                    return 1.25;
                case ZIEMIA:
                    std::cout << "Zwiekszono moc ataku!" << std::endl;
                    return 1.25;
                case POWIETRZE:
                    return 1;
                case OGIEN:
                    return 1;
                case LOD:
                    std::cout << "Zmniejszono moc ataku!" << std::endl;
                    return 0.8;
                case STAL:
                    std::cout << "Zmniejszono moc ataku!" << std::endl;
                    return 0.8;
            }
        case LOD:
            switch (this->getRodzaj()) {
                case WODA:
                    return 1;
                case ZIEMIA:
                    std::cout << "Zwiekszono moc ataku!" << std::endl;
                    return 1.25;
                case POWIETRZE:
                    std::cout << "Zwiekszono moc ataku!" << std::endl;
                    return 1.25;
                case OGIEN:
                    std::cout << "Zwiekszono moc ataku!" << std::endl;
                    return 1.25;
                case LOD:
                    std::cout << "Zmniejszono moc ataku!" << std::endl;
                    return 0.8;
                case STAL:
                    return 1;
            }
        case STAL:
            switch (this->getRodzaj()) {
                case WODA:
                    return 1;
                case ZIEMIA:
                    std::cout << "Zwiekszono moc ataku!" << std::endl;
                    return 1.25;
                case POWIETRZE:
                    std::cout << "Zmniejszono moc ataku!" << std::endl;
                    return 0.8;
                case OGIEN:
                    std::cout << "Zwiekszono moc ataku!" << std::endl;
                    return 1.25;
                case LOD:
                    return 1;
                case STAL:
                    std::cout << "Zmniejszono moc ataku!" << std::endl;
                    return 0.8;
            }
    }
}






