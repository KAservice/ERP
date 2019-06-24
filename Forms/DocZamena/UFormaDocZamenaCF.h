#ifndef UFormaDocZamenaCFH                  
#define UFormaDocZamenaCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocZamenaCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocZamenaCF();                                                           
   ~TFormaDocZamenaCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
