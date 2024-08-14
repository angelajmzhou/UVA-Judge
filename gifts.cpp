#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n;
    bool firstGroup = true;

    while(cin >> n){
        if (!firstGroup) {
            cout << endl;
        }
        firstGroup = false;

        vector<string> people(n);
        map<string, int> balance;

        for (int i = 0; i < n; i++) {
            cin >> people[i];
            balance[people[i]] = 0;
        }


        for (int i = 0; i < n; i++) {
            string giver;
            int spend, r;
            cin >> giver >> spend >> r;

            if (r > 0) {
                int amount = spend / r;
                int totalSpent = amount * r;
                balance[giver] -= spend;
                balance[giver] += spend % r;

                for (int j = 0; j < r; j++) {
                    string recipient;
                    cin >> recipient;
                    balance[recipient] += amount;
                }
            }
        }

        // Print balances
        for (int i = 0; i < n; i++) {
            cout << people[i] << " " << balance[people[i]] << endl;
        }
    }

    return 0;
}
