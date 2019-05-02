//Time Complexity: Best case: O(n) and for worst case: O(n^2)
//Space Complexity: O(n)
//Programming Assignment
//Submitted to: Dr Juan Gomez
//Submitted by: Priyanshi Jajoo
//Grade ID:37
//STID: 013826618
#include <iostream>
#include <vector>
#include "asteroid.h"
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
