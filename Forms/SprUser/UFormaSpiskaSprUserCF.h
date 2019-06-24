#ifndef UFormaSpiskaSprUserCFH                  
#define UFormaSpiskaSprUserCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprUserCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprUserCF();                                                           
   ~TFormaSpiskaSprUserCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
