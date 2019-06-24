#ifndef UFormaSpiskaSprRaschSchetCFH                  
#define UFormaSpiskaSprRaschSchetCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprRaschSchetCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprRaschSchetCF();                                                           
   ~TFormaSpiskaSprRaschSchetCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
