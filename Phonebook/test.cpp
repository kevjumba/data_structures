#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    unordered_map<int, string> phonebook;
    phonebook.emplace(2, "kevin");
    cout<<phonebook[1];

}
