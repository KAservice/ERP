#ifndef UFormaElementaSprNomPropertiesNaborSostavCFH                  
#define UFormaElementaSprNomPropertiesNaborSostavCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprNomPropertiesNaborSostavCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprNomPropertiesNaborSostavCF();                                                           
   ~TFormaElementaSprNomPropertiesNaborSostavCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
