#include <bits/stdc++.h>

enum TYPE {
    ROCK = 1,
    PAPER,
    SCISSOR
};

static const std::vector<std::vector<int>> winning = {
        {0, -1, 1},
        {1, 0, -1},
        {-1, 1, 0}
    };

static inline TYPE convert_type(const std::string &type) {
    if (type == "A" || type == "X") {
        return ROCK;
    } else if (type == "B" || type == "Y") {
        return PAPER;
    } else {
        return SCISSOR;
    }
}

static inline int compute_points(const int result) {
    return 3 * (1 - result);
}

static inline int get_match_result(const std::string &result) {
    return 1 - result.compare("X");
}

static int check_result(const std::string &player1, const std::string &player2) {
    return winning[convert_type(player1) - 1][convert_type(player2) - 1];
}

std::vector<std::pair<std::string, std::string>> read_input() {
    std::vector<std::pair<std::string, std::string>> res;
    std::string first, second;

    while (std::cin >> first >> second) {
        res.push_back({first, second});
    }

    return res;
}

int solve_task1(auto input) {
    int res = 0;

    for (auto &[other, me] : input) {
        int match_result = check_result(other, me);
        res += compute_points(match_result) + convert_type(me);
    }
    return res;
}

int solve_task2(auto input) {
    int res = 0;

    for (auto &[other, me] : input) {
        int match_result = get_match_result(me);
        assert(abs(match_result) <= 1);
        for (int i = 0; i < 3; ++i) {
            if (winning[convert_type(other) - 1][i] == match_result) {
                res += compute_points(match_result) + i + 1;
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