#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

class Statistics {
private:
    int num_value;
    double arithmetic_mean;
    double harmonic_mean;
    double deviation;
    double sum_squares;
    double square_deviation;

public:
    Statistics(int num, double arithmetic, double harmonic, double dev)
        : num_value(num),
          arithmetic_mean(arithmetic),
          harmonic_mean(harmonic),
          deviation(dev) {
        square_deviation = (deviation * deviation) * num_value;
        sum_squares = square_deviation + num_value * (arithmetic_mean * arithmetic_mean);
    }

    bool isNumber(const std::string &str) const
    {
        std::istringstream iss(str);
        float number;
        return (iss >> number) && (iss.eof());
    }

    void print() const
    {
        std::cout << "    Number of values:\t" << num_value << std::endl;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "    Standard deviation:\t" << deviation << std::endl;
        std::cout << "    Arithmetic mean:\t" << arithmetic_mean << std::endl;
        std::cout << "    Root mean square:\t" << std::sqrt(sum_squares / num_value) << std::endl;
        std::cout << "    Harmonic mean:\t" << harmonic_mean << std::endl;
        std::cout << "\n";
    }

    int processInput()
    {
        std::string input;

        while (true) {
            std::cout << "Enter next value: ";
            std::getline(std::cin, input);
            if (input == "END")
                break;
            if (isNumber(input)) {
                double value = std::stof(input);
                double prev_mean = arithmetic_mean;
                num_value += 1;
                arithmetic_mean += (value - arithmetic_mean) / num_value;
                square_deviation += (value - prev_mean) * (value - arithmetic_mean);
                deviation = std::sqrt(square_deviation / num_value);
                sum_squares += value * value;
                if (value != 0)
                    harmonic_mean = num_value / ((num_value - 1) / harmonic_mean + 1 / value);
                else
                    return 84;
                print();
            } else {
                std::cerr << "Invalid input" << std::endl;
                return 84;
            }
        }
        return 0;
    }
};

int is_float(const std::string &str)
{
    for (int i = 0; str[i]; i++){
        if (str[i] < '0' || str[i] > '9')
            return 84;
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 5)
        return 84;
    if (is_float(argv[1]) == 84
    || is_float(argv[2]) == 84
    || is_float(argv[3]) == 84
    || is_float(argv[4]) == 84)
        return 84;
    int num_value = std::stoi(argv[1]);
    if (num_value < 0)
        return 84;
    double arithmetic = std::stod(argv[2]);
    double harmonic = std::stod(argv[3]);
    double deviation = std::stod(argv[4]);
    if (deviation < 0)
        return 84;
    Statistics stats(num_value, arithmetic, harmonic, deviation);
    if (stats.processInput() == 84)
        return 84;
    return 0;
}
