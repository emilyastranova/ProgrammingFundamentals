#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

string space() // I got tired of typing three tabs
{
    return "\t\t\t";
}
string space(int x) // Specified amount of tabs (e.g. space(4))
{
    string tab = "";

    for (int i = 0; i < x; i++)
        tab = tab + "\t";

    return tab;
}

int ball1 = 0;
int ball2 = 0;
int scores1[] = {0,0,0,0,0,0,0,0,0,0,-1,-1}; // Last 2 xtra
int scores2[] = {0,0,0,0,0,0,0,0,0,0};
int scoresTotal[] = {0,0,0,0,0,0,0,0,0,0};
int scoreTotal = 0;
bool isStrike = false;

bool checkValidScore(int x, int y)
{
    return (x+y)<=10;
}

bool isSpare(int x, int y)
{
    return (x+y)==10;
}

void getUserScores(int f)
{
    cout << space() << "Frame - " << f+1 << endl;
    // Reset ball scores
        ball1 = 0;
        ball2 = 0;
        scoreTotal = 0;
    // Get input on ball 1
        cout << space(4) << "Ball - 1 : ";
        cin >> ball1;

        if(ball1 > 10)
        {
            do
            {
                cout << space() << space() << "Illegal score, do one more time..." << endl;
                cout << space(4) << "Ball - 1 : ";
                cin >> ball1;
            } while (ball1 > 10);
            
        }

        if(ball1 == 10)
        {
            cout << space() << space() << "Congratulation! It is STRIKE..." << endl;
            isStrike = true;
        }
        else
            isStrike = false;

        cout << endl;
        // If ball 1 not equal 10 or last round, get ball 2
        if(ball1 != 10 || (f==9 && ball1 !=10))
        {
            cout << space(4) << "Ball - 2 : ";
            cin >> ball2;
            
        if (isSpare(ball1, ball2) && !isStrike)
        {
            cout << space() << space() << "Not bad, it is SPARE..." << endl;
        }
            cout << endl;
        }
        else
            ball2 = 0;
}

int main()
{

    char more;
    do // Input loop, ends when user says N
    {
        // Frame loop, runs 10 times
        for(int f = 0; f < 10; f++){    

        // Get score from user
            getUserScores(f);

        // Check if scores are valid
            if(!checkValidScore(ball1, ball2))
            {
                do
                {
                    cout << space() << space() << "Illegal score, do one more time..." << endl;
                    cout << space(4) << "Ball - 2 : ";
                    cin >> ball2;
                    if (isSpare(ball1, ball2) && !isStrike)
                    {
                        cout << space() << space() << "Not bad, it is SPARE..." << endl;
                    }
                    cout << endl;
                } while (!checkValidScore(ball1, ball2));
                
            }
        // Store ball scores
            scores1[f] = ball1;
            scores2[f] = ball2;
        }

        // Tally up score
        
        for(int i = 0; i < 10; i++)
        {
            // If open lane
            if(scores1[i] + scores2[i] < 10)
            {
                scoreTotal += scores1[i]+scores2[i];
            }
            // If spare
            if(scores1[i] + scores2[i] == 10 && scores1[i] != 10)
            {
                scoreTotal += 10 + scores1[i+1];
            }

            // If strike
            if(scores1[i] == 10 && scores1[i+1] != 10)
            {
                scoreTotal += 10 + scores1[i+1] + scores2[i+1];
            }
            if(scores1[i] == 10 && scores1[i+1] == 10)
            {
                scoreTotal += 10 + scores1[i+1] + scores1[i+2];
            }

            scoresTotal[i] = scoreTotal;

        }

        // Bowl extra ball if last frame was a spare
            cout << space() << "Extra - 1: ";
            cin >> ball1;
            if (ball1 > 10){
                do
                {
                    cout << space() << space() << "Illegal score, do one more time..." << endl;
                    cout << space() << "Extra - 1: ";
                    cin >> ball1;
                } while (ball1>10);
            }
            scores1[10] = ball1;
                

        // Display score
        cout << "\t   Frame - ";
        for(int i = 0; i < 12; i++)
        {
            if(i < 10)
                cout << right << setw(3) << fixed << i+1 << " ";
            if(i==10)
                cout << right << setw(3) << fixed << " Xtr-1" << " ";
            if(i==11)
                cout << right << setw(3) << fixed << "Xtr-2" << " ";
        }
        cout << endl;
        cout << "\tBall - 1 : "; 
        for(int i = 0; i < 12; i++)
            {
                cout << right << setw(3) << fixed << scores1[i] << " ";
            }

        cout << endl;
        cout << "\tBall - 2 : ";
        for(int i = 0; i < 10; i++)
        {
            cout << right << setw(3) << fixed << scores2[i] << " ";
        }
        cout << endl;
        cout << "\t   Score : ";
        for(int i = 0; i < 10; i++)
        {
            cout << right << setw(3) << fixed << scoresTotal[i] << " ";
        }
        

        cout << "\n\t\t\t\tDo more (Y/N)? ";
        cin >> more;
    } while (more == 'y' || more == 'Y');
}