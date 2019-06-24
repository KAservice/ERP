#ifndef UFormaSpiskaSprPropertiesCFH                  
#define UFormaSpiskaSprPropertiesCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprPropertiesCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprPropertiesCF();                                                           
   ~TFormaSpiskaSprPropertiesCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
