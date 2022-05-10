#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{
    cout << "The 3 traits for the child will be eye color, hair color, ski and handedness\n";
    cout << "Eye color: B for black or b for green\n";
    cout << "Hair color: B for black or b for blond\n";
    cout << "Handedness: r for handedness or R for right handedness\n";
    int k = 3;
    vector <int> chances;
    while ( k != 0) {
        string cross_1;
        string cross_2;
        string saved_cross1;
        string saved_cross2;
        cout << "Please input the first generation (string of two of the same letter).\n";
        cin >> cross_1 >> cross_2;
        cout << "1st Generation: " << cross_1 << " " << cross_2 << "\n";
        saved_cross1 = cross_1;
        saved_cross2 = cross_2;
        transform(cross_1.begin(), cross_1.end(), cross_1.begin(), ::tolower);
        transform(cross_2.begin(), cross_2.end(), cross_2.begin(), ::tolower);

            if (k == 3) {
                if (cross_1 != "bb" || (cross_1 != cross_2 || cross_1.size() != 2 || cross_2.size() != 2)) {
                    cerr << "\nError, not the same letters.";
                    return 0;
                }
            }
            else if (k == 2) {
                if (cross_1 != "bb" || (cross_1 != cross_2 || cross_1.size() != 2 || cross_2.size() != 2)) {
                    cerr << "\nError, not the same letters.";
                    return 0;
                }
            }
            else if (k == 1) {
                if (cross_1 != "rr" || (cross_1 != cross_2 || cross_1.size() != 2 || cross_2.size() != 2)) {
                    cerr << "\nError, not the same letters.";
                    return 0;
                }
            } 
            
        
        string new_cross1 = saved_cross1.substr(0,1) + saved_cross2.substr(0,1);
        string new_cross2 = saved_cross1.substr(0,1) + saved_cross2.substr(1,1);
        string new_cross3 = saved_cross1.substr(1,1) + saved_cross2.substr(0,1);
        string new_cross4 = saved_cross1.substr(1,1) + saved_cross2.substr(1,1);
        vector<string> crosses;
        crosses.push_back(new_cross1);
        crosses.push_back(new_cross2);
        crosses.push_back(new_cross3);
        crosses.push_back(new_cross4);

        int percent_dom = 0;
        int percent_rec = 0;
        for (int i = 0; i < crosses.size(); i++) {
            for (int j = 0; j < crosses[i].size(); j++) {
                if (isupper(crosses[i][j])) {
                    percent_dom += 25;
                    break;
                }
            }
        }
        chances.push_back(percent_dom);
        percent_rec = 100 - percent_dom;
        //calculating the percent dominant and recessive
        cout << "2nd Generation:\n----------\n" << "|  " << saved_cross1.substr(0,1) << "   " << saved_cross1.substr(1,1) << " |\n" <<
        "|" << saved_cross2.substr(0,1) << " " << new_cross1 << "  " << new_cross3 << "|\n" <<
        "|" << saved_cross2.substr(1,1) << " " << new_cross2 << "  " << new_cross4 << "|\n----------\n";
        cout << "Dominant: " << percent_dom << "%\n";
        cout << "Recessive: " << percent_rec << "%\n";
        k--;
    }
    cout << "\nThe results show that:\nThe child will have a " << chances[0] << "% chance of having black eyes and a " <<
    100 - chances[0] << "% chance of having green eyes.\nThe child will have a " << chances[1] << "% chance of having black hair and a " <<
    100 - chances[1] << "% chance of having blond hair.\nThe child will have a " << chances[2] << "% chance of being right-handed and a " <<
    100 - chances[2] << "% chance of being left-handed.\n";
}