#ifndef UFormaSpiskaSprPartCFH                  
#define UFormaSpiskaSprPartCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprPartCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprPartCF();                                                           
   ~TFormaSpiskaSprPartCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
