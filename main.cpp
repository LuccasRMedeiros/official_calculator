#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>

using namespace std;

void find_formula(string line)
{
    int total = 0;
    int operation = 0;

    for (size_t i = 0; line[i] != '\0'; ++i)
    {
        if (isdigit(line[i]))
        {
            if (operation)
            {
                total += atoi(line.substr(i).c_str()) * operation;
                cout << total << endl;

                total = 0;
                operation = 0;
            }
            else
            {
                total = atoi(line.substr(i).c_str());
            }

            while (isdigit(line[i]))
            {
                ++i;
            }
        }

        if (total > 0 && (line[i] == '+' || line[i] == '-'))
        {
            if (operation != 0)
            {
                total = 0;
                operation = 0;
            }
            else
            {
                operation = line[i] == '+' ? 1 : -1;
            }
        }
    }
}

int main(int argc, char **argv)
{
    while (1)
    {
        string buffer;

        cin >> buffer;
        find_formula(buffer);
    }

    return 0;
}
