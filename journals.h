#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

struct journalStruct
{
    string journals_id = "";
    string journals_title = "";
};

class journals
{
public:
    journalStruct journalStruct_ds[200];
    int journal_count = 0;

    journals()
    {
        ifstream file("journals.csv");
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
                journalStruct_ds[journal_count].journals_id = 'J' + to_string(journal_count);
                getline(ss, field, ',');
                journalStruct_ds[journal_count].journals_title = field;
                journal_count++;
            }
        }
        file.close();
    }
};
