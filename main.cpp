#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

string product;
int menu;

void showproductlist(string filename)
{
    string line;
    int nr = 1;
    fstream file;
    file.open(filename, ios::in);
    if (file.good() == false)
    {
        cout << "Shopping list does not exist!" << endl;
        exit(0);
    }

    cout << "Shopping list:" << endl;
    while (getline(file, line))
    {
        cout << nr << ". " << line << endl;
        nr++;
    }
    file.close();
}

int main()
{
    cout << "Create your shopping list!" << endl;
    cout << " " << endl;

    for(;;)
    {
        system("pause");
        system("cls");
        cout << " " << endl;
        cout << "Menu:" << endl;
        cout << " " << endl;
        cout << "1.Add a new product to the list" << endl;
        cout << "2.Remove product from list" << endl;
        cout << "3. View shopping list" << endl;
        cout << "4.Mark the product as purchased" << endl;
        cout << "5.Mark the product as unpurchased" << endl;
        cout << "6.Delete the entire list" << endl;
        cout << "7.Close the program" << endl;
        cout << " " << endl;
        cout << "Choose: ";
        cin >> menu;
        cout << " " << endl;

        switch (menu)
        {

        case 1:
        {
            cout << "Enter product: ";
            cin >> product;
            fstream file;
            file.open("shopping_list.txt", ios::out | ios::app);
            file << product << endl;
            file.close();
            cout << " " << endl;
            cout << "Added to list:" << endl;
            cout << " " << endl;
            {
                string line;
                int nr = 1;
                fstream file;
                file.open("shopping_list.txt",ios::in);
                if(file.good()==false)
                {
                    cout<<"Shopping list does not exist!";
                    exit(0);
                }
                while (getline(file, line))
                {
                    cout << nr << ". " << line << endl;
                    nr++;
                }
                file.close();
            }
        }
        break;
        case 2:
        {
            string filename = "shopping_list.txt";

            showproductlist(filename);

            int deleteproduct;
            cout << "Enter the product number to remove: ";
            cin >> deleteproduct;

            fstream file;
            file.open(filename, ios::in);

            ofstream tmpfile("tmpfile.txt");
            string line;
            int nr = 1;

            if (file.is_open() && tmpfile.is_open())
            {
                while (getline(file, line))
                {
                    if (nr != deleteproduct)
                    {
                        tmpfile << line << endl;
                    }
                    nr++;
                }
                file.close();
                tmpfile.close();

                remove(filename.c_str());
                rename("tmpfile.txt", filename.c_str());
            }
            else
            {
                cout << "Unable to open the file!" << endl;
            }
        }

        break;

        case 3:
        {
            string filename = "shopping_list.txt";
            showproductlist(filename);
        }

        break;

        case 4:
        {
            string filename = "shopping_list.txt";

            showproductlist(filename);

            int purchasedproduct;
            cout << "Enter the product number to mark as purchased: ";
            cin >> purchasedproduct;

            fstream file;
            file.open(filename, ios::in);

            ofstream tmpfile("tmpfile.txt");
            string line;
            int nr = 1;

            if (file.is_open() && tmpfile.is_open())
            {
                while (getline(file, line))
                {
                    if (nr == purchasedproduct)
                    {
                        tmpfile << line << "(purchased)"<< endl;
                    }
                    else
                    {
                        tmpfile << line << " " << endl;
                    }
                    nr++;
                }

                file.close();
                tmpfile.close();

                remove(filename.c_str());
                rename("tmpfile.txt", filename.c_str());
            }
            else
            {
                cout << "Unable to open the file!" << endl;
            }
        }
        break;

        case 5:
        {
            string filename = "shopping_list.txt";

            showproductlist(filename);

            int purchasedproduct;
            cout << "Remove the buy tag from the product: ";
            cin >> purchasedproduct;

            fstream file;
            file.open(filename, ios::in);

            ofstream tmpfile("tmpfile.txt");
            string line;
            int nr = 1;

            if (file.is_open() && tmpfile.is_open())
            {
                while (getline(file, line))
                {
                    if (nr == purchasedproduct)
                    {
                        size_t pos = line.find("(purchased)");
                        if (pos != string::npos)
                        {
                            line.replace(pos,9,1,' ');
                        }
                    }
                    else
                    {
                        tmpfile << line << " " << endl;
                    }
                    nr++;
                }
                file.close();
                tmpfile.close();
            }
            else
            {
                cout << "Unable to open the file!" << endl;
            }
        }
        break;

        case 6:
        {
            string filename = "shopping_list.txt";
            string yn;

            cout << "Are you sure you want to deleteac shopping list? Write YES or NO" << endl;

            cin >> yn;

            while (yn != "YES" && yn != "Yes" && yn != "yes" && yn != "NO" && yn != "No" && yn != "no")
            {
                cout << "There is no such option in the menu! Write YES or NO: ";
                cin >> yn;
            }
            if (yn == "YES" || yn == "Yes" || yn == "yes")
            {
                remove(filename.c_str());
                cout << " " << endl;
                cout << "The file has been deleted." << endl;
                cout << " " << endl;
                cout << "Add a new product to create a shopping list." << endl;
                cout << " " << endl;
            }
            if (yn == "NO" || yn == "No" || yn == "no")
            {
                cout << " " << endl;
                cout << "The file has not been deleted." << endl;
                cout << " " << endl;
            }
        }
        break;

        case 7:
        {
            exit(0);
        }
        break;

        default:
        {
            cout<<"There is no such option in the menu!";
        }
        break;
        }
    }
    return 0;
}
