#ifndef UFormaReportOCBPaySaleCFH                  
#define UFormaReportOCBPaySaleCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaReportOCBPaySaleCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaReportOCBPaySaleCF();                                                           
   ~TFormaReportOCBPaySaleCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
