#include <iostream>
#include <string>
using namespace std;

bool is_valid_credit_card(string card_number) {
    int sum = 0;
    int digit, temp;
    bool is_second = false;

    for (int i = card_number.length() - 1; i >= 0; i--) {
        digit = card_number[i] - '0';

        if (is_second) {
            temp = digit * 2;
            if (temp > 9) {
                temp = (temp % 10) + 1;
            }
        } else {
            temp = digit;
        }

        sum += temp;
        is_second = !is_second;
    }
    return (sum % 10 == 0);
}

int main() {
    string card_number;

    cout << "Enter credit card number: ";
    cin >> card_number;

    if (is_valid_credit_card(card_number)) {
        cout << "The credit card number is valid." << endl;
    } else {
        cout << "The credit card number is invalid." << endl;
    }

    return 0;
}
