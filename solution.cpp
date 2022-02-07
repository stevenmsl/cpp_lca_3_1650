#include "solution.h"

#include <functional>
#include <unordered_set>
using namespace sol1650;
using namespace std;

/*takeaways
  - build an unordered set out of p's ancestors
    (or q - it really doesn't matter)
  - walk up the tree from q - this is how
    we can make sure we find the lca of p
    and q.
  - search p's ancestors set to find a match
    - we don't really know q's ancestors
      in relation to p's so we need to
      scan p's ancestor set again every time
      we walk up the tree to find q's next
      ancestor
    - let's why an unordered set is sufficient

*/

Node *Solution::lca(Node *tree, Node *p, Node *q)
{
  unordered_set<Node *> pas;
  /*
    - walk up the tree from p to
      build a ancestor set
  */
  auto t = p;
  while (t != nullptr)
  {
    pas.insert(t);
    t = t->parent;
  }

  /*
    - walk up the tree from q;
      this is how we make sure
      the ancestor we found is
      a lca
  */
  t = q;
  while (t != nullptr)
  {
    /*
      - scan p's ancestor set to find a match
    */
    if (pas.count(t))
      return t;
    t = t->parent;
  }

  return nullptr;
}