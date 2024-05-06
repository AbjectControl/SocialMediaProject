#include "ProfilePage.h"
using namespace std;

ProfilePage::ProfilePage (string p, int a, string l)
{
 professionPP = p;
 agePP = a;
 locationPP = l;
}
void ProfilePage::readfilePP(ifstream& file)
{
 file >> professionPP;
 file >> agePP;
 file >> locationPP;
}
void ProfilePage::outputFilePP(ofstream& file)
{
 file << professionPP << " " << agePP << " " << locationPP << endl;
}
void ProfilePage::DisplayP()
{
 cout <<"Profession : " << professionPP << endl;
 cout <<"Age : " << agePP << endl;
 cout <<"Lives in : " << locationPP << endl;
}
//SETTERS
void ProfilePage::SetprofessionPP(const string& p)
{
	professionPP = p;
}
void ProfilePage::SetagePP(int a)
{
 agePP = a;
}
void ProfilePage::SetloactionPP(const string& l)
{
 locationPP = l;
}
//GETTERS
string ProfilePage::GetprofessionPP()
{
 return professionPP;
}
int ProfilePage::GetagePP()
{
 return agePP;
}
string ProfilePage::GetloactionPP()
{
 return locationPP;
 }