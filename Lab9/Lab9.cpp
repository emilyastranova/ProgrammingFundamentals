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
                                                                            // To unit test with your own list:
int scores[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  // <-- Comment
//int scores[] = {1,0,1,9,10,0,9,0,9,1,4,4,4,4,4,2,1,5,9,1,9,0};                    // <-- Uncomment
int scoresTotal[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int scoreTotal = 0;

bool isSpare(int x, int y)
{
    return (x + y) == 10 && x != 10 && y != 10;
}

bool isStrike(int x, int y)
{
    return x == 10 || y == 10;
}

bool isOpenFrame(int x, int y)
{
    return (x + y) < 10;
}

void tallyScores()
{
    int f = 0;
    for (int i = 0; i < 20; i += 2)
    {
        if (isOpenFrame(scores[i], scores[i + 1]))
        {
            scoreTotal += (scores[i] + scores[i + 1]);
            scoresTotal[f] = scoreTotal;
        }
        if (isSpare(scores[i], scores[i + 1]))
        {
            scoreTotal += (scores[i] + scores[i + 1] + scores[i + 2]);
            scoresTotal[f] = scoreTotal;
        }
        if (isStrike(scores[i], scores[i + 1]))
        {
            scoreTotal += (scores[i] + scores[i + 1] + scores[i + 2] + scores[i + 3]);
            scoresTotal[f] = scoreTotal;
        }
        f++;
    }
}

void displayScore()
{
    cout << "\t   Frame - ";
    for (int i = 0; i < 12; i++)
    {
        if (i < 10)
            cout << right << setw(3) << fixed << i + 1 << " ";
        if (i == 10)
            cout << right << setw(3) << fixed << " Xtr-1"
                 << " ";
        if (i == 11)
            cout << right << setw(3) << fixed << "Xtr-2"
                 << " ";
    }
    cout << endl;
    cout << "\tBall - 1 : ";
    for (int i = 0; i < 24; i += 2)
    {
        cout << right << setw(3) << fixed << scores[i] << " ";
    }

    cout << endl;
    cout << "\tBall - 2 : ";
    for (int i = 1; i < 20; i += 2)
    {
        cout << right << setw(3) << fixed << scores[i] << " ";
    }
    cout << endl;
    cout << "\t   Score : ";
    for (int i = 0; i < 10; i++)
    {
        cout << right << setw(3) << fixed << scoresTotal[i] << " ";
    }
}

void clearScores()
{
    scoreTotal = 0;
    for (int i = 0; i < 22; i++)
        scores[i] = 0;
    for (int i = 0; i < 10; i++)
        scoresTotal[i] = 0;
}

bool checkValidScore(int x, int y)
{
    if (x > 10 || y > 10 || x + y > 10)
        return false;
    else
        return true;
}

void getUserScores()
{
    int ball1 = 0;
    int ball2 = 0;
    int frame = 1;

    for (int i = 0; i < 20; i += 2)
    { 
        cout << space() << "Frame - " << frame << endl;
        frame++;
        cout << space(4) << "Ball - 1 : ";
        cin >> ball1;
        cout << endl;

        if(ball1 > 10)
        {
            do
            {
                cout << space() << space() << "Illegal score, do one more time..." << endl;
                cout << space(4) << "Ball - 1 : ";
                cin >> ball1;
                cout << endl;
            } while (ball1 > 10);
            
        }

        if(ball1 != 10)
        {
            cout << space(4) << "Ball - 2 : ";
            cin >> ball2;
            cout << endl;

            if(ball2 > 10)
            {
                do
                {
                    cout << space() << space() << "Illegal score, do one more time..." << endl;
                    cout << space(4) << "Ball - 2 : ";
                    cin >> ball2;
                    cout << endl;
                } while (ball2 > 10);
                
            }
        }
        else
        {
            ball2 = 0;
            cout << space() << space() << "Congratulation! It is STRIKE..." << endl;
        }

        if (checkValidScore(ball1, ball2))
        {
            scores[i] = ball1;
            scores[i + 1] = ball2;
        }
        else
        {
            do
            {
                cout << space() << space() << "Illegal score, do one more time..." << endl;
                cout << space(4) << "Ball - 2 : ";
                cin >> ball2;
                cout << endl;
            } while (!checkValidScore(ball1, ball2));
            
        }
        if(isSpare(ball1, ball2))
            cout << space() << space() << "Not bad, it is SPARE..." << endl;
        if(!isStrike(ball1, ball2) && !isSpare(ball1, ball2))
            cout << space() << space() << "Need work harder, Dude!" << endl;
    }
}

void extraBallCheck()
{
    int extra1 = 0;
    int extra2 = 0;
    if(isSpare(scores[18], scores[19])) // One extra ball
    {
        cout << "Extra ball 1: ";
        cin >> extra1;
        cout << endl;

        if(extra1 > 10)
        {
            do
            {
                cout << space() << space() << "Illegal score, do one more time..." << endl;
                cout << "Extra ball 1: ";
                cin >> extra1;
                cout << endl;
            } while (extra1 > 10);
            
        }
    }

    if(isStrike(scores[18], scores[19])) // Two extra balls
    {
        cout << "Extra ball 1: ";
        cin >> extra1;
        cout << endl;

        if(extra1 > 10)
        {
            do
            {
                cout << space() << space() << "Illegal score, do one more time..." << endl;
                cout << "Extra ball 1: ";
                cin >> extra1;
                cout << endl;
            } while (extra1 > 10);
            
        }

        cout << "Extra ball 2: ";
        cin >> extra1;
        cout << endl;

        if(extra2 > 10 || checkValidScore(extra1, extra2))
        {
            do
            {
                cout << space() << space() << "Illegal score, do one more time..." << endl;
                cout << "Extra ball 2: ";
                cin >> extra2;
                cout << endl;
            } while (extra2 > 10);
            
        }
    }

    scores[20] = extra1;
    scores[21] = extra2;

}

int main()
{

    char more;
    do // Input loop, ends when user says N
    {
        getUserScores(); // Comment out for unit testing
        extraBallCheck();
        tallyScores();
        displayScore();
        clearScores();  // In case they want to run program again

        cout << "\n\t\t\t\tDo more (Y/N)? ";
        cin >> more;
    } while (more == 'y' || more == 'Y');
}