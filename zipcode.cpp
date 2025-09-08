#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
class Letter{
public:
    string name; string address; string province; string district; int zip;
    bool operator < (const Letter& other) const {
        //**Begin Insert**
        if(this->zip != other.zip) return this->zip < other.zip;
        if(this->address != other.address) return this->address < other.address;
        if(this->district != other.district) return this->district < other.district;
        if(this->province != other.province) return this->province < other.province;
        return this->name < other.name;
        //**End Insert**
    }
};

class ZipInfo{
public:
    int zip;
    string province;
    string district;
};
void correctZipAndSortLetters(vector<ZipInfo>& zipinfo, vector<Letter>& letters) {
    //**Begin Insert**
    for (auto &letter:letters){
        for (auto &zips:zipinfo){
            if (letter.district==zips.district && letter.province==zips.province) {
                letter.zip=zips.zip;
                break;
            }
        }
    }
    sort(letters.begin(), letters.end());
    //**End Insert**
}
int main() {
    int nzip;
    cin>>nzip;
    vector<ZipInfo> zipinfo;
    for (int i = 0; i < nzip; i++) {
        ZipInfo z;
        cin>>z.zip>>z.district>>z.province;
        zipinfo.push_back(z);
    }
    int n;
    cin>>n;
    vector<Letter> letters;
    for (int i = 0; i < n; i++) {
        Letter l;
        cin>>l.name>>l.address>>l.district>>l.province>>l.zip;
        letters.push_back(l);
    }
    correctZipAndSortLetters(zipinfo, letters);
    for (auto& l:letters) {
        cout<<l.name<<" "<<l.address<<" "<<l.district<<" "<<l.province<<" "<<l.zip<<endl;
    }
}
