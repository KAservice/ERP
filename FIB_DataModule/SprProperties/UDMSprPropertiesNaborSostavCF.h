#ifndef UDMSprPropertiesNaborSostavCFH                  
#define UDMSprPropertiesNaborSostavCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprPropertiesNaborSostavCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprPropertiesNaborSostavCF();                                                           
   ~TDMSprPropertiesNaborSostavCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
