// 노가다
#include <iostream>
#include <cstring>
using namespace std;

void URLs(string& str, int number) {
    string protocol, host, port, path;
    int protocolPos = str.find("://");

    protocol = str.substr(0, protocolPos);

    int portPos = str.find(":", protocolPos + 3);
    int pathPos = str.find("/", protocolPos + 3);
    if (portPos == string::npos && pathPos == string::npos) {
        host = str.substr(protocolPos + 3);
        port = path = "<default>";
    }
    else if (portPos != string::npos) {
        host = str.substr(protocolPos + 3, portPos - (protocolPos + 3));
        if (pathPos != string::npos && portPos < pathPos) {
            port = str.substr(portPos + 1, pathPos - (portPos + 1));
            path = str.substr(pathPos + 1);
        }
        else if (pathPos != string::npos && portPos > pathPos) {
            host = str.substr(protocolPos + 3, pathPos - protocolPos - 3);
            port = "<default>";
            path = str.substr(pathPos + 1);
        }
        else {
            port = str.substr(portPos + 1);
            path = "<default>";
        }
    }
    else {
        host = str.substr(protocolPos + 3, pathPos - (protocolPos + 3));
        path = str.substr(pathPos + 1);
        port = "<default>";
    }
    cout << "URL #" << number << '\n';
    cout << "Protocol = " << protocol << '\n';
    cout << "Host     = " << host << '\n';
    cout << "Port     = " << port << '\n';
    cout << "Path     = " << path << '\n';
}
int main() {
    int number;
    string URL;
    cin >> number;
    for (int i = 1; i <= number; i++) {
        cin >> URL;
        URLs(URL, i);
        if (i != number) {
            cout << "\n";
        }
    }
    return 0;
}
/*
// 정규표현식 (regex)
#include <iostream>
#include <regex>
using namespace std;
int main() {
    regex r(R"((^\w+)://([^:/]+)(:\d+)?(/.+$)?)");
    int n;
    string s, ans[4];
    cin >> n;
    for (int cnt = 1; cnt <= n; cnt++) {
        cin >> s;
        auto it = *sregex_iterator(s.begin(), s.end(), r);
        for (int i = 0; i < 4; i++) {
            ans[i] = it[i + 1];
            if (ans[i].empty()) {
                ans[i] = "<default>";
            }
        }
        if (ans[2][0] == ':') {
            ans[2] = ans[2].substr(1);
        }
        if (ans[3][0] == '/') {
            ans[3] = ans[3].substr(1);
        }
        cout << "URL #" << cnt << '\n';
        cout << "Protocol = " << ans[0] << '\n';
        cout << "Host     = " << ans[1] << '\n';
        cout << "Port     = " << ans[2] << '\n';
        cout << "Path     = " << ans[3] << '\n' << '\n';
    }
}
*/