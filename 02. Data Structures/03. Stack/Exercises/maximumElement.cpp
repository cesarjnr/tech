#include <bits/stdc++.h>

using namespace std;

vector<int> getMax(vector<string> operations) {
  vector<int> operation_values;
  vector<int> max_values;
  vector<int> answers;
  
  for (int i = 0; i < operations.size(); i++) {
    string query = operations[i];
    char operation = query.front();
    
    if (operation == '1') {
      int value = stoi(query.substr(2));

      operation_values.push_back(value);

      if (max_values.empty() || value > max_values.back()) {
        max_values.push_back(value);
      } else {
        max_values.push_back(max_values.back());
      }
    } else if (operation == '2') {
      operation_values.pop_back();
      max_values.pop_back();
    } else {
      answers.push_back(max_values.back());
    }
  }
  
  return answers;
}

int main() {
  vector<string> queries = {
    "1 1",
    "1 44",
    "3",
    "3",
    "2",
    "3",
    "3",
    "1 3",
    "1 37",
    "2",
    "3",
    "1 29",
    "3",
    "1 73",
    "1 51",
    "3",
    "3",
    "3",
    "1 70",
    "3",
    "1 8",
    "2",
    "1 49",
    "1 56",
    "1 81",
    "2",
    "1 59",
    "1 44",
    "2",
    "3",
    "3",
    "2",
    "3"
    "3"
    "1 4",
    "3",
    "1 89",
    "2",
    "1 37",
    "1 50",
    "1 64",
    "2",
    "1 49",
    "1 35",
    "1 85",
    "3",
    "1 41",
    "2",
    "3",
    "3",
    "1 86",
    "3",
    "1 60",
    "1 8",
    "3",
    "1 100",
    "3",
    "1 83",
    "3",
    "1 47",
    "2",
    "1 78",
    "2",
    "1 55",
    "1 97",
    "2",
    "3",
    "1 40"
  };
  vector<int> answers = getMax(queries);

  for (size_t i = 0; i < answers.size(); i++) {
    cout << answers[i] << endl;
  }
  

  return 0;
}