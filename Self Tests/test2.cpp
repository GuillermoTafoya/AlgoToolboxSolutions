#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


/*
 * Complete the 'find_meeting_slots' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER num_slots
 *  2. 2D_STRING_ARRAY employee_schedules
 */

vector<string> find_meeting_slots(int num_slots, vector<vector<string>> employee_schedules) {
    // We will use a vector of vectors to represent the matrix.
    vector<vector<bool>> available(employee_schedules.size(), vector<bool>(24*4, true));
    // Now we parse the employee schedules and fill in the matrix.
    for (int i = 0; i < employee_schedules.size(); i++) {
        for (int j = 0; j < employee_schedules[i].size(); j++) {
            // Parse the time slot
            string start_time = employee_schedules[i][j].substr(0, 5);
            string end_time = employee_schedules[i][j].substr(6, 5);

            // Convert the time to 15 minute intervals
            int start_time_int = stoi(start_time.substr(0, 2)) * 4 + stoi(start_time.substr(3, 2)) / 15;
            int end_time_int = stoi(end_time.substr(0, 2)) * 4 + stoi(end_time.substr(3, 2)) / 15;

            // Fill in the matrix
            for (int k = start_time_int; k < end_time_int; k++) {
                available[i][k] = false;
            }
        }
    }

    // We go over each 15 minute interval and count the number of employees available.
    // We will use a vector of pairs to store the number of employees available and the time slot.
    vector<pair<int, int>> num_employees_available;
    for (int i = 0; i < 24*4; i++) {
        int num_available = 0;
        for (int j = 0; j < available.size(); j++) {
            if (available[j][i]) {
                num_available++;
            }
        }
        num_employees_available.push_back(make_pair(num_available, i));
    }
    
    // We sort the vector of pairs by the number of employees available and then by the time slot.
    sort(num_employees_available.begin(), num_employees_available.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    });
    
    // We now go over the sorted vector of pairs and greedy select the time slots.
    // We keep popping the first element of the vector while the time slots are contiguous.
    // We stop when we have selected the number of time slots we want or when there are no more time slots.
    vector<string> meeting_slots;
    while (meeting_slots.size() < num_slots && num_employees_available.size() > 0) {
        // Convert the time slot to the format "HH:MM-HH:MM"
        int start_time = num_employees_available[0].second;
        int end_time = start_time + 1;
        // A meeting must be have at least 2 employees available. 
        int available_employees = num_employees_available[0].first;
        num_employees_available.erase(num_employees_available.begin());
        while (num_employees_available.size() > 0 && num_employees_available[0].second == end_time) {
            end_time++;
            num_employees_available.erase(num_employees_available.begin());
        }
        if (available_employees < 2) {
            break;
        }
        string start_minutes = to_string(start_time % 4 * 15);
        if (start_minutes.size() == 1) {
            start_minutes = "0" + start_minutes;
        }
        string start_hours = to_string(start_time / 4);
        if (start_hours.size() == 1) {
            start_hours = "0" + start_hours;
        }
        string end_minutes = to_string(end_time % 4 * 15);
        if (end_minutes.size() == 1) {
            end_minutes = "0" + end_minutes;
        }
        string end_hours = to_string(end_time / 4);
        if (end_hours.size() == 1) {
            end_hours = "0" + end_hours;
        }
        string meeting_slot = start_hours + ":" + start_minutes + "-" + end_hours + ":" + end_minutes;
        meeting_slots.push_back(meeting_slot);
    }

    if (meeting_slots.size() < num_slots) {
        return {};
    }

    // We sort the meeting times by earliest to latest.
    sort(meeting_slots.begin(), meeting_slots.end(), [](string a, string b) {
        return a < b;
    });
    return meeting_slots;
}
    
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string num_slots_temp;
    getline(cin, num_slots_temp);

    int num_slots = stoi(ltrim(rtrim(num_slots_temp)));

    string employee_schedules_rows_temp;
    getline(cin, employee_schedules_rows_temp);

    int employee_schedules_rows = stoi(ltrim(rtrim(employee_schedules_rows_temp)));

    string employee_schedules_columns_temp;
    getline(cin, employee_schedules_columns_temp);

    int employee_schedules_columns = stoi(ltrim(rtrim(employee_schedules_columns_temp)));

    vector<vector<string>> employee_schedules(employee_schedules_rows);

    for (int i = 0; i < employee_schedules_rows; i++) {
        string employee_schedules_row_temp_temp;
        getline(cin, employee_schedules_row_temp_temp);

        vector<string> employee_schedules_row_temp = split(rtrim(employee_schedules_row_temp_temp));
        employee_schedules.push_back(employee_schedules_row_temp);
    }

    vector<string> result = find_meeting_slots(num_slots, employee_schedules);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}