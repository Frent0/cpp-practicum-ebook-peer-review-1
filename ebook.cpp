#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <iomanip>

using namespace std;

class BookReference {
public:
    BookReference() {
        user_to_page.resize(100001, -1);
        pages_read_users.resize(1001, 0);
    }

    void ProcessRequests() {
        int count_request;
        cin >> count_request;

        while (count_request--) {
            string request;
            cin >> request;

            if (request == "READ") {
                ProcessReadRequest();
            }
            else if (request == "CHEER") {
                ProcessCheerRequest();
            }
        }
    }

private:
    vector<int> user_to_page;
    vector<int> pages_read_users;
    int count_users = 0;

    void ProcessReadRequest() {
        int user, page;
        cin >> user >> page;

        if (user_to_page[user] == -1) {
            ++count_users;
        }
        else {
            --pages_read_users[user_to_page[user]];
        }

        user_to_page[user] = page;
        ++pages_read_users[page];
    }

    void ProcessCheerRequest() {
        int user;
        cin >> user;

        if (user_to_page[user] == -1) {
            cout << 0 << "\n";
            return;
        }

        if (count_users == 1) {
            cout << 1 << "\n";
            return;
        }

        double count = 0;
        const int need_page = user_to_page[user];

        for (int number_page = 1; number_page < need_page; ++number_page) {
            count += pages_read_users[number_page];
        }

        cout << setprecision(6) << count / (count_users - 1) << "\n";
    }
};


int main() {
    BookReference test;
    test.ProcessRequests();
}
