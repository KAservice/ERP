#ifndef UFormaSpiskaSprPropertiesValuesListCFH                  
#define UFormaSpiskaSprPropertiesValuesListCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprPropertiesValuesListCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprPropertiesValuesListCF();                                                           
   ~TFormaSpiskaSprPropertiesValuesListCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
