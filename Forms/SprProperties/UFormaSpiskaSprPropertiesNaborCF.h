#ifndef UFormaSpiskaSprPropertiesNaborCFH                  
#define UFormaSpiskaSprPropertiesNaborCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprPropertiesNaborCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprPropertiesNaborCF();                                                           
   ~TFormaSpiskaSprPropertiesNaborCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
