#include fstream

fstream outfile("table.txt", ios::out);
// create out file tablet.txt

int main()
{
    const int ROWS = 5;
    const int COLS = 3;

    for (int row=0; row<ROW; ro++)
    {
        for (int col; col<ROLS; col++)
        {
            outfile << setw(8) << nums[row][col];
        }
        outFile << endl;
    }
outFile.close();

}
// -------------------------------------------------
void showContents(fstream &file)
{
    string line;
    while (file >> line)
    {
        cout << line << endl;
    }
}
// -------------------------------------------------
// This program demonstrates reading from one file and writing
// to a second file.
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>	// Needed for the toupper function.
using namespace std;

int main()
{
   string fileName;		// To hold the file name
   char ch;				// To hold a character
   ifstream inFile;		// Input file
   
   // Open a file for output.
   ofstream outFile("out.txt");

   // Get the input file name.
   cout << "Enter a file name: ";
   cin >> fileName;
   
   // Open the file for input.
   inFile.open(fileName);
   
   // If the input file opened successfully, continue.
   if (inFile)
   {
       // Read a char from file 1.
       inFile.get(ch);
       
       // While the last read operation was
       // successful, continue.
       while (inFile)
       {
          // Write uppercase char to file 2.
          outFile.put(toupper(ch));
          // Read another char from file 1. 
          inFile.get(ch);
       }
       string input;
       outFile.close();
      fstream outFile("out.txt", ios::in);//open file to print on screen
       while (outFile)  
       {
         getline(outFile, input);
          // Display the last item read.
          cout << input << endl;
          
          // Read an item using $ as a delimiter.
       }
       // Close the two files.
       inFile.close();
       cout << "File conversion done.\n";
   }
   else
      cout << "Cannot open " << fileName << endl;
   return 0;
}
