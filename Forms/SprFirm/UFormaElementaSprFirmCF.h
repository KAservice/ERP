#ifndef UFormaElementaSprFirmCFH                  
#define UFormaElementaSprFirmCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprFirmCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprFirmCF();                                                           
   ~TFormaElementaSprFirmCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
