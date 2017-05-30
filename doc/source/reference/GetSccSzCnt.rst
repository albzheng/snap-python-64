GetSccSzCnt
'''''''''''

.. function:: GetSccSzCnt(Graph, SccSzCnt)

Returns a distribution of strongly connected component sizes.

Parameters:

- *Graph*: graph (input)
	A Snap.py graph or a network.

- *SccSzCnt*: :class:`TIntPr64V`, a vector of (int, int) pairs (output)
    Vector of pairs (number of nodes in the component, number of such components).

Return Value:

- None


The following example shows how to get the distribution of strongly-connected component sizes in
:class:`TNGraph`, :class:`TUNGraph`, and :class:`TNEANet`::

	import snap

	Graph = snap.GenRndGnm(snap.PNGraph, 100, 1000)
	ComponentDist = snap.TIntPr64V()
	snap.GetSccSzCnt(Graph, ComponentDist)
	for comp in ComponentDist:
	    print "Size: %d - Number of Components: %d" % (comp.GetVal1(), comp.GetVal2())

	UGraph = snap.GenRndGnm(snap.PUNGraph, 100, 1000)
	ComponentDist = snap.TIntPr64V()
	snap.GetSccSzCnt(UGraph, ComponentDist)
	for comp in ComponentDist:
	    print "Size: %d - Number of Components: %d" % (comp.GetVal1(), comp.GetVal2())

	Network = snap.GenRndGnm(snap.PNEANet, 100, 1000)
	ComponentDist = snap.TIntPr64V()
	snap.GetSccSzCnt(Network, ComponentDist)
	for comp in ComponentDist:
	    print "Size: %d - Number of Components: %d" % (comp.GetVal1(), comp.GetVal2())
