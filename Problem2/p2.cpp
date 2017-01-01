#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("promote.in");
ofstream fout("promote.out");

int main()
{
    int bronzebefore, bronzeafter, silverbefore, silverafter, goldbefore, goldafter, platbefore, platafter;
    fin >> bronzebefore >> bronzeafter >> silverbefore >> silverafter >> goldbefore >> goldafter >> platbefore >> platafter;
    int bpromote, spromote, gpromote;
    gpromote = platafter - platbefore; //gold promotion only has to do with platinum
    spromote = goldafter - (goldbefore - gpromote); //silver promotion only has to do with gold and gold promotion
    bpromote = silverafter - (silverbefore - spromote); //bronze only has to do with all 3
    fout << bpromote << endl << spromote << endl << gpromote << endl;
}
