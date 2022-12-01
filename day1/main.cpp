#include <bits/stdc++.h>


std::pair<int, int> solve() {
    std::string line;
    int current = 0;
    std::vector<int> v;

    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            v.push_back(current);
            current = 0;
        } else {
            current += std::stoi(line);
        }
    }

    if (current != 0) {
        v.push_back(current);
    }

    std::sort(v.begin(), v.end(), std::greater<int>());

    return {v[0], v[0] + v[1] + v[2]};
}

void solve_task2() {

}


int main() {

    auto [task1, task2] = solve();
    std::cout << task1 << "\n";
    std::cout << task2 << "\n";
    return 0;
}