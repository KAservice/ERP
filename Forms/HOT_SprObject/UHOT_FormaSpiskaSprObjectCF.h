#ifndef UHOT_FormaSpiskaSprObjectCFH                  
#define UHOT_FormaSpiskaSprObjectCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_FormaSpiskaSprObjectCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_FormaSpiskaSprObjectCF();                                                           
   ~THOT_FormaSpiskaSprObjectCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
