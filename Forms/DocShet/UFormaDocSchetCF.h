#ifndef UFormaDocSchetCFH                  
#define UFormaDocSchetCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocSchetCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocSchetCF();                                                           
   ~TFormaDocSchetCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
