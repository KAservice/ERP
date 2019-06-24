#ifndef UFormaViborSprEdCFH                  
#define UFormaViborSprEdCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaViborSprEdCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaViborSprEdCF();                                                           
   ~TFormaViborSprEdCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
