#include<bits/stdc++.h>

using namespace std;

struct Player{
    int x,y;
    void read(){
        cin >> x >> y;
    }
};
struct nextCheckPoint{
    int x,y,dist,angle;
    void read(){
        cin >> x >> y >> dist >> angle;
    }
};

int main()
{
    int count = 0;
    int mxdist = INT_MIN;
    bool used = false;
    // game loop
    while (true) {
        count++;
        Player me, opponent;
        me.read();
        nextCheckPoint next_cp;
        next_cp.read();
        opponent.read();
        int thrust = 100;
        mxdist = max(mxdist, next_cp.dist);
        auto range = [&](int x, int y){
            return y >= x-400 && y <= x+400;
        };
        if(count > 80 && range(mxdist, next_cp.dist)){
            cout << next_cp.x << " " << next_cp.y << " " << "BOOST" << endl;
            used = true;
            cerr << "i used boost " << endl;
            continue;
        }
        cerr << mxdist << endl;
        if(next_cp.angle > 90 || next_cp.angle < -90) thrust = 0;
        if(next_cp.dist < 100) thrust = 0;
        //cerr << next_cp.dist << endl;
        cout << next_cp.x << " " << next_cp.y << " " << thrust << endl;
    }
}
