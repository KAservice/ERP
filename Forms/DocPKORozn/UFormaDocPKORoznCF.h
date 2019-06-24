#ifndef UFormaDocPKORoznCFH                  
#define UFormaDocPKORoznCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocPKORoznCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocPKORoznCF();                                                           
   ~TFormaDocPKORoznCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
