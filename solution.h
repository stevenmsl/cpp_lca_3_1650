
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <stack>
#include <string>
using namespace std;
namespace sol1650
{
    class Solution
    {
    private:
    public:
        Node *lca(Node *tree, Node *p, Node *q);
    };
}
#endif