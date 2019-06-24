#ifndef UREM_FormaDocPostOtDileraCFH                  
#define UREM_FormaDocPostOtDileraCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocPostOtDileraCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocPostOtDileraCF();                                                           
   ~TREM_FormaDocPostOtDileraCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
