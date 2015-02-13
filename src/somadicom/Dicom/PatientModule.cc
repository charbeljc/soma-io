#ifdef SOMA_IO_DICOM
#include <soma-io/Dicom/PatientModule.h>
#else
#include <Dicom/PatientModule.h>
#endif

#include <dcmtk/config/osconfig.h>
#include <dcmtk/dcmdata/dcdatset.h>
#include <dcmtk/dcmdata/dcdeftag.h>
#include <dcmtk/dcmdata/dcuid.h>


soma::PatientModule::PatientModule()
                   : soma::DicomModule(),
                     _name( "" ),
                     _id( "" ),
                     _birthDate( "" ),
                     _sex( "" ),
                     _age( "" ),
                     _weight( 0.0 )
{
}


bool soma::PatientModule::parseDataset( DcmDataset* dataset )
{

  if ( dataset )
  {

    OFString tmpString;
    Float64 tmpDouble;

#if OFFIS_DCMTK_VERSION_NUMBER >= 360
    if ( dataset->findAndGetOFString( DCM_PatientName, tmpString ).good() )
#else
    if ( dataset->findAndGetOFString( DCM_PatientsName, tmpString ).good() )
#endif
    {

      _name = tmpString.c_str();

    }

    if ( dataset->findAndGetOFString( DCM_PatientID, tmpString ).good() )
    {

      _id = tmpString.c_str();

    }

#if OFFIS_DCMTK_VERSION_NUMBER >= 360
    if ( dataset->findAndGetOFString( DCM_PatientBirthDate, tmpString ).good() )
#else
    if ( dataset->findAndGetOFString( DCM_PatientsBirthDate, 
                                      tmpString ).good() )
#endif
    {

      _birthDate = tmpString.c_str();

    }

#if OFFIS_DCMTK_VERSION_NUMBER >= 360
    if ( dataset->findAndGetOFString( DCM_PatientSex, tmpString ).good() )
#else
    if ( dataset->findAndGetOFString( DCM_PatientsSex, tmpString ).good() )
#endif
    {

      _sex = tmpString.c_str();

    }

#if OFFIS_DCMTK_VERSION_NUMBER >= 360
    if ( dataset->findAndGetOFString( DCM_PatientAge, tmpString ).good() )
#else
    if ( dataset->findAndGetOFString( DCM_PatientsAge, tmpString ).good() )
#endif
    {

      _age = tmpString.c_str();

    }

#if OFFIS_DCMTK_VERSION_NUMBER >= 360
    if ( dataset->findAndGetFloat64( DCM_PatientWeight, tmpDouble ).good() )
#else
    if ( dataset->findAndGetFloat64( DCM_PatientsWeight, tmpDouble ).good() )
#endif
    {

      _weight = double( tmpDouble );

    }

    return true;

  }

  return false;

}


const std::string& soma::PatientModule::getName() const
{

  return _name;

}


const std::string& soma::PatientModule::getId() const
{

  return _id;

}


const std::string& soma::PatientModule::getBirthDate() const
{

  return _birthDate;

}


const std::string& soma::PatientModule::getSex() const
{

  return _sex;

}


const std::string& soma::PatientModule::getAge() const
{

  return _age;

}


double soma::PatientModule::getWeight() const
{

  return _weight;

}

