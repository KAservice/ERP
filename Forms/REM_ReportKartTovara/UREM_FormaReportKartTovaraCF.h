#ifndef UREM_FormaReportKartTovaraCFH                  
#define UREM_FormaReportKartTovaraCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaReportKartTovaraCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaReportKartTovaraCF();                                                           
   ~TREM_FormaReportKartTovaraCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
