#include <iostream>

// 452--lbc--1s--sfl--232
bool string_checker(const std::string& input)
{
    char delimiter = '-';
    std::string cur_string;
    int cur_quad{};
    int numbers{}, letters{};
    for (int i = 0; i < input.size(); i++)
    {
        char cur_char = input[i];
        if (cur_char == delimiter)
        {
            switch (cur_quad)
            {
            case 0: // Check if all numbers
                for (char c : cur_string)
                {
                    if (c < '0' || c > '9') return false;
                }
                break;
            case 1: // check if all letters
                for (char c : cur_string)
                {
                    // Cleaner version with capital letters too
                    if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) return false;
                    // if (c < 'a' || c > 'z') return false;
                }
                break;
            case 2:
                for (char c : cur_string)
                {
                    if (c >= '0' && c <= '9') numbers++;
                    else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) letters++; // cleaner version
                    // else if (c >= 'a' && c <= 'z') letters++;
                    else return false;
                }
                if (letters != 1 || numbers != 1) return false;
                break;
            case 3: // check if all letters
                for (char c : cur_string)
                {
                    // Cleaner version with capital letters too
                    if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) return false;
                    // if (c < 'a' || c > 'z') return false;
                }
                break;
            }
            cur_string = "";
            cur_quad++;
            i++;
            continue;
        }
        cur_string += cur_char;
    }
    // Check last quadrant (Check if all numbers)
    for (char c : cur_string)
    {
        if (c < '0' || c > '9') return false;
    }
    return true;
}

int main()
{
    std::string input = "431--vzx--1a--sfl--232";
    if (string_checker(input)) std::cout << "true" << "\n";
    else std::cout << "false" << "\n";
    return 0;
}