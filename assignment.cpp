#include <iostream>
using namespace std;

class Book {
public:
    int bookId;
    string title, author;
    bool isIssued;

    Book() {
        isIssued = false;
    }

    void input() {
        cout << "Enter Book ID: ";
        cin >> bookId;
        cout << "Enter Title: ";
        cin >> title;
        cout << "Enter Author: ";
        cin >> author;
    }

    void display() {
        cout << bookId << " " << title << " " << author;
        if(isIssued)
            cout << " (Issued)";
        else
            cout << " (Available)";
        cout << endl;
    }

    void issueBook() {
        isIssued = true;
    }

    void returnBook() {
        isIssued = false;
    }
};

class User {
public:
    int userId;
    string name;
    Book* issuedBook;

    User() {
        issuedBook = NULL;
    }

    void input() {
        cout << "Enter User ID: ";
        cin >> userId;
        cout << "Enter Name: ";
        cin >> name;
    }

    void display() {
        cout << userId << " " << name;
        if(issuedBook != NULL)
            cout << " (Has Book ID: " << issuedBook->bookId << ")";
        cout << endl;
    }

    void borrowBook(Book* b) {
        if(issuedBook == NULL && !b->isIssued) {
            issuedBook = b;
            b->issueBook();
            cout << "Book Issued Successfully\n";
        } else {
            cout << "Cannot Issue Book\n";
        }
    }

    void returnBook() {
        if(issuedBook != NULL) {
            issuedBook->returnBook();
            issuedBook = NULL;
            cout << "Book Returned\n";
        } else {
            cout << "No Book to Return\n";
        }
    }
};

int main() {
    Book* books[10];
    User* users[10];
    int bCount = 0, uCount = 0;
    int choice;

    do {
        cout << "\n1.Add Book\n2.Add User\n3.Issue Book\n4.Return Book\n5.Display Books\n6.Display Users\n7.Exit\n";
        cin >> choice;

        switch(choice) {
            case 1:
                books[bCount] = new Book();
                books[bCount]->input();
                bCount++;
                break;

            case 2:
                users[uCount] = new User();
                users[uCount]->input();
                uCount++;
                break;

            case 3: {
                int uid, bid;
                cout << "Enter User ID and Book ID: ";
                cin >> uid >> bid;

                for(int i=0;i<uCount;i++) {
                    if(users[i]->userId == uid) {
                        for(int j=0;j<bCount;j++) {
                            if(books[j]->bookId == bid) {
                                users[i]->borrowBook(books[j]);
                            }
                        }
                    }
                }
                break;
            }

            case 4: {
                int uid;
                cout << "Enter User ID: ";
                cin >> uid;

                for(int i=0;i<uCount;i++) {
                    if(users[i]->userId == uid) {
                        users[i]->returnBook();
                    }
                }
                break;
            }

            case 5:
                for(int i=0;i<bCount;i++)
                    books[i]->display();
                break;

            case 6:
                for(int i=0;i<uCount;i++)
                    users[i]->display();
                break;

        }

    } while(choice != 7);

    return 0;
}