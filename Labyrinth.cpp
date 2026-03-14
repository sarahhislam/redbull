#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;


string questions[3] = {
    "What year did Maha graduate from high school?", 
    "What year did ford get invented?",
    "what year did Maha learn swimming?"

};

string trueAnswers[3] ={
    "2025",
    "2014",
    "she never learned swimming"
};

string wrongAnswers[3] = {
    "2026",
    "2018",
    "2019"
};


int main(){

    const int NUM_SENTINELS = 3;
    const int MAX_LIVES = 3;
    const int WIN_STREAK = 3;

    int lives = MAX_LIVES;
    int consecutiveCorrect = 0;
    int totalQuestions = 0;
    
    cout << "Welcome to the Truth of Lie Labyrinth!\n";
    cout << "TRUTH OR LIE LABYRINTH GAME" << endl;
    cout << "===================================================================" << endl;
    cout << endl;
    cout << "HOW TO PLAY: " << endl;
    cout << "- There are 3 sentinels guiding paths." << endl;
    cout << "- Each sentinel is secretly TRUTHFUL or a LIAR." << endl;
    cout << "- Pick a sentinel and they will answer a question." << endl;
    cout << "- You decide: Are they telling the truth?" << endl;
    cout << "WIN : 3 detections IN A ROW" << endl;
    cout << "LIVES: You have 3 lives. Wrong = Lose a life." << endl;
    cout << "Once you lose a life, the game resets with reshuffled sentinel roles" << endl;
    cout << "And once you lose all 3 lives, you lose the game" << endl;
    cout << "===================================================================" << endl;

    srand(time(0));
    while(lives > 0){
        int sentinelRoles[NUM_SENTINELS] = {};
        for(int i = 0; i < NUM_SENTINELS; i++){
            sentinelRoles[i] = rand() % 2;
        }
    

        int questionIndex = rand() % 3; //change this to 8

        cout << "\nThere are " << NUM_SENTINELS << " sentinels. Choose one(1 -" << NUM_SENTINELS << "):";

        int sentinelChoice = 0;
        bool validInput = false;

        while(!validInput){
            cin >> sentinelChoice;
            if(cin.fail()){
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Numbers only. \n";
                cout << "Enter sentinel choice again: ";
            }
            else if(sentinelChoice <= 0 || sentinelChoice > NUM_SENTINELS){
                cout << "Out of range. Try again.\n";
                cout << "Enter sentinel choice again: " << endl;
            }
            else {
                validInput = true;
            }
        }

        cout << "\nYou ask the sentinel: " << questions[questionIndex] << endl;

        if(sentinelRoles[sentinelChoice - 1] == 0){
            cout << "The sentinel responds: " << trueAnswers[questionIndex] << endl;
        }
        else{
            cout << "The sentinel responds: " << wrongAnswers[questionIndex] << endl;
        }
        string playerGuess = "";
        validInput = false;
        cout << "Do you think the sentinel is telling the truth(yes/no): ";
        while(!validInput){
            cin >> playerGuess;
            if(cin.fail()){
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Enter yes or no only: ";


            }
            else if(playerGuess!="yes" && playerGuess!="no"){
                cout << "Enter only yes or no: ";
            }
            else{
                validInput = true;
            }
        }

        totalQuestions++;

        if((playerGuess== "yes" && sentinelRoles[sentinelChoice-1] == 0) || (playerGuess == "no" && sentinelRoles[sentinelChoice - 1] == 1)){
            consecutiveCorrect++;
            cout << "Correct detection" << endl;
            cout << "Your win streak is: " << consecutiveCorrect << "/3" << endl;
            cout << "Your total lives remaining: " << lives << "/" << MAX_LIVES << endl;

        } else{
            consecutiveCorrect = 0;
            lives--;
            cout << "Wrong detection! Lives remaining: " << lives << endl;
        }

        if (consecutiveCorrect >= WIN_STREAK){
            cout << "Congratulations! YOU WON!!" << endl;
            cout << "The total questions asked: " << totalQuestions << endl;
            cout << "Lives remaining: " << lives << endl;
            cout << "The consecutive answers you got right: " << consecutiveCorrect << endl;
            break;

        }

        if(lives <= 0){
            cout << "You have lost...womp womp womp" << endl;
            cout << "Total Questions asked: " << totalQuestions << endl;
            cout << "Lives lost: " << MAX_LIVES - lives << endl;
        }


    }

    




    return 0;
};


