#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

struct magazine_struct
{
    string magazine_id = "";
    string magazine_title = "";
};

class magazine
{
public:
    magazine_struct magazine_struct_ds[200];
    int i = 0;
    int magazine_count;

    magazine()
    {
        ifstream file("magazine.csv");
        if (!file.is_open())
        {
            cout << "Error opening file." << endl;
            return;
        }
        int k = 1;
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string field;
            if (k == 1)
            {
                k = 0;
            }
            else
            {
                magazine_struct_ds[i].magazine_id = 'M' + to_string(i);
                getline(ss, field, ',');
                magazine_struct_ds[i++].magazine_title = field;
            }
        }
        file.close();
        magazine_count = i;
    }
};
