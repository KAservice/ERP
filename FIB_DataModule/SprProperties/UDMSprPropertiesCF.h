#ifndef UDMSprPropertiesCFH                  
#define UDMSprPropertiesCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprPropertiesCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprPropertiesCF();                                                           
   ~TDMSprPropertiesCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
