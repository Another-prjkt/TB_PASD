#include <iostream>
#include <string>

using namespace std;

const string VERSION = "1.0.0";

// untuk menyimpan data
struct PasswordData
{
    string akun;
    string password;
};

// implementasi stack 
class Stack 
{
    private:
        static const int MAX_SIZE = 100;
        PasswordData data[MAX_SIZE];
        int top;
    
    public:
        Stack() 
        {
            top = -1;
        }

        void push(PasswordData passwordData)
        {
            if (top >= MAX_SIZE - 1) 
            {
                cout << "Data ditambahkan" << endl;
                return;
            }
            data[++top] = passwordData;
        }

        void pop()
        {
            if (isEmpty())
            {
                cout << "Stack kosong!" << endl;
                return;
            }
            top--;
        }

        PasswordData topElement()
        {
            if (isEmpty())
            {
                PasswordData emptyData;
                emptyData.akun = "";
                emptyData.password = "";
                return emptyData;
            }
            return data[top];
        }

        bool isEmpty()
        {
            return top == -1;
        }
};

class Queue 
{
    private:
        static const int MAX_SIZE = 100;
        PasswordData data[MAX_SIZE];
        int depan;
        int belakang;

    public:
        Queue()
        {
            depan = -1;
            belakang = -1;
        }

        void enqueue(PasswordData passwordData)
        {
            if (belakang == MAX_SIZE - 1)
            {
                cout << "Queue Terisi" << endl;
                return;
            }

            data[++belakang] = passwordData;
            if (depan == - 1) 
            {
                depan = 0;
            }
        }

        void dequeue()
        {
            if (isEmpty())
            {
                cout << "Queue kosong!" << endl;
                return;
            }
            depan++;
            if (depan > belakang)
            {
                depan = -1;
                belakang = -1;
            }
        }

        PasswordData elemenDepan()
        {
            if (isEmpty())
            {
                PasswordData emptyData;
                emptyData.akun = "";
                emptyData.password = "";
                return emptyData;
            }
            return data[depan];
        }
        bool isEmpty()
        {
            return depan == -1;
        }
};

void login()
{
    string username, passwd;
    int loginOption;
    cout << "Login sebagai: " << endl;
    cout << "1. Admin" << endl;
    cout << "2. User" << endl;
    cout << "Pilihan: "; cin >> loginOption;
    if (loginOption == 1)
    {
        cout << "Admin login" << endl;
        cout << "Username : "; cin >> username;
        cout << "Password : "; cin >> passwd;
        if (username == "admin" && passwd == "admin")
        {
            cout << "Login berhasil sebagai Admin" << endl;
        }
    } else 
    {
        cout << "Login berhasill sebagai user" << endl;
    }
    
}

int main() 
{
    login();

}