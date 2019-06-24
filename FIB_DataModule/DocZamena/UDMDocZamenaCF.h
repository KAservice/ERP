#ifndef UDMDocZamenaCFH                  
#define UDMDocZamenaCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDocZamenaCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDocZamenaCF();                                                           
   ~TDMDocZamenaCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
