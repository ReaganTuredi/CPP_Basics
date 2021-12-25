#include <iostream>
#include <sstream>

int get_line_sum(const std::string& line)
{
    /*Get sum of digits in a line.*/
    int sum = 0;
    for (int i = 0; i < (int)line.size(); ++i){
        sum += line.at(i) - '0';
    }
    return sum;
}

char get_next_state(const std::string& neighborhood, const std::string& rules)
{
    /*Given set of rules, return new character for given neighborhood.*/
    std::string line, number;

    std::stringstream rules_stream(rules);

    while (getline(rules_stream, line)) {
        number = line.substr(0, 3);
        if (number == neighborhood) {
            return line.at(line.size() - 1);
        }
    }
    return '0';
}

std::string get_neighborhood(const std::string& line, int index)
{
    /*Returns neighborhood of given index.*/
    if (index == 0) {
        return std::string() + line.at(line.size() - 1) + line.at(0) + line.at(1);
    }
    else if (index == (int)line.size() - 1) {
        return std::string() + line.at(index - 1) + line.at(index) + line.at(0);
    }
    else {
        return std::string() + line.at(index - 1) + line.at(index) + line.at(index + 1);
    }
}

void update_line(std::string& line, const std::string& rules)
{
    /*Update line - one step in automata.*/
    std::string result{};

    /*Get how result should look like*/
    for (int i = 0; i < (int)line.size(); i++) {
        result += get_next_state(get_neighborhood(line, i), rules);
    }

    /*Replace original line with result.*/
    for (int i = 0; i < (int)line.size(); i++) {
        line.at(i) = result.at(i);
    }
}

std::string run_cellular_automata(const std::string& rules, int iterations, std::string line)
{
    /*Run automata with given rules and starting line for specified number of iterations.*/
    std::string result = line + " sum = " + std::to_string(get_line_sum(line)) + "\n";
    for (int i = 1; i < iterations; ++i) {
        update_line(line, rules);
        result += line + " sum = " + std::to_string(get_line_sum(line)) + "\n";
    }
    return result;
}

int main()
{
    /*Get rules, iteration count and starting line from user, run automata.*/
    std::string rules, line, input;
    int iterations;

    while (getline(std::cin, input)) {
        if (input == ".") {
            break;
        }
        rules += input + "\n";
    }

    std::cin >> iterations >> line;
    std::cout << run_cellular_automata(rules, iterations, line);
    return 0;
}


// https://en.cppreference.com/w/cpp/string/basic_string/getline
// https://www.cplusplus.com/reference/string/string/at/
// https://iq.opengenus.org/endl-and-n-in-cpp/
// https://www.cplusplus.com/reference/string/string/substr/
// https://www.tutorialspoint.com/cpp_standard_library/cpp_bitset_to_string.htm
