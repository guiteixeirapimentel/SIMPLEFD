#include <iostream>
#include <vector>
#include <fstream>

#include "EastBoundary.h"
#include "WestBoundary.h"
#include "NorthBoundary.h"
#include "SouthBoundary.h"

#include "InternalNode.h"

int main()
{
    const double flatPlateThickness = 1.0;
    const double flatPlateLength = 1.0;

    const double freestreamU = 1.0;
    const double freestreamV = 0.0;

    const double domainHeight = 10.0;
    const double domainLength = 10.0;

    // Garantindo Courant-Number até vel dez x maior.
    const double dx = 0.01; 
    const double dy = 0.01;
    const double dt = 0.001*1.0/( (10.0*freestreamU/dx) + (10.0*freestreamU /dy) );
    const double simTime = 0.01;

    size_t nIterTime = simTime / dt;
    
    size_t numberX = domainLength/dx;
    size_t numberY = domainHeight/dy;

    std::vector<InternalNode*> internFieldLeft;
    std::vector<InternalNode*> internFieldTop;
    std::vector<InternalNode*> internFieldBottom;
    std::vector<InternalNode*> internFieldRight;

    const size_t toplimit = size_t((numberY / 2) - (flatPlateThickness/(dy*2.0)))-1;
    const size_t botstart = size_t((numberY / 2) + (flatPlateThickness/(dy*2.0)));
    const size_t leftLimit = size_t((numberX/2) - (flatPlateLength/(dx*2.0)))-1;
    const size_t rightStart = size_t((numberX/2) + (flatPlateLength/(dx*2.0)));

    internFieldTop.resize(numberX * toplimit);
    for(size_t i = 0; i < toplimit; i++)
    {
        for(size_t j = 0; j < numberX; j++)
        {
            const double y = (i * dy)+dy;
        
            const double x = (j * dx)+dx;

            internFieldTop[j + (i * numberX)] = new InternalNode(x, y, 0.0);
        }
    }

    internFieldBottom.resize(numberX * (numberY - botstart));
    for(size_t i = botstart; i < numberY; i++)
    {
        for(size_t j = 0; j < numberX; j++)
        {            
            const double y = (i * dy)+dy;
        
            const double x = (j * dx)+dx;
                    
            internFieldBottom[j + ((i-botstart) * numberX)] = new InternalField(x, y, 0.0, 0.0, 0.0);
        }
    }

    internFieldLeft.resize(leftLimit * (botstart - toplimit));

    for(size_t i = toplimit; i < botstart; i++)
    {
        for(size_t j = 0; j < leftLimit; j++)
        {            
            const double y = (i * dy)+dy;
        
            const double x = (j * dx)+dx;
                    
            internFieldLeft[j + ((i-toplimit) * leftLimit)] = new InternalField(x, y, 0.0, 0.0, 0.0);
         
        }
    }

    internFieldRight.resize((numberX - rightStart) * (botstart - toplimit));
    
    for(size_t i = toplimit; i < botstart; i++)
    {
        for(size_t j = rightStart; j < numberX; j++)
        {            
            const double y = (i * dy)+dy;
        
            const double x = (j * dx)+dx;
                    
            internFieldRight[(j-rightStart) + (((i-toplimit) * (numberX-rightStart)))] = new InternalField(x, y, 0.0, 0.0, 0.0);
        }
    }
    
    std::vector<NorthBoundary*> freestreamBoundaryTop;
    freestreamBoundaryTop.resize(numberX);

    std::vector<SouthBoundary*> freestreamBoundaryBottom;
    freestreamBoundaryBottom.resize(numberX);    

    for(size_t j = 0; j < numberX; j++)
    {
        freestreamBoundaryTop[j] = new NorthBoundary((j*dx)+dx, 0.0, freestreamU, freestreamV,
         0.0, BoundaryField::FIXEDVALUE);

        freestreamBoundaryTop[j]->SetSouthNode(internFieldTop[j]);

        freestreamBoundaryBottom[j] = new SouthBoundary((j*dx)+dx, domainHeight + dy, freestreamU, freestreamV, 
        0.0, BoundaryField::FIXEDVALUE);

        freestreamBoundaryBottom[j]->SetNorthNode(internFieldBottom[j + ((numberY-botstart - 1) * numberX)]);
    }  

    std::vector<WestBoundary*> freestreamBoundaryLeft;
    freestreamBoundaryLeft.resize(numberY);
    std::vector<EastBoundary*> freestreamBoundaryRight;
    freestreamBoundaryRight.resize(numberY);

    for(size_t i = 1; i < numberY+1; i++)
    {
        if(i <= toplimit)
        {
            freestreamBoundaryLeft[i - 1] = new WestBoundary(0.0, i*dy, freestreamU, freestreamV, 0.0, 
             BoundaryField::FIXEDVALUE);

            freestreamBoundaryLeft[i-1]->SetEastNode(internFieldTop[0 + (((i-1) * numberX))]);

            freestreamBoundaryRight[i - 1] = new EastBoundary(domainLength + dx, i*dy, freestreamU, freestreamV, 0.0,
             BoundaryField::ZEROGRADIENT);     

            freestreamBoundaryRight[i-1]->SetWestBoundary(internFieldTop[(numberX-1) + ((i-1) * (numberX))]);

        }
        else if(i > botstart)
        {
            freestreamBoundaryLeft[i - 1] = new WestBoundary(0.0, i*dy, freestreamU, freestreamV, 0.0, 
             BoundaryField::FIXEDVALUE);

            freestreamBoundaryLeft[i-1]->SetEastNode(internFieldBottom[0 + (((i- botstart-1) * numberX))]);

            freestreamBoundaryRight[i - 1] = new EastBoundary(domainLength + dx, i*dy, freestreamU, freestreamV, 0.0,
             BoundaryField::ZEROGRADIENT);     

            freestreamBoundaryRight[i-1]->SetWestBoundary(internFieldBottom[(numberY - 1) + ((i-botstart-1) * (numberX))]);
        }
        else 
        {
            freestreamBoundaryLeft[i - 1] = new WestBoundary(0.0, i*dy, freestreamU, freestreamV, 0.0, 
            BoundaryField::FIXEDVALUE);

            freestreamBoundaryLeft[i-1]->SetEastNode(internFieldLeft[0 + (((i-toplimit-1) * leftLimit))]);

            freestreamBoundaryRight[i - 1] = new EastBoundary(domainLength + dx, i*dy, freestreamU, freestreamV, 0.0,
             BoundaryField::ZEROGRADIENT);     

            freestreamBoundaryRight[i-1]->SetWestBoundary(internFieldRight[(numberX - rightStart-1) + ((i-toplimit-1) * (numberX - rightStart))]);

        }
        
    }     

    std::vector<WestBoundary*> flatPlaneEastBoundary;
    std::vector<EastBoundary*> flatPlaneWestBoundary;
    std::vector<SouthBoundary*> flatPlaneNorthBoundary;
    std::vector<NorthBoundary*> flatPlaneSouthBoundary; 

    const size_t flatPlaneBottom = (flatPlateThickness/dy)+1;
    const size_t flatPlaneRight = (flatPlateLength/dx) - 1;

    flatPlaneEastBoundary.resize(flatPlaneBottom);
    flatPlaneWestBoundary.resize(flatPlaneBottom);

    flatPlaneNorthBoundary.resize(flatPlaneRight);
    flatPlaneSouthBoundary.resize(flatPlaneRight);

    for(size_t j = 0; j < flatPlaneRight; j++)
    {
        const double x = (((j+leftLimit)*dx) + dx + dx);
        const double ynorth = ((toplimit*dy) + dy);
        const double ysouth = ((toplimit+flatPlaneBottom)*dy);

        flatPlaneNorthBoundary[j] = new SouthBoundary(x, ynorth, 0.0, 0.0, 0.0, 
        BoundaryField::ZEROGRADIENTNOSLIP);

		flatPlaneNorthBoundary[j]->SetNorthNode(internFieldTop[j + leftLimit + 1 + (numberX*(toplimit - 1))]);

        flatPlaneSouthBoundary[j] = new NorthBoundary(x, ysouth, 0.0, 0.0, 0.0, 
        BoundaryField::ZEROGRADIENTNOSLIP);

		flatPlaneSouthBoundary[j]->SetSouthNode(internFieldBottom[j + leftLimit + 1]);
    }

    for(size_t i = 0; i < flatPlaneBottom; i++)
    {
        const double xeast = (((leftLimit+flatPlaneRight)*dx) + dx+dx);
        const double xwest = ((leftLimit*dx) + dx);

        const double y = ((i+toplimit)*dy) + dy;

        flatPlaneWestBoundary[i] = new EastBoundary(xwest, y, 0.0, 0.0, 0.0, 
        BoundaryField::ZEROGRADIENTNOSLIP);

		flatPlaneWestBoundary[i]->SetWestBoundary(internFieldLeft[leftLimit - 1 + (i * leftLimit)]);

        flatPlaneEastBoundary[i] = new WestBoundary(xeast, y, 0.0, 0.0, 0.0, 
        BoundaryField::ZEROGRADIENTNOSLIP);
		
		flatPlaneEastBoundary[i]->SetEastNode(internFieldRight[0 + (i * (numberX - rightStart))]);
	}

    // SET NEIGHBOURS INTERNALFIELD

    // NORTH PART

    for(size_t i = 0; i < toplimit; i++)
    {
        for(size_t j = 0; j < numberX; j++)
        {
            // north Node
            if(i != 0)
            {                
                internFieldTop[j + (i * numberX)]->SetNorthNode(internFieldTop[j + ((i -1)*numberX)]);
            }
            else
            {
                internFieldTop[j + (i * numberX)]->SetNorthNode(freestreamBoundaryTop[j]);
            }
            
            // south Node
            if((i != toplimit -1 ))
            {
                internFieldTop[j + (i * numberX)]->SetSouthNode(internFieldTop[j + ((i + 1)*numberX)]);
            }
            else if (j < leftLimit)
            {
                internFieldTop[j + (i * numberX)]->SetSouthNode(internFieldLeft[j]);
            }
            else if (j >= rightStart)
            {
                internFieldTop[j + (i * numberX)]->SetSouthNode(internFieldRight[j - rightStart]);                
            }            
            else
            {
                if(j == leftLimit)
                    internFieldTop[j + (i * numberX)]->SetSouthNode(flatPlaneWestBoundary[0]);                    
                else if (j == rightStart -1)
                    internFieldTop[j + (i * numberX)]->SetSouthNode(flatPlaneEastBoundary[0]);
                else
                    internFieldTop[j + (i * numberX)]->SetSouthNode(flatPlaneNorthBoundary[j - leftLimit-1]);
            }                          

            // West Node
            if(j != 0)
            {
                internFieldTop[j + (i * numberX)]->SetWestNode(internFieldTop[(j-1) + ((i)*numberX)]);
            }
            else
            {
                internFieldTop[j + (i * numberX)]->SetWestNode(freestreamBoundaryLeft[i]);
            }
            
            // East Node
            if(j != numberX - 1)
            {
                internFieldTop[j + (i * numberX)]->SetEastNode(internFieldTop[(j+1) + ((i)*numberX)]);
            }
            else
            {
                 internFieldTop[j + (i * numberX)]->SetEastNode(freestreamBoundaryRight[i]);
            }
        }
    }
    //BOTTOM PART
    for(size_t i = 0; i < numberY-botstart; i++)
    {
        for(size_t j = 0; j < numberX; j++)
        {            
            // north Node
            if((i != 0))
            {
                internFieldBottom[j + (i * numberX)]->SetNorthNode(internFieldBottom[j + ((i - 1)*numberX)]);
            }
            else if (j < leftLimit)
            {
                internFieldBottom[j + (i * numberX)]->SetNorthNode(internFieldLeft[j + (leftLimit * (botstart-toplimit-1))]);
            }
            else if (j >= rightStart)
            {
                internFieldBottom[j + (i * numberX)]->SetNorthNode(internFieldRight[j - rightStart + ((numberX - rightStart) * (botstart-toplimit-1))]);                
            }            
            else
            {
                if(j == leftLimit)
                    internFieldBottom[j + (i * numberX)]->SetNorthNode(flatPlaneWestBoundary.back());                    
                else if (j == rightStart -1)
                    internFieldBottom[j + (i * numberX)]->SetNorthNode(flatPlaneEastBoundary.back());
                else
                    internFieldBottom[j + (i * numberX)]->SetNorthNode(flatPlaneSouthBoundary[j - leftLimit-1]);
            }
            
            // south Node
            if((i != numberY - botstart - 1))
            {
                internFieldBottom[j + (i * numberX)]->SetSouthNode(internFieldBottom[j + ((i +1)*numberX)]);
            }
            else
            {
                internFieldBottom[j + (i * numberX)]->SetSouthNode(freestreamBoundaryBottom[j]);
            }
            

            // West Node
            if(j != 0)
            {
                internFieldBottom[j + (i * numberX)]->SetWestNode(internFieldBottom[(j-1) + ((i)*numberX)]);
            }
            else
            {
                internFieldBottom[j + (i * numberX)]->SetWestNode(freestreamBoundaryLeft[i + botstart]);
            }
            
            // East Node
            if(j != numberX -1)
            {
                internFieldBottom[j + (i * numberX)]->SetEastNode(internFieldBottom[j+1 + ((i)*numberX)]);
            }
            else
            {
                 internFieldBottom[j + (i * numberX)]->SetEastNode(freestreamBoundaryRight[i + botstart]);
            }        
        }
    }

    // LEFT PART
    for(size_t i = 0; i < botstart - toplimit; i++)
    {
        for(size_t j = 0; j < leftLimit; j++)
        {            
           // north Node
            if((i != 0))
            {
                internFieldLeft[j + (i * leftLimit)]->SetNorthNode(internFieldLeft[j + ((i - 1)*leftLimit)]);
            }
            else 
            {
                internFieldLeft[j + (i * leftLimit)]->SetNorthNode(internFieldTop[j + (numberX * (toplimit - 1))]);
            }
            
            
            // south Node
            if((i != flatPlaneBottom-1))
            {
                internFieldLeft[j + (i * leftLimit)]->SetSouthNode(internFieldLeft[j + ((i +1)*leftLimit)]);
            }
            else
            {
                internFieldLeft[j + (i * leftLimit)]->SetSouthNode(internFieldBottom[j]);
            }
            

            // West Node
            if(j != 0)
            {
                internFieldLeft[j + (i * leftLimit)]->SetWestNode(internFieldLeft[(j-1) + ((i)*leftLimit)]);
            }
            else
            {
                internFieldLeft[j + (i * leftLimit)]->SetWestNode(freestreamBoundaryLeft[i + toplimit]);
            }
            
            // East Node
            if(j != leftLimit -1)
            {
                internFieldLeft[j + (i * leftLimit)]->SetEastNode(internFieldLeft[j+1 + ((i)*leftLimit)]);
            }
            else
            {
                 internFieldLeft[j + (i * leftLimit)]->SetEastNode(flatPlaneWestBoundary[i]);
            }        
        }
    }
    
    // RIGHT PART
    for(size_t i = 0; i < botstart - toplimit; i++)
    {
        for(size_t j = 0; j < numberX-rightStart; j++)
        {            
            // north Node
            if((i != 0))
            {
                internFieldRight[j + (i * (numberX-rightStart))]->SetNorthNode(internFieldRight[j + ((i - 1)*(numberX-rightStart))]);
            }
            else 
            {
                internFieldRight[j + (i * (numberX-rightStart))]->SetNorthNode(internFieldTop[j+rightStart + (numberX * (toplimit - 1))]);
            }
            
            
            // south Node
            if((i != flatPlaneBottom-1))
            {
                internFieldRight[j + (i * (numberX-rightStart))]->SetSouthNode(internFieldRight[j + ((i +1)*(numberX-rightStart))]);
            }
            else
            {
                internFieldRight[j + (i * (numberX-rightStart))]->SetSouthNode(internFieldBottom[j+rightStart]);
            }
            

            // West Node
            if(j != 0)
            {
                internFieldRight[j + (i * (numberX-rightStart))]->SetWestNode(internFieldRight[(j-1) + ((i)*(numberX-rightStart))]);
            }
            else
            {
                internFieldRight[j + (i * (numberX-rightStart))]->SetWestNode(flatPlaneEastBoundary[i]);
            }
            
            // East Node
            if(j != numberX - rightStart -1)
            {
                internFieldRight[j + (i * (numberX-rightStart))]->SetEastNode(internFieldRight[j+1 + ((i)*(numberX-rightStart))]);
            }
            else
            {
                 internFieldRight[j + (i * (numberX-rightStart))]->SetEastNode(freestreamBoundaryRight[i + toplimit]);
            }   
        }
    }

    for(size_t itTime = 0; itTime < nIterTime; itTime++)
    {
        std::cout << (itTime*dt) << std::endl;

        for(size_t i = 0; i < freestreamBoundaryTop.size(); i++)
        {
            freestreamBoundaryTop[i]->CalculatePRelax();
            freestreamBoundaryTop[i]->CalculateU(dt);
            freestreamBoundaryTop[i]->CalculateV(dt);
        }

        for(size_t i = 0; i < freestreamBoundaryBottom.size(); i++)
        {
            freestreamBoundaryBottom[i]->CalculatePRelax();
            freestreamBoundaryBottom[i]->CalculateU(dt);
            freestreamBoundaryBottom[i]->CalculateV(dt);
        }

        for(size_t i = 0; i < freestreamBoundaryLeft.size(); i++)
        {
            freestreamBoundaryLeft[i]->CalculatePRelax();
            freestreamBoundaryLeft[i]->CalculateU(dt);
            freestreamBoundaryLeft[i]->CalculateV(dt);
        }

        for(size_t i = 0; i < freestreamBoundaryRight.size(); i++)
        {
            freestreamBoundaryRight[i]->CalculatePRelax();
            freestreamBoundaryRight[i]->CalculateU(dt);
            freestreamBoundaryRight[i]->CalculateV(dt);
        }

		for (size_t i = 0; i < flatPlaneEastBoundary.size(); i++)
		{
			flatPlaneEastBoundary[i]->CalculatePRelax();
			flatPlaneEastBoundary[i]->CalculateU(dt);
			flatPlaneEastBoundary[i]->CalculateV(dt);
		}

		for (size_t i = 0; i < flatPlaneWestBoundary.size(); i++)
		{
			flatPlaneWestBoundary[i]->CalculatePRelax();
			flatPlaneWestBoundary[i]->CalculateU(dt);
			flatPlaneWestBoundary[i]->CalculateV(dt);
		}

		for (size_t i = 0; i < flatPlaneNorthBoundary.size(); i++)
		{
			flatPlaneNorthBoundary[i]->CalculatePRelax();
			flatPlaneNorthBoundary[i]->CalculateU(dt);
			flatPlaneNorthBoundary[i]->CalculateV(dt);
		}

		for (size_t i = 0; i < flatPlaneSouthBoundary.size(); i++)
		{
			flatPlaneSouthBoundary[i]->CalculatePRelax();
			flatPlaneSouthBoundary[i]->CalculateU(dt);
			flatPlaneSouthBoundary[i]->CalculateV(dt);
		}
        
        for(size_t i = 0; i < internFieldTop.size(); i++)
        {
            internFieldTop[i]->PreCalculatePoissonSource(dt);
        }

        for(size_t i = 0; i < internFieldBottom.size(); i++)
        {
            internFieldBottom[i]->PreCalculatePoissonSource(dt);
        }

        for(size_t i = 0; i < internFieldLeft.size(); i++)
        {
            internFieldLeft[i]->PreCalculatePoissonSource(dt);
        }

        for(size_t i = 0; i < internFieldRight.size(); i++)
        {
            internFieldRight[i]->PreCalculatePoissonSource(dt);
        }
			
        double maxError = 100.0;

        const size_t mNIterP = 500;
        size_t nIterP = 0;

        while(maxError > 0.1)//nIterP < mNIterP )
        {
			//std::cout << maxError << std::endl;
            nIterP++;

            maxError = 0.0;
            for(size_t i = 0; i < internFieldTop.size(); i++)
            {
                double err = internFieldTop[i]->CalculatePRelax();
                if(err > maxError)
                {
                    maxError = err;
                }
            }

            for(size_t i = 0; i < internFieldBottom.size(); i++)
            {
                double err = internFieldBottom[i]->CalculatePRelax();
                if(err > maxError)
                {
                    maxError = err;
                }
            }

            for(size_t i = 0; i < internFieldLeft.size(); i++)
            {
                double err = internFieldLeft[i]->CalculatePRelax();
                if(err > maxError)
                {
                    maxError = err;
                }
            }

            for(size_t i = 0; i < internFieldRight.size(); i++)
            {
                double err = internFieldRight[i]->CalculatePRelax();
                if(err > maxError)
                {
                    maxError = err;
                }
            }

			for (size_t i = 0; i < freestreamBoundaryTop.size(); i++)
			{
				freestreamBoundaryTop[i]->CalculatePRelax();
			}

			for (size_t i = 0; i < freestreamBoundaryBottom.size(); i++)
			{
				freestreamBoundaryBottom[i]->CalculatePRelax();
			}

			for (size_t i = 0; i < freestreamBoundaryLeft.size(); i++)
			{
				freestreamBoundaryLeft[i]->CalculatePRelax();
			}

			for (size_t i = 0; i < freestreamBoundaryRight.size(); i++)
			{
				freestreamBoundaryRight[i]->CalculatePRelax();
			}

			for (size_t i = 0; i < flatPlaneEastBoundary.size(); i++)
			{
				flatPlaneEastBoundary[i]->CalculatePRelax();
			}

			for (size_t i = 0; i < flatPlaneWestBoundary.size(); i++)
			{
				flatPlaneWestBoundary[i]->CalculatePRelax();
			}

			for (size_t i = 0; i < flatPlaneNorthBoundary.size(); i++)
			{
				flatPlaneNorthBoundary[i]->CalculatePRelax();
			}

			for (size_t i = 0; i < flatPlaneSouthBoundary.size(); i++)
			{
				flatPlaneSouthBoundary[i]->CalculatePRelax();
			}

			for (size_t i = 0; i < internFieldTop.size(); i++)
			{
				internFieldTop[i]->CalculateU(dt);
				internFieldTop[i]->CalculateV(dt);
			}

			for (size_t i = 0; i < internFieldBottom.size(); i++)
			{
				internFieldBottom[i]->CalculateU(dt);
				internFieldBottom[i]->CalculateV(dt);
			}

			for (size_t i = 0; i < internFieldLeft.size(); i++)
			{
				internFieldLeft[i]->CalculateU(dt);
				internFieldLeft[i]->CalculateV(dt);
			}

			for (size_t i = 0; i < internFieldRight.size(); i++)
			{
				internFieldRight[i]->CalculateU(dt);
				internFieldRight[i]->CalculateV(dt);
			}

			for (size_t i = 0; i < internFieldTop.size(); i++)
			{
				internFieldTop[i]->EndStep();
			}

			for (size_t i = 0; i < internFieldBottom.size(); i++)
			{
				internFieldBottom[i]->EndStep();
			}

			for (size_t i = 0; i < internFieldLeft.size(); i++)
			{
				internFieldLeft[i]->EndStep();
			}

			for (size_t i = 0; i < internFieldRight.size(); i++)
			{
				internFieldRight[i]->EndStep();
			}
        }

		std::cout << "Max Error: " << maxError << std::endl;

		std::cout << "Velocidade U: " << internFieldTop[0]->GetU() << std::endl;
		std::cout << "Velocidade V: " << internFieldTop[0]->GetV() << std::endl;
		std::cout << "Pressao P: " << internFieldTop[0]->GetP() << std::endl;
    }

    std::ofstream out("arq.csv");

    out << "time;X;Y;U;V;P\n";

    for(size_t i = 0; i < internFieldTop.size(); i++)
    {
        out << simTime << ";";
        out << internFieldTop[i]->GetX() << ";";
        out << internFieldTop[i]->GetY() << ";";
        out << internFieldTop[i]->GetU() << ";";
        out << internFieldTop[i]->GetV() << ";";
        out << internFieldTop[i]->GetP() << "\n";
    }

    for(size_t i = 0; i < internFieldBottom.size(); i++)
    {
        out << simTime << ";";
        out << internFieldBottom[i]->GetX() << ";";
        out << internFieldBottom[i]->GetY() << ";";
        out << internFieldBottom[i]->GetU() << ";";
        out << internFieldBottom[i]->GetV() << ";";
        out << internFieldBottom[i]->GetP() << "\n";
    }

    for(size_t i = 0; i < internFieldLeft.size(); i++)
    {
        out << simTime << ";";
        out << internFieldLeft[i]->GetX() << ";";
        out << internFieldLeft[i]->GetY() << ";";
        out << internFieldLeft[i]->GetU() << ";";
        out << internFieldLeft[i]->GetV() << ";";
        out << internFieldLeft[i]->GetP() << "\n";
    }

    for(size_t i = 0; i < internFieldRight.size(); i++)
    {
        out << simTime << ";";
        out << internFieldRight[i]->GetX() << ";";
        out << internFieldRight[i]->GetY() << ";";
        out << internFieldRight[i]->GetU() << ";";
        out << internFieldRight[i]->GetV() << ";";
        out << internFieldRight[i]->GetP() << "\n";
    }

    out.close();


    for(size_t i = 0; i < freestreamBoundaryTop.size(); i++)
    {
        NorthBoundary* ptr = freestreamBoundaryTop[i];
        delete ptr;
        ptr = nullptr;
    }

    for(size_t i = 0; i < freestreamBoundaryBottom.size(); i++)
    {
        delete (freestreamBoundaryBottom[i]);
        freestreamBoundaryBottom[i] = nullptr;
    }

    for(size_t i = 0; i < freestreamBoundaryLeft.size(); i++)
    {
        delete freestreamBoundaryLeft[i];
        freestreamBoundaryLeft[i] = nullptr;
    }

    for(size_t i = 0; i < freestreamBoundaryRight.size(); i++)
    {
        delete freestreamBoundaryRight[i];
        freestreamBoundaryRight[i] = nullptr;
    }

    for(size_t i = 0; i < internFieldTop.size(); i++)
    {
        delete internFieldTop[i];
        internFieldTop[i] = nullptr;
    }

    for(size_t i = 0; i < internFieldBottom.size(); i++)
    {
        delete internFieldBottom[i];
        internFieldBottom[i] = nullptr;
    }

    for(size_t i = 0; i < internFieldLeft.size(); i++)
    {
        delete internFieldLeft[i];
        internFieldLeft[i] = nullptr;
    }

    for(size_t i = 0; i < internFieldRight.size(); i++)
    {
        delete internFieldRight[i];
        internFieldRight[i] = nullptr;
    }


    for(size_t i = 0; i < flatPlaneEastBoundary.size(); i++)
    {
        delete flatPlaneEastBoundary[i];
        flatPlaneEastBoundary[i] = nullptr;
    }

    for(size_t i = 0; i < flatPlaneNorthBoundary.size(); i++)
    {
        delete flatPlaneNorthBoundary[i];
        flatPlaneNorthBoundary[i] = nullptr;
    }

    for(size_t i = 0; i < flatPlaneSouthBoundary.size(); i++)
    {
        delete flatPlaneSouthBoundary[i];
        flatPlaneSouthBoundary[i] = nullptr;
    }

    for(size_t i = 0; i < flatPlaneWestBoundary.size(); i++)
    {
        delete flatPlaneWestBoundary[i];
        flatPlaneWestBoundary[i] = nullptr;
    }
    
    return 0;
}