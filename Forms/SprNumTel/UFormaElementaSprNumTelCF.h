#ifndef UFormaElementaSprNumTelCFH                  
#define UFormaElementaSprNumTelCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprNumTelCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprNumTelCF();                                                           
   ~TFormaElementaSprNumTelCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
