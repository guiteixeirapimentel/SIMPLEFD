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
	
	std::vector<InternalNode*> cInternalPNodesLeft;
	std::vector<InternalNode*> cInternalPNodesTop;
	std::vector<InternalNode*> cInternalPNodesBottom;
	std::vector<InternalNode*> cInternalPNodesRight;

	std::vector<InternalNode*> cInternalVNodesLeft;
	std::vector<InternalNode*> cInternalVNodesTop;
	std::vector<InternalNode*> cInternalVNodesBottom;
	std::vector<InternalNode*> cInternalVNodesRight;

	std::vector<NorthBoundary*> cFreestreamBPressureTop;
	std::vector<SouthBoundary*> cFreestreamBPressureBottom;
	std::vector<EastBoundary*> cFreestreamBPressureLeft;
	std::vector<WestBoundary*> cFreestreamBPressureRight;

	std::vector<NorthBoundary*> cFreestreamVPressureTop;
	std::vector<SouthBoundary*> cFreestreamVPressureBottom;
	std::vector<EastBoundary*> cFreestreamVPressureLeft;
	std::vector<WestBoundary*> cFreestreamVPressureRight;

	std::vector<WestBoundary*> cFlatPlanePEastBoundary;
	std::vector<EastBoundary*> cFlatPlanePWestBoundary;
	std::vector<SouthBoundary*> cFlatPlanePNorthBoundary;
	std::vector<NorthBoundary*> cFlatPlanePSouthBoundary;

	std::vector<WestBoundary*> cFlatPlaneVEastBoundary;
	std::vector<EastBoundary*> cFlatPlaneVWestBoundary;
	std::vector<SouthBoundary*> cFlatPlaneVNorthBoundary;
	std::vector<NorthBoundary*> cFlatPlaneVSouthBoundary;
};

#endif