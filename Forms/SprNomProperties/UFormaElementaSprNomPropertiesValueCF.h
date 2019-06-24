#ifndef UFormaElementaSprNomPropertiesValueCFH                  
#define UFormaElementaSprNomPropertiesValueCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprNomPropertiesValueCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprNomPropertiesValueCF();                                                           
   ~TFormaElementaSprNomPropertiesValueCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
