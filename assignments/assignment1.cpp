/*
 * I will first initialize a accumulator and memory double to keep track of the calculations in the main function.
 * This program first finds the length of the text file using the length(ifStream) function and then initializes the
 * array of strings to that length. Each line in the text file represents one additional row in the array. I will then
 * parse through the array using the parse(string) to do the calculations line by line.
 *
 */



/*
 * The statements below are the includes which
 * give me the ability to perform more advanced
 * functions in my program.
 */
#include <iostream>
#include <math.h>
#include <fstream>
#include <string>

/*
 * The statements below allow for to use more basic
 * statements throughtout my code to get the job done.
 */
using std::cout;
using std::cin;
using namespace std;

/*
    * This following segment is meant to tell me how long my
    * string array must be to contain the entire text file.
    */
int lengthtext(ifstream a)
{
    int x=0;
    string placeholder;
    if (a.is_open())
    {
        while (getline(a, placeholder))
        {
            x++;
            cout<<placeholder<<"/n";
        }
        a.close();
    }
    return x;
}

/*
 * This will only deal with the functions that are simple computations as decided
 * by me. This entails only the +,-,*, and / processes as they are easy to perform
 * outside of the main in a function.
 */
double parse(string currentcalc, double currentVal)
{
    int charactercount=0;
    double linevalue=0.0;
    char assignement='';
    string number=" ";

    /*
     * Need to break up into the appliable commands and the value.
     */
        number=currentcalc.
        .c_str();

        /*
         * After we parse through the string being passed in we need to perform the
         * specified actions in this next part of the function.
         */
        if(assignement=='+')
        {
            linevalue= currentVal+;
        }
        if(assignement=='-')
        {
            linevalue= currentVal-;
        }
        if(assignement=='*')
        {
            linevalue= currentVal*;
        }
        //First need to see if it division then see if we are dividing by 0.
        if(assignement=="/")
        {
            linevalue= currentVal/;
        }
        return linevalue;
}

/*
 * This is the main function where the work will take place.
 */
int main()
{
    int x=0;
    string currentline;
    ifstream myReadFile;
    myReadFile.open("input.txt");//Opens up the text file allowing me to work with it.
    x=lengthtext(myReadFile);


    string lines[x];//Declaring string array the length of the amount of lines in the text file.


    myReadFile.close();
return 0;// in theory this ends the program
}


