#include <bits/stdc++.h>

std::pair<int, int> split_pair(const std::string &s) {
    int delimiter_pos = s.find('-');
    int first_number = std::stoi(s.substr(0, delimiter_pos));
    int second_number = std::stoi(s.substr(delimiter_pos + 1));

    return {first_number, second_number};
}

std::pair<std::pair<int, int>, std::pair<int, int>> parse_string(const std::string &s) {
    int delimiter_pos = s.find(',');
    std::string first_interval = s.substr(0, delimiter_pos);
    std::string second_interval = s.substr(delimiter_pos + 1);

    return {split_pair(first_interval), split_pair(second_interval)};
}

std::vector<std::string> read_input() {
    std::vector<std::string> res;
    std::string line;

    while (std::cin >> line) {
        res.push_back(line);
    }

    return res;
}

bool check_full_overlap(const std::pair<int, int> &first, const std::pair<int, int> &second) {
    return (first.first >= second.first && first.second <= second.second) ||
        (second.first >= first.first && second.second <= first.second);
}

bool check_overlap(const std::pair<int, int> &first, const std::pair<int, int> &second) {
    return std::max(first.first, second.first) <= std::min(first.second, second.second);
}

int solve_task1(auto input) {
    int res = 0;
    for (auto &line : input) {
        auto [f, s] = parse_string(line);
        res += (check_full_overlap(f, s));
    }
    return res;
}

int solve_task2(auto input) {
    int res = 0;
    for (auto &line : input) {
        auto [f, s] = parse_string(line);
        res += (check_overlap(f, s));
    }
    return res;
}


std::pair<int, int> solve() {
    const auto input = read_input();
    return {solve_task1(input), solve_task2(input)};
}

int main() {
    auto [task1, task2] = solve();
    std::cout << task1 << "\n";
    std::cout << task2 << "\n";

    return 0;
}