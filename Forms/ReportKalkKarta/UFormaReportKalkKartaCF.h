#ifndef UFormaReportKalkKartaCFH                  
#define UFormaReportKalkKartaCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaReportKalkKartaCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaReportKalkKartaCF();                                                           
   ~TFormaReportKalkKartaCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
