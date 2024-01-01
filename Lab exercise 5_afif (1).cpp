#include<iostream>
using namespace std;

//AFIF SHAQIR IRFAN BIN ARQAM A23CS0204

void dispStatus(int activecases) {
    if (activecases > 40) {
        cout << "Status of zone : Red";
    } else if (activecases >= 21 && activecases <=40) {
        cout << "Status of zone : Orange";
    } else if (activecases >= 1 && activecases <= 20) {
        cout << "Status of zone : Yellow";
    } else {
        cout << "Status of zone : Green";
    }
}

void getInput(int& reftotal, int& refnew_cases, int& refdeath, int& refrecovered) {
    cout << "Enter number of total cases: ";
    cin >> reftotal;
    cout << "Enter number of new cases: ";
    cin >> refnew_cases;
    cout << "Enter number of total death: ";
    cin >> refdeath;
    cout << "Enter number of total recovered: ";
    cin >> refrecovered;
}

int calcAverage(int siu, int tot) {
        return siu / tot;
    
    }


int main() {
    char highestState [50], state [50];
    char choose;
    int total, new_cases, death, recovered, active_cases, sum = 0;
    int highest = 0, totalCount = 0;

  do{
       
        cout << "\n<<<<<<<<<<<<<<DATA>>>>>>>>>>>>>>>>>>>>" << endl;
        cout << "State name: ";
        cin.getline (state, 50);
        getInput(total, new_cases, death, recovered);

        cout << "\n<<<<<<<<<<<SUMMARY>>>>>>>>>>>>>>" << endl;
        active_cases = (total + new_cases) - death - recovered;
        cout << "Active cases: " << active_cases << endl;
        dispStatus(active_cases);

        sum += active_cases;
        totalCount++;

        if (active_cases > highest) {
            highest = active_cases;
            strcpy (highestState, state);
        }
    
        cout << "\nPress <ENTER> to continue : ";
        cin >> choose;
        cin.ignore();

    }while (choose != 'N' && choose != 'n');
    
    cout << "\n<<<<<<<<< ACTIVE CASES >>>>>>>>>>" << endl;
    cout << "Total: " << sum << endl;
    cout << "Highest: " << highest << " (" << highestState << ")" << endl;
    cout << "Average for " << totalCount << " state: " << calcAverage(sum, totalCount) << endl;

    return 0;
}
