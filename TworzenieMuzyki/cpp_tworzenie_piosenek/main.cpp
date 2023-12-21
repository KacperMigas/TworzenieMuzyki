#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Main{
    public:
        int choose;
        int numberOfVerses;
        string file;
        string fileName;
        string fileTypeTxt = ".txt";
        string errorNameOfFile = "bledna nazwa pliku";
        string verses[100000];
        string results[100000];
        string refrain;
        string refrainresult;

    void getChoose()
        {

            cout<<endl<<"wybierz co chcesz zrobic"<<endl;
            cout<<"wpisz 0 jesli chcesz zakonczyc dzialanie programu"<<endl;
            cout<<"wpisz 1 jesli chcesz stworzyc nowa piosenke"<<endl;
            cout<<"wpisz 2 jesli chcesz odczytac plik"<<endl;
                cin>>choose;

        }

    void setChoose()
    {
        do
        {
            getChoose();
            if(choose==1)
            {
                    cout<<"wybrales tworzenie nowej piosenki"<<endl;
                    cout<<"wpisz nazwe pliku"<<endl;
                    cin.ignore();
                    getline(cin,fileName);

                    file = fileName+fileTypeTxt;

                    cout<<"wpisz refren (jesli skonczysz pisac refren wpisz znak srednika(';'))"<<endl;
                    cin.ignore();
                    getline(cin, refrain, ';');

                    refrainresult += refrain;

                    cout<<"ile zwrotek bedize miec twoja piosenka"<<endl;
                    cin>>numberOfVerses;

                    for(int i = 0; i < numberOfVerses; i++)
                        {
                            cout<<"podaj " << i+1 << " zwrotke" << endl;
                            cin.ignore();
                                while(getline(cin, verses[i]))
                                {
                                    results[i] += verses[i];
                                    if(verses[i].find(';'))
                                        {
                                            break;
                                        }
                                }
                        }

                    ofstream MyFile(file);

                    for (int i = 0; i < numberOfVerses; i++)
                        {
                            MyFile << results[i] << endl << refrainresult << endl;
                        }
                        MyFile.close();

               }
               else if(choose==2)
                {
                    try
                    {
                        cout<<"podaj nazwe pliku"<<endl;
                        cin.ignore();
                        getline(cin, fileName);

                        ifstream MyReadFile(fileName+".txt");

                         if(MyReadFile.is_open())
                            {

                                string MyText;

                                    while(getline(MyReadFile,MyText))
                                        {
                                            cout << MyText <<endl;
                                        }
                                MyReadFile.close();
                            }
                            else
                            {
                                throw "zla nazwa pliku";
                            }
                    }
                    catch(string errorNameOfFile)
                    {
                        throw errorNameOfFile;
                    }
                }
        }
        while(choose != 0);
    }
};

using namespace std;
int main()
{
    try{
        Main objectChoose;
        objectChoose.setChoose();
    }
    catch(const char *errorNameOfFile)
    {
        cout<<"blad : "<<errorNameOfFile<<endl;
    }
}
