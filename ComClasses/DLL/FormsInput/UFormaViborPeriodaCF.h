#ifndef UFormaViborPeriodaCFH                  
#define UFormaViborPeriodaCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaViborPeriodaCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaViborPeriodaCF();                                                           
   ~TFormaViborPeriodaCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
