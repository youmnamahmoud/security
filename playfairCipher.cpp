#include <iostream>
#include <string>

using namespace std;

int main()
{
    string matrix, plaintext, cipher;
    cin >> matrix;
    cin >> plaintext;
    string front, back;
    string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ";

    for (long long i = 0; i < plaintext.length(); i++)
        if (plaintext[i] == 'J')
            plaintext[i] = 'I';
    for (long long i = 0; i < matrix.length(); i++)
        if (matrix[i] == 'J')
            matrix[i] = 'I';

    matrix = matrix + alphabet;
    for (long long i = 0; i < matrix.length(); i++)
    {
        for (long long j = i + 1; j < matrix.length(); j++)
        {
            if (matrix[i] == matrix[j])
            {
                front = matrix.substr(0, j);
                if (j + 1 != matrix.length())
                {
                    back = matrix.substr(j + 1, matrix.length());
                    matrix = front + back;
                    j--;
                }
                else
                {
                    matrix = front;
                    j--;
                }
            }
        }
    }
    string test = "";
    for (long long i = 0; i < plaintext.length(); i += 2)
    {
        if ((i + 1 != plaintext.length()) && (plaintext[i] == plaintext[i + 1]) && plaintext[i] != 'X')
        {
            test = plaintext.substr(0, i + 1) + "X" + plaintext.substr(i + 1, plaintext.length());
            plaintext = test;
        }
        else if ((i + 1 != plaintext.length()) && (plaintext[i] == plaintext[i + 1]) && plaintext[i] == 'X')
        {
            test = plaintext.substr(0, i + 1) + "Q" + plaintext.substr(i + 1, plaintext.length());
            plaintext = test;
        }
    }

    if ((plaintext.length() % 2 != 0) && plaintext[plaintext.length() - 1] == 'X')
        plaintext = plaintext + "Q";
    else if (plaintext.length() % 2 != 0 && plaintext[plaintext.length() - 1] != 'X')
        plaintext = plaintext + 'X';

    int rowi, rowii, coli, colii;
    string ciphertext = "";
    for (long long i = 0; i < plaintext.length(); i += 2)
    {
        rowi = matrix.find(plaintext[i]) / 5;
        rowii = matrix.find(plaintext[i + 1]) / 5;
        coli = matrix.find(plaintext[i]) % 5;
        colii = matrix.find(plaintext[i + 1]) % 5;

        if (rowi == rowii)
        {
            coli = (coli + 1) % 5;
            colii = (colii + 1) % 5;
        }
        else if (coli == colii)
        {
            rowi = (rowi + 1) % 5;
            rowii = (rowii + 1) % 5;
        }
        else
        {
            int temp = coli;
            coli = colii;
            colii = temp;
        }

        ciphertext = ciphertext + matrix[(rowi * 5) + coli] + matrix[(rowii * 5) + colii];
    }

    cout << ciphertext;
    return 0;
}
