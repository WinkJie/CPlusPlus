#pragma once

#include "PublicHeader.h"
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*面试题餐馆问题*/

class CanGuanProcess
{
public:
	

public:

    vector<int > global = {0};
    int Do();
    struct node
    {
        int x;
        int y;
    };
    static bool mycomp(node a, node b);
    long long  maxprofit(vector<int>n_num, vector<node>m_num);

public:
    void vec();



};

