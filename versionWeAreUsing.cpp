#include <iostream>  // Stream for input/output - our bridge to the user
#include <cstdlib>   // Standard library for rand() and srand()
#include <ctime>     // Time library to seed the randomizer with the current clock
#include <string>    // String class to handle all our text data easily

using namespace std; // Use the standard namespace to keep code clean and readable

// =========================================================
// ✨ THE SQUAD DATABASE (UPDATED) ✨
// =========================================================

// This is our primary index. The order here determines the index for everything else!
string members[8] = {"Sarah", "Maha", "Ayeisha", "Luke", "Vanessa", "Juveria", "Stephanie", "Silvi"};

// Row 0: Sarah, Row 1: Maha, Row 2: Ayeisha, Row 3: Luke, Row 4: Vanessa, Row 5: Juveria, Row 6: Stephanie, Row 7: Silvi
string questions[8][5] = {

    //Sarah's questions
    {"Sarah's fav F1 team?",
         "Sarah's fav jewelry metal?",
         "How long has Sarah driven?",
          "Can Sarah solder?", 
          "Does Sarah run an F1 blog?"},

//Maha's questions (UPDATED)
    {"What year did Maha immigrate to America?", 
        "How many high school hackathons did Maha win?",
         "Who's Maha's favorite poet?",
          "Is Maha a professional sUAS driver?",
           "What is Maha's favorite coordinate transformation?"},
           
// Ayeisha's questions
    {"Ayeisha's skill?",
         "Ayeisha's book?", 
         "Ayeisha's birth month?", 
         "Ayeisha's OS?", 
         "Ayeisha's height?"},

// Luke's questions (UPDATED)
    {"How many tornadoes has Luke seen?", 
        "What is Luke's favorite 3d hyperbolic honeycomb?", 
        "Luke's favorite drink?", 
        "Has Luke ever wrestled a bear in the Ozarks?", 
        "Does Luke own a custom-built medieval trebuchet?"},

// Vanessa's questions
    {"What baby animal did Vanessa nurse?",
         "Has Vanessa traveled overseas?", 
         "Vanessa's target non-tech field?", 
         "Vanessa's chocolate choice?",
          "Vanessa's piercing count?"},

//Juveria's questions
    {"How many chicks did Juveria raise?",
         "What other state did Juveria live in?", 
         "Juveria's dream superpower?",
          "Is Juveria good at baking?", 
          "Juveria's favorite snack?"},

// Stephanie's questions
    {"Times Steph watched Shrek 2 in a year?",
         "Times Steph sprained her ankle?", 
         "Steph's favorite TV show?",
          "Where has Steph traveled?",
           "Steph's favorite band?"}, 

// Silvi's questions
    {"Silvi's favorite movie genre?",
         "Silvi's favorite animal?", 
         "Has Silvi driven over 3 years?", 
         "Silvi's current favorite show?", 
         "Silvi's favorite color?"}
};

// The "Yes" source. These are the factual answers you provided.
string trueAnswers[8][5] = {

 // Sarah's answers   
    {"Mercedes", 
        "Gold", 
        "1 year", 
        "Very well", 
        "False"},

    // Maha's answers (UPDATED)   
    {"2018",
         "2", 
         "Rabindranath Tagore", 
         "Yes",
          "Cylindrical"},

    // Ayeisha's answers
    {"Design",
         "1984",
         "May", 
         "Linux", 
         "170cm"},

// Luke's answers (UPDATED)
    {"2",
         "{3,5,3} icosahedral honeycomb", 
         "Hot chocolate",
          "False", 
          "False"},

          // Vanessa's answers
    {"Lion",
         "False", 
         "Healthcare", 
         "Dark chocolate", 
         "7"},

         // Juveria's answers
    {"3",
         "New Jersey",
          "Teleporting", 
          "True", 
          "Hot Cheetos"},
            // Stephanie's answers
    {"20", 
        "3 times", 
        "Breaking Bad",
         "Mexico", 
         "The Strokes"},

            // Silvi's answers
    {"Horror", 
        "Cat", 
        "False", 
        "The Boys", 
        "Black"}
};

// The "No" source. These are the lies the Sentinel will try to trick you with.
string wrongAnswers[8][5] = {
    {"Red Bull", "Silver", "3 years", "Not at all", "True"},
    {"2020", "4", "Bob Dylan", "No", "Spherical"}, // Maha False
    {"Coding", "Hobbit", "June", "Windows", "160cm"},
    {"1", "{5,3,5} pentahedral honeycomb", "Coffee", "True", "True"}, // Luke False
    {"Monkey", "True", "Finance", "Milk chocolate", "3"},
    {"10", "New York", "Flying", "False", "Pretzels"},
    {"18", "2 times", "Bridgerton", "Spain", "The Arctic Monkeys"},
    {"Comedy", "Dog", "True", "Stranger Things", "White"}
};

// Redemption round questions
string profQuestions[3] = {"Prof's language?", "Prof's years teaching?", "Prof's office?"};
string profAnswers[3] = {"C++", "10", "404"};

// =========================================================
// 🎨 LOGIC & FLAVOR FUNCTIONS
// =========================================================

void printZoneArt(int mIdx) {
    cout << "\n--- ZONE: " << members[mIdx] << " ---" << endl; 
    if(mIdx == 0)      cout << "  🏎️💨 [F1 TRACK] " << endl; 
    else if(mIdx == 6) cout << "  👹🏰 [SHREK SWAMP]" << endl; 
    else               cout << "  [==] [==] " << endl;        
}

void applyZoneModifier(int mIdx, int &bonus) {
    if(mIdx == 0) cout << "[BONUS] Sarah's focus: +1 Accuracy!" << endl;
    else if(mIdx == 1) { cout << "[BONUS] Maha's luck: +1 Point!" << endl; bonus++; }
}

// =========================================================
// 🚀 MAIN GAME ENGINE
// =========================================================

int main() {
    srand(static_cast<unsigned int>(time(0)));

    // 1. HOMEPAGE & INSTRUCTIONS
    cout << "================================================" << endl;
    cout << "      🌀 WELCOME TO THE SQUAD LABYRINTH 🌀      " << endl;
    cout << "================================================" << endl;
    cout << "\n\"Are you ready to enter the labyrinth?\" (y/n): ";
    char ready; cin >> ready;
    if (ready != 'y' && ready != 'Y') return 0;

    cout << "\n--- INSTRUCTIONS ---" << endl;
    cout << "- Identify if the Sentinel is telling the TRUTH (yes) or a LIE (no)." << endl;
    cout << "- Achieve a 3-win streak to escape the simulation." << endl;
    cout << "- If you fail, the Professor will challenge you to save your life." << endl;
    cout << "------------------------------------------------\n" << endl;

    int lives = 3, streak = 0, bonusPoints = 0, arch;
    int stats[8] = {0,0,0,0,0,0,0,0}; 
    bool usedAbility = false;          

    cout << "--- CHOOSE ARCHETYPE ---\n1. Hacker (Reveal Liar)\n2. Diplomat (Skip Error)\n3. Athlete (+1 Life)\nChoice: ";
    cin >> arch; 
    if(arch == 3) lives++; 

    while (lives > 0) {
        // STATUS LOG
        cout << "\n[ 📊 LOG | Lives: " << lives << " | Streak: " << streak << " | Shop Pts: " << bonusPoints << " ]" << endl;

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

        cout << "QUESTION: " << questions[mIdx][qIdx] << endl;
        cout << "SENTINEL: " << (role == 0 ? trueAnswers[mIdx][qIdx] : wrongAnswers[mIdx][qIdx]) << endl;
        cout << "Truth? (yes/no): ";
        string guess; cin >> guess;

        if ((guess == "yes" && role == 0) || (guess == "no" && role == 1)) {
            streak++;        
            stats[mIdx]++;   
            cout << ">>> CORRECT! Streak: " << streak << endl;
        } else {
            if(arch == 2 && !usedAbility) {
                cout << "[DIPLOMAT] Ability used to bypass failure!" << endl;
                usedAbility = true;
            } else {
                cout << "\n>>> WRONG! Professor Challenge!" << endl;
                int pIdx = rand() % 3;
                cout << profQuestions[pIdx] << " Answer: ";
                string pAns; cin >> pAns;
                
                if (pAns == profAnswers[pIdx]) { 
                    cout << "Professor is satisfied. +1 Point." << endl;
                    bonusPoints++; 
                    streak = 0; 
                } else { 
                    cout << "Professor is disappointed. -1 Life." << endl;
                    lives--; 
                    streak = 0; 
                }
            }
        }
        
        if (streak >= 3) {
            cout << "\n🔥 STREAK ACHIEVED! WINNER! 🔥" << endl;
            break;
        }
    }

    cout << "\n--- FINAL REPORT ---" << endl;
    for(int i=0; i<8; i++) {
        cout << members[i] << ": " << stats[i] << " correct answers." << endl;
    }
    
    if (lives > 0) cout << "\n🎉 YOU ESCAPED THE SIMULATION! 🎉" << endl;
    else cout << "\n💀 GAME OVER. YOU RAN OUT OF LIVES. 💀" << endl;

    return 0; 
}