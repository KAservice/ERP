#ifndef UREM_FormaDocVigruskaCFH                  
#define UREM_FormaDocVigruskaCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocVigruskaCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocVigruskaCF();                                                           
   ~TREM_FormaDocVigruskaCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
