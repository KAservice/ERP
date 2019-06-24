#ifndef UFormaSpiskaSprPodrCFH                  
#define UFormaSpiskaSprPodrCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprPodrCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprPodrCF();                                                           
   ~TFormaSpiskaSprPodrCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
