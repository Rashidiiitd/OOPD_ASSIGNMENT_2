#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct book_Struct
{
    string book_id = "";
    int book_count = 0;
    string book_isbn = ""; // Changed the type to string
    string book_title = "";
    string author_name = ""; // Corrected the member name
};

class IITDBooks
{
public:
    int i = 0;
    book_Struct Book_dataset1[102];

    IITDBooks()
    {
        ifstream file("IITD_LIBRARY_DATASET.csv");
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
                // Remove the extra double quotes from the book ID
                Book_dataset1[i].book_id = "D" + field.substr(1, field.length() - 2);

                getline(ss, field, ',');
                Book_dataset1[i].book_count = stoi(field);
                getline(ss, field, ',');
                Book_dataset1[i].book_isbn = field;
                getline(ss, field, ',');
                getline(ss, field, ',');
                Book_dataset1[i].author_name = field;
                getline(ss, field, ',');
                getline(ss, field, ',');
                Book_dataset1[i].book_title = field;

                i++;
            }
        }
        file.close();
    }
  
    int GetTotalBooks()
    {
        return i;
    }
};

// int main()
// {
//     IITDBooks bookList;
//     int totalBooks = bookList.GetTotalBooks();

//     // Access the book data using bookList.Book_dataset array
//     for (int j = 0; j < totalBooks; j++)
//     {
//         cout << "Book ID: " << bookList.Book_dataset1[j].book_id << endl;
//         cout << "Book Count: " << bookList.Book_dataset1[j].book_count << endl;
//         cout << "Book ISBN: " << bookList.Book_dataset1[j].book_isbn << endl;
//         cout << "Book Title: " << bookList.Book_dataset1[j].book_title << endl;
//         cout << "Author Name: " << bookList.Book_dataset1[j].author_name << endl;
//         cout << endl;
//     }

//     return 0;
// }
