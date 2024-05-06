#ifndef PROFILEPAGE_H
#define PROFILEPAGE_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ProfilePage {
private:
    string professionPP;
    int agePP;
    string locationPP;

public:
    ProfilePage(string p = "", int a = 0, string l = "");

    void readfilePP(ifstream& file);
    void outputFilePP(ofstream& file);
    void DisplayP();

    // Setters
    void SetprofessionPP(const string& p);
    void SetagePP(int a);
    void SetloactionPP(const string& l);

    // Getters
    string GetprofessionPP();
    int GetagePP();
    string GetloactionPP();
};

#endif 

