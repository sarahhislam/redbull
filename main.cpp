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
bool questionUsed[TOTAL_Q];
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
    cout << "NOTE: No question will ever repeat, teehee! GOOD LUCK FELLAS!";
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
    randomizeRoles();
    for (int i = 0; i < TOTAL_Q; i++){
        questionUsed[i] = false;
    }

    lives = MAX_LIVES;
    streak = 0;
    totalAsked = 0;
    bestStreak = 0;
}

int questionsLeftForSentinel(int sentinelIndex){
    int count = 0;
    for(int i = 0; i < TOTAL_Q; i++){
        if
    }
}









void initGame(){
    for (int i = 0; i < TOTAL_Q; i++){
        sentinelOf[i] = i /2 ;
    } // declare the  sentinelOf 
};
