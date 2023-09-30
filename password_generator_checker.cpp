#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <ctime>

using namespace std;

int main()
{
    int dim;
    char exit, choice;
    string alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!£$%&/?@#*";
    int alphabet_length = alphabet.length();

    cout << "What do you want to do?" << endl;
    cout << "Press 1 to generate a password" << endl;
    cout << "Press 2 to check how much your password is strong" << endl;
    do
    {
        cout << "Press 1 or 2 and hit enter: ";  
        cin >> choice;
    } while (choice != '1' && choice != '2');
    
    if (choice == '1')
    {
        do
        {
            cout << endl << "Type the length of the password you want: ";
            cin >> dim;
            if (dim <= 8)
                cout << "Password could be weak!" << endl;
        } while (dim <= 0);

        cout << endl << "(by default the password will contain numbers, letters (capital and non) and special symbols)" << endl;
        srand(time(0));
        cout << "Generated password is: ";
        for (int i = 0; i < dim; i++)
        {
            cout << alphabet[rand() % alphabet_length]; 
        }
    }
        else if (choice == '2')
        {
            string password;
            bool foundNumber = false, foundUpper = false, foundLower = false, foundSymbol = false; 
            cout << endl << "Type your password: ";
            cin >> password;
            cout << endl << "Checking it..." << endl;
            cout << "- Length: " << password.length() << endl;
            for (char c : password)
            {
                if (isdigit(c))
                    foundNumber = true;
                if (islower(c))
                    foundLower = true;
                if (isupper(c))
                    foundUpper = true;
                if (!isalnum(c))
                    foundSymbol = true;
            }
            if (foundNumber)
                cout << "- Numbers: OK" << endl;
                else
                    cout << "- Numbers: NO" << endl;
            if (foundLower)
                cout << "- Lowercase: OK" << endl;
                else
                    cout << "- Lowercase: NO" << endl;
            if (foundUpper)
                cout << "- Uppercase: OK" << endl;
                else
                    cout << "- Uppercase: NO" << endl;
            if (foundSymbol)
                cout << "- Symbols: OK" << endl;
                else
                    cout << "- Symbols: NO" << endl;
        }    

    cout << endl << endl << "Press any key and hit enter to continue... ";
    cin >> exit;

    return 0;
}