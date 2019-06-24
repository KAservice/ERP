#ifndef UFormaElementaSprPropertiesGrpCFH                  
#define UFormaElementaSprPropertiesGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprPropertiesGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprPropertiesGrpCF();                                                           
   ~TFormaElementaSprPropertiesGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
