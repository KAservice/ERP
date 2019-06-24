#ifndef UFormaElementaSprCodeTelCFH                  
#define UFormaElementaSprCodeTelCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprCodeTelCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprCodeTelCF();                                                           
   ~TFormaElementaSprCodeTelCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
