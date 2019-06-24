#ifndef UFormaDocPlatPorCFH                  
#define UFormaDocPlatPorCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocPlatPorCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocPlatPorCF();                                                           
   ~TFormaDocPlatPorCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
