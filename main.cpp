#include "tubes.h"

int main()
{
    string input;
    menu_welcome();
    cin >> input;

    if(input == "Ya" || input == "YA" || input == "ya") {
        clearScreen();
        listKelompok LKp;
        createListKelompok(LKp);

        cin.ignore();

        menu(LKp);
    }
    return 0;
}
