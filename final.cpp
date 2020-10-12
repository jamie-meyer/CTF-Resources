#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::cin;
using std::string;


void nope() {
  cout << endl
       << "uh no, that's wrong" << endl;
  exit(0);
}

void init() {
  cout << "You're gonna have to answer a bunch of questions (or not?)" << endl
       << "I think I should let you know that there are 1000 questions..." << endl
       << "And you need to get all of them right" << endl
       << "Good luck!" << endl;
  std::srand(std::time(nullptr));
  setvbuf(stderr, NULL, _IONBF, 0);
  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdout, NULL, _IONBF, 0);
}


string get_question(int answer) {
    int op = rand()%3;
    if (op == 0) { // addition
        int new_rand = rand()%100000;
        return std::to_string(answer-new_rand) + " + " + std::to_string(new_rand) + "?";
    }
    else if (op == 1) { // subtraction
        int new_rand = rand()%100000;
        return std::to_string(new_rand+answer) + " - " + std::to_string(new_rand) + "?";
    }
    else { // division or mult (unlikely)
        int new_rand = rand()%100;

        if ((answer % new_rand) == 0) {
            return std::to_string((int)(answer/new_rand)) + " * " + std::to_string(new_rand) + "?";
        }

        return std::to_string(new_rand*answer) + " / " + std::to_string(new_rand) + "?";
    }
}

void give_quiz() {
    string question;
    int guess;
    for (int i = 0; i < 1000; i++) {
        int answer = rand()%100000;
        question = get_question(answer);
        cout << question << endl;
        try {
            char g[100];
            cin >> g;
            guess = atoi(g);
        }
        catch (int e) {
            nope();
        }

        if (guess != answer) {
            nope();
        }

    }
}

int main() {
    init();
    give_quiz();

    int key1[26] = {83,118,-49,100,-124,69,17,9,0,13,-7,92,-84,90,63,-106,74,91,96,82,126,-71,97,-63,-53,-6};
    int key2[26] = {53,26,-82,3,-1,60,126,124,114,104,-90,61,-13,55,94,-30,34,4,7,55,16,-48,20,-78,-74,-6};

    for (int i = 0; i < 26; i++) cout << (char)(key1[i] ^ key2[i]);
    cout << endl;
}
