#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

const int NUM_SENTINELS = 8;
const int QUESTIONS_EACH = 2;
const int TOTAL_Q = NUM_SENTINELS * QUESTIONS_EACH;
const int MAX_LIVES = 3;
const int WIN_STREAK = 3;

string questionText[TOTAL_Q] = {
    "What year did Maha graduate high school?",
    "What city is Wayne State University located in?",

    "What class does prof hadi teach besides c++?",
    "when did professor Hadi graduate with his masters degree?",

    "What car does Professor Hadi drive?",
    "what programming language is taught in csc 2200?",

    "how many credits is a typical CS major?",
    "What does CPU stand for?",

    "WHat does RAM stand for?",
    "which language is known as the mother of all languages?",

    "what is the base of the inary number system?",
    "what does OOP stand for?",

    "how many bits in one byte?",
    "what symbol is used for single line comments in c++?",

    "what keyword is used to define a class in C++?",
    "what function is the entry point of every c++ program?"
};

string truthAnswer[TOTAL_Q] = {
    "2020", "Detroit", 
    "Data Structures", "2019",
    "Toyota", "C++",
    "3", "Central Processing Unit",
    "Random Access Memory", "C",
    "2", "Object Oriented Programming",
    "8", "//",
    "class", "main"
};

string lieAnswer[TOTAL_Q]= {
    "2014", "Ann Arbor",
    "python", "2014",
    "ford", "Java",
    "5", "Core processing unit ",
    "Rapid Access Memory", "Assesmbly",
    "10", "ordered Object Processing",
    "16", "#",
    "struct", "start"
};


bool sentinelIsTruthful[NUM_SENTINELS];
int sentinelOf[TOTAL_Q];

int lives;
int streak;
int totalAsked;
int bestStreak;


void printDivider(){
    cout << "===================================================================" << endl;
}

void printWelcome(){
    cout << "TRUTH OR LIE LABYRINTH GAME" << endl;
    cout << "===================================================================" << endl;
    cout << endl;
    cout << "HOW TO PLAY: " << endl;
    cout << "- There are 8 sentinels guiding paths." << endl;
    cout << "- Each sentinel is secretly TRUTHFUL or a LIAR." << endl;
    cout << "- Pick a sentinel and they will answer a question." << endl;
    cout << "- You decide: Are they telling the truth?" << endl;
    cout << "WIN : 3 detections IN A ROW";
    cout << "LIVES: You have 3 lives. Wrong = Lose a life." << endl;
    cout << "===================================================================" << endl;
    cout << endl;
};

void printStatus(){
    cout << endl;
    printDivider();
    cout << "Lives: " << lives << "/" << MAX_LIVES << endl;
    cout << "Streak: " << streak << "/" << WIN_STREAK << endl;
    cout << "Questions remaining: " << (TOTAL_Q - totalAsked) << endl;
    printDivider();
    cout << endl;
};

void printStatus(bool won){
    cout << endl;
    cout << "==================================================================="<< endl;
    if (won){
        cout << "YOU WIN! 3 correct detections in a row!" << endl;
        cout << "GAME OVER - no lives remaining teehee" << endl;
        cout << "================================================================";
        cout << "Total Questions Asked: " << totalAsked << endl; //use iomanip library
        cout << "Best streak reached : " << bestStreak << endl; //use iomanip library
        cout << "Lives Remaining: " << lives << endl;
        cout << "================================================================" << endl;

        } 
}

void printStatus(bool won, string message){
    printStatus(won);
    cout << " Note:" << message << endl;
    cout << "=============================" << endl;

}

void randomizeRoles(){
    for (int i = 0; i < NUM_SENTINELS; i++){
        if (rand() % 2 == 0){
            sentinelIsTruthful[i] = true;
        } else {
            sentinelIsTruthful[i] = false;
        }
    }
}

void initGame(){

    for(int i = 0; i < TOTAL_Q; i++){
        sentinelOf[i] = i / 2;
    }

    randomizeRoles();

    lives = MAX_LIVES;
    streak = 0;
    totalAsked = 0;
    bestStreak = 0;
}

int pickQuestion(int sentinelIndex){
    vector<int>available;
    for (int i = 0; i < TOTAL_Q; i++){
        if(sentinelOf[i] == sentinelIndex){
            available.push_back(i);
        }
    }

    int pick = rand() % available.size();
    return available[pick];
}

int getValidSentinelChoice(){
    int choice = 0;
    bool valid = false;

    while(!valid){
        cout << "Choose a sentinel to question (1-" << NUM_SENTINELS << "):";

        if (cin >> choice){
            if (choice >= 1 && choice <= NUM_SENTINELS){
                valid = true;
            }
            else{
                cout << "Out of bounds! Enter a number between 1 and " << NUM_SENTINELS << "." << endl;
            }
        } else{
            cout << "Invalid input! Please enter a whole number." << endl;

            cin.clear();
        }
    }

    return choice - 1;
}

bool getYesNo(){
    string input = "";
    bool valid = false;
    bool answer = false;

    while (!valid){
        cout << "Do you think the sentinel is telling the truth? (Yes/No): ";
        cin >> input;

        // make sure to enter everything in lower case;

        if (input == "yes" || input == "y"){
            answer = true;
            valid = true;
        }
        else if(input == "no" || input == "n"){
            answer = false;
            valid = true;
        }
        else{
            cout << "Invalid input! Please type Yes or No" << endl;
        }
    }

    return answer;
}

int runOneTurn(int sentinelIndex){
    int qIndex = pickQuestion(sentinelIndex);
    totalAsked++;

    string response = "";

    cout << endl;
    cout << "You asked the sentinel" << (sentinelIndex +1) << ": " << questionText[qIndex] << endl;

    if(sentinelIsTruthful[sentinelIndex]){
        response = truthAnswer[qIndex];
    } else{
        response = lieAnswer[qIndex];
    }

    cout << "The sentinel responds: " << response << endl;
    cout << endl;

    bool playerSaysTruth = getYesNo();

    if(playerSaysTruth == sentinelIsTruthful[sentinelIndex]){
        return 1;
    } else {
        return 0;
    }
}


int main(){
    srand(time(0));
    printWelcome();
    initGame();

    bool gameOver = false;

    while (!gameOver){
        printStatus();

        int sentinelIndex = getValidSentinelChoice();

        int result = runOneTurn(sentinelIndex);
        switch(result){
            case 1:
            if (streak > bestStreak){
                bestStreak = streak;
            }
            cout << "You detected correctly" << endl;
            cout << "Streak: " << streak << "/" << WIN_STREAK << endl;

            if(streak == WIN_STREAK){
                printStatus(true);
                gameOver = true;
            }

            break;

            case 0:
            cout << "Wrong detection! You lose a life" << endl;
            lives--;
            streak = 0;

            randomizeRoles();

            cout << " Sentinel roles have been reshuffled! " << endl;
            if(lives == 0){
                printStatus(false);
                gameOver = true;
            }

            break;

        }
    }

    return 0;
}




