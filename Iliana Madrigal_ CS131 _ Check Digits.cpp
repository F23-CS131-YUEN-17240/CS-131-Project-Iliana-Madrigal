#include <iostream>
#include <string>
using namespace std;


bool isISBNvalid(string num);
int checkDigit(string num);
bool isUSPSvalid(string num);
int checkDigitUSPS(string num);

int main()
{
    int choice;
    string num_ISBN, check_isbn, num_usps, check_usps;
    cout << "Welcome this code is meant to use check digits to help verify the entered numbers." << endl;
    cout << "You have the options to check if the entered ISBN or USPS money order is valid, or to find their check digit." << endl;
    cout << "Please select what option you wish to choose: " << endl;
    cout << "1. ISBN-10 Checker" << endl;
    cout << "2. Find the check digit for ISBN-10" << endl;
    cout << "3. USPS money order checker." << endl;
    cout << "4. Find the check digit for the USPS money order." << endl;
    cin >> choice;
    if (choice == 1) {
        cout << "Please enter the ten digit ISBN-10 (ex. 1234567890): ";
        cin >> num_ISBN;
        if (isISBNvalid(num_ISBN)) {
            cout << "\nThe ISBN is valid" << endl;
        }
        else {
            cout << "\nThe ISBN is invalid." << endl;
        }
    }
    if (choice == 2) {
        cout << "Please enter the nine digit ISBN-10 number (ex. 123456789): ";
        cin >> check_isbn;
        cout << "\nThe check digit for the ISBN-10 number " << check_isbn << " is:  " << checkDigit(check_isbn);
    }
    if (choice == 3) {
        cout << "Please enter the 11-digit USPS money order number (ex. 12345678901): ";
        cin >> num_usps;
        if (isUSPSvalid(num_usps)) {
            cout << "\nThe UPSP money order number is valid." << endl;
        }
        else {
            cout << "\nThe USPS money order number is invalid." << endl;
        }
    }
    if (choice == 4) {
        cout << "Please enter the 10-digit money order number (ex. 1234567890): ";
        cin >> check_usps;
        cout << "\n The check digit for theUSPS money order " << check_usps << " is: " << checkDigitUSPS(check_usps);
    }
    else {
        cout << "Invalid choice entered." << endl;
        return 0;
    }

    return 0;
}

bool isISBNvalid(string isbn) {
    int x = 1;
    int sum = 0;
    int check = 0;
    if (isbn.size() != 10) {
        return false;
    }

    for (int i = 0; i < 10; i++) {
        int num = isbn[i] - '0';
        sum += (x * num);
        x++;
    }

    check = (sum % 11);
    if (check == 0) {
        return true;
    }
    else {
        return false;
    }
}

int checkDigit(string isbn) {
    int sum = 0;
    int x = 1;
    int digit;
    if (isbn.size() != 9) {
        cout << "Invalid ISBN number entered.";
        exit(0);
    }
    for (int i = 0; i < 9; i++) {
        int num = isbn[i] - '0';
        sum += (x * num);
        x++;
    }
    digit = (sum % 11);
    return digit;
}

bool isUSPSvalid(string usps) {
    int sum = 0;
    int check = 0;
    if (usps.size() != 11) {
        return false;
    }

    for (int i = 0; i < 10; i++) {
        int num = usps[i] - '0';
        sum += num;
    }

    int last = usps[10] - '0';

    check = (sum % 9);
    if (check == last) {
        return true;
    }
    else {
        return false;
    }
}

int checkDigitUSPS(string usps) {
    int sum = 0;
    int check = 0;
    if (usps.size() != 10) {
        cout << "Invalid USPS money order number.";
        exit(0);
    }

    for (int i = 0; i < 10; i++) {
        int num = usps[i] - '0';
        sum += num;
    }

    check = (sum % 9);
    return check;
}