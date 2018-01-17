#include <iostream>
#include <algorithm>
#include <fstream>

bool lencomp(std::string &str1, std::string &str2)
{
    return str1.length() < str2.length();
}

int main (int argc, char** argv)
{
    std::ifstream infile("stringlist.txt", std::ios::in);
    std::string line = "";

    while(getline(infile, line)) {
        std::string result = "";
        int len = line.length();
        int perms = ((len * (len + 1)) / 2 ) - len;;
        std::string* subs = new std::string[perms];

        int ind = 0;
        /** For each starting letter */
        for(int i = 0; i < len; i++) {
            /** For each length */
            for(int j = 1; j < len - i; j++, ind++) {
                /** For each character */
                for(int k = 0; k <= j; k++) {
                    subs[ind] += line[k + i];
                }
            }
        }

        std::sort(subs, subs + perms, lencomp);

        for(int i = 0; i < perms - 1; i++) {
            for(int j = i + 1; j < perms; j++) {
                if(subs[i] == subs[j]) {
                    result = subs[i];
                    break;
                }
            }
            if(result != "")
                break;
        }

        std::cout << "And the winner is... " << result << std::endl;

        delete[] subs;
        infile.close();
    }
}
