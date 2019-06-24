#ifndef UHOT_FormaReportDvNomFondaCFH                  
#define UHOT_FormaReportDvNomFondaCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_FormaReportDvNomFondaCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_FormaReportDvNomFondaCF();                                                           
   ~THOT_FormaReportDvNomFondaCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
