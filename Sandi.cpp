#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c=='a'||c=='i'||c=='u'||c=='e'||c=='o');
}

// manual reverse
string manualReverse(string s) {
    for (int i=0, j=s.size()-1; i<j; i++, j--) {
        char t = s[i]; s[i] = s[j]; s[j] = t;
    }
    return s;
}

// ENCODE
string encode(string kata) {
    string tanpaVokal="";
    for (char c : kata) if (!isVowel(c)) tanpaVokal+=c;

    string dibalik = manualReverse(tanpaVokal);

    int asciiVal = (int)kata[0];
    string asciiStr = to_string(asciiVal);

    int mid = dibalik.size()/2;
    return dibalik.substr(0,mid)+asciiStr+dibalik.substr(mid);
}

// DECODE
string decode(string sandi) {
    string angka="", huruf="";
    for (char c: sandi) {
        if (isdigit(c)) angka+=c;
        else huruf+=c;
    }
    char firstChar = (char)stoi(angka);
    string asli = manualReverse(huruf);

    // cek apakah firstChar sudah ada
    if (asli.empty() || asli[0] != firstChar) {
        asli = firstChar + asli;
    }
    return asli + " (tanpa vokal)";
}

int main() {
    string kata, sandi;
    cout<<"Input kata asli: ";
    cin>>kata;
    cout<<"Hasil encode: "<<encode(kata)<<endl;

    cout<<"Input kata sandi: ";
    cin>>sandi;
    cout<<"Hasil decode: "<<decode(sandi)<<endl;
}