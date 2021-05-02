#include <map>
#include <iostream>
#include <vector>
#include <set>
#include <initializer_list>


void create_cell(std::map<std::pair<int, int>, std::map<char, std::pair<int, int>>>& field, 
                int c_x, int c_y, int l_x, int l_y, int u_x, int u_y, 
                int r_x, int r_y, int d_x, int d_y) 
{
    auto center = std::make_pair(c_x, c_y);
    auto left = std::make_pair(l_x, l_y);
    auto up = std::make_pair(u_x, u_y);
    auto right = std::make_pair(r_x, r_y);
    auto down = std::make_pair(d_x, d_y);
    field[center]['L'] = left;
    field[center]['U'] = up;
    field[center]['R'] = right;
    field[center]['D'] = down;
}


char edge(std::pair<int, int> coord) {
    if (coord.second >= 9) return 'B';
    if (coord.second >= 6) return 'U';
    if (coord.first >= 6) return 'R';
    if (coord.first <= 2) return 'L';
    if (coord.second >= 3) return 'F';
    return 'D';
}


char change_edge(char operation, char now, char next) {
    if (now == next || now == 'F') return operation;
    if (now == 'U') {
        if (next == 'B') return 'U';
        if (next == 'L' || next == 'F' || next == 'R') return 'D';
    }
    if (now == 'B') {
        if (next == 'L') return 'R';
        if (next == 'R') return 'L';
        if (next == 'U') return 'D';
        if (next == 'D') return 'U';
    }
    if (now == 'D') {
        if (next == 'F' || next == 'L' || next == 'R') return 'U';
        if (next == 'B') return 'D';
    }
    if (now == 'L') return 'R';
    return 'L';
}


size_t find_oper(std::vector<char>& vect, char oper) {
    size_t i = 0;
    for (; i < vect.size(); ++i) {
        if (vect[i] == oper) break;
    }
    return i;
}


std::set<std::pair<int, int>> create_set(std::initializer_list<int> list) {
    auto it = list.begin();
    std::set<std::pair<int, int>> res;
    while (it != list.end()) {
        int a = *it;
        ++it;
        int b = 0;
        if (it != list.end()) {
            b = *it;
            ++it;
        }
        res.insert(std::make_pair(a, b));
    }
    return res;
}

void edge_to_cube(std::map<std::set<std::pair<int, int>>, int>& ans, std::initializer_list<int> list){
    ans[create_set(list)] = 0;
}


int main(){
    std::map<std::pair<int, int>, std::map<char, std::pair<int, int>>> field;
    for (int i = 10; i >= 1; --i) {
        create_cell(field, 4, i, 3, i, 4, i + 1, 5, i, 4, i - 1);
    }
    for (int i = 1; i <= 7; ++i) {
        if (i == 4) continue;
        create_cell(field, i, 4, i - 1, 4, i, 5, i + 1, 4, i, 3);
    }
    create_cell(field, 3, 11, 0, 3, 3, 0, 4, 11, 3, 10);
    create_cell(field, 3, 10, 0, 4, 3, 10, 4, 10, 3, 9);
    create_cell(field, 3, 9, 0, 5, 3, 10, 4, 9, 3, 8);
    create_cell(field, 3, 8, 0, 5, 3, 9, 4, 8, 3, 7);
    create_cell(field, 3, 7, 1, 5, 3, 8, 4, 7, 3, 6);
    create_cell(field, 3, 6, 2, 5, 3, 7, 4, 6, 3, 5);
    create_cell(field, 3, 5, 2, 5, 3, 6, 4, 5, 3, 4);
    create_cell(field, 3, 3, 2, 3, 3, 4, 4, 3, 3, 2);
    create_cell(field, 3, 2, 2, 3, 3, 3, 4, 2, 3, 1);
    create_cell(field, 3, 1, 1, 3, 3, 2, 4, 1, 3, 0);
    create_cell(field, 3, 0, 0, 3, 3, 1, 4, 0, 3, 11);

    create_cell(field, 5, 11, 4, 11, 5, 0, 8, 3, 5, 10);
    create_cell(field, 5, 10, 4, 10, 5, 11, 8, 4, 5, 9);
    create_cell(field, 5, 9, 4, 9, 5, 10, 8, 5, 5, 8);
    create_cell(field, 5, 8, 4, 8, 5, 9, 8, 5, 5, 7);
    create_cell(field, 5, 7, 4, 7, 5, 8, 7, 5, 5, 6);
    create_cell(field, 5, 6, 4, 6, 5, 7, 6, 5, 5, 5);
    create_cell(field, 5, 5, 4, 5, 5, 6, 6, 5, 5, 4);
    create_cell(field, 5, 3, 4, 3, 5, 4, 6, 3, 5, 2);
    create_cell(field, 5, 2, 4, 2, 5, 3, 6, 3, 5, 1);
    create_cell(field, 5, 1, 4, 1, 5, 2, 7, 3, 5, 0);
    create_cell(field, 5, 0, 4, 0, 5, 1, 8, 3, 5, 11);

    create_cell(field, 0, 5, 3, 9, 3, 8, 1, 5, 0, 4);
    create_cell(field, 1, 5, 0, 5, 3, 7, 2, 5, 1, 4);
    create_cell(field, 2, 5, 1, 5, 3, 6, 3, 5, 2, 4);
    create_cell(field, 6, 5, 5, 5, 5, 6, 7, 5, 6, 4);
    create_cell(field, 7, 5, 6, 5, 5, 7, 8, 5, 7, 4);
    create_cell(field, 8, 5, 7, 5, 5, 8, 5, 9, 8, 4);

    create_cell(field, 0, 3, 3, 11, 0, 4, 1, 3, 3, 0);
    create_cell(field, 1, 3, 0, 3, 1, 4, 2, 3, 3, 1);
    create_cell(field, 2, 3, 1, 3, 2, 4, 3, 3, 3, 2);
    create_cell(field, 6, 3, 5, 3, 6, 4, 7, 3, 5, 2);
    create_cell(field, 7, 3, 6, 3, 7, 4, 8, 3, 5, 1);
    create_cell(field, 8, 3, 7, 3, 8, 4, 5, 11, 5, 0);

    create_cell(field, 4, 11, 3, 11, 4, 0, 5, 11, 4, 10);
    create_cell(field, 0, 4, 3, 10, 0, 5, 1, 4, 0, 3);
    create_cell(field, 8, 4, 7, 4, 8, 5, 5, 10, 8, 3);
    create_cell(field, 4, 0, 3, 0, 4, 1, 5, 0, 4, 11);


    std::map<std::set<std::pair<int, int>>, int> ans;

    edge_to_cube(ans, {4, 10});
    edge_to_cube(ans, {4, 7});
    edge_to_cube(ans, {4, 4});
    edge_to_cube(ans, {1, 4});
    edge_to_cube(ans, {7, 4});
    edge_to_cube(ans, {4, 1});


    edge_to_cube(ans, {4, 5, 4, 6});
    edge_to_cube(ans, {5, 4, 6, 4});
    edge_to_cube(ans, {4, 3, 4, 2});
    edge_to_cube(ans, {3, 4, 2, 4});

    edge_to_cube(ans, {4, 8, 4, 9});
    edge_to_cube(ans, {5, 7, 7, 5});
    edge_to_cube(ans, {3, 7, 1, 5});

    edge_to_cube(ans, {7, 3, 5, 1});
    edge_to_cube(ans, {8, 4, 5, 10});

    edge_to_cube(ans, {4, 0, 4, 11});
    edge_to_cube(ans, {3, 1, 1, 3});

    edge_to_cube(ans, {0, 4, 3, 10});


    edge_to_cube(ans, {2, 5, 3, 5, 3, 6});
    edge_to_cube(ans, {5, 6, 5, 5, 6, 5});
    edge_to_cube(ans, {5, 2, 5, 3, 6, 3});
    edge_to_cube(ans, {2, 3, 3, 3, 3, 2});
    edge_to_cube(ans, {5, 8, 5, 9, 8, 5});
    edge_to_cube(ans, {0, 5, 3, 8, 3, 9});
    edge_to_cube(ans, {5, 0, 8, 3, 5, 11});
    edge_to_cube(ans, {3, 0, 0, 3, 3, 11});

    std::vector<char> new_operate = {'L', 'U', 'R', 'D'};
    char cmd;
    char operation = 'U';
    ans[std::set<std::pair<int, int>>{std::make_pair(4, 4)}] = 1;
    std::pair<int, int> now_coord = std::make_pair(4, 4);
    while (std::cin >> cmd) {
        if (cmd == 'S') break;
        if (cmd == 'F') {
            auto new_coord = field[now_coord][operation];
            operation = change_edge(operation, edge(now_coord), edge(new_coord));
            for (auto& elem : ans) {
                if (elem.first.find(new_coord) != elem.first.end()) {
                    ans[elem.first] = 1;
                    break;
                }
            }
            now_coord = new_coord;
        } else {
            size_t i = find_oper(new_operate, operation);
            if (cmd == 'L') { operation = new_operate[(i + 3) % 4]; }
            else { operation = new_operate[(i + 1) % 4]; } 
        }
    }
    int res = 0;
    for (const auto& elem : ans) {
        if (elem.second) res++;
    }
    std::cout << res << std::endl;
}