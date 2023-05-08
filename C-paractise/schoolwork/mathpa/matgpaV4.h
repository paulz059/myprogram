#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <functional>
#include <sstream>
#include <windows.h>
using namespace std;

    string qusention[10] ;
    int difficulty;
    int score = 0;
    int ans[10];
    const int NUM_QUESTIONS = 10;
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);