#ifndef _AxialTransformation_h_
#define _AxialTransformation_h_


#ifdef SOMA_IO_DICOM
#include <soma-io/config/soma_config.h>
#include <soma-io/Transformation/Transformation3d.h>
#include <soma-io/Container/Vector.h>
#else
#include <Transformation/Transformation3d.h>
#include <Container/Vector.h>
#endif


namespace soma
{


class AxialTransformation3d : public Transformation3d
{

  public:

    typedef void (AxialTransformation3d::*TPointer)( const double inX, 
                                                     const double inY, 
                                                     const double inZ,
                                                     double& outX, 
                                                     double& outY, 
                                                     double& outZ ) const;

    AxialTransformation3d();
    AxialTransformation3d( const Vector& rowCosine,
                           const Vector& columnCosine,
                           const Vector& origin = Vector( 0.0, 0.0, 0.0 ) );
    AxialTransformation3d( const AxialTransformation3d& other );

    void setTranslation( const Vector& translation );

    void getDirect( const double fromX, const double fromY, const double fromZ,
                    double& toX, double& toY, double& toZ ) const;
    void getInverse( const double toX, const double toY, const double toZ,
                     double& fromX, double& fromY, double& fromZ ) const;

  protected:

    void initialize( const Vector& normalVec );
    void getDirectAxial( const double fromX, 
                         const double fromY, 
                         const double fromZ,
                         double& toX, 
                         double& toY, 
                         double& toZ ) const;
    void getDirectSagittal( const double fromX, 
                            const double fromY, 
                            const double fromZ,
                            double& toX, 
                            double& toY, 
                            double& toZ ) const;
    void getDirectCoronal( const double fromX, 
                           const double fromY, 
                           const double fromZ,
                           double& toX, 
                           double& toY, 
                           double& toZ ) const;
    void getInverseAxial( const double toX, 
                          const double toY, 
                          const double toZ,
                          double& fromX, 
                          double& fromY, 
                          double& fromZ ) const;
    void getInverseSagittal( const double toX, 
                             const double toY, 
                             const double toZ,
                             double& fromX, 
                             double& fromY, 
                             double& fromZ ) const;
    void getInverseCoronal( const double toX, 
                            const double toY, 
                            const double toZ,
                            double& fromX, 
                            double& fromY, 
                            double& fromZ ) const;

    TPointer _directPointer;
    TPointer _inversePointer;

};


}


#endif
