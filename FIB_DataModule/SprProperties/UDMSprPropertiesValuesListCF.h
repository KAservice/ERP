#ifndef UDMSprPropertiesValuesListCFH                  
#define UDMSprPropertiesValuesListCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprPropertiesValuesListCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprPropertiesValuesListCF();                                                           
   ~TDMSprPropertiesValuesListCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
