#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void printSlowly(const char* text, int delay = 100) {
    for (int i = 0; text[i] != '\0'; ++i) {
        cout << text[i];
        Sleep(delay);
    }
}

void printJolokotturin() {
    const char* jolokotturin = "    I    a m    J o l a k k o t t u r i n n .";
    for (int i = 0; jolokotturin[i] != '\0'; ++i) {
        cout << jolokotturin[i];
        Sleep(100);
    }
    cout << endl;
}

void printASCIIArt() {
    const char* art[] = {
        "      _.---.._             _.---...__      ",
        "   .-'   /\\   \\          .'  /\\     /   ",
        "   `.   (  )   \\        /   (  )   /      ",
        "     `.  \\/   .'\\      /`.   \\/  .'     ",
        "       ``---''   )    (   ``---''          ",
        "               .';.--.;`.                  ",
        "             .' /_...._\\ `.               ",
        "           .'   `.a  a.'   `.              ",
        "          (        \\/        )            ",
        "           `.___..-'`-..___.'              ",
        "              \\          /                 ",
        "               `-.____.-'                  "
    };
    for (int i = 0; i < sizeof(art) / sizeof(art[0]); ++i) {
        cout << art[i] << endl;
        Sleep(100);
    }
    cout << endl;
}

const char* generateResponse(int digit) {
    if (digit == 1 || digit == 2) {
        return "  Interesting... But, no.";
    } else if (digit == 3 || digit == 4) {
        return "  I believe that the answer is... no.";
    } else if (digit == 5 || digit == 6) {
        return "  That's funny... It's a yes.";
    } else if (digit == 7 || digit == 8) {
        return "... You know what's the answer to that.";
    } else {
        return "  I assure you that it's a yes.";
    }
}

void setConsoleSize(int width, int height) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Set screen buffer size
    COORD bufferSize;
    bufferSize.X = width;
    bufferSize.Y = height;
    SetConsoleScreenBufferSize(hConsole, bufferSize);

    // Set window size
    SMALL_RECT windowSize;
    windowSize.Left = 0;
    windowSize.Top = 0;
    windowSize.Right = width - 1;
    windowSize.Bottom = height - 1;
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}

int main() {

    srand(static_cast<unsigned>(time(0)));
    int digit = rand() % 8 + 1;

    printJolokotturin();
    printASCIIArt();

    printSlowly("  What is it that you inquire?", 100);
    cout << endl << endl;

    string question;
    cout << "  ";
    cin >> question;
    cout << endl << endl;

    // Clear the screen after input
    system("cls");

    printASCIIArt();

    const char* response = generateResponse(digit);
    printSlowly(response, 100);
    cout << endl << endl;

    // Credits to Felix Lee for the ASCII art.

    return 0;
}

