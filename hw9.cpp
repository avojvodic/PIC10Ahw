//
// Homework 9
// June 9, 2017
//
// Aleksandra Vojvodic
// ID 904578899
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

//establish global variables as constants for matrix size
const int rows = 10;
const int columns = 10;

//fill matrix with random values
void fill_random (int matrix_a [rows][columns], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            matrix_a[i][j] = rand() % 20 - 10; // establishes range of values from -10 to 10
            
        }
    }
}

//print matrix to console
void print_matrix(const int matrix_a[rows][columns], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << setw(5) << matrix_a[i][j] << " ";
        }
        cout << "\n";
    }
}

//add two matrices
void add_matrix(int matrix_a[rows][columns], int matrix_b[rows][columns], int r, int c)
{
    cout << "Sum equals: " << endl;
    
    int matrix_c[rows][columns];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            matrix_c[i][j] = (matrix_a[i][j] + matrix_b[i][j]);
            cout << setw(5) << matrix_c[i][j] << " ";
        }
        cout << endl;
    }
}

//fill matrix with values from file
void fill_from_file(int matrix_a[rows][columns], int r, int c, ifstream &fin)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            fin >> matrix_a[i][j];
            
        }
    }
    
}

//outputs matrices to file
void output_to_file(int matrix_a[rows][columns], int matrix_b[rows][columns], int r, int c, ofstream &fout)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            
            fout << matrix_a[i][j] + matrix_b[i][j] << " ";
        }
        fout << endl;
    }
}

int main()
{
    srand((int)(time(0)));
    
    int r;
    int c;
    
    //keep dimensions under 10 by 10
    bool invalid_rows = true;
    while (invalid_rows)
    {
        cout << "Enter number of rows: ";
        cin >> r;
        if (r > 10)
        {
            invalid_rows = true;
            cout << "Invalid row number. \n";
        }
        else
        {
            invalid_rows = false;
        }
    }
    bool invalid_columns = true;
    while (invalid_columns)
    {
        cout << "Enter number of columns: ";
        cin >> c;
        
        if (c > 10)
        {
            invalid_columns = true;
            cout << "Invalid number of columns. \n";
        }
        else
        {
            invalid_columns = false;
        }
    }
    
    int matrix_a[rows][columns];
    int matrix_b[rows][columns];
    
    string response;
    cout << "Would you like to fill vectors randomly or from a file? \n(enter random or file): ";
    cin >> response;
    
    if (response == "random")
    {
        fill_random(matrix_a, r, c);
        fill_random(matrix_b, r, c);
    }
    else
    {
        //fill matrices from file
        ifstream fin;
        string file_in;
        cout << "Enter file name to read: ";
        cin >> file_in;
        fin.open(file_in.c_str());
        fill_from_file(matrix_a, r, c, fin);
        fill_from_file(matrix_b, r, c, fin);
        fin.close();
    }
    string answer;
    cout << "Would you like to output to a file or to console? \n(enter file or console): ";
    cin >> answer;
    if (answer == "console")
    {
        //add matrices and prints to console
        cout << endl << "Matrix One equals: " << endl;
        print_matrix(matrix_a, r, c);
        
        cout << endl << "Matrix Two equals: " << endl;
        print_matrix(matrix_b, r, c);
        cout << endl;
        
        
        
        add_matrix(matrix_a, matrix_b, r, c);
    }
    else
    {
        //output matrices to file
        ofstream fout;
        string file_out;
        cout << "Enter file name to output to: ";
        cin >> file_out;
        
        fout.open(file_out.c_str());
        
        output_to_file(matrix_a, matrix_b, r, c, fout);
        
        fout.close();
        
    }
    
    return 0;
}
