#ifndef UFormaReportKassaCFH                  
#define UFormaReportKassaCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaReportKassaCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaReportKassaCF();                                                           
   ~TFormaReportKassaCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
