#ifndef UDMFibConnectionCFH                  
#define UDMFibConnectionCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMFibConnectionCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMFibConnectionCF();                                                           
   ~TDMFibConnectionCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
