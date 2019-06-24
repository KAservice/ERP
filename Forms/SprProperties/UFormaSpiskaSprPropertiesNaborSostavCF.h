#ifndef UFormaSpiskaSprPropertiesNaborSostavCFH                  
#define UFormaSpiskaSprPropertiesNaborSostavCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprPropertiesNaborSostavCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprPropertiesNaborSostavCF();                                                           
   ~TFormaSpiskaSprPropertiesNaborSostavCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
