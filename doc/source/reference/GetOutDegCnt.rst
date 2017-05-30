GetOutDegCnt
''''''''''''

.. function:: GetOutDegCnt(Graph, DegToCntV)

Computes an out-degree histogram: a vector of pairs (out-degree, number of nodes of such out-degree). The results are stored in *DegToCntV*.

Parameters:

- *Graph*: graph (input)
    A Snap.py graph or a network.

- *DegToCntV*: :class:`TIntPr64V`, a vector of (int, int) pairs (output)
    A vector of (out-degree, number of nodes of such out-degree) pairs.

Return value:

- None


The following examples shows how to obtain the out-degree histogram for nodes in :class:`TNGraph`, :class:`TUNGraph`, and :class:`TNEANet`::

    import snap

    Graph = snap.GenRndGnm(snap.PNGraph, 100, 1000)
    DegToCntV = snap.TIntPr64V()
    snap.GetOutDegCnt(Graph, DegToCntV)
    for item in DegToCntV:
        print "%d nodes with out-degree %d" % (item.GetVal2(), item.GetVal1())

    UGraph = snap.GenRndGnm(snap.PUNGraph, 100, 1000)
    DegToCntV = snap.TIntPr64V()
    snap.GetOutDegCnt(UGraph, DegToCntV)
    for item in DegToCntV:
        print "%d nodes with out-degree %d" % (item.GetVal2(), item.GetVal1())

    Network = snap.GenRndGnm(snap.PNEANet, 100, 1000)
    DegToCntV = snap.TIntPr64V()
    snap.GetOutDegCnt(Network, DegToCntV)
    for item in DegToCntV:
        print "%d nodes with out-degree %d" % (item.GetVal2(), item.GetVal1())
