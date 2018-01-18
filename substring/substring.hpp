#ifndef _SUBSTR_
#define _SUBSTR_

#include <string>

class Substr
{
public:
    int len;

    Substr(std::string _superstr, int _min_length);
    ~Substr(void);

    void ret_substrings(void);
    std::string ret_minimum(void);
    void sort_substrings(void);
    void sort_substrings(std::string* _substr, int _len);

private:
    std::string superstr;
    std::string* substr;
    int perms;
    int min_length;

    static bool lencomp(std::string &str1, std::string &str2);
};

#endif
