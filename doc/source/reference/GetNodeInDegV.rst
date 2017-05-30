GetNodeInDegV
'''''''''''''''

.. function:: GetNodeInDegV(Graph, NIdInDegV)

Computes the in-degree for every node in *Graph*. 
The result is stored in *NIdInDegV*, a vector of pairs (node id, node in degree).

Parameters:

- *Graph*: graph (input)
	A Snap.py graph or a network.

- *NIdInDegV*: :class:`TIntPr64V`, a vector or (int, int) pairs (output)
	A vector of (node id, node in-degree) pairs.

Return value:

- None


The following example shows how to use :func:`GetNodeInDegV` with nodes in :class:`TNGraph`, :class:`TUNGraph`, and :class:`TNEANet`::

    import snap

    Graph = snap.GenRndGnm(snap.PNGraph, 100, 1000)
    InDegV = snap.TIntPr64V()
    snap.GetNodeInDegV(Graph, InDegV)
    for item in InDegV:
        print "node ID %d: in-degree %d" % (item.GetVal1(), item.GetVal2())

    UGraph = snap.GenRndGnm(snap.PUNGraph, 100, 1000)
    InDegV = snap.TIntPr64V()
    snap.GetNodeInDegV(UGraph, InDegV)
    for item in InDegV:
        print "node ID %d: in-degree %d" % (item.GetVal1(), item.GetVal2())

    Network = snap.GenRndGnm(snap.PNEANet, 100, 1000)
    InDegV = snap.TIntPr64V()
    snap.GetNodeInDegV(Network, InDegV)
    for item in InDegV:
        print "node ID %d: in-degree %d" % (item.GetVal1(), item.GetVal2())
