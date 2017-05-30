GetLen2Paths
''''''''''''
.. note::

    This page is a draft and under revision.


.. function:: GetLen2Paths (Graph, NId1, NId2, NbrV)

.. note::

    This function is not yet supported.

Return the number of length 2 paths between a pair of nodes.

Parameters:

- *Graph*: graph (input)
    A Snap.py graph or a network

- *NId1*: int (input)
    ID of the source node

- *NId2*: int (input)
    ID of the destination node

- *NbrV*: TInt64V (input)
    List of nodes on each path between node NId1 and node NId2. The list is filled by the function.

Return value:

- Number of length 2 paths between a pair of nodes.

The following example shows how to use GetLen2Paths in :class:`PUNGraph`, :class:`PNGraph`, and :class:`PNEANet` 
(**NOTE**: at the time this document was written, GetLen2Paths is not implemented yet so the author could not verify the code)::

    import snap

    g = snap.GenRndGnm(snap.PUNGraph, 100, 1000)
    middle_nodes = snap.TInt64V()
    print snap.GetLen2Paths(g, 0, 1, middle_nodes)

    g = snap.GenRndGnm(snap.PNGraph, 100, 1000)
    middle_nodes = snap.TInt64V()
    print snap.GetLen2Paths(g, 0, 1, middle_nodes)

    g = snap.GenRndGnm(snap.PNEANet, 100, 1000)
    middle_nodes = snap.TInt64V()
    print snap.GetLen2Paths(g, 0, 1, middle_nodes)
