#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void run() {
    int n;
    string type, name;
    int number;
    vector<string> phonebook;
    cin >> n;
    phonebook.resize(10*10*10*10*10*10*10);
    for (int i = 0; i < n; ++i) {
        cin >> type;
        if (type == "add"){
            cin>>number;
            cin>>name;
            phonebook[number]= name;
        }

        else if(type == "del"){
            cin>>number;
            phonebook[number] = "";
        }
        else{
            cin>>number;
            if(phonebook[number] == ""){
                cout<<"not found"<<endl;
            }
            else cout<<phonebook[number]<<endl;
        }
    }
    return;
}


int main() {
run();
    return 0;
}
