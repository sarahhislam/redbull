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

// Row 0: Sarah, Row 4: Vanessa, Row 5: Juveria, Row 6: Stephanie, Row 7: Silvi (Updated!)
string questions[8][5] = {
    {"Sarah's fav F1 team?", "Sarah's fav jewelry metal?", "How long has Sarah driven?", "Can Sarah solder?", "Does Sarah run an F1 blog?"},
    {"Maha's grad year?", "Maha's favorite sport?", "Maha's dream job?", "Maha's pet?", "Maha's color?"},
    {"Ayeisha's skill?", "Ayeisha's book?", "Ayeisha's birth month?", "Ayeisha's OS?", "Ayeisha's height?"},
    {"Luke's car?", "Luke's fav game?", "Luke's coffee?", "Luke's gym split?", "Luke's hair color?"},
    {"What baby animal did Vanessa nurse?", "Has Vanessa traveled overseas?", "Vanessa's target non-tech field?", "Vanessa's chocolate choice?", "Vanessa's piercing count?"},
    {"How many chicks did Juveria raise?", "What other state did Juveria live in?", "Juveria's dream superpower?", "Is Juveria good at baking?", "Juveria's favorite snack?"},
    {"Times Steph watched Shrek 2 in a year?", "Times Steph sprained her ankle?", "Steph's favorite TV show?", "Where has Steph traveled?", "Steph's favorite band?"},
    {"Silvi's favorite movie genre?", "Silvi's favorite animal?", "Has Silvi driven over 3 years?", "Silvi's current favorite show?", "Silvi's favorite color?"}
};

// The "Yes" source. These are the factual answers you provided.
string trueAnswers[8][5] = {
    {"Mercedes", "Gold", "1 year", "Very well", "False"},
    {"2025", "Tennis", "Pilot", "Dog", "Blue"},
    {"Design", "1984", "May", "Linux", "170cm"},
    {"Tesla", "Elden Ring", "Latte", "Push", "Black"},
    {"Lion", "False", "Healthcare", "Dark chocolate", "7"},
    {"3", "New Jersey", "Teleporting", "True", "Hot Cheetos"},
    {"20", "3 times", "Breaking Bad", "Mexico", "The Strokes"},
    {"Horror", "Cat", "False", "The Boys", "Black"}
};

// The "No" source. These are the lies the Sentinel will try to trick you with.
string wrongAnswers[8][5] = {
    {"Red Bull", "Silver", "3 years", "Not at all", "True"},
    {"2026", "Soccer", "Doctor", "Bird", "Red"},
    {"Coding", "Hobbit", "June", "Windows", "160cm"},
    {"Ford", "FIFA", "Mocha", "Legs", "Blonde"},
    {"Monkey", "True", "Finance", "Milk chocolate", "3"},
    {"10", "New York", "Flying", "False", "Pretzels"},
    {"18", "2 times", "Bridgerton", "Spain", "The Arctic Monkeys"},
    {"Comedy", "Dog", "True", "Stranger Things", "White"}
};

// Redemption round questions - if you get a teammate question wrong, the Professor steps in!
string profQuestions[3] = {"Prof's language?", "Prof's years teaching?", "Prof's office?"};
string profAnswers[3] = {"C++", "10", "404"};

// =========================================================
// 🎨 LOGIC & FLAVOR FUNCTIONS
// =========================================================

// Visual helper: Draws ASCII art based on who the user is visiting.
void printZoneArt(int mIdx) {
    cout << "\n--- ZONE: " << members[mIdx] << " ---" << endl; 
    if(mIdx == 0)      cout << "  🏎️💨 [F1 TRACK] " << endl; // Sarah's F1 Theme
    else if(mIdx == 6) cout << "  👹🏰 [SHREK SWAMP]" << endl; // Steph's Shrek Theme
    else               cout << "  [==] [==] " << endl;        // Default blocks
}

// Modifier helper: Applies specific gameplay buffs depending on the member.
void applyZoneModifier(int mIdx, int &bonus) {
    if(mIdx == 0) cout << "[BONUS] Sarah's focus: +1 Accuracy!" << endl;
    else if(mIdx == 1) { cout << "[BONUS] Maha's luck: +1 Point!" << endl; bonus++; }
}

// =========================================================
// 🚀 MAIN GAME ENGINE
// =========================================================

int main() {
    // Start the clock! This ensures the random numbers aren't the same every run.
    srand(static_cast<unsigned int>(time(0)));

    // Initialize core game stats: lives, current win streak, and shop points.
    int lives = 3, streak = 0, bonusPoints = 0, arch;
    int stats[8] = {0,0,0,0,0,0,0,0}; // Tracks how many questions you got right per person.
    bool usedAbility = false;          // Tracks if the one-time Archetype skill was fired.

    // 1. CHOOSE YOUR CHARACTER TYPE
    cout << "--- CHOOSE ARCHETYPE ---\n1. Hacker (Reveal Liar)\n2. Diplomat (Skip Error)\n3. Athlete (+1 Life)\nChoice: ";
    cin >> arch; 
    if(arch == 3) lives++; // Athletes start with a safety net of 4 lives.

    // 2. THE GAME LOOP (The "Simulation")
    while (lives > 0) {
        // Shop Check: Trade 2 bonus points for an extra life if things get dicey.
        if (bonusPoints >= 2) {
            cout << "\n[SHOP] Buy life for 2pts? (y/n): ";
            char choice; cin >> choice;
            if (choice == 'y') { bonusPoints -= 2; lives++; }
        }

        // Random Selection: Pick a person, pick their question, and flip a coin (Truth vs Lie).
        int mIdx = rand() % 8;
        int qIdx = rand() % 5;
        int role = rand() % 2; 

        printZoneArt(mIdx); // Display the person's name and art.
        applyZoneModifier(mIdx, bonusPoints); // Apply any special buffs.

        // HACKER SKILL: If you're a hacker, it reveals the liar's intent once.
        if(arch == 1 && !usedAbility) {
            cout << "[HACKER] Sentinel is " << (role ? "A LIAR" : "TRUTHFUL") << endl;
            usedAbility = true; 
        }

        // 3. THE INTERROGATION
        cout << "QUESTION: " << questions[mIdx][qIdx] << endl;
        // Output either the true answer or the lie based on the 'role' coin flip.
        cout << "SENTINEL: " << (role == 0 ? trueAnswers[mIdx][qIdx] : wrongAnswers[mIdx][qIdx]) << endl;
        cout << "Truth? (yes/no): ";
        string guess; cin >> guess;

        // 4. JUDGMENT LOGIC
        // If (Guess 'yes' AND Truth) OR (Guess 'no' AND Lie), you win the round!
        if ((guess == "yes" && role == 0) || (guess == "no" && role == 1)) {
            streak++;        // Increment the win streak.
            stats[mIdx]++;   // Track the win for the Final Report.
            cout << ">>> CORRECT! Streak: " << streak << endl;
        } else {
            // DIPLOMAT SKILL: If you fail, the Diplomat can cancel the penalty once.
            if(arch == 2 && !usedAbility) {
                cout << "[DIPLOMAT] Ability used to bypass failure!" << endl;
                usedAbility = true;
            } else {
                // REDEMPTION ROUND: If you're wrong, you must answer a Professor question to stay alive.
                cout << "\n>>> WRONG! Professor Challenge!" << endl;
                int pIdx = rand() % 3;
                cout << profQuestions[pIdx] << " Answer: ";
                string pAns; cin >> pAns;
                
                if (pAns == profAnswers[pIdx]) { 
                    cout << "Professor is satisfied. +1 Point." << endl;
                    bonusPoints++; 
                    streak = 0; // Streak resets even if you survive the Professor.
                } else { 
                    cout << "Professor is disappointed. -1 Life." << endl;
                    lives--; 
                    streak = 0; 
                }
            }
        }
        
        // WIN CONDITION: If you get a 3-win streak, you win the whole game!
        if (streak >= 3) {
            cout << "\n🔥 STREAK ACHIEVED! WINNER! 🔥" << endl;
            break;
        }
    }

    // 5. THE FINAL REPORT (Debriefing)
    cout << "\n--- FINAL REPORT ---" << endl;
    for(int i=0; i<8; i++) {
        // Shows exactly how well you know each teammate.
        cout << members[i] << ": " << stats[i] << " correct answers." << endl;
    }
    
    // Check if the loop ended because of a win (lives > 0) or a game over.
    if (lives > 0) cout << "\n🎉 YOU ESCAPED THE SIMULATION! 🎉" << endl;
    else cout << "\n💀 GAME OVER. YOU RAN OUT OF LIVES. 💀" << endl;

    return 0; // Standard C++ successful program exit.
}