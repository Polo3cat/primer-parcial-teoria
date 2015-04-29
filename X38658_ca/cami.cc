#include "Arbre.hh"
#include <stack>

using namespace std;

stack<int> cami_pref_aux(Arbre<int>& a);

void cami_preferent (Arbre<int>& a, stack<int>& c)
{
  c = cami_pref_aux(a);
}

stack<int> cami_pref_aux (Arbre<int>& a)
{
  stack<int> x, y, z;
  Arbre<int> e, d;
  if (not a.es_buit())
    a.fills(e, d);
    x = cami_pref_aux(e);
    y = cami_pref_aux(d);
    if (x.size() >= y.size())
      z = x;
    else
      z = y;
    z.push(a.arrel());
  }
  return z;
}