#ifndef UREM_FormaDocProverkaCFH                  
#define UREM_FormaDocProverkaCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocProverkaCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocProverkaCF();                                                           
   ~TREM_FormaDocProverkaCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
