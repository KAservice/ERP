#ifndef UFormaSpiskaSprKKMCFH                  
#define UFormaSpiskaSprKKMCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprKKMCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprKKMCF();                                                           
   ~TFormaSpiskaSprKKMCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
