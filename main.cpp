#include <iostream>
#include "graph.h"

int main(){
Graph g;
Node zero;
zero.SetAList(0, 1, 1, 0, 0, 0, 1, 0, 0);
g.AddNode(&zero);
Node one;
one.SetAList(0, 0, 0, 1, 0, 0, 0, 0, 0);
g.AddNode(&one);
Node two;
two.SetAList(1, 0, 0, 1, 1, 0, 0, 0, 0);
g.AddNode(&two);
Node three;
three.SetAList(0, 0, 0, 0, 0, 0, 1, 0, 0);
g.AddNode(&three);
Node four;
four.SetAList(1, 0, 0, 0, 0, 1, 0, 0, 1);
g.AddNode(&four);
Node five;
five.SetAList(0, 0, 1, 1, 1, 0, 0, 1, 0);
g.AddNode(&five);
Node six;
six.SetAList(0, 0, 0, 0, 0, 0, 0, 1, 0);
g.AddNode(&six);
Node seven;
seven.SetAList(0, 0, 0, 1, 0, 0, 0, 0, 1);
g.AddNode(&seven);
Node eight;
eight.SetAList(0, 0, 0, 0, 0, 1, 0, 0, 0);
g.AddNode(&eight);
g.Print();

printf("\n\n");
g.Breitensuche();

printf("\n\n");
g.Tiefensuche();

return 0;
}
