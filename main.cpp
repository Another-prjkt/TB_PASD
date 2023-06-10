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

        void push(PasswordData password)
        {
            if (top >= MAX_SIZE - 1) 
            {
                cout << "Data ditambahkan" << endl;
                return;
            }
            data[++top] = password;
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

int main() 
{
    cout << "test";
}