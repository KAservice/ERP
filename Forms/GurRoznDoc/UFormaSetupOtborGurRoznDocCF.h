#ifndef UFormaSetupOtborGurRoznDocCFH                  
#define UFormaSetupOtborGurRoznDocCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSetupOtborGurRoznDocCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSetupOtborGurRoznDocCF();                                                           
   ~TFormaSetupOtborGurRoznDocCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
