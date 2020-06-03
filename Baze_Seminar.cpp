
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void isIn(string f, vector<string>& D) {
    if (f.find("->") != string::npos) {
        f = f.replace(f.find("->"), 2, "");
    }

    int fSize = f.size();
    
    if (D.size() == 0) {
        D.push_back(f);
        return;
    }

    for (int i = 0; i < D.size(); ++i) {
        int helperCounter = 0;
        int fLetterCounter = 0;
        for (int j = 0; j < fSize; ++j) {
            if (D[i].find(f[j]) != string::npos) helperCounter++;
            fLetterCounter++;
        }
        if (helperCounter == fSize) return;
    }
    D.push_back(f);
}

bool findKey(string key, vector<string>& D) {
    int keySize = key.size();

    for (int i = 0; i < D.size(); ++i) {
        int helperCounter = 0;
        int fLetterCounter = 0;
        for (int j = 0; j < keySize; ++j) {
            if (D[i].find(key[j]) != string::npos) helperCounter++;
            fLetterCounter++;
        }
        if (helperCounter == keySize) return true;
    }
    return false;
}

int main()
{

    //string R = "ABCDEFG";
    vector<string> keys = { "ACG", "ACB", "ACE" };
    vector<string> fCover = {"A->D", "AG->B", "B->G",
        "B->E", "E->B", "E->F"};
    vector<string> D;
    bool keyFound = false;

    int coverLen = fCover.size();
    for (int i = 0; i < coverLen; ++i) {
        isIn(fCover.at(i), D);
    }

    for (int i = 0; i < keys.size(); ++i) {
        keyFound = findKey(keys[i], D);
        if (keyFound == true) break;
    }

    if (!keyFound) D.push_back(keys[0]);

    cout << "Dekompozicija: { ";
    for (int i = 0; i < D.size(); ++i) {
        cout << D[i] << ", ";
    }
    cout << "}";

}
