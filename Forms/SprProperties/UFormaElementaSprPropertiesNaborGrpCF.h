#ifndef UFormaElementaSprPropertiesNaborGrpCFH                  
#define UFormaElementaSprPropertiesNaborGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprPropertiesNaborGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprPropertiesNaborGrpCF();                                                           
   ~TFormaElementaSprPropertiesNaborGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
