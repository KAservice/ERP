#ifndef UFormaReportOCBRegOstNomCFH                  
#define UFormaReportOCBRegOstNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaReportOCBRegOstNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaReportOCBRegOstNomCF();                                                           
   ~TFormaReportOCBRegOstNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
