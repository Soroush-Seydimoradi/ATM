#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <cstdlib>

#define MAX_ROWS 100
#define MAX_COLS 4
using namespace std;

void main_menu();

void Login_attendant();

void Log_att_checker();

void menu_attendant();

void Open_an_account();

void create_username();

void create_account_number();

void create_password_for_user();

void create_balance();

void Update_an_account();

void Edit_menu();

void Change_username();

void Change_password();

void Increase_balance();

void Show_all_users();

void Search_for_account();

void Login_user();

void Log_user_checker();

void menu_user();

void Account_balance();

void Cash_Transfer();

void Cash_withdrawl();

void Change_password_as_user();

struct Login_admin {
    string admin_username;
    string admin_password;
} L;
struct Open_account {
    string user_username;
    string account_number;
    string password;
    string balance;
} O;
struct Edit_account {
    string user_username;
    string user_password;
} E;
struct New_edit_account {
    string user_username_new;
    string user_password_new;
    string user_balance_new;
} N;
struct Login_user {
    string user_username;
    string user_password;
} LU;
struct Cash_transfer {
    string username;
    string cash;
} C;
struct Withdrawl {
    string cash;
} W;
struct New_password {
    string previous_password;
    string new_password;
} NP;

int main() {
    system("color F0");
    main_menu();
}

void main_menu() {
    system("cls");
    int number;
    cout << "1-Login as attendant" << endl;
    cout << "2-Login as user" << endl;
    cout << "3-Exit" << endl;
    cout << "please enter number:" << endl;
    cin >> number;
    if (number == 1)
        Login_attendant();
    else if (number == 2)
        Login_user();
    else if (number == 3)
        exit(0);
    else {
        system("cls");
        cout << "error!" << endl << "Please enter number(1-2-3)";
        getch();
        main_menu();
    }
}

void Login_attendant() {
    system("cls");
    cout << "please enter your username:" << endl;
    cin >> L.admin_username;
    cout << "please enter your password:" << endl;
    cin >> L.admin_password;
    Log_att_checker();
}

void Log_att_checker() {
    system("cls");
    if (L.admin_username == "admin" && L.admin_password == "2024")
        menu_attendant();
    else {
        int numbere;
        cout << "is incorrect!" << endl;
        bool flage = false;
        while (!flage) {
            cout << "1-try again." << endl << "2-back to main menu." << endl;
            cin >> numbere;
            if (numbere == 1)
                Login_attendant();
            if (numbere == 2)
                main_menu();
            if (numbere != 1 && numbere != 2) {
                cout << "error!" << "(1-2)";
                getch();
            }
        }
    }
}

void menu_attendant() {
    int number;
    system("cls");
    cout << "---------welcome---------" << endl;
    cout << "1-Open an account" << endl;
    cout << "2-Update an account" << endl;
    cout << "3-Show all users" << endl;
    cout << "4-Search for an account" << endl;
    cout << "5-Back to the main menu" << endl;
    cout << "please enter number:" << endl;
    cin >> number;
    if (number == 1)
        Open_an_account();
    else if (number == 2)
        Update_an_account();
    else if (number == 3)
        Show_all_users();
    else if (number == 4)
        Search_for_account();
    else if (number == 5)
        main_menu();
    else {
        system("cls");
        cout << "error!" << endl << "Please enter number(1-2-3-4-5)";
        getch();
        menu_attendant();
    }
}

void Open_an_account() {
    system("cls");
    create_username();
    create_account_number();
    create_password_for_user();
    create_balance();
    system("cls");
    cout << "<<an account succesfully created>>";
    getch();
    main_menu();
}


void create_username() {
    bool flag = false;
    while (!flag) {
        system("cls");
        cout << "please enter username of user:" << endl;
        cin >> O.user_username;
        string target;
        ifstream f2("user profiles");
        string arr[MAX_ROWS][MAX_COLS];
        for (int i = 0; i < MAX_ROWS; i++) {
            for (int j = 0; j < MAX_COLS; j++) {
                f2 >> arr[i][j];
            }
        }
        for (int i = 0; i < MAX_ROWS; i++) {
            if (arr[i][0] == O.user_username) {
                target = arr[i][0];
                break;
            }
        }
        f2.close();
        int counter = 0;
        for (int i = 0; i < O.user_username.length(); i++) {
            if (isalpha(O.user_username[i]))
                counter++;
        }
        if (3 > O.user_username.length() || O.user_username.length() > 32 || O.user_username.length() != counter) {
            int numbere;
            cout << "The username is invalid !" << endl
                 << "the username should be at least 3 character and just enter alphabet" << endl;
            getch();
        } else if (O.user_username == target) {
            cout << "This username already taken .please try another username" << endl;
            getch();
        } else {
            flag = true;
        }
    }
    ofstream f1("user profiles", ios::app);
    f1 << O.user_username << ' ';
    f1.close();
}

void create_account_number() {
    bool flag = false;
    while (!flag) {
        system("cls");
        cout << "please enter account number:" << endl;
        cin >> O.account_number;

        string target;
        ifstream f2("user profiles");
        string arr[MAX_ROWS][MAX_COLS];
        for (int i = 0; i < MAX_ROWS; i++) {
            for (int j = 0; j < MAX_COLS; j++) {
                f2 >> arr[i][j];
            }
        }

        for (int i = 0; i < MAX_ROWS; i++) {
            if (arr[i][1] == O.account_number) {
                target = arr[i][1];
                break;
            }
        }
        f2.close();

        int counter = 0;
        for (int i = 0; i < O.account_number.length(); i++) {
            if (isdigit(O.account_number[i]))
                counter++;
        }
        if (O.account_number.length() != 10 || counter != 10) {
            cout << "The account number is invalid !" << endl
                 << "the account number should be 10 character and all digit" << endl;
            getch();
        } else if (O.account_number == target) {
            cout << "This account number already taken .please try another account number" << endl;
            getch();
        } else
            flag = true;
    }
    ofstream f1("user profiles", ios::app);
    f1 << O.account_number << ' ';
    f1.close();
}

void create_password_for_user() {
    bool flag = false;
    while (!flag) {
        system("cls");
        cout << "please enter password:" << endl;
        cin >> O.password;
        int counter = 0;
        for (int i = 0; i < O.password.length(); i++) {
            if (isdigit(O.password[i]))
                counter++;
        }
        if (O.password.length() != 4 || counter != 4) {
            cout << "The password is invalid !" << endl << "the password should be 4 character and all digit" << endl;
            getch();
        } else
            flag = true;
    }
    ofstream f1("user profiles", ios::app);
    f1 << O.password << ' ';
    f1.close();
}


void create_balance() {
    bool flag = false;
    while (!flag) {
        system("cls");
        cout << "please specify the account balance($):" << endl;
        cin >> O.balance;
        int counter = 0;
        for (int i = 0; i < O.balance.length(); i++) {
            if (isdigit(O.balance[i]))
                counter++;
        }
        if (counter != O.balance.length()) {
            cout << "The balance is invalid !" << "the balance should be all digit" << endl;
            getch();
        } else
            flag = true;
    }
    ofstream f1("user profiles", ios::app);
    f1 << O.balance << ' ';
    f1 << endl;
    f1.close();

}

void Update_an_account() {
    bool flag = false;
    while (!flag) {
        system("cls");
        cout << "please enter the username of account you want to edit:" << endl;
        cin >> E.user_username;
        cout << "please enter the password of account you want to edit:" << endl;
        cin >> E.user_password;

        string target1, target2;
        ifstream f2("user profiles");
        string arr[MAX_ROWS][MAX_COLS];
        for (int i = 0; i < MAX_ROWS; i++) {
            for (int j = 0; j < MAX_COLS; j++) {
                f2 >> arr[i][j];
            }
        }

        for (int i = 0; i < MAX_ROWS; i++) {
            if (arr[i][0] == E.user_username)
                target1 = arr[i][0];
            if (arr[i][2] == E.user_password)
                target2 = arr[i][2];
        }
        f2.close();
        if (E.user_username == target1 && E.user_password == target2)
            flag = true;
        else {
            int numbere;
            cout << "incorrect! ." << endl;
            bool flage = false;
            while (!flage) {
                cout << "1-try again." << endl << "2-back to menu." << endl;
                cin >> numbere;
                if (numbere == 1)
                    Update_an_account();
                if (numbere == 2)
                    menu_attendant();
                if (numbere != 1 && numbere != 2) {
                    cout << "error!" << "(1-2)";
                    getch();
                }
            }
        }
    }
    Edit_menu();
}

void Edit_menu() {
    system("cls");
    int number;
    cout << "1) Change username." << endl;
    cout << "2) Change password." << endl;
    cout << "3) Increase balance." << endl;
    cout << "4) Back to main menu." << endl;
    cout << "please enter number:" << endl;
    cin >> number;
    if (number == 1)
        Change_username();
    else if (number == 2)
        Change_password();
    else if (number == 3)
        Increase_balance();
    else if (number == 4)
        main_menu();
    else {
        cout << "error!" << endl << "Please enter number(1-2-3-4)";
        Edit_menu();
    }
}

void Change_username() {
    bool flag = false;
    while (!flag) {
        system("cls");
        cout << "please enter new username for this account:" << endl;
        cin >> N.user_username_new;
        string target;
        ifstream f2("user profiles");
        string arr[MAX_ROWS][MAX_COLS];
        for (int i = 0; i < MAX_ROWS; i++) {
            for (int j = 0; j < MAX_COLS; j++) {
                f2 >> arr[i][j];
            }
        }

        for (int i = 0; i < MAX_ROWS; i++) {
            if (arr[i][0] == N.user_username_new) {
                target = arr[i][0];
                break;
            }
        }
        f2.close();


        int counter = 0;
        for (int i = 0; i < N.user_username_new.length(); i++) {
            if (isalpha(N.user_username_new[i]))
                counter++;
        }
        if (3 > N.user_username_new.length() || N.user_username_new.length() > 32 ||
            N.user_username_new.length() != counter) {
            int numbere;
            cout << "The username is invalid !" << endl
                 << "the username should be at least 3 character and just enter alphabet" << endl;
            bool flage = false;
            while (!flage) {
                cout << "1-try again." << endl << "2-back to menu." << endl;
                cin >> numbere;
                if (numbere == 1)
                    Change_username();
                if (numbere == 2)
                    Edit_menu();
                if (numbere != 1 && numbere != 2) {
                    cout << "error!" << "(1-2)";
                    getch();
                }
            }
        } else if (N.user_username_new == target) {
            int numbere;
            cout << "This username already taken ." << endl;
            bool flage = false;
            while (!flage) {
                cout << "1-try again." << endl << "2-back to menu." << endl;
                cin >> numbere;
                if (numbere == 1)
                    Change_username();
                if (numbere == 2)
                    Edit_menu();
                if (numbere != 1 && numbere != 2) {
                    cout << "error!" << "(1-2)";
                    getch();
                }
            }
        } else {
            flag = true;
        }

    }
    ifstream f2("user profiles");
    string arr[MAX_ROWS][MAX_COLS];
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            f2 >> arr[i][j];
        }
    }
    f2.close();
    for (int i = 0; i < MAX_ROWS; i++) {
        if (arr[i][0] == E.user_username)
            arr[i][0] = N.user_username_new;
    }
    ofstream f3("user profiles");
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            f3 << arr[i][j] << ' ';
        }
        f3 << endl;
    }
    f3.close();
    cout << "The username successfully changed";
    getch();
    Edit_menu();
}

void Change_password() {
    bool flag = false;
    while (!flag) {
        system("cls");
        cout << "please enter new password for this account :" << endl;
        cin >> N.user_password_new;
        int counter = 0;
        for (int i = 0; i < N.user_password_new.length(); i++) {
            if (isdigit(N.user_password_new[i]))
                counter++;
        }
        if (N.user_password_new.length() != 4 || counter != 4) {
            int numbere;
            cout << "The password is invalid !" << endl << "the password should be 4 character and all digit" << endl;
            bool flage = false;
            while (!flage) {
                cout << "1-try again." << endl << "2-back to menu." << endl;
                cin >> numbere;
                if (numbere == 1)
                    Change_password();
                if (numbere == 2)
                    Edit_menu();
                if (numbere != 1 && numbere != 2) {
                    cout << "error!" << "(1-2)";
                    getch();
                }
            }
        } else
            flag = true;
    }


    ifstream f2("user profiles");
    string arr[MAX_ROWS][MAX_COLS];
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            f2 >> arr[i][j];
        }
    }
    f2.close();
    for (int i = 0; i < MAX_ROWS; i++) {
        if (arr[i][2] == E.user_password)
            arr[i][2] = N.user_password_new;
    }
    ofstream f3("user profiles");
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            f3 << arr[i][j] << ' ';
        }
        f3 << endl;
    }
    f3.close();
    cout << "The password successfully changed";
    getch();
    Edit_menu();
}


void Increase_balance() {
    system("cls");
    int money, x, sum;
    cout << "how much do you want to increase this account balance" << endl;
    cin >> money;
    ifstream f2("user profiles");
    string arr[MAX_ROWS][MAX_COLS];
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            f2 >> arr[i][j];
        }
    }
    f2.close();
    for (int i = 0; i < MAX_ROWS; i++) {
        if (arr[i][0] == E.user_username) {
            x = stoi(arr[i][3]);
            sum = money + x;
            arr[i][3] = to_string(sum);
            getch();
        }
    }
    ofstream f3("user profiles");
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            f3 << arr[i][j] << ' ';
        }
        f3 << endl;
    }
    f3.close();
    cout << "The account balance successfully increased";
    getch();
    Edit_menu();
}

void Show_all_users() {
    system("cls");
    ifstream f2("user profiles");
    string arr[MAX_ROWS][MAX_COLS];
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            f2 >> arr[i][j];
        }
    }
    f2.close();
    for (int i = 0; i < MAX_ROWS; i++) {
        if (arr[i][0].length() != 0) {
            cout << i + 1 << " - " << arr[i][0] << endl;
        }
    }
    cout << "press enter to back menu.";
    getch();
    menu_attendant();
}

void Search_for_account() {
    system("cls");
    cout << "Enter the username of account you want to find:" << endl;
    cin >> O.user_username;

    ifstream f2("user profiles");
    string arr[MAX_ROWS][MAX_COLS];
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            f2 >> arr[i][j];
        }
    }
    f2.close();
    int counter = 0;
    for (int i = 0; i < MAX_ROWS; i++) {
        if (arr[i][0] == O.user_username) {
            cout << "account number: " << arr[i][1] << endl;
            cout << "account password: " << arr[i][2] << endl;
            cout << "account balance: " << arr[i][3] << endl;
            counter++;
            break;
        }
    }
    if (counter == 0)
        cout << "This username is not exist" << endl;
    cout << "press enter to back menu.";
    getch();
    menu_attendant();
}

void Login_user() {
    system("cls");
    cout << "please enter your username:" << endl;
    cin >> LU.user_username;
    cout << "please enter your password:" << endl;
    cin >> LU.user_password;
    Log_user_checker();
}

void Log_user_checker() {
    system("cls");
    ifstream f2("user profiles");
    string arr[MAX_ROWS][MAX_COLS];
    for (int i = 0; i < MAX_ROWS; i++)
        for (int j = 0; j < MAX_COLS; j++)
            f2 >> arr[i][j];
    f2.close();
    int counter = 0;
    for (int i = 0; i < MAX_ROWS; i++) {
        if (arr[i][0] == LU.user_username && arr[i][2] == LU.user_password) {
            counter++;
            menu_user();
        }
    }
    if (counter == 0) {
        int numbere;
        cout << "is incorrect!" << endl;
        bool flage = false;
        while (!flage) {
            cout << "1-try again." << endl << "2-back to menu." << endl;
            cin >> numbere;
            if (numbere == 1)
                Login_user();
            if (numbere == 2)
                main_menu();
            if (numbere != 1 && numbere != 2) {
                cout << "error!" << "(1-2)";
                getch();
            }
        }
    }

}


void menu_user() {
    int number;
    system("cls");
    cout << "---------welcome---------" << endl;
    cout << "1-Account balance" << endl;
    cout << "2-Cash Transfer" << endl;
    cout << "3-Cash withdrawal" << endl;
    cout << "4-Change password" << endl;
    cout << "5-Back to the main menu" << endl;
    cout << "please enter number:" << endl;
    cin >> number;
    if (number == 1)
        Account_balance();
    else if (number == 2)
        Cash_Transfer();
    else if (number == 3)
        Cash_withdrawl();
    else if (number == 4)
        Change_password_as_user();
    else if (number == 5)
        main_menu();
    else {
        system("cls");
        cout << "error!" << endl << "Please enter number(1-2-3-4-5)";
        getch();
        menu_user();
    }

}

void Account_balance() {
    system("cls");
    ifstream f2("user profiles");
    string arr[MAX_ROWS][MAX_COLS];
    for (int i = 0; i < MAX_ROWS; i++)
        for (int j = 0; j < MAX_COLS; j++)
            f2 >> arr[i][j];
    f2.close();
    for (int i = 0; i < MAX_ROWS; i++)
        if (arr[i][0] == LU.user_username) {
            cout << "balance= " << arr[i][3] << "($)" << endl;
            cout << "press enter to back menu.";
            getch();
            menu_user();
        }
}

void Cash_Transfer() {
    bool flag = false;
    while (!flag) {
        system("cls");
        cout << "Enter the username of account you want to transfer cash:" << endl;
        cin >> C.username;
        cout << "How much do you want transfer cash:" << endl;
        cin >> C.cash;
        ifstream f2("user profiles");
        string arr[MAX_ROWS][MAX_COLS];
        for (int i = 0; i < MAX_ROWS; i++)
            for (int j = 0; j < MAX_COLS; j++)
                f2 >> arr[i][j];
        f2.close();
        int x = stoi(C.cash);
        int y, z, m, n;
        string target;
        for (int i = 0; i < MAX_ROWS; i++) {
            if (arr[i][0] == LU.user_username) {
                y = stoi(arr[i][3]);
            }
        }
        for (int i = 0; i < MAX_ROWS; i++) {
            if (arr[i][0] == C.username) {
                target = arr[i][0];
                z = stoi(arr[i][3]);
            }
        }
        if (target != C.username) {
            int numbere;
            cout << "This username is not exist!" << endl;
            bool flage = false;
            while (!flage) {
                cout << "1-try again." << endl << "2-back to menu." << endl;
                cin >> numbere;
                if (numbere == 1)
                    Cash_Transfer();
                if (numbere == 2)
                    menu_user();
                if (numbere != 1 && numbere != 2) {
                    cout << "error!" << "(1-2)";
                    getch();
                }
            }
        } else if (x > y) {
            int numbere;
            cout << "Insuficient inventory" << endl;
            bool flage = false;
            while (!flage) {
                cout << "1-try again." << endl << "2-back to menu." << endl;
                cin >> numbere;
                if (numbere == 1)
                    Cash_Transfer();
                if (numbere == 2)
                    menu_user();
                if (numbere != 1 && numbere != 2) {
                    cout << "error!" << "(1-2)";
                    getch();
                }
            }
        } else {
            y = y - x;
            z = z + x;
            flag = true;
            for (int i = 0; i < MAX_ROWS; i++) {
                if (arr[i][0] == LU.user_username)
                    arr[i][3] = to_string(y);
                if (arr[i][0] == C.username)
                    arr[i][3] = to_string(z);
            }
            ofstream f3("user profiles");
            for (int i = 0; i < MAX_ROWS; i++) {
                for (int j = 0; j < MAX_COLS; j++) {
                    f3 << arr[i][j] << ' ';
                }
                f3 << endl;
            }
            f3.close();
            break;
        }
    }


    cout << "Transfering cash was successful." << endl << "Press enter to back menu" << endl;
    getch();
    menu_user();
}

void Cash_withdrawl() {
    bool flag = false;
    while (!flag) {
        system("cls");
        cout << "How much money do you want withdrawl?" << endl;
        cin >> W.cash;
        ifstream f2("user profiles");
        string arr[MAX_ROWS][MAX_COLS];
        for (int i = 0; i < MAX_ROWS; i++)
            for (int j = 0; j < MAX_COLS; j++)
                f2 >> arr[i][j];
        f2.close();
        int x, counter = 0;
        for (int i = 0; i < MAX_ROWS; i++) {
            if (arr[i][0] == LU.user_username) {
                if (stoi(W.cash) <= stoi(arr[i][3])) {
                    x = stoi(arr[i][3]) - stoi(W.cash);
                    arr[i][3] = to_string(x);
                    flag = true;
                    ofstream f3("user profiles");
                    for (int i = 0; i < MAX_ROWS; i++) {
                        for (int j = 0; j < MAX_COLS; j++) {
                            f3 << arr[i][j] << ' ';
                        }
                        f3 << endl;
                    }
                    f3.close();
                    counter++;
                }
            }
        }
        if (counter != 0) {
            cout << "Cash withdrawl successfully done." << endl;
            getch();
        } else if (counter == 0) {
            int numbere;
            cout << "You do not have enough money." << endl;
            bool flage = false;
            while (!flage) {
                cout << "1-try again." << endl << "2-back to menu." << endl;
                cin >> numbere;
                if (numbere == 1)
                    Cash_withdrawl();
                if (numbere == 2)
                    menu_user();
                if (numbere != 1 && numbere != 2) {
                    cout << "error!" << "(1-2)";
                    getch();
                }
            }
        }
    }
    menu_user();
}

void Change_password_as_user() {
    system("cls");
    bool flag1 = false, flag2 = false;
    string target;
    ifstream f2("user profiles");
    string arr[MAX_ROWS][MAX_COLS];
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            f2 >> arr[i][j];
        }
    }
    f2.close();
    for (int i = 0; i < MAX_ROWS; i++) {
        if (arr[i][0] == LU.user_username) {
            target = arr[i][2];
        }
    }
    while (!flag1) {
        system("cls");
        cout << "please enter previous password:" << endl;
        cin >> NP.previous_password;
        if (NP.previous_password != target) {
            int numbere;
            cout << "The password is wrong." << endl;
            bool flage = false;
            while (!flage) {
                cout << "1-try again." << endl << "2-back to menu." << endl;
                cin >> numbere;
                if (numbere == 1)
                    Change_password_as_user();
                if (numbere == 2)
                    menu_user();
                if (numbere != 1 && numbere != 2) {
                    cout << "error!" << "(1-2)";
                    getch();
                }
            }
        } else
            flag1 = true;
    }
    while (!flag2) {
        system("cls");
        cout << "please enter new password:" << endl;
        cin >> NP.new_password;
        int counter = 0;
        for (int i = 0; i < NP.new_password.length(); i++) {
            if (isdigit(NP.new_password[i]))
                counter++;
        }
        if (NP.new_password.length() != 4 || counter != 4) {
            int numbere;
            cout << "The new password is invalid !" << endl << "the password should be 4 character and all digit"
                 << endl;
            bool flage = false;
            while (!flage) {
                cout << "1-try again." << endl << "2-back to menu." << endl;
                cin >> numbere;
                if (numbere == 1)
                    Change_password_as_user();
                if (numbere == 2)
                    menu_user();

                if (numbere != 1 && numbere != 2) {
                    cout << "error!" << "(1-2)";
                    getch();
                }
            }
        } else
            flag2 = true;
    }
    for (int i = 0; i < MAX_ROWS; i++) {
        if (arr[i][0] == LU.user_username) {
            arr[i][2] = NP.new_password;
        }
    }
    ofstream f3("user profiles");
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            f3 << arr[i][j] << ' ';
        }
        f3 << endl;
    }
    f3.close();
    cout << "The password successfully changed";
    getch();
    menu_user();
}
