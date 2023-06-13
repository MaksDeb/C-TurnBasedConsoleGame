#include <iostream>
#include "Stworzenie.h"
#include <vector>



std::ostream & operator<<(std::ostream& ostream,Stworzenie stworzenie){
    return ostream<<stworzenie.getNazwaStworzenia() << " " << stworzenie.getRodzajString((int)(stworzenie.getRodzaj())) << std::endl;
}

void printvector(std::vector<Stworzenie> v){
    for (int i = 0; i < v.size(); i++) {
        std::cout<< i+1 << " " << v.at(i);
    }
}
void printvectorzprzesunieciem(std::vector<Stworzenie> v){
    for (int i = 1; i < v.size(); i++) {
        std::cout<< i+1 << " " << v.at(i);
    }
}

/***
 * Funkcja wykorzystywana przy wybieraniu stworzen do druzyny
 * Przyjmuje ona vector przechowujacy indkesy stworzen, sortuje go a nastepnie sprawdza czy wartosci sie powtarzaja po czym zwraca true lub false
 * @param myVector
 * @return
 */
bool checkforduplicates(std::vector<int> myVector){
    sort(myVector.begin(), myVector.end());
    auto it = std::unique(myVector.begin(), myVector.end());
    if(it != myVector.end()){
        return true;
    }else{
        return false;
    }
}
/***
 * Funkcja wykorzstywana przy mechanizmie walki, sprawdza czy strumien przyjmuje dobry input.
 * Jezeli nie, czysci strumien i wypisuje komunikat o bledzie.
 * Zwraca int, ktory bedzie wykorzystywany pozniej przy funkcji switch na ktorej opiera sie caly mechanizm walk.
 * @return
 */
int getChoice(){
    int choice = 0;

    std::cout << "Wybierz co chcesz zrobic!" << std::endl;
    std::cout << " 1 - Atak zwykly \n 2 - Moc Specjalna \n 3 - Wymiana stworzenia \n 4 - Ewolucja \n 5 - Wyjscie z gry \n 6 - --help" << std::endl;
    std::cin >> choice;

    while (!std::cin.good()){
        std::cout << "Blad!" << std::endl;

        std::cin.clear();
        std::cin.ignore(INT_MAX,'\n');

        std::cout << "Wybierz co chcesz zrobic!" << std::endl;
        std::cout << " 1 - Atak zwykly \n 2 - Moc Specjalna \n 3 - Wymiana stworzenia \n 4 - Ewolucja \n 5 - Wyjscie z gry \n 6 - --help" << std::endl;
        std::cin >> choice;
    }
    return choice;
}

int main() {

    srand( time( NULL ) );
    std::vector<Stworzenie> mojeStworzenia;
    std::vector<Stworzenie> wszystkieStworzenia;
    std::vector<Stworzenie> przeciwneStworzenia;

    /***
     * STWORZENIE OBIEKTOW WSZYSTKICH STOWRZEN KTORE DODAJEMY DO CALEJ BAZY(WEKTORA)
     */
    Stworzenie *stworzenie = new Stworzenie(OGIEN,"Pikachu",380,85,18,"Piorun",2,180,20);
    wszystkieStworzenia.push_back(*stworzenie);
    Stworzenie *stworzenie1 = new Stworzenie(ZIEMIA,"Bulbasaur",700,60,30,"Uderzenie",1,300,15);
    wszystkieStworzenia.push_back(*stworzenie1);
    Stworzenie *stworzenie2 = new Stworzenie(OGIEN,"Charmander",330,110,10,"Ogien",1,200,30);
    wszystkieStworzenia.push_back(*stworzenie2);
    Stworzenie *stworzenie3 = new Stworzenie(WODA,"Squirtle",360,75,20,"Tsunami",1,210,15);
    wszystkieStworzenia.push_back(*stworzenie3);
    Stworzenie *stworzenie4 = new Stworzenie(POWIETRZE,"Pidgey",600,70,60,"Atak skrzydlami",1,300,25);
    wszystkieStworzenia.push_back(*stworzenie4);
    Stworzenie *stworzenie5 = new Stworzenie(ZIEMIA,"Ratata",400,90,20,"Ugryzienie",3,100,20);
    wszystkieStworzenia.push_back(*stworzenie5);
    Stworzenie *stworzenie6 = new Stworzenie(WODA,"Psyduck",1,1,1,"Uderzenie",1,1,1);
    wszystkieStworzenia.push_back(*stworzenie6);
    Stworzenie *stworzenie7 = new Stworzenie(ZIEMIA,"Machop",1,1,1,"Potrojny cios",1,1,1);
    wszystkieStworzenia.push_back(*stworzenie7);
    Stworzenie *stworzenie8 = new Stworzenie(STAL,"Magnemite",1,1,1,"Porazenie pradem",1,1,1);
    wszystkieStworzenia.push_back(*stworzenie8);
    Stworzenie *stworzenie9 = new Stworzenie(STAL,"Steelix",1,1,1,"Uderzenie ogonem",1,1,1);
    wszystkieStworzenia.push_back(*stworzenie9);
    Stworzenie *stworzenie10 = new Stworzenie(LOD,"Lapras",1,1,1,"Zamrozenie",1,1,1);
    wszystkieStworzenia.push_back(*stworzenie10);
    Stworzenie *stworzenie11 = new Stworzenie(LOD,"Articuno",1,1,1,"Uderzenie soplem lodu",1,1,1);
    wszystkieStworzenia.push_back(*stworzenie11);
    Stworzenie *stworzenie12 = new Stworzenie(POWIETRZE,"Zubat",1,1,1,"Oslepienie",1,1,1);
    wszystkieStworzenia.push_back(*stworzenie12);
    Stworzenie *stworzenie13 = new Stworzenie(WODA,"Poliwag",1,1,1,"Zatopienie",1,1,1);
    wszystkieStworzenia.push_back(*stworzenie13);
    Stworzenie *stworzenie14 = new Stworzenie(POWIETRZE,"Murkrow",1,1,1,"Dziobniecie",1,1,1);
    wszystkieStworzenia.push_back(*stworzenie14);


    printvector(wszystkieStworzenia);

    /***
     * GRACZ WYBIERA DO DRUZYNY STWORZENIA WPISUJAC INDEKSY Z WYZEJ WYSWIETLONEJ LISTY,
     * PROGRAM SPRAWDZA CZY INDEKS TEN NIE ZOSTAL WYBRANY JUZ WCZESNIEJ ORAZ CZY ZNAJDUJE SIE ON W ZAKRESIE
     */
    int x;
    std::vector<int> wybraneindeksy;

    for(int i = 0; i < 6 ; i++){
        std:: cout << "Wybierz stworzenie do druzyny!" << std:: endl;
        std :: cin >> x;
        wybraneindeksy.push_back(x-1);
        bool check = checkforduplicates(wybraneindeksy);
        if((x > wszystkieStworzenia.size()) || check == true || x <= 0){
            wybraneindeksy.pop_back();
            i--;
            std:: cout << "Blad! Wybrano to samo stworzenie lub stworzenie spoza listy!" << std::endl;
        } else {
            mojeStworzenia.push_back(wszystkieStworzenia.at(wybraneindeksy.at(i)));
        }
    }
    std::cout << "Wybrana druzyna: " << std::endl;
    printvector(mojeStworzenia);
    std::cout << " " << std::endl;




    double lvl = 0;

    /***
     * Mechanizm walki dzieli sa na 4 rundy po 4 przeciwnikow. Losujemy 4 przeciwnikow dla tylko jednej rundy, dodajemy ich do wektora przechowujacego przeciwnikow i ustawiamy dla nich statystyki zalezne od poziomu.
     * Jezeli przeciwnik zginie jest on usuwany z wektora. Cala walka zamknieta jest w petli while ktora sprawdza czy ktorys z wektorow(naszej lub przeciwnej druzyny)
     * nie jest pusty(co jest rownoznaczne smierci wszystkich stworzen). Natomiast zawartosc petli jest to rozbudowany switch ktory sprawdza wartosc przekazana z cin i wykonuje odpowiednie operacje.
     */
    for (int i = 0; i < 4; i++) {
        lvl += 1;
        std::cout << "***************************************************************" << std::endl;
        std::cout << "Przeciwnicy na poziomie : " << lvl << std::endl;
        std::cout << "***************************************************************" << std::endl;

        for (int j = 0; j < 4; j++) {
            int randhp = (std::rand() % 120 + 90);
            int randsila = ((std::rand() % 60 + 40));
            int randzrecz = (std::rand() % 15 + 10);
            int randsilaspec = ((std::rand() % 110 + 70));
            int randomint = (std::rand() %14 + 1);
            przeciwneStworzenia.push_back(wszystkieStworzenia.at(randomint));
            przeciwneStworzenia.at(j).setHp((lvl/2)*(randhp * 1.5));
            przeciwneStworzenia.at(j).setSila((lvl/2)*(randsila * 1.5));
            przeciwneStworzenia.at(j).setZrecznosc((lvl/2)*(randzrecz * 1.5));
            przeciwneStworzenia.at(j).setSilaSpec(((lvl/2)*(randsilaspec * 1.5)));

        }
        printvector(przeciwneStworzenia);

        int indeksobecnegostworzeniagracz = 0;
        int indeksobecnegostworzeniaprzeciwnik = 0;


        while (!mojeStworzenia.empty() && !przeciwneStworzenia.empty()){
            int decyzja;
            std::cout << "Statystyki twojego stworzenia: " << mojeStworzenia.at(indeksobecnegostworzeniagracz) << " HP: " << mojeStworzenia.at(indeksobecnegostworzeniagracz).getHp() << " |Sila: "
                      << mojeStworzenia.at(indeksobecnegostworzeniagracz).getSila() << " |Zrecznosc: " << mojeStworzenia.at(indeksobecnegostworzeniagracz).getZrecznosc()
                      << " |Nazwa mocy:" << mojeStworzenia.at(indeksobecnegostworzeniagracz).getNazwaMocy() << " |Sila mocy:" << mojeStworzenia.at(indeksobecnegostworzeniagracz).getSilaSpec()
                      << " |Liczba uzyc mocy specjalnej:" << mojeStworzenia.at(indeksobecnegostworzeniagracz).getMaxuzycia() << " |Punkty exp: " << mojeStworzenia.at(indeksobecnegostworzeniagracz).getPunktyExp()
                      << std::endl;

            std::cout << "Walczysz z: " << przeciwneStworzenia.at(indeksobecnegostworzeniaprzeciwnik) << " HP: " << przeciwneStworzenia.at(indeksobecnegostworzeniaprzeciwnik).getHp() << " Sila: "
                                        << przeciwneStworzenia.at(indeksobecnegostworzeniaprzeciwnik).getSila() << " Zrecznosc: " << przeciwneStworzenia.at(indeksobecnegostworzeniaprzeciwnik).getZrecznosc()
                                        << std::endl;

            //std::cout << "Wybierz co chcesz zrobic!" << std::endl;
            //std::cout << " 1 - Atak zwykly \n 2 - Moc Specjalna \n 3 - Wymiana stworzenia \n 4 - Ewolucja \n 5 - Wyjscie z gry" << std::endl;
            //std::cin >> decyzja;
            decyzja = getChoice();


            switch (decyzja) {
                /***
                 * W przypadku wykonania zwyklego ataku sprawdzamy czy obecne stworzenie przeciwnika uniknelo naszego ataku(za pomoca funkcji statycznej szansanaunik).
                 * Jezeli nie, przeprowadzamy atak, a nastepnie sprawdzamy czy przeciwnik jest jeszcze zywy. Zaleznie od zwroconej wartosci usuwamy go z wektotra, wyswietlamy komunikat i dodajemy punkty EXP do naszego stworzenia
                 * lub przeciwnik wykonuje swoj atak. Nastepnie powtarzamy ta logike, ale tym razem to komputer atakuje nasze stworzenie.
                 */
                case 1: {
                    if (Stworzenie::szansanaunik(przeciwneStworzenia.at(indeksobecnegostworzeniaprzeciwnik)) == false) {
                        mojeStworzenia.at(indeksobecnegostworzeniagracz).atak(
                                przeciwneStworzenia.at(indeksobecnegostworzeniaprzeciwnik));
                        if (przeciwneStworzenia.at(indeksobecnegostworzeniaprzeciwnik).isAlive() == false) {
                            std::cout << "Przeciwnik zemdlal! Przygotuj sie na kolejna walke!" << std::endl;
                            przeciwneStworzenia.erase(przeciwneStworzenia.begin());
                            mojeStworzenia.at(indeksobecnegostworzeniagracz).setPunktyExp(
                                    mojeStworzenia.at(indeksobecnegostworzeniagracz).getPunktyExp() +
                                    (10 * lvl / 2));
                        } else {
                            if (Stworzenie::szansanaunik(mojeStworzenia.at(indeksobecnegostworzeniagracz)) == false) {
                                przeciwneStworzenia.at(indeksobecnegostworzeniaprzeciwnik).atak(
                                        mojeStworzenia.at(indeksobecnegostworzeniagracz));
                                if (mojeStworzenia.at(indeksobecnegostworzeniagracz).isAlive() == false) {
                                    std::cout << "Stworzenie zemdlalo! Zamiana na najblizsze dostepne stworzenie!"
                                              << std::endl;
                                    mojeStworzenia.erase(mojeStworzenia.begin());
                                    if (mojeStworzenia.size() == 0) {
                                        std::cout << "Przegrales! Dziekujemy za rozgrywke!" << std::endl;
                                        exit(1);
                                    }
                                }
                            } else {
                                std::cout << mojeStworzenia.at(indeksobecnegostworzeniagracz).getNazwaStworzenia()
                                          << " wykonanl unik, nie zadano mu obrazen!" << std::endl;
                            }
                        }
                    } else {
                        std::cout << "Wykonano unik, nie zadano obrazen!" << std::endl;
                        if (Stworzenie::szansanaunik(mojeStworzenia.at(indeksobecnegostworzeniagracz)) == false) {
                            przeciwneStworzenia.at(indeksobecnegostworzeniaprzeciwnik).atak(
                                    mojeStworzenia.at(indeksobecnegostworzeniagracz));
                            if (mojeStworzenia.at(indeksobecnegostworzeniagracz).isAlive() == false) {
                                std::cout << "Stworzenie zemdlalo! Zamiana na najblizsze dostepne stworzenie!"
                                          << std::endl;
                                mojeStworzenia.erase(mojeStworzenia.begin());
                                if (mojeStworzenia.size() == 0) {
                                    std::cout << "Przegrales! Dziekujemy za rozgrywke!" << std::endl;
                                    exit(1);
                                }
                            }
                        } else {
                            std::cout << mojeStworzenia.at(indeksobecnegostworzeniagracz).getNazwaStworzenia()
                                      << " wykonanl unik, nie zadano mu obrazen!" << std::endl;
                        }
                    }
                    break;
                }

                case 2: {
                    /***
                     * To samo rozumowanie co w przypadku case 1
                     */
                    if (Stworzenie::szansanaunik(przeciwneStworzenia.at(indeksobecnegostworzeniaprzeciwnik)) == false) {
                        mojeStworzenia.at(indeksobecnegostworzeniagracz).atakspecjalny(
                                przeciwneStworzenia.at(indeksobecnegostworzeniaprzeciwnik));
                        if (przeciwneStworzenia.at(indeksobecnegostworzeniaprzeciwnik).isAlive() == false) {
                            std::cout << "Przeciwnik zemdlal! Przygotuj sie na kolejna walke!" << std::endl;
                            przeciwneStworzenia.erase(przeciwneStworzenia.begin());
                            mojeStworzenia.at(indeksobecnegostworzeniagracz).setPunktyExp(
                                    mojeStworzenia.at(indeksobecnegostworzeniagracz).getPunktyExp() + (10 * lvl / 2));
                        } else {
                            przeciwneStworzenia.at(indeksobecnegostworzeniaprzeciwnik).atak(
                                    mojeStworzenia.at(indeksobecnegostworzeniagracz));
                            if (mojeStworzenia.at(indeksobecnegostworzeniagracz).isAlive() == false) {
                                std::cout << "Stworzenie zemdlalo! Zamiana na najblizsze dostepne stworzenie!"
                                          << std::endl;
                                mojeStworzenia.erase(mojeStworzenia.begin());
                                if (mojeStworzenia.size() == 0) {
                                    std::cout << "Przegrales! Dziekujemy za rozgrywke!" << std::endl;
                                    exit(1);
                                }
                            }
                        }
                    } else {
                        std::cout << "Wykonano unik, nie zadano obrazen!" << std::endl;
                        przeciwneStworzenia.at(indeksobecnegostworzeniaprzeciwnik).atak(
                                mojeStworzenia.at(indeksobecnegostworzeniagracz));
                        if (mojeStworzenia.at(indeksobecnegostworzeniagracz).isAlive() == false) {
                            std::cout << "Stworzenie zemdlalo! Zamiana na najblizsze dostepne stworzenie!"
                                      << std::endl;
                            mojeStworzenia.erase(mojeStworzenia.begin());
                            if (mojeStworzenia.size() == 0) {
                                std::cout << "Przegrales! Dziekujemy za rozgrywke!" << std::endl;
                                exit(1);
                            }
                        }
                    }
                    break;
                }

                case 3: {
                    /***
                     * Wyswietlamy liste stworzen na ktore mozliwe jest wymiana, zamieniamy stworzenia pozycjami w wektorze, a nastepnie pozwalamy komputerowi wyprowadzic atak.
                     */
                    int wymianastworzenia;
                    std::cout << "Wybierz stworzenie ktore chcesz wymienic!" << std::endl;
                    printvectorzprzesunieciem(mojeStworzenia);

                    std::cin >> wymianastworzenia;
                    mojeStworzenia.insert(mojeStworzenia.begin(), mojeStworzenia.at(wymianastworzenia - 1));
                    mojeStworzenia.erase(mojeStworzenia.begin() + wymianastworzenia);
                    //printvector(mojeStworzenia);
                    indeksobecnegostworzeniagracz = 0;
                    std::cout << "Na plac wychodzi: "
                              << mojeStworzenia.at(indeksobecnegostworzeniagracz).getNazwaStworzenia() << std::endl;
                    przeciwneStworzenia.at(indeksobecnegostworzeniaprzeciwnik).atak(
                            mojeStworzenia.at(indeksobecnegostworzeniagracz));
                    if (mojeStworzenia.at(indeksobecnegostworzeniagracz).isAlive() == false) {
                        std::cout << "Stworzenie zemdlalo! Zamiana na najblizsze dostepne stworzenie!" << std::endl;
                        mojeStworzenia.erase(mojeStworzenia.begin());
                        if (mojeStworzenia.size() == 0) {
                            std::cout << "Przegrales! Dziekujemy za rozgrywke!" << std::endl;
                            exit(1);
                        }
                    }
                    break;
                }

                case 4: {
                    /***
                     * Sprawdzamy czy liczba zdobytych punktow EXP jest rowna wymaganej liczbie. Jezeli tak gracz wybiera 1 z 4 statystyk a nastepnie przy pomocy switcha przy uzyciu setterow oraz getterow statystyki sa ulepszane.
                     * W przypadku braku wymaganej liczby punktow wyswietlamy komunikat.
                     */
                    int indekswybranegoatrybutu;
                    if (mojeStworzenia.at(indeksobecnegostworzeniagracz).getPunktyExp() >=
                        mojeStworzenia.at(indeksobecnegostworzeniagracz).getWymaganePunktyExp()) {
                        std::cout << "Wybierz ktore statystyki chcesz ulepszyc!" << std::endl;
                        for (int j = 0; j < 2; ++j) {
                            std::cout << " 1 HP \n 2 Atak \n 3 Atakspecjalny \n 4 Zrecznosc" << std::endl;
                            std::cin >> indekswybranegoatrybutu;
                            switch (indekswybranegoatrybutu) {
                                case 1:
                                    mojeStworzenia.at(indeksobecnegostworzeniagracz).setHp(
                                            mojeStworzenia.at(indeksobecnegostworzeniagracz).getHp() + 40);
                                    break;
                                case 2:
                                    mojeStworzenia.at(indeksobecnegostworzeniagracz).setSila(
                                            mojeStworzenia.at(indeksobecnegostworzeniagracz).getSila() + 30);
                                    break;
                                case 3:
                                    mojeStworzenia.at(indeksobecnegostworzeniagracz).setSilaSpec(
                                            mojeStworzenia.at(indeksobecnegostworzeniagracz).getSilaSpec() + 30);
                                    break;
                                case 4:
                                    mojeStworzenia.at(indeksobecnegostworzeniagracz).setZrecznosc(
                                            mojeStworzenia.at(indeksobecnegostworzeniagracz).getZrecznosc() + 5);
                                    break;
                                default:
                                    std::cout << "Nie ma takiej opcji!" << std::endl;
                                    j--;
                                    break;
                            }
                        }
                        std::cout << "Wykonano ewolucje!" << std::endl;
                        mojeStworzenia.at(indeksobecnegostworzeniagracz).setPunktyExp(
                                mojeStworzenia.at(indeksobecnegostworzeniagracz).getPunktyExp() -
                                mojeStworzenia.at(indeksobecnegostworzeniagracz).getWymaganePunktyExp());
                    } else {
                        std::cout << "Za malo puntkow!" << std::endl;
                    }
                    break;
                }
                case 5: {
                    std::cout << "Dziekujemy za gre! Nastapilo wyjscie" << std::endl;
                    exit(1);
                }
                case 6: {
                    std::string kontynuacja;
                    std::cout << "-Grasz w gre turowa polegajaca na pokonaniu wszystkich przeciwnikow. \n-Celem gry jest pokonanie wszystkich przecwinikow spotkanych na drodze" << std::endl;
                    std::cout << "-Gra dzieli sie na 4 rundy, a w kazdej z rund gracz ma doczynienia z 4 stworzeniami" << std::endl;
                    std::cout << "-Kazde stworzenie posiada nastepujace statystyki: HP,Sila,Zrecznosc,Moc Specjalna, Liczba uzyc mocy, Punkty EXP" << std::endl;
                    std::cout << "-Podczas rozgrywki gracz posiada 5 mozliwych wariantow z ktorych moze skorzystac" << std::endl;
                    std::cout << "-Atak zwykly: Atakujesz przeciwne stworzenie i odbierasz mu punkty HP" << std::endl;
                    std::cout << "-Moc specjalna: Atakujesz przeciwne stworzenie przy uzyciu swojej mocy specjalnej lub leczysz sie. \n"
                                 "Uwazaj! Moc specjalna ma ograniczona liczbe uzyc, po wykorzystaniu wszystkich uzyc proba wykonania ataku specjalnego \nbedzie rownala sie ze strata swojego posuniecia!" << std::endl;
                    std::cout << "-Wymiana stworzenia: Gracz ma mozliwosc wprowadzenia innego stworzenia ze swojej druzyny na plac boju. \nUwaga! Wymiana stworzenia ozanacza stracenie posuniecia w danej turze!" << std::endl;
                    std::cout << "-Ewolucja: Kazde stworzenie po pokonaniu przeciwnika zdobywa odpowiednia ilosc punktow EXP. \n"
                                 "Po zebraniu wystarczajacej liczby puntkow mozliwa jest ewolucja stworzenia. \nPolega ona na zwiekszeniu dwoch wybranych statystyk. \n"
                                 "*Wazne!* Pamietaj, ze kazde stworzenia ma inna wymagana liczbe punktow do ewolucji \noraz z kazda runda dostajesz coraz wiecej puntkow EXP" << std::endl;
                    std::cout << "-Wyjscie z gry: Wyjscie podczas rozgrywki" << std::endl;
                    std::cout << "Uwaga! W grze zostal zaimplementowany system interakcji miedzy stworzeniami!" << std::endl;
                    std::cout << "Po kazdym wykonanym ataku gracza oraz przeciwnika mozliwe jest wyswietlenie sie informacji na temat mocy ataku" << std::endl;
                    std::cout << "Atak moze miec zwiekszona lub zmniejszona moc w zaleznosci od oddzialywania na siebie dwoch rodzajow walczacych stworzen" << std::endl;
                    std::cout << "Wybierz cokolwiek a nastepnie wcisnij enter aby kontynuowac. Powodzenia!" << std::endl;
                    std::cin >> kontynuacja;
                    break;
                }

                default:
                    std::cout << "Niepoprawna opcja!" << std::endl;
                    break;

            }

        }

        przeciwneStworzenia.clear();
    }

    std::cout << "Gratuluje! Wygrales rozgrywke!" << std::endl;


    return 0;
}

