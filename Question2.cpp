#include <iostream>
#include "book.h"
#include "journals.h"
#include "magazine.h"
#include "IITD_LIBRARY.h"
#include <bits/stdc++.h>
using namespace std;

struct student_info {
    string rollno;
    string name = "";
    string book_ids[100];
    string book_titles[100];
    string issue_dates[100];
    string return_dates[100];
    int num_books = 0;
    string magazine_titles[100];
    string Journal_titles[100];
    int journal_count1 = 0;
    int magazine_count1 = 0;
    string  type = " ";
};

class student : public book, public magazine, public journals,public IITDBooks
{
public:
    student_info Student_data[100];

    int numberof_Student = 0;
   // int numberof_Faculty = 0;
    student() {
        //cout << "Constructor called" << endl;
    }
    
     void Hash_Map(string book_name,string name ) {
        const int numBooks = 100;
        const int booksPerShelf = numBooks / 10; // 10 books per shelf

        // Extract the numeric part of the book name (e.g., "B25" -> 25)
        int bookNumber = stoi(book_name.substr(1));

        if (bookNumber >= 1 && bookNumber <= numBooks) {
            int shelfNumber = (bookNumber - 1) / booksPerShelf + 1; // Calculate the shelf number
            cout << "The book "<<name << book_name << " is on shelf " << shelfNumber << endl;
            cout << "And Row number is " << shelfNumber % 10 << endl;
        } else {
            cout << "Invalid book name. Please enter a book name between B1 and B100." << endl;
        }
    };
   // To serch  book in the Libarary 
    void Hashing(string LinearProbing) {
    bool flag = false;
    for (int i = 0; i < ttl1; i++) {
       // cout << "Debug: Checking book " << b1[i].book_id << endl; // Debug statement
        if (b1[i].book_isbn == LinearProbing || b1[i].book_id == LinearProbing || b1[i].book_title == LinearProbing) {
            Hash_Map(b1[i].book_id, b1[i].book_title);
            flag = true;
            
        }
    }
    if (!flag) {
        cout << "You entered the wrong book details." << endl;
    }
}

    int Student_Registration(string name, string rollno,string type) {
        bool flagStudent = false;
        int i = 0;
        for (; i < numberof_Student; i++) {
            if (Student_data[i].rollno == rollno || Student_data[i].name == name) {
                cout << "You already registered" << endl;
                flagStudent = true;
                
                return i;
            }
        }
        Student_data[numberof_Student].name = name;
        Student_data[numberof_Student].rollno = rollno;
        Student_data[numberof_Student].type = type;
        numberof_Student++;
        cout << "Congrat You Registered " << endl;
        return i;
    }

    int Hashing1(string LinearProbing) {
        bool flag = false;
        for (int i = 0; i < ttl1; i++) {
            if (b1[i].book_id == LinearProbing) {
                return i;
            }
        }
        if (!flag) {
            cout << "You entered the wrong book details." << endl;
        }
        return -1;  // Return -1 if the book is not found
    }
      void SearchBy_Authour_Name()
     {            string taker;
                 bool flag = true;
                cout << "Enter the Author Name" << endl;
               cin.ignore(); // Ignore newline character
                getline(cin,taker);

       for(int i = 1; i < ttl1; i++)
             {    // cout<<"I am in for loop"<<endl;
                  if(b1[i].author_name.find(taker) != string::npos)
                  {   flag = true;
                     //x =1;
                    // cout<<"hello";
                     cout<<"Title: " << b1[i].book_title<<" and location is  =  ";
                     Hashing(b1[i].book_title);

                  }
             }
             if(!flag){
                cout<<"u enter the Wrong author name "<<endl;
             }
      
    }
      void Search_Magzine(string ident){
        for(int i =0 ;i<magazine_count;i++){
            if(magazine_struct_ds[i].magazine_id == ident || magazine_struct_ds[i].magazine_title == ident)
            {
                cout<<"Magzine Title of Your Magzine is "<<magazine_struct_ds[i].magazine_title<<endl;
                cout<<"And Location of Your Magzine is  shelf:"<<rand()%10<<" ,row: "<<rand()%10<<endl;
                return ;
            } 
        }
        cout<<"OOPS! Your Search Item is not Found"<<endl;
    }
    void Serach_Journal(string ident){
        for(int i =0 ;i<journal_count;i++){
            if(journalStruct_ds[i].journals_id == ident )
            {
                cout<<"Journal Title of Your journal  is "<<journalStruct_ds[i].journals_title<<endl;
            
                 cout<<"Journal is not Physical item"<<endl;
                return ;
            } 
        }
        cout<<"OOPS! Your Search Item is not Found"<<endl;
    }
    string getNextMonthDate(string occupation) {
        time_t currentTime = std::time(nullptr);
        tm currentTm = *localtime(&currentTime);
        if (occupation == "St" || occupation == "st") {
            currentTm.tm_mon++;
        } else {
            currentTm.tm_mon = currentTm.tm_mon + 6;
        }
        if (currentTm.tm_mon == 12) {
            currentTm.tm_mon = 0;
            currentTm.tm_year++;
        }
        time_t nextMonthTime = mktime(&currentTm);
        tm nextMonthTm = *localtime(&nextMonthTime);
        stringstream ss;
        ss << put_time(&nextMonthTm, "%d-%m-%Y");
        return ss.str();
    };

    string current_date() {
        time_t currentTime = time(nullptr);
        tm currentTm = *localtime(&currentTime);
        stringstream ss;
        ss << setw(2) << setfill('0') << currentTm.tm_mday << '-';
        ss << setw(2) << setfill('0') << currentTm.tm_mon + 1 << '-';
        ss << (currentTm.tm_year + 1900);
        string currentDateStr = ss.str();
        return currentDateStr;
    };
   int Hashing_IITD(string id){
     
     for(int i = 0;i<102;i++){
        if(Book_dataset1[i].book_id == id){
            return i;
        }
     }
     return -1;
   }
   
  void book_allocation_toStudent(string name, string rollno,string type) {
        cout << "Enter the number of books to borrow: ";
        int numBooksToBorrow;
        cin >> numBooksToBorrow;

        for (int i = 0; i < numBooksToBorrow; i++) {
            cout << "Enter BOOK ID (format as B--): ";
            string bookid;
            cin >> bookid;

            int bookidinBook = Hashing1(bookid);
            if (bookidinBook >= 0 && bookidinBook < ttl1) {
                for (int j = 0; j < numberof_Student; j++) {
                    if (Student_data[j].rollno == rollno) {
                        Student_data[j].book_ids[Student_data[j].num_books] = bookid;
                        Student_data[j].book_titles[Student_data[j].num_books] = b1[bookidinBook].book_title;
                        Student_data[j].issue_dates[Student_data[j].num_books] = current_date();
                        Student_data[j].return_dates[Student_data[j].num_books] = getNextMonthDate(type);
                        Student_data[j].num_books++;

                        cout << "Book " << bookid << " allocated successfully to " << name << endl;
                    }
                }
            } else {
                cout << "Book with ID " << bookid << " not found." << endl;
            }
        }
    }
    int extractIntegerPart(const std::string &bookId) {
    // Find the position of the first non-digit character (i.e., the start of the integer part)
    size_t pos = bookId.find_first_not_of("0123456789");

    // Extract the substring containing only the integer part
    std::string integerPart = bookId.substr(1, pos - 1);

    // Convert the extracted substring to an integer
    int result = std::atoi(integerPart.c_str());

    return result;
}
 void book_allocation_toStudent_fromIITD(string name, string rollno) {
    cout << "Enter the number of books to borrow: ";
    int numBooksToBorrow;
    cin >> numBooksToBorrow;

    for (int i = 0; i < numBooksToBorrow; i++) {
        cout << "Enter BOOK ID (format as D--): "; // Changed to D-- to represent IITD Library books
        string bookid;
        cin >> bookid;

          int bookidinBook = Hashing_IITD(bookid);
          if(bookidinBook==-1){
            cout<<"Book IS NOT ALSO PRESENT IN IITD LIB"<<endl;
            continue;
          }
        // Check if the book ID is valid and issue the book
        for (int j = 0; j < 101; j++) { // Use 101 as the loop limit, assuming there are 101 books in the IITD Library
            int iitdBookIdInt = Hashing_IITD(Book_dataset1[j].book_id);
            if (iitdBookIdInt ==bookidinBook) {
                if (Book_dataset1[j].book_count > 0) {
                    // Issue the book from IITD Library
                    Book_dataset1[j].book_count--;

                    // Find the student and allocate the book
                    for (int k = 0; k < numberof_Student; k++) {
                        if (Student_data[k].rollno == rollno) {
                            Student_data[k].book_ids[Student_data[k].num_books] = bookid;
                            Student_data[k].book_titles[Student_data[k].num_books] = Book_dataset1[j].book_title;
                            Student_data[k].issue_dates[Student_data[k].num_books] = current_date();

                            // Set the due date to 7 days from the current date
                            Student_data[k].return_dates[Student_data[k].num_books] = getNextWeekDate();
                            Student_data[k].num_books++;

                            cout << "Book " << bookid << " allocated successfully to " << name << endl;
                            return; // Exit the loop once the book is issued
                        }
                    }
                } else {
                    cout << "Book " << bookid << " is not available in the IITD Library." << endl;
                }
            }
        }
        cout << "Book with ID " << bookid << " not found in the IITD Library." << endl;
    }
}



// Define a method to get the date 7 days from the current date
string getNextWeekDate() {
    time_t currentTime = std::time(nullptr);
    tm currentTm = *localtime(&currentTime);
    currentTm.tm_mday += 7; // Add 7 days
    mktime(&currentTm);
    stringstream ss;
    ss << put_time(&currentTm, "%d-%m-%Y");
    return ss.str();
}

    
   int Hashing2(string id_) {
        bool flag = false;
        for (int i = 0; i < journal_count; i++) {
            if (journalStruct_ds[i].journals_id == id_) {
                return i;
            }
        }
        if (!flag) {
            cout << "You entered the wrong Journal details." << endl;
        }
        return -1;  // Return -1 if journal is not found
    }
 void Journal_Allocation_toStudent(string name, string studentRollNo) {
        cout << "Enter Journal ID (format as J--): ";
        string journalID;
        cin >> journalID;
        
        //int magazineIndex = Hashing3(magazineID);
        int journalIndex = Hashing2(journalID);
        if (journalIndex != -1) {
            for (int i = 0; i < numberof_Student; i++) {
                if (Student_data[i].rollno == studentRollNo) {
                    Student_data[i].Journal_titles[Student_data[i].journal_count1] = journalStruct_ds[journalIndex].journals_title;
                    Student_data[i].journal_count1++;

                    cout << "Journal allocated successfully to student " << Student_data[i].name << endl;
                    return;
                }
            }
            cout << "Student with Roll No " << studentRollNo << " not found." << endl;
        } else {
            cout << "Journal with ID " << journalID << " not found." << endl;
        }
    }
     int Hashing3(string ident) {
        for (int i = 0; i < magazine_count; i++) {
            if (magazine_struct_ds[i].magazine_id == ident) {
                return i;
            }
        }
        cout << "OOPS! Your Search Item is not Found" << endl;
        return -1;  // Return -1 if magazine is not found
    }
    void Magazine_Allocation_toStudent(string name, string studentRollNo) {
     cout << "Enter Magazine ID (format as M--): ";
        string magazineID;
        cin >> magazineID;
        
        int magazineIndex = Hashing3(magazineID);
        if (magazineIndex != -1) {
            for (int i = 0; i < numberof_Student; i++) {
                if (Student_data[i].rollno == studentRollNo) {
                    Student_data[i].magazine_titles[Student_data[i].magazine_count1] = magazine_struct_ds[magazineIndex].magazine_title;
                    Student_data[i].magazine_count1++;

                    cout << "Magazine allocated successfully to student " << Student_data[i].name << endl;
                    return;
                }
            }
            cout << "Student with Roll No " << studentRollNo << " not found." << endl;
        } else {
            cout << "Magazine with ID " << magazineID << " not found." << endl;
        }
    }
    

 void PrintRegisteredStudents() {
    cout << "Registered Students:" << endl;
    for (int i = 0; i < numberof_Student; i++) {
        cout << " Name: " << Student_data[i].name << endl;
        cout << "Roll No: " << Student_data[i].rollno << endl;
        cout << "Number of Books Allocated: " << Student_data[i].num_books << endl;
        cout<<"Student or Facult  --> "<<Student_data[i].type<<endl;
        for (int j = 0; j < Student_data[i].num_books; j++) {
            cout << "Book Title: " << Student_data[i].book_titles[j] << endl;
            cout << "Book ID: " << Student_data[i].book_ids[j] << endl;
            cout << "Issue Date: " << Student_data[i].issue_dates[j] << endl;
            cout << "Due Date: " << Student_data[i].return_dates[j] << endl;
            cout << endl;
        }
        cout << "Number of Journals Allocated: " << Student_data[i].journal_count1 << endl;
        for (int j = 0; j < Student_data[i].journal_count1; j++) {
            cout << "Journal Title: " << Student_data[i].Journal_titles[j] << endl;
            // Print other journal-related information here
        }
        cout << "Number of Magazines Allocated: " << Student_data[i].magazine_count1 << endl;
        for (int j = 0; j < Student_data[i].magazine_count1; j++) {
            cout << "Magazine Title: " << Student_data[i].magazine_titles[j] << endl;
            // Print other magazine-related information here
        }
        cout << endl;
    }
}
 void Search_IITD(string ident){
        for(int i =0 ;i<101;i++){
            if(Book_dataset1[i].book_id == ident)
            {
                cout<<"Your BOOK Title is "<<Book_dataset1[i].book_title<<endl;
                cout<<"And Location of Your BOOK IN IITD Libarary is  = : shelf:"<<rand()%10<<" ,row: "<<rand()%10<<endl;
                return ;
            } 
        }
        cout<<"OOPS! Your Search Item is not Found"<<endl;
    }

};

  

int main() {
    cout << "******************************************" << endl;
    cout << "      Welcome to IIIT Delhi Library       " << endl;
    cout << "******************************************" << endl;
    cout << "Explore, Borrow, and Enjoy the Reading!" << endl;
    cout << endl;
    cout << "At IIIT Delhi Library, we offer a wide range of books, magazines," << endl;
    cout << "newspapers, and electronic resources to enhance your learning experience." << endl;
    cout << "Our collection is carefully curated to cater to the diverse interests" << endl;
    cout << "and academic needs of our students and faculty." << endl;
    cout << endl;
    cout << "Whether you are a student, a faculty member, we are here" << endl;
    cout << "to assist you in finding the resources you need and ensuring a smooth" << endl;
    cout << "Learning experience." << endl;
    cout << endl;

    student Student_Obj;

   
    string name, roll,type;
    while(1){
    cout << "Enter the 0 for Registration " << endl;
    cout<<"Enter 1 for Search for Book"<<endl;
    cout<<"Enter 2 for Search for Journal"<<endl;
    cout<<"Enter 3 for Search for Magazine"<<endl;
    cout<<"Enter 5 for Seacrch Book in IITD Library"<<endl;
    cout<<"Enter 4 for exit "<<endl;
    int code;
    cin >> code;

    if (code == 0) {
        cout << "Enter name of student or Faculty (Case Sensitive): ";
        cin >> name;
        cout<<"Enter Ft for Faculty or St for Student "<<endl;
        cin>>type;
        cout << "Enter College ID of Voracious: ";
        cin >> roll;



        int studentId = Student_Obj.Student_Registration(name, roll,type);
        cout <<  name <<"<--- Registration  " << " is Done --->" << endl;
       while(1){
        cout << "<---Enter 1 for to give book--->" << endl;
        cout << "<---Enter 2 for to give Journal--->" << endl;
        cout << "<---Enter 3 for to give Magazine--->" << endl;
        cout<<"Enter 5 to Borrow Item from IITD Libarary"<<endl;
        cout<<"Enter 4 to exit "<<endl;

        int code_1;
        cin >> code_1;

        if (code_1 == 1) {
            char borrowAnother;
            do {
                Student_Obj.book_allocation_toStudent(name, roll,type);

                cout << "Borrow another book? (Y/N): ";
                cin >> borrowAnother;
            } while (borrowAnother == 'Y' || borrowAnother == 'y');
        }
        else if (code_1 == 2) {
            char borrowAnother;
            do {
                Student_Obj.Journal_Allocation_toStudent(name, roll);
                cout << "Borrow another Journal? (Y/N): ";
                cin >> borrowAnother;
            } while (borrowAnother == 'Y' || borrowAnother == 'y');
        }
        else if(code_1 == 3){
             char borrowAnother;
            do {
                Student_Obj.Magazine_Allocation_toStudent(name, roll);
                cout << "Borrow another Magazine? (Y/N): ";
                cin >> borrowAnother;
            } while (borrowAnother == 'Y' || borrowAnother == 'y');
        }
        else if(code_1 == 4) break;
      
        else if(code_1==5){
          Student_Obj.book_allocation_toStudent_fromIITD(name,roll);
        }
        
    
       }}
    else if(code==1){
 /// searxh for BOOK
     
     
           cout<<"You Want to See the Location of the BOOK"<<endl;
            cout << "Enter 1 for Search by Title or ISBN or BookID " << endl;
            cout << "Enter 2 for Search by Author Name that may be multiple Books" << endl;
            int tester;
            
            cin >> tester;
            if (tester == 1) {
                string taker;
                cout << "Enter the ISBN or Title of BOOK" << endl;
                cin.ignore(); // Ignore newline character
                getline(cin, taker);
                Student_Obj.Hashing(taker);
            } else if (tester == 2) {
               
                Student_Obj.SearchBy_Authour_Name();
            } else {
                cout << "Sorry, you are trying to do something else for which functionality is not provided."
                     << endl;
            }

    }
    else if(code == 2){
        string id;
        cout<<"Enter id of Journal"<<endl;
        cin>>id;
        Student_Obj.Serach_Journal(id);

    }
    else if (code == 3){
     string id ;

     cout<<"Enter the id of Magazine"<<endl;
     cin>>id;
     Student_Obj.Search_Magzine(id);
    }
    else if(code == 4){
        break;
    }
    else if(code == 5){
        string id;
        cout<<"Enter id"<<endl;
        cin>>id;
        Student_Obj.Search_IITD(id);

    }
    }
    // Print the registered students
    Student_Obj.PrintRegisteredStudents();
   // faculty_Obj.PrintRegisteredFaculty();

    return 0;
}
