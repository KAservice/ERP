#ifndef UFormaReportOCBRegGoodsCFH                  
#define UFormaReportOCBRegGoodsCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaReportOCBRegGoodsCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaReportOCBRegGoodsCF();                                                           
   ~TFormaReportOCBRegGoodsCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
