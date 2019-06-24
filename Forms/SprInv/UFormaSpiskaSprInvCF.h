#ifndef UFormaSpiskaSprInvCFH                  
#define UFormaSpiskaSprInvCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprInvCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprInvCF();                                                           
   ~TFormaSpiskaSprInvCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
