#ifndef UFormaSetupOtborCFH                  
#define UFormaSetupOtborCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSetupOtborCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSetupOtborCF();                                                           
   ~TFormaSetupOtborCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
