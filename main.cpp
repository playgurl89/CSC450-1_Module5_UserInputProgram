/*
 * main.cpp
 *
 *  Created on: Nov 22, 2026
 *      Author: samanthawidell
 */


#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// Function to reverse all characters in a file
void reverseFile(const string& inputFile, const string& outputFile)
{
    ifstream inFile(inputFile);
    string fileContents;

    // Read the entire file into a string
    if (inFile.is_open())
    {
        char character;

        while (inFile.get(character))
        {
            fileContents += character;
        }

        inFile.close();
    }
    else
    {
        cout << "Error opening input file for reversal." << endl;
        return;
    }

    // Reverse all characters in the string
    reverse(fileContents.begin(), fileContents.end());

    // Write reversed content to a new file
    ofstream outFile(outputFile);

    if (outFile.is_open())
    {
        outFile << fileContents;
        outFile.close();

        cout << "Reversed file created successfully: "
             << outputFile << endl;
    }
    else
    {
        cout << "Error creating reversed output file." << endl;
    }
}

int main()
{
    string userInput;

    // File names
    string inputFile = "CSC450_CT5_mod5.txt";
    string outputFile = "CSC450-mod5-reverse.txt";

    cout << "Enter information to append to the text file: ";
    getline(cin, userInput);

    // Append user input to the original file
    ofstream outFile(inputFile, ios::app);

    if (outFile.is_open())
    {
        outFile << endl << userInput << endl;
        outFile.close();

        cout << "Data successfully appended to "
             << inputFile << endl;
    }
    else
    {
        cout << "Error opening file for writing." << endl;
        return 1;
    }

    // Reverse the contents of the original file
    reverseFile(inputFile, outputFile);

    cout << "Program completed successfully." << endl;

    return 0;
}



