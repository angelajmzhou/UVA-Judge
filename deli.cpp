#include <iostream>
#include <map>

using namespace std;
bool isConsonant(char c) {
    c = tolower(c);

    // Check if the character is a letter and not a vowel
    return isalpha(c) && (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u');
}

int main(){
    int l,n,i,end;
    string singular, plural, word, suffix;
    map<string, string> irreg; 
    cin >> l >> n;
    for (i=0;i<l;i++){
        cin >> singular >> plural;
        irreg[singular] = plural;
    }
    for (i=0;i<n;i++){
        cin >> word;
        end = word.length()-1;
        suffix = word.substr(end-1,2);

        if (irreg.find(word) != irreg.end()){
            cout<<irreg[word]<<endl;
        }
        else if(isConsonant(word[end-1]) && word[end] =='y'){
            word.pop_back();
            cout<<word<<"ies"<<endl;
        }
        else if(word.back()=='o'||word.back()=='s'||word.back()=='x'){
            cout<<word<<"es"<<endl;
        }
        else if(suffix == "ch" || suffix == "sh" || suffix == "es"){
            cout<<word<<"es"<<endl;
        }
        else{
            cout<<word<<"s"<<endl;
        }
    }
    return 0;
}