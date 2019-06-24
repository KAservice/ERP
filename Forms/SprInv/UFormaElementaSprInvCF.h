#ifndef UFormaElementaSprInvCFH                  
#define UFormaElementaSprInvCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprInvCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprInvCF();                                                           
   ~TFormaElementaSprInvCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
