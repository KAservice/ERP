#ifndef UDMSprTypeNachislCFH                  
#define UDMSprTypeNachislCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprTypeNachislCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprTypeNachislCF();                                                           
   ~TDMSprTypeNachislCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
