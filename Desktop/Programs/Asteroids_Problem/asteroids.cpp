//Programming Assignment
//Submitted to: Dr Juan Gomez
//Submitted by: Priyanshi Jajoo
#include <iostream>
#include <vector>
//#include "asteroid.h"
using namespace std;

enum direction
{
    left,
    right
};

struct asteroid_t
{
     int m;       // Mass
    direction d; // Direction
};

typedef struct asteroid_t Asteroid;

int countHits(std::vector<Asteroid> a);

int main()
{
    Asteroid A1, A2, A3, A4;
   
    A1.m = 45;
    A1.d = direction::right;

    A2.m = 15;
    A2.d = direction::left;

    A3.m = 20;
    A3.d = direction::right;

    A4.m = 10;
    A4.d = direction::left;

    vector<Asteroid> a;
    a.push_back(A1);
    a.push_back(A2);
    a.push_back(A3);
    a.push_back(A4);
    int count = countHits(a);
    cout <<"Total Number of asteroids hiting space station: "<<count<<"\n";
    return 0;
}

//Time Complexity: Best case: O(n) and for worst case: O(n^2)
//Space Complexity: O(n)
//Programming Assignment
//Submitted to: Dr Juan Gomez
//Submitted by: Priyanshi Jajoo
//Grade ID:37
//STID: 013826618
int countHits(std::vector<Asteroid> a)
{
    // Creating vector for Right direction moving asteroids.
    vector<Asteroid> rightAsteroids;

    for (int i = 0; i < a.size(); i++)
    {
        if(a[i].m==0 || a[i].m<0)
        {
            cerr<<"Mass of asteroid can not be negative or zero\n";
            exit(0);
        }
    
        if (a[i].d == direction::right)
        {
            rightAsteroids.push_back(a[i]);
        }
        else if(a[i].d ==direction::left)
        {
            //Comparing mass of two oppositie side moving asteroids, once both will collide, will move according to their masses.
            if (rightAsteroids.size() != 0)
            {
                for (int j = rightAsteroids.size() - 1; j >= 0; j--)
                {
                   
                    if (rightAsteroids[j].m > a[i].m)
                    {
                      break;
                    }
                    //If mass of right moving and left moving asteroid is equal, both will get vaporised.
                    else if (rightAsteroids[j].m ==a[i].m)
                    {
                        rightAsteroids.pop_back();
                        break;
                    }
                    else
                    {
                        rightAsteroids.pop_back();
                    }
                
                }
            }
        } 
        else {
            cerr<<"No other direction is allowed other then LEFT and RIGHT. Exiting the program.\n";
            exit(0);
        }
    }
    //Returning value of asteroids which are going to hit space station.
    return rightAsteroids.size();
}
