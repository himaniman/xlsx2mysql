#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream in;
    ofstream out;
    in.open("data.txt");    //Открытие потока на чтение
    out.open("out.txt");    //Открытие потока на запись

    int counterZapis=0;
    string zapis;

    getline(in,zapis);
    while (getline(in,zapis))
    {


        //getline(in,zapis);

        string *pole;
        pole=new string [60];
        int iterator=0;

        for (int i=0; i<zapis.length(); i++)
        {
            if (zapis[i]=='\t')
            {
                iterator+=1;
                continue;
            }
            pole[iterator]+=zapis[i];
        }
        cout<<"scan of - "<<iterator<<" poles read"<<endl;
        counterZapis+=1;

        string zapros;
        zapros="insert into table values(";
        for (int j=0;j<iterator;j++){
            zapros+=pole[j]+", ";
        }
        zapros+=pole[iterator];
        zapros+=")\n";
        out<<zapros;
    }
    cout << "Our zapis is "<<counterZapis << endl;
    return 0;
}
