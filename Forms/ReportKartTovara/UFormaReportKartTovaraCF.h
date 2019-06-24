#ifndef UFormaReportKartTovaraCFH                  
#define UFormaReportKartTovaraCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaReportKartTovaraCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaReportKartTovaraCF();                                                           
   ~TFormaReportKartTovaraCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
