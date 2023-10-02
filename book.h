#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct book1
{
    string book_id = "";
    int book_count = 0;
    string book_isbn = ""; // Changed the type to string
    string book_title = "";
    string author_name = ""; // Corrected the member name
};

class book
{
public:
    int bi = 0;
    int ttl1;
    book1 b1[200];

    book()
    {
        ifstream file("books_id.csv");
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
                getline(ss, field, ',');
                b1[bi].book_id = 'B'  + field;
                getline(ss, field, ',');
                getline(ss, field, ',');
                getline(ss, field, ',');
                getline(ss, field, ',');
                b1[bi].book_count = stoi(field);
                getline(ss, field, ',');
                b1[bi].book_isbn = field; // Assign as a string
                getline(ss, field, ',');
				 getline(ss, field, ',');
                b1[bi].author_name = field; // Corrected member name
                getline(ss, field, ',');
                getline(ss, field, ',');
                b1[bi].book_title = field;

                bi++;
            }
        }
        file.close();

        ttl1 = bi;
    }
};
