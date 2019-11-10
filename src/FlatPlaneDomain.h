#ifndef FLATPLANEDOMAIN_H
#define FLATPLANEDOMAIN_H

#include "InternalNode.h"

#include "NorthBoundary.h"
#include "SouthBoundary.h"
#include "EastBoundary.h"
#include "WestBoundary.h"

class FlatPlaneDomain
{
public:
	FlatPlaneDomain(double flatPlateThickness, double flatPlateLength, double freestreamU, double freestreamV, double domainHeight, double domainLength,
		double dx, double dy);
	~FlatPlaneDomain();


public:
	const size_t cNNodesHor;
	const size_t cNNodesVer;
	const size_t cTopLimit;
	const size_t cBotStart;
	const size_t cLeftLimit;
	const size_t cRightStart;
	const size_t cFlatPlaneBottom;
	const size_t cFlatPlaneRight;
	
	std::vector<InternalNode*> cInternalNodesLeft;
	std::vector<InternalNode*> cInternalNodesTop;
	std::vector<InternalNode*> cInternalNodesBottom;
	std::vector<InternalNode*> cInternalNodesRight;

	std::vector<NorthBoundary*> cFreestreamTop;
	std::vector<SouthBoundary*> cFreestreamBottom;
	std::vector<EastBoundary*> cFreestreamLeft;
	std::vector<WestBoundary*> cFreestreamRight;

	std::vector<WestBoundary*> cFlatPlaneEastBoundary;
	std::vector<EastBoundary*> cFlatPlaneWestBoundary;
	std::vector<SouthBoundary*> cFlatPlaneNorthBoundary;
	std::vector<NorthBoundary*> cFlatPlaneSouthBoundary;

};

#endif