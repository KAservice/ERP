#ifndef UFormaElementaSprPropertiesNaborCFH                  
#define UFormaElementaSprPropertiesNaborCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprPropertiesNaborCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprPropertiesNaborCF();                                                           
   ~TFormaElementaSprPropertiesNaborCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
