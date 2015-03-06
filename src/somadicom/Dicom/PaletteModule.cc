#ifdef SOMA_IO_DICOM
#include <soma-io/Dicom/PaletteModule.h>
#else
#include <Dicom/PaletteModule.h>
#endif

#include <dcmtk/config/osconfig.h>
#include <dcmtk/dcmdata/dcdatset.h>
#include <dcmtk/dcmdata/dcdeftag.h>


soma::PaletteModule::PaletteModule()
                   : soma::DicomModule()
{
}


bool soma::PaletteModule::parseDataset( DcmDataset* dataset )
{

  if ( dataset )
  {

    _red.initialize( dataset, 
                     DCM_RedPaletteColorLookupTableDescriptor,
                     DCM_RedPaletteColorLookupTableData );
    _green.initialize( dataset,
                       DCM_GreenPaletteColorLookupTableDescriptor,
                       DCM_GreenPaletteColorLookupTableData );
    _blue.initialize( dataset,
                      DCM_BluePaletteColorLookupTableDescriptor,
                      DCM_BluePaletteColorLookupTableData );

    return true;

  }

  return false;

}


soma::Rgba soma::PaletteModule::operator()( int32_t index )
{

  uint8_t r, g, b;

  if ( _red.getBits() == 8 )
  {

    r = uint8_t( _red( index ) & 0xff );
    g = uint8_t( _green( index ) & 0xff );
    b = uint8_t( _blue( index ) & 0xff );

  }
  else
  {

    r = uint8_t( ( _red( index ) & 0xff00 ) >> 8 );
    g = uint8_t( ( _green( index ) & 0xff00 ) >> 8 );
    b = uint8_t( ( _blue( index ) & 0xff00 ) >> 8 );

  }

  return soma::Rgba( r, g, b );

}
