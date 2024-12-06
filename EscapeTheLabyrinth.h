#include <utility>
#include <random>
#include <set>
#include "grid.h"
#include "maze.h"
using namespace std;

/* Change constant kYourNetID to store your netID 
 *    - your submission will be manually inspected to ensure
 *      you have used the exact string that is your netID
 *    - thus, it is vital you understand what your netID is
 *    - ex: Professor Reckinger's email is scotreck@uic.edu, so
 *          Professor Reckinger's netID is scotreck     
 *    - ex: Professor Kidane's email is ekidan2@uic.edu, so
 *          Professor Kidane's netID is ekidan2     
 *    - ex: Student Sparky's email is sspark211@uic.edu, so
 *          Student Sparky's netID is sspark211 
 * WARNING: Once you've set set this constant and started 
 * exploring your maze, do NOT edit the value of kYourNetID. 
 * Changing kYourNetID will change which maze you get back, 
 * which might invalidate all your hard work!
 */
const string kYourNetID = "dbudz2";

/* Change these constants to contain the paths out of your mazes. */
const string kPathOutOfRegularMaze = "ESSSWENNNEESNWSSES";
const string kPathOutOfTwistyMaze = "NSWWEEWNSS";

bool isPathToFreedom(MazeCell *start, const string& moves) {
    //initialize item states as false first
    bool potion = false;
    bool spellbook = false;
    bool wand = false;
    
    //check if starting location has items just in case
    if(start->whatsHere == "Potion"){
        potion = true;
    }
    if(start->whatsHere == "Spellbook"){
        spellbook = true;
    }
    if(start->whatsHere == "Wand"){
        wand = true;
    }

    //loop through moves
    for(int i = 0; i < moves.length(); i++){
        // each direction (N,S,E,W) are checked and then moved. if null, exit
        if(moves[i] == 'N'){
            if(start->north == nullptr){
                return false;
            }
            start = start->north;
            
        }else if(moves[i] == 'E'){
            if(start->east == nullptr){
                return false;
            }
            start = start->east;

        }else if(moves[i] == 'S'){
            if(start->south == nullptr){
                return false;
            }
            start = start->south;

        }else if(moves[i] == 'W'){
            if(start->west == nullptr){
                return false;
            }
            start = start->west;
        }else{
            return false;
        }
        //check whats at the specific location after moving
        if(start->whatsHere == "Potion"){
            potion = true;
        }
        if(start->whatsHere == "Spellbook"){
            spellbook = true;
        }
        if(start->whatsHere == "Wand"){
            wand = true;
        }
    }
    //once done looping, check if all items are found. if so return true, if not return false
    if(potion == true && spellbook == true && wand == true){
        return true;
    }else{
        return false;
    }
}
