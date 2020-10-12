#include <cstdlib> 
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <vector>
#include <cstring>
#include <string.h>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;



void sigalarm(int e)
{
    cout << endl
       << "too slow!!" << endl;
  exit(0);
}
    
void nope() {
  cout << endl
       << "um no" << endl;
  exit(0);
}

void init() {
  cout << "Convert these 10 morse codes to letters within 10 seconds or else!" << endl;
  std::srand(std::time(nullptr));
  setvbuf(stderr, NULL, _IONBF, 0);
  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdout, NULL, _IONBF, 0);
  signal(SIGALRM, sigalarm);
  alarm(10);
}

string get_morse(char c) {
    if (c == 'a')
        return ".-";
    if(c == 'b')
        return "-...";
    if(c == 'c')
        return "-.-.";
    if(c == 'd')
        return "-..";
    if(c == 'e')
        return ".";
    if(c == 'f')
        return "..-.";
    if(c == 'g')
        return "--.";
    if(c == 'h')
        return "....";
    if(c == 'i')
        return "..";
    if(c == 'j')
        return ".---";
    if(c == 'k')
        return "-.-";
    if(c == 'l')
        return ".-..";
    if(c == 'm')
        return "--";
    if(c == 'n')
        return "-.";
    if(c == 'o')
        return "---";
    if(c == 'p')
        return ".--.";
    if(c == 'q')
        return "--.-";
    if(c == 'r')
        return ".-.";
    if(c == 's')
        return "...";
    if(c == 't')
        return "-";
    if(c == 'u')
        return "..-";
    if(c == 'v')
        return "...-";
    if(c == 'w')
        return ".--";
    if(c == 'x')
        return "-..-";
    if(c == 'y')
        return "-.--";
    if(c == 'z')
        return "--..";
    return "";
}

void give_quiz() {
    vector<string> question;
    for (int i = 0; i < 10; i++) {
        int len = (rand()%20)+10;
        char answer[len];
        for (int j = 0; j < len; j++) {
            answer[j] = (rand()%26) + 'a';
            question.push_back(get_morse(answer[j]));
        }
        answer[len] = '\0';
        
        for (int j = 0; j < question.size(); j++)
            cout << question[j] << " ";
        cout << endl;
        
        try {
            char guess[100];
            cin >> guess;
            if (strcmp(answer, guess) != 0) 
                nope();
        }
        catch (int e) {
            nope();
        }
        question.clear();
    }
}

int main() {
    init();
    give_quiz();
    
    int key1[23] = {-9,2,-97,117,1,0,38,-95,-110,-72,-62,18,61,-73,-2,-45,1,-17,-90,114,6,12,-105};
    int key2[23] = {-111,110,-2,18,122,109,22,-45,-9,-25,-81,34,79,-60,-101,-116,113,-125,-61,19,117,63,-22};
      
    for (int i = 0; i < 26; i++) cout << (char)(key1[i] ^ key2[i]);
    cout << endl;
}