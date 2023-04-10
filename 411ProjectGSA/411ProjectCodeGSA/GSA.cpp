// CSCI 411 - Spring 2023
// Project: Gale-Shapley Algorithm
// Author: Luke Hazelton

#include <iostream>
#include <vector>
using namespace std;

void GSA(const vector<vector<int>>& acc_pref, const vector<vector<int>>& donor_pref,
                vector<int>& acc_match, vector<int>& donor_match, vector<int>& acc_propose) {

        int n = acc_pref.size(); // get the number of acceptors/donors
        // initialize matches and proposals
        for (int i = 0; i < n; i++) {
                acc_match[i] = -1;
                donor_match[i] = -1;
                acc_propose[i] = 0; // start proposing with the first choice for each acceptor
        }

        int free_count = n;
        while (free_count > 0) {  // while there exists a free patient (an acceptor without a donor)
                int p;
                // find the next free patient (acceptor)
                for (p = 0; p < n; p++) {
                        if (acc_match[p] == -1) break;
                }
                // propose to next preferred donor until proposal is accepted
                for (int i = 0; i < n && acc_match[p] == -1; i++) {
                        int d = acc_pref[p][acc_propose[p]]; // get the current preferred donor for the current acceptor
                        if (donor_match[d] == -1) { // if the donor is free, match the acceptor with the donor
                                acc_match[p] = d;
                                donor_match[d] = p;
                                free_count--;
                        } else { // if the donor is already matched
                                int p2 = donor_match[d];
                                bool found_p = false;
                                bool found_p2 = false;
                                for (int j = 0; j < donor_pref[d].size(); j++) {// iterate over the donor's preference list
                                        if (donor_pref[d][j] == p) found_p = true;// check if the current acceptor is preferred to the current match
                                        if (donor_pref[d][j] == p2) found_p2 = true;// check if the current match is preferred to the current acceptor
                                        if (found_p && !found_p2) {// if the current acceptor is preferred to the current match
                                                acc_match[p] = d;
                                                donor_match[d] = p;
                                                acc_match[p2] = -1;
                                                break;
                                        } else if (found_p2) {// if the current match is preferred to the current acceptor
                                                break;
                                        }
                                }
                        }
                        acc_propose[p]++; //on to the next
                }
        }
}

int main() {
        // read input
        int n;
        cout << "How many people will be in each list?: ";
        cin >> n;
        vector<vector<int>> acc_pref(n);
        vector<vector<int>> donor_pref(n);
        for (int i = 0; i < n; i++) {
                int k;
                cout << "How many preferences will acceptor " << i << " have?" << endl;
                cin >> k;
                acc_pref[i].resize(k);
                for (int j = 0; j < k; j++) {
                        cout << "Input preference " << j << " for acceptor " << i << " :";
                        cin >> acc_pref[i][j];
                        cout << endl;
                }
        }
        for (int i = 0; i < n; i++) {
                int k;
                cout << "How many preferences will donor " << i << " have?" << endl;
                cin >> k;
                donor_pref[i].resize(k);
                for (int j = 0; j < k; j++) {
                        cout << "Input preference " << j << " for donor " << i << " :";
                        cin >> donor_pref[i][j];
                        cout << endl;
                }
        }

        vector<int> acc_match(n, -1);
        vector<int> donor_match(n, -1);
        vector<int> acc_propose(n, 0);

        // run algorithm
        GSA(acc_pref, donor_pref, acc_match, donor_match, acc_propose);

        // print matches
        for (int i = 0; i < n; i++) {
                cout << "Acceptor " << i << " is matched with Donor " << acc_match[i] << endl;
        }
        return 0;
}

