

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
using namespace std;

// ======================================
// BASIC LOGIC GATES
// ======================================

int AND(int a, int b) {
    return a && b;
}

int OR(int a, int b) {
    return a || b;
}

int NOT(int a) {
    return !a;
}

int NAND(int a, int b) {
    return !(a && b);
}

int NOR(int a, int b) {
    return !(a || b);
}

int XOR(int a, int b) {
    return a != b;
}

int XNOR(int a, int b) {
    return a == b;
}

int BUFFER(int a) {
    return a;
}

// ======================================
// INPUT VALIDATION
// ======================================

int getNumber(string message, int minValue, int maxValue) {
    int number;

    while (true) {
        cout << message;

        if (cin >> number) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (number >= minValue && number <= maxValue) {
                return number;
            }
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Invalid input! Try again.\n";
    }
}

int getBit(string name) {
    return getNumber("Enter " + name + " (0 or 1): ", 0, 1);
}

// ======================================
// HALF ADDER
// ======================================

void halfAdder(int a, int b) {
    int sum = XOR(a, b);
    int carry = AND(a, b);

    cout << "\n--- HALF ADDER ---\n";
    cout << "SUM       = " << sum << endl;
    cout << "CARRY OUT = " << carry << endl;
}

// ======================================
// FULL ADDER
// ======================================

void fullAdder(int a, int b, int cinBit) {
    int p = XOR(a, b);

    int sum = XOR(p, cinBit);
    int carry = OR(AND(a, b), AND(p, cinBit));

    cout << "\n--- FULL ADDER ---\n";
    cout << "SUM       = " << sum << endl;
    cout << "CARRY OUT = " << carry << endl;
}

// ======================================
// HALF SUBTRACTOR
// ======================================

void halfSubtractor(int a, int b) {
    int difference = XOR(a, b);
    int borrow = AND(NOT(a), b);

    cout << "\n--- HALF SUBTRACTOR ---\n";
    cout << "DIFFERENCE = " << difference << endl;
    cout << "BORROW     = " << borrow << endl;
}

// ======================================
// FULL SUBTRACTOR
// ======================================

void fullSubtractor(int a, int b, int bin) {
    int p = XOR(a, b);

    int difference = XOR(p, bin);
    int borrow = OR(AND(NOT(a), b), AND(NOT(p), bin));

    cout << "\n--- FULL SUBTRACTOR ---\n";
    cout << "DIFFERENCE = " << difference << endl;
    cout << "BORROW     = " << borrow << endl;
}

// ======================================
// 2:1 MULTIPLEXER
// ======================================

void multiplexer(int a, int b, int select) {
    int output = OR(AND(NOT(select), a), AND(select, b));

    cout << "\n--- 2:1 MULTIPLEXER ---\n";
    cout << "SELECT = " << select << endl;
    cout << "OUTPUT = " << output << endl;
}

// ======================================
// 4-BIT RIPPLE CARRY ADDER
// ======================================

void rippleCarryAdder() {
    int A[4], B[4], S[4];
    int carry;

    cout << "\n--- 4-BIT RIPPLE CARRY ADDER ---\n";

    cout << "\nEnter A bits (MSB to LSB):\n";

    for (int i = 3; i >= 0; i--) {
        stringstream ss;
        ss << "A[" << i << "]";
        A[i] = getBit(ss.str());
    }

    cout << "\nEnter B bits (MSB to LSB):\n";

    for (int i = 3; i >= 0; i--) {
        stringstream ss;
        ss << "B[" << i << "]";
        B[i] = getBit(ss.str());
    }

    carry = getBit("Carry In");

    for (int i = 0; i < 4; i++) {
        int p = XOR(A[i], B[i]);

        S[i] = XOR(p, carry);

        carry = OR(AND(A[i], B[i]), AND(p, carry));
    }

    cout << "\nA      = ";
    for (int i = 3; i >= 0; i--) {
        cout << A[i];
    }

    cout << "\nB      = ";
    for (int i = 3; i >= 0; i--) {
        cout << B[i];
    }

    cout << "\nRESULT = " << carry << " ";

    for (int i = 3; i >= 0; i--) {
        cout << S[i];
    }

    cout << endl;
}

// ======================================
// TRUTH TABLE GENERATOR
// ======================================

void truthTable() {
    cout << "\n--- LOGIC GATE TRUTH TABLE ---\n\n";

    cout << "A B | AND OR NAND NOR XOR XNOR\n";
    cout << "------------------------------\n";

    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            cout << a << " " << b << " |  "
                 << AND(a, b) << "   "
                 << OR(a, b) << "    "
                 << NAND(a, b) << "    "
                 << NOR(a, b) << "   "
                 << XOR(a, b) << "    "
                 << XNOR(a, b) << endl;
        }
    }

    cout << "\nNOT and BUFFER:\n";
    cout << "A | NOT BUFFER\n";
    cout << "--------------\n";

    for (int a = 0; a <= 1; a++) {
        cout << a << " |  "
             << NOT(a) << "     "
             << BUFFER(a) << endl;
    }
}

// ======================================
// MAIN PROGRAM
// ======================================

int main() {
    int choice, A, B, C;

    do {
        cout << "\n====================================\n";
        cout << "       DIGITAL LOGIC SIMULATOR\n";
        cout << "====================================\n";

        cout << "1.  AND Gate\n";
        cout << "2.  OR Gate\n";
        cout << "3.  NOT Gate\n";
        cout << "4.  NAND Gate\n";
        cout << "5.  NOR Gate\n";
        cout << "6.  XOR Gate\n";
        cout << "7.  XNOR Gate\n";
        cout << "8.  BUFFER Gate\n";
        cout << "9.  Half Adder\n";
        cout << "10. Full Adder\n";
        cout << "11. Half Subtractor\n";
        cout << "12. Full Subtractor\n";
        cout << "13. 2:1 Multiplexer\n";
        cout << "14. 4-bit Ripple Carry Adder\n";
        cout << "15. Truth Table Generator\n";
        cout << "0.  Exit\n";

        cout << "====================================\n";

        choice = getNumber("Select an option: ", 0, 15);

        if (choice == 0) {
            cout << "\nProgram ended. Goodbye!\n";
            break;
        }

        if (choice == 14) {
            rippleCarryAdder();
            continue;
        }

        if (choice == 15) {
            truthTable();
            continue;
        }

        A = getBit("A");

        if (choice != 3 && choice != 8) {
            B = getBit("B");
        }

        if (choice == 10) {
            C = getBit("Carry In");
        } else if (choice == 12) {
            C = getBit("Borrow In");
        } else if (choice == 13) {
            C = getBit("Select");
        }

        cout << "\n========== RESULT ==========\n";

        switch (choice) {
            case 1:
                cout << "AND = " << AND(A, B) << endl;
                break;

            case 2:
                cout << "OR = " << OR(A, B) << endl;
                break;

            case 3:
                cout << "NOT = " << NOT(A) << endl;
                break;

            case 4:
                cout << "NAND = " << NAND(A, B) << endl;
                break;

            case 5:
                cout << "NOR = " << NOR(A, B) << endl;
                break;

            case 6:
                cout << "XOR = " << XOR(A, B) << endl;
                break;

            case 7:
                cout << "XNOR = " << XNOR(A, B) << endl;
                break;

            case 8:
                cout << "BUFFER = " << BUFFER(A) << endl;
                break;

            case 9:
                halfAdder(A, B);
                break;

            case 10:
                fullAdder(A, B, C);
                break;

            case 11:
                halfSubtractor(A, B);
                break;

            case 12:
                fullSubtractor(A, B, C);
                break;

            case 13:
                multiplexer(A, B, C);
                break;
        }

        cout << "============================\n";

    } while (true);

    return 0;
}

