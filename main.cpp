#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

string produkt;
int menu;

void wyswietlListeProduktow(string nazwaPliku)
{
    string linia;
    int nr = 1;
    fstream plik;
    plik.open(nazwaPliku, ios::in);
    if (plik.good() == false)
    {
        cout << "Lista zakupow nie istnieje!" << endl;
        exit(0);
    }

    cout << "Lista zakupow:" << endl;
    while (getline(plik, linia))
    {
        cout << nr << ". " << linia << endl;
        nr++;
    }
    plik.close();
}

int main()
{
    cout << "Stworz swoja liste zakupow!" << endl;
    cout << " " << endl;

    for(;;)
    {
        cout << " " << endl;
        cout << "Menu:" << endl;
        cout << " " << endl;
        cout << "1.Dodaj nowy produkt do listy" << endl;
        cout << "2.Usun produkt z listy" << endl;
        cout << "3.Zobacz liste zakupow" << endl;
        cout << "4.Oznacz produkt jako kupiony" << endl;
        cout << "5.Oznacz produkt jako niekupiony" << endl;
        cout << "6.Usun cala liste" << endl;
        cout << "7.Zamknij program" << endl;
        cout << " " << endl;
        cout << "Wybierz: ";
        cin >> menu;
        cout << " " << endl;

        switch (menu)
        {

        case 1:
        {
            cout << "Wpisz produkt: ";
            cin >> produkt;
            fstream plik;
            plik.open("lista_zakupow.txt", ios::out | ios::app);
            plik << produkt << endl;
            plik.close();
            cout << " " << endl;
            cout << "Dodano do listy:" << endl;
            cout << " " << endl;
            {
                string linia;
                int nr = 1;
                fstream plik;
                plik.open("lista_zakupow.txt",ios::in);
                if(plik.good()==false)
                {
                    cout<<"Lista zakupow nie istnieje!";
                    exit(0);
                }
                while (getline(plik, linia))
                {
                    cout << nr << ". " << linia << endl;
                    nr++;
                }
                plik.close();
            }
            getchar();
        }

        break;

        case 2:
        {
            string nazwaPliku = "lista_zakupow.txt";

            wyswietlListeProduktow(nazwaPliku);

            int usunprodukt;
            cout << "Podaj numer produktu do usuniêcia: ";
            cin >> usunprodukt;

            fstream plik;
            plik.open(nazwaPliku, ios::in);

            ofstream tymczplik("tymczplik.txt");
            string linia;
            int nr = 1;

            if (plik.is_open() && tymczplik.is_open())
            {
                while (getline(plik, linia))
                {
                    if (nr != usunprodukt)
                    {
                        tymczplik << linia << endl;
                    }
                    nr++;
                }
                plik.close();
                tymczplik.close();

                remove(nazwaPliku.c_str());
                rename("tymczplik.txt", nazwaPliku.c_str());
            }
            else
            {
                cout << "Nie mo¿na otworzyæ pliku!" << endl;
            }
            getchar();
        }

        break;

        case 3:
        {
            string nazwaPliku = "lista_zakupow.txt";
            wyswietlListeProduktow(nazwaPliku);
            getchar();
        }

        break;

        case 4:
        {
            string nazwaPliku = "lista_zakupow.txt";

            wyswietlListeProduktow(nazwaPliku);

            int kupionyprodukt;
            cout << "Podaj numer produktu do oznaczenia jako kupiony: ";
            cin >> kupionyprodukt;

            fstream plik;
            plik.open(nazwaPliku, ios::in);

            ofstream tymczplik("tymczplik.txt");
            string linia;
            int nr = 1;

            if (plik.is_open() && tymczplik.is_open())
            {
                while (getline(plik, linia))
                {
                    if (nr == kupionyprodukt)
                    {
                        tymczplik << linia << "(kupiony)"<< endl;
                    }
                    else
                    {
                        tymczplik << linia << " " << endl;
                    }
                    nr++;
                }

                plik.close();
                tymczplik.close();

                remove(nazwaPliku.c_str());
                rename("tymczplik.txt", nazwaPliku.c_str());
            }
            else
            {
                cout << "Nie mo¿na otworzyæ pliku!" << endl;
            }
            getchar();
        }
        break;

        case 5:
        {
            string nazwaPliku = "lista_zakupow.txt";

            wyswietlListeProduktow(nazwaPliku);

            int kupionyprodukt;
            cout << "Usun znacznik kupiony z produktu: ";
            cin >> kupionyprodukt;

            fstream plik;
            plik.open(nazwaPliku, ios::in);

            ofstream tymczplik("tymczplik.txt");
            string linia;
            int nr = 1;

            if (plik.is_open() && tymczplik.is_open())
            {
                while (getline(plik, linia))
                {
                    if (nr == kupionyprodukt)
                    {
                        size_t pozycja = linia.find("(kupiony)");
                        if (pozycja != string::npos)
                        {
                            linia.replace(pozycja,9,1,' ');
                        }
                    }
                    else
                    {
                        tymczplik << linia << " " << endl;
                    }
                    nr++;
                }
                plik.close();
                tymczplik.close();
            }
            else
            {
                cout << "Nie mo¿na otworzyæ pliku!" << endl;
            }
            getchar();
        }
        break;

        case 6:
        {
            string nazwaPliku = "lista_zakupow.txt";
            string taknie;

            cout << "Czy na pewno chcesz usunac liste zakupow? Napisz TAK lub NIE" << endl;

            cin >> taknie;

            while (taknie != "TAK" && taknie != "Tak" && taknie != "tak" && taknie != "NIE" && taknie != "Nie" && taknie != "nie")
            {
                cout << "Nie ma takiej opcji w menu! Napisz TAK lub NIE: ";
                cin >> taknie;
            }
            if (taknie == "TAK" || taknie == "Tak" || taknie == "tak")
            {
                remove(nazwaPliku.c_str());
                cout << " " << endl;
                cout << "Plik zostal usuniety." << endl;
                cout << " " << endl;
                cout << "Dodaj nowy produkt, zeby utworzyc liste zakupow." << endl;
                cout << " " << endl;
            }
            if (taknie == "NIE" || taknie == "Nie" || taknie == "nie")
            {
                cout << " " << endl;
                cout << "Plik nie zostal usuniety." << endl;
                cout << " " << endl;
            }
        }
        getchar();
        break;

        case 7:
        {
            exit(0);
        }
        break;

        default:
            cout<<"Nie ma takiej opcji w menu!";
            break;

        }
        getchar();
        system("cls");
    }
    return 0;
}
