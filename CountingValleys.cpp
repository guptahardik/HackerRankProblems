#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */

int countingValleys(int steps, string path) {

    //my algorithm starts
    bool first = true;
    stack<char> tape;
    int count = 0;
    
    for(char i : path){
        if(first){
            tape.push(i);
            first = false;
        }else{
            switch (i) {

                case 'U':
                if(tape.empty()){
                    tape.push('U');
                }
                else if(tape.top() == 'U'){
                    tape.push('U');
                }else{
                    tape.pop();
                }
                if(tape.empty()){
                    count++;
                }
                break;
        
                case 'D':
                if(tape.empty()){
                    tape.push('D');
                }
                else if(tape.top() == 'D'){
                    tape.push('D');
                }else{
                    tape.pop();
                }

                break;

                default:
                break;
                }

        }
        
    
    }
    return count;
    
    //my algorithm ends.
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string steps_temp;
    getline(cin, steps_temp);

    int steps = stoi(ltrim(rtrim(steps_temp)));

    string path;
    getline(cin, path);

    int result = countingValleys(steps, path);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
