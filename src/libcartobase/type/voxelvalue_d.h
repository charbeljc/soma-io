/* This software and supporting documentation are distributed by
*     Institut Federatif de Recherche 49
*     CEA/NeuroSpin, Batiment 145,
*     91191 Gif-sur-Yvette cedex
*     France
*
* This software is governed by the CeCILL-B license under
* French law and abiding by the rules of distribution of free software.
* You can  use, modify and/or redistribute the software under the
* terms of the CeCILL-B license as circulated by CEA, CNRS
* and INRIA at the following URL "http://www.cecill.info".
*
* As a counterpart to the access to the source code and  rights to copy,
* modify and redistribute granted by the license, users are provided only
* with a limited warranty  and the software's author,  the holder of the
* economic rights,  and the successive licensors  have only  limited
* liability.
*
* In this respect, the user's attention is drawn to the risks associated
* with loading,  using,  modifying and/or developing or reproducing the
* software by the user in light of its specific status of free software,
* that may mean  that it is complicated to manipulate,  and  that  also
* therefore means  that it is reserved for developers  and  experienced
* professionals having in-depth computer knowledge. Users are therefore
* encouraged to load and test the software's suitability as regards their
* requirements in conditions enabling the security of their systems and/or
* data to be ensured and,  more generally, to use and operate it in the
* same conditions as regards security.
*
* The fact that you are presently reading this means that you have had
* knowledge of the CeCILL-B license and that you accept its terms.
*/

#ifndef CARTOBASE_TYPE_VOXELVALUE_D_H
#define CARTOBASE_TYPE_VOXELVALUE_D_H

//--- cartobase --------------------------------------------------------------
#include <cartobase/type/voxelvalue.h>
//----------------------------------------------------------------------------

namespace carto {
  
  //==========================================================================
  //   C O N S T R U C T O R S
  //==========================================================================
  
  template <typename T, unsigned int C>
  VoxelValue<T,C>::VoxelValue()
  {
    #ifdef CARTO_DEBUG_VOXELVALUE
      std::cout << "VOXELVALUE:: constructor()" << std::endl;
    #endif
  }
  
  template <typename T, unsigned int C>
  VoxelValue<T,C>::VoxelValue( const VoxelValue<T,C> & other )
  {
    #ifdef CARTO_DEBUG_VOXELVALUE
      std::cout << "VOXELVALUE:: constructor( other )" << std::endl;
    #endif
    *this = other;
  }
  
  template <typename T, unsigned int C>
  VoxelValue<T,C>::~VoxelValue()
  {
    #ifdef CARTO_DEBUG_VOXELVALUE
      std::cout << "VOXELVALUE:: destructor()" << std::endl;
    #endif
  }
  
  //==========================================================================
  //   I N T E R N   O P E R A T O R S
  //==========================================================================
  
  template <typename T, unsigned int C> inline
  bool VoxelValue<T,C>::operator == ( const VoxelValue<T,C> &aa )
  {
    #ifdef CARTO_DEBUG_VOXELVALUE
      std::cout << "VOXELVALUE:: VV == VV" << std::endl;
    #endif
    unsigned int i;
    for( i=0; i<C; ++i )
      if( (*this)[ i ] != aa[ i ] )
        return false;
    return true;
  }
  
  template <typename T, unsigned int C> inline
  bool VoxelValue<T,C>::operator != ( const VoxelValue<T,C> &aa )
  {
    #ifdef CARTO_DEBUG_VOXELVALUE
      std::cout << "VOXELVALUE:: VV != VV" << std::endl;
    #endif
    return !( (*this) == aa );
  }
  
  template <typename T, unsigned int C>
  bool VoxelValue<T,C>::operator == ( const T &bb )
  {
    #ifdef CARTO_DEBUG_VOXELVALUE
      std::cout << "VOXELVALUE:: VV == const" << std::endl;
    #endif
    unsigned int i;
    for( i=0; i<C; ++i )
      if( (*this)[ i ] != bb )
        return false;
    return true;
  }
  
  template <typename T, unsigned int C> inline
  bool VoxelValue<T,C>::operator != ( const T &bb )
  {
    #ifdef CARTO_DEBUG_VOXELVALUE
      std::cout << "VOXELVALUE:: VV != const" << std::endl;
    #endif
    return !( (*this) == bb );
  }
  
}

#endif
