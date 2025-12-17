#include <iostream>
#include <vector>
#include <unordered_set>
#include <iomanip>
#include <queue>     // <-- WAJIB BIAR queue KENAL
using namespace std;

int main(){
    vector<string> pool = {
        "Ling","Fanny","Lancelot","Hayabusa","Tigreal",
        "Johnson","Edith","YuZhong","Chou","Balmond",
        "Kagura","Xavier","Nana","Lesley","Miya",
        "Argus","Freya","Sun","Vale","Gusion"
    };

    unordered_set<int> banned, picked;

    int bansPerTeam = 2;
    int picksPerTeam = 3;

    cout << "Pilih tim Anda: (1) BLUE  (2) RED : ";
    int teamChoice; cin >> teamChoice;
    string userTeam = (teamChoice == 1 ? "BLUE" : "RED");
    string otherTeam = (userTeam == "BLUE" ? "RED" : "BLUE");

    cout << "Anda tim: " << userTeam << "\n\n";

    vector<string> banOrder;
    vector<string> pickBLUE, pickRED;

    queue<string> qBan, qPick;
    for(int i=0;i<bansPerTeam;i++){
        qBan.push("BLUE"); qBan.push("RED");
    }
    for(int i=0;i<picksPerTeam;i++){
        qPick.push("BLUE"); qPick.push("RED");
    }

    // BAN PHASE
    cout << "=== BAN PHASE ===\n";
    for(int i=0;i<2*bansPerTeam; i++){
        string tm = qBan.front(); qBan.pop();
        cout << "[" << tm << "] Ban " << (i+1) << "\n";
        cout << "Available heroes:\n";
        for(int j=0;j<(int)pool.size();j++){
            if(banned.count(j)==0){
                cout << setw(2) << j+1 << ". " << pool[j] << "\n";
            }
        }
        cout << "Pilih hero yang diban (nomor): ";
        int h; cin >> h;
        if(h < 1 || h > (int)pool.size()){
            cout << "Input invalid, ulangi.\n"; i--; continue;
        }
        int idx = h-1;
        if(banned.count(idx)){
            cout << "Hero sudah diban, ulangi.\n"; i--; continue;
        }
        banned.insert(idx);
        banOrder.push_back(pool[idx]);
        cout << tm << " memban " << pool[idx] << "\n\n";
    }

    // PICK PHASE
    cout << "=== PICK PHASE ===\n";
    for(int i=0;i<2*picksPerTeam; i++){
        string tm = qPick.front(); qPick.pop();
        cout << "[" << tm << "] Pick " << (i+1) << "\n";
        cout << "Available heroes:\n";
        for(int j=0;j<(int)pool.size();j++){
            if(banned.count(j)==0 && picked.count(j)==0){
                cout << setw(2) << j+1 << ". " << pool[j] << "\n";
            }
        }
        cout << "Pilih hero (nomor): ";
        int h; cin >> h;
        if(h < 1 || h > (int)pool.size()){
            cout << "Input invalid, ulangi.\n"; i--; continue;
        }
        int idx = h-1;
        if(banned.count(idx)){
            cout << "Hero diban — tidak bisa dipick, ulangi.\n"; i--; continue;
        }
        if(picked.count(idx)){
            cout << "Hero sudah dipick, ulangi.\n"; i--; continue;
        }
        picked.insert(idx);
        if(tm == "BLUE") pickBLUE.push_back(pool[idx]);
        else pickRED.push_back(pool[idx]);
        cout << tm << " mem-pick " << pool[idx] << "\n\n";
    }

    // HASIL AKHIR
    cout << "\n=== HASIL AKHIR ===\n";
    cout << "Ban order: ";
    for(auto &b: banOrder) cout << b << ", ";
    cout << "\nPicks BLUE: ";
    for(auto &h: pickBLUE) cout << h << ", ";
    cout << "\nPicks RED : ";
    for(auto &h: pickRED) cout << h << ", ";
    cout << "\n";

    return 0;
}
