#ifndef UREM_DMDocVigruskaCFH                  
#define UREM_DMDocVigruskaCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocVigruskaCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocVigruskaCF();                                                           
   ~TREM_DMDocVigruskaCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
