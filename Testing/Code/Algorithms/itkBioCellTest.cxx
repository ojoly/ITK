/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkBioCellTest.cxx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#if defined(_MSC_VER)
#pragma warning ( disable : 4786 )
#endif

#include <iostream>

#include "itkBioCell.h"


int itkBioCellTest( int, char * [] )
{
   typedef itk::bio::Cell CellType;
    
   CellType * egg = CellType::CreateEgg();

   CellType::VectorType forceVector;

   forceVector[0] = 10.5;
   forceVector[1] = 20.5;

   egg->ClearForce();
   egg->AddForce( forceVector );
   egg->SecreteProducts();
   egg->ComputeGeneNetwork();

   const double radius = egg->GetRadius();

   CellType::SetGrowthRadiusLimit( 2.0 );
   CellType::SetGrowthRadiusIncrement( 0.1 );
   CellType::SetEnergySelfRepairLevel( 1.0 );
   CellType::SetNutrientSelfRepairLevel( 1.0 );

   CellType::SetGrowthMaximumLatencyTime( 10 );
   CellType::SetDivisionMaximumLatencyTime( 10 );

   std::cout << "Growth Latency = " << 
     CellType::GetGrowthMaximumLatencyTime() << std::endl;

   std::cout << "Division Latency = " << 
     CellType::GetDivisionMaximumLatencyTime() << std::endl;

   delete egg;

   std::cout << "Test Passed !" << std::endl;
   return EXIT_SUCCESS;
}











