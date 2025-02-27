#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

bool isNumber(const std::string& str)
{
    std::istringstream iss(str);
    float number;
    return (iss >> number) && (iss.eof());
}

void print(int num_value, double arithmetic, double harmonic, double deviation, double rms)
{
    std::cout << "\tNumber of values:\t" << num_value << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\tStandard deviation:\t" << deviation << std::endl;
    std::cout << "\tArithmetic mean:\t" << arithmetic << std::endl;
    std::cout << "\tRoot mean square:\t" << rms << std::endl;
    std::cout << "\tHarmonic mean:\t\t" << harmonic << std::endl;
}

int user_input(int num_value, double arithmetic, double harmonic, double deviation)
{
    std::string input;
    double square_deviation = (deviation * deviation) * num_value;
    double sum_squares = square_deviation + num_value * (arithmetic * arithmetic);

    while (true) {
        std::cout << "Enter next value: ";
        std::getline(std::cin, input);
        if (input == "END")
            break;
        if (isNumber(input)) {
            double value = std::stof(input);
            double prev_mean = arithmetic;
            num_value += 1;
            arithmetic += (value - arithmetic) / num_value;
            square_deviation += (value - prev_mean) * (value - arithmetic);
            deviation = sqrt(square_deviation / num_value);
            sum_squares += value * value;
            double rms = sqrt(sum_squares / num_value);
            if (value != 0)
                harmonic = num_value / ((num_value - 1) / harmonic + 1 / value);
            print(num_value, arithmetic, harmonic, deviation, rms);
        } else {
            std::cerr << "Invalid input" << std::endl;
            return 84;
        }
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 5)
        return 84;
    int num_value = std::stoi(argv[1]);
    if (num_value < 0)
        return 84;
    double arithmetic = std::stoi(argv[2]);
    double harmonic = std::stoi(argv[3]);
    double deviation = std::stoi(argv[4]);
    if (user_input(num_value, arithmetic, harmonic, deviation) == 84)
            return 84;
    return 0;
}
