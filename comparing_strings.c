#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> // To include the string functions
#include <ctype.h> // To include MORE string functions

// Declaring the functions:
int calcLengthStrSimplified(char charArray[]); // This function will be necessary for our comparingStrings function.
bool comparingStrings(char array1[], char array2[]);


int main(void){
    // A series of char array variables that can be used to test the comparingArrays() function:
    char charArray1[] = "I love Baldur's Gate";
    char charArray2[] = "Neverwinter Nights is great";
    char charArray3[] = "I love Baldur's Gate";
    char charArray4[] = "I loves Baldur's Gates";
    char charArray5[] = "I lovei Baldur's Gates";
    char charArray6[] = "I love Baldur's Gati";

    printf("%d\n", comparingStrings(charArray1, charArray6));

    return 0;
};

//// Implementing the functions ////

int calcLengthStrSimplified(char charArray[])
{
    int i;
    int lengthStringChall1;
    int answer;

    for (i = 0; charArray[i] != '\0'; i++)
    {
        lengthStringChall1 = i + 1;
    };

    return lengthStringChall1;
};


bool comparingStrings(char array1[], char array2[])
{
    /*
    This function compares two strings in terms of their individual elements (chars) and their lengths.
    In case their lengths are different, the user will still be allowed to compare their individual elements,
    unless the iteration hits an element that differs; in the latter case, the program will terminate, and in either
    case the function will return false. If, however, the lengths are the same, then the program will start comparing
    the individual elements; it returns true if all the elements are equal, and false otherwise.

    Parameter variable(s):
        array1[] -> char
        array2[] -> char

    Return variable(s):
        arraysAreEqual -> bool
    */

    _Bool arraysAreEqual; // Will be returned if the arrays are equal or different.
    int indexArray; // So we can iterate through the arrays.
    int answer; // If the user wants to check whether or not the arrays have common elements despite the difference
    // in length.

    // Calculating the length of each array.
    int lengthArray1 = calcLengthStrSimplified(array1);
    int lengthArray2 = calcLengthStrSimplified(array2);

    printf("The length of the first array is %d\n", lengthArray1);
    printf("The length of the second array is %d\n", lengthArray2);

    // If the lengths are different, the string arrays are, obviously, different a priori. However, the user will still
    // have the option to compare the chars in the strings until the program hits a char that differs, in which case it
    // will return false and terminate.
    if (lengthArray1 != lengthArray2)
    {
        VALIDANSWER:
        printf("Arrays are not equal, but may have some elements in common in their respective index positions."
        " Would you like to check for elements in common? Press 0 for 'No' or 1 for 'Yes'\n");
        scanf("%d", &answer);
        if (answer == 0)
        {
            arraysAreEqual = false;
            return arraysAreEqual;
        } else if (answer == 1)
        {
            goto CHECKELEMENTS;
        } else
        {
            printf("Please type in a valid answer.\n");
            goto VALIDANSWER;
        };
    }else
    {
        for (indexArray = 0; array1[indexArray] != '\0' && array2[indexArray] != '\0'; indexArray++)
        {
            if (array1[indexArray] == array2[indexArray] && (lengthArray1 == lengthArray2))
            {
                printf("%c ::: %c\n", array1[indexArray], array2[indexArray]);
            } else if (array1[0] != array2[0])
            {
                printf("The first element in both arrays are not equal to each other. The program will now terminate.");
                arraysAreEqual = false;
                return arraysAreEqual;
            } else
            {
                printf("%c ::: %c\n", array1[indexArray], array2[indexArray]);
                if (array1[indexArray] != array2[indexArray])
                {
                    printf("Arrays have some elements in common, but are not equal.\n");
                    arraysAreEqual = false;
                    return arraysAreEqual;
                };
            };
        }; // End of the first for loop

        printf("These arrays are indeed equal.\n");
        arraysAreEqual = true;
        return arraysAreEqual;
    };

    // Checking possible common elements despite the difference in length. If the program encounters an element
    // that differs, it terminates:
    CHECKELEMENTS:
    for (indexArray = 0; array1[indexArray] != '\0' || array2[indexArray] != '\0'; indexArray++)
    // We need to put an || (or) here because since we already know these arrays have different lengths, we want
    // to also print out the elements that will be in the index position of one that will not be in the index position
    // of the other, since they may be equal to each other in all of their elements, until we hit the character that
    // will be in the index position inexistent in the other.
    {
        if (lengthArray1 != lengthArray2)
        {
            printf("%c ::: %c\n", array1[indexArray], array2[indexArray]);
            //if (array1[indexArray] != array2[indexArray])
            if (array1[0] != array2[0])
            {
                printf("The first element in both arrays are not equal to each other. The program will now terminate.");
                arraysAreEqual = false;
                return arraysAreEqual;
            }
            else if (array1[indexArray] != array2[indexArray])
            {
                printf("Arrays have some elements in common, but are not equal.\n");
                arraysAreEqual = false;
                return arraysAreEqual;
            };
        };
    }; // End of the second for loop.

}; //End of the function
