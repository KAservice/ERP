#ifndef UFormaElementaSprPropertiesValuesListCFH                  
#define UFormaElementaSprPropertiesValuesListCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprPropertiesValuesListCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprPropertiesValuesListCF();                                                           
   ~TFormaElementaSprPropertiesValuesListCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
