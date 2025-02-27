#include <iostream>
#include <string>
#include <sstream>

bool isNumber(const std::string& str)
{
    std::istringstream iss(str);
    int number;
    return (iss >> number) && (iss.eof());
}

int len_argument(int argc)
{
    int len = 0;
    for (int i = 0; i < argc; i++){
        len++;
    }
    return len;
}

int user_input()
{
    std::string input;

    while (true) {
        std::cout << "Enter next value: ";
        std::getline(std::cin, input);
        if (input == "END") {
            std::cout << "End of the program." << std::endl;
            break;
        }
        if (isNumber(input)) {
            int value = std::stoi(input);
            std::cout << "Vous avez saisi: " << value << std::endl;
        } else {
            std::cout << "Invalid input" << std::endl;
            return 84;
            break;
        }
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (len_argument(argc) != 5)
        return 84;
    else
        if (user_input() == 84)
            return 84;
    return 0;
}
