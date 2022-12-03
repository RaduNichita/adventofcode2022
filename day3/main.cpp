#include <bits/stdc++.h>

std::vector<std::string> read_input() {
    std::vector<std::string> res;
    std::string line;

    while (std::cin >> line) {
        res.push_back(line);
    }

    return res;
}

int solve_task1(auto input) {
    int res = 0;

    for (auto &line : input) {
        std::unordered_set<char> seen_letters;
        assert(line.size() % 2 == 0);
        for (int i = 0; i < line.size() / 2; ++i) {
            seen_letters.insert(line[i]);
        }

        for (int i = line.size() / 2; i < line.size(); ++i) {
            if (seen_letters.find(line[i]) != seen_letters.end()) {
                if (line[i] >= 'A' && line[i] <= 'Z') {
                    res += 26 + (line[i] - 'A' + 1);
                } else {
                    res += (line[i] - 'a' + 1);
                }
                break;
            }
        }
    }

    return res;
}

int solve_task2(auto input) {
    int res = 0;
    for (int i = 0; i < input.size(); i += 3) {
        std::vector<std::string> elfs = {input[i], input[i + 1], input[i + 2]};

        std::vector<std::vector<bool>> v(52, std::vector<bool>(3, 0));
        for (int j = 0; j < elfs.size(); ++j) {
            for (auto &c : elfs[j]) {
                int index = 0;
                if (c >= 'A' && c <= 'Z') {
                    index = 26 + (c - 'A');
                } else {
                    index = c - 'a';
                }
                v[index][j] = true;
            }
        }

        for (int j = 0; j < 52; ++j) {
            if (v[j][0] && v[j][1] && v[j][2]) {
                res += (j + 1);
            }
        }
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