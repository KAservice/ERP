#ifndef UFormaDocInvCFH                  
#define UFormaDocInvCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocInvCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocInvCF();                                                           
   ~TFormaDocInvCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
