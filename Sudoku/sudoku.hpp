#pragma once
#include <bits/stdc++.h>
using namespace std;

class board
{

public:
    vector<vector<int>> mat;
    board(/* args */){
        mat.resize(9, vector<int>(9, 0));
    }
};



void show();
void solve();
