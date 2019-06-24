#ifndef UFormaReportResultRealCFH                  
#define UFormaReportResultRealCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaReportResultRealCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaReportResultRealCF();                                                           
   ~TFormaReportResultRealCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
