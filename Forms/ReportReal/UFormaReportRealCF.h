#ifndef UFormaReportRealCFH                  
#define UFormaReportRealCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaReportRealCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaReportRealCF();                                                           
   ~TFormaReportRealCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
