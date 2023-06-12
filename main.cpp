#include <iostream>
#include <string>

using namespace std;

const string VERSION = "1.0.1";

// untuk menyimpan data
struct PasswordData
{
    string akun;
    string password;
};

bool isEmpty();

// implementasi stack
const int MAX_SIZE = 100;
PasswordData stackData[MAX_SIZE];
int top = -1;

void push(PasswordData passwordData)
{
    if (top >= MAX_SIZE - 1)
    {
        cout << "Data ditambahkan" << endl;
        return;
    }
    stackData[++top] = passwordData;
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
    return stackData[top];
}

bool isEmpty()
{
    return top == -1;
}

// implementasi queue
PasswordData queueData[MAX_SIZE];
int frontIndex = -1;
int rearIndex = -1;

void enqueue(PasswordData passwordData)
{
    if (rearIndex == MAX_SIZE - 1)
    {
        cout << "Queue Terisi" << endl;
        return;
    }

    queueData[++rearIndex] = passwordData;
    if (frontIndex == -1)
    {
        frontIndex = 0;
    }
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Queue kosong!" << endl;
        return;
    }
    frontIndex++;
    if (frontIndex > rearIndex)
    {
        frontIndex = -1;
        rearIndex = -1;
    }
}

PasswordData frontElement()
{
    if (isEmpty())
    {
        PasswordData emptyData;
        emptyData.akun = "";
        emptyData.password = "";
        return emptyData;
    }
    return queueData[frontIndex];
}

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