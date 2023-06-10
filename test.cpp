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

int main() {
    string username, password;
    Stack passwordGenerator;
    Queue passwordManager;

    int loginOption;
    cout << "Login sebagai: " << endl;
    cout << "1. Admin" << endl;
    cout << "2. User" << endl;
    cout << "Pilihan: ";
    cin >> loginOption;

    if (loginOption == 1) {
        cout << "Login" << endl;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        if (username == "admin" && password == "admin") {
            cout << "Login berhasil sebagai admin." << endl;

            while (true) {
                int option;
                cout << "Pilih opsi: " << endl;
                cout << "1. Password Manager" << endl;
                cout << "2. Password Generator" << endl;
                cout << "3. Keluar" << endl;
                cout << "Pilihan: ";
                cin >> option;

                if (option == 1) {
                    int managerOption;
                    cout << "Opsi Password Manager:" << endl;
                    cout << "1. Push" << endl;
                    cout << "2. Pop" << endl;
                    cout << "3. Tampilkan Data" << endl;
                    cout << "4. Kembali" << endl;
                    cout << "Pilihan: ";
                    cin >> managerOption;

                    if (managerOption == 1) {
                        PasswordData password;
                        cout << "Website: ";
                        cin >> password.akun;
                        cout << "Password: ";
                        cin >> password.password;
                        passwordManager.enqueue(password);
                    } else if (managerOption == 2) {
                        passwordManager.dequeue();
                    } else if (managerOption == 3) {
                        cout << "Data Password Manager:" << endl;
                        if (passwordManager.isEmpty()) {
                            cout << "Password manager kosong." << endl;
                        } else {
                            Queue tempQueue = passwordManager;
                            int count = 1;
                            while (!tempQueue.isEmpty()) {
                                PasswordData passwordData = tempQueue.elemenDepan();
                                cout << "Data " << count << ":" << endl;
                                cout << "Website: " << passwordData.akun << endl;
                                cout << "Password: " << passwordData.password << endl;
                                cout << endl;
                                tempQueue.dequeue();
                                count++;
                            }
                        }
                    } else if (managerOption == 4) {
                        continue;
                    } else {
                        cout << "Opsi yang Anda pilih tidak valid." << endl;
                    }
                } else if (option == 2) {
                    int generatorOption;
                    cout << "Opsi Password Generator:" << endl;
                    cout << "1. Push" << endl;
                    cout << "2. Pop" << endl;
                    cout << "3. Kembali" << endl;
                    cout << "Pilihan: ";
                    cin >> generatorOption;

                    if (generatorOption == 1) {
                        PasswordData password;
                        cout << "Username: ";
                        cin >> password.akun;
                        cout << "Password: ";
                        cin >> password.password;
                        passwordGenerator.push(password);
                    } else if (generatorOption == 2) {
                        passwordGenerator.pop();
                    } else if (generatorOption == 3) {
                        continue;
                    } else {
                        cout << "Opsi yang Anda pilih tidak valid." << endl;
                    }
                } else if (option == 3) {
                    break;
                } else {
                    cout << "Opsi yang Anda pilih tidak valid." << endl;
                }
            }
        } else {
            cout << "Username atau password yang Anda masukkan salah." << endl;
        }
    } else if (loginOption == 2) {
        cout << "Login" << endl;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        if (username == "user" && password == "user") {
            cout << "Login berhasil sebagai user." << endl;
            while (true) {
                int option;
                cout << "Pilih opsi: " << endl;
                cout << "1. Password Manager" << endl;
                cout << "2. Password Generator" << endl;
                cout << "3. Keluar" << endl;
                cout << "Pilihan: ";
                cin >> option;

                if (option == 1) {
                    int managerOption;
                    cout << "Opsi Password Manager:" << endl;
                    cout << "1. Push" << endl;
                    cout << "2. Pop" << endl;
                    cout << "3. Tampilkan Data" << endl;
                    cout << "4. Kembali" << endl;
                    cout << "Pilihan: ";
                    cin >> managerOption;

                    if (managerOption == 1) {
                        PasswordData password;
                        cout << "Website: ";
                        cin >> password.akun;
                        cout << "Password: ";
                        cin >> password.password;
                        passwordManager.enqueue(password);
                    } else if (managerOption == 2) {
                        passwordManager.dequeue();
                    } else if (managerOption == 3) {
                        cout << "Data Password Manager:" << endl;
                        if (passwordManager.isEmpty()) {
                            cout << "Password manager kosong." << endl;
                        } else {
                            Queue tempQueue = passwordManager;
                            int count = 1;
                            while (!tempQueue.isEmpty()) {
                                PasswordData password = tempQueue.elemenDepan();
                                cout << "Data " << count << ":" << endl;
                                cout << "Website: " << password.akun << endl;
                                cout << "Password: " << password.password << endl;
                                cout << endl;
                                tempQueue.dequeue();
                                count++;
                            }
                        }
                    } else if (managerOption == 4) {
                        continue;
                    } else {
                        cout << "Opsi yang Anda pilih tidak valid." << endl;
                    }
                } else if (option == 2) {
                    int generatorOption;
                    cout << "Opsi Password Generator:" << endl;
                    cout << "1. Push" << endl;
                    cout << "2. Pop" << endl;
                    cout << "3. Kembali" << endl;
                    cout << "Pilihan: ";
                    cin >> generatorOption;

                    if (generatorOption == 1) {
                        PasswordData password;
                        cout << "Username: ";
                        cin >> password.akun;
                        cout << "Password: ";
                        cin >> password.password;
                        passwordGenerator.push(password);
                    } else if (generatorOption == 2) {
                        passwordGenerator.pop();
                    } else if (generatorOption == 3) {
                        continue;
                    } else {
                        cout << "Opsi yang Anda pilih tidak valid." << endl;
                    }
                } else if (option == 3) {
                    break;
                } else {
                    cout << "Opsi yang Anda pilih tidak valid." << endl;
                }
            }
        } else {
            cout << "Username atau password yang Anda masukkan salah." << endl;
        }
    } else {
        cout << "Opsi yang Anda pilih tidak valid." << endl;
    }

    return 0;
}
