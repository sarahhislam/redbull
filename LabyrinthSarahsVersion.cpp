#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// --- DATA STRUCTURES ---
string members[8] = {"Sarah", "Maha", "Ayeisha", "Luke", "Vanessa", "Juveria", "Stephanie", "Silvi"};

string questions[8][5] = {
    {"Sarah's city?", "Sarah's hobby?", "Sarah's fav food?", "Sarah's major?", "Sarah's cat name?"},
    {"Maha's grad year?", "Maha's favorite sport?", "Maha's dream job?", "Maha's pet?", "Maha's color?"},
    {"Ayeisha's skill?", "Ayeisha's book?", "Ayeisha's birth month?", "Ayeisha's OS?", "Ayeisha's height?"},
    {"Luke's car?", "Luke's fav game?", "Luke's coffee?", "Luke's gym split?", "Luke's hair color?"},
    {"Vanessa's sibling count?", "Vanessa's movie?", "Vanessa's eye color?", "Vanessa's phone?", "Vanessa's music?"},
    {"Juveria's number?", "Juveria's instrument?", "Juveria's dream city?", "Juveria's laptop?", "Juveria's snack?"},
    {"Stephanie's language?", "Stephanie's travel?", "Stephanie's birthday?", "Stephanie's team?", "Stephanie's hobby?"},
    {"Silvi's join year?", "Silvi's coding style?", "Silvi's OS?", "Silvi's snack?", "Silvi's project?"}
};

string trueAnswers[8][5] = {
    {"London", "Reading", "Pizza", "Medicine", "Luna"},
    {"2025", "Tennis", "Pilot", "Dog", "Blue"},
    {"Design", "1984", "May", "Linux", "170cm"},
    {"Tesla", "Elden Ring", "Latte", "Push", "Black"},
    {"3", "Inception", "Brown", "iPhone", "Jazz"},
    {"7", "Piano", "Tokyo", "Dell", "Chips"},
    {"Spanish", "Japan", "June", "Red Bull", "Chess"},
    {"2024", "Clean", "Windows", "Nuts", "Alpha"}
};

string wrongAnswers[8][5] = {
    {"Paris", "Gaming", "Pasta", "Arts", "Simba"},
    {"2026", "Soccer", "Doctor", "Bird", "Red"},
    {"Coding", "Hobbit", "June", "Windows", "160cm"},
    {"Ford", "FIFA", "Mocha", "Legs", "Blonde"},
    {"1", "Titanic", "Blue", "Samsung", "Rock"},
    {"13", "Guitar", "Paris", "Apple", "Nuts"},
    {"French", "Italy", "July", "Monster", "Tennis"},
    {"2022", "Messy", "Mac", "Chips", "Beta"}
};

string profQuestions[3] = {"Prof's language?", "Prof's years teaching?", "Prof's office?"};
string profAnswers[3] = {"C++", "10", "404"};

void printZoneArt(int mIdx) {
    cout << "\n--- ZONE: " << members[mIdx] << " ---" << endl;
    if(mIdx == 0) cout << " /\\_/\\ \n( o.o )" << endl; 
    else if(mIdx == 1) cout << "  ___  \n |Grad|" << endl;
    else cout << " [==] [==]" << endl;
}

void applyZoneModifier(int mIdx, int &bonus) {
    if(mIdx == 0) cout << "[BONUS] Sarah's focus: +1 Accuracy!" << endl;
    else if(mIdx == 1) { cout << "[BONUS] Maha's luck: +1 Point!" << endl; bonus++; }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int lives = 3, streak = 0, bonusPoints = 0, arch;
    int stats[8] = {0,0,0,0,0,0,0,0};
    bool usedAbility = false;

    cout << "--- CHOOSE ARCHETYPE ---\n1. Hacker (Reveal Liar)\n2. Diplomat (Skip Error)\n3. Athlete (+1 Life)\nChoice: ";
    cin >> arch;
    if(arch == 3) lives++;

    while (lives > 0) {
        if (bonusPoints >= 2) {
            cout << "\n[SHOP] Buy life for 2pts? (y/n): ";
            char choice; cin >> choice;
            if (choice == 'y') { bonusPoints -= 2; lives++; }
        }

        int mIdx = rand() % 8;
        int qIdx = rand() % 5;
        int role = rand() % 2; 

        printZoneArt(mIdx);
        applyZoneModifier(mIdx, bonusPoints);

        if(arch == 1 && !usedAbility) {
            cout << "[HACKER] Sentinel is " << (role ? "A LIAR" : "TRUTHFUL") << endl;
            usedAbility = true;
        }

        cout << "SENTINEL: " << (role == 0 ? trueAnswers[mIdx][qIdx] : wrongAnswers[mIdx][qIdx]) << endl;
        cout << "Truth? (yes/no): ";
        string guess; cin >> guess;

        if ((guess == "yes" && role == 0) || (guess == "no" && role == 1)) {
            streak++; stats[mIdx]++;
            cout << ">>> CORRECT!" << endl;
        } else {
            if(arch == 2 && !usedAbility) {
                cout << "[DIPLOMAT] Ability used to bypass failure!" << endl;
                usedAbility = true;
            } else {
                cout << "\n>>> WRONG! Professor Challenge!" << endl;
                int pIdx = rand() % 3;
                cout << profQuestions[pIdx] << " Answer: ";
                string pAns; cin >> pAns;
                if (pAns == profAnswers[pIdx]) { bonusPoints++; streak = 0; }
                else { lives--; streak = 0; }
            }
        }
        if (streak >= 3) break;
    }

    cout << "\n--- FINAL REPORT ---" << endl;
    for(int i=0; i<8; i++) cout << members[i] << ": " << stats[i] << "/5 correct." << endl;
    if (lives > 0) cout << "YOU ESCAPED!" << endl;
    else cout << "GAME OVER." << endl;

    return 0;
}