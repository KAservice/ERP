#ifndef UFormaElementaSprTypeNachislCFH                  
#define UFormaElementaSprTypeNachislCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprTypeNachislCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprTypeNachislCF();                                                           
   ~TFormaElementaSprTypeNachislCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
