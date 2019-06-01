#ifndef GRAPH.H
#define GRAPH.H

#include <iostream>
#include <queue>

using namespace std;

#define n 9

enum colour {white, grey, black};
int number = 0;
int time = 1;

class Node{
private:
    enum colour col;
    int dist;
    int alist[n] = {0};
    Node *pred;
    int nmbr;
    int firsttime;
    int lasttime;
public:
    Node();
    void PrintColour();
    void SetAList(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9);
    void Print();
    int GetColour();
    void SetColour(enum colour newcol);
    int GetNeighbour(int i);
    int GetNumber();
    void SetDist(int i);
    int GetDist();
    void SetPred(Node *newpred);
    void SetFirsttime();
    int GetFirsttime();
    void SetLasttime();
    int GetLasttime();
};


class Graph{
private:
    Node* nodes[n] = {0};

public:
    void AddNode(Node* newn);
    void Print();
    void Breitensuche();
    void Tiefensuche();
    void DFSVisit(Node *u);
};

Node::Node(){
   col = white;
   dist = 100;
   pred = NULL;
   nmbr = number;
   number++;
}

void Node::PrintColour(){
printf("Colour: %d", col);
}

/*void Node::SetAList(int *newlist){
    for(int i = 0; i <= n; i++){
        alist[i] = newlist[i];
    }
}*/

void Node::SetColour(enum colour newcol){
col = newcol;
}

int Node::GetColour(){
return col;
}

int Node::GetNeighbour(int i){
return alist[i];
}

int Node::GetNumber(){
return nmbr;
}

void Node::SetDist(int i){
dist = i;
}

int Node::GetDist(){
return dist;
}

void Node::SetPred(Node *newpred){
pred = newpred;
}

void Node::SetFirsttime(){
firsttime = time;
time++;
}

int Node::GetFirsttime(){
return firsttime;
}

void Node::SetLasttime(){
lasttime = time;
time++;
}

int Node::GetLasttime(){
return lasttime;
}

void Node::SetAList(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9){
    alist[0] = n1;
    alist[1] = n2;
    alist[2] = n3;
    alist[3] = n4;
    alist[4] = n5;
    alist[5] = n6;
    alist[6] = n7;
    alist[7] = n8;
    alist[8] = n9;
}

void Node::Print(){
    for(int i = 0; i < n; i++){
        printf("%d  ", alist[i]);
    }
}

void Graph::AddNode(Node* newn){
int i = 0;
    while(nodes[i] != 0){
        i++;
    }
    nodes[i] = newn;
}

void Graph::Print(){
 for(int i = 0; i < n; i++){
        printf("%d: ", i);
        nodes[i]->Print();
        printf("\n");
    }
}

void Graph::Breitensuche(){
Node u;
queue<Node> Q;
nodes[0]->SetDist(0);
nodes[0]->SetColour(grey);
Q.push(*nodes[0]);
    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        printf("v%d dist:%d     ", u.GetNumber(), u.GetDist());
        for(int i = 0; i < n; i++){
            if((u.GetNeighbour(i) == 1) && (nodes[i]->GetColour() == white)){
                nodes[i]->SetColour(grey);
                nodes[i]->SetDist(u.GetDist() + 1);
                nodes[i]->SetPred(&u);
                Q.push(*nodes[i]);
            }
        }
        u.SetColour(black);
    }
}

void Graph::DFSVisit(Node *u){
u->SetFirsttime();
u->SetColour(grey);
  for(int i = 0; i < n; i++){
        if((u->GetNeighbour(i) == 1) && (nodes[i]->GetColour() == white)){
            nodes[i]->SetPred(u);
            DFSVisit(nodes[i]);
        }
    }
   u->SetColour(black);
   u->SetLasttime();
   printf("v%d firsttime:%d lasttime:%d         ", u->GetNumber(), u->GetFirsttime(), u->GetLasttime());
}

void Graph::Tiefensuche(){
  for(int i = 0; i < n; i++){
      if(nodes[i]->GetColour() == white){
          DFSVisit(nodes[i]);
      }
  }
}

#endif
