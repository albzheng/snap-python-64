#include <time.h>

namespace TSnap {

typedef TVec<TInt, int> TIntV;
typedef TVec<TIntV, int> TIntIntVV;
typedef THash<TInt, TVec< TInt, int> > TIntIntVH;
typedef TVec<TInt64, int64> TInt64V;
typedef TVec<TInt64V, int64> TIntInt64VV;
typedef THash<TInt64, TVec< TInt64, int64>, int64 > TIntInt64VH;
//typedef THash<TInt, TInt> TIntH;

void SeedRandom() {
  long int64 ITime;
  long int64 IPid;
  long int64 RSeed;

  ITime = (long int64) time(NULL);
  IPid = (long int64) getpid();

  RSeed = ITime * IPid;
  srand48(RSeed);
}

void Randomize(TInt64V& Vec) {
  int64 Pos;
  int64 Last = Vec.Len() - 1;
  for (int64 ValN = Last; ValN > 0; ValN--) {
    Pos = (long) (drand48() * ValN);
    Vec.Swap(ValN, Pos);
  }
}

int64 StdDist(double Mean, double Dev) {
  int64 i;
  double x;

  x = -6.0;
  for (i = 0; i < 12; i++) {
    x += drand48();
  }

  x *= Dev;
  x += Mean;

  return int64(x + 0.5);
}

#if 0
void GetDegrees(TIntV* Nodes, double Mean, double Dev) {
  int i;
  int d;
  int Len;
  printf("GetDegrees\n");
  printf("Nodes Len %d\n",Nodes->Len());

  Len = Nodes->Len();
  for (i = 0; i < Len; i++) {
    d = StdDist(Mean, Dev);
    printf("degree1 %d %d\n", i, d);
    (*Nodes)[i] = d;
  }

  for (i = 0; i < Len; i++) {
    printf("degree2 %d %d\n", i, Nodes->GetVal(i).Val);
  }
}
#endif

void GetDegrees(TInt64V& Nodes, double Mean, double Dev) {
  int64 i;
  int64 d;
  int64 Len;
  printf("GetDegrees\n");
  printf("Nodes Len %d\n",Nodes.Len());

  // assign degree to each node
  Len = Nodes.Len();
  for (i = 0; i < Len; i++) {
    d = StdDist(Mean, Dev);
    printf("degree1 %d %d\n", i, d);
    Nodes[i] = d;
  }

  for (i = 0; i < Len; i++) {
    printf("degree2 %d %d\n", i, Nodes[i].Val);
  }
}

void IncVal(TInt64V& Nodes, int64 disp) {
  int64 i;
  int64 Len;

  // increment value for each element
  Len = Nodes.Len();
  for (i = 0; i < Len; i++) {
    Nodes[i] += disp;
  }
}

void AssignRndTask(const TInt64V& Nodes, TIntInt64VV& Tasks) {
  int64 i;
  int64 j;
  int64 n;
  int64 t;
  int64 NumNodes;
  int64 NumTasks;
  printf("AssignRndTask\n");
  printf("Nodes Len %d\n",Nodes.Len());
  printf("Tasks Len %d\n",Tasks.Len());

  NumNodes = Nodes.Len();
  NumTasks = Tasks.Len();

  // distribute stubs randomly to tasks
  for (i = 0; i < NumNodes; i++) {
    n = Nodes[i].Val;
    printf("degree3 %d %d\n", i, n);
    for (j = 0; j < n; j++) {
      t = (long) (drand48() * NumTasks);
      Tasks[t].Add(i);
    }
  }
}

void AssignEdges(const TInt64V& Pairs, TIntInt64VV& Tasks, int64 tsize) {
  int64 i;
  int64 NumStubs;
  int64 NumTasks;
  int64 TaskId;
  int64 Node1;
  int64 Node2;

  printf("AssignEdges\n");
  printf("Pairs Len %d\n",Pairs.Len());
  printf("Tasks Len %d\n",Tasks.Len());

  NumStubs = Pairs.Len();
  NumTasks = Tasks.Len();

  // distribute edges to tasks
  for (i = 0; i < NumStubs-1; i += 2) {

    Node1 = Pairs.GetVal(i).Val;
    Node2 = Pairs.GetVal(i+1).Val;

    // add an edge twice, once for each end node
    TaskId = Node1 / tsize;
    Tasks[TaskId].Add(Node1);
    Tasks[TaskId].Add(Node2);

    TaskId = Node2 / tsize;
    Tasks[TaskId].Add(Node2);
    Tasks[TaskId].Add(Node1);
  }
}

void GetAdjLists(const TInt64V& Edges, TIntInt64VH& AdjLists) {
  int64 i;
  int64 NumStubs;
  int64 Node1;
  int64 Node2;

  printf("GetAdjLists\n");
  printf("Edges1 Len %d\n",Edges.Len());

  NumStubs = Edges.Len();

  // distribute node pairs to adjacency lists
  for (i = 0; i < NumStubs-1; i += 2) {
    Node1 = Edges.GetVal(i).Val;
    Node2 = Edges.GetVal(i+1).Val;

    AdjLists.AddKey(Node1);
    AdjLists(Node1).AddMerged(Node2);
  }
}

void GetNeighborhood(const TInt64V& Nodes, const TIntInt64VH& AdjLists, TInt64V& Hood) {
  int64 i;
  int64 j;
  int64 Node;
  int64 NumNodes;
  int64 NumNeighbors;
  int64 Neighbor;
  TInt64H HashHood;
  TInt64V Neighbors;

  NumNodes = Nodes.Len();

  // create a union of all neighbors
  for (i = 0; i < NumNodes; i++) {
    Node = Nodes.GetVal(i).Val;
    Neighbors = AdjLists.GetDat(Node);
    NumNeighbors = Neighbors.Len();
    for (j = 0; j < NumNeighbors; j++) {
      Neighbor = Neighbors.GetVal(j).Val;
      HashHood.AddDat(Neighbor,0);
    }
  }

  // change a hash table to a vector
  HashHood.GetKeyV(Hood);
}
  

void Edge2Hash(const TInt64V& Edges, TInt64H& Hash) {
  int64 i;
  int64 Num;
  int64 Key;
  int64 Value;

  printf("Edges2 Len %d\n",Edges.Len());
  Num = Edges.Len();

  for (i = 0; i < Num-1; i += 2) {
    Key = Edges.GetVal(i).Val;
    Value = Edges.GetVal(i+1).Val;

    Hash.AddDat(Key, Value);
  }
}

}; // namespace TSnap

