#ifndef UFormaDocPostNaSchetCFH                  
#define UFormaDocPostNaSchetCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocPostNaSchetCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocPostNaSchetCF();                                                           
   ~TFormaDocPostNaSchetCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
