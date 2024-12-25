/*
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int main(){
    vector<string> names = {"lanre", "eniola", "dieko", "tim", "tobi"};
    vector<bool> chosen(names.size(), false); // Tracks whether a name has been picked
    int count = names.size();

    string name;
    srand(time(0));
    do{
        cout<<"What is your name? ";
        cin>>name;
        int randnum;
         do {
            randnum = rand() % names.size();
        } while (chosen[randnum]);

        if(name == names[randnum]){
            cout<<"You picked yourself.\n Press enter to choose again.\n";
            cin.get();
        }else {
            cout<<"You picked someone\n";
            cout<<"\t \t \t"<<names[randnum]<<"\n press enter to hide your choice.\n";
            chosen[randnum] = true;
            count--;
            //cin.get();
        }
        cin.ignore();
        system("cls");

    }while(count>0);

    for(int i=0; i<5; i++){
        cout<<names[i]<<" ";
    }
}
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <vector>
using namespace std;

int main() {
    vector<string> names = {"lanre", "eniola", "dieko", "tim", "tobi"};
    vector<bool> chosen(names.size(), false); // Tracks whether a name has been picked
    int count = names.size();

    string name;
    srand(time(0));

    while (count > 0) {
        cout << "What is your name? ";
        cin >> name;

        // Generate a random number until an unchosen name is found
        int randnum;
        do {
            randnum = rand() % names.size();
        } while (chosen[randnum]);

        // Check if the user picks their own name
        if (name == names[randnum]) {
            cout << "You picked yourself. Press enter to choose again.\n";
            cin.get();
        } else {
            cout << "You picked someone!\n";
            cout << "\t\t\t" << names[randnum] << "\nPress enter to hide your choice.\n";
            chosen[randnum] = true; // Mark the name as chosen
            count--;
            cin.get();
        }

        // Wait for user input before clearing
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("cls");
    }

    cout << "All names have been chosen. Final list:\n";
    for (size_t i = 0; i < names.size(); i++) {
        cout << names[i] << " - " << (chosen[i] ? "Chosen" : "Not Chosen") << "\n";
    }

    return 0;
}
