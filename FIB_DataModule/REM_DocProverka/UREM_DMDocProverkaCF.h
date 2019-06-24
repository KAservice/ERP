#ifndef UREM_DMDocProverkaCFH                  
#define UREM_DMDocProverkaCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocProverkaCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocProverkaCF();                                                           
   ~TREM_DMDocProverkaCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
