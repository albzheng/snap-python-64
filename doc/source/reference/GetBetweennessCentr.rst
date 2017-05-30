GetBetweennessCentr
'''''''''''''''''''

.. function:: GetBetweennessCentr(Graph, NIdBtwH, EdgeBtwH, NodeFrac=1.0, IsDir=False)

Computes (approximate) Node and Edge Betweenness Centrality based on a sample of *NodeFrac* nodes.

Parameters:

- *Graph*: graph (input)
    A Snap.py graph or a network.

- *NIdBtwH*: :class:`TIntFlt64H`, a hash table with int keys and float values (output)
    Hash table mapping node ids to their corresponding betweenness centrality values.

- *EdgeBtwH*: :class:`TIntPrFlt64H`, a hash table with int pair keys and float values (output)
    Hash table mapping edges (provided as pairs of node ids) to their corresponding betweenness centrality values.

- *NodeFrac*: float (input)
    Quality of the approximation. NodeFrac=1.0 gives exact betweenness values.

- *IsDir*: bool (input)
    Indicates whether the edges should be considered directed (*True*) or undirected (*False*).

Return Value:

- None

See "A Faster Algorithm for Betweenness Centrality", Ulrik Brandes, Journal of Mathematical Sociology, 2001, and "Centrality Estimation in Large Networks", Urlik Brandes and Christian Pich, 2006 for more details. 


The following example shows how to calculate Betweenness Centrality scores for nodes and edges in
:class:`TNGraph`,
:class:`TUNGraph`, and
:class:`TNEANet`::

    import snap

    Graph = snap.GenRndGnm(snap.PNGraph, 100, 1000)
    Nodes = snap.TIntFlt64H()
    Edges = snap.TIntPrFlt64H()
    snap.GetBetweennessCentr(Graph, Nodes, Edges, 1.0)
    for node in Nodes:
        print "node: %d centrality: %f" % (node, Nodes[node])
    for edge in Edges:
        print "edge: (%d, %d) centrality: %f" % (edge.GetVal1(), edge.GetVal2(), Edges[edge])

    UGraph = snap.GenRndGnm(snap.PUNGraph, 100, 1000)
    Nodes = snap.TIntFlt64H()
    Edges = snap.TIntPrFlt64H()
    snap.GetBetweennessCentr(UGraph, Nodes, Edges, 1.0)
    for node in Nodes:
        print "node: %d centrality: %f" % (node, Nodes[node])
    for edge in Edges:
        print "edge: (%d, %d) centrality: %f" % (edge.GetVal1(), edge.GetVal2(), Edges[edge])

    Network = snap.GenRndGnm(snap.PNEANet, 100, 1000)
    Nodes = snap.TIntFlt64H()
    Edges = snap.TIntPrFlt64H()
    snap.GetBetweennessCentr(Network, Nodes, Edges, 1.0)
    for node in Nodes:
        print "node: %d centrality: %f" % (node, Nodes[node])
    for edge in Edges:
        print "edge: (%d, %d) centrality: %f" % (edge.GetVal1(), edge.GetVal2(), Edges[edge])




