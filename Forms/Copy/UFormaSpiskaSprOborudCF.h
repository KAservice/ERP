#ifndef UFormaSpiskaSprOborudCFH                  
#define UFormaSpiskaSprOborudCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprOborudCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprOborudCF();                                                           
   ~TFormaSpiskaSprOborudCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
